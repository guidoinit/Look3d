#ifndef SCALEEDIT_H
#define SCALEEDIT_H


#define MOVES 20000
#define LENGTH 20

#include <stdlib.h>
#include <math.h>

#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;




namespace l3d
{
    namespace tool
    {
        class scaleedit
        {
        public:
            scaleedit();
            ~scaleedit(void);
            void Draw(bool);
            void DrawSelect();
        private:
            l3d_mesh_struct _cube;
            l3d_vertex_fast _v[6],_wp,_wp2,_angolo;

        public:
            // raggio per disegnare il puntatore in grandezza rispetto all'osservatore
            float m_radius;
            void setpos(l3d_vertex_fast _p);
        };

    }
}

#endif // SCALEEDIT_H
