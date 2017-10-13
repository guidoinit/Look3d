#define GLEW_STATIC
#include <GL/glew.h>

#include "l3d_modifier_draw.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_material.h"
#include "mesh/l3d_mesh.h"

using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;

#include "l3d_modifier_picking.h"

l3d_modifier_picking::l3d_modifier_picking()
{
}
void l3d_modifier_picking::draw_select(int _sx, int _sy, int _rx, int _ry)
{


}
