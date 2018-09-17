/* increment/decrement/deference 操作符 */

#include <iostream>
using namespace std;

class INT
{
	friend ostream& operator<<(ostream& os, const INT& i);

public:
	INT(int i):m_i(i) { }

	//prefix : increment and then fetch
	INT& operator++()
	{
		 ++(this->m_i);
		 return (*this);
	}

	//postfix ；fetch and then increment
	const INT operator++(int)//后++表达式不能做左值
	{
		INT temp = *this;
		++(*this);
		return temp;
	}

	//prefix : decrement and then fetch
	INT& operator--()
	{
		--(this->m_i);
		return (*this);
	}

	//postfix : fetch and then decrement
	const INT operator--(int)
	{
		INT temp = *this;
		--(*this);
		return (*temp);
	}

	int& operator*() const
	{
		//以下转换操作告诉编译器，你确实要将const int 转换为non-const lvalue;
		//如果没有明确的这样转型，有些编译器会给你警告，有些更严格的编译器会视为错误
		return (int&)m_i;
	}

private:
	int m_i;
};

ostream& operator<<(ostream& os, const INT& i)
{
	os << '[' << i.m_i << ']';
	return os;
}

int main()
{
	INT I(5);
	cout << I++; //[5]
	cout << ++I; //[7]
	cout << I--; //[7]
	cout << --I; //[5]
	cout << *I;  //[5]
	cout << I;   //[5]

	return 0;
}