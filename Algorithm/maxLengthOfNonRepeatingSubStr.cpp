#include <iostream>
#include <string>
using namespace std;

/*
 *寻找最长不含有重复字符的子串
*/
int maxLegnthOfNonRepeatingSubStr(string str) 
{
	const char *bytes = str.c_str();
	cout << bytes << " ";

	int lastOccurred[256] = {-1};
	int maxLength = 0, start = 0, lastI = 0;

	for (int i = 0; i < str.length(); i++) 
	{
		lastI = lastOccurred[str[i]];

		if (lastI >= start)
		{
			start = lastOccurred[str[i]];
		} 

		if (i-start > maxLength) 
		{
			maxLength = i - start;
		}
		lastOccurred[str[i]] = i;
	}

	return maxLength;
}

int main() 
{
	cout << maxLegnthOfNonRepeatingSubStr("hello world!") << endl;
	cout << maxLegnthOfNonRepeatingSubStr("bbbbbbb") << endl;
	cout << maxLegnthOfNonRepeatingSubStr("abcabcab") << endl;
	return 0;
}