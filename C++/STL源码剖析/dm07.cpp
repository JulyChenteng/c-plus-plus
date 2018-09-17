//组态_STL_FUNCTION_TMPL_PARTIAL_ORDER
#include <iostream>
using namespace std;

class alloc 
{
};

template <class T, class Alloc = alloc>
class vector 
{
public:
	void swap(vector<T, Alloc>&) { cout << "swap()" << endl; }
};

template <class T, class Alloc>
inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	x.swap(y);
}

int main()
{
	vector<int> x, y;
	swap(x, y);  //swap()
	return 0;
}