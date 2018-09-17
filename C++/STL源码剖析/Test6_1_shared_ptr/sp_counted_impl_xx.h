#ifndef _SP_COUNTED_IMPL_XX_H
#define _SP_COUNTED_IMPL_XX_H

#include"sp_counted_base.h"

template<class X> 
class sp_counted_impl_xx : public sp_counted_base
{
public:
	sp_counted_impl_xx( X * px ): px_( px )
	{
#ifdef DISPLAY
		cout<<"Create sp_counted_impl_xx Object."<<endl;
#endif
	}
	~sp_counted_impl_xx()
	{
#ifdef DISPLAY
		cout<<"Free sp_counted_impl_xx Object."<<endl;
#endif
		delete px_;
	}
public:
	virtual void dispose()
	{
#ifdef DISPLAY
		cout<<"This is sp_counted_impl_xx:dispose()"<<endl;
#endif
		delete this;
	}
private:
	X * px_;
};

#endif