#include <iostream>
#include <cstring>

using namespace std;

void ReplaceBlank(char  str[], int len, int cap)
{
	char *pStr = str;
	if (NULL == str || len <= 0)
	{
		return;
	}

	int newLength = 0, numberOfBlank = 0;
	while (*pStr != '\0') 
	{
		if (*pStr == ' ')
		{
			numberOfBlank++;
		}

		pStr++;
	}

	newLength = len + 2 * numberOfBlank;
	cout << newLength << endl;
	
	//加上'/0'的长度
	if (newLength + 1 > cap)
	{
		return;
	}

	int indexOfNew = newLength, indexOfOriginal = len;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		indexOfOriginal--;
	}

	str[newLength] = '\0';
}

int main() 
{
	char str[30] = "We are happy.";
	
	cout << sizeof(str) << " " << strlen(str) << endl;
	
	ReplaceBlank(str, strlen(str), sizeof(str));
	cout << str << endl;

	return 0;
}