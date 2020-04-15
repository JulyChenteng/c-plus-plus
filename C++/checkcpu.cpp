#include <stdio.h>

int checkCPU()
{
 	union w
 	{ 
 		int a;
 		char b;
 	} c;
 	
 	c.a = 1;
 	return (c.b == 1);
}

int main() 
{
	if (checkCPU() == true)
	{
		printf("Little-Endian！\n");	
	}
	
	return 0;
}