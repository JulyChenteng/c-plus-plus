/*用折半查找法查找数组中一个指定的数字，并输出第几个*/
//在数组a的前n个元素中查找x元素，返回该元素第一次在数组中出现的下标
#include<stdio.h>
int bin_search(int *a, int n, int x)
{
	int head = -1, tail = n, mid = -1;
	int pos = -1;

	while (head+1 != tail)
	{
		mid = (tail+head) / 2;

		if (x > a[mid])
			head = mid;
		else
			tail = mid;

		//assert(head+1 == tail && x > a[head] && x <= a[tail]);
	}

	pos = tail;
	if (pos >= n || a[pos] != x)
		pos = -1;

	return pos;
}

int main()
{
	int a[] = {1, 3, 4, 2, 9, 7, 10, 8, 4, 3};
	int pos = bin_search(a, 10, 4);

	printf("4-Pos(下标从零开始): %d\n", pos);

	return 0;
}
