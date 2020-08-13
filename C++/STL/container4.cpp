/**************************map/multimap*********************************/
#include <iostream>
#include <map>

using namespace std;

/*
map简介：
	map是标准的关联式容器，一个map是一个键值对序列，即(key,value)对。它提供基于key的快速检索能力。
	map中key值是唯一的。集合中的元素按一定的顺序排列。元素插入过程是按排序规则插入，所以不能指定插入位置。
	map的具体实现采用红黑树变体的平衡二叉树的数据结构。在插入操作和删除操作上比vector快。
	map可以直接存取key所对应的value，支持[]操作符，如map[key]=value。
	multimap与map的区别：map支持唯一键值，每个键只能出现一次；而multimap中相同键可以出现多次。multimap不
支持[]操作符。
map/multimap采用模板类实现，对象的默认构造形式：
	map<T1,T2> mapTT; 
	multimap<T1,T2>  multimapTT;  

插入：
	map.insert(...);    //往容器插入元素，返回pair<iterator,bool>

	在map中插入元素的三种方式：
		假设  map<int, string> mapStu;

		一、通过pair的方式插入对象
			mapStu.insert(pair<int,string>(3,"小张"));
		二、通过value_type的方式插入对象
			mapStu.insert(map<int,string>::value_type(1,"小李")); //make_pair(1, "小李")
		三、通过数组的方式插入值
			mapStu[3] = “小刘";
			mapStu[5] = “小王"；
			...
			第三种方法非常直观，但存在一个性能的问题。插入3时，先在mapStu中查找主键为3的项，若没发现，
		则将一个键为3，值为初始化值的对组插入到mapStu中，然后再将值修改成“小刘”。若发现已存在3这个键，
		则修改这个键对应的value。

			前两种方法，采用的是insert()方法，该方法返回值为pair<iterator,bool>
	pair< map<int,string>::iterator , bool> pairResult  = mapStu.insert(pair<int,string>(3,"小张"));
	如果插入成功，(pairResult.first)->first==3, (pairResult.first)->second=="小张", pairResult.second==true。

	map<T1,T2,less<T1> >  mapA;  	//该容器是按键的升序方式排列元素。未指定函数对象，默认采用less<T1>函数对象。
	map<T1,T2,greater<T1>> mapB;   	//该容器是按键的降序方式排列元素。
	less<T1>与greater<T1>  可以替换成其它的函数对象functor。

	可编写自定义函数对象以进行自定义类型的比较，使用方法与set构造时所用的函数对象一样。

取操作和插入操作：
	string strName = mapStu[2];   //取操作或插入操作
	上面操作只有当mapStu存在2这个键时才是正确的取操作，否则会自动插入一个实例，键为2，值为初始化值。

迭代器：
	map.begin();  	//返回容器中第一个数据的迭代器。
	map.end();  	//返回容器中最后一个数据之后的迭代器。
	map.rbegin();  	//返回容器中倒数第一个元素的迭代器。
	map.rend();   	//返回容器中倒数最后一个元素的后面的迭代器。

拷贝构造与赋值：
	map(const map &mp);		     	//拷贝构造函数
	map& operator=(const map &mp);	//重载等号操作符
	map.swap(mp);					//交换两个集合容器

大小：
	map.size();	//返回容器中元素的数目
	map.empty();//判断容器是否为空

删除:
	map.clear();			//删除所有元素
	map.erase(pos);			//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	map.erase(beg,end);	    //删除区间[beg,end)的所有元素	，返回下一个元素的迭代器。
	map.erase(keyElem);     //删除容器中key为keyElem的对组。

查找:
	map.find(key);   		//查找键key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回map.end();
	map.count(keyElem);   	//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
	map.lower_bound(keyElem);  	//返回第一个key>=keyElem元素的迭代器。
	map.upper_bound(keyElem);	//返回第一个key>keyElem元素的迭代器。
	//equal_range函数返回两个迭代器，而这两个迭代器被封装在pair中。
	map.equal_range(keyElem);	//返回容器中key与keyElem相等的上下限的两个迭代器。上限是闭区间，下限是开区间，如[beg,end)。
*/
#if 0
int main()
{
	map<int, string> mapStu;

	pair<map<int, string>::iterator, bool> pairResult = mapStu.insert(pair<int, string>(3, "tony"));
	mapStu.insert(make_pair(1, "tom"));

	map<int, string>::iterator it = mapStu.find(3);
	if (it != mapStu.end())
	{
		int i = it->first;
		string name = it->second;
		cout << i << "\t" << name << endl << endl;
	}

	/*
	auto map_it = mapStu.cbegin();
	while (map_it != mapStu.cend())
	{
		cout << map_it->first << "\t" << map_it->second << endl;
		++map_it;
	}
	*/
	for (auto p : mapStu)
		cout << p.first << "\t" << p.second << endl;

	return 0;
}
#endif

