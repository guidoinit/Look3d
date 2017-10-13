#ifndef L3D_UV_H
#define L3D_UV_H
#include "l3d_include.h"
#include "l3d_id_picking.h"
#include "l3d_vertex.h"
#include "l3d_line.h"
#include "l3d_face3.h"
#include "l3d_face4.h"
#include "l3d_transform.h"
#include "l3d_material.h"
#include "l3d_vertex_group.h"
#include "l3d_blend.h"
#include "vbo/l3d_bufferobject.h"
#include "vbo/l3d_vertexbufferobject.h"
#include "group.h"
#include "scene/sceneenum.h"

namespace l3d
{
    using namespace vertex3f;
    using namespace edge;
    using namespace face3;
    using namespace face4;
    using namespace material;
    using namespace vertex_group;

    enum UVTYPE
    {
        uvvertex=0,
        uvtriangle=1,
        uvquad=2,

        last=100
    };

    typedef struct _l3d_uv_struct
    {
        l3d_double u,v;

        l3d_uint _index_vertex;

        l3d_uint _index_quad;

        l3d_uint _index_triangle;

        UVTYPE _type;


        struct _l3d_uv_struct * _next;

    }l3d_uv_struct,*pl3d_uv_struct;

    class l3d_uv
    {
    private:
        l3d_uint _size;
        pl3d_uv_struct _first;
    public:
        void add(pl3d_uv_struct);

        void add(UVTYPE _type,l3d_uint _index,l3d_uint _index2);

        void clear();

        pl3d_uv_struct get(UVTYPE _type,l3d_uint _index,l3d_uint _index2);

        pl3d_uv_struct get(l3d_uint _index);

        pl3d_uv_struct first();

        l3d_bool empty();

        l3d_uint size();

        l3d_uv();
    };
}
#endif // L3D_UV_H
