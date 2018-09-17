#include <iostream>
#include <cstring>

using namespace std;

#if 0
//练习
class Int
{
public:
	Int(int i = 0) : m_i(i)	{ cout << "constructor called ! " << endl; }
	Int(const Int &tmp) { cout << "copy constructor called !" << endl; }
	~Int()	{}

public:
	Int operator+(const Int &tmp);
	Int operator-(const Int &tmp);
	Int operator*(const Int &tmp);
	Int operator/(const Int &tmp);

	Int& operator+=(const Int &tmp);
	Int& operator-=(const Int &tmp);
	Int& operator*=(const Int &tmp);
	Int& operator/=(const Int &tmp);

	//前++和后++用一个参数来区别
	Int& operator++();	  //++x
	Int operator++(int);	  //x++

	int show() { return m_i; }

private:
	int m_i;
};	 

Int Int::operator+(const Int &tmp)
{ 
	return Int(m_i + tmp.m_i);
}

Int Int::operator-(const Int &tmp)
{
	return Int(m_i - tmp.m_i);
}

Int Int::operator*(const Int &tmp)
{
	return Int(m_i * tmp.m_i);
}

Int Int::operator/(const Int &tmp)
{
	assert(tmp.m_i != 0);
	return 	Int(m_i / tmp.m_i);
}

Int& Int::operator+=(const Int &tmp)
{
	m_i += tmp.m_i;
	return *this;
}

Int& Int::operator-=(const Int &tmp)
{
	m_i -= tmp.m_i;
	return *this;
}
Int& Int::operator*=(const Int &tmp)
{
	m_i *= tmp.m_i;
	return *this;
}
Int& Int::operator/=(const Int &tmp)
{
	assert(tmp.m_i != 0);
	m_i /= tmp.m_i;
	return *this;
}

Int& Int::operator++()
{
	++m_i;
	return *this;
}

Int Int::operator++(int)
{
	Int tmp = *this;
	m_i++;

	return tmp;
}

int main()
{
	Int a(10);
	Int b(20);

	Int c;
	c = a - b;
	cout << c.show() << endl;

	return 0;
}
#endif

#if 0
//友元的简单实用
class Complex;
void show(Complex c);//友元函数的声明必须在类声明之后

class Complex
{
	friend Complex operator+(int x, const Complex &c2);
public:
	Complex(int real=0, int imag=0):m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	Complex operator+(const Complex &c);
	Complex operator+(int x);
private:
	int m_real;
	int m_imag;
};
Complex Complex::operator+(const Complex &c)
{
	return Complex(this->m_real+c.m_real, this->m_imag+c.m_imag);
}
Complex Complex::operator+(int x)
{
	return Complex(m_real+x,m_imag+x);
}

Complex operator+(int x, const Complex &c2)
{
	return Complex(x+c2.m_real,x+c2.m_imag);
}
int main()
{
	Complex c1(1,2), c2(2,3);
	Complex c = c1 + c2; //c1.operator+(c2);
	Complex d = c1 + 10; //
	Complex e = 10 + c1;

	return 0;
}

/*
int main()
{
	Complex  c(10);//这个10会传至构造函数的第一个参数
	show(c);
	return 0;
}
*/
#endif

#if 1
//重写String类，主要是重载+=、+、[]这三种运算符
class String;
ostream& operator<<(ostream &out, const String &s);

class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(const char *str = "")
	{
		if (str == NULL)
		{
			data = new char;
			data[0] = '\0';
		}
		else
		{
			data = new char[strlen(str) + 1];
			strcpy(data, str);
			data[strlen(str)] = '\0';
		}
	}

	String(const String &s)
	{
		data = new char[strlen(s.data) + 1];
		strcpy(data, s.data);
	}

	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(data);
			data = new char[strlen(s.data) + 1];
			strcpy(data, s.data);
		}
		return *this;
	}
	~String()
	{
		delete []data;
		data = NULL;
	}
public:
	String operator+(const String &s) //s = s1+s2
	{
		if (s.data == NULL)
			return String(s.data);
		
		char *str = new char[strlen(data) + strlen(s.data) + 1];
		memset(str, 0, strlen(data)+strlen(s.data)+1);
		strncpy(str, data, strlen(data));
		strncat(str, s.data, strlen(s.data));

		String tmp(str);
		delete []str;
		
		str = NULL;

		return tmp;
	}

	String& operator+=(const String &s)//s1 += s2;
	{
		char *newStr = NULL;
		if (s.data != NULL)
		{
			newStr = new char[strlen(s.data) + strlen(data) + 1];
			memset(newStr, 0, strlen(s.data) + strlen(data) + 1);
			strncpy(newStr, data, strlen(data));
			strncat(newStr, s.data, strlen(s.data));
			
			delete []data;
			this->data = newStr;
		}

		return *this;
	}

	char operator[](int index)         //s1[i];
	{
		char str = '\0';
		if (data != NULL && index >= 0 && index < strlen(data))
			str = data[index];

		return str;
	}
public:
	char *data;
};

ostream& operator<<(ostream &out, const String &s)
{
	out << s.data;
	return out;
}

int main()
{
	String s("abcxyz");
	String s1("hello");
	String s3 = s + s1;
	s3 += s;

	cout << s3.data << endl;
	cout << s3[3] << endl;

	system("pause");
	return 0;
}
#endif