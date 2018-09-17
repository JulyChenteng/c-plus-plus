/*
所谓class template explicit specialization是指类模板的特例化
*/
#include <iostream>
using namespace std;

//将_STL_TEMPLATE_NULL定义为template<>，显式特例化前必须有‘template <>’
#define _STL_TEMPLATE_NULL template<> 

template <class key>
struct Hash
{
	void operator()() { cout << "Hash<T>" << endl; }
};

//explicit specialization
_STL_TEMPLATE_NULL struct Hash<char>
{
	void operator()() { cout << "Hash<char>" << endl; }
};

_STL_TEMPLATE_NULL struct Hash<unsigned char>
{
	void operator()() { cout << "Hash<unsigned char>" << endl; }
};

int main()
{
	Hash<long> t1;			//Hash<T>
	Hash<char> t2;			//Hash<char>
	Hash<unsigned char> t3; //Hash<unsigned char>

	t1(); //Hash<T>
	t2(); //Hash<char>
	t3(); //Hash<unsigned char>

	return 0;
}