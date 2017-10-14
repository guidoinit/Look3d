
#include <vector>

#include "mesh/l3d_vertex.h"
#include "bezierbase.h"

using namespace std;
using namespace l3d::vertex3f;
bezierbase::bezierbase()
{
}


bezierbase::bezierbase(l3d_vertex _l)
{
    _cpoint=_l;
}

void bezierbase::add(l3d_vertex_fast v)
{
    _cpoint.add(&v);
}

void bezierbase::rem(int i)
{

    if(i>=0 && i < _cpoint.size())
    {
        l3d_uint iv=i;

        _cpoint.del(iv);

    }
}

void bezierbase::set(l3d_vertex_fast v,int i)
{
    if(i>=0 && i < _cpoint.size())
    {
        pl3d_vertex_fast appv=_cpoint.get(i);
        *appv=v;
    }
}

int bezierbase::size()
{
    return (_cpoint.size());
}
