#include <stdio.h>

/*
	函数声明：主函数之前，头文件里面
		函数是否需要返回值，是否有参数列表
	函数定义：源文件里面
		函数实现体
	函数调用：在主调函数中

	函数返回值；
		1.是否需要函数返回值：被调函数执行完之后是否需要给主调函树带回一个有用的消息，如果有，就返回。
		2.函数返回值只能由return语句带回。
		3.一个函数有且只有一个返回值。
		4.一个函数可以有多个return语句，执行到哪个语句，哪个语句返回。

	函数参数（形参）：
		实参：主调函数
		形参：被调函数
		参数传递：只能从实参到形参，是单向的值传递。
*/

#if 0
void max(int a, int b);
int getMax(int a, int b);


int main()
{
	int a = 10, b = 20;

	int c = getMax(a, b);
	max(a, b);

	printf("c = %d\n", c);

	return 0;	
}

void max(int a, int b)
{
	if (a > b)
		printf("%d\n", a);
	else	
		printf("%d\n", b);
}

int getMax(int a, int b)
{
	int m;

	if (a > b)
		m = a;
	else
		m = b;	

	return m;
}
#endif

#if 0
void swap(int *a, int *b);

int main()
{
	int a = 10, b = 20;

	swap(&a, &b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;	
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
#endif

#if 0
void InitArray(int *a, int n); //初始化数组
void PrintArray(int *a, int n);//打印数组
void Sort(int *a, int n);	   //排序

int main()
{
	int a[10];

	InitArray(a, 10);
	PrintArray(a, 10);
	Sort(a, 10);
	PrintArray(a, 10);

	return 0;	
}

void InitArray(int *a, int n)
{
	//以从大到小的值给数组赋值
	for (int i = 0, j = n; i < n; i++, j--)
		a[i] = j;	
}

//打印数组
void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

//选择法排序
void Sort(int *a, int n)
{
	int i, j, k, t;

	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i+1; j < n; j++)
		{
			if (a[j] < a[k])
				k = j;
		}		

		if (k != i)
		{
			t = a[k];
			a[k] = a[i];
			a[i] = t;			
		}
	}
}
#endif

#if 0
/*求对应位置a数组中元素大于b数组中元素的个数，小于的个数，等于的个数*/
void CmpAToB(int a[], int b[], int length, int *count);

int main()
{
	int a[10] = {1, 2, 4, 3, 7, 6, 5, 0, 9, 8};
	int b[10] = {1, 3, 2, 4, 5, 6, 7, 0, 8, 9};
	int count[3] = {0};

	CmpAToB(a, b, sizeof(a)/sizeof(int), count);//sizeof(a)求得的是字节数,类型为unsigned int
	printf("%d\n%d\n%d\n", count[0], count[1], count[2]);

	return 0;	
}

void CmpAToB(int a[], int b[], int length, int *count)
{
	int m1 = 0, m2 = 0, m3 = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] > b[i])
			m1++;
		else if (a[i] < b[i])
			m2++;
		else
			m3++;
	}	

	count[0] = m1;
	count[1] = m2;
	count[2] = m3;
}
#endif

#if 1
/*筛选法求100以内的素数*/
int man()
{
	int i, j, a[100];
	for (i = 1; i <= 100; i++)
		a[i-1] = i;

	for (i = 2; i < 10; i++)
	{
		for (j = 0; j < )
	}

	return 0;
}
#endif