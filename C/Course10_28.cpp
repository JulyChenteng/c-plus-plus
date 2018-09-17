#if 0
int main()
{
	int a[3][4] = {{1},{2},{3}};
	int b[4][3];
	//a(int (*)[4]),a[0](int*),a[0][0](int)
	//a[0][0] ~a[2][3]
	printf("%d,%d\n",a,a+1);
	printf("%d,%d\n",a[0],a[0]+1);
	printf("%d,%d\n",sizeof(a),sizeof(a[0]));

	return 0;
}
#endif
#if 0
int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int i,j,t;
	for(i = 0;i<3;i++)
	{
		for(j = 0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	for(i = 0;i<3;i++)
	{
		//for(j=0;j<i;j++)
		for(j = i;j<3;j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}
	for(i = 0;i<3;i++)
	{
		for(j = 0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
#endif
/*
2016.10.28
1.0,0,0总共多少天
2.在当前日期上加上n天得出新的日期
*/
#if 0
int a[2][13] = {{0,31,29,31,30,31,30,31,31,30,31,30,31},
{0,31,28,31,30,31,30,31,31,30,31,30,31}};
int leapYear(int y)
{
	if(y%4==0&&y%100!=0 || y%400 ==0)
		return 1;
	else
		return 0;
}
int main()
{
	int y = 2016,m = 10,d = 28;
	int s = 0;
	int i;
	for(i = 1;i<2016;i++)
	{
		if(leapYear(i))
			s = s + 366;
		else
			s = s + 365;
	}
	if(leapYear(y))
	{
		for(i = 1;i<m;i++)
			s = s + a[0][i];
	}
	else
	{
		for(i = 1;i<m;i++)
			s = s + a[1][i];
	}
	s = s + d;
/*	s = s + n;
	i = 1;
	while(1)
	{
	if(s < 365)
	break;
	if(leapYear(i))
	s = s - 366;
	else
	s = s - 365;
	i++;
	}
*/
	return 0;
} 
#endif
/*
strcpy,strncpy
strcmp,strncmp
strlen:  size_t strlen( const char *string );
strcat
strtok
memcpy,memcmp,memset
*/

#include <string.h>
#if 0
int main()
{
/*	char a[3][20];
	int i;
	for(i = 0;i<3;i++)
		gets(a[i]);
	for(i = 0;i<3;i++)
		puts(a[i]);
		*/
/*
	char a[50];
	int i,s = 0;
	gets(a);
//	printf("%d\n",strlen(a));
	for(i = 0;a[i] != '\0';i++)
		s++;
	printf("%d\n",s);
	*/

	char a[20] = "1234567";
	char b[20] = "134";
//	puts(strcpy(a,b));
//	puts(strncpy(a,b,1));
//	puts(a);

	int n ;
	n = strcmp(a,b);
	printf("%d\n",n);
	strcat(a,b);
	puts(a);
	return 0;
}
#endif
#if 0
//11.输入一行字符，统计其中有多少个单词，单词之间用',', '.', ';', ' '隔开。
int main()
{
	char a[50] = "i am,a.student;asd";
	char b[] = "; .,";
	char *tok = NULL;
	int n  = 0;
	for(tok = strtok(a,b);tok != NULL;
		tok = strtok(NULL,b))
	{
		n++;
		puts(tok);
	}
	printf("%d\n",n);
	return 0;
}
#endif

#if 0
void main()
{
	char a[20] = "12345678";
	char b[20] = "qwert";
//	int i = 0;
//	for(i = 0;b[i] != '\0';i++)
	//	a[i] = b[i];
//	a[i] = '\0';
//	puts(a);
#if 0
	int n;
	while(a[i] != '\0'&&b[i]!='\0'&&a[i]==b[i])
		i++;
	n = a[i] - b[i];
	if(n  > 0)
		printf("a>b\n");
	else if(n == 0)
		printf("a == b\n");
	else
		printf("a < b\n");
#endif

	int i,j;
	for(i = 0;a[i] !='\0';i++)
		;
	for(j = 0;b[j] != '\0';j++)
		a[i+j] = b[j];
	a[i+j] = '\0';
	puts(a);

}
#endif

/*
作业：
1.有三个字符串，要求找出其中最大者。

2.用筛选法求100之内的素数 //ok

3.求一个3*3的整形矩阵对角线元素之和。

//ok
4.已有一个已排好序的数组，今输入一个数，
要求按原来排序的规律将它插入数组中。

5.将一个数组中的值按逆序重新存放。 //ok

6.打印杨辉三角形（前10行） //ok

7.用折半查找法查找数组中一个指定的数字，并输出第几个。

8.编程，写一个程序，将两个字符串链接起来，不要用strcat函数。

9。编程，写一个函数，编写strcmp函数

10.编写strcpy函数。

11.输入一行字符，统计其中有多少个单词，单词之间用空格隔开。

12.输出字符串A和字符串B的最长公共单词

14.有一行电文，已按下面规律译成密码：
   A->Z  a->z  B->Y  b->y   C->X  c->x
   即第1个字母变成第26个字母，第i个字母变成第（26-i+1）个字母，非字母字符不变，要求编程将密码译回原文，并打印出密码和原文。

15.日期题目

16.求数字个数

17.求两个int数组相乘的结果

18.输出100以内平方是回文的数字
*/
