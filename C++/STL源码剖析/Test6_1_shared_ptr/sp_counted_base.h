#ifndef _SP_COUNTED_BASE_H
#define _SP_COUNTED_BASE_H

#include<iostream>
using namespace std;

#include"config.h"

class sp_counted_base
{
public:
	sp_counted_base() : use_count_(1)
    {
#ifdef DISPLAY
		cout<<"Create sp_counted_base Object."<<endl;
#endif
	}
	virtual ~sp_counted_base()
	{
#ifdef DISPLAY
		cout<<"Free sp_counted_base Object."<<endl;
#endif
	}
public:
	long use_count()const
	{return use_count_;}
	virtual void dispose() = 0;
	void release()
	{
		if(--use_count_ == 0)
		{
			this->dispose();
		}

	}
public:
	void add_ref_copy()
	{
		++use_count_;
	}
private:
	long use_count_;
};

#endif