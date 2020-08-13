#include <iostream>
#include <cmath>
using namespace std;

class Test
{
public:
	Test() : a(5), b(6)	{ cout << "constructor no arguments!" << endl; }
	Test(int a, int b)	{ cout << "constructor with arguments!" << endl;  this->a = a;	this->b = b; }
	Test(const Test &t)
	{
		cout << "copy constructor!" << endl;
		a = t.a;
		b = t.b;
	}

	//重载赋值运算符时，返回值为引用或其本身是为了连续多此赋值，类似于整型，如int a, b , c =3;  a = b = c;返回引用是最佳选择，
	//可以避免函数返回时的拷贝构造，提高效率。
	//参数为引用是为了避免调用时的拷贝构造，提高效率。
	//注意：虽然引用可以提高效率，但是函数返回值为引用类型时，此时要非常注意函数返回的变量不受函数限制（如局部变量），否则函数结束返回的变量也会被释放。
	Test& operator=(const Test &t)
	{ 
		cout << "assign operator!" << endl;
		if (this != &t)
		{
			a = t.a;
			b = t.b;
		}

		return *this;
	}
	
	~Test()	{ cout << "destructor called !" << endl; }

public:
	int max(int a, int b);
	int min(int a, int b);

private:
	int a; 
	int b;
};


/*
class Test2
{
public:
	Test2() { cout << "constructor no arguments !" << endl; }
	Test2(int a) { cout << "constructor with arguments !" << endl; this->a = a; }
	~Test2() { cout << "deconstructor called !" << endl; }

	//定义该类到整型的转化
	operator int() const
	{
		cout << "operator called !" << endl;
		return a;
	}

public:
	int a;
};
*/

int main()
{
	Test t1, t2(7, 8);
	Test t3 = t2;
	Test t4;
	t4 = t2 = t1;
	t2 = { 2, 3 };

	/*
	Test2 t;
	t = 5;
	cout << "t : " << t << endl;		  //因为我们定义了该类到整型的转化，所以输出t时，会将t转化为整型。

	int a = t;							  //会将t先转化为整型，再进行赋值
	cout << "a : " << a << endl;
	 */
	system("pause");
	return 0;	
}


int Test::max(int a, int b)
{
	return (a + b - abs(a - b)) / 2;
}

int Test::min(int a, int b)
{
	return (a + b - abs(a - b)) / 2;
}

