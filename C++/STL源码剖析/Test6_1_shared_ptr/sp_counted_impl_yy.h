#ifndef _SP_COUNTED_IMPL_YY_H
#define _SP_COUNTED_IMPL_YY_H

#include"sp_counted_base.h"

template<class X> 
class sp_counted_impl_yy : public sp_counted_base
{
public:
	sp_counted_impl_yy( X * px ): px_( px )
	{
#ifdef DISPLAY
		cout<<"Create sp_counted_impl_yy Object."<<endl;
#endif
	}
	~sp_counted_impl_yy()
	{
#ifdef DISPLAY
		cout<<"Free sp_counted_impl_yy Object."<<endl;
#endif
		delete px_;
	}
public:
	virtual void dispose()
	{
#ifdef DISPLAY
		cout<<"This is sp_counted_impl_yy:dispose()"<<endl;
#endif
		delete this;
	}
private:
	X * px_;
};

#endif