#if 0
int main()
{
	map<int, string> mapStu;

	mapStu.insert(make_pair(1, "tom"));
	mapStu.insert(pair<int, string>(1, "tom"));
	mapStu.insert(pair<int, string>(2, "tony"));
	mapStu.insert(pair<int, string>(3, "alpha"));
	mapStu.insert(pair<int, string>(5, "loral"));
	mapStu.insert(pair<int, string>(7, "roral"));
	mapStu.insert(pair<int, string>(8, "list"));

	auto itA = mapStu.lower_bound(5);
	auto itB = mapStu.upper_bound(5);
	cout << itA->first << "\t" << itA->second << endl;
	cout << itB->first << "\t" << itB->second << endl;

	cout << endl;
	
	//如果所查找的key不在map中，则返回比它大的键值对的迭代器
	itA = mapStu.lower_bound(5);
	itB = mapStu.upper_bound(5);
	cout << itA->first << "\t" << itA->second << endl;
	cout << itB->first << "\t" << itB->second << endl;

	cout << endl;

	pair<map<int, string>::iterator, map<int, string>::iterator> pairA = mapStu.equal_range(5);
	itA = pairA.first;
	itB = pairA.second;
	cout << itA->first << "\t" << itA->second << endl;
	cout << itB->first << "\t" << itB->second << endl;
 
	return 0;
}
#endif

#if 1
struct userdevice
{
	string m_devicename;
	long m_deviceid;
	int m_devicePopedom;
};

typedef multimap<string, userdevice> USERTABLE;
typedef USERTABLE::const_iterator CIT;
typedef pair<CIT, CIT> Range;

int main()
{
	CIT it;
	userdevice d1, d2, d3, d4;
	
	d1.m_deviceid = 1234;
	d1.m_devicename = "d1";
	d1.m_devicePopedom = 123;

	d2.m_deviceid = 2345;
	d2.m_devicename = "d2";
	d2.m_devicePopedom = 234;

	d3.m_deviceid = 3456;
	d3.m_devicename = "d3";
	d3.m_devicePopedom = 345;

	d4.m_deviceid = 4567;
	d4.m_devicename = "d4";
	d4.m_devicePopedom = 456;

	USERTABLE user;

	user.insert(make_pair("tom", d1));
	user.insert(make_pair("tom", d2));

	user.insert(make_pair("tony", d3));
	user.insert(make_pair("tony", d4));

	//查找方法一
	Range range = user.equal_range("tom");
	for (CIT it = range.first; it != range.second; ++it)
	{
		cout << it->second.m_deviceid << "\t"
			<< it->second.m_devicename << "\t"
			<< it->second.m_devicePopedom << endl;
	}
	cout << endl;

	//查找方法二
	it = user.find("tony");
	while (it != user.end())
	{
		cout << it->second.m_deviceid << "\t"
			<< it->second.m_devicename << "\t"
			<< it->second.m_devicePopedom << endl;

		++it;
	}
	cout << endl;

	//遍历
	for (auto p : user)
	{
		cout << p.second.m_deviceid << "\t"
			<< p.second.m_devicename << "\t"
			<< p.second.m_devicePopedom << endl;
	}


	return 0;
}
#endif