/***************************deque、queue、stack、list*******************************/
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <list>

using namespace std;

/*
deque(double-ended queue)，和vector一样都是STL的容器，deque是双端的，而vector是单向的。
deque在接口上和vector非常相似，在许多操作的地方可以直接替换。
deque可以随机存取元素（支持索引值直接存取， 用[]操作符或at()方法）。
deque头部和尾部添加或移除元素都非常快速。但是在中部安插元素或移除元素比较费时。

stack和queue都是简单的装饰deque而形成的。

deque采用模板类实现，默认构造形式：deque<T> deqT;  
基本操作：
	deque.push_back(elem);	//在容器尾部添加一个数据
	deque.push_front(elem);	//在容器头部插入一个数据
	deque.pop_back();    	//删除容器最后一个数据
	deque.pop_front();		//删除容器第一个数据

存取：
	deque.at(idx); 	//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
	deque[idx];  	//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
	deque.front(); 	//返回第一个数据。
	deque.back();  	//返回最后一个数据。

迭代器
	deque.begin();  //返回容器中第一个元素的迭代器。
	deque.end();  	//返回容器中最后一个元素之后的迭代器。
	deque.rbegin(); //返回容器中倒数第一个元素的迭代器。
	deque.rend();   //返回容器中倒数最后一个元素之后的迭代器。

带参构造函数：
	deque(beg,end);    	//构造函数将[beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
	deque(n,elem);    	//构造函数将n个elem拷贝给本身。
	deque(const deque  &deq);  //拷贝构造函数。

赋值：
	deque.assign(beg,end);  //将[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
	deque.assign(n,elem);  	//将n个elem拷贝赋值给本身。
	deque.swap(deq);  		// 将vec与本身的元素互换。
	deque& operator=(const deque &deq);	//重载等号操作符

大小：
	deque.size();	   //返回容器中元素的个数
	deque.empty();	   //判断容器是否为空
	deque.resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	deque.resize(num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

插入：
	//参数pos由迭代器指定
	deque.insert(pos,elem);   	//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	deque.insert(pos,n,elem);   //在pos位置插入n个elem数据，无返回值。
	deque.insert(pos,beg,end);  //在pos位置插入[beg,end)区间的数据，无返回值。

删除：
	deque.clear();			//移除容器的所有数据
	deque.erase(beg,end);  	//删除[beg,end)区间(由迭代器制定)的数据，返回下一个数据的位置。
	deque.erase(pos);    	//删除pos位置(由迭代器制定)的数据，返回下一个数据的位置。
*/
#if 0
int main()
{
	return 0;
}
#endif

/*
queue是队列容器，是一种“先进先出”的容器。
基本操作：
	queue.push(elem);   //往队尾添加元素
	queue.pop();   		//从队头移除第一个元素
存取：
	queue.back();		//返回最后一个元素
	queue.front();   	//返回第一个元素

大小：
	queue.empty();   	//判断队列是否为空
	queue.size(); 	    //返回队列的大小
*/
#if 0
int main()
{
	return 0;
}
#endif
/*
stack是堆栈容器，是一种“先进后出”的容器
基本操作
	stack.push(elem);   //往栈头添加元素
	stack.pop();   		//从栈头移除第一个元素

存取：
	stack.top();	  	//返回最后一个压入栈元素

大小：
	stack.empty();   	//判断堆栈是否为空
	stack.size(); 	    //返回堆栈的大小
*/
#if 0
int main()
{
	return 0;
}
#endif

/*
list是一个双向链表容器，可高效地进行插入删除元素。
list不可以随机存取元素，所以不支持at.(pos)函数与[]操作符。

list采用模板类实现，list对象的默认构造形式：list<T> lstT;

首尾添加移除操作：
	list.push_back(elem);	   	//在容器尾部加入一个元素
	list.pop_back();          	//删除容器中最后一个元素
	list.push_front(elem);     	//在容器开头插入一个元素
	list.pop_front();         	//从容器开头移除第一个元素

存取：
	list.front();   //返回第一个元素。
	list.back();  	//返回最后一个元素。

迭代器操作：
	list.begin();       //返回容器中第一个元素的迭代器。
	list.end();    		//返回容器中最后一个元素之后的迭代器。
	list.rbegin();     	//返回容器中倒数第一个元素的迭代器。
	list.rend();      	//返回容器中倒数最后一个元素的后面的迭代器

带参构造函数：
	list(beg,end);    	//构造函数将[beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
	list(n,elem);   	//构造函数将n个elem拷贝给本身。
	list(const list &lst);  //拷贝构造函数。

赋值：
	list.assign(beg,end);    //将[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
	list.assign(n,elem);  	 //将n个elem拷贝赋值给本身。
	list& operator=(const list &lst);	//重载等号操作符
	list.swap(lst);     	// 将lst与本身的元素互换。

大小：
	list.size();	   //返回容器中元素的个数
	list.empty();	   //判断容器是否为空
	list.resize(num);  //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	list.resize(num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

插入：
	//pos由迭代器指定
	list.insert(pos,elem);   	//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	list.insert(pos,n,elem);   	//在pos位置插入n个elem数据，无返回值。
	list.insert(pos,beg,end);   //在pos位置插入[beg,end)区间的数据，无返回值。

删除：
	list.clear();			//移除容器的所有数据
	list.erase(beg,end);  	//删除[beg,end)区间（由迭代器指定）的数据，返回下一个数据的位置。
	list.erase(pos);    	//删除pos位置（由迭代器指定）的数据，返回下一个数据的位置。
	lst.remove(elem);   	//删除容器中所有与elem值匹配的元素。

反序排列：
	lst.reverse();     		//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
*/
#if 1
int main()
{
	int array[] = {1, 2, 3, 3, 4, 3, 5, 6};
	list<int> ilist(array, array+8);

	ilist.remove(3);
	ilist.reverse();

	for (auto i : ilist)
		cout << i << ' ';
	cout << endl;

	return 0;
}
#endif