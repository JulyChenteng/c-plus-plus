#ifndef _STL_ALLOC_H
#define _STL_ALLOC_H

/*
* SGI STL��������������
* SGI STL��һ���������� a. allocate()ֱ��ʹ�� malloc()��deallocate()ֱ��ʹ��free()��
					  b. ģ��C++��set_new_handler()�Լ������ڴ治���״����
* SGI STL�ڶ����������� a.	ά��16����������(free lists),��128bytes, ����16��С������Ĵ�����������
					�ڴ��(memory pool)�� malloc() ���ö��á�
					  b. ��������������128bytes����ת���õ�һ���������� 
*/							  
#if 0

#include <new>
#define _THROW_BAD_ALLOC throw bad_alloc

#elif !defined(_THROW_BAD_ALLOC)

#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

#define _THROW_BAD_ALLOC cout << "out of memory" << endl;exit(1)

#endif
										   
//malloc-based allocator.ͨ�����Ժ���ܵ�default alloc�ٶ���
//ע����"template�ͱ����"�� "���ͱ����"inst��ȫû�����ó�
template <int inst>
class __malloc_alloc_template
{
public:
	static void* allocate(size_t n)
	{
		void  *result = malloc(n); //��һ��������ֱ��ʹ��malloc
		if (0 == result) result = oom_malloc(n);
		return result;
	}
	static void deallocate(void *p, size_t /* n */)
	{
		free(p); //��һ��������ֱ��ʹ��free()
	}

	static void* reallocate(void *p, size_t /* old_sz */, size_t new_sz)
	{
		void *result = realloc(p, new_sz);	//��һ��������ֱ��ʹ��realloc
		if (0 == result) result = oom_realloc(p, new_sz);
		return result;
	}

	//����C++��set_new_handler()��ͨ��������ָ���Լ���out-of-memory handler
	//��������һ������ֵΪ����ָ��ĺ������������ָ��ָ��һ������ֵΪ�ղ���Ϊ����ָ��ĺ�����
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return(old);
	}

	
private:
	//���������ڴ治������ oom: out of memory
	static void* oom_malloc(size_t);
	static void* oom_realloc(void *, size_t);
	static void(*__malloc_alloc_oom_handler)();//����ָ��
};

//malloc_alloc out-of-memory handling
//��ֵΪ0���д��Ͷ��趨
template <int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template <int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void(*my_malloc_handler)(); //����ָ��
	void *result;

	for (;;)		  //���ϳ����ͷš����á����ͷš�������
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler) { _THROW_BAD_ALLOC; }
		(*my_malloc_handler)(); //���ô������̣� ��ͼ�ͷ��ڴ�
		result = malloc(n);

		if (result) return result;
	}
}

template <int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
	void(*my_malloc_handler)(); //����ָ��
	void *result;

	for (;;)		  //���ϳ����ͷš����á����ͷš�������
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler) { _THROW_BAD_ALLOC; }
		(*my_malloc_handler)(); //���ô������̣� ��ͼ�ͷ��ڴ�
		result = realloc(p, n);

		if (result) return result;
	}
}

//ע�⣬����ֱ�ӽ����� inst ָ��Ϊ0
typedef __malloc_alloc_template<0> malloc_alloc;

////////////////////////////////////////////////////////////////////////////////////////////
//�ڶ���������
enum { __ALIGN = 8 };							//С��������ϵ��߽�
enum { __MAX_BYTES = 128 };						//С�����������
enum { __NFREELISTS = __MAX_BYTES / __ALIGN };  //free-lists����
	
//ע�⣺��"template�ͱ����"���ҵڶ�������ȫû�����ó�
//��һ�������ڶ��̻߳����£����鲻���۶��̻߳���
template <bool threads, int inst>
class __default_alloc_template
{
private:
	//ROUND_UP()��bytes�ϵ���8�ı���
	static size_t ROUND_UP(size_t bytes)
	{
		return ((bytes) + __ALIGN-1) & ~(__ALIGN-1);
	}

private:
	union obj		 //free-lists�Ľڵ㹹��
	{
		union obj *free_list_link;
		char client_data[1];  /*The client sees this.*/
	};

private:
	static obj* volatile free_list[__NFREELISTS];//16��free-lists
	
	//���º�����������Ĵ�С������ʹ�õ�n��free-list.n��0����
	static size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes) + __ALIGN - 1) / __ALIGN - 1);
	}

	//����һ����СΪn�Ķ��� �����ܼ����СΪn���������鵽free list
	static void* refill(size_t n);	
	//����һ���ռ䣬������nobjs����СΪ"size"������
	//�������nobjs�������������㣬nobjs���ܻή��
	static char* chunk_alloc(size_t size, int &nobjs);	  

	//Chunk allocation state
	static char *start_free; //�ڴ����ʼλ�ã�ֻ��chunk_alloc()�б仯
	static char *end_free;	 //�ڴ�ؽ���λ�ã�ֻ��chunk_alloc()�б仯
	static size_t heap_size;

