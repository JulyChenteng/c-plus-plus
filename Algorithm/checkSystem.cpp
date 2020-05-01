/*************************************************************************
  > File Name: checkSystem.cpp
  > Description:检测大小端 
  > Author: Actually
  > Created Time: Fri 02 Nov 2018 04:39:03 AM EDT
 ************************************************************************/

#include <iostream>
using namespace std;

int checkCPU(void)  
{  
    union  
    {  
        int a;  
        char b;  
    }c;  
    c.a = 1;
    cout << int(c.b) << endl;
    return (c.b == 1);  
} 

int main() 
{
    union test 
    {
        int i;
        char x[2];
    }t;
    //union test t;
    t.i = 0;
    t.x[0] = 10;
    t.x[1] = 1;

    checkCPU();
    cout << sizeof(t) << endl;
    cout << t.i << endl;

    return 0;
}
