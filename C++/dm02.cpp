#include <iostream>
#include <typeinfo>
using namespace std;

class CObject
{
public:
    int m_num = 111;
};

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

/****************************************************************************************
* new_type 是要转换成的目标类型，expression 是要被转换的内容
* reinterpret_cast <new_type> (expression)
  可以将一个指针转换为任意其他类型的指针，对指针内容不做任何检查。也可以将一个指针转换为整型，反之依然。

* static_cast <new_type> (expression)
  可以执行所有能够隐含执行的类型转换，以及它们的反向操作（即使这种方向操作是不允许隐含执行的）

* dynamic_cast <new_type> (expression)
  可以用来进行任何可以隐含进行的转换操作以及它们被用于多态类情况下的方向操作。然而与static_cast不同的是，dynamic_cast会检查后
  一种情况的操作是否合法，也就是说它会检查类型转换操作是否会返回一个被要求类型的有效的完整的对象。

* const_cast <new_type> (expression)
  可以对常量的const属性进行设置或取消操作
*****************************************************************************************/

int main()
{
    CObject obj0;
    CBase* pObj1;
    
    //强转
    pObj1 = (CBase*)&obj0;   
    cout << pObj1->Sum() << "	" << pObj1->m_x << endl;  //不会报错,结果异常

    //reinterpret_cast
    pObj1 = reinterpret_cast<CBase*>(&obj0);
    cout << pObj1->m_x << " " << pObj1->m_y << endl;  //111 未知

    CBase *pBase = new CBase(2, 3); 

    //static_cast
    CDerived *pDerived = static_cast<CDerived*>(pBase);   
    cout << pDerived->m_x << endl;			// 2

    //dynamic_cast
    //CDerived *pDerived2 = dynamic_cast<CDerived*>(pBase); //编译报错,无法转换
    CBase *pBase2 = dynamic_cast<CBase*>(pDerived);
    cout << pBase2->m_x << endl;			// 2
    
    //const_cast
    const CBase *pBase3 = new CBase(5, 5);
    //CBase *pBase4 = pBase3;		// 编译报错,无法转换
    CBase *pBase4 = const_cast<CBase*>(pBase3);
    cout << pBase4->m_x << endl;	// 5

    delete pBase;
    pBase = NULL;

    return 0;
}
