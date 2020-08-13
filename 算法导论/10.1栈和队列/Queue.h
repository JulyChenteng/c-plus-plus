#include <iostream>
#include <string>

using namespace std;

struct queue
{
	int head;  //队列头指针
	int tail;  //队列尾指针
	int *s;
	int length;


	queue(int size) : tail(1), head(1), length(size)
	{
		s = new int[size+1];
	}
};

void Print(queue Q)
{
	int i;
	if (Q.tail >= Q.head)
	{
		for (i=Q.head; i<Q.tail; i++)
			cout << Q.s[i] << ' ';

		cout << endl;
	}
	else	//因为循环的缘故，队列尾可能在队列头的前面
	{
		for (i=Q.head; i<=Q.length; i++)
			cout << Q.s[i] << ' ';
		for (i=1; i<Q.tail; i++)
			cout << Q.s[i] << ' ';

		cout << endl;
	}
}

bool Queue_Empty(Queue Q)
{
	if (Q.tail == Q.head)
		return true;
	else
		return false;
}

void Enqueue(queue &Q, int x)
{
	Q.s[Q.tail] = x;

	if (Q.tail == Q.length)
		Q.tail = 1;
	else 
		Q.tail++;
}

//能够处理上溢的入队操作
void Enqueue2(queue &Q, int x)
{
	int t;

	if (Q.tail == Q.length)
		t = 1;
	else
		t = Q.tail + 1;

	if (t == Q.head)
	{
		cout << "error: overflow" << endl;
		return;
	}
	else
	{
		Q.s[Q.tail] = x;
		Q.tail = t;
	}
}

int Dequeue(queue &Q)
{
	int x = Q.s[Q.head];

	if (Q.head == Q.length)
		Q.head = 1;
	else
		Q.head++;

	return x;
}

//能够处理下溢的出队操作
int Dequeue2(queue &Q)
{
	if (Q.head == Q.tail)
	{
		cout << "error: underflow" << endl;
		return -1;
	}

	int x = Q.s[Q.head];
	if (Q.head == Q.length)
		Q.head = 1;
	else
		Q.head++;

	return x;
}