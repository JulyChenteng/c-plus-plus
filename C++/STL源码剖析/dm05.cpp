//测试在class template中拥有static data members

#include <iostream>
using namespace std;

template <typename T>
class testClass
{
public:
	static int _data;
};

template<> int testClass<int>::_data = 1; //前边添加"template<>"表示模板的特例化，以支持C++新标准
template<> int testClass<char>::_data = 2;

int main()
{
	cout << testClass<int>::_data << endl;   // 1
 	cout << testClass<char>::_data << endl;  // 2

	testClass<int> obji1, obji2; 
	testClass<char> objc1, objc2;

	cout << obji1._data << endl;  // 1
	cout << obji2._data << endl;  // 1
	cout << objc1._data << endl;  // 2
	cout << objc2._data << endl;  // 2

	obji2._data = 3;
	objc2._data = 4;

	cout << obji1._data << endl;  // 3
	cout << obji2._data << endl;  // 3
	cout << objc1._data << endl;  // 4
	cout << objc2._data << endl;  // 4 

	return 0;
}