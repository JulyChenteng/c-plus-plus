#include <stdio.h>
#include <math.h>

#if 0 
/*Pi/4 = 1-1/3+1/5-1/7+1/9+...*/
int main()
{
	int a = 1, b = 1;
	double t = 1.0;
	double s = 0.0;

	while (fabs(t) >= 1e-6)
	{
		s = s + t;
		a = (-1) * a;
		b = b + 2;
		t = (double)a/b;
	}

	printf("%lf\n", 4*s);

	return 0;
}
#endif 

#if 0
/*Fibonacci数列前四十个数的递归实现*/
int Fab(int n)
{
	if (1 == n || 2 == n)
		return 1;
	else
		return Fab(n-2) + Fab(n-1);
}

int main()
{
	int num = 0;

	for (int i = 1; i <= 40; i++)
	{
		num = Fab(i);
		printf("%d  ", num);
	}

	printf("\n");

	return 0;
}
#endif


#if 0
/*求Fabonacci数列的前四十个数的非递归实现*/
int main()
{
	int i = 1;
	int num = 0, a = 0, b = 0;

	while (i <= 40)
	{
		if (i == 1 || i==2)
		{
			a = 1;
			b = 1;
			printf("1  ");
		}
		else
		{
			num = a + b;
			a = b;
			b = num;

			printf("%d ", num);
		}

		i++;
	}

	printf("\n");

	return 0;
}
#endif 

#if 0
/*判断一个数是否是素数*/
bool is_prime(int n)
{
	if ((n & 1) != 0)
	{
		int limit = (int)sqrt(n);

		for (int div = 3; div <= limit; div += 2)
		{
			if ((n % div) == 0)
				return false;
		}

		return true;
	}

	return (n == 2);	
}

int main()
{
	int num;
	
	scanf("%d", &num);

	if (is_prime(num))
	{
		printf("%d 是素数！\n", num);
	}
	else
	{
		printf("%d 不是素数！\n", num);
	}
	
	return 0;
}
#endif

#if 0
/*输入一行字串，分别统计其中字母、数字、空格、和其他字符的个数*/
int main()
{
	char ch;
	int a = 0, b = 0, c = 0, d = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			a++;
		else if (ch >= '0' && ch <= '9')
			b++;
		else if (ch == ' ')
			c++;
		else 
			d++;
	}

	printf(" 字母个数：%d\n 数字个数：%d\n 空格个数：%d\n 其他字符个数：%d\n\n", a, b, c, d);

	return 0;
}
#endif

#if 0
/*求1+2!+3!+...+20!之和*/
int main()
{
	double sum = 0, t = 1;
	int i = 1, n = 20;\

	while (i <= n)
	{
		t = t*i;
		sum = sum + t;
		i++;
	}

	printf("%lf\n", sum);

	return 0;
}
#endif

#if 0
/*
打印所有的水仙花数，所谓水仙花数是指一个3位数，其各位数字立方和等于该数本身。
例如：153 = 1*1*1 + 5*5*5 + 3*3*3 
*/
int main()
{
	int num = 0;
	int a = 0, b = 0, c = 0;

	for (num = 100; num < 1000; num++)
	{
		a = num / 100;        //求百位数
		b = (num / 10) % 10;  //求十位数
		c = num % 10;         //求个位数

		if (num == (a*a*a + b*b*b + c*c*c))
			printf("%d  ", num);
	}

	printf("\n");

	return 0;
}
#endif

#if 0
int main()
{
	char ch = 'A';
	int k = 0, j = 0;

	for (int i = 0; i < 7; i++)
	{
		if (i < 4)
		{
			for (k = 0; k < 4-i; k++)
				printf(" ");
			for (int j = 0; j < 2*i+1; j++)
			{
				printf("%c", ch);
			}
		}
		else
		{
			for (k = 0; k < i-2; k++)
				printf(" ");
			for (j = 0; j <13-2*i; j++)
				printf("%c", ch);
		}

		printf("\n");
		ch += 1;
	}

	return 0;
}
#endif 

#if 0
int main()
{
	char ch;
	int k = 0, j = 0;

	for (int i = 0; i < 4; i++)
	{
		for (k = 0; k < 4-i; k++)
			printf(" ");

		for (int j = 0, ch = 65; j < i+1; j++, ch += 1)
		{			
			printf("%c", ch);
		}

		ch = ch-2; //注意ch会在上面循环中多加一次，所以减2
		for (int h = 0; h < i; h++, ch--)
			printf("%c", ch);


		printf("\n");
	}

	return 0;
}
#endif

#if 0
/*有一分数序列：2/1，3/2，5/3, 8/5，13/8，21/13...求这个数列的前20项之和*/
int main()
{
	int n = 1, m = 1, j = 1;
	double sum = 0.0, temp = 0.0;

	for (int i = 0; i < 3; i++)
	{
		m = m + n;
		n = j;
		temp = (double)m / n;
		j = m;
		sum = sum + temp;
	}

	printf("%lf\n", sum);

	return 0;
}
#endif



#if 1
/*输入两个数，m，n，求其最大公约数和最小公倍数*/
int main()
{
	int m = 16, n = 12;
	int t = m < n ? m : n;
	int i;
//	for(i=1;i<=t;i++);
	for(i = t;i>=1;i--)
	{
		if(m %i==0&&n%i==0)
		{
			printf("%d\n",i);
			break;
		}
	}
	t = m>n?m:n;
	for(i = t;i<=m*n;i++)
	{
		if(i%m==0&&i%n==0)
		{
			printf("%d\n",i);
			 break;
		}
	}
	//printf("%d\n",m*n/i);
	return 0;
}
#endif

#if 0
/*一个数如果恰好等于它的因子之和，这个数就称为“完数”，编程找出1000之内的所有完数，并打印输出*/
int main()
{
	int num = 0;

	for(int n = 2; n < 1000; n++)
	{
		num = n;
		for (int i = 1; i < n; i++)
		{	
			if ((n % i) == 0)
			{
				num = num -i;
			}	
		}

		if (0 == num)
		{
			printf("%d \n", n);
		}
	}

	printf("\n");

	return 0;
}
#endif


#if 0
/*用迭代法求x = sqrt(a), 迭代公式为：Xn+1 = 1/2(Xn + a/Xn), 要求前后两次求出的x的差的绝对值小于1e-5*/
int main()
{
	double x1 = 0, x2 = 1;
	int a = 100;


	while (fabs(x1-x2) >= 1e-5)
	{
		x1 = x2;
		x2 = (double)1/2 *(x1 + 4/x1);	
	}

	printf("%lf\n", x2);

	return 0;
}
#endif

