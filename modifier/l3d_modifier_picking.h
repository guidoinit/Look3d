#ifndef L3D_MODIFIER_PICKING_H
#define L3D_MODIFIER_PICKING_H
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
        class l3d_modifier_picking
        {
        public:
            l3d_modifier_picking();
            void draw_select(int,int,int,int);
        };
    }
}
#endif // L3D_MODIFIER_PICKING_H
