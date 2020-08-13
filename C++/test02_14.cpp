#include<iostream>
#include<new.h>
#include<string>
using namespace std;

//1解决内存泄漏
//2编写赋值语句
//3写时拷贝
class String;
ostream& operator<<(ostream &out, const String &s);

/////////////////////////////////////////////////////////////////////
class String_rep
{
	friend class String;
	friend ostream& operator<<(ostream &out, const String &s);

private:
	String_rep(const char *str = "") : use_count_(0)
	{
		if (str == NULL)
		{
			data = new char[1];
			data[0] = '\0';
		}
		else
		{
			data = new char[strlen(str) + 1];
			strcpy(data, str);
		}
	}
	String_rep(const String_rep &rep)
	{
		this->data = rep.data;
	}
	String_rep& operator=(const String_rep &rep)
	{
		this->data = rep.data;
	}
	~String_rep()
	{
		if (data != NULL)
		{
			delete[]data;
			data = NULL;
		}
	}
public:
	void increment()
	{
		++use_count_;
	}

	void decrement()
	{
		//引用计数为0，释放共享内存
		if (--use_count_ == 0)
			delete this;
	}

private:
	char *data;
	int use_count_;
};
//////////////////////////////////////////////////////
class String
{
	friend ostream& operator<<(ostream& out, const String &s);

public:
	String(const char *str = "") :rep(new String_rep(str))
	{
		rep->increment();
	}
	String(const String &s)
	{
		rep = s.rep;
		rep->increment();
	}
	String& operator=(const String &s)
	{
		if (&s != this)
		{
			this->rep->decrement();	  //原有共享内存中的引用计数减一
			this->rep = s.rep;
			this->rep->increment();	  //现有引用计数加一
		}
		return *this;
	}
	~String()
	{
		//String析构一次，引用计数减一
		rep->decrement();
	}

public:
	void to_upper();
	String& operator+=(const String &str);

private:
	String_rep *rep;
};

/////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream &out, const String &s)
{
	out << s.rep->data;
	return out;
}

//创建新的共享内存原来共享内存中值一样，然后再修改
void String::to_upper()
{
	String *newStr = new String(this->rep->data);
	this->rep->decrement();
	this->rep = newStr->rep;
	this->rep->increment();

	char *str = this->rep->data;
	while (*str != '\0')
	{
		*str -= 32;
		++str;
	}
	delete newStr;
}

String& String::operator+=(const String &str)
{
	char *ch = new char[strlen(str.rep->data) + strlen(this->rep->data) + 1];
	strcpy(ch,this->rep->data);
	strcat(ch, str.rep->data);

	this->rep->decrement();
	String_rep *s = new String_rep(ch);
	this->rep = s;
	this->rep->increment();

	return *this;
}

int main()
{
	String s("abc");
	String s1;
	s1 = s; //
	String s2("xyz");
	String s3(s);
	s2.to_upper();
	
	s3 += s2;
	cout << s2 << endl;
	cout << s3 << endl;

	return 0;
}