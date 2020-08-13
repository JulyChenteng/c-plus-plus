#include <iostream>
#include <string>

using namespace std;

struct stack 
{
	int top;
	int *s;
	int length;

	stack(int size) : top(0), length(size)
	{
		s = new int[size+1];
	}

	~stack() 
	{
		delete []s;
	}
};

void Print(stack S)
{
	int i;

	for (i=1; i<=S.top; i++)
		cout << S.s[i] << ' ';
	cout << endl;
}

bool Stack_Empty(stack &S)
{
	if (S.top == 0)
		return true;
	else
		return false;
}

void Push(stack &S, int x)
{
	if (S.top == S.length)
	{
		cout << "overflow" << endl;
		exit(0);
	}

	S.top++;
	S.s[S.top] = x;
}

int Pop(stack &S)
{
	if (Stack_Empty(S))
	{
		cout << "underflow" << endl;
		exit(0);
	}
	else
	{
		S.top--;
		return S.s[S.top+1];
	}
}
