
#include <math.h>
#include <vector>



#include "mesh/vbo/objectvbo.h"
#include "scene/animation/frame.h"
#include "scene/animation/animate.h"

#include "mesh/vbo/sphereuvvbo.h"
#include "scene/elements/l3d_light.h"


#include "scene/elements/moveedit.h"





#include "scene/l3d_meshselect.h"

#include "scene/animation/baseframe.h"
#include "scene/animation/locx.h"
#include "scene/animation/locy.h"
#include "scene/animation/locz.h"







#include "mesh/group.h"

#include "qt/insertobject.h"

#include "mainscenedocument.h"

#include "modifier/l3d_modifier_subdivide.h"
#include "modifier/l3d_modifier_draw.h"
#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;

extern insertObject * Main_insert;


#include "l3d_mainscenedocument.h"

l3d_mainscenedocument::l3d_mainscenedocument()
{
}
void l3d_mainscenedocument::unselectobject()
{

}
animationmanager *l3d_mainscenedocument::getmanageranimation()
{
    return &m_animate;
}
void l3d_mainscenedocument::settype(SCENE::SceneType st)
{
    m_type=st;
}
int l3d_mainscenedocument::getsizecamera()
{
    return m_telecamera.size();
}
int l3d_mainscenedocument::getcameraselected()
{
    return 0;//to-do
}
l3d_vertex_fast l3d_mainscenedocument::gettoolpos()
{
    l3d_vertex_fast v;
    return v; //to-do
}
void l3d_mainscenedocument::selecteditpoligon(int np,bool b1,bool b2)
{
 //to-do
}
void l3d_mainscenedocument::selecteditpoligonpaint(int np,bool b1,bool b2)
{
    //to-do
}
void l3d_mainscenedocument::selecteditline(int nl, bool shift, bool ctrl)
{
    //to-do
}
void l3d_mainscenedocument::selecteditvertex(int nv, bool shift, bool ctrl)
{
    //to-do
}
int l3d_mainscenedocument::getSizeObjects()
{
    return (mesh.size());
}
pl3d_mesh_struct l3d_mainscenedocument::getObject(int no)
{
    pl3d_mesh_struct mf=mesh.find(no);
    return mf;
}
void l3d_mainscenedocument::selectobject(int no)
{
    mesh.find(no)->selected();
}
void l3d_mainscenedocument::draweditpoligon()
{
    pl3d_mesh_struct md;
    for(int ix=0; ix < mesh.size(); ix++)
    {
        pl3d_mesh_struct mf=mesh.find(ix);
        if(mf->selected())
        {
            md=mf;
        }
    }
    modifier::l3d_modifier_draw _draw;
    _draw.draw_edit(md);
}
void l3d_mainscenedocument::draweditline()
{

}
void l3d_mainscenedocument::draweditvertex()
{

}
void l3d_mainscenedocument::drawedit()
{
    pl3d_mesh_struct md;
    for(int ix=0; ix < mesh.size(); ix++)
    {
        pl3d_mesh_struct mf=mesh.find(ix);
        if(mf->selected())
        {
            md=mf;
        }
    }
    modifier::l3d_modifier_draw _draw;
    _draw.draw_edit(md);

}
void l3d_mainscenedocument::draw()
{
    modifier::l3d_modifier_draw _draw;
    pl3d_mesh_struct md;
    for(int ix=0; ix < mesh.size(); ix++)
    {
        pl3d_mesh_struct mf=mesh.find(ix);
        _draw.draw(mf,SCENE::color);

    }



}
void l3d_mainscenedocument::drawtexture()
{
    modifier::l3d_modifier_draw _draw;

    for(int ix=0; ix < mesh.size(); ix++)
    {
        pl3d_mesh_struct mf=mesh.find(ix);
        _draw.draw(mf,SCENE::mtexture);

    }



}
void l3d_mainscenedocument::addmaterial(l3d_material_struct _mat)
{
    int ix=0;
    pl3d_mesh_struct mf=NULL;
    while(!mf)
    {
        if(mesh.find(ix)->selected())
        {
            mf=mesh.find(ix);
        }
    }
    mf->_material.add(&_mat);
}
void l3d_mainscenedocument::addmesh(l3d_mesh_type _mt, l3d_float *par)
{
    mesh.create(_mt,par);
}
void l3d_mainscenedocument::addlight(LigthType _lt)
{

}
void l3d_mainscenedocument::deleteobjects()
{

}
void l3d_mainscenedocument::setedit(SCENE::ModeEdit value)
{
    m_edit=value;
}
void l3d_mainscenedocument::setmodedraw(SCENE::ModeDraw md)
{
    m_modedraw=md;
}
void l3d_mainscenedocument::setmodedocument(SCENE::ModeDocument md)
{
    m_modedoc=md;
}
pl3d_light l3d_mainscenedocument::getlight(int nl)
{
    pl3d_light pl;
    return pl; //to-do
}
l3d_material * l3d_mainscenedocument::getmaterials()
{
    return (&m_materials);
}
void l3d_mainscenedocument::addGroup(l3d_vertex_fast appv)
{
    //to-do
}
void l3d_mainscenedocument::unGroup()
{
    //to-do
}
void l3d_mainscenedocument::setSmoothGroup(int index)
{
    //to-do
}
void l3d_mainscenedocument::MoveObjectsVertex(l3d_vertex_fast appv)
{
    //to-do
}
void l3d_mainscenedocument::scale(float _scale[])
{
    //todo
}
void l3d_mainscenedocument::scalevertex(float _scale[])
{
    //to-do
}

