//#define _USE_MALLOC //����Ĭ��ִ�еڶ������������Ƕ���__USE_MALLOC

//ע��ͷ�ļ�����˳�򣬱��⸲�Ǻ궨��
#include "config.h"		//�������#include <iostream>ǰ����Ϊ����������ж����������Ḳ��_THROW_BAD_ALLOC��
#include <iostream>
using namespace std;

void out_of_memory()
{
	cout << "My out of memory!" << endl;
}

/*
int main()
{
	alloc::set_malloc_handler(out_of_memory);
	//int *p = (int *)alloc::allocate(sizeof(int));
	int *p = (int *)alloc::allocate(sizeof(int) * 533333333);

	alloc::deallocate(p, sizeof(int));

	return 0;
}
*/

int main()
{
	char *p = (char *)alloc::allocate(10);
	alloc::deallocate(p, 10);

	return 0;
}