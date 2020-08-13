#include <stdio.h>
#include <stdlib.h>


#if 0
//讨论作业1
char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

int main()
{
	//需要注意运算符优先级
	printf("%s\n", **++cpp);//本语句执行完后，cpp指向了c+2
	printf("%s\n", *--*++cpp + 3);//本语句执行完后，cpp指向了c+1
	printf("%s\n", *cpp[-2]+3);//本语句执行完后，cpp指向了c+1,cpp指向的位置并没有变
	printf("%s\n",cpp[-1][-1]+1);

	return 0;
}
#endif 
#if 1
//讨论作业2
int main()  
{  
    char *str[]={"welcome","to","Fortemedia","Nanjing"};  
    char **p=str+1; 
	int i;

    str[0]=(*p++)+2;  
    str[1]=*(p+1);  
    str[2]=p[1]+3;  
    str[3]=p[0]+(str[2]-str[1]);

    printf("%s\n",str[0]);
	printf("%s\n",str[1]);
	printf("%s\n",str[2]);
	printf("%s\n",str[3]);
    return 0;  
}  
#endif

/*
数据类型: 基本数据类型、构造类型、空类型、指针类型
构造数据类型：数组，结构体，共用体
结构体(c语言中可以为空）：
	struct student
	{
		int id;
		char name[20];
		char gender;
		int age;
	};
定义：
1.在定义类型的同时定义变量
	struct Data
	{
		int a;
		int b;
	}data; //相当于struct Data data;

2. 在定义类型的同时定义变量,不建议使用
	struct 
	{
		int a;
		int b;
	}ss；
3. 先定义结构体类型，再定义变量
	struct student
	{
		int num;
		char name[20];
		char sex;
		int age;
	};
	typedef struct student STU;

注意：
	一个结构体可以包含另外一个结构体类型，但是不能包含本结构体的
非指针类型
struct people
{
	//struct people a;//error
	struct people *a; //right
};
*/

#if 0
typedef struct student
{
	
	char gender;
	char name[20];
	int id;
	int age;
}STU;

void read(STU *stu, int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d %s %c %d", &stu[i].id, stu[i].name, &stu[i].gender, &stu[i].age);
}

void print(STU *stu, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d %s %c %d\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].age);
}

void sort(STU *stu, int n)
{
	int i, j;
	STU t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (stu[j].id > stu[j+1].id) //if (strcmp(stu[j].name, stu[j+1].name) > 0)
			{
				t = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = t;
			}
		}
	}
}

int main()
{
	STU stu[5];

	read(stu, 5);
	sort(stu, 5);
	print(stu, 5);

	return 0;
}
#endif 

#if 0
/*
其实字节对齐的细节和具体编译器实现相关，但一般而言，满足三个准则：
　　1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
　　2) 结构体每个成员相对于结构体首地址的偏移量都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节；
　　3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个成员之后加上填充字节。
注意：是最宽基本类型，如char[20]则按照char来计算。
*/
typedef struct _BaseA
{
	char ch1;
	int a;
	char ch2;
}BASEA;

typedef struct _BaseB
{
	int a;
	char ch1;
	char ch2;
}BASEB;

int main()
{
	printf("%d\n%d\n", sizeof(BASEA), sizeof(BASEB));//12 8

	return 0;
}
#endif

#if 0
/*
链表初讲
*/
typedef struct data
{
	int n;
	struct data *next;
}Data;

int main()
{
	Data *head = NULL;
	Data *p = NULL;
	Data *pnew = NULL,*pold = NULL;

	pnew = (Data*)malloc(sizeof(Data));
	pnew->next = NULL;

	//当遇到一个非法输入后跳出循环
	while(1 == scanf("%d",&pnew->n))
	{
		if(head == NULL)
		{
			head = pnew;
			p = head;
		}
		else
		{
			pold->next = pnew;
		}

		pold = pnew;
		pnew = (Data*)malloc(sizeof(Data));
		pnew->next = NULL;
	}

	while (p != NULL)
	{
		printf("%d ", p->n);
		p = p->next;
	}

	printf("\n");
	free(pnew);
	pnew = NULL;

	return 0;
}
#endif

