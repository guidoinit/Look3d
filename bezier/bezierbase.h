#ifndef BEZIERBASE_H
#define BEZIERBASE_H
#include <vector>
#include "mesh/l3d_vertex.h"
using namespace std;
using namespace l3d::vertex3f;
class bezierbase
{

public:
    bezierbase();
    ~bezierbase()
    {
        _cpoint.clear();
    }

    bezierbase(l3d_vertex _l);
    bezierbase(const bezierbase& b)
    {
        _cpoint=b._cpoint;
    }
    bezierbase& operator=(const bezierbase& b)
    {
        _cpoint=b._cpoint;

        return (*this);
    }

    void add(l3d_vertex_fast);
    void rem(int);
    void set(l3d_vertex_fast,int);
    int size();
protected:
    l3d_vertex _cpoint;
};

#endif // BEZIERBASE_H
