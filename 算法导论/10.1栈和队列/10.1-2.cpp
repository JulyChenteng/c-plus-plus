/*
	��ţ�		10.1-2 
	Ҫ��		��һ������A[1..n]ʵ������ջ�� ʹ������ջ�е�Ԫ����������nʱ�����߶����ᷢ������
	ע�����	PUSH��POP������ʱ��ӦΪO(1), �����±��1��ʼ
	˼·��		�ֱ��������������Ϊ����ջ����㣬���м���չ������ջ�е�Ԫ�ص��ܺͲ�����nʱ����
			��ջ��������������������磬�ڳ�������������һ��������0�����ջ1�Ĳ�����1�����ջ2��
			����
*/
#include <iostream>
using namespace std;

class arrayToTwoStack
{
public:
	//ջ��ָ��
	int top1, top2; //�ֱ��ʼ��Ϊ0��n+1
	int len;		//���鳤��
	int *s;			//����

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
	if (top1 > top2)          //�ֱ��ջ1��ջ2���в��������Ե�

	{
		cout << "overflow" << endl;
		return;
	}

	//��ջ1�Ĳ���
	if (index == 0)
	{
		top1++;           //ջ1��ջ��Ϊs[1]����top1��ʼΪ0������Ӧ���ȼ�1����ֵ
		s[top1] = data;
	}
	else if (index == 1) //��ջ2�Ĳ���
	{
		//ջ2��ջ��Ϊs[size+1]����top2��ʼΪsize+1������Ӧ���ȼ�1����ֵ
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
	int ret; //�����ջԪ�ص�ֵ
	
	//��ջ1����
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
	else if (index == 1)  //��ջ2�Ĳ���
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

	cout << "��ջǰ��" << S.top1 << endl;
	cout << "��ջǰ��" << S.top2 << endl;
	S.push(0, 3);
	S.push(0, 4);
	S.push(1, 5);
	S.push(1, 1);
	cout << "��ջ��" << S.top1 << endl;
	cout << "��ջ��" << S.top2 << endl;

	if (!S.isEmpty(1))
	{
		cout << "ջ2��Ϊ��" << endl;
	}
	if (!S.isEmpty(0))
	{
		cout << "ջ1��Ϊ��" << endl;
	}
	
	int n1 = S.pop(0);
	int n2 = S.pop(1);
	printf("ջ1��ջ��%d\n", n1);
	printf("ջ2��ջ��%d\n", n2);

	delete []S.s;

	return 0;
}