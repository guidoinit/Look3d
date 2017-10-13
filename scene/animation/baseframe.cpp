#include "baseframe.h"


baseframe::baseframe(void)
{

}

baseframe::baseframe(int fstart,int fend)
{
	_fstart=fstart;
	_fend=fend;
}


baseframe::~baseframe(void)
{
}

int baseframe::getstart()
{
	return _fstart;
}

int baseframe::getend()
{
	return _fend;
}

void baseframe::setstart(int val)
{
	_fstart=val;
}

void baseframe::setend(int val)
{
	_fend=val;
}
/*
void baseframe::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar << _fstart;
		ar << _fend;
	}
	else
	{
		ar >> _fstart;
		ar >> _fend;

	}
}
*/
