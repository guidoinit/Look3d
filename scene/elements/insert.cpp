#define GLEW_STATIC
#include <GL/glew.h>
#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "mesh/object3dinclude.h"

#include "mesh/mesh3d/mesh3dinclude.h"

#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "mesh/l3d_mesh.h"



#include "insert.h"



#define RAGGIO_ELEMENTS 200.0F
using namespace l3d;
using namespace l3d::mesh;
insert::insert()
{
        m_angolo=0.0F;
        m_distance=0.0F;
        m_oldsel=0;
        iswireframe=true;
}

insert::~insert()
{
}

void insert::Create()
{
        world_pos.SetVertex(0.0F,0.0F,0.0F);

        GLfloat ambient[4]={
            0.5F,0.5F,0.5F,1.0F
        };
        m_select=0;

        for(int ix=0; ix < 4 ; ix++)
        {
            m_mat.mat_ambient[ix]=ambient[ix];
            m_mat.mat_diffuse[ix]=ambient[ix];
            m_mat.mat_emission[ix]=ambient[ix];
            m_mat.mat_specular[ix]=ambient[ix];

        }
        m_mat.mat_shininess[0]=20.0F;
        m_mat.m_bambientanddiffuse=false;

        m_bselect=false;

        m_angolo=0.0F;

        m_oselected=false;

        m_object.clear();

        float par[5];
        float *fpar=&par[0];

        par[0]=1;
        par[1]=10.0F;
        _mesh.create(mesh_plane,fpar);

        par[0]=2;
        _mesh.create(mesh_plane,fpar);

        par[0]=4;
        _mesh.create(mesh_plane,fpar);

        /*mplane.create(1,10.0F);
        mplane.SetColor(0.5F,0.5F,0.5F,.5F);
        mplane.setName("plane","1-10");
        mplane.setMaterial(m_mat);*/

        //m_object.push_back(mplane);

        /*mplane.create(2,10.0F);
        mplane.SetColor(0.5F,0.5F,0.5F,.5F);
        mplane.setName("plane","2-10");
        mplane.setMaterial(m_mat);
        m_object.push_back(mplane);

        mplane.create(4,10.0F);
        mplane.SetColor(0.5F,0.5F,0.5F,.5F);
        mplane.setName("plane","4-10");
        mplane.setMaterial(m_mat);
        m_object.push_back(mplane);
        */
        par[0]=2;
        _mesh.create(mesh_cube,fpar);

        par[0]=4;
        _mesh.create(mesh_cube,fpar);

        par[0]=8;
        _mesh.create(mesh_cube,fpar);


        /*cb.create(2,10.0F);
        cb.SetColor(0.5F,0.5F,0.5F,.5F);
        cb.setName("cube","2-10");
        cb.setMaterial(m_mat);
        m_object.push_back(cb);

        cb.create(4,10.0F);
        cb.SetColor(0.5F,0.5F,0.5F,.5F);
        cb.setName("cube","4-10");
        cb.setMaterial(m_mat);
        m_object.push_back(cb);

        cb.create(8,10.0F);
        cb.SetColor(0.5F,0.5F,0.5F,.5F);
        cb.setName("cube","8-10");
        cb.setMaterial(m_mat);
        m_object.push_back(cb);

        */

        //_mesh.create(mesh_disck,NULL);

/*
        mdisck.create(10.0F,8);
        mdisck.setName("disck","10-8");
        mdisck.setMaterial(m_mat);
        m_object.push_back(mdisck);

        mdisck.create(10.0F,16);
        mdisck.setName("disck","10-16");
        mdisck.setMaterial(m_mat);
        m_object.push_back(mdisck);

        mdisck.create(10.0F,32);
        mdisck.setName("disck","10-32");
        mdisck.setMaterial(m_mat);
        m_object.push_back(mdisck);

        mdisck.create(10.0F,64);
        mdisck.setName("disck","10-64");
        mdisck.setMaterial(m_mat);
        m_object.push_back(mdisck);

*/
        par[0]=par[1]=4;
        par[2]=10.0F;
        _mesh.create(mesh_sphereuv,fpar);

        par[0]=par[1]=8;
        _mesh.create(mesh_sphereuv,fpar);

        par[0]=par[1]=16;
        _mesh.create(mesh_sphereuv,fpar);

        par[0]=par[1]=32;
        _mesh.create(mesh_sphereuv,fpar);

        par[0]=par[1]=48;
        //_mesh.create(mesh_sphereuv,fpar);


        par[0]=16;
        par[1]=10.0F;

        _mesh.create(mesh_cone,fpar);

        par[0]=32;


        _mesh.create(mesh_cone,fpar);

        par[0]=64;

        _mesh.create(mesh_cone,fpar);

        par[0]=20.0F;
        par[1]=32;

        //_mesh.create(mesh_tube,fpar); to-do risolvere errore

        par[0]=par[1]=8;
        par[2]=25;
        par[3]=8;

        _mesh.create(mesh_torus,fpar);

        par[0]=par[1]=16;

        _mesh.create(mesh_torus,fpar);

        par[0]=par[1]=32;

        //_mesh.create(mesh_torus,fpar);

        par[0]=par[1]=64;

        //_mesh.create(mesh_torus,fpar);

        for(int ix=0; ix < _mesh.size();ix++)
            _mesh.create_vbo(ix);

        /*
        sp.create(4,4,10.0F);
        sp.SetColor(0.5F,0.5F,0.5F,1.0F);
        sp.setName("sphere","4-4-10");
        sp.setMaterial(m_mat);
        m_object.push_back(sp);

        sp.create(8,8,10.0F);
        sp.SetColor(.5F,0.5F,0.5F,1.0F);
        sp.setName("sphere","8-8-10");
        sp.setMaterial(m_mat);
        m_object.push_back(sp);

        sp.create(16,16,10.0F);
        sp.setName("sphere","16-16-10");
        sp.setMaterial(m_mat);
        m_object.push_back(sp);
        */
       // sp.create(32,32,10.0F);
       // m_object.push_back(sp);
      //  sp.create(64,64,10.0F);
      //  m_object.push_back(sp);

/*
        co.create(16,10.0F);
        co.SetColor(0.5F,0.5F,0.5F,1.0F);
        co.setName("cone","16-10");
        co.setMaterial(m_mat);
        m_object.push_back(co);

        co.create(32,10.0F);
        co.SetColor(0.5F,0.5F,0.5F,1.0F);
        co.setName("cone","32-10");
        co.setMaterial(m_mat);
        m_object.push_back(co);
*/
/*
        mtube.create(20.0F,32);
        mtube.SetColor(0.5F,0.5F,0.5F,1.0F);
        mtube.setName("cylinder","32-20");
        mtube.setMaterial(m_mat);
        m_object.push_back(mtube);

        mtube.create(20.0F,64);
        mtube.SetColor(0.5F,0.5F,0.5F,1.0F);
        mtube.setName("cylinder","64-20");
        mtube.setMaterial(m_mat);
        m_object.push_back(mtube);

        mtubes.create(20.0F,32,10);
        mtubes.SetColor(0.5F,0.5F,0.5F,1.0F);
        mtubes.setName("cylinder","32-20-10");
        mtubes.setMaterial(m_mat);
        m_object.push_back(mtubes);

        mtubes.create(20.0F,32,5);
        mtubes.SetColor(0.5F,0.5F,0.5F,1.0F);
        mtubes.setName("cylinder","32-20-5");
        mtubes.setMaterial(m_mat);
        m_object.push_back(mtubes);
*/
        /*
        t.create(10.0F,5.0F,20,10);
        t.SetColor(0.5F,0.5F,0.5F,1.0F);
        t.setMaterial(m_mat);
        m_object.push_back(t);

        t.create(10.0F,5.0F,40,20);
        t.SetColor(.5F,0.5F,0.5F,1.0F);
        t.setMaterial(m_mat);
        m_object.push_back(t);

        t.create(10.0F,5.0F,60,30);
        t.SetColor(.5F,0.5F,0.5F,1.0F);
        t.setMaterial(m_mat);
        m_object.push_back(t);

*/
        float step=360.0F/(float)(m_object.size());
        int ix=0;
        float raggio=RAGGIO_ELEMENTS;
        float fx=0.0F;
        for (ix=0; ix < _mesh.size(); ix++)
        {
                float x,y,z;
                x=cos(fx *3.1415F/180.0F )*raggio;
                y=0.0F;
                z=sin(fx* 3.1415F/180.0F )*raggio;


                _mesh.find(ix)->_transformation._wp.x=x;
                _mesh.find(ix)->_transformation._wp.y=y;
                _mesh.find(ix)->_transformation._wp.z=z;

                //m_object[ix].world_pos.SetVertex(x,y,z);

                //m_object[ix].m_angolo[2]=45.0F; to-do
                fx+=step;
        }
        l3d_uint c=0;
        pl3d_mesh_struct _m=_mesh.find(c);
        m_tel.Create(vertex(0.0F,0.0F,0.0F),vertex(_m->_transformation._wp.x,_m->_transformation._wp.y,_m->_transformation._wp.z));///m_object[0].world_pos);

}

