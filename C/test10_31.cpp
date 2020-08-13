#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#if 0
/*1.求n!*/    
int getFac(int n) 
{
	int fac = 1;
	for (int i = 1; i < n+1; i++)
	{
		fac =  fac * i;
	}

	return fac; 
}

int main()
{
	int fac = getFac(5);

	printf("%d\n", fac);

	return 0;
}
#endif

#if 0
/*
* 有一个一维数组，内放10个学生成绩，写一个函数，求出平均分，最高分和最低分
*/
//求平均数
double getAvg(const double *a, int length)
{
	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += a[i]; 
	}

	return sum/length;
}

//求最高分
double getMax(const double *a, int length)
{
	double max = a[0];
	for (int i = 1; i < length; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	return max;
}

//求最低分
double getMin(const double *a, int length)
{
	double min = a[0];
	for (int i = 0; i < length; i++)
	{
		if (a[i] < min)
			min = a[i];
	}

	return min;
}

int main()
{
	double score[10] = {10.5, 11, 12, 9, 8, 15, 5, 16, 4, 10};
	int n = sizeof(score)/sizeof(score[0]);

	double avg = getAvg(score, n);
	printf("averag = %lf\n", avg);

	double max = getMax(score, n);
	printf("max = %lf\n", max);

	double min = getMin(score, n);
	printf("min = %lf\n", min);

	return 0;
}
#endif

#if 0
/*
* 写一个函数，使给定的一个二维数组（3*3）转置
*/
void trans(int matrix[3][3], int row, int col)
{ 
	for (int i = 0; i < row; i++)
	{ 
		for (int j = i+1; j < col; j++)
		{
			
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
		}
	}
}

int main()
{
	int matrix[][3]= {{1, 2, 3},
					  {4, 5, 6},
					  {7, 8, 9}};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(*(matrix+i)+j));
		}
		printf("\n");
	}
	printf("\n");

	trans(matrix, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(*(matrix+i)+j));
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
/*
写一个函数，将一个字符串中的元音字母复制到另一个字符串，然后输出
*/
//判断字符是否是元音
bool isVowel( const char ch)
{
	char vowel[] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < sizeof(vowel); i++)
	{
		if (ch == vowel[i] || ch == toupper(vowel[i]))
		{
			return true;
		}
	}

	return false;
}

//将字符串src中的元音字母复制到另一个字符串dest中
void getVowel(const char *src, int length, char *dest)
{
	char *pdest = dest;
	for (int i = 0; i < length; i++)
	{
		if (isVowel(src[i]))
		{
			*pdest++ = src[i]; 
		}
	}
}

int main()
{
	char str[] = "hello worldABCE!";
	char dest[10] = {0};

	getVowel(str, sizeof(str), dest);

	printf("%s\n", dest);

	return 0;
}
#endif

#if 0
/*
写一个函数，输入一个4位数，要求输出这4个数字字符，但每两个数字间空一个空格。
输入: 1990
输出: 1 9 9 0
*/
void outWithSpace(int num, char *str, int length)
{
	sprintf(str, "%d", num);
	int len = strlen(str);
	for (int i = len-1, j = len-1; i > 0 && j>0 && i+j < length; i--, j--)
	{
			str[i+j] = str[i];	
	}

	//奇数位全为空格
	for (int i = 1; i < length; i+=2)
		str[i] = ' ';
}

int main()
{
	int num = 1990;
	char str[10] = {0};
	int length = sizeof(str);

	outWithSpace(num, str, length);
	printf("%s\n", str);

	return 0;
}
#endif

#if 0
/*
写一个函数，输入一行字符，将此字符串中的最长的单词输出
*/
void outputLgst(char *src)
{
	char *str = NULL;
	char tok[] = ", .;";
	char word[10][10] = {0};
	int maxLen = 0, count = 0, i = 0;

	for (str = strtok(src, tok); str != NULL; str = strtok(NULL, tok))
	{
		count++;				  	  //计数
		strcpy(word[i++], str); 	  //将获取到的单词保存到word中
	}

	//找到最长的单词并记录其长度
	maxLen = strlen(word[0]);
	for (int i = 1; i < count; i++)
	{
		if (strlen(word[i]) > maxLen)
			maxLen = strlen(word[i]);
	}

	//将最长的单词输出，可能有多个
	for (int i = 0; i < count; i++)
	{
		if (strlen(word[i]) == maxLen)
			printf("%s\n", word[i]);
	}
}

int main()
{
	char str[] = " look at me, this is a book";
	outputLgst(str);

	return 0;
}
#endif

#if 0
/*
写几个函数：
	1.输入10个职工的姓名和职工号；
    2.按职工号由小到达顺序排序，姓名顺序也随之调整;
    3.输入一个职工号，用折半查找法找出该职工姓名
*/
typedef struct student
{
	int ID;
	char name[10];
}STU;

