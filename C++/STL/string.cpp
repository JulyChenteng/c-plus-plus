/************************************string类******************************/
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#if 1
/*
1.构造函数：
	a.默认构造函数：
		string();	   //构造一个空的字符串string s1。
	b.拷贝构造函数：
		string(const string &str);//构造一个与str一样的string。如string s1(s2)。
	c.带参数的构造函数
   		string(const char *s);     //用字符串s初始化
   		string(int n, char c);     //用n个字符c初始化
*/
int main()
{
	string s1 = "hello world!";

	char chA = s1[2];		//利用数组下标取值
	char chB = s1.at(6);	//利用内部函数at函数取值

	char chC = s1[50]; 		//使用数组访问越界,其取值是不确定的
	char chD;
	try
	{
		char chD = s1.at(50);	//当用内部函数，访问越界时会抛出异常
	}
	catch(out_of_range)//????????
	{
		cout << "OUT OF RANGE!";
	}
	cout << chA << "\t" << chB << "\t" << chC << "\t" << chD << endl;

	return 0;
}
#endif 

#if 0
/*
2.string类的字符操作：
	const char &operator[] (int n) const;
	const char &at(int n) const;
	char  &operator[] (int n);
	char  &at(int n);
	
	//从string取得const char*的操作
	const char *c_str() const;   //返回一个以'\0'结尾的字符串

	//把string拷贝到char*指向的内存空间的操作
	//	  把当前串中以pos开始的n个字符拷贝到以s为起始位置的字符数组中，返回实际
    //拷贝的数目。注意要保证s所指向的空间足够大以容纳当前字符串，不然会越界。
	int copy(char *s, int n, int pos=0) const;  
*/
int main()
{
	string s1 = "hello world";
	char str[10] = {0};

	cout << s1 << endl;
	cout << s1.c_str() << endl; //将string 类型转化为const char*类型

	s1.copy(str, 7, 0); 		//将s1的前七个字符拷贝至str中
	cout << str << endl;

	return 0;
}
#endif

#if 0
/*
3.基本操作
	int length() const;   	//返回当前字符串的长度。长度不包括字符串结尾的'\0'。
	bool empty() const;     //当前字符串是否为空

	//赋值操作
	string& operator=(const string &s); 	//把字符串s赋给当前的字符串
	string& assign(const char *s); 			//把字符串s赋给当前的字符串
	string& assign(const char *s, int n); 	//把字符串s的前n个字符赋给当前的字符串
	string& assign(const string &s);  		//把字符串s赋给当前字符串
	string& assign(int n,char c);  			//用n个字符c赋给当前字符串
	string& assign(const string &s,int start, int n);  //把字符串s中从start开始的n个字符赋给当前字符串

	//连接操作
	string& operator+=(const string &s);  	//把字符串s连接到当前字符串结尾
	string& operator+=(const char *s);		//把字符串s连接到当前字符串结尾
	string& append(const char *s);    		//把字符串s连接到当前字符串结尾
	string& append(const char *s,int n); 	//把字符串s的前n个字符连接到当前字符串结尾
	string& append(const string &s);   		//同operator+=()
	string& append(int n, char c);   		//在当前字符串结尾添加n个字符c
	string& append(const string &s,int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
*/
int main()
{
	string str = "hello ";
	string s1 = "world";
	string s2 = "award";

	str += s1;
	str += "!";

	str.append("123");
	s1.append("hello", 3); //将"hello"的前n个字符追加至s1末尾
	s2.append(s1, 2, 5);   //将s1中从第3个字符开始的5个字符（包括第3个字符)追加至s2末尾

	cout << str << endl;
	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}
#endif

