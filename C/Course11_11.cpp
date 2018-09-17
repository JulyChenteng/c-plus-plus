#include <stdio.h>
#include <string.h>

#if 0
int main()
{
	int a = 0; 
	int *p = &a;

	int b[5] = {1, 2, 3, 4, 5};
	p = &b[0];			//相当于p = b;
	printf("%d, %d\n", &b[1], p+1);
	printf("%d, %d\n", *&b[1], *(p+1));

	for (int i = 0; i < 5; i++)
		printf("%d ", *(p+i));		//也可以p[i], *(p++)
	for (int i = 0; i < 5; i++)
		printf("%d ", *(b+i));		//可以b[i],但是不能b++，因为数组名是只读的，不能被修改

	for (p = b; p < b+10; p++)     //p < p+5因为我们使用的是左闭右开原则，所以结束标志应该为第六个元素的首地址
		printf("%d ", *p);

	printf("\n");

	return 0;
}
#endif

#if 0
int main()
{
	int a[5] = {1, 2, 3, 4, 5}; 
	int *p = (int *)(&a+1);
	printf("%d, %d"\n, *(a+1), *(p-1)); //a的类型：int(*p)[5]，所以a+1就相当于向后偏移了一行
	printf("%d, %d\n", &a, &a+1);
	printf("%d, %d\n", a, a+1);

	return 0;	
}

#endif

#if 0
int main()
{
	int *p = (int *)0x518;
	int *q = (int *)0x500;
	//18的十进制位24，因为是整型指针，24/4 = 6
	printf("%d\n", p-q);//6 
	printf("%x\n", q+6);//518

	return 0;
}

#endif

#if 0
int main()
{
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int p = a[0]; //p = &a[0][0];

	/*
	for (int i = 0; i < 3*4; i++)
		printf("%d ", *(p+i));

	for (p = a[0]; p < a[0]+12; p++)
		printf("%d ", *p);
	*/

	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d ", *(p+i*4+j));//p+i*4是每一行的首地址
	}
	*/

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p+i)+j);
		}
	}

	printf("%d, %d, %d, %d\n", **q, *(*q+3), *(*(q+2)), *(*(q+1)+1));//1 4 9 6
}
#endif

#if 0
//利用指针实现选择排序
int main()
{
	int a[6] = {1, 4, 3, 2, 8, 7};
	int k, temp;
	
	for (int i = 0; i < 6; i++)
	{
		k = i;
		for (int j = i+1; j < 6; j++)
		{
			if (*(a+k) > *(a+j))
				k = j;
		}

		if (k != i)
		{
			temp = *(a+i);
			*(a+i) = *(a+k);
			*(a+k) = temp;
		}
	}
	
	for (int i = 0; i < 6; i++)
		printf("%d  ", *(a+i));

	return 0;
}
#endif

#if 0
int main()
{
	/*
	char a[] = "1234567"; //将常量字串拷贝一份保存至字符数组a中
	char *p = "123";	// p保存常量区中的字串“123”的首地址
	*/

	char a[20];
	char *p;

	strcpy(a, "1234");//合法
	p = "123";        //合法
	//strcpy(p, "123");//不合法，必须让p指向一个合法内存
	//使p指向一块合法内存的两种方法：1.分配内存（让它指向一块合法内存） 2.使它指向一个合法内存

	return 0;
}
#endif

#if 0
int main()
{
	int a = 5;
	int *const p1 = &a; //p1本身不能修改 不能使用p1++，可以对齐指向的值进行修改
	const int *p2 = &a; //*p2不能被修改(即指针指向的值不能被修改) 不能使用(*p2)++，可以对它本身的值进行修改
	int const *p3 = &a; //同上
	const int *const p4 = &a;//p4本身和p4指向的值都不能被修改

	return 0;
}
#endif

#if 0
int main()
{
	char a[] = "123";//拷贝形式的初始化
	char b[] = "123";

	const char a1[] = "123";
	const char a2[] = "123";

	char *p = "123";//指向常量区的字串“123”，保存其首地址
	char *q = "123";

	const char *p1 = "123";
	const char *q1 = "123"; 

	if (a == b)
		printf("a == b\n");
	if (a1 == a2)
		printf("a1 == b1\n");
	if (p == q)
		printf("p == q\n");
	if (p1 == q1)
		printf("p1 == q1\n");
	if (p == p1)
		printf("p == p1\n");

	return 0;
}
#endif

#if 1
int main()
{
	/*
	int a[5] = {1, 2, 3, 4, 5};
	int *p[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};//指针数组
	*/
	/*
	for (int i = 0; i < 5; i++)
		p[i] = &a[i];
	*/
	/*
	for (int i = 0; i < 5; i++)
		printf("%d ", *p[i]);
	printf("\n");
	*/

	char name[20][30];
	char *pname[4] = {"lili", "xiaoming", "liuliu", "zhangsan"};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (strcmp(p[], p[j+1]) > 0)
			{
				
			}
		}
	}

	return 0;
}
#endif