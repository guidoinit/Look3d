#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <vector>



#include "modifiersubdivide.h"


using namespace std;
modifiersubdivide::modifiersubdivide()
{
    _meshto=NULL;
}

modifiersubdivide::modifiersubdivide(object3d *_mesh)
{
    _meshto=_mesh;
}
modifiersubdivide::modifiersubdivide(object3d _mesh)
{
    _meshto=&_mesh;
    _meshto2=_mesh;
}

void modifiersubdivide::set_mesh(object3d *_mesh)
{
    if(_meshto!=NULL)
        delete (_meshto);

    _meshto=_mesh;
}
void modifiersubdivide::set_mesh(object3d _mesh)
{
    if(_meshto!=NULL)
        delete (_meshto);

    _meshto=(object3d*)&_mesh;
    _meshto2=_mesh;
}
modifiersubdivide::~modifiersubdivide()
{
    delete(_meshto);
}
void modifiersubdivide::subdivide_all()
{
    int l=_meshto2.m_poly4.size();

    for(int ix=0; ix < l; ix++)
        if(!_meshto2.m_poly4[ix].m_berase)
            _meshto2.m_poly4[ix].selected(true);

    subdivideface();

}
void modifiersubdivide::subdivide_all(object3d *_mesh)
{
    set_mesh(_mesh);

    int l=_meshto->m_poly4.size();

    for(int ix=0; ix < l; ix++)
        _meshto->m_poly4[ix].selected(true);

    subdivideface();

}
void modifiersubdivide::subdivide()
{
    subdivideface();


}
void modifiersubdivide::subdivideface(int nface)
{
    vertex v;
    int vi[4];
    int li[4];
    int vstart=_meshto->local_vertex.size();
    //eliminare le linee non associate ad altri poligoni

    for(int iv=0; iv<4;iv++)
    {
        vi[iv]=_meshto->m_poly4[nface].Get(iv);
        li[iv]=_meshto->m_poly4[nface].getline(iv);

        //elimino tutte le linee del poligono



    }




    //eliminare i poligoni a 3 vertici associati al poligono


    //vstart
    v=_meshto->local_vertex[vi[0]];
    v+=_meshto->local_vertex[vi[1]];

    v/=2.0F;
    _meshto->local_vertex.push_back(v);

    //vstart+1
    v=_meshto->local_vertex[vi[1]];
    v+=_meshto->local_vertex[vi[3]];

    v/=2.0F;
    _meshto->local_vertex.push_back(v);

    //vstart+2
    v=_meshto->local_vertex[vi[2]];
    v+=_meshto->local_vertex[vi[3]];

    v/=2.0F;
    _meshto->local_vertex.push_back(v);

    //vstart+3
    v=_meshto->local_vertex[vi[0]];
    v+=_meshto->local_vertex[vi[2]];

    v/=2.0F;
    _meshto->local_vertex.push_back(v);

    //vstart+4
    v=_meshto->local_vertex[vi[0]];
    v+=_meshto->local_vertex[vi[1]];
    v+=_meshto->local_vertex[vi[2]];
    v+=_meshto->local_vertex[vi[3]];

    v/=4.0F;

    _meshto->local_vertex.push_back(v);

    _meshto->AddPoligon(vi[0],vstart,vstart+3,vstart+4);
    _meshto->AddPoligon(vstart,vi[1],vstart+4,vstart+1);
    _meshto->AddPoligon(vstart+3,vstart+4,vi[2],vstart+2);
    _meshto->AddPoligon(vstart+4,vstart+1,vstart+2,vi[3]);

    _meshto->rempoly4(nface);


}

void modifiersubdivide::subdivideface()
{
    _meshto=&_meshto2;
    for(int ix=0; ix < _meshto->m_poly4.size(); ix++)
    {
        if(_meshto->m_poly4[ix].selected() && !_meshto->m_poly4[ix].m_berase)
        {
            subdivideface(ix);
            ix=-1;

        }

    }
    //eliminare tutte le linee contrassegnate to-do
    _meshto->finddoublevertex();

    _meshto->purge();

}

void modifiersubdivide::subdivide(object3d *_mesh)
{
    set_mesh(_mesh);
    subdivide();

}

object3d * modifiersubdivide::get_pmesh()
{
    return (_meshto);
}
object3d  modifiersubdivide::get_mesh()
{
    return (_meshto2);
}
