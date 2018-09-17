/* function call 操作符 */

#include <iostream>
#include <cstdlib>
using namespace std;

#if 0
int fcmp(const void* elem1, const void *elem2);

int main()
{
	int ia[10] = {32, 92, 67, 58, 10, 4, 25, 52, 59, 54};

	for (int i = 0; i < 10; ++i)
	{
		cout << ia[i] << " "; 
	}
	cout << endl;

	//在C语言时代，要想将函数当做参数传递，唯有通过函数指针才能达成。
	qsort(ia, sizeof(ia)/sizeof(int), sizeof(int), fcmp);

	for (int i = 0; i < 10; ++i)
	{
		cout << ia[i] << " "; 
	}

	return 0;
}

int fcmp(const void *elem1, const void *elem2)
{
	const int *i1 = (const int*)elem1;
	const int *i2 = (const int*)elem2;

	if (*i1 < *i2)
		return -1;
	else if (*i1 == *i2)
		return 0;
	else if (*i1 > *i2)
		return 1;
}
#endif

template <class T>
class Plus{
public:
	T operator()(const T& x, const T& y) const
	{ return x + y; }
};

template <class T>
class Minus{
public:
	T operator()(const T& x, const T& y) const
	{ return x - y; }
};

int main()
{
	//产生仿函数对象
	Plus<int> plusobj;
	Minus<int> minusobj;

	cout << plusobj(3, 5) << endl; //8
	cout << minusobj(3, 5) << endl;//-2

	cout << Plus<int>()(43, 30) << endl; //73
	cout << Minus<int>()(39, 30) << endl;//9

	return 0;
}