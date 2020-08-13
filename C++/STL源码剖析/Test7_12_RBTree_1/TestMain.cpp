#include<iostream>
#include<assert.h>
#include"rb_tree.h"
using namespace std;

void main()
{
	int ar[] = {10, 7, 8};
	//int ar[] = {100, 70, 80, 50, 40, 75, 73, 72, 74, 71};
	int n = sizeof(ar) / sizeof(int);

	RBTree<int> rb;
	for(int i=0; i<n; ++i)
	{
		rb.Insert(ar[i]);
	}
	return;
}

