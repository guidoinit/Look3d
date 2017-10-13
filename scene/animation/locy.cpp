
#include "locy.h"


locy::locy(int fstart, int fend ,float y)
	:baseframe(fstart,fend)
{


	_y=y;
}

locy::locy(void)
{
}


locy::~locy(void)
{
}

float locy::get()
{
	return _y ;
}
void locy::set(float val)
{
	_y=val;
}

/*void locy::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		baseframe::Serialize(ar);
		ar << _y;
	}
	else
	{
		baseframe::Serialize(ar);
		ar >> _y;
	}
}
*/
