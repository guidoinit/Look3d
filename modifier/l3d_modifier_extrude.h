#ifndef L3D_MODIFIER_EXTRUDE_H
#define L3D_MODIFIER_EXTRUDE_H

#include "mesh/l3d_mesh.h"
#include "mesh/l3d_vertex.h"
#include "l3d_include.h"

using namespace l3d;
using namespace l3d::mesh;
namespace l3d
{
using namespace vertex3f;
using namespace edge;
using namespace face3;
using namespace face4;
using namespace mesh;
namespace modifier
{
class l3d_modifier_extrude
{
public:
    l3d_modifier_extrude();

    void set_mesh(pl3d_mesh_struct);
    void extrudevertex();
    void extrudevertex(l3d_uint);
    void extrudeedge();
    void extrudequad();
private:
    pl3d_mesh_struct _mesh;
    std::list<int> _ladded,_qadded;
    std::list<int> _ledge_perimeter;
    void makeindex_edges();
    void makeindex_quads();
    std::list<int> find_edges(l3d_uint);
    l3d_bool isedgeall();
    l3d_bool isquadall();
    l3d_bool isedgealone(l3d_uint);
    l3d_bool isquadalone(l3d_uint);
    l3d_bool isedgealone_sin(l3d_uint);
    l3d_bool isedgealone_des(l3d_uint);
    l3d_bool isedge_perimeter(l3d_uint ix);
    void extrudeedge(int);
    void extrudequad(l3d_uint);
    void extrudeedge(std::list<int> _list);
    void extrudeedge_perimeter(std::list<int> _list);

};
}
}

#endif // L3D_MODIFIER_EXTRUDE_H
