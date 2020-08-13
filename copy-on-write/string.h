#include <iostream>
#include <cstring>

using namespace std;

class String;
ostream& operator<<(ostream &out, const String &str);

class String_rep
{
    friend class String;
    friend ostream& operator<<(ostream &out, const String &str);

private:
    String_rep(const char *str = "") : _use_count(0)
    {
        if (NULL == str)
        {
            m_data = new char[1];
            m_data[0] = '\0';
        }
        else
        {
            m_data= new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }

    String_rep(const String_rep &rep)
    {
        this->m_data = rep.m_data;
    }

    String_rep& operator=(const String_rep &rep)
    {
        this->m_data = rep.m_data;
    }

    ~String_rep() 
    {
        if (NULL != m_data)
        {
            delete []m_data;
            m_data = NULL;
        }
    }

public:
    void increment()
    {
        ++_use_count;
    }
    void decrement()
    {
        --_use_count;
    }

private:
    char *m_data;
    int _use_count;
};

////////////////////////////////////////////////////////
class String
{
    friend ostream&  operator<<(ostream &out, const String &str);

public:
    String(const char *str = "") : rep(new String_rep(str))
    {
        rep->increment();
    }

    String(const String &str)
    {
        this->rep = str.rep;
        rep->increment();
    }

    String& operator=(const String &str)
    {
        if (&str != this) 
        {
            this->rep->decrement();
            this->rep = str.rep;
            this->rep->increment();
        }

        return *this;
    }

    ~String() 
    {
        rep->decrement();
    }

public:
    void to_upper();
    String& operator+=(const String &str);

private:
    String_rep *rep;
};

void String::to_upper() 
{
    String *newStr = new String(this->rep->m_data);
    this->rep->decrement();

    this->rep = newStr->rep;
    this->rep->increment();

    char *str = this->rep->m_data;
    while (*str != '\0')
    {
        *str -= 32;
        ++str;
    }
    delete newStr;
}

String& String::operator+=(const String &str)
{
    int len = strlen(str.rep->m_data) + strlen(this->rep->m_data) + 1;
    char *ch = new char[len];

    strcpy(ch, this->rep->m_data);
    strcat(ch, str.rep->m_data);

    this->rep->decrement();
    this->rep = new String_rep(ch);
    this->rep->increment();

    return *this;
}

ostream& operator<<(ostream &out, const String &str)
{
    out << str.rep->m_data;
    return out;
}


