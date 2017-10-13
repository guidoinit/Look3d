#include "locx_vertex.h"


locx_vertex::locx_vertex(int fstart, int fend ,float x)
        :baseframe_vertex(fstart,fend)
{


        _x=x;
}

locx_vertex::locx_vertex(void)
{
}


locx_vertex::~locx_vertex(void)
{
}

float locx_vertex::get()
{
        return _x;
}
void locx_vertex::set(float val)
{
        _x=val;
}
