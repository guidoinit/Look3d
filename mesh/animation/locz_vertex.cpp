#include "locz_vertex.h"

locz_vertex::locz_vertex(int fstart, int fend ,float z)
        :baseframe_vertex(fstart,fend)
{


        _z=z;
}

locz_vertex::locz_vertex(void)
{
}


locz_vertex::~locz_vertex(void)
{
}

float locz_vertex::get()
{
        return _z;
}
void locz_vertex::set(float val)
{
        _z=val;
}

