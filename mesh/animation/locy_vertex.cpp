#include "locy_vertex.h"



locy_vertex::locy_vertex(int fstart, int fend ,float y)
        :baseframe_vertex(fstart,fend)
{


        _y=y;
}

locy_vertex::locy_vertex(void)
{
}


locy_vertex::~locy_vertex(void)
{
}

float locy_vertex::get()
{
        return _y;
}
void locy_vertex::set(float val)
{
        _y=val;
}
