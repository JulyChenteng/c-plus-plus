/**********************容器简介、vector、迭代器****************************/
#include <iostream>
#include <vector>

using namespace std;

#if 0
/*
容器：一些特定类型对象的集合
容器的分类：
	容器有序列式容器（Sequence containers）和关联式容器（Associated containers）

序列式容器：每个元素的位置取决于元素被插入的时机,被插入时设置的位置，和元素值本身无关。
			序列式容器有vector、deque、list

关联式容器：元素位置取决于特定的排序准则，和插入顺序无关。
			关联式容器有set、multiset、map、multimap
*/
/*
vector特点：
	是将元素置于一个动态数组中加以管理的容器。
	可以随机存取元素（支持索引值直接存取， 用[]操作符或at()方法）。
	尾部添加或移除元素非常快速。但是在中部或头部插入元素或移除元素比较费时。

vector采用模板类实现，vector对象的默认构造形式：vector<T> vecT; 
如：
	vector<int> vecInt;         //一个存放int的vector容器。
	vector<float> vecFloat;     //一个存放float的vector容器。
	vector<string> vecString;   //一个存放string的vector容器。
	...				    		//尖括号内还可以设置指针类型或自定义类型。
	Class CA{};
	vector<CA*> vecpCA;	 		//用于存放CA对象的指针的vector容器。
	vector<CA> vecCA;     		//用于存放CA对象的vector容器。由于容器元素的存放是按值复制的方式进行的，
								//所以此时CA必须提供CA的拷贝构造函数，以保证CA对象间拷贝正常。
*/
/*
vector 基本操作：
	push_back(elem);	//在容器尾部加入一个元素。
	pop_back();      //移除容器中最后一个元素

vector数据存取：
	at(idx);  		//返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
	vec[idx];	//返回索引idx所指的数据，越界时，会得到一个不确定的值。
	front();   	//返回第一个数据。
	back();    	//返回最后一个数据
*/
int main()
{
	vector<int> ivec;

	for (int i = 0; i < 10; i++)
		ivec.push_back(i);	//添加元素至末尾

	ivec.pop_back();		//删除末尾元素

	ivec[2] = 155;
	ivec[3] = 177;

	int nfront = ivec.front();
	cout << nfront << endl;
	int nback = ivec.back();
	cout << nback << endl;

	ivec.front() = 133;
	ivec.back() = 199;

	for (size_t i = 0; i < ivec.size(); i++)
		cout << ivec.at(i) << ' '; 

	cout << endl;

	return 0;
}
#endif

