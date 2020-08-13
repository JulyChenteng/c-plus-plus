#include <iostream>

using namespace std;

#if 0
/*
模板是实现代码重用机制的一种工具，实质就是实现类型参数化，即把类型定义为参数。
C++提供两种模板：函数模板，类模板

函数模板：
	函数模板就是建立一个通用的函数，其函数返回类型和形参类型不具体指定，而是用虚拟的类型来代表。
凡是函数体相同的函数都可以用函数模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用
函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能
*/
template <typename T>              //或者template <class T>
T getMax(const T &a, const T &b)
{
	return a > b ? a : b;
}

int main()
{
	auto cMax = getMax('a', 'b');
	cout << cMax << endl;

	auto iMax = getMax(23, 45);
	cout << iMax << endl;

	auto dMax = getMax(23.1, 23.2);
	cout << dMax << endl;

	return 0;
}
#endif

#if 1
/*
类模板：
	和函数模板一样，类模板就是建立一个通用类，其数据成员的类型、成员函数的返回类型和参数类形
都可以不具体指定，而用虚拟的类型来代表。当使用类模板建立对象时，系统会根据实参的类型取代类模
板中的虚拟类型，从而实现不同类的功能。
*/
template <typename T> 
class CMax
{
public:
	CMax(T a, T b)
	{
		m_a = a;
		m_b = b;
	}

public:
	T getMax();


private:
	T m_a;
	T m_b;
};

template<class T>
T CMax<T>::getMax()
{
	return m_a > m_b ? m_a : m_b;
}

int main()
{
	CMax<char> myMax0('a', 'c');
	auto cMax = myMax0.getMax();
	cout << cMax << endl;

	CMax<int> myMax1(12, 16);
	auto iMax = myMax1.getMax();
	cout << iMax << endl;

	return 0;
}
#endif