void insert::next()
{
        if(m_select+1 > m_object.size()-1)
                m_select=0;
        else
                m_select++;
}
void insert::prev()
{
        if(m_select-1 < 0)
                m_select=m_object.size()-1;
        else
                m_select--;
}
void insert::Select()
{
        m_bselect=true;
}
void insert::addobject(object3d obj)
{
    m_object.push_back(obj);
}

void insert::Draw()
{
        //m_tel..Draw();

        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        gluLookAt(m_tel.vpos.GetX(),m_tel.vpos.GetY(),m_tel.vpos.GetZ(),m_tel.vposwhere.GetX(),m_tel.vposwhere.GetY(),m_tel.vposwhere.GetZ(),0.0F,1.0F,0.0F);

        glPushMatrix();

        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());

        //glRotatef(30.0F,1.0F,0.0F,0.0F);
        glRotatef(m_angolo,0.0F,1.0F,0.0F);

        if(m_oldsel!=m_select)
            m_distance=0.0F;
        m_distance+=4.0F;
        if(m_oldsel < m_select)
        {
            m_angolo+=2.0F;

        }
        if(m_oldsel > m_select)
                m_angolo-=2.0F;

        if(m_angolo >= (360.0F/(float)_mesh.size())*m_select)
        {
                m_oldsel=m_select;
                m_angolo=(360.0F/(float)m_object.size())*m_select;


        }
        if(m_distance >=(RAGGIO_ELEMENTS/3.0F*2.5F))
            m_distance=(RAGGIO_ELEMENTS/3.0F*2.5F);


        /*to-do
        m_object[m_select].m_angolo[0]+=1.0F;
        m_object[m_select].m_angolo[1]+=2.0F;
        m_object[m_select].m_angolo[2]+=3.0F;
        */

        m_mat.set();

        //m_object[m_select].m_angolo[2]=45.0F;

        for(int ix=0; ix < _mesh.size(); ix++)
        {
            pl3d_mesh_struct m=_mesh.find(ix);


                _mesh.draw_vbo(ix);
                /*
                    if(iswireframe)
                        m_object[ix].DrawLines();
                    else
                    {
                        m_object[ix].DrawMaterial(true);

                    }
                */



                if(ix!= m_select)
                {
                    m->_transformation._rotate.x=0.0F;
                    m->_transformation._rotate.y=0.0F;
                    m->_transformation._rotate.z=0.0F;

                    float x,y,z,fx;


                    fx=360.0F/(float)(_mesh.size())*ix;


                    x=cos(fx *3.1415F/180.0F )*(RAGGIO_ELEMENTS);//(+m_distance);

                    y=0.0F;

                    z=sin(fx* 3.1415F/180.0F )*(RAGGIO_ELEMENTS);//+m_distance);

                    m->_transformation._rotate.set(x,y,z);
                }
                else
                {
                        float x,y,z,fx;

                        fx=360.0F/(float)(_mesh.size())*ix;

                        x=cos(fx *3.1415F/180.0F )*(RAGGIO_ELEMENTS-m_distance);//+m_distance);
                        y=0.0F;
                        z=sin(fx* 3.1415F/180.0F )*(RAGGIO_ELEMENTS-m_distance);//+m_distance);

                        m->_transformation._wp.set(x,y,z);
                }


        }
        if(m_bselect)
        {

                m_tel.vpos.AddZ(RAGGIO_ELEMENTS/50.0F);//(RAGGIO_ELEMENTS/50.0F));

                if (m_tel.vpos.GetZ() < -4000.0F)
                {
                        m_bselect=false;
                        l3d_uint c=0;
                        pl3d_mesh_struct _m=_mesh.find(c);
                        m_tel.Create(vertex(0.0F,10.0F,0.0F),vertex(_m->_transformation._wp.x,_m->_transformation._wp.y,_m->_transformation._wp.z));
                        m_oselected=true;
                }
        }
        glPopMatrix();

}
bool insert::Selected()
{
        return(m_oselected);
}
object3d insert::GetObjectSelected()
{
        object3d obj=m_object[m_select];
        m_oselected=false;

        obj.SetWorldPos(0.0F,0.0F,0.0F);
        obj.m_angolo[0]=0.0F;
        obj.m_angolo[1]=0.0F;
        obj.m_angolo[2]=0.0F;
        obj.SetSmooth(false);
        obj.CalcNormal();
        return obj;


}
