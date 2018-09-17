#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#if 0
/*有三个字符串，要求找出其中最大者*/
char* CmpStr(char *str1, char *str2, char *str3)
{
	if (strcmp(str1, str2) > 0)
	{
		if (strcmp(str1, str3) > 0)
			return str1;
		else
			return str3;
	}
	else if (strcmp(str2, str3) > 0)
	{
		return str2;
	}
	else
	{
		return str3;
	}
} 

int main()
{
	char str1[] = "hello";
	char str2[] = "chenteng";
	char str3[6] = "happy";

	char *maxStr = CmpStr(str1, str2, str3);

	printf("%s, %s, %s中最大的一个为：%s\n", str1, str2, str3, maxStr);

	return 0;	
}
#endif

#if 0
/*用筛选法求出100以内的素数*/
int main()
{
	int a[101];
	int i = 0, j = 0;

	for (i = 1; i < 101; i++)
		a[i] = i;

	a[1] = 0;
	for (i = 2; i < sqrt(100); i++)
	{
		for (j = i+1; j < 100; j++)
		{
			if (a[j] != 0 && a[i] != 0)
			{
				if (a[j] % a[i] == 0)
					a[j] = 0;
			}
		}
	}

	for (int i = 1; i < 100; i++)
	{
		if (a[i] != 0)
			printf("%d ", i);
	}

	printf("\n");

	return 0;	
}
#endif

#if 0
/*求一个三乘三的矩阵对角线之和*/
int main()
{
	int a[3][3] = {{5, 2, 3}, {4, 6, 6}, {7, 8, 9}};
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				sum1 += a[i][j];
			if (i+j == 2)
				sum2 += a[i][j];			
		}
	}

	printf("主对角线之和：%d\n", sum1);
	printf("次对角线之和：%d\n", sum2);

	return 0;	
}
#endif

#if 0
/*已有一个已排好序的数组，输入一个数，要求按原来的排好的顺序插入数组*/

//数组a长度为length，给其前n个元素从小到大排序
void sort(int a[], int length, int n)
{
	assert(n <= length);
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n -i-1; j++)//j<n-1防止数组访问越界
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void insert_arr(int *a, int length, int *n, int x)
{
	int count = *n;
	int k = -1;
	int i;
	assert(count < length);

	for (i = 0; i < count; i++)
	{
		if (x < a[i])
			break;
	}
	k = i;
	for (i = count; i > k; i--)
		a[i] = a[i - 1];

	a[k] = x;
	(*n)++;
}