#if 0
/*
4.string常用操作一
	//比较操作
	//compare函数在>时返回 1，<时返回 -1，==时返回 0。比较区分大小写，
	//比较时参考字典顺序，排越前面的越小。大写的A比小写的a小。
	int compare(const string &s) const;  //与字符串s比较
	int compare(const char *s) const;    //与字符串s比较

	//子串操作
	string substr(int pos=0, int n=npos) const;		//返回由pos开始的n个字符组成的子字符串

	//查找
	//注意返回值始终是在当前字符串中的位置
	int find(char c,int pos=0) const;  				//从pos开始查找字符c在当前字符串的位置，如果查找不到，就返回-1
	int find(const char *s, int pos=0) const;  		//从pos开始查找字符串s在当前字符串的位置，如果查找不到，就返回-1
	int find(const string &s, int pos=0) const;  	//从pos开始查找字符串s在当前字符串中的位置，如果查找不到，就返回-1

	//返回值始终是在当前字符串中的位置，是反向查找，但是位置是相对于第一个字符而言的
	int rfind(char c, int pos=npos) const;   		//从pos开始从后向前查找字符c在当前字符串中的位置(反向查找)，如果查找不到， 返回-1
	int rfind(const char *s, int pos=npos) const;
	int rfind(const string &s, int pos=npos) const;
*/
int main()
{
	string str = "hello world!";
	string subStr;

	subStr = str.substr(1, 6);  //将str中从第2个字符开始的6个字符赋给subStr

	int pos0 = str.find('w', 0); //6
	int pos1 = str.find("world", 0);

	int pos2 = str.rfind('o');		 //反向查找到的第一个'o'，在字符串中的位置为8

	cout << pos0 << endl;
	cout << pos1 << endl;
	cout << pos2 << endl;
	cout << subStr << endl;

	return 0;
}
#endif

#if 0
/*
4.string常用操作二
	//插入操作
	//前两个函数在pos位置插入字符串s
	string &insert(int pos, const char *s);
	string &insert(int pos, const string &s);
	string &insert(int pos, int n, char c);  //在pos位置 插入n个字符c

	//删除操作
	string &erase(int pos=0, int n=npos);  //删除pos开始的n个字符，返回修改后的字符串

	//替换操作
	string &replace(int pos, int n, const char *s);		//删除从pos开始的n个字符，然后在pos处插入串s
	string &replace(int pos, int n, const string &s);   //删除从pos开始的n个字符，然后在pos处插入串s
	void swap(string &s2);    							//交换当前字符串与s2的值
*/
int main()
{
	string str("world");

	str.insert(0, "hello ");	//hello world
	cout << str << endl;

	str.erase(5, 1); 			//helloworld
	cout << str << endl;

	str.replace(2, 4, "hello"); //hehelloorld
	cout << str << endl;

	return 0;
}
#endif

#if 0
/*
string与wstring的区别：
	string是对char*的管理，一个字符只占一个字节大小。一个汉字占两个字节，ASCII编码。
	wstring是对wchar_t*的管理，一个字符占两个字节大小，一个汉字占两个字节，Unicode编码。
	wstring的使用方法跟string类似，区别主要在于函数参数char*与函数参数wchar_t*
string与wstring的转换：
	第一种方法
	    调用Windows的API函数：WideCharToMultiByte()函数和MultiByteToWideChar()函数。
	第二种方法
	   使用ATL的CA2W类与CW2A类。或使用A2W宏与W2A宏。
	第三种方法，跨平台的方法，使用CRT库的mbstowcs()函数和wcstombs()函数，需设定locale。
	以下是第三种方法的实现例子：
		#include <string>
		#include <locale.h>
		using namespace std;

		//wstring转成string
		string ws2s(const wstring &ws)
		{
			string curLocale = setlocale(LC_ALL,NULL);  //curLocale="C";
			setlocale(LC_ALL,"chs");
			const wchar_t * _Source=ws.c_str();
			size_t _Dsize=2*ws.size()+1;
			char * _Dest = new char[_Dsize];
			memset(_Dest,0,_Dsize);
			wcstombs(_Dest,_Source,_Dsize);
			string result = _Dest;
			delete[] _Dest;
			setlocale(LC_ALL,curLocale.c_str());
			return result;
		}

		//string转成wstring
		wstring s2ws(const string &s)
		{
			string curLocale = setlocale(LC_ALL,NULL);    //curLocale = "C"
			setlocale(LC_ALL, "chs");
			const char *_Source = s.c_str();
			size_t _Dsize = s.size()+1;
			wchar_t *_Dest = new wchar_t[_Dsize];
			wmemset(_Dest,0,_Dsize);
			mbstowcs(_Dest,_Source,_Dsize);
			wstring result = _Dest;
			delete[] _Dest;
			setlocale(LC_ALL, curLocale.c_str());
			return result;
		}

编码统一化，编写单一程序：
		如果我们想建立两个版本的程序，一个处理ASCII字符串，另一个处理Unicode字符串，最好的解决办法是编写出既能按ASCII编译
	又能按Unicode编译的单一源代码。把以下代码加入到程序中，只要修改一个宏就能满足我们的要求。
		#ifdef _UNICODE
		typedef wstring  tstring;
		typedef wchar_t  tchar;
		#define _T(x)  L ## x
		#else
		typedef string tstring;
		typedef char tchar;
		#define _T(x) x
		#endif
*/
#endif
