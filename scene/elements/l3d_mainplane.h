#ifndef L3D_MAINPLANE_H
#define L3D_MAINPLANE_H
#include "l3d_include.h"
class l3d_mainplane
{
public:
    void init(l3d_float *);
    l3d_mainplane();
private:
    l3d::mesh::l3d_mesh_struct _plane;

};

#endif // L3D_MAINPLANE_H
