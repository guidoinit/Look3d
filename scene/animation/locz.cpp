
#include "locz.h"


locz::locz(int fstart, int fend ,float z)
	:baseframe(fstart,fend)
{


	_z=z;
}


locz::locz(void)
{
}


locz::~locz(void)
{
}

float locz::get()
{
	return _z ;
}
void locz::set(float val)
{
	_z=val;
}
/*void locz::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		baseframe::Serialize(ar);
		ar << _z;
	}
	else
	{
		baseframe::Serialize(ar);
		ar >> _z;
	}
}
*/
