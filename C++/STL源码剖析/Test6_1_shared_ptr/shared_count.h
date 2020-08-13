#ifndef _SHARED_COUNT_H
#define _SHARED_COUNT_H

#include"sp_counted_base.h"
#include"sp_counted_impl_xx.h"
#include"sp_counted_impl_yy.h"

class shared_count
{
public:
	shared_count():pi_(0)
	{
#ifdef DISPLAY
		cout<<"Create shared_count Object."<<endl;
#endif
	}
	shared_count(const shared_count &r):pi_(r.pi_)
	{
		if(pi_ != 0)
			pi_->add_ref_copy();
	}
	//template<class Y>
	//shared_count(Y *p):pi_(new sp_counted_impl_xx<Y>(p))
	template<class Y>
		shared_count(Y *p) : pi_(0)
	{
#ifdef DISPLAY
		cout<<"Create shared_count Object."<<endl;
#endif
		
#ifdef SP_COUNTED_IMPL_XX
		pi_ = new sp_counted_impl_xx<Y>(p);
#else
		pi_ = new sp_counted_impl_yy<Y>(p);
#endif
	}
	~shared_count()
	{
#ifdef DISPLAY
		cout<<"Free shared_count Object."<<endl;
#endif

		if(pi_ != 0)
			pi_->release(); 
	}
public:
	long use_count()const
	{
		if(pi_ != 0)
			return pi_->use_count();
		else
			return 0;
	}
	void swap(shared_count & r) 
    {
        sp_counted_base * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }
private:
	sp_counted_base *pi_;
};
  
#endif