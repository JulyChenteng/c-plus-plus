//#define _USE_MALLOC //程序默认执行第二级配置器除非定义__USE_MALLOC

//注意头文件包含顺序，避免覆盖宏定义
#include "config.h"		//必须放在#include <iostream>前，因为编译器会带有额外的依赖项，会覆盖_THROW_BAD_ALLOC宏
#include <iostream>
using namespace std;

void out_of_memory()
{
	cout << "My out of memory!" << endl;
}

/*
int main()
{
	alloc::set_malloc_handler(out_of_memory);
	//int *p = (int *)alloc::allocate(sizeof(int));
	int *p = (int *)alloc::allocate(sizeof(int) * 533333333);

	alloc::deallocate(p, sizeof(int));

	return 0;
}
*/

int main()
{
	char *p = (char *)alloc::allocate(10);
	alloc::deallocate(p, 10);

	return 0;
}