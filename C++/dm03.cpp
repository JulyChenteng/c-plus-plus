#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

using namespace std;

class CBase
{
public:
    int m_x, m_y;

public:
    CBase(int x=1, int y=2) { m_x = x; m_y = y; }
    virtual int Sum() { return m_x + m_y; }
    //int Sum() { return m_x + m_y; }
};

class CDerived : public CBase 
{
public:
	int m_z;
};

/********************************************************************************************************
 *      RTTI的用途：在使用多态的情况下，有时候需要知道指针指向的是哪种对象，可能是想调试时跟踪生成的对象类型，
 *  可能是希望调用类方法的正确版本。只要该函数是类层次结构中所有成员都拥有的虚函数，则并不真正需要知道对象的类型。
 *  但派生对象可能包含不是继承而来的方法，在这种情况下，只有某些类型的对象可以使用该方法。
 *  
 *  RTTI只适用于包含虚函数的类。第一个例子打印结果可以说明。
 *  
 *  dynamic_cast<Type *>(pt)/dynamic_cast<Type &>(t)
 *      dynamic_cast会检检查类型转换操作是否会返回一个被要求类型的有效的完整的对象。如果指向的对象（*pt）的类型为Type
 *  或者是从Type直接或间接派生而来的类型，则上面的表达式将从指针pt转换为Type类型的指针。否则结果为0，即空指针。用于引用
 *  的时候，因为没有与空指针对应的引用值，因此无法使用特殊的引用值来指示失败。当转换失败时，dynamic_cast将引发类型为
 *  bad_cast的异常，这种异常是从exception类派生而来，该异常定义于头文件typeinfo中。
 *
 *  typeid(expression)
 *       检查表达式的类型，返回一个类型为type_info的常量对象指针，这种类型定义在标准头文件#include<typeinfo>中。
 *   这种返回值可以用操作符 == 和 != 来互相进行比较，也可以用来通过name()函数获得一个描述数据类型或类名称的字符串。
 *
 *  注意：type_info类的实现随厂商而异，但包含一个name()成员，该函数返回一个随实现而异的字符串：通常（但并非一定）
    是类的名称。
*********************************************************************************************************/
#if 1
int main()
{
    CBase *pBase = new CDerived();
    CBase *pBase2 = new CBase();

    //父子类无虚函数的场景, 注释掉virtual int Sum()函数
    cout << "without virtual function:\n"; 
    cout << "\t*pBase is: " << typeid(*pBase).name() << endl;     // *pBase is: 5CBase
    cout << "\tpBase is: " << typeid(pBase).name() << endl;       // pBase is: P5CBase
    cout << "\t*pBase2 is: " << typeid(*pBase2).name() << endl;   // *pBase2 is: 5CBase
    cout << "\tpBase2 is: " << typeid(pBase2).name() << endl;     // pBase2 is: P5CBase

    //父子类有虚函数的场景, 取消virtual int Sum()函数的注释
    cout << "with virtual function:\n"; 
    cout << "\t*pBase is: " << typeid(*pBase).name() << endl;     // *pBase is: 8CDerived
    cout << "\tpBase is: " << typeid(pBase).name() << endl;       // pBase is: P5CBase
    cout << "\t*pBase2 is: " << typeid(*pBase2).name() << endl;   // *pBase2 is: 5CBase
    cout << "\tpBase2 is: " << typeid(pBase2).name() << endl;     // pBase2 is: P5CBase
    
    return 0;
}
#endif

class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}

    virtual void Speak() const { cout << "I'm a grand class！\n"; }
    virtual int  Value() const { return hold; }
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}

    void Speak() const { cout << "I'm a superb class!!\n"; }
    virtual void Say() const 
    {
        cout << "I hold the superb value of " << Value() << "!\n";
    }
};

class Magnificent : public Superb
{
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}

    void Speak() const { cout << "I'm a magnificent class!!!\n"; }
    void Say() const 
    { 
        cout << "I hold the character " << ch << " and the integer " << Value() << "!\n"; 
    }
};

Grand* GetOne();

#if 0
int main()
{
    srand(time(0));
    Grand *pg;
    Superb *ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        
        // Say方法只有在Superb以及其子类中才存在
        if ( ps = dynamic_cast<Superb *>(pg) )
            ps->Say();
    }

    return 0;
}
#endif

#if 0
int main()
{
    srand(time(0));
    Grand *pg;
    Superb *ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "Now processing type " << typeid(*pg).name() << ".\n";

        pg->Speak();
        
        // Say方法只有在Superb以及其子类中才存在
        if ( ps = dynamic_cast<Superb *>(pg) )
            ps->Say();

        if ( typeid(Magnificent) == typeid(*pg) )
            cout << "Yes, you're really magnificent.\n";
    }

    return 0;
}
#endif


// generate one of three kinds of objects randomly
Grand* GetOne()
{
    Grand *p;
    
    switch (rand() % 3)
    {
        case 0: 
            p = new Grand(rand() % 100);
            break;
        case 1:
            p = new Superb(rand() % 100);
            break;
        case 2:
            p = new Magnificent(rand() % 100, rand() % 26 + 'A') ;
            break;
    }

    return p;
}