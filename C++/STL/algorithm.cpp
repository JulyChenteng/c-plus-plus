#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <set>
#include <ctime>

using namespace std;

/*
	算法部分主要由头文件<algorithm>，<numeric>和<functional>组成。
	<algorithm>是所有STL头文件中最大的一个，其中常用到的功能范围涉及到比较、交换、
查找、遍历操作、复制、修改、反转、排序、合并等等。
	<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数，包括加法和
乘法在序列上的一些操作。
	<functional>中则定义了一些模板类，用以声明函数对象。

	STL提供了大量实现算法的模版函数，只要我们熟悉了STL之后，许多代码可以被大大的化简，
只需要通过调用一两个算法模板，就可以完成所需要的功能，从而大大地提升效率。
	
常用的查找算法：
	adjacent_find()（ adjacent 是邻近的意思）,binary_search(),count(),
	count_if(),equal_range(),find(),find_if()。
	
	adjacent_find(): 在iterator对标识元素范围内，查找一对相邻重复元素，找到则返回指向这
对元素的第一个元素的迭代器。否则返回past-the-end。  
	binary_search:  在有序序列中查找value,找到则返回true。注意：在无序序列中，不可使用。
	count:     		利用等于操作符，把标志范围内的元素与输入值比较，返回相等的个数。
	count_if:  		利用输入的函数，对标志范围内的元素进行比较操作，返回结果为true的个数
	equal_range:    返回一对iterator，第一个表示lower_bound,第二个表示upper_bound。
	find:  			利用底层元素的等于操作符，对指定范围内的元素与输入值进行比较。当匹配时，
结束搜索，返回该元素的迭代器。
	find_if:   		使用输入的函数代替等于操作符执行find。返回被找到的元素的迭代器。

常用的排序算法：
	merge(),sort(),random_shuffle()（shuffle是洗牌的意思） ,reverse()。

	以下是排序和通用算法：提供元素排序策略
	merge:   合并两个有序序列，存放到另一个序列。
	sort:  	 以默认升序的方式重新排列指定范围内的元素。若要改排序规则，可以输入比较函数
	random_shuffle:     对指定范围内的元素随机调整次序。
	reverse:   	    对指定范围内元素重新反序排序。

常用的拷贝和替换算法：
	copy(), replace(),
	replace_if(),swap()

常用的算术和生成算法：
	accumulate()（ accumulate 是求和的意思）,fill()。
	
	accumulate: 对指定范围内的元素求和，然后结果再加上一个由val指定的初始值。
	fill:   	将输入值赋给标志范围内的所有元素

常用的集合算法：
	set_union(),set_intersection(),
	set_difference()。

	set_union:  构造一个有序序列，包含两个有序序列的并集。
	set_intersection:  构造一个有序序列，包含两个有序序列的交集。
	set_difference:  构造一个有序序列，该序列保留第一个有序序列中存在而第二个有序序列中不存在的元素。


常用的遍历算法：
	for_each(), transform()（ transform 是变换的意思）

	for_each:  用指定函数依次对指定范围内所有元素进行迭代访问。该函数不得修改序列中的元素。
	transform: 与for_each类似，遍历所有元素，但可对容器的元素进行修改
	
*/

#if 0
bool greaterThree(int value)
{
	if (value >= 3)
		return true;
	else
		return false;
}

//查找
int main()
{
	vector<int> ivec;
	for (int i = 0; i < 10; i++)
		ivec.push_back(i);
	ivec.push_back(9);
	ivec.push_back(9);

	auto it1 = adjacent_find(ivec.begin(), ivec.end());
	cout << *it1 << endl;		//9

	set<int> iset;
	for (int i = 0; i < 10; i++)
		iset.insert(i);

	bool bFind = binary_search(iset.begin(), iset.end(), 5);
	if (bFind)
		cout << "Find Sucess!" << endl;

	int nCount = count(ivec.begin(), ivec.end(), 9);
	cout << nCount << endl;		//3

	nCount = count_if(ivec.begin(), ivec.end(), greaterThree);
	cout << nCount << endl;		//9

	auto it2 = find(ivec.begin(), ivec.end(), 4);
	cout << *it2 << endl;		//4

	cout << endl;
	for (auto it3 = find_if(ivec.begin(), ivec.end(), greaterThree); it3 != ivec.end(); it3++)
	{
		it3 =find_if(it3, ivec.end(), greaterThree);
		cout << *it3 << "  ";
	}
	cout << endl;

	return 0;
}
#endif

