 //测试template参数可否根据前一个template参数而设定默认值
#include <iostream>
using namespace std;

class alloc
{
};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque
{
public:
	deque() { cout << "deque" << endl; }
};

template <class T, class Sequence = deque<T>>
class stack 
{
public:
	stack() { cout << "stack" << endl; }
private:
	Sequence c;
};

int main()
{
	stack<int> x; 	//deque 
	return 0;		//stack
}