int main()
{
	int a[20] = { 1, 3, 5, 4, 2, 6, 7, 9, 100, 8};
	int length = sizeof(a) / sizeof(int);
	int count = 10;

	sort(a, length, count);
	insert_arr(a, length, &count, 3);
	insert_arr(a, length, &count, 20);
	insert_arr(a, length, &count, 50);
	insert_arr(a, length, &count, 101);

	for (int i = 0; i < count; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	return 0;
}
#endif

#if 0
/*将一个数组中的值按逆序重新存放*/
int main()
{
	int a[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int temp = 0;
	int n = sizeof(a)/sizeof(int);
	
	printf("原始数据：\n");
	for (int i = 0; i< n; i++)
		printf("%d ", a[i]);
	printf("\n");

	for (int i = 0, j = n-1; i < j; i++, j--)
	{	
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	printf("逆序后：\n");
	for (int i = 0; i< n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;	
}
#endif

#if 0
/*打印杨辉三角前十行*/
int main()
{
	int a[10][10];
	int i,j;
	
    for(i=0; i <= 9; i++)
	{
		for (j=0; j<=i; j++)
		{
			if (i==j || j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1] + a[i-1][j];
			
			printf("%5d",a[i][j]);
		
		}
		
		printf("\n");
	}
	
	return 0;	
}
#endif 

#if 0
/*用折半查找法查找数组中一个指定的数字，并输出第几个*/
//在数组a的前n个元素中查找x元素，返回该元素第一次在数组中出现的下标
int bin_search(int *a, int n, int x)
{
	int head = -1, tail = n, mid = -1;
	int pos = -1;

	while (head+1 != tail)
	{
		mid = (tail+head) / 2;

		if (x > a[mid])
			head = mid;
		else
			tail = mid;

		//assert(head+1 == tail && x > a[head] && x <= a[tail]);
	}

	pos = tail;
	if (pos >= n || a[pos] != x)
		pos = -1;

	return pos;
}

int main()
{
	int a[] = {1, 3, 4, 2, 9, 7, 10, 8, 4, 3};
	int pos = bin_search(a, 10, 4);

	printf("4-Pos(下标从零开始): %d\n", pos);

	return 0;
}
#endif

#if 0
/*写一个程序，将两个字符串链接起来，不要用strcat函数*/
void strc(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	const char *psrc = src;
	
	
	while (*pdest != '\0')
		pdest++;

	while ((*pdest++ = *psrc++) != '\0')
		;
}

int main()
{
	char str1[] = "hello";
	char str2[] = "wangwu";
    
    strc(str1, str2); 

    printf("%s\n", str1);

	return 0;
}
#endif

#if 0
/*编写strcmp函数*/
int my_strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);

	const char *pstr1 = str1;
	const char *pstr2 = str2;

	for (; *pstr1 == *pstr2; pstr1++, pstr2++)
	{
		if (*pstr1 == '\0')
			return 0;
	}

	return (*pstr1 > *pstr2) ? 1 : -1;
}

int main()
{
	char str1[] = "hello";
	char str2[] = "hellp";

	int result = my_strcmp(str1, str2);
	printf("%d\n", result);

	return 0;
}
#endif

#if 0
/*编写strcpy函数*/
void my_strcpy(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	const char *psrc = src;

	while (*psrc != '\0')
		*pdest++ = *psrc++;

	*pdest = '\0';
}

int main()
{
	char str[] = "hello";
	char str1[] = {'1', 'a', 'c', 'b', 'd', 'e', 'f', 'g'};

	my_strcpy(str, str1);

	printf("%s\n", str);

	return 0;
}
#endif
#if 0
/*输入一行字符，统计其中有多少个单词，单词之间用空格隔开。*/
int main()
{
	char a[50] = "i am a student asd";
	char *tok = NULL;
	int n  = 0;

	for(tok = strtok(a, " "); tok != NULL; tok = strtok(NULL, " "))
	{
		n++;
		puts(tok);
	}

	printf("%d\n",n);
	return 0;
}
#endif

#if 0
/*输出字符串A和字符串B的最长公共单词*/
int main()
{
	char a[] = "I, am;a good hate";
	char b[] = "c I am good hate";
	char tok[] = ",. ;";	  //截取标记
	char *str = NULL;		  //保存临时获取的单词
	char word[10][10] = {0};  //保存a中的单词

	int count = 0;		//保存获取到的a中的单词个数
	int length = 0;		//保存字符串长度

	int i = 0;
	//获取a中的单词
	for (str = strtok(a, tok); str != NULL; i++,  str = strtok(NULL, tok))
	{
		count++;				  //计数
		strcpy(word[i], str); //将获取到的单词保存到word中
	}
	
	//获取b中的每个单词，并与a中的单词作比较，如果相等，则记录最长字符串的长度
	for (str = strtok(b, tok); str != NULL; str = strtok(NULL, tok))
	{
		for (i = 0; i < count; i++)
		{
			if (strcmp(word[i], str) == 0)
			{
				if (strlen(word[i]) > length)
					length = strlen(word[i]);
			}
		}
	}

	//将a与b共有的单词中最长的打印输出
	for (int i = 0; i < count; i++)
	{
		if (strlen(word[i]) == length)
			puts(word[i]);
	}
	return 0;
}
#endif

#if 0
/*
有一行电文，已按下面规律译成密码： 
   A->Z  a->z  B->Y  b->y   C->X  c->x
即第1个字母变成第26个字母，第i个字母变成第（26-i+1）个字母，非字母字符不变，
要求编程将密码译回原文，并打印出密码和原文。
*/
int main()
{
	char a[] = "Aa,b1123cC";
	int n = strlen(a);

	for (int i = 0; i < n; i++)
	{
		if (islower(a[i]))//a[i] >= 'a' && a[i] <= 'z'
		{
			a[i] = a[i] + (25-2*(a[i]-'a'));
		}
		else if (isupper(a[i]))//a[i] >= 'A' && a[i] <= 'Z'
		{
			a[i] = a[i] + (25-2*(a[i]-'A'));
		}
	}

	puts(a);
	printf("%d\n",n);

	return 0;
}
#endif

#if 0
/*日期题目*/
int main()
{
	return 0;
}
#endif

#if 0
/求数字个数*/
int main()
{
	return 0;
}
#endif

#if 0
/*求两个int数组相乘的结果*/
/*
C = A*B;
当矩阵A的列数等于矩阵B的行数时，A与B可以相乘。
矩阵C的行数等于矩阵A的行数，C的列数等于B的列数。
乘积C的第m行第n列的元素等于矩阵A的第m行的元素与矩阵B的第n列对应元素乘积之和。
*/
int main()
{
	//矩阵相乘必须让两个数组的一个的行数与另一个列数相等
	int a[2][3] = {1 ,2 ,3, 4, 5, 6};
	int b[3][4] = {2, 4, 6, 3, 5, 7, 8 ,9, 2, 5, 7 , 8};
	int mul[2][4] = {0};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 3; k++)
			 	mul[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%-3d ", mul[i][j]);

		printf("\n");
	}

	return 0;
}
#endif

#if 0
/*输出100以内平方是回文的数字*/
int main()
{
	int i = 0, m = 0;
	int num = 0, sum = 0;

	for (i = 1; i < 100; i++)
	{
		m = i * i;
		num = m;
		sum = 0;
		while (m)
		{
			sum = sum*10 + m%10;
			m = m / 10;
		}
		
		if (sum == num)
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;
}
#endif

#if 1
/*输出字符串A和字符串B的最长公共子串*/
int main()
{
	char a[] = "serdlfffd";
	char b[] = "sslserddfj";
	int n = 0;
	char *t = NULL;

	for (int i = 0; i < sizeof(a); i++) {
		for (int j = sizeof(a); j>i && j - i>n; j--)
		{
			char temp[10] = { 0 };
			int k = i;
			for (int m = 0; m<j - i && j>i; m++, k++)
			{
				temp[m] = a[k];
			}
			if (strstr(b, temp) != NULL)
			{
				n = j - i;
				t = temp;
				printf("%s\n", t);
			}
		}
	}
	
	return 0;
}
#endif