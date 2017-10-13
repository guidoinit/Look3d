#include "l3d_modifier_subdivide.h"
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

l3d_modifier_subdivide::l3d_modifier_subdivide()
{
    _meshto=l3d_null;
    _meshto2=l3d_null;
}

l3d_modifier_subdivide::l3d_modifier_subdivide(pl3d_mesh_struct _mesh)
{
    _meshto=_mesh;
    if(_meshto2!=l3d_null)
        _meshto2->clear();
    _meshto2=l3d_null;
    copy();
}
l3d_modifier_subdivide::l3d_modifier_subdivide(l3d_mesh_struct _mesh)
{
    _meshto=&_mesh;
    if(_meshto2!=l3d_null)
        _meshto2->clear();
    _meshto2=l3d_null;
    copy();

}

void l3d_modifier_subdivide::set_mesh(pl3d_mesh_struct _mesh)
{
    _meshto=_mesh;
    if(_meshto2!=l3d_null)
        _meshto2->clear();
    _meshto2=l3d_null;
    copy();
}
void l3d_modifier_subdivide::set_mesh(l3d_mesh_struct _mesh)
{
    _meshto=&_mesh;
    if(_meshto2!=l3d_null)
        _meshto2->clear();
    _meshto2=l3d_null;
    copy();
}
l3d_modifier_subdivide::~l3d_modifier_subdivide()
{
    _meshto2->clear();

    delete(_meshto2);
}
void l3d_modifier_subdivide::subdivide_all()
{
    int l=_meshto2->_quad.size();

    for(int ix=0; ix < l; ix++)
        if(!_meshto2->_quad.find(ix)->_erase)
            _meshto2->_quad.find(ix)->_selected=true;

    subdivideface();

}
void l3d_modifier_subdivide::subdivide_all(pl3d_mesh_struct _mesh)
{
    set_mesh(_mesh);

    int l=_meshto->_quad.size();

    for(int ix=0; ix < l; ix++)
        _meshto->_quad.find(ix)->_selected=true;

    subdivideface();

}
void l3d_modifier_subdivide::subdivide()
{
    subdivideface();


}
void l3d_modifier_subdivide::subdivideface(int nface)
{

    int vi[4];
    int li[5];
    pl3d_face4_struct qstart=_meshto2->_quad.find(nface);
    //eliminare le linee non associate ad altri poligoni

    //while(vstart)
    vi[0]=qstart->_v0;
    vi[1]=qstart->_v1;
    vi[2]=qstart->_v2;
    vi[3]=qstart->_v3;

    for(int iv=0; iv<5;iv++)
    {

        li[iv]=qstart->l[iv];

        //elimino tutte le linee del poligono



    }




    //eliminare i poligoni a 3 vertici associati al poligono


    //vstart

    /*
    l3d_vertex_fast v;
    v=*qstart->_pv0;
    v+=*qstart->_pv1;

    v/=2.0F;

    _meshto2.addvertex(&v);



    v+=_meshto._vertex->find(vi[1]);

    v/=2.0F;
    _meshto._vertex->add(v);

    //vstart+1
    v=_meshto._vertex->find(vi[1]);
    v+=_meshto._vertex->find(vi[3]);

    v/=2.0F;
    _meshto._vertex->add(v);

    //vstart+2
    v=_meshto._vertex->find(vi[2]);
    v+=_meshto._vertex->find(vi[3]);

    v/=2.0F;
    _meshto._vertex->add(v);

    //vstart+3
    v=_meshto._vertex->find(vi[0]);
    v+=_meshto._vertex->find(vi[2]);

    v/=2.0F;
    _meshto._vertex->add(v);

    //vstart+4
    v=_meshto._vertex->find(vi[0]);
    v+=_meshto._vertex->find(vi[1]);
    v+=_meshto._vertex->find(vi[2]);
    v+=_meshto._vertex->find(vi[3]);

    v/=4.0F;

    _meshto._vertex->add(v);

    _meshto.adddquad(v1[0],vstart,vstart+3,vstart+4);
    _meshto.adddquad(vstart,vi[1],vstart+4,vstart+1);
    _meshto.adddquad(vstart+3,vstart+4,vi[2],vstart+2);
    _meshto.adddquad(vstart+4,vstart+1,vstart+2,vi[3]);

    //_meshto->rempoly4(nface);
*/

}

void l3d_modifier_subdivide::subdivideface()
{
    /*
    _meshto=&_meshto2;
    for(int ix=0; ix < _meshto->m_poly4.size(); ix++)
    {
        if(_meshto->_quad-> m_poly4[ix].selected() && !_meshto->m_poly4[ix].m_berase)
        {
            subdivideface(ix);
            ix=-1;

        }

    }
    //eliminare tutte le linee contrassegnate to-do
    _meshto->finddoublevertex();

    _meshto->purge();
*/
}

void l3d_modifier_subdivide::subdivide(pl3d_mesh_struct _mesh)
{
    set_mesh(_mesh);
    subdivide();

}

pl3d_mesh_struct  l3d_modifier_subdivide::get_pmesh()
{
    return (_meshto);
}
l3d_mesh_struct  l3d_modifier_subdivide::get_mesh()
{
    //return (_meshto2);
}
void l3d_modifier_subdivide::copy()
{
    _meshto2=new l3d_mesh_struct;
    pl3d_vertex_fast vfirst=_meshto->_vertex.find(0);
    while(vfirst)
    {
        _meshto2->addvertex(vfirst->x,vfirst->y,vfirst->z);
        vfirst=vfirst->next;
    }
    pl3d_line_struct l=_meshto->_edges.find(0);
    while(l)
    {
        _meshto2->addedge(l->v0,l->v1);
        l=l->next;
    }
    pl3d_face3_struct pf=_meshto->_faces.find(0);
    while(pf)
    {
        _meshto2->addface3(pf->v0,pf->v1,pf->v2,pf->_alone,abcCW);
        pf=pf->next;

    }
    pl3d_face4_struct pq=_meshto->_quad.find(0);
    while(pq)
    {
        _meshto2->addquad(pq->_v0,pq->_v1,pq->_v2,pq->_v3,abcdCW);
        pq=pq->next;
    }



}
