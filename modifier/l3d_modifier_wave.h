#ifndef L3D_MODIFIER_WAVE_H
#define L3D_MODIFIER_WAVE_H
#include "l3d_modifier_extrude.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"


using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;

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
class l3d_modifier_wave
{
public:
    l3d_modifier_wave();
    void set_mesh(pl3d_mesh_struct);
    void use();
private:
    pl3d_mesh_struct _mesh;
    void make_wave();
};
}
}

#endif // L3D_MODIFIER_WAVE_H
