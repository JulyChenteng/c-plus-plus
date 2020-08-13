#include<iostream>
using namespace std;

#include"AVL.h"

void main()
{
	int ar[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	int n = sizeof(ar) / sizeof(int);
	AVLTree<int> avl;

	for(int i=0; i<n; ++i)
	{
		avl.Insert(ar[i]);
	}

	//avl.Remove(15);
	avl.Remove(26);
	return;
}
