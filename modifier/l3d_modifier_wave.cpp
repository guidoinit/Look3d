#include "l3d_modifier_wave.h"
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



l3d_modifier_wave::l3d_modifier_wave()
{
    _mesh=l3d_null;
}

void l3d_modifier_wave::set_mesh(pl3d_mesh_struct _m)
{
    if(_m)
        _mesh=_m;
}
void l3d_modifier_wave::use()
{
    make_wave();
}

void l3d_modifier_wave::make_wave()
{


    std::list<int> vx,vx2;
    std::list<int>::iterator it,it2;

    //prelevo prima i vertici con x>0.0

    pl3d_vertex_fast start=_mesh->_vertex.first();
    l3d_uint ix=0;
    while(start)
    {
        if(start->x > 0.0F)
            vx.push_back(ix);

        ix++;
        start=start->next;
    }

    //prelevo vertici con x<0.0 allo stesso modo
    start=_mesh->_vertex.first();
    while(start)
    {
        if(start->x < 0.0F)
            vx2.push_back(ix);

        ix++;
        start=start->next;
    }

    //eseguo il link dei vertici con x < 0.0 e coordinate y e z uguali
    for(it=vx.begin(); it!=vx.end(); ++it)
    {
        pl3d_vertex_fast appv=_mesh->_vertex.find((*it));

        for(it2=vx2.begin(); it2!=vx2.end(); ++it2)
        {
            pl3d_vertex_fast appv2=_mesh->_vertex.find((*it2));

            if(appv!=appv2 && appv->y == appv2->y && appv->z==appv2->z)
            {
                //collego i due vertici
                appv->setwave((*it2));
                appv2->setwave(l3d_link);

            }


        }


    }



}
