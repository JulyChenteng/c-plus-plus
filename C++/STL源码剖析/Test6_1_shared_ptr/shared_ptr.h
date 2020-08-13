#ifndef _SHARED_PTR_H
#define _SHREAD_PTR_H

#include"shared_count.h"

template<class T> 
class shared_ptr
{
	typedef shared_ptr<T> this_type;
public:
	shared_ptr():px(0),pn()
	{}
	shared_ptr(T *p):px(p), pn(p)
	{
#ifdef DISPLAY
		cout<<"Create shared_ptr Object."<<endl;
#endif
	}
	shared_ptr(const shared_ptr<T> &r) : px(r.px),pn(r.pn)
	{}
	shared_ptr<T>& operator=(const shared_ptr<T> &r)
	{
		this_type(r).swap(*this);
        return *this;
	}
	~shared_ptr()
	{
#ifdef DISPLAY
		cout<<"Free shared_ptr Object."<<endl;
#endif
	}
public:
	long use_count()const
	{
		return pn.use_count();
	}
	void swap(shared_ptr<T> & other)
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }
private:
	T *px;             
    shared_count pn;
};

#endif