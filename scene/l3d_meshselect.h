#ifndef L3D_MESHSELECT_H
#define L3D_MESHSELECT_H


#include "mesh/l3d_mesh.h"

using namespace l3d::mesh;
namespace l3d
{


class l3d_meshselect
{
public:
    l3d_meshselect();

    l3d_meshselect(pl3d_mesh_struct value);
    void set(pl3d_mesh_struct value);

    void setname(int value);
    //funzioni select

    void selectvertex();
    void selectvertex(pl3d_mesh_struct value);

    void selectedge();
    void selectedge(pl3d_mesh_struct value);

    void selectface();
    void selectface(pl3d_mesh_struct value);

    void selectobject();
    void selectobject(pl3d_mesh_struct value);

private:
    pl3d_mesh_struct  m_pobject;
    int m_istartname;
};
}
#endif // L3D_MESHSELECT_H
