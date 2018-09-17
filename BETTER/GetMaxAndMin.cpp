#include <stdio.h>
#include <math.h>

int getMax(int a, int b)
{
	return (a+b+abs(a-b))/2; //获取两者之中较大的一个
}

int getMin(int a, int b)
{
	return (a+b-abs(a-b))/2; //获取两者之中较小的一个
}

int main()
{
	int a = 20, b = 30;

	printf("Max: %d\n", getMax(a, b));
	printf("Min: %d\n", getMin(a, b));

	return 0;
}