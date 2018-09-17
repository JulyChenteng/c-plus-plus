//测试class template partial specialization——在class template的一般化设计之外，
//特别针对某些template参数做特殊化设计

#include <iostream>
using namespace std;

template <class I, class O>
struct testClass
{
	testClass() { cout << "I, O" << endl; }
};

//特殊化设计
template <class T>
struct testClass<T*, T*>
{
	testClass() { cout << "T*, T*" << endl; }
};

//特殊化设计
template<class T>
struct testClass<const T*, T*>
{
	testClass() { cout << "const T*, T*" << endl; }
};

int main()
{
	testClass<int, char> obj1;			// I, O
	testClass<int*, int*> obj2;			// T*, T*
	testClass<const int*, int*> obj3;	//const T*, T*

	return 0;
}