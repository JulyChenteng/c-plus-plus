/***************************set/multiset、functor、pair***********************************/

#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

/*
set是一个集合容器，其中所包含的元素是唯一的，集合中的元素按一定的顺序排列。
	元素插入过程是按排序规则插入，所以不能指定插入位置。
	采用红黑树变体的数据结构实现，红黑树属于平衡二叉树。在插入操作和删除操作上比vector快。
	不可以直接存取元素。（不可以使用at.(pos)与[]操作符）。
	multiset与set的区别：set支持唯一键值，每个元素值只能出现一次；而multiset中同一值可以出现多次。
不可以直接修改set或multiset容器中的元素值，因为该类容器是自动排序的。如果希望修改一个元素值，必须
先删除原有的元素，再插入新的元素。

set采用模板类实现，set/multiset对象的默认构造形式：set<T> setT;  multiset<T> multisetT; 
	set<int,less<int> >  setIntA;  		//该容器是按升序方式排列元素。
	set<int,greater<int>> setIntB;   	//该容器是按降序方式排列元素。
	set<int> 相当于 set<int,less<int>>。
	less<int>与greater<int>中的int可以改成其它类型，该类型主要要跟set容纳的数据类型一致。

疑问1：less<>与greater<>是什么？
疑问2：如果set<>不包含int类型，而是包含自定义类型，set容器如何排序？
	要解决如上两个问题，需要了解容器的函数对象，也叫伪函数，英文名叫functor。

插入：
	//按照排序规则插入不需要提供pos参数
	set.insert(elem);     //在容器中插入元素。

迭代器操作：
	set.begin();  	//返回容器中第一个数据的迭代器。
	set.end();  	//返回容器中最后一个数据之后的迭代器。
	set.rbegin();  	//返回容器中倒数第一个元素的迭代器。
	set.rend();   	//返回容器中倒数最后一个元素的后面的迭代器。

拷贝构造和赋值:
	set(const set &st);		     	//拷贝构造函数
	set& operator=(const set &st);	//重载等号操作符
	set.swap(st);					//交换两个集合容器

大小:
	set.size();		//返回容器中元素的数目
	set.empty();	//判断容器是否为空

删除：
	set.clear();			//清除所有元素
	set.erase(pos);			//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	set.erase(beg,end);	    //删除区间[beg,end)的所有元素	，返回下一个元素的迭代器。
	set.erase(elem);     	//删除容器中值为elem的元素。

查找:
	set.find(elem);   		//查找elem元素，返回指向elem元素的迭代器。
	set.count(elem);  		//返回容器中值为elem的元素个数。对set来说，要么是0，要么是1。对multiset来说，值可能大于1。
	set.lower_bound(elem);  //返回第一个>=elem元素的迭代器。
	set.upper_bound(elem);	//返回第一个>elem元素的迭代器。

	set.equal_range(elem);	//返回容器中与elem相等的上下限的两个迭代器。上限是闭区间，下限是开区间，如[beg,end)。
	此函数返回两个迭代器，而这两个迭代器被封装在pair中。

以下讲解pair的含义与使用方法。
	pair译为对组，可以将两个值视为一个单元。
	pair<T1,T2>存放的两个值的类型，可以不一样，如T1为int，T2为float。T1,T2也可以是自定义类型。
	pair.first是pair里面的第一个值，是T1类型。
	pair.second是pair里面的第二个值，是T2类型
*/
#if 0
int main()
{
	set<int, less<int>> iSet; 

	for (int i = 0; i < 10; i++)
		iSet.insert(i);

	iSet.insert(3); //键值是唯一的

	pair<set<int, less<int>>::iterator, set<int, less<int>>::iterator> itPair = iSet.equal_range(5);
	set<int, less<int>>::iterator itA, itB;

	itA = itPair.first;
	itB = itPair.second;

	cout << *itA << endl;
	cout << *itB << endl;
	for (set<int>::iterator it = iSet.begin(); it != iSet.end(); it++)
		cout << *it << ' ';
	cout << endl;


	return 0;
}
#endif
#if 0
int main()
{
	int temp;
	multiset<int> iMset;

	while (1 == scanf("%d", &temp))
	{
		iMset.insert(temp);
	}

	while (!iMset.empty())
	{
		multiset<int>::iterator it = iMset.begin();
		cout << *it << ' ';
		iMset.erase(it);
	}
	cout << endl;

	return 0;
}
#endif

/*
	尽管函数指针被广泛用于实现函数回调，但C++还提供了一个重要的实现回调函数的方法，那就是函数对象。
functor，翻译成函数对象，伪函数，算符，是重载了“()”操作符的普通类对象。从语法上讲，它与普通函数行
为类似。
	greater<>与less<>就是函数对象。
	下面举出greater<int>的简易实现原理。
	struct greater
	{
		bool operator() (const int& iLeft, const int& iRight)
		{
		       return (iLeft>iRight);          //如果是实现less<int>的话，这边是return (iLeft<iRight);                                                                    
		}
	}
	容器就是调用函数对象的operator()方法去比较两个值的大小。
*/
#if 1
class CStudent
{
public:
	CStudent(int nID, string strName)
	{
		m_nID = nID;
		m_strName = strName;
	}

public:
	int m_nID;
	string m_strName;
};

struct stuFunctor
{
	bool operator()(const CStudent &stuL, const CStudent &stuR)
	{
		return (stuL.m_nID > stuR.m_nID);
	}
};

int main()
{
	set<CStudent, stuFunctor> stu;

	stu.insert(CStudent(1, "陈一"));
	stu.insert(CStudent(5, "王五"));
	stu.insert(CStudent(3, "张三"));
	stu.insert(CStudent(4, "李四"));
	stu.insert(CStudent(2, "赵二"));

	for (auto pstu : stu)
		cout << pstu.m_nID << ' ' << pstu.m_strName << endl;

	return 0;
}

#endif