void l3d_mainscenedocument::invertselect()
{
    //to-do
}
void l3d_mainscenedocument::applyscale()
{
    //to-do
}
void l3d_mainscenedocument::applyscaleedit()
{
    //to-do
}
void l3d_mainscenedocument::applyrotate()
{
    //to-do
}
void l3d_mainscenedocument::rotate(float _rotate[])
{
    //to-do
}
void l3d_mainscenedocument::move(l3d_vertex_fast v)
{
    //to-do
}
void l3d_mainscenedocument::SelectAllObjectsVertex()
{
    //to-do
}
void l3d_mainscenedocument::UnselectAllObjectsVertex()
{
    //to-do
}
void l3d_mainscenedocument::UnselectAllObjectVertex(int index)
{
    //to-do
}

void l3d_mainscenedocument::SelectAllObjectsLines()
{
    //to-do
}
void l3d_mainscenedocument::SelectAllObjectLines(int index)
{

}
void l3d_mainscenedocument::UnselectAllObjectsLines()
{
    //to-do
}
void l3d_mainscenedocument::UnselectAllObjectLines(int index)
{
    //to-do
}
void l3d_mainscenedocument::mergeObjectsSelected()
{
    //to-do
}
void l3d_mainscenedocument::duplicatevertex()
{

}
void l3d_mainscenedocument::duplicateedge()
{

}
void l3d_mainscenedocument::duplicateface()
{

}
void l3d_mainscenedocument::duplicate()
{

}
void l3d_mainscenedocument::deleteeditvertex()
{

}
void l3d_mainscenedocument::deleteeditedge()
{

}
void l3d_mainscenedocument::deleteeditface()
{

}
int l3d_mainscenedocument::getiGroupSelected()
{
    return 0;
}
int l3d_mainscenedocument::getiLightSelected()
{
    return 0;
}
void l3d_mainscenedocument::addnull()
{

}
void l3d_mainscenedocument::addTorus()
{

}
void l3d_mainscenedocument::extrude()
{

}
void l3d_mainscenedocument::extrudevertex()
{

}
int l3d_mainscenedocument::getObjectSelected()
{
    return(mesh.getiselected());
}
void l3d_mainscenedocument::extrudeedge()
{

}
void l3d_mainscenedocument::extrudeedgeind()
{

}
void l3d_mainscenedocument::addvertexgroup(string _namegroup)
{

}
void l3d_mainscenedocument::remvertexgroup(int _ng)
{

}
void l3d_mainscenedocument::subdivide()
{

}
void l3d_mainscenedocument::subdivide_all()
{

}