#if 0
/*
迭代器是一个“可遍历STL容器内全部或部分元素”的对象。
迭代器指出容器中的一个特定位置。
迭代器就如同一个指针。
迭代器提供对一个容器中的对象的访问方法，并且可以定义了容器中对象的范围。

迭代器的类别：
	输入迭代器：也有叫法称之为“只读迭代器”，它从容器中读取元素，只能一次读入一个元素向前移动，
只支持一遍算法，同一个输入迭代器不能两遍遍历一个序列。
	输出迭代器：也有叫法称之为“只写迭代器”，它往容器中写入元素，只能一次写入一个元素向前移动，
只支持一遍算法，同一个输出迭代器不能两遍遍历一个序列。
	正向迭代器：组合输入迭代器和输出迭代器的功能，还可以多次解析一个迭代器指定的位置，可以对一个值进行多次读/写。
	双向迭代器：组合正向迭代器的功能，还可以通过--操作符向后移动位置。
	随机访问迭代器：组合双向迭代器的功能，还可以向前向后跳过任意个位置，可以直接访问容器中任何位置的元素。

双向迭代器支持的操作：
	it++,  ++it,    it--,   --it，*it， itA = itB，
	itA == itB，itA != itB
	          其中list,set,multiset,map,multimap支持双向迭代器。

随机访问迭代器支持的操作：
	在双向迭代器的操作基础上添加 
	it+=i， it-=i， it+i(或it=it+i)，it[i],
	itA<itB,   itA<=itB,  itA>itB,  itA>=itB  的功能。
	          其中vector，deque支持随机访问迭代器。

vector与迭代器的配合使用
	vec.begin();  	//返回容器中第一个元素的迭代器。
	vec.end();  	//返回容器中最后一个元素之后的迭代器。
	vec.rbegin();  	//返回容器中倒数第一个元素的迭代器。
	vec.rend();   	//返回容器中倒数最后一个元素之后的迭代器

迭代器还有其它两种声明方法，这两种分别是：
如：
	vector<int>::const_iterator
	vector<int>::const_reverse_iterator
	
	vector<int>::iterator
	vector<int>::reverse_iterator的只读形式，使用这两种迭代器时，不会修改到容器中的值。
		
		备注：不过容器中的insert和erase方法仅接受这四种类型中的iterator，其它三种不支持。《Effective STL》建议我们尽量使用
	iterator取代const_iterator、reverse_iterator和const_reverse_iterator。

*/
int main()
{
	vector<int> ivec;

	for (int i = 0; i < 10; i++)
		ivec.push_back(i);	//添加元素至末尾

	vector<int>::iterator it = ivec.begin();
	++it;
	it--;
	it += 2;

	cout << *it << endl;
	for (it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	for (vector<int>::reverse_iterator it = ivec.rbegin(); it != ivec.rend(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	return 0;
}
#endif


/*
vector带参构造函数：
	vector(beg,end);    //构造函数将[beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
	vector(n,elem);   	/构造函数将n个elem拷贝给本身。
	vector(const vector &vec);  //拷贝构造函数。

赋值操作：
	vector.assign(beg,end);    	//将[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
	vector.assign(n,elem);  	//将n个elem拷贝赋值给本身。
	vector.swap(vec);  			// 将vec与本身的元素互换。
	vector& operator=(const vector  &vec);	//重载等号操作符

vetor大小：
	vector.size();	   			//返回容器中元素的个数
	vector.empty();	  		 	//判断容器是否为空
	vector.resize(num);   		//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	vector.resize(num, elem); 	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

vector插入：
	//insert函数的第一个参数（要插入元素的位置）是由迭代器指定的
	vector.insert(pos,elem);   		//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	vector.insert(pos,n,elem);   	//在pos位置插入n个elem数据，无返回值。
	vector.insert(pos,beg,end);   	//在pos位置插入[beg,end)区间的数据，无返回值。

vector删除：
	vector.clear();			//移除容器的所有数据
	vec.erase(beg,end);  	//删除[beg,end)区间（由迭代器指定）的数据，返回下一个数据的位置。
	vec.erase(pos);    		//删除pos位置(由迭代器指定)的数据，返回下一个数据的位置。
*/
#if 0
int main()
{
	int array[] = {0, 1, 2, 3, 4, 5};

	vector<int> ivec1(array, array+5);
	vector<int> ivec2(ivec1.begin(), ivec1.end());
	vector<int> ivec3(5, 9);

	ivec2.insert(ivec2.begin(), 9);
	ivec1.insert(ivec1.begin()+2, 3, 9);
	ivec3.insert(ivec3.begin()+2, ivec1.begin(), ivec1.end());

	for (auto i : ivec1)
		cout << i << ' ';
	cout << endl;

	for (auto i : ivec2)
		cout << i << ' ';
	cout << endl;

	for (auto i : ivec3)
		cout << i << ' ';
	cout << endl;
	return 0;
}
#endif

#if 1
int main()
{
	int array[] = {1, 2, 3, 4, 5, 6};
	vector<int> ivec(array, array+6);

	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		if (3 == *it)
			it = ivec.erase(it); //删除vector中等于3的元素
		else
			++it;
	}

	for (auto i : ivec)
		cout << i << ' ';
	cout << endl;

	return 0;
}
#endif