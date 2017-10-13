#include "join.h"

join::join()
{
    _info=NULL;
}
join::join(l3d_vertex_fast *_j)
{
    _info=_j;
}
l3d_vertex_fast * join::get()
{
    return(_info);
}

void join::set(l3d_vertex_fast *_j)
{
    _info=_j;
}

void join::draw()
{
    //to-do
}
