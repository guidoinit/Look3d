#ifndef INSERT_H
#define INSERT_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "mesh/l3d_mesh.h"
#include "mesh/l3d_material.h"

#include "mesh/object3d.h"

using namespace l3d;
using namespace l3d::mesh;
using namespace l3d::material;
class insert
{
private:
        vertex world_pos;
        l3d_mesh _mesh;
        std::vector<object3d> m_object;
        float m_angolo;
        float m_distance;
        bool m_bselect;
        bool m_oselected;
        telecamera m_tel;
        int m_oldsel;
        int m_select;
        l3d_material_struct m_mat;
public:
        insert();
        void addobject(object3d);
        virtual ~insert();
        void next();
        void prev();
        void Select();
        void Create();
        void Draw();
        bool Selected();
        object3d GetObjectSelected();
        bool iswireframe;
};
#endif // INSERT_H
