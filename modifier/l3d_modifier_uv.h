#ifndef L3D_MODIFIER_UV_H
#define L3D_MODIFIER_UV_H
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

namespace l3d
{
    using namespace vertex3f;
    using namespace edge;
    using namespace face3;
    using namespace face4;
    using namespace mesh;
    namespace modifier
    {

    enum ALG_UV
    {
        normal=0,
        poligonalinx=1,
        poligonaliny=2,
        poligonalinz=3,
        poligonalinx_move=4

    };
        class l3d_modifier_uv
        {
        private:
            pl3d_mesh_struct _mesh;
            ALG_UV _alg;

        public:
            l3d_modifier_uv();
            l3d_modifier_uv(pl3d_mesh_struct _m,ALG_UV _a);

            void make();
            void make(pl3d_mesh_struct _m,ALG_UV _a);
            void poligonal();
            void poligonal_x();
            void poligonal_x_move();
            void poligonal_y();
            void poligonal_z();
        };
    }
}
#endif // L3D_MODIFIER_UV_H
