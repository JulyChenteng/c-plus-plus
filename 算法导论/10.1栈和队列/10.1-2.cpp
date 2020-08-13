/*
	题号：		10.1-2 
	要求：		用一个数组A[1..n]实现两个栈， 使得两个栈中的元素总数不到n时，两者都不会发生上溢
	注意事项：	PUSH和POP操作的时间应为O(1), 数组下标从1开始
	思路：		分别用数组的两端作为两个栈的起点，向中间扩展，两个栈中的元素的总和不超过n时，两
			个栈都不会溢出，即不会上溢，在程序中我们设置一个索引，0代表对栈1的操作，1代表对栈2的
			操作
*/
#include <iostream>
using namespace std;

class arrayToTwoStack
{
public:
	//栈顶指针
	int top1, top2; //分别初始化为0和n+1
	int len;		//数组长度
	int *s;			//数组

public:
	arrayToTwoStack(int size) : top1(0), top2(size+1), len(size)
	{
		s = new int[size+1];
	}

	bool isEmpty(int index);
	void push(int index, int x);
	int pop(int index);
};

typedef arrayToTwoStack ATTS;

bool ATTS::isEmpty(int index)
{
	if (index == 0 && top1 < 1)
		return true;
	if (index == 1 && top2 > len)
		return true;

	return false;
}

void ATTS::push(int index, int data)
{
	if (top1 > top2)          //分别对栈1和栈2进行操作，所以当

	{
		cout << "overflow" << endl;
		return;
	}

	//对栈1的操作
	if (index == 0)
	{
		top1++;           //栈1的栈底为s[1]，而top1初始为0，所以应该先加1，后赋值
		s[top1] = data;
	}
	else if (index == 1) //对栈2的操作
	{
		//栈2的栈底为s[size+1]，而top2初始为size+1，所以应该先减1，后赋值
		top2--;               
		s[top2] = data;
	}
	else
	{
		cout << "input error!" << endl;
		return;
	}
}

int ATTS::pop(int index)
{
	int ret; //保存出栈元素的值
	
	//对栈1操作
	if (index == 0)
	{
		if (top1 < 0)
		{
			cout << "underflow" << endl;
			return -1;
		}
		else
		{
			ret = s[top1];
			top1--;
		}
	}
	else if (index == 1)  //对栈2的操作
	{
		if (top2 > len)
		{
			cout << "underflow" << endl;
			return -1;
		}
		else
		{
			ret = s[top2];
			top2++;
		}
	}
	else
	{
		cout << "input error!" << endl;
		return -1;
	}

	return ret;
}

int main()
{
	ATTS S(5);

	cout << "入栈前：" << S.top1 << endl;
	cout << "入栈前：" << S.top2 << endl;
	S.push(0, 3);
	S.push(0, 4);
	S.push(1, 5);
	S.push(1, 1);
	cout << "入栈后：" << S.top1 << endl;
	cout << "入栈后：" << S.top2 << endl;

	if (!S.isEmpty(1))
	{
		cout << "栈2不为空" << endl;
	}
	if (!S.isEmpty(0))
	{
		cout << "栈1不为空" << endl;
	}
	
	int n1 = S.pop(0);
	int n2 = S.pop(1);
	printf("栈1出栈：%d\n", n1);
	printf("栈2出栈：%d\n", n2);

	delete []S.s;

	return 0;
}