#if 0
//排序
int main()
{
	vector<int> ivecA;
	for (int i = 1; i < 10; i += 2)
		ivecA.push_back(i);

	vector<int> ivecB;
	for (int i = 2; i < 10; i += 2)
		ivecB.push_back(i);

	vector<int> ivecC;
	ivecC.resize(9);
	merge(ivecA.begin(), ivecA.end(), ivecB.begin(), ivecB.end(), ivecC.begin());
	sort(ivecC.begin(), ivecC.end());

	for (auto it : ivecC)
		cout << it << "  ";
	cout << endl;

	return 0;
}
#endif

#if 0
//学生类
class CStudent
{
public:
    CStudent(int iID, string strName)
		{m_iID=iID;  m_strName=strName; }

public:            
	int m_iID;
	string m_strName;
};

//学号比较函数
bool Compare(const CStudent &stuA,const CStudent &stuB)
{
 		 return (stuA.m_iID<stuB.m_iID);
}

//排序
int main()
{
	//srand(time(0));//设置随机种子，让每次运行时随机排列的顺序都不同

   	vector<CStudent> vecStu;
    vecStu.push_back(CStudent(2,"tom"));
	vecStu.push_back(CStudent(1,"tony"));
	vecStu.push_back(CStudent(3,"hello"));
	vecStu.push_back(CStudent(4,"caty"));
      
    sort(vecStu.begin(),vecStu.end(),Compare);
    //random_shuffle(vecStu.begin(), vecStu.end());
    reverse(vecStu.begin(), vecStu.end()); //反转

    for (auto it : vecStu)
    	cout << it.m_strName << "  ";
    cout << endl;

	return 0;
}
#endif

#if 0
bool greaterThree(int value)
{
	if (value >= 3)
		return true;
	else
		return false;
}

//拷贝和替换
int main()
{
	vector<int> ivecA;
	for (int i = 1; i < 10; i += 2)
		ivecA.push_back(i);

	vector<int> ivecB;
	ivecB.resize(5);

	copy(ivecA.begin(), ivecA.end(), ivecB.begin());
	replace(ivecB.begin(), ivecB.end(), 3, 8); //把所有的3替换成8
	replace_if(ivecB.begin(), ivecB.end(), greaterThree, 8);//将满足条件的替换成8

	for (auto it : ivecB)
		cout << it << "  ";
	cout << endl << endl;

	int sum = accumulate(ivecB.begin(), ivecB.end(), 100);//ivecB中元素之和加上100
	cout << "sum = " << sum << endl;

	fill(ivecA.begin(), ivecA.end(), 0);
	for (auto it : ivecA)
		cout << it << "  ";
	cout << endl << endl;

	return 0;
}
#endif

#if 0
int main()
{
	vector<int> ivecA;
	for (int i = 1; i < 10; i += 2)
		ivecA.push_back(i);
	ivecA.push_back(2);
	ivecA.push_back(4);

	vector<int> ivecB;
	for (int i = 2; i < 10; i += 2)
		ivecB.push_back(i);

	vector<int> ivecC;
	ivecC.resize(11);

//???
	set_union(ivecA.begin(), ivecA.end(), ivecB.begin(), ivecB.end(), ivecC.begin());//C为A、B两个集合的并集，元素无重复
	//fill(ivecC.begin(), ivecC.end(), 0);
	//set_intersection(ivecA.begin(), ivecA.end(), ivecB.begin(), ivecB.end(), ivecC.begin());
	//set_difference(ivecA.begin(), ivecA.end(), ivecB.begin(), ivecB.end(), ivecC.begin());

	for (auto it : ivecC)
		cout << it << "  ";
	cout << endl;

	return 0;
}
#endif

#if 1
void show(int value)
{
	cout << value << " ";
}

int increase(int value)
{
	return value+1;
}

//遍历
int main()
{
	int array[] = {1, 3, 5, 7, 9};

	for_each(array, array+5, show);
	cout << endl << endl;

	transform(array, array+5, array, increase);
	for_each(array, array+5, show);
	cout << endl << endl;

	return 0;
}
#endif