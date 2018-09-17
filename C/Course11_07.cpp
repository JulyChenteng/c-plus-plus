#include <iostream>
#include <typeinfo>

using namespace std;

//指针两值
//指针为什么在32位机器上就是4位
//大端对齐，小端对齐 一般是大端对齐
//指针类型的作用（加一之后再内存中移几位）
//数据在内存中以补码方式存储

//指针与数组: 三值合一 
//数组名总是代表整个数组空间，其值为数组首元素的地址。

#if 0
int main()
{
	int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = ar; //OK
	int (*p1)[10] = &ar;//ok

	cout << &ar[0] << endl;
	cout << typeid(&ar[0]).name() << endl;
	cout << ar << endl;
	cout << typeid(ar).name() << endl;
	cout << &ar << endl;
	cout << typeid(&ar).name() << endl;


	return 0;
}
#endif

#if 0
int main()
{
	int ar[10];

	ar[0] = 100;//ok
	0[ar] = 200;//ok

	return 0;	
}
#endif

#if 1
//长整型转化为十六进制
char* convert_to_hex(unsigned long value)
{
	char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	static char hex[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
	int m = value;
	int x = 0;
	int n = 8;

	while (m != 0)
	{
		x = m % 16;
		hex[--n] = ch[x]; 
		m = m / 16;
	}

	return hex;
}

int main()
{
	unsigned long value = 47194;

	char *val = convert_to_hex(value);
	cout << "0x" << val << endl;

	cout << endl;

	return 0;
}
#endif