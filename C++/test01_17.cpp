#include <iostream>
#include <cstring>

using namespace std;

#if 1
//改变fun函数中的返回值形式和函数tmp的定义形式、还有main函数中的t1的定义形式，观察结果得结论。
//详细结果查看笔记编译器的优化
class Test
{
public:
	Test(int d = 0) : data(d)
	{
		cout << "Create Obj : " << this << endl;
	}
	Test(const Test &t)
	{
		cout << "Copy Create Obj : " << this << endl;
		data = t.data;
	}
	//t2 = t1;
	Test& operator=(const Test &t)
	{
		cout << "Assign:" << this << " = " << &t << endl;
		if (this != &t)
		{
			data = t.data;
		}
		return *this;
	}
	~Test()
	{
		cout << "Free Obj : " << this << endl;
	}
public:
	//重载取值运算符
	Test* operator&()
	{
		return this;
	}
	//重载const类型的取值运算符
	const Test* operator&()const
	{
		return this;
	}
public:
	int GetData()const
	{
		return data;
	}
private:
	int data;
};

Test fun(Test &x)
{
	int val = x.GetData();
	Test tmp(val);
	return tmp;
}
#endif

#if 0
int main()
{
	Test t;
	Test *pt = &t;
	const Test t1;
	const Test *pt1 = &t1;

	return 0;
}
#endif

#if 1
int main()
{
	Test t;
	Test t1 = fun(t);

	system("pause");
	return 0;
}
#endif

#if 0
//练习拷贝构造和赋值运算符重载
class String
{
public:
	String(const char *str = " ")
	{
		if (str == NULL)
		{
			this->str = (char *)malloc(sizeof(char));
			this->str[0] = '\0';
		}
		else
		{
			this->str = (char *)malloc(sizeof(char)* (strlen(str) + 1));
			strcpy(this->str, str);
		}
	}

	String(const String &s)
	{
		this->str = (char *)malloc(sizeof(char)* (strlen(s.str) + 1));
		strcpy(this->str, s.str);
	}
	
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(this->str);
			this->str = (char *)malloc(sizeof(char)* (strlen(s.str) + 1));
			strcpy(this->str, s.str);
		}

		return *this;
	}

	~String()
	{
		free(str);
		str = NULL;
	}

public:
	char *str;
};

int main()
{
	String s1 = "hello";
	String s2 = s1;
	String s3;
	s3 = s1;

	return 0;
}
#endif