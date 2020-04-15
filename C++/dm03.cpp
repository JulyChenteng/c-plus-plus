#include <iostream>
#include <typeinfo>

using namespace std;

class CBase
{
public:
    int m_x, m_y;

public:
    CBase(int x=1, int y=2) { m_x = x; m_y = y; }
    int Sum() { return m_x + m_y; }
};

class CDerived : public CBase 
{
public:
	int m_z;
};

/*
 * typeid(expression)
 * 检查表达式的类型，返回一个类型为type_info的常量对象指针，这种类型定义在标准头文件#include<typeinfo>中。这种返回值可以用操作符 == 和 != 来互相进行比较，也可以用来通过name()函数获得一个描述数据类型或类名称的字符串。
 *
**/

int main()
{
    CBase *pBase = new CDerived();
    CBase *pBase2 = new CBase();

    //typid
    if (typeid(*pBase) == typeid(*pBase2))
    {
      cout << "pBase is: " << typeid(pBase).name() << endl;
      cout << "pBase2 is: " << typeid(pBase2).name() << endl;
    }

    return 0;
}