public:
	static void* allocate(size_t n)
	{
		obj * volatile *my_free_list;
		obj * result;

		//����128bytes�͵��õ�һ��������
		if (n > (size_t)__MAX_BYTES)
			return (malloc_alloc::allocate(n));

		//Ѱ��16��free lists ���ʵ���һ��
		my_free_list = free_list + FREELIST_INDEX(n);
		result = *my_free_list;												  
		if (result == 0)			//û�ҵ����õ�free list,׼���������free list
		{
			void *r = refill(ROUND_UP(n));
			return r;
		}

		//����fress list
		*my_free_list = result->free_list_link;
		return result;
	}						
	static void deallocate(void *p, size_t n) 
	{
		obj *q = (obj*)p;
		obj * volatile *my_free_list;

		//����128�͵��õ�һ��������
		if (n > (size_t)__MAX_BYTES)
		{
			malloc_alloc::deallocate(p, n);
			return;
		}
	  
		//Ѱ�Ҷ�Ӧ��free list
		my_free_list = free_list + FREELIST_INDEX(n);
		//����free list, ��������
		q->free_list_link = *my_free_list;
		*my_free_list = q;
	}
	static void *realloc(void *p, size_t old_sz, size_t new_sz);
};

template <bool threads, int inst>
char * __default_alloc_template<threads, inst>::start_free = 0;

template <bool threads, int inst>
char * __default_alloc_template<threads, inst>::end_free = 0;

template <bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

template <bool threads, int inst>
typename __default_alloc_template<threads, inst>::obj * volatile
__default_alloc_template<threads, inst>::free_list[__NFREELISTS] = 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


//����һ����СΪn�Ķ��󣬲�����ʱ���Ϊ�ʵ���free list���ӽڵ�
//���� n �Ѿ��ʵ��ϵ��� 8 �ı���
template <bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	int nobjs = 20;
	//����chunk_alloc(),����ȡ��nobjs��������Ϊfree list���½ڵ�
	//ע�����nobjs��pass  by reference
	char *chunk = chunk_alloc(n, nobjs);
	obj * volatile *my_free_list;
	obj *result;
	obj *current_obj, *next_obj;

	//���ֻ���һ�����飬�򽫴����������������ã�free list���½ڵ�
	if (1 == nobjs) return (chunk);

	//�������free list, �����½ڵ� 
	my_free_list = free_list + FREELIST_INDEX(n);

	//������chunk�ռ�������free list
	result = (obj *)chunk;   //��һ�鷵�ظ��Ͷ�ʹ��
	*my_free_list = next_obj = (obj *)(chunk + n);//��������free listָ�������õĿռ�(ȡ���ڴ��)

	//���½�free list�ĸ��ڵ㴮������
	for (int i = 1;; i++)
	{
		current_obj = next_obj;
		next_obj = (obj *)((char *)next_obj + n);
		if (nobjs - 1 == i)
		{
			current_obj->free_list_link = 0;
			break;
		}
		else
		{
			current_obj->free_list_link = next_obj;
		}
	}

	return result;
}

template <bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int &nobjs)
{
	char *result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free; //�ڴ��ʣ��ռ�

	if (bytes_left >= total_bytes)
	{
		//�ڴ��ʣ��ռ���ȫ����Ҫ��
		result = start_free;
		start_free += total_bytes;
		return (result);
	}
	else if (bytes_left >= size)
	{
		//�ڴ��ʣ��ռ䲻�����������������㹻��Ӧһ�����������ϵ�����
		nobjs = bytes_left / size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;

		return (result);
	}
	else
	{
		//�ڴ��ʣ��ռ���һ������Ĵ�С���޷��ṩ
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);

		//���ڴ�صĲ�����ͷ����Щ���ü�ֵ
		if (bytes_left > 0)
		{
			//�ڴ�ػ�����ͷ��������ʵ���free list
			//Ѱ���ʵ���free list
			obj * volatile *my_free_list = free_list + FREELIST_INDEX(bytes_left);
			//����free list, ���ڴ���в���ռ����
			((obj *)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj *)start_free;
		}						  

		//���� heap �ռ䣬���������ڴ��
		start_free = (char *)malloc(bytes_to_get);
		if (0 == start_free)
		{
			//heap�ռ䲻�㣬malloc()ʧ��
			int i;
			obj * volatile *my_free_list, *p;

			for (i = size; i <= __MAX_BYTES; i += __ALIGN)
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if (0 != p)
				{
					*my_free_list = p->free_list_link;
					start_free = (char *)p;
					end_free = start_free + i;

					return (chunk_alloc(size, nobjs));
				}
			}

			end_free = 0;
			start_free = (char *)malloc_alloc::allocate(bytes_to_get);
		}
	
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;

		return (chunk_alloc(size, nobjs));	
	}
}

#endif