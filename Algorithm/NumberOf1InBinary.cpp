#include <iostream>
using namespace std;

/*
int NumberOf1InBinary(int n) 
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (n & flag)
			count += 1;
		
		flag = flag << 1;
	}

	return count;
}
*/

int NumberOf1InBinary(int n) 
{
	int count = 0;

	while (n)
	{
		count++;
		n = (n - 1) & n;
	}

	return count;
}

int main() 
{
	int count = NumberOf1InBinary(9);
	cout << "9 -> " << count << endl;
}



