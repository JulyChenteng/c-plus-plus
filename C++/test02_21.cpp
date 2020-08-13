
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

bool greaterThan(int n)
{
	return n > 5;
}

class GreaterThan
{
public:
	GreaterThan(int n = 0) : m(n) {}
	bool operator()(int n) 
	{
		return n > m;
	}
private:
	int m;
};

class DivBy
{
public:
	DivBy(int n = 0) : m(n) {}
	bool operator()(int n)
	{
		return (n % m ==0);
	}
private:
	int m;
};

#if 0
int main()
{
	int arr[] = {3, 5, 89, 33, 0, 89, 43, 22, 10, 25};
	int n = sizeof(arr) / sizeof(int);
	vector<int>	vt(arr, arr+n);
	vector<int> vtmp;

	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_insert_iterator<vector<int>>(vtmp));
	copy(vtmp.begin(), vtmp.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	sort(vt.begin(), vt.end());

	copy(arr, arr+n, ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(vt.begin(), vt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<int>::iterator itBegin = vt.begin();
	while (itBegin != vt.end())
	{
		auto it = find_if(itBegin, vt.end(), greaterThan);
		//auto it = find_if(itBegin, vt.end(), GreaterThan(5));
		if (it == vt.end()) break;
		cout << *it << " ";
		itBegin = it+1;
	}
	cout << endl;

	itBegin = vt.begin();
	while (itBegin != vt.end())
	{
		auto it = find_if(itBegin, vt.end(), DivBy(5));
		if (it == vt.end()) break;
		cout << *it << " ";
		itBegin = it + 1;
	}
	cout << endl;

	return 0;
}
#endif

template<class T>
class Print
{
public:
	void operator()(const T& t) const
	{
		cout << t << " ";
	}
};

#if 1
int main()
{
	vector<int> a;
	int b[13];

	for (int i = 0; i < 10; ++i)
		a.push_back(i);
	a.push_back(3);
	a.push_back(33);
	a.push_back(-1);

	for_each(a.begin(), a.end(), Print<int>());
	cout << endl;

	copy(a.begin(), a.end(), b);
	for_each(b, b+13, Print<int>());
	cout << endl;

	vector<int>::iterator  it = find(a.begin(), a.end(), 9);
	if (it != a.end()) cout << *it << endl;
	
	it = a.begin();
	while (it != a.end())
	{
		auto it2 = find_if(it, a.end(), greaterThan);
		if (it2 == a.end()) break;
		cout << *it2 << " ";
		it = it2 + 1;
	}
	cout << endl;

	int n = count(a.begin(), a.end(), 3);
	cout << n << endl;
	n = count_if(a.begin(), a.end(), greaterThan);
	cout << n << endl;

	replace(a.begin(), a.end(), 9, 2); //用2替换a中的10
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	replace_if(a.begin(), a.end(), GreaterThan(10), 0);
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	transform(a.begin(), a.end(), ostream_iterator<int>(cout, " "), negate<int>());	//取相反数输出
	cout << endl;

	reverse(a.begin(), a.end());
	for_each(a.begin(), a.end(), Print<int>());
	cout << endl;

	swap_ranges(a.begin(), a.end(), b);
	copy(b, b+13, ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
#endif
