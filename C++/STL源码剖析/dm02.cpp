/* test in-class initialization of static const integral members */
//integral 泛指所有整数型别，不单是指int

#include <iostream>
using namespace std;

template <typename T>
class testClass
{
public:         //expedient 方便的、有利的
	static const int _datai = 5;
	static const long _datal = 3L;
	static const char _datac = 'c';
};

int main()
{
	cout << testClass<int>::_datai << endl;
	cout << testClass<int>::_datal << endl;
	cout << testClass<int>::_datac << endl;

	return 0;
}