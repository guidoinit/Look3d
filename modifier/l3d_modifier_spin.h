#ifndef L3D_MODIFIER_SWAP_H
#define L3D_MODIFIER_SWAP_H
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
    class l3d_modifier_spin
    {
    public:
        l3d_modifier_spin();


        void set_mesh(pl3d_mesh_struct);
        void spinvertex_steps(l3d_uint _steps,l3d_vertex_fast _degree);
        void spinvertex();
        void spinvertex(l3d_vertex_fast _degree);

        void spinedges_steps(l3d_uint _steps,l3d_vertex_fast _degree);
        void spinedges();
        void spinedges(l3d_vertex_fast _degree);




    private:
        void matmult(GLfloat M[16], GLfloat v[4])
        {

            GLfloat res[4];                                                       // Hold


            res[0]=M[ 0]*v[0]+M[ 4]*v[1]+M[ 8]*v[2]+M[12]*v[3];

            res[1]=M[ 1]*v[0]+M[ 5]*v[1]+M[ 9]*v[2]+M[13]*v[3];

            res[2]=M[ 2]*v[0]+M[ 6]*v[1]+M[10]*v[2]+M[14]*v[3];

            res[3]=M[ 3]*v[0]+M[ 7]*v[1]+M[11]*v[2]+M[15]*v[3];


            v[0]=res[0];                                                          // Results


            v[1]=res[1];

            v[2]=res[2];

            v[3]=res[3];

        }
        void extrudevertex();
        void extrudevertex(l3d_uint);
        void extrudeedge();
        void extrudequad();

        pl3d_mesh_struct _mesh;
        l3d_vertex_fast _center,_rotate;
        std::list<int> _ladded,_qadded;
        std::list<int> _ledge_perimeter;
        std::list<int> _vadded;
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

#endif // L3D_MODIFIER_SWAP_H
