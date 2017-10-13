#include "baseframe_vertex.h"

baseframe_vertex::baseframe_vertex()
{
}


baseframe_vertex::baseframe_vertex(int fstart,int fend)
{
        _fstart=fstart;
        _fend=fend;
}


baseframe_vertex::~baseframe_vertex(void)
{
}

int baseframe_vertex::getstart()
{
        return _fstart;
}

int baseframe_vertex::getend()
{
        return _fend;
}

void baseframe_vertex::setstart(int val)
{
        _fstart=val;
}

void baseframe_vertex::setend(int val)
{
        _fend=val;
}
