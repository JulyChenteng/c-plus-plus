#include <stdio.h>
#include <string.h>

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
			
			//由长到短求子串
			for (int m = 0; m < j-i && j>i; m++, k++)
			{
				temp[m] = a[k];
			}

			if (strstr(b, temp) > NULL)
			{
				n = j - i;
				t = temp;
				printf("%s\n", t);
			}
		}
	}

	return 0;
}