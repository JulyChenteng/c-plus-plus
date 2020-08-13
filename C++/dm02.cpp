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
 *  new_type 是要转换成的目标类型，expression 是要被转换的内容
 *  reinterpret_cast<new_type>(expression)
 *    用于天生危险的类型转换，可以将一个指针转换为任意其他类型的指针，对指针内容不做任何检查。也
 可以将一个指针转换为整型，反之依然。
 *
 *  static_cast<new_type>(expression)
 *    可以执行所有能够隐含执行的类型转换，以及它们的反向操作（即使这种方向操作是不允许隐含执行的）,
 *  仅当new_type可被隐式转换为expression所属的类型或expression可被隐式转换为new_type所属的类型
 *  时，上述转换才是合法的，否则将出错。
 *
 *  const_cast<new_type>(expression)
 *    new_type和expression的类型必须相同，const_cast对expression的const或volatile属性进行
 * 设置或取消操作，由于编程时可能无意间同时改变类型和常量特征，因此使用const_cast运算符更安全。
 *
*****************************************************************************************/
#if 1
int main()
{
    CObject obj0;
    CBase* pObj1;
    
    //强转
    pObj1 = (CBase *)&obj0;   
    cout << pObj1->Sum() << "	" << pObj1->m_x << endl;  //不会报错,结果异常

    //reinterpret_cast
    pObj1 = reinterpret_cast<CBase *>(&obj0);
    cout << pObj1->m_x << " " << pObj1->m_y << endl;  //111 未知

    CBase *pBase = new CBase(2, 3); 

    //static_cast
    CDerived *pDerived = static_cast<CDerived *>(pBase);   
    cout << pDerived->m_x << endl;			// 2

    static_cast<void>(pBase);   // 可以将某表达式转换为void
    
    //const_cast
    const CBase *pBase3 = new CBase(5, 5);
    //CBase *pBase4 = pBase3;		// 编译报错,无法转换
    CBase *pBase4 = const_cast<CBase *>(pBase3);
    cout << pBase4->m_x << endl;	// 5

    const CBase *pBase5 = const_cast<const CBase *>(pBase4);
    cout << pBase5->m_x << endl;

    delete pBase;
    pBase = NULL;

    return 0;
}
#endif