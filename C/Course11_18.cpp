#include <stdio.h>

#if 0
int main()
{
	int (*p)(int,int); //函数指针
	/**/
	int *q(int,int); //指针函数，返回值为指针的函数

	char *x; //字符指针
	int (*m)[5];//数组指针
	int *n[5];//指针数组，数组里面有5个元素，每个都是指针
	printf("%d\n",max(4,6));
	return 0;
}
#endif

#if 0
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int add(int a,int b)
{
	return a + b;
}
/*
函数指针用法：
1.指向一个函数，并调用
2.作为另外一个函数的参数出现
3.作为一个函数的返回值出现
*/
void fn(int a,int b,int (*fp1)(int,int))
	//fp1 = add
{
	printf("fn:%d\n",fp1(a,b)); //add(a,b);
}
/*函数名为test，此函数包含一个int n参数，此函数返回值为指针，
此指针指向一个函数（int min(int,int)）*/
typedef int (*FN)(int,int);
//FN 为int (*)(int,int)的别名
//int (*test(int n))(int,int)  
FN test(int n)
{
	printf("test : %d\n",n);
	return min;
}
int main()
{
	//int m = max(4,6);
	//int (*fp)(int,int);
	FN fp;
	int m;
	fp = max;
	m = fp(4,6); //m = max(4,6);
	printf("%d\n",m);
	fp = min;
	printf("%d\n",fp(4,6));
	fn(4,6,add);

	fp = test(4);//fp = min;
	printf("%d\n",fp(2,4));
	return 0;
}
#endif

#if 0
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int add(int a,int b)
{
	return a + b;
}
int sub(int a,int b)
{
	return a - b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	if(b != 0)
		return a / b;
}
int main()
{
	//函数指针数组,相当于定义了5个函数指针
	int (*fp[])(int,int) = {max,min,add,sub,mul,div};
	int size = sizeof(fp)/sizeof(fp[0]);
	int num = 0; 
	printf("%d\n",size);
	while(1 == scanf("%d",&num))
	{
		if(num <0 || num >= size)
		{
			printf("输入超过范围，请重新输入\n");
			continue;
		}
		printf("%d\n",fp[num](3,8));
	}
	return 0;
}
#endif

#if 0
int main()
{
	int a[5] = {1,2,3,4,5};
	int *p[5] = {&a[0],&a[1],&a[2],&a[3],&a[4]};
	int **q = p;
	for(q = p;q < p+5;q++)
		printf("%d\n",**q);
	q = p;
	printf("%d\n",**(q+3));
	return 0;
}
#endif


#if 0
#include <malloc.h>
#include <string.h>
/*
指针作为函数参数传递，并修改指针所指向的空间
注意：参数传递的几种类型
1.在子函数中修改实参的值，就需要传递实参本身的地址
（不同的时间修改同一段内存空间里面的内容）
2.在子函数中不需要修改实参的值，传递值本身
（在不同的时间里修改不同的空间里面的内容）
*/
void mymalloc(char **p,int *b)
{
	*p = (char*)malloc(100); //
	/*开辟100个连续的内存空间，并将所开辟的空间的首地址赋值给*p*/

	*b = 6;
}
int main()
{
	char *str = NULL;
	int a = 0;
	mymalloc(&str,&a); //注意参数的传递
	printf("%d\n",a);
	strcpy(str,"hello");
	puts(str);
	free(str);
	str = NULL;
	return 0;
}
#endif

#if 0
#include <string.h>
#include <malloc.h>
char *GetMalloc()
{
	//char a[100];
	//return a; //返回指向栈内存的指针
	char *a = (char*)malloc(100);
	return a;
}
int main()
{
	char *str = NULL;
	str = GetMalloc();//str = a
	strcpy(str,"helloworld");
	puts(str);
	free(str);
	str = NULL;
	return 0;
}
#endif

#if 0
void fn(char a[10],int n)//char *a
{
	printf("%d\n",sizeof(a));
}
int main()
{
	char a[100];
	printf("%d\n",sizeof(a));
	fn(a,5);
	return 0;
}
#endif


/*
讨论作业：
#if 0
char *c[] = { "ENTER", "NEW", "POINT", "FIRST" }; 
char **cp[] = { c+3, c+2, c+1, c }; 
char ***cpp = cp; 

int main(void)
{ 
	printf("%s\n", **++cpp); 
	printf("%s\n", *--*++cpp+3);
	printf("%s\n", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1); 
	return 0;
}
#endif

#if 0
int main()  
{  
    char *str[]={"welcome","to","Fortemedia","Nanjing"};  
    char**p=str+1; 
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
*/

#if 1
int inc(int a)
{
    return(++a);
}
int multi(int*a,int*b,int*c)
{
    return(*c=*a**b);//
}
typedef int (FUNC1)(int in);
typedef int (FUNC2)(int*,int*,int*);
void show(FUNC2 fun,int arg1, int*arg2)
{
    int (*p)(int)=&inc;
    int temp =p(arg1);//11
    fun(&temp,&arg1, arg2);
    printf("%d\n",*arg2);
}
int main()
{
    int a;
    show(multi,10,&a);
    return 0;
}
#endif