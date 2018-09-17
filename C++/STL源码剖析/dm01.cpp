/*临时对象的产生与运用*/
//本例测试仿函数用于for_each()的情形

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class print
{
public:
	void operator()(const T& elem)
	{ cout << elem << ' '; }
};

int main()
{
	int ia[6] = { 0, 1, 2, 3, 4, 5 };
	vector<int> iv (ia, ia+6);

	//print<int>()是一个临时对象，不是一个函数的调用操作
	//当for_each结束，这个临时对象生命周期也就结束了
	for_each(iv.begin(), iv.end(), print<int>());

	return 0;
}