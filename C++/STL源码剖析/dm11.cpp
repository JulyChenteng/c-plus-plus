/*
	这种奇怪的语法是为了实现所谓的bound friend templates, 也就是说class template
的某个具体实现与其friend function template 的某个具体实现有一对一的关系
*/
#include <iostream>
#include <cstddef>
using namespace std;

class alloc
{
};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque
{
public:
	deque() { cout << "deque" << ' '; }
};

/*
//这样的声明可有可无
template <class T, class Sequence> class stack;
template <class T, class Sequence> 
bool operator==(const stack<T, Sequence>& x, const stack<T, Sequence>& y);
template <class T, class Sequence>
bool operator<(const stack<T, Sequence>& x, const stack<T, Sequence>& y);
*/

template <class T, class Sequence = deque<T> > //注意模板声明结尾"> >"应该有空格
class stack
{
	//写成这样是可以的
	friend bool operator== <T> (const stack<T>&, const stack<T>&);
	friend bool operator< <T> (const stack<T>&, const stack<T>&);

	/*
	//写成这样也是可以的
	friend bool operator== <T> (const stack&, const stack&);
	friend bool operator< <T> (const stack&, const stack&);

	//写成这样也是可以的
	friend bool operator== <> (const stack<T>&, const stack<T>&);
	friend bool operator< <> (const stack<T>&, const stack<T>&);
	*/
	
	//写成这样是不可以的
	//friend bool operator== (const stack&, const stack&);
	//friend bool operator< (const stack&, const stack&);

public:
	stack() { cout << "stack" << endl; }
private:
	Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T, Sequence>& x, const stack<T, Sequence>& y)
{
	cout << "operator==" << ' ';
	return true;
}

template <class T, class Sequence>
bool operator<(const stack<T, Sequence>& x, const stack<T, Sequence>& y)
{
	cout << "operator<" << ' ';
	return true;
}

int main()
{
	stack<int> x;		//deque stack
	stack<int> y;		//deque stack

	cout << (x == y) << endl; 	//operator== 1
	cout << (x<y) << endl;		//operator< 1

	stack<char> y1;		//deque stack
	//cout << (x == y1) << endl;    //error: no match for...
	//cout << (x<y) << endl;		//error: no match for...

	return 0;
}
