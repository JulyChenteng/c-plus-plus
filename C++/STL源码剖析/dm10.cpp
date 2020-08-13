//测试class template可否拥有non-type template参数
#include <iostream>
#include <cstddef>
using namespace std;

class alloc
{
};

inline size_t _deque_buf_size(size_t n, size_t sz)
{
	return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template <class T, class Ref, class Ptr, size_t BufSize>
struct _deque_iterator
{
	typedef _deque_iterator<T, T&, T*, BufSize> iterator;
	typedef _deque_iterator<T, const T&, const T*, BufSize> const_iterator;

	static size_t buffer_size() { return _deque_buf_size(BufSize, sizeof(T)); }
};

template <class T, class Alloc = alloc, size_t BufSize = 0>
class deque
{
public:   	//Iterators
	typedef _deque_iterator<T, T&, T*, BufSize> iterator;
};

int main()
{
	cout << deque<int>::iterator::buffer_size() << endl;   //128
	cout << deque<int, alloc, 64>::iterator::buffer_size() << endl;   //64


	return 0;
}