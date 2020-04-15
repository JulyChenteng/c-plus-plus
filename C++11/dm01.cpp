#include <iostream>
#include <cstdarg>

using namespace std;

/*
 *  C99变长函数:
        va_list、va_start、va_end
 */

double Sum(int count, ...)
{
    va_list ap;
    double sum = 0;
    
    va_start(ap, count);                //获取变长列表的句柄ap

    for (int i = 0; i < count; i++)
    {
        sum += va_arg(ap, double);      //每次获取一个参数
    }
    
    va_end(ap);

    return sum;
}

int main()
{
    cout << Sum(3, 1.2, 2.4, 3.5) << endl;  // 7.1

    return 0;
}