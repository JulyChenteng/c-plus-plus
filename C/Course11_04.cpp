#include <stdio.h>
#include <math.h>

#if 0
int add(int n);//求1到100之和

//输出两个数中比较大的数值，不能比较
int getMax(int m, int n)
{
	return (m+n+abs(m-n))/2;//(m+n-abs(m-n))//求二者中较小的值
}

int main()
{
	int sum = 0;
	sum = add(100);
	printf("%d\n", sum);

	return 0;
}

int add(int n)
{
	int sum = 0;

	if (n == 0)
		sum = 0;
	else 
		sum = add(n-1) + n;

	return sum;
}
#endif 

/*
1+2+3+...+n
*/
#if 0
int fn(int n);
#include <math.h>
int main()
{
	//int m = fn(5);
		int m,n;
	scanf("%d%d",&m,&n);
	printf("%d\n",(m+n+abs(m-n))/2);
	//...
	//printf("%d\n",m);
	return 0;
}
int fn(int n)
{
	int m;
	if(n==0|| n== 1)
		m = 1;
	else
		m = fn(n-1)*n;
	return m;
}
#endif

/*
指针：地址
指针变量：存放其他变量的地址的变量
基类型 *指针变量名；
基类型：不是基本类型， 是指针所要指向的变量的类型

野指针：不是NULL指针，是指向垃圾内存的指针
	1.声明一个zhizhen，没有指向合法空间
	2.free指针后，没有指向合法空间

*p: 从p所指向的地址开始，以其基类型所占内存的字节数为偏移量读取内存中的值
*/
int main()
{
	/*
	int a = 5;
	//int *q;	//野指针
	int *p = NULL;
	p = &a;
	*p = 7;
	*/
	
	/*
	char a[10] = {1, 1, 1, 1, 1, 1};
	int *p = (int*)a;
	//printf("%d\n", a);
	printf("%d\n", *p);//2^24+2^16+2^8+1
	*/

	int *p = (int *)0x2000;
	printf("%x\n", (char *)p + 1);
	printf("%x\n", (double *)p + 1);
	printf("%x\n", (short *)p + 1);
	printf("%x\n", p + 1);
	

	return 0;
}