void read(STU *stu, int length)
{
	int i;
	for (i = 0; i < length; i++)
		scanf("%d %s", &stu[i].ID, stu[i].name);
}

void print(const STU *stu, int length)
{
	int i;
	for (i = 0; i < length; i++)
		printf("%d\t%s\n", stu[i].ID, stu[i].name);
}

void sort(STU *stu, int length)
{
	int i, j;
	STU t;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length-i-1; j++)
		{
			if (stu[j].ID > stu[j+1].ID)
			{
				t = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = t;
			}
		}
	}
}

//在数组stu的前n个元素中查找ID号为id的元素，返回该元素第一次在数组中出现的下标
 int bin_search(STU *stu, int n, int id)
{
	int head = -1, tail = n, mid = -1;
	int pos = -1;

	while (head + 1 != tail)
	{
		mid = (head+tail) / 2;

		if (id > stu[mid].ID)
			head = mid;
		else
			tail = mid;
	}

	pos = tail;
	if (pos >= n || stu[pos].ID != id )
		pos = -1;

	return pos;
}

int main()
{
	STU stu[10];
	int id = -1;
	int n = sizeof(stu)/sizeof(stu[0]);

	printf(_T("please input:\n"));
	read(stu, n);
	sort(stu, n);
	print(stu, n);
	printf("\n");

	printf(_T("input ID：\n"));
	scanf("%d", &id);
	int pos = bin_search(stu, n, id);
	printf("%d\t%s\n", stu[pos].ID, stu[pos].name);

	return 0;
}
#endif

#if 0
/*
用递归方法求n阶勒让德多项式(legendre polynomials)的值，递归公式为：

            1                                      (n=0)
    pn(x) = x                                      (n=1)
           ((2n-1)*x -pn-1(x) - (n-1)*pn-2(x))/n   (n>=1)
*/ 

double poly(int n, int x)
{
	if (0 == n)
		return 1;
	else if (1 == n)
		return x;
	else
		return (double)((2*n-1) * x - poly(n-1, x) - (n-1)*poly(n-2, x))/n;
}

int main()
{
	double result = poly(2, 5);
	printf("result = %lf\n", result);

	return 0;
}
#endif

#if 0
/*
* 写一个函数，输入一个十六进制数，输出相应的十进制。
*/

int convert_to_dec(char *hex)
{
	int dec = 0;
	char *validNum = hex + 2;
	int len = strlen(validNum);	//除去十六进制0x标志

	char ch[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	for (int j = len-1; j >= 0; j--)
	{
		for (int i = 0; i < sizeof(ch); i++)
		{
			if (ch[i] == *validNum)
			{
				validNum++;
				dec += i*pow(16, j);
				break;
			}
		}
	}

	return  dec;
}

int main()
{
	char hex[10] = {0};
	printf("please input hex: ");
	scanf("%s", hex);

	int dec = convert_to_dec(hex);
	printf("\nhex = %s\ndec = %d\n",hex, dec);

	return 0;
}
#endif

#if 1
/*
* 用递归法将一个整数n转换成字符串。
*/
char* convert(int num, char *dest)
{
	char * p = dest;

	if (num / 10 != 0)
	{		
		p = convert(num / 10, p);
	}

	*p = num % 10 + '0';//将数字转化为字符   
	++p;
	*p = '\0';			//为字符最后添加'\0'   

		return p;
}

int main()
{
	int num = 0;
	char dest[10] = { 0 };

	printf("Please input a number : ");
	scanf("%d", &num);

	convert(num, dest);
	printf("num : %d  	str : %s\n", num, dest);
	return 0;
}
#endif

#if 0
/*
	    有两个数组a.b，各有10个元素，将它们对应的逐个相比，如果a数组中的元素大于b数组中的相
	应元素的数目多于b数组中元素大于a数组中相应元素的数目，则认为a数组大于b数组，并分别统计出
	两个数组相应元素大于，等于，小于的次数。
*/

const int size = 10;
bool isAlargerThanB(int *a, int *b, int result[])
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == b[i])
			result[2]++;
		else if (a[i] > b[i])
			result[0]++;
		else
			result[1]++;
	}
	if (result[0] < result[1])
		return false;

	return true;
}

int main()
{
	int a[size] = {1, 2, 3, 1, 5, 6, 7 ,8, 9, 10};
	int b[size] = {1, 2, 3, 5, 7, 4, 3, 8, 8, 9} ;
	//result[0]存放a中元素大于b中元素的个数，result[1]存放a中元素小于b中元素的个数，result[2]存放a中元素等于b中元素的个数
	int result[3] = {0};	

	if (isAlargerThanB(a, b, result))
		printf("a > b\ngreter : %d\nless : %d\nequal : %d\n", result[0], result[1], result[2]);
	else
		printf("a <= b\ngreter : %d\nless : %d\nequal : %d\n", result[0], result[1], result[2]);
}
#endif