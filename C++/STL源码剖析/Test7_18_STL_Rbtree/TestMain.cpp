#include<iostream.h>
#include<sgi/map>
#include<sgi/set>
//#include<sgi/stl_tree.h>

void main()
{
	map<int,int> mp;
	mp[1] = 10;
	mp[2] = 20;

	mp[3] = 30;

	int value = mp[1];
	mp[1] = 100;

}

/*
template<class T>
struct KeyOfValue
{
	const T& operator()(const T &x)
	{
		return x;
	}
};

void main()
{
	rb_tree<int, int, KeyOfValue<int>, less<int> > rb;
	rb.insert_unique(10);
	rb.insert_unique(7);
	rb.insert_unique(5);
}
*/