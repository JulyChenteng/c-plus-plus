#include<iostream>
#include<vld.h>
#include"smart_ptr.h" //<boost/smart_ptr.hpp>
using namespace std;

void main()
{
	int *p = new int(10);
	shared_ptr<int> ps(p);
	cout<<"ps use_count = "<<ps.use_count()<<endl;
	shared_ptr<int> ps1 = ps;
	cout<<"ps use_count = "<<ps.use_count()<<endl;
	shared_ptr<int> ps2;
	ps2 = ps;
	cout<<"ps use_count = "<<ps.use_count()<<endl;
}

