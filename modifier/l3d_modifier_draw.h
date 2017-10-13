#ifndef L3D_MODIFIER_DRAW_H
#define L3D_MODIFIER_DRAW_H

#include "mesh/l3d_mesh.h"
#include "mesh/l3d_vertex.h"

#include "scene/elements/l3d_light.h"
#include "l3d_include.h"

using namespace l3d;
using namespace l3d::mesh;
using namespace l3d::light;



namespace l3d
{

using namespace vertex3f;
using namespace edge;
using namespace face3;
using namespace face4;
using namespace mesh;


    namespace modifier
    {
        class l3d_modifier_draw
        {
        private:
            pl3d_mesh_struct _mesh;
            void draw_face3();
            void draw_face3_solid();
            void draw_wireframe();
            void draw_texture();
            void draw_quad(pl3d_face4_struct _q);

        public:
            l3d_modifier_draw();
            void draw(pl3d_mesh_struct _pmesh,SCENE::ModeDraw _mode);
            void draw_light(pl3d_light _plight );
            void draw_edit(pl3d_mesh_struct  mesh);
            void draw_select(pl3d_mesh_struct  mesh);
            void draw_face3(pl3d_mesh_struct _mesh);

            void draw_vertex(pl3d_vertex_fast _v);
            void draw_vertex_solid(pl3d_vertex_fast _v);
            void draw_vertex_texture(pl3d_vertex_fast _v,l3d_double u,l3d_double v);

        };

    }
}
#endif // L3D_MODIFIER_DRAW_H
