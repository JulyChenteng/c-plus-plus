#include <stdio.h>

/*
数组：构造数据类型
特点：是一个有序数据的集合,在内存里面占据一段连续的内存空间
数组里面的元素类型都是一样的
*/
#define N 10
#if 0
int main()
{	
	/*
	int a[10] = {1,2,3,4,7};
	int i;
	printf("%d,%d,%d\n",&a[0],&a[1],&a[2]);
	printf("%d\n",sizeof(a));
	printf("%d,%d,%d\n",a,a+1,a+2);
	for(i = 0;i<10;i++)
		scanf("%d",&a[i]);
	for(i =0;i<10;i++)
		printf("%d ",a[i]);
	*/

	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int n = sizeof(a)/sizeof(a[0]);

	int i,j;
	//...
	int t;
	/*
	for(i = 0;i<n/2;i++)
	{
		t = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = t;
	}*/
	for(i = 0,j = n-1;i<j;i++,j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	for(i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
#endif
/*
5 4 1 2 3 0 9 7 8 6
4 1 2 3 0 5 7 8 6 9  1  i   j
1 2 3 0 4 5 7 6 8 9  2
*/
#if 1
int main()
{
	int a[] = {5,4,1,2,3,0,9,7,8,6};
	int n = sizeof(a)/sizeof(a[0]);
	int t,i,j;
	int flag = 1;
	for(i = 1;i<n && flag == 1;i++) //趟数
	{
		flag = 0;
		for(j = 0;j<n-i;j++)
		{
			if(a[j] > a[j+1]) //相邻的两个数
			{
				flag = 1;
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
#endif

/*
5 4 1 2 3 0 9 7 8 6  i
          k
0 4 1 2 3 5 9 7 8 6

*/

#if 0
int main()
{
	int a[] = {5,4,1,2,3,0,9,7,8,6};
	int n = sizeof(a)/sizeof(a[0]);
	int t,i,j,k;
	for(i = 0;i<n;i++)
	{
		k = i; //假定当前i为最小数位置
		for(j = i+1;j<n;j++)//从当前位置往后找比k位置小的数据
		{
			if(a[k] > a[j]) //找到比k位置小的数字
				k = j;
		}
		if(k != i) //最小数不在最终要放的位置
		{
			t = a[k];
			a[k] = a[i];
			a[i] = t;
		}
	}
	for(i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
#endif

/*
作业：
1.用pi/4 ~ = 1-1/3+1/5-1/7+...公式求pi的近似值，直到某一项的绝对值小于1e-6为止。

2.编程求Fibonacci数列前40个数，这个数列有如下特点:第1，2两个数为1，1，从第3个数开始，该数
  
  是其前面两个数之和。即：F1 = 1(n=1) F2 = 1(n=2) Fn = Fn-1 + Fn-2(n>=3)。

3.判断所输入的数字是否为素数。

4.输入两个整数m和n，求其最大公约数和最小公倍数

5.输入一行字符，分别统计其中英文字母，空格，数字和其他字符的个数。

6.编程：Sn = a+aa+aaa+aaaa+...aa..a(n个a)之和，其中a是一个数字，n由键盘输入。

7.编程：Sn = 1! + 2! + 3! + ...+ 20!;

8.打印所有的水仙花数，所谓水仙花数是指一个3位数，其各位数字立方和等于该数本身。

  例如：153 = 1*1*1 + 5*5*5 + 3*3*3

9.一个数如果恰好等于它的因子之和，这个数就称为“完数”，编程找出1000之内的所有完数，并输出

10.用迭代法求x = sqrt(a),迭代公式为：
xn+1 = 1/2(xn + a / xn),要求前后两次求出的
x的差的绝对
  值小于1e-5。

  while(fabs(x1-x2)>=1e-5)
  {
	 x1 = x2;
	 x2 = 1.0/2*(x1+a/x1);
  }
11.打印出下面图案：
   A
  BBB
 CCCCC
DDDDDDD
 EEEEE
  FFF
   G 


       A
      ABA    
     ABCBA
    ABCDCBA
    

12.有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。

*/
