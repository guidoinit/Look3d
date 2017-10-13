
#include "locx.h"


locx::locx(int fstart, int fend ,float x)
	:baseframe(fstart,fend)
{


	_x=x;
}

locx::locx(void)
{
}


locx::~locx(void)
{
}

float locx::get()
{
	return _x;
}
void locx::set(float val)
{
	_x=val;
}
/*
void locx::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		baseframe::Serialize(ar);
		ar << _x;
	}
	else
	{
		baseframe::Serialize(ar);
		ar >> _x;
	}
}
*/
