#ifndef JOIN_H
#define JOIN_H
#include "mesh/l3d_vertex.h"
using namespace l3d::vertex3f;
class join
{
public:
    join();
    join(pl3d_vertex_fast);

    pl3d_vertex_fast  get();
    void set(pl3d_vertex_fast);

    void draw();

private:
    pl3d_vertex_fast _info;
};

#endif // JOIN_H
