#ifndef L3D_MODIFIER_SUBDIVIDE_H
#define L3D_MODIFIER_SUBDIVIDE_H
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

        class l3d_modifier_subdivide
        {
    public:
        l3d_modifier_subdivide();
        l3d_modifier_subdivide(pl3d_mesh_struct);
        l3d_modifier_subdivide(l3d_mesh_struct);
        ~l3d_modifier_subdivide();

        void set_mesh(pl3d_mesh_struct _mesh);
        void set_mesh(l3d_mesh_struct _mesh);

        void subdivide();
        void subdivide(pl3d_mesh_struct  _mesh);

        void subdivide_all();
        void subdivide_all(pl3d_mesh_struct _mesh);
        pl3d_mesh_struct get_pmesh();
        l3d_mesh_struct  get_mesh();
    private:
        pl3d_mesh_struct _meshto;
        pl3d_mesh_struct _meshto2;
        void subdivideface();
        void subdivideface(int nface);
        void copy();

        };

    }
}
#endif // L3D_MODIFIER_SUBDIVIDE_H
