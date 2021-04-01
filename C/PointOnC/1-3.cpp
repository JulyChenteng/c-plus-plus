/*
	从标准输入读取一些字符，并把它们写到标准输出上。它同时应该计算checksum(检验和)用一个signed char类型的变量进行计算，
它初始化为-1，当每个字符从标准输入读取时，它的值就被加到checksum中，如果checksum变量产生了溢出，那么这些溢出就会被忽略。
当所有的字符均被写入后，程序以十进制整数的形式打印出checksum的值，他有可能是负值。注意在checksum后面要添加一个换行符。

实例：输入： Hello world！
      输出： Hello world！
      		 102
*/

#include <stdio.h>

int main(void)
{
	signed char checksum = -1;
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
		checksum += c;
	}

	printf("%d\n", checksum);
	return 0;
}



/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("Hello world!\n");
	signed char checksum = -1;

	for (auto ch : str)
	{
		checksum += ch;
	}

	cout << str << (int)checksum << endl;;

	return 0;
}
*/