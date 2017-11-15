#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_line.h"
#include "l3d_face3.h"
#include "l3d_face4.h"
#include "l3d_mesh.h"

#include "vbo/l3d_bufferobject.h"
#include "vbo/l3d_vertexbufferobject.h"

#include "scene/sceneenum.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;

l3d_mesh::l3d_mesh()
{
    _first=NULL;
    _last=NULL;
    _nmeshes=0;
    _icount=0;
}
l3d_bool l3d_mesh::vertex_alone(int ix)
{

    return(true);
}

l3d_bool l3d_mesh::isfirst()
{
    return(_first==NULL && _last==NULL && _nmeshes==0);
}

void l3d_mesh::add(pl3d_mesh_struct _e)
{
    //_e->faces_normals(); ?? is correct?
    init_material(_e);
    _e->_description=_e->_description1=_e->_description2="";
    _e->_display->inmove=false;
    _e->_display->invert=false;
    _e->make_box();

    _e->_transformation._wpgroup=_e->_transformation._wp;
    _e->_id_group=-1;
    _e->_lgroup=l3d_null;
    _e->_transformation._scalegroup.set(1.0F,1.0F,1.0F);
    _e->_transformation._rotategroup.set(0.0F,0.0F,0.0F);

    _e->_transformation._scalevertex.set(1.0F,1.0F,1.0F);

    if(isfirst())
    {
        _first=_e;
        _first->next=NULL;
        _first->prev=NULL;
        _last=_first;


    }
    else
    {
        _e->prev=_last;
        _e->next=NULL;
        _last->next=_e;
        _last=_e;



    }
    _nmeshes++;
}
pl3d_mesh_struct l3d_mesh::first()
{
    return(_first);
}
l3d_uint l3d_mesh::find( pl3d_mesh_struct _m)
{
    l3d_uint im=0;
    pl3d_mesh_struct appm=_first;

    while(appm)
    {
        if(appm==_m)
            return(im);
        im++;
        appm=appm->next;
    }
    return(-1);
}

pl3d_mesh_struct l3d_mesh::find(l3d_uint _index)
{
    l3d_uint ix=0;
    if(_index < 0 || _index > _nmeshes)
        return NULL;

    pl3d_mesh_struct pfirst=_first;

    while(ix++ != _index && pfirst)
        pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return NULL;
}
void l3d_mesh::del(pl3d_mesh_struct _m)
{
    l3d_uint im=find(_m);

    if(im!=-1)
        del(im);
}

void l3d_mesh::del(l3d_uint _index)
{
    if(isfirst())
        return;
    else
    {
        pl3d_mesh_struct mf=find(_index),plast=_last;

        if(mf != NULL)
        {
            mf->_faces.clear();
            mf->_edges.clear();
            mf->_vertex.clear();
            mf->_quad.clear();

            if(mf==_first && mf==_last && _nmeshes==1)
            {
                _first=_last=l3d_null;



            }
            else if(mf==_first)
            {
                _first=_first->next;
                _first->prev=l3d_null;


            }

            else if (mf==_last)
            {
                _last=_last->prev;
                _last->next=l3d_null;


            }

            else
            {
                mf->prev->next=mf->next;
                mf->next->prev=mf->prev;



            }
            delete(mf->_display);
            delete(mf);

            _nmeshes--;

        }




    }

}

void l3d_mesh::clear()
{
    pl3d_mesh_struct ms=_last;

    while(_last)
    {
        _last=_last->prev;

        ms->_faces.clear();
        ms->_edges.clear();
        ms->_vertex.clear();

        delete(ms);

        ms=_last;

    }

    _first=NULL;
    _last=NULL;
    _nmeshes=0;

}
void l3d_mesh::create_null()
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;

    newmesh->_id_group=-1;

    newmesh->_display->isnull=true;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("null",_icount++);

    newmesh->_sub_name="null object";
    newmesh->_display->isnull=true;

    newmesh->next=NULL;
    newmesh->prev=NULL;

    add(newmesh);

}
void l3d_mesh::create_line(l3d_float*)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->_name=new char[25];

    newmesh->setname("line",_icount++);


    newmesh->_sub_name="line object";


    l3d_uint m_points=8;
    l3d_float m_side=32;

    float pstart=-m_side;

    float stepx=(m_side*2)/(float)m_points;


    for(float ix=pstart;ix <=m_side; ix+=stepx)
    {


        newmesh->addvertex(ix,0.0F,0.0F);


    }


    for(int ix=0; ix < newmesh->_vertex.size()-1; ix++)
    {
        newmesh->addedge(ix,ix+1);



    }
    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);

}
void l3d_mesh::create_circle(l3d_float*par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("circle",_icount++);
    newmesh->_sub_name="circle object";

    l3d_uint m_points=32;

    l3d_float stepa=(float)(360.0F/(float)m_points);

    l3d_float py=0.0F,px,pz,m_radius=10.0F;


    if(par!=NULL)
    {
        m_points=(l3d_uint)*par++;
        m_radius=(l3d_float)*par;
    }

    for(float fx=0.0F; fx < 360.0F; fx+=stepa)
    {

        px=sin(fx/180.0F*3.1415F)*m_radius;
        pz=cos(fx/180.0F*3.1415F)*m_radius;

        newmesh->addvertex(px,0.0F,pz);

    }
    //creare la linee


    l3d_uint startv=0;
    for(int ix=1;ix < newmesh->_vertex.size(); ix++)
    {
        newmesh->addedge(startv,ix);



        startv++;


    }
    newmesh->addedge(0,newmesh->_vertex.size()-1);
    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);
}
void l3d_mesh::create_circle(pl3d_mesh_struct _m, l3d_float* par)
{

    _m->_display= new l3d_mesh_display_struct;


    _m->_display->isnull=false;
    _m->_display->invert=false;

    _m->_transformation.init();

    _m->setname("circle",_icount++);
    _m->_sub_name="circle object";

    l3d_uint m_points=32;

    l3d_float stepa=(float)(360.0F/(float)m_points);

    l3d_float py=0.0F,px,pz,m_radius=10.0F;


    if(par!=NULL)
    {
        m_points=(l3d_uint)*par++;
        m_radius=(l3d_float)*par;
    }

    for(float fx=0.0F; fx < 360.0F; fx+=stepa)
    {

        px=sin(fx/180.0F*3.1415F)*m_radius;
        pz=cos(fx/180.0F*3.1415F)*m_radius;

        _m->addvertex(px,0.0F,pz);

    }
    //creare la linee


    l3d_uint startv=0;
    for(int ix=1;ix < _m->_vertex.size(); ix++)
    {
        _m->addedge(startv,ix);



        startv++;


    }
    _m->addedge(0,_m->_vertex.size()-1);
    _m->next=NULL;
    _m->prev=NULL;

}
void l3d_mesh::create_disck(l3d_float*par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("disck",_icount++);
    newmesh->_sub_name="disck object";


    int vert=1;
    l3d_uint m_istep=32;
    l3d_float raggio=10.0F;

    if(par!=NULL)
    {
        m_istep=(l3d_uint)*par++;
        raggio=(l3d_float)*par;
    }

    float step=360.0F/(float)m_istep ;

    newmesh->addvertex(0.0F,0.0F,0.0F);


    for (float a=0.0F; a<360.0F; a+=step)
    {
        float x,y,z;
        x=y=z=0.0F;

        x=(float)sin((float)a * 3.1415f / 180.0f)*raggio;
        y=(float)0.0f;
        z=(float)cos((float)a * 3.1415f / 180.0f)*raggio;



        newmesh->addvertex(x,y,z);

        newmesh->addedge(0,newmesh->_vertex.size()-1);
        vert++;
    }
    //int ivp;
    /*for(int ix=1; ix < newmesh->_vertex.size()-1; ix++)
    {
        newmesh->addedge(ix,ix+1);

        ivp=ix+1;
    }

    newmesh->addedge(ivp ,1);
    */

    int verc=0;
    vert=0;

    int a,b,c;
    for (int nIndex=1;nIndex<newmesh->_vertex.size()-1;nIndex++)
    {

        a=verc;
        b=nIndex;
        c=nIndex+1;

        newmesh->addface3(a,b,c,true,abcCW);

        vert++;
    }
    a=verc;
    b=newmesh->_vertex.size()-1;
    c=1;

    newmesh->addface3(a,b,c,true,abcCW);



    verc=0;
    vert=newmesh->_faces.size();
    for (int nIndex=1;nIndex < newmesh->_vertex.size()-1;nIndex++)
    {
        a=verc;
        c=nIndex;
        b=nIndex+1;
        newmesh->addface3(a,b,c,true,abcCW);

        vert++;
    }
    a=verc;
    c=newmesh->_vertex.size()-1;
    b=1;

    newmesh->addface3(a,b,c,true,abcCW);

    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);

}
void l3d_mesh::create_plane(l3d_float* par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();


    newmesh->setname("plane",_icount++);

    newmesh->_sub_name="plane object";

    l3d_float m_fraggio=10.0F;
    l3d_uint m_nstrati=2;
    l3d_uint m_function=0;
    if(par!=NULL)
    {
        m_nstrati=(l3d_uint)*par++;
        m_fraggio=(l3d_float)*par++;
        m_function=(l3d_uint)*par;
    }




    double step=(double)(m_fraggio*2.0F/(double)m_nstrati);
    int nvert=m_nstrati+1;
    float fy=0.0F;


    int vprevx=0,vprevy=0;
    int startv=0;
    double fx=-m_fraggio;

    for(int ix=0; ix <nvert; ix++ )
    {

            startv=newmesh->_vertex.size();

            double fz=-m_fraggio;

            for(int iy=0; iy <nvert; iy++)
            {
                    fy=0.0F;
                    switch(m_function)
                    {
                    case 1:
                            fy=sin(fx);
                            break;
                    case 2:
                            fy=sin(fz);
                            break;
                    case 3:
                            fy=sin(fx)*sin(fz);
                            break;
                    case 4:
                            fy=sin(fx * fz);
                            break;
                    case 5:
                            fy=sin(fx)+cos(fz);
                            break;
                    }

                    newmesh->addvertex(fx,fy,fz);

                    fz+=step;
                    vprevy++;
            }
            fx+=step;

            if(vprevx>0){

                    for(int ix=0; ix < nvert-1; ix++)
                    {
                        l3d_uint a,b,c,d;

                        a=startv-nvert+ix;
                        b=startv-nvert+ix+1;
                        c=startv+ix;
                        d=startv+ix+1;
                        //a,b,c,d
                        newmesh->addquad(a,b,c,d,abcdCW);

                    }

            }

            vprevy=0;
            vprevx++;

    }

    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);

}
void l3d_mesh::create_cube(l3d_float* par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;


    if(newmesh->_display!=NULL)
    {
        newmesh->_display=NULL;

        newmesh->_display= new l3d_mesh_display_struct;

    }


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("cube",_icount++);


    newmesh->_sub_name="cube object";
    l3d_float m_dim=10.0F;
    l3d_float m_side=4;

    if(par!=NULL)
    {
        m_side=*par++;
        m_dim=*par;
    }

    double step=(double)(m_dim*2.0F/(double)m_side);
    int nvert=m_side+1;
    int x,x1,y,y1;

    int vprevx=0,vprevy=0;
    int startv=0,startv2;
    double fx=-m_dim;
    double fz=-m_dim;
    float fy=-m_dim;

    //parte inferiore
    for(int ix=0; ix <nvert; ix++ )
    {
            startv=newmesh->_vertex.size();

            fx=-m_dim;

            for(int iy=0; iy <nvert; iy++)
            {
                newmesh->addvertex(fx,fy,fz);

                fx+=step;
                vprevy++;
            }
            fz+=step;

            if(vprevx>0)
            {
                //qDebug()<<"piano inf:";
                for(int ix=0; ix < nvert-1; ix++)
                {
                    int a,b,c,d;
                    a=startv-nvert+ix;
                    b=startv-nvert+ix+1;
                    c=startv+ix;
                    d=startv+ix+1;
                    //qDebug() << ":"<<x<< ":"<<y1<< ":"<<x1<< ":"<<y;
                    newmesh->addquad(a,b,c,d,abcdCW);


                }
            }

            vprevy=0;
            vprevx++;

    }

    //parte centrale


    l3d_vertex piano;


    fy=-m_dim;

    for(int ix=0; ix <m_side-1;ix++)//nvert-1; ix++ )
    {

        piano.clear();



        fy+=step;
        fx=-m_dim;
        fz=-m_dim;

        for(int ix2=0; ix2 <nvert; ix2++ )
        {
            piano.add(fx,fy,fz);
            //local_vertex.push_back();

            fx+=step;
        }
        //inserisci poligoni

        startv=newmesh->_vertex.size();

        newmesh->addvertex(piano.get(0));

        //local_vertex.push_back(piano.get(0));

        x=startv;
        x1=startv+1;

        if(ix==0)
            y=0;
        else
            y=startv-(m_side*4);
        y1=y+1;

        //qDebug() <<startv << ":" <<nvert << ":"<< y;

        for(int ix2=1; ix2 < piano.size(); ix2++)
        {
            newmesh->addvertex(piano.get(ix2));
            //local_vertex.push_back(piano.at(ix2));
            //qDebug() << ":"<<y<< ":"<<x<< ":"<<y1<< ":"<<x1;
            //if(ix==0)
            newmesh->addquad(y++,x++,y1++,x1++,abcdCW);



        }
        //qDebug() << ":"<<x<< ":"<<x1<< ":"<<y<< ":"<<y1;
        startv2=y;
        piano.clear();
        //inserisci altro lato
        fx-=step;
        fz+=step;
        for(int ix2=0; ix2 <nvert-1; ix2++ )
        {
            //if(ix==0)
            piano.add(fx,fy,fz);

            //local_vertex.push_back();

            fz+=step;
        }
        //inserisci poligoni

        startv=newmesh->_vertex.size()-1;

        x=startv;
        x1=startv+1;

        y=startv2;
        if(ix==0)
            y1=y+nvert;
        else
            y1=y+1;

        //qDebug() <<"y:"<< y<<"startv;"<<startv;
        for(int ix2=0; ix2 < piano.size(); ix2++)
        {
            //if(ix==0)
            newmesh->addvertex(piano.get(ix2));
            //local_vertex.push_back(piano.at(ix2));
            //qDebug() << ":"<<x<< ":"<<y<< ":"<<x1<< ":"<<y1;
            //if(ix==0)
            newmesh->addquad(y,x++,y1,x1++,abcdCW);
            //AddPoligon(y,x++,y1,x1++);
            if(ix==0)
                y+=nvert;
            else
                y++;
            if(ix==0)
                y1+=nvert;
            else
                y1++;


        }
        piano.clear();
        //inserisci altro lato
        if(ix==0)
            startv2=y1-nvert;
        else
            startv2=y1;
        fz-=step;
        for(int ix2=0; ix2 <nvert-1; ix2++ )
        {
            fx-=step;
            //if(ix==0)
            piano.add(fx,fy,fz);

            //local_vertex.push_back();


        }
        //inserisci poligoni

        startv=newmesh->_vertex.size()-1;

        x=startv;
        x1=startv+1;

        y=startv2;
        y1=y-1;

        qDebug() <<"y:"<< y<<"x;"<<startv;
        for(int ix2=0; ix2 < piano.size(); ix2++)
        {
            newmesh->addvertex(piano.get(ix2));

            qDebug() << ":"<<x<< ":"<<x1<< ":"<<y<< ":"<<y1;
            if(ix==0)
                newmesh->addquad(y,x++,y1,x1++,abcdCW);
                //AddPoligon();
            else
                newmesh->addquad(x++,x1++,y1,y,abcdCW);
                //AddPoligon(x++,x1++,y1,y);
            if(ix==0)
            {
                y--;
                y1--;

            }
            else
            {
                y++;
                y1++;

            }




        }
        piano.clear();
        //inserisci altro lato
        startv2=y++;

        for(int ix2=0; ix2 <nvert-2; ix2++ )
        {
            fz-=step;
            //if(ix==0)
            piano.add(fx,fy,fz);

            //local_vertex.push_back();


        }
        //inserisci poligoni

        startv=newmesh->_vertex.size()-1;

        x=startv;
        x1=startv+1;
        if(ix==0)
        {
            y=startv2;
            y1=y-nvert;

        }else
        {
            y=startv2-1;
            y1=y+1;
        }


        qDebug() <<"y:"<< y<<"x:"<<startv;
        for(int ix2=0; ix2 < piano.size(); ix2++)
        {
            newmesh->addvertex(piano.get(ix2));

            //local_vertex.push_back(piano.at(ix2));
            //qDebug() << ":"<<x<< ":"<<x1<< ":"<<y<< ":"<<y1;
            if(ix==0)
            {
                newmesh->addquad(y,x++,y1,x1++,abcdCW);
                //AddPoligon(y,x++,y1,x1++);
                y-=nvert;
                y1-=nvert;
            }
            else
            {
                newmesh->addquad(y++,x++,y1++,x1++,abcdCW);
                //AddPoligon(y++,x++,y1++,x1++);
            }





        }
        //ultimo poligono to-do

        y=y1-(m_side*4);
        x=x1-(m_side*4);
        y1--;
        x1--;
        if(ix==0)
        {

            y=0;
            y1=nvert;

        }
        qDebug() << "last:"<<x<< ":"<<x1<< ":"<<y<< ":"<<y1;
        newmesh->addquad(x1,x,y1,y,abcdCW);
        //AddPoligon(x1,x,y1,y);




    }
    //parte superiore
    fx=-m_dim;
    fz=-m_dim;
    fy=m_dim;
    vprevx=0;
    vprevy=0;
    startv2=newmesh->_vertex.size();

    for(int ix=0; ix <nvert; ix++ )
    {
            startv=newmesh->_vertex.size();

            fx=-m_dim;

            for(int iy=0; iy <nvert; iy++)
            {

                   newmesh->addvertex(fx,fy,fz);

                   fx+=step;
                   vprevy++;
            }
            fz+=step;

            if(vprevx>0)
            {
                //qDebug()<<"piano inf:";
                for(int ix=0; ix < nvert-1; ix++)
                {
                    int x,x1,y,y1;
                    x=startv-nvert+ix;
                    x1=startv-nvert+ix+1;
                    y=startv+ix;
                    y1=startv+ix+1;
                    //qDebug() << ":"<<x<< ":"<<y1<< ":"<<x1<< ":"<<y;
                    newmesh->addquad(x1,x,y1,y,abcdCW);

                    //AddPoligon(startv-nvert+ix,startv-nvert+ix+1,startv+ix,startv+ix+1);
                }
            }

            vprevy=0;
            vprevx++;

    }
    //collega con parte superiore
    x=startv2;
    x1=x+1;
    y=startv2-(m_side*4);
    y1=y+1;
    for(int ix2=0; ix2 < m_side; ix2++)
    {
       newmesh->addquad(x++,x1++,y++,y1++,abcdCW);
    }
    x=x1-1;
    y=y1-1;
    x1=x+nvert;
    y1=y+1;
    for(int ix2=0; ix2 < m_side; ix2++)
    {
        newmesh->addquad(x,x1,y++,y1++,abcdCW);
        x+=nvert;
        x1+=nvert;
    }
    x1=x-1;
    y1=y+1;
    for(int ix2=0; ix2 < m_side; ix2++)
    {
        newmesh->addquad(x--,x1--,y++,y1++,abcdCW);

    }
    x=x1+1;
    y=y1-1;
    x1=x-nvert;
    y1=y+1;
    for(int ix2=0; ix2 < m_side-1; ix2++)
    {

        newmesh->addquad(x,x1,y++,y1++,abcdCW);
        x-=nvert;
        x1-=nvert;
    }
    //ultimo poligono
    x=x1+nvert;
    y=y1-1;
    x1=startv2;
    y1=startv2-(m_side*4);
    //qDebug() <<"last part:"<<x<<x1<<y<<y1;

    newmesh->addquad(x,x1,y,y1,abcdCW);

    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);

}
void l3d_mesh::create_cone(l3d_float* par,pl3d_mesh_struct _mesh)
{
    if(!_mesh)
        return;

    pl3d_mesh_struct newmesh= _mesh;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("cone",0);
    newmesh->_sub_name="cone object";

    l3d_float m_raggio=10.0F;
    l3d_float m_size=32;

    if(par!=NULL)
    {
        m_size=*par++;
        m_raggio=*par;
    }

    float dimobj=m_raggio;



    newmesh->addvertex(0.0F,0.0F,0.0F);




    //inserimento dei vertici della base

    int vert=1;

    float fsize=(float)360.0F/m_size;


    for (float a=0.0F; a<360.0F; a+=fsize)

    {

        float x,y,z;

        x=y=z=0;

        x=(float)sin((float)a * 3.1415F / 180.0)*m_raggio;

        y=0.0F;

        z=(float)cos((float)a * 3.1415F / 180.0)*m_raggio ;

        newmesh->addvertex(x,y,z);

        newmesh->addedge(0,newmesh->_vertex.size()-1);

        vert++;

    }






    //definizione dei poligoni
    newmesh->addvertex(0.0F,dimobj*2,0.0F);


    int verc=0,a,b,c;
    vert=0;

    for (int nIndex=1;nIndex<m_size;nIndex++)
    {




        a=verc;
        c=nIndex;
        b=nIndex+1;
        newmesh->addface3(a,b,c,true,abcCW);




        vert++;

    }



    a=verc;
    c=m_size;
    b=1;

    newmesh->addface3(a,b,c,true,abcCW);



    vert++;

    verc=m_size+1;

    for (int nIndex=1;nIndex<m_size;nIndex++)

    {


        a=verc;

        b=nIndex;
        c=nIndex+1;

        newmesh->addface3(a,b,c,true,abcCW);



        vert++;

    }



    a=verc;

    b=m_size;
    c=1;

    newmesh->addface3(a,b,c,true,abcCW);

    newmesh->next=l3d_null;
    newmesh->prev=l3d_null;



}

void l3d_mesh::create_cone(l3d_float* par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("cone",_icount++);
    newmesh->_sub_name="cone object";

    l3d_float m_raggio=10.0F;
    l3d_float m_size=32;

    if(par!=NULL)
    {
        m_size=*par++;
        m_raggio=*par;
    }

    float dimobj=m_raggio;



    newmesh->addvertex(0.0F,0.0F,0.0F);




    //inserimento dei vertici della base

    int vert=1;

    float fsize=(float)360.0F/m_size;


    for (float a=0.0F; a<360.0F; a+=fsize)

    {

        float x,y,z;

        x=y=z=0.0F;

        x=(float)sin((float)a * 3.1415F / 180.0)*m_raggio;

        y=0.0F;

        z=(float)cos((float)a * 3.1415F / 180.0)*m_raggio ;

        newmesh->addvertex(x,y,z);



        vert++;

    }






    //definizione dei poligoni
    newmesh->addvertex(0.0F,dimobj*2,0.0F);


    int verc=0,a,b,c;
    vert=0;

    for (int nIndex=1;nIndex<m_size;nIndex++)
    {




        a=verc;
        c=nIndex;
        b=nIndex+1;
        newmesh->addface3(a,b,c,true,abcCW);




        vert++;

    }



    a=verc;
    c=m_size;
    b=1;

    newmesh->addface3(a,b,c,true,abcCW);



    vert++;

    verc=m_size+1;

    for (int nIndex=1;nIndex<m_size;nIndex++)

    {


        a=verc;

        b=nIndex;
        c=nIndex+1;

        newmesh->addface3(a,b,c,true,abcCW);



        vert++;

    }



    a=verc;

    b=m_size;
    c=1;

    newmesh->addface3(a,b,c,true,abcCW);

    newmesh->next=l3d_null;
    newmesh->prev=l3d_null;
    add(newmesh);



}
void l3d_mesh::create_cylinder(l3d_float* par)
{
    int a,b,c,d;
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("cylinder",_icount++);
    newmesh->_sub_name="cylinder object";



    int vert=0;

    l3d_float m_hight=10.0F;
    l3d_float m_size=32,m_radius=5.0F;
    if(par!=NULL)
    {

        m_size=*par++;
        m_hight=*par++;

        m_radius=*par;

    }



    float fup= float(m_hight / 2.0F );
    float fdown=-fup;


    newmesh->addvertex(0.0F,fdown,0.0F);


    float step=360.0F/(float)m_size ;

    for (float a=0.0F; a<360.0F; a+=step)
    {
            float x,y,z;
            x=y=z=0.0F;

            x=(float)sin((float)a * 3.1415f / 180.0f)*m_radius;
            y=fdown;
            z=(float)cos((float)a * 3.1415f / 180.0f)*m_radius;

            newmesh->addvertex(x,y,z);


            vert++;
    }











    for (float a=0.0F; a<360.0F; a+=step)
    {
            float x,y,z;
            x=y=z=0.0F;


            x=(float)sin((float)a * 3.1415f / 180.0f)*m_radius;
            y=fup;
            z=(float)cos((float)a * 3.1415f / 180.0f)*m_radius;

            newmesh->addvertex(x,y,z);



    }

    newmesh->addvertex(0.0F, fup,0.0F);




    //definizione parte inferiore

    for (int nIndex=1;nIndex<m_size;nIndex++)
    {
        a=0;
        b=nIndex+1;
        c=nIndex;


        newmesh->addface3(a,b,c,true,abcCW);


    }
    a=0;
    b=1;
    c=m_size;

    newmesh->addface3(a,b,c,true,abcCW);

    //definizione parte superiore
    vert = newmesh->_vertex.size()-1;
    for (int nIndex=m_size+1; nIndex < vert-1; nIndex++)
    {
        a=vert;
        b=nIndex;
        c=nIndex+1;

        newmesh->addface3(a,b,c,true,abcCW);


    }
    a=vert;
    b=newmesh->_vertex.size()-2              ;
    c= m_size+1;

    newmesh->addface3(a,b,c,true,abcCW);



    //creazione dei poligoni restanti
    int pvert=newmesh->_vertex.size()-m_size-1;


    for(int nIndex=1; nIndex < m_size; nIndex++)
    {
        a=nIndex;
        b=nIndex+1;
        c=pvert;
        d=pvert+1;

        newmesh->addquad(a,b,c,d,abcdCW);
        pvert++;
    }
    a=m_size;
    b=1;
    c=vert-1;
    d=m_size+1;





    //d,c,b,a

    newmesh->addquad(a,b,c,d,abcdCW);
    newmesh->next=l3d_null;
    newmesh->prev=l3d_null;
    add(newmesh);

}
void l3d_mesh::create_cylindern(l3d_float* par)
{

    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;

    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;
    l3d_float m_height=10.0F,m_size=10,m_radius=5.0F,m_section=10.0F;


    if(par!=NULL)
    {

        m_size=*par++;
        m_height=*par++;
        m_section=*par;
        //m_radius=*par++;


    }

    newmesh->_transformation.init();

    newmesh->_transformation._wp.x=0.0F;
    newmesh->_transformation._wp.y= float(m_height / 2.0F ) ;
    newmesh->_transformation._wp.z=0.0F;


    newmesh->setname("cylindern",_icount++);
    newmesh->_sub_name="cylinder object";



    int vert=0;








    newmesh->addvertex(0.0F,- float(m_height / 2.0F ),0.0F);


    float step=360.0F/(float)m_size ;

    for (float a=0.0F; a<360.0F; a+=step)
    {
            float x,y,z;
            x=y=z=0.0F;

            x=(float)sin((float)a * 3.1415f / 180.0f)*m_radius;
            y=- float(m_height / 2.0F );
            z=(float)cos((float)a * 3.1415f / 180.0f)*m_radius;



            newmesh->addvertex(x,y,z);


            vert++;
    }




    vert=newmesh->_vertex.size();

    for (int nIndex=1;nIndex<vert-1;nIndex++)
    {

        newmesh->addface3(0,nIndex+1,nIndex,true,abcCW);



    }


    newmesh->addface3(0,1,vert-1,true,abcCW);


    //creazione degli strati del tubo a piu strati
    //ciclo che parte dallo strato successivo alla base fino ad arrivare
    //alla base superiore

    float start_strato=(float)(-(m_height/2.0F)) + ((m_height)/ m_section);
    float step_strato=(float)((m_height)/ m_section);
    float appy=(float)(-(m_height/2.0F));

    step=360.0F/(float)m_size ;

    int startv_strato=newmesh->_vertex.size()-1,endv_strato=0,oldv_strato;

    vert=1;
    for(int ix=0; ix < m_section-1; ix++)
    {
        oldv_strato=startv_strato-endv_strato;

        startv_strato=newmesh->_vertex.size();
        appy+=step_strato;

        for (float a=0.0F; a<360.0F; a+=step)
        {
            float x,y,z;
            x=y=z=0.0F;

            x=(float)sin((float)a * 3.1415f / 180.0f)*m_radius;
            y=appy;
            z=(float)cos((float)a * 3.1415f / 180.0f)*m_radius;



            newmesh->addvertex(x,y,z);




       }
       // creazione delle linee del perimetro dello strato



        endv_strato=newmesh->_vertex.size()-1;


        //colegare lo strato precedente a quello corrente
        int v1,v2,v3,v4;
        v1=vert;
        v2=vert+1;
        v3=startv_strato;
        v4=startv_strato+1;

        for (float a=0.0F; a<(360.0F-step); a+=step)
        {
            newmesh->addquad(v1,v2,v3,v4,abcdCW);

            v1=v2;
            v2++;
            v3=v4;
            v4++;

        }
        newmesh->addquad(startv_strato-1,vert,v3,startv_strato,abcdCW);

        vert=startv_strato;
    }

    //creazione della parte superiore








    for (float a=0.0F; a<360.0F; a+=step)
    {
            float x,y,z;
            x=y=z=0.0F;


            x=(float)sin((float)a * 3.1415f / 180.0f)*m_radius;
            y=(float)(m_height / 2.0F );
            z=(float)cos((float)a * 3.1415f / 180.0f)*m_radius;



            newmesh->addvertex(x,y,z);



    }

    newmesh->addvertex(0.0F, (float)(m_height / 2.0F ),0.0F);

    //collegare l'ultimo strato con i vertici alla base superiore

    int v1,v2,v3,v4;
    v1=newmesh->_vertex.size()-2;
    v2=v1-1;

    v3=vert+1;
    v4=v3+1;

    for (float a=0.0F; a<(360.0F-step); a+=step)
    {
        //newmesh->addquad(v1,v2,v3,v4,abcdCW);
        v1=v2;
        v2++;
        v3=v4;
        v4++;

    }
    //newmesh->addquad(v1,startv_strato,newmesh->_vertex.size()-1,v1+2,abcdCW);


    for (int nIndex=vert+1;nIndex<newmesh->_vertex.size()-1;nIndex++)
    {

        //newmesh->addface3(vert,nIndex,nIndex+1,true,abcCW);


    }

    //newmesh->addface3(vert,newmesh->_vertex.size()-1,vert+1,true,abcCW);
    newmesh->next=l3d_null;
    newmesh->prev=l3d_null;

    add(newmesh);

}
void l3d_mesh::create_sphereuv(l3d_float *par, pl3d_mesh_struct _m)
{
    if(!_m)
        return;
    pl3d_mesh_struct newmesh=_m;


    newmesh->_display= new l3d_mesh_display_struct;
    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;
    newmesh->init_material();
    l3d_float uvx=16.0F,uvy=16.0F;
    l3d_float m_raggio=10.0F;





    newmesh->_display->isnull=false;

    newmesh->_transformation.init();

    newmesh->_name=new char[25];
    newmesh->setname("sphereuv",0);


    newmesh->_sub_name="sphereuv object";


    if(par!=NULL)
    {

        uvx=*par++;
        uvy=*par++;

        m_raggio=*par;


    }
    int count1 , count2 ;
    int nIndInf , nIndInf1;
    int v1,v2,v3,v4;
    float dimobj=m_raggio;
    float xapp,yapp,raggioapp;
    float raggio=m_raggio;





    newmesh->addvertex(0.0F,dimobj,0.0F);


    int vert=1;
    double angoloy=(180.0F/(double)(uvy));
    double angolox=(360.0F/(double)(uvx));

    for (double angolo=(angoloy/2.0F); angolo<(180.0f); angolo+=angoloy)
    {
         xapp=(float)sin((float)angolo*3.1415f/180.0f)*raggio;
         yapp=(float)cos((float)angolo*3.1415f/180.0f)*raggio;
         raggioapp=xapp;

         for (double a=(angolox/2.0F); a<360.0F; a+=angolox)
         {

             float x,y,z;
             x=y=z=0;

             x=(float)sin((float)a * 3.1415F / 180.0F)*raggioapp;
             y=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp *(float)cos((float)90.0F*3.1415F/180.0F);
             z=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp * (float)(-sin((float)90.0F*3.1415F/180.0F));

             y=y+yapp;
             newmesh->addvertex(x,y,z);
             vert++;
         }
     }
    newmesh->addvertex(0.0F,-dimobj,0.0F);

    //definizione della parte superiore

    int nm_poly=0;
    int nIndSup=0;

    for (int iy=0; iy < uvx-1 ; iy++)
    {

        v1=nIndSup;

        v2=iy+2;

        v3=iy+1;


        newmesh->addface3(v1,v2,v3,true,abcCW);

        nm_poly++;


    }

    v1=nIndSup;

    v2=nIndSup+1;

    v3=nIndSup+uvx;




    newmesh->addface3(v1,v2,v3,true,abcCW);

    //definizione della parte inferiore


    nIndInf  = newmesh->_vertex.size()- 1 ;


    nIndInf1 = nIndInf - 1 ;


    for (int x=0; x< uvx-1;x++)

    {


        v1=nIndInf;

        v2=nIndInf1-1;

        v3=nIndInf1;


        nIndInf1--;


        newmesh->addface3(v1,v2,v3,true,abcCW);



        nm_poly++;


    }

    v1=nIndInf;

    v2=nIndInf-1;

    v3=nIndInf-uvx;


    newmesh->addface3(v1,v2,v3,true,abcCW);

    //definizione del corpo


    int nIndex=1;

    int nIndex1=uvx + 1;

    for ( int n=1 ; n < uvy; n++)//nvertx-1; n++ )


    {

        count1=nIndex;

        count2=nIndex1;


        for (int x=0;x < uvx -1 ; x++ ){


            //Primo poligono


            v1 = count1   ;

            v2 = count1+1 ;

            v3 = count2   ;

            v4 = count2+1 ;

            newmesh->addquad(v1,v2,v3,v4,abcdCW);

            nm_poly++;


            count1++;


            count2++;


        }

        v1=nIndex1-1;
        v2=nIndex;
        v3=v4;
        v4=v1 +1;


        newmesh->addquad(v1,v2,v3,v4,abcdCW);





        nm_poly++;


        nIndex=nIndex1;


        nIndex1+=uvx;


    }



}

void l3d_mesh::create_sphereuv(l3d_float* par)
{

    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;

    newmesh->_display->isnull=false;

    l3d_float uvx=16.0F,uvy=16.0F;
    l3d_float m_raggio=10.0F;





    newmesh->_display->isnull=false;

    newmesh->_transformation.init();

    newmesh->_name=new char[25];
    newmesh->setname("sphereuv",_icount++);


    newmesh->_sub_name="sphereuv object";


    if(par!=NULL)
    {

        uvx=*par++;
        uvy=*par++;

        m_raggio=*par;


    }
    int count1 , count2 ;
    int nIndInf , nIndInf1;
    int v1,v2,v3,v4;
    float dimobj=m_raggio;
    float xapp,yapp,raggioapp;
    float raggio=m_raggio;





    newmesh->addvertex(0.0F,dimobj,0.0F);


    int vert=1;
    double angoloy=(180.0F/(double)(uvy));
    double angolox=(360.0F/(double)(uvx));

    for (double angolo=(angoloy/2.0F); angolo<(180.0f); angolo+=angoloy)
    {
         xapp=(float)sin((float)angolo*3.1415f/180.0f)*raggio;
         yapp=(float)cos((float)angolo*3.1415f/180.0f)*raggio;
         raggioapp=xapp;

         for (double a=(angolox/2.0F); a<360.0F; a+=angolox)
         {

             float x,y,z;
             x=y=z=0;

             x=(float)sin((float)a * 3.1415F / 180.0F)*raggioapp;
             y=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp *(float)cos((float)90.0F*3.1415F/180.0F);
             z=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp * (float)(-sin((float)90.0F*3.1415F/180.0F));

             y=y+yapp;
             newmesh->addvertex(x,y,z);
             vert++;
         }
     }
    newmesh->addvertex(0.0F,-dimobj,0.0F);

    //definizione della parte superiore

    int nm_poly=0;
    int nIndSup=0;

    for (int iy=0; iy < uvx-1 ; iy++)
    {

        v1=nIndSup;

        v2=iy+2;

        v3=iy+1;


        newmesh->addface3(v1,v2,v3,true,abcCW);




        nm_poly++;


    }

    v1=nIndSup;

    v2=nIndSup+1;

    v3=nIndSup+uvx;




    newmesh->addface3(v1,v2,v3,true,abcCW);

    //definizione della parte inferiore


    nIndInf  = newmesh->_vertex.size()- 1 ;


    nIndInf1 = nIndInf - 1 ;


    for (int x=0; x< uvx-1;x++)

    {


        v1=nIndInf;

        v2=nIndInf1-1;

        v3=nIndInf1;


        nIndInf1--;


        newmesh->addface3(v1,v2,v3,true,abcCW);



        nm_poly++;


    }

    v1=nIndInf;

    v2=nIndInf-1;

    v3=nIndInf-uvx;


    newmesh->addface3(v1,v2,v3,true,abcCW);



    //definizione del corpo


    int nIndex=1;

    int nIndex1=uvx + 1;

    for ( int n=1 ; n < uvy; n++)


    {

        count1=nIndex;

        count2=nIndex1;


        for (int x=0;x < uvx -1 ; x++ ){


            //Primo poligono


            v1 = count1   ;

            v2 = count1+1 ;

            v3 = count2   ;

            v4 = count2+1 ;

            newmesh->addquad(v1,v2,v3,v4,abcdCW);

            nm_poly++;


            count1++;


            count2++;


        }

        v1=nIndex1-1;
        v2=nIndex;
        v3=v4;
        v4=v1 +1;


        newmesh->addquad(v1,v2,v3,v4,abcdCW);





        nm_poly++;


        nIndex=nIndex1;


        nIndex1+=uvx;


    }
    add(newmesh);

}

void l3d_mesh::create_torus(l3d_float* par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;
    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    l3d_float m_uvx=16.0F,m_uvy=16.0F,m_raggiox=20.0F,m_raggioy=5.0F;


    if(par!=NULL)
    {

        m_uvx=*par++;
        m_uvy=*par++;

        m_raggiox=*par++;
        m_raggioy=*par;

    }
    newmesh->_display->isnull=false;

    newmesh->_transformation.init();

    newmesh->setname("torus",_icount++);
    newmesh->_sub_name="torus object";

    double fx,fy;
    GLfloat m[4];

    fx=360.0F/(double)m_uvx;
    fy=360.0F/(double)m_uvy;



    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    //gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);
    GLfloat mat[16];
   // glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
   // glPushMatrix();

   // glLoadIdentity();

   // glTranslatef(0.0F,0.0F,0.0F);


    for(double ix=(fx/2.0F); ix < 360.0F; ix+=fx)
    {
            float appx,appy,appz;
            appx=sin(ix * 3.1415F / 180.0F)*m_raggiox;
            appz=cos(ix * 3.1415F / 180.0F)*m_raggiox;
            appy=0.0F;
           // glPushMatrix();
           // glTranslatef(appx,appy,appz);
          //  glRotatef(90.0F,1.0F,0.0F,0.0F);
           // glRotatef(90.0F-ix,0.0F,0.0F,1.0F);

            for(double iy=(fy/2.0F); iy<360.0F; iy+=fy)
            {



                    float appx1,appy1,appz1;
                    appx1=sin(iy * 3.1415F /180.0F)*m_raggioy;
                    appz1=cos(iy * 3.1415F /180.0F)*m_raggioy;
                    appy1=0.0F;

           //         glGetFloatv(GL_MODELVIEW_MATRIX,mat);
                    m[0]=appx1;
                    m[1]=appy1;
                    m[2]=appz1;
                    m[3]=1.0F;

                    matmult(mat,m);

                    newmesh->addvertex(m[0],m[1],m[2]);


            }
          //  glPopMatrix();



    }


   // glPopMatrix();

            // creazione dei poligoni
            int start=0;
            int end=m_uvy;

            for(int x=0; x <m_uvx-1; x++)
            {
                    int v1,v2,v3,v4;
                    int sapp=start;
                    int eapp=end;
                    for(int y=0; y < m_uvy-1; y++)
                    {


                            v1=start;
                            v2=end;
                            v3=start+1;
                            v4=end+1;

                            newmesh->addquad(v1,v2,v3,v4,abcdCW);

                            start++;
                            end++;


                    }
                    v1=start;
                    v2=end;
                    v3=sapp;
                    v4=eapp;
                    newmesh->addquad(v1,v2,v3,v4,abcdCW);

                    start++;
                    end++;

            }
            start=newmesh->_vertex.size()-m_uvy;
            end=0;
            int sapp=start;
            int eapp=end;
            int v1,v2,v3,v4;
            for(int y=0; y < m_uvy-1; y++)
            {


                    v1=start;
                    v2=end;
                    v3=start+1;
                    v4=end+1;

                    newmesh->addquad(v1,v2,v3,v4,abcdCW);

                    start++;
                    end++;


            }
            v1=start;
            v2=end;
            v3=sapp;
            v4=eapp;

            newmesh->addquad(v1,v2,v3,v4,abcdCW);

        newmesh->next=NULL;
        newmesh->prev=NULL;

        add(newmesh);

}
void l3d_mesh::create_logo(l3d_float* par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;



    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();

    newmesh->setname("logo",_icount++);
    newmesh->_sub_name="logo object";



    float r=5.0F;
    float r1=1.5F;

    if(par!=NULL)
    {
        r=*par++;
        r1=*par;
    }



    newmesh->addvertex(-r,0.0F,0.0F);
    newmesh->addvertex(0.0F,0.0F,r);
    newmesh->addvertex(r,0.0F,0.0F);
    newmesh->addvertex(0.0F,0.0F,-r);

    newmesh->addvertex(-r1,0.0F,r1);
    newmesh->addvertex(-r1,0.0F,-r1);
    newmesh->addvertex(r1,0.0F,r1);
    newmesh->addvertex(r1,0.0F,-r1);

    newmesh->addvertex(0.0F,1.0F,0.0F);
    newmesh->addvertex(0.0F,-1.0F,0.0F);




    newmesh->addface3(0,4,8,true,abcCW);

    newmesh->addface3(0,8,5,true,abcCW);

    newmesh->addface3(1,8,4,true,abcCW);

    newmesh->addface3(1,6,8,true,abcCW);

    newmesh->addface3(2,8,6,true,abcCW);

    newmesh->addface3(2,7,8,true,abcCW);

    newmesh->addface3(3,5,8,true,abcCW);

    newmesh->addface3(3,8,7,true,abcCW);

    newmesh->addface3(0,9,4,true,abcCW);

    newmesh->addface3(0,5,9,true,abcCW);

    newmesh->addface3(1,4,9,true,abcCW);

    newmesh->addface3(1,9,6,true,abcCW);

    newmesh->addface3(2,6,9,true,abcCW);

    newmesh->addface3(2,9,7,true,abcCW);

    newmesh->addface3(3,9,5,true,abcCW);

    newmesh->addface3(3,7,9,true,abcCW);

    newmesh->next=NULL;
    newmesh->prev=NULL;
    add(newmesh);


}

void l3d_mesh::matmult(GLfloat M[16], GLfloat v[4])
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
void l3d_mesh::create(l3d_mesh_type _type,l3d_float* par)
{





    switch(_type)
    {
        case mesh_null:
            create_null();



        break;
        case mesh_line:

            create_line(par);





        break;
        case mesh_circle:
            create_circle(par);

        break;

        case mesh_plane:
            create_plane(par);
        break;
        case mesh_disck:
            create_disck(par);
        break;

        case mesh_cube:
            create_cube(par);

        break;
        case mesh_cone:
            create_cone(par);
        break;
        case mesh_tube:
            create_cylinder(par);
        break;
        case mesh_tube_n:
            create_cylindern(par);
        break;
        case mesh_sphereuv:
            create_sphereuv(par);
        break;
        case mesh_torus:
            create_torus(par);
        break;

        case mesh_logo:
            create_logo(par);
        break;

    }




}
void l3d_mesh::delete_vbo(pl3d_mesh_struct _e)
{
    l3d_uint n=find(_e);
    if(n!=-1 && _e->_vbo)
        delete_vbo(n);
}

void l3d_mesh::delete_vbo(l3d_uint _e)
{
    pl3d_mesh_struct mesh=find(_e);

    if(mesh==NULL )
        return;
    if( mesh->_vbo==l3d_null)
        return;

    l3d_vertexbufferobject *vbo=mesh->_vbo;

    vbo->clean();



}
void l3d_mesh::create_vao(l3d_uint _e)
{


    pl3d_mesh_struct mesh=find(_e);
    if(mesh==NULL)
    {

        mesh->_vao=l3d_null;
        return;
    }
    l3d_uint size=mesh->_vertex.size();

    if(size==0)
    {

        mesh->_vao=l3d_null;
        return;

    }


    l3d_uint size_index=mesh->_edges.size();

    l3d_uint size_index_face=mesh->_faces.size();

    l3d_uint size_index_quad=mesh->_quad.size();

    l3d_vetexarrayobject *vao=new l3d_vetexarrayobject;

    vao->_elementvbo=NULL;
    vao->_elementedge=NULL;
    vao->_elementface=NULL;
    vao->_elementquad=NULL;
    vao->_elementvert=NULL;


    vao->_elementvbo= new l3d_vertexbufferobjectVAO;
    vao->_elementvbo->setlenght(sizeof(l3d_float));
    vao->_elementvbo->setsize(size);

    vao->_elementvert= new l3d_vertexbufferobjectVAO;
    vao->_elementvert->setlenght(sizeof(l3d_uint));
    vao->_elementvert->setsize(size);


    //vbo->_vbosize=size; ?? da inserire?

    if(size_index>0)
    {
        vao->_elementedge= new l3d_vertexbufferobjectVAO;
        vao->_elementedge->setlenght(sizeof(l3d_uint));
        vao->_elementedge->setsize  (size_index  *  2);

    }



    if(size_index_face>0)
    {
        vao->_elementface=new l3d_vertexbufferobjectVAO;
        vao->_elementface->setlenght(sizeof(l3d_uint));
        vao->_elementface->setsize (size_index_face  *  3);

    }
    if(size_index_quad>0)
    {
        vao->_elementquad=new l3d_vertexbufferobjectVAO;
        vao->_elementquad->setlenght(sizeof(l3d_uint));
        vao->_elementquad->setsize (size_index_quad  *  4);
    }








    //vbo->_linesize=size_index;


    l3d_float* first=(l3d_float*)vao->_elementvbo->getbuffer();

    //vbo->_index=new l3d_uint[size_index*2];


    l3d_uint * pvert=(l3d_uint *)vao->_elementvert->getbuffer();

    l3d_uint * pedge;
    l3d_uint * pface;
    l3d_uint * pquad;

    if(vao->_elementedge!=NULL)
        pedge=(l3d_uint *)vao->_elementedge->getbuffer();

    if(vao->_elementface!=NULL)
        pface=(l3d_uint *)vao->_elementface->getbuffer();

    if(vao->_elementquad!=NULL)
        pquad=(l3d_uint *)vao->_elementquad->getbuffer();
    int ix=0;
    pl3d_vertex_fast v=mesh->_vertex.find(ix);
    while(v)
    {


        *pvert++=ix;

        *first++=v->x;
        *first++=v->y;
        *first++=v->z;

        ix++;
        v=v->next;
    }

    for(int ix=0; ix < size_index;ix++)
    {
        pl3d_line_struct  l=mesh->_edges.find(ix);

        *pedge++=l->v0;
        *pedge++=l->v1;
    }
    for(int ix=0; ix < size_index_face;ix++)
    {
        pl3d_face3_struct f=mesh->_faces.find(ix);

        if(mesh->_display->invert)

        {

            *pface++=f->v0;
            *pface++=f->v1;
            *pface++=f->v2;

        }

        else
        {
            *pface++=f->v0;
            *pface++=f->v2;
            *pface++=f->v1;

        }

    }
    pl3d_face4_struct q=mesh->_quad.first();
    while(q)
    {
        *pquad++=q->get(0);
        *pquad++=q->get(1);
        *pquad++=q->get(2);
        *pquad++=q->get(3);

        q=q->next;
    }
    vao->load();

    //vbo->_elementvbo->create_sub(buffer_array,usage_dynamic_draw);

   // vbo->_elementvert->create(buffer_element_array,usage_static_draw);

    //if(vbo->_elementedge!=NULL)
    //    vbo->_elementedge->create(buffer_element_array,usage_static_draw);

    //if(vbo->_elementface!=NULL)
    //    vbo->_elementface->create(buffer_element_array,usage_static_draw);

    /*
    glBindBuffer(buffer_array, 0);

    glGenBuffers(1, &vbo->_idindex);

    glBindBuffer(buffer_element_array,vbo->_idindex);

    glBufferData(buffer_element_array, sizeof(l3d_uint)*size_index*2, NULL, usage_static_draw);

    glBufferSubData(buffer_element_array, 0, sizeof(l3d_uint)*size_index*2, vbo->_index);

    glBindBuffer(buffer_element_array, 0);

    */

    //delete vbo->_index;

    mesh->_vao=vao;

}
void l3d_mesh::create_vao(pl3d_mesh_struct m)
{

    pl3d_mesh_struct mesh=m;

    if(mesh==NULL)
        return;
    l3d_uint size=mesh->_vertex.size();
    if(size==0)
        {

        mesh->_vbo=l3d_null;
        return;

    }


    l3d_uint size_index=mesh->_edges.size();

    l3d_uint size_index_face=mesh->_faces.size();

    l3d_vertexbufferobject *vbo=new l3d_vertexbufferobject;

    vbo->_elementvbo=NULL;
    vbo->_elementedge=NULL;
    vbo->_elementface=NULL;
    vbo->_elementquad=NULL;
    vbo->_elementvert=NULL;


    vbo->_elementvbo= new l3d_bufferobject;
    vbo->_elementvbo->setlenght(sizeof(l3d_VBO_element));
    vbo->_elementvbo->setsize(size);

    vbo->_elementvert= new l3d_bufferobject;
    vbo->_elementvert->setlenght(sizeof(l3d_uint));
    vbo->_elementvert->setsize(size);


    vbo->_vbosize=size;

    if(size_index>0)
    {
        vbo->_elementedge= new l3d_bufferobject;
        vbo->_elementedge->setlenght(sizeof(l3d_uint));
        vbo->_elementedge->setsize  (size_index  *  2);

    }



    if(size_index_face>0)
    {
        vbo->_elementface=new l3d_bufferobject;
        vbo->_elementface->setlenght(sizeof(l3d_uint));
        vbo->_elementface->setsize (size_index_face  *  3);

    }








    //vbo->_linesize=size_index;


    pl3d_VBO_element first=(pl3d_VBO_element)vbo->_elementvbo->getbuffer();

    //vbo->_index=new l3d_uint[size_index*2];


    l3d_uint * pvert=(l3d_uint *)vbo->_elementvert->getbuffer();

    l3d_uint * pedge;
    l3d_uint * pface;

    if(vbo->_elementedge!=NULL)
        pedge=(l3d_uint *)vbo->_elementedge->getbuffer();

    if(vbo->_elementface!=NULL)
        pface=(l3d_uint *)vbo->_elementface->getbuffer();

    for(int ix=0; ix < size;ix++)
    {
        pl3d_vertex_fast v=mesh->_vertex.find(ix);

        *pvert++=ix;

        first->location[0]=v->x;
        first->location[1]=v->y;
        first->location[2]=v->z;

        first->tex[0]=v->u;
        first->tex[1]=v->v;

        first->normal[0]=v->normals[0];
        first->normal[1]=v->normals[1];
        first->normal[2]=v->normals[2];

        first->color[0]=0.5F;
        first->color[1]=0.5F;
        first->color[2]=0.5F;
        first->color[3]=1.0F;

        first->imaterial=0;

        *first++;
    }

    for(int ix=0; ix < size_index;ix++)
    {
        pl3d_line_struct  l=mesh->_edges.find(ix);

        *pedge++=l->v0;
        *pedge++=l->v1;
    }
    for(int ix=0; ix < size_index_face;ix++)
    {
        pl3d_face3_struct f=mesh->_faces.find(ix);
        if(mesh->_display->invert)

        {

            *pface++=f->v0;
            *pface++=f->v1;
            *pface++=f->v2;

        }

        else
        {
            *pface++=f->v0;
            *pface++=f->v2;
            *pface++=f->v1;

        }




    }

    vbo->_elementvbo->create_sub(buffer_array,usage_static_draw);

    vbo->_elementvert->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementedge!=NULL)
        vbo->_elementedge->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementface!=NULL)
        vbo->_elementface->create(buffer_element_array,usage_static_draw);

     mesh->_vbo=vbo;

}
void l3d_mesh::create_vbo(l3d_uint _e)
{

    /* example vbo

    geometry = new GLfloat[8*num_geometry];
    indices = new GLuint[num_indices];

    /* Fill geometry: 0, 1, 2 = vertex_xyz
    *                3, 4, 5 = normal_xyz
    *                6, 7 = tex_coord_uv
    */
    /*
    glGenBuffers(1, &geometry_array);
    glBindBuffer(GL_ARRAY_BUFFER, geometry_array);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*8*num_geometry, NULL, GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*8*num_geometry, geometry);

    glGenBuffers(1, &indice_array);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indice_array);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*num_indices, NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint)*num_indices, indices);
    */
    pl3d_mesh_struct mesh=find(_e);
    if(mesh==NULL)
        return;
    l3d_uint size=mesh->_vertex.size();
    if(size==0)
        {

        mesh->_vbo=l3d_null;
        return;

    }


    l3d_uint size_index=mesh->_edges.size();

    l3d_uint size_index_face=mesh->_faces.size();

    l3d_vertexbufferobject *vbo=new l3d_vertexbufferobject;

    vbo->_elementvbo=NULL;
    vbo->_elementedge=NULL;
    vbo->_elementface=NULL;
    vbo->_elementquad=NULL;
    vbo->_elementvert=NULL;


    vbo->_elementvbo= new l3d_bufferobject;
    vbo->_elementvbo->setlenght(sizeof(l3d_VBO_element));
    vbo->_elementvbo->setsize(size);

    vbo->_elementvert= new l3d_bufferobject;
    vbo->_elementvert->setlenght(sizeof(l3d_uint));
    vbo->_elementvert->setsize(size);


    vbo->_vbosize=size;

    if(size_index>0)
    {
        vbo->_elementedge= new l3d_bufferobject;
        vbo->_elementedge->setlenght(sizeof(l3d_uint));
        vbo->_elementedge->setsize  (size_index  *  2);

    }



    if(size_index_face>0)
    {
        vbo->_elementface=new l3d_bufferobject;
        vbo->_elementface->setlenght(sizeof(l3d_uint));
        vbo->_elementface->setsize (size_index_face  *  3);

    }








    //vbo->_linesize=size_index;


    pl3d_VBO_element first=(pl3d_VBO_element)vbo->_elementvbo->getbuffer();

    //vbo->_index=new l3d_uint[size_index*2];


    l3d_uint * pvert=(l3d_uint *)vbo->_elementvert->getbuffer();

    l3d_uint * pedge;
    l3d_uint * pface;

    if(vbo->_elementedge!=NULL)
        pedge=(l3d_uint *)vbo->_elementedge->getbuffer();

    if(vbo->_elementface!=NULL)
        pface=(l3d_uint *)vbo->_elementface->getbuffer();

    int ix=0;
    pl3d_vertex_fast v=mesh->_vertex.find(ix);
    while(v)
    {


        *pvert++=ix;

        first->location[0]=v->x;
        first->location[1]=v->y;
        first->location[2]=v->z;

        first->tex[0]=v->u;
        first->tex[1]=v->v;

        first->normal[0]=v->normals[0];
        first->normal[1]=v->normals[1];
        first->normal[2]=v->normals[2];

        first->color[0]=0.5F;
        first->color[1]=0.5F;
        first->color[2]=0.5F;
        first->color[3]=1.0F;

        first->imaterial=0;

        *first++;

        ix++;
        v=v->next;
    }

    for(int ix=0; ix < size_index;ix++)
    {
        pl3d_line_struct  l=mesh->_edges.find(ix);

        *pedge++=l->v0;
        *pedge++=l->v1;
    }
    for(int ix=0; ix < size_index_face;ix++)
    {
        pl3d_face3_struct f=mesh->_faces.find(ix);

        if(mesh->_display->invert)

        {

            *pface++=f->v0;
            *pface++=f->v1;
            *pface++=f->v2;

        }

        else
        {
            *pface++=f->v0;
            *pface++=f->v2;
            *pface++=f->v1;

        }

    }

    vbo->_elementvbo->create_sub(buffer_array,usage_dynamic_draw);

    vbo->_elementvert->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementedge!=NULL)
        vbo->_elementedge->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementface!=NULL)
        vbo->_elementface->create(buffer_element_array,usage_static_draw);

    /*
    glBindBuffer(buffer_array, 0);

    glGenBuffers(1, &vbo->_idindex);

    glBindBuffer(buffer_element_array,vbo->_idindex);

    glBufferData(buffer_element_array, sizeof(l3d_uint)*size_index*2, NULL, usage_static_draw);

    glBufferSubData(buffer_element_array, 0, sizeof(l3d_uint)*size_index*2, vbo->_index);

    glBindBuffer(buffer_element_array, 0);

    */

    //delete vbo->_index;

    mesh->_vbo=vbo;

}
void l3d_mesh::create_vbo(pl3d_mesh_struct m)
{

    pl3d_mesh_struct mesh=m;

    if(mesh==NULL)
        return;
    l3d_uint size=mesh->_vertex.size();
    if(size==0)
        {

        mesh->_vbo=l3d_null;
        return;

    }


    l3d_uint size_index=mesh->_edges.size();

    l3d_uint size_index_face=mesh->_faces.size();

    l3d_vertexbufferobject *vbo=new l3d_vertexbufferobject;

    vbo->_elementvbo=NULL;
    vbo->_elementedge=NULL;
    vbo->_elementface=NULL;
    vbo->_elementquad=NULL;
    vbo->_elementvert=NULL;


    vbo->_elementvbo= new l3d_bufferobject;
    vbo->_elementvbo->setlenght(sizeof(l3d_VBO_element));
    vbo->_elementvbo->setsize(size);

    vbo->_elementvert= new l3d_bufferobject;
    vbo->_elementvert->setlenght(sizeof(l3d_uint));
    vbo->_elementvert->setsize(size);


    vbo->_vbosize=size;

    if(size_index>0)
    {
        vbo->_elementedge= new l3d_bufferobject;
        vbo->_elementedge->setlenght(sizeof(l3d_uint));
        vbo->_elementedge->setsize  (size_index  *  2);

    }



    if(size_index_face>0)
    {
        vbo->_elementface=new l3d_bufferobject;
        vbo->_elementface->setlenght(sizeof(l3d_uint));
        vbo->_elementface->setsize (size_index_face  *  3);

    }








    //vbo->_linesize=size_index;


    pl3d_VBO_element first=(pl3d_VBO_element)vbo->_elementvbo->getbuffer();

    //vbo->_index=new l3d_uint[size_index*2];


    l3d_uint * pvert=(l3d_uint *)vbo->_elementvert->getbuffer();

    l3d_uint * pedge;
    l3d_uint * pface;

    if(vbo->_elementedge!=NULL)
        pedge=(l3d_uint *)vbo->_elementedge->getbuffer();

    if(vbo->_elementface!=NULL)
        pface=(l3d_uint *)vbo->_elementface->getbuffer();

    for(int ix=0; ix < size;ix++)
    {
        pl3d_vertex_fast v=mesh->_vertex.find(ix);

        *pvert++=ix;

        first->location[0]=v->x;
        first->location[1]=v->y;
        first->location[2]=v->z;

        first->tex[0]=v->u;
        first->tex[1]=v->v;

        first->normal[0]=v->normals[0];
        first->normal[1]=v->normals[1];
        first->normal[2]=v->normals[2];

        first->color[0]=0.5F;
        first->color[1]=0.5F;
        first->color[2]=0.5F;
        first->color[3]=1.0F;

        first->imaterial=0;

        *first++;
    }

    for(int ix=0; ix < size_index;ix++)
    {
        pl3d_line_struct  l=mesh->_edges.find(ix);

        *pedge++=l->v0;
        *pedge++=l->v1;
    }
    for(int ix=0; ix < size_index_face;ix++)
    {
        pl3d_face3_struct f=mesh->_faces.find(ix);
        if(mesh->_display->invert)

        {

            *pface++=f->v0;
            *pface++=f->v1;
            *pface++=f->v2;

        }

        else
        {
            *pface++=f->v0;
            *pface++=f->v2;
            *pface++=f->v1;

        }




    }

    vbo->_elementvbo->create_sub(buffer_array,usage_static_draw);

    vbo->_elementvert->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementedge!=NULL)
        vbo->_elementedge->create(buffer_element_array,usage_static_draw);

    if(vbo->_elementface!=NULL)
        vbo->_elementface->create(buffer_element_array,usage_static_draw);

     mesh->_vbo=vbo;

}
void l3d_mesh::draw_vbo(l3d_vertexbufferobject* vbo)
{
    if(vbo==l3d_null)
        return;

    if(vbo->_elementvbo!=NULL)
        vbo->_elementvbo->bind();


    //if(vbo->_elementvert!=NULL)
    //    vbo->_elementvert->bind();

    //if(vbo->_elementedge!=NULL)
    //    vbo->_elementedge->bind();

    if(vbo->_elementface!=NULL)
        vbo->_elementface->bind();

    //glBindBuffer(buffer_element_array, vbo->_idindex);

 //   glEnableClientState(cap_texture_coord);
//    glEnableClientState(cap_normal);
//    glEnableClientState(cap_vertex);

//    glTexCoordPointer(3, GL_FLOAT, sizeof(l3d_VBO_element) , (float*)(sizeof(l3d_glfloat)*3));
//    glNormalPointer(GL_FLOAT, sizeof(l3d_VBO_element) , (float*)(sizeof(l3d_glfloat)*5));
    //glVertexPointer(3, GL_FLOAT, sizeof(l3d_VBO_element) , NULL);

    //if(vbo->_elementvert!=NULL)
    //    glDrawElements(GL_POINTS,  vbo->_elementvert->size() , GL_UNSIGNED_INT, NULL);
   // if(vbo->_elementface!=NULL)
   //     glDrawElements(GL_TRIANGLES,  vbo->_elementface->size() , GL_UNSIGNED_INT, NULL);


  //  glDisableClientState(cap_vertex);
  //  glDisableClientState(cap_normal);
  //  glDisableClientState(cap_texture_coord);

    //glBindBuffer(buffer_array, 0);
    //glBindBuffer(buffer_element_array, 0);



}
void l3d_mesh::draw_edit(l3d_uint  n)
{
    pl3d_mesh_struct m=find(n);

    if(m)
        draw_edit(m);
}

void l3d_mesh::draw_edit(pl3d_mesh_struct  mesh)
{


       l3d_glfloat alpha=.4F;

       int nIndex=0;

//       glDisable(GL_CULL_FACE);
//       glDisable(GL_DEPTH_TEST);


//       if(mesh->_display->invert)
    //        glFrontFace(GL_CCW);
  //     else
 //           glFrontFace(GL_CW);


 //      glDisable(GL_LIGHTING);


       mesh->use_blend_edit();


 //      glMatrixMode(GL_MODELVIEW);


 //      glPushMatrix();


       mesh->_transformation.draw();


       pl3d_face4_struct face4;
       if (mesh->_quad.size()==0 && mesh->_faces.size()==0)
       {


           pl3d_line_struct pl=mesh->_edges.find(0);

           while( pl)
           {

  //             if (pl->selected())
  //                 glColor4f(0.0F,0.5F,1.0F,alpha);
  //             else
 //                  glColor4f(0.0F,0.5F,0.5F,alpha);

               l3d_uint v0,v1;
               pl3d_vertex_fast vp;
               v0=pl->v0;
               v1=pl->v1;



  //             glBegin(GL_LINES);

                vp=mesh->_vertex.find(v0);

 //               glVertex3f(vp->x,vp->y,vp->z);

                vp=mesh->_vertex.find(v1);

 //               glVertex3f(vp->x,vp->y,vp->z);




   //            glEnd();


               pl=pl->next;

           }


       }

       if (mesh->_quad.size()>0){

  //          glBegin(GL_QUADS);

            l3d_uint ix=0;
            face4=mesh->_quad.find(ix);

            while (face4 )
            {


                if(face4->_erase)
                {
                    face4=face4->next;
                    ix++;
                    continue;
                }


                l3d_bool ccw=false;
                l3d_uint a,b,c,d;

                switch(face4->_insert)
                {
                case abcdCW:
                    a=face4->_v0;
                    b=face4->_v1;
                    c=face4->_v2;
                    d=face4->_v3;
                    break;
                case abdcCW:
                    a=face4->_v0;
                    b=face4->_v1;
                    d=face4->_v2;
                    c=face4->_v3;
                    break;
                case abcdCCW:
                    a=face4->_v0;
                    b=face4->_v1;
                    c=face4->_v2;
                    d=face4->_v3;
                    ccw=true;
                    break;
                case abdcCCW:
                    a=face4->_v0;
                    b=face4->_v1;
                    d=face4->_v2;
                    c=face4->_v3;
                    ccw=true;
                    break;

                }




     //           glColor4f(0.0F,1.0F,0.5F,alpha);


     //           if (face4->_selected)

     //               glColor4f(0.0F,0.5F,1.0F,alpha);

    //            else

     //               glColor4f(0.0F,0.5F,0.5F,alpha);





                pl3d_vertex_fast appv;






                if(!ccw)
                    {
                        //d----c
                        //|    |
                        //|    |
                        //a----b
                        //cw:  d,c,b,a

                        appv=mesh->_vertex.find(d);

     //                   glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(c);

     //                   glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(b);

     //                   glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(a);

     //                   glVertex3f(appv->x,appv->y,appv->z);


                    }


                else
                    {
                        //d----c
                        //|    |
                        //|    |
                        //a----b
                       //cw:  d,c,b,a
                        //ccw: a,b,c,d

                        appv=mesh->_vertex.find(a);

   //                     glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(b);

  //                      glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(c);

    //                    glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(d);

     //                   glVertex3f(appv->x,appv->y,appv->z);



                    }








                ix++;
                face4=face4->next;

            }
      //      glEnd();

            ix=0;
            face4=mesh->_quad.find(ix);

     //       glBegin(GL_LINES);
            {
            pl3d_vertex_fast appv;
            while (face4 )
            {
                if(face4->_erase)
                {
                    face4=face4->next;
                    ix++;
                    continue;
                }
                pl3d_line_struct l0,l1,l2,l3;

      //          glLineWidth(2.0F);


                    l0=face4->_l0;
                    l1=face4->_l1;
                    l2=face4->_l2;
                    l3=face4->_l3;

                    if(!l0->erase)
                    {
 //                       if(l0->selected())
  //                          glColor4f(0.0F,1.0F,1.0F,alpha);
  //                      else
  //                          glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l0->_v0;
//                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l0->_v1;
 //                       glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l1->erase)
                    {
  //                      if(l1->selected())
  //                          glColor4f(0.0F,1.0F,1.0F,.2F);
  //                      else
  //                          glColor4f(0.0F,0.0F,0.0F,.2F);




                        appv=l1->_v0;
//                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l1->_v1;
//                        glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l2->erase)
                    {
  //                      if(l2->selected())
  //                          glColor4f(0.0F,1.0F,1.0F,alpha);
  //                      else
  //                          glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l2->_v0;
//                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l2->_v1;
//                        glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l3->erase)
                    {
                        //if(l3->selected())
                           // glColor4f(0.0F,1.0F,1.0F,alpha);
                       // else
                       //     glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l3->_v0;
                      //  glVertex3f(appv->x,appv->y,appv->z);
                        appv=l3->_v1;
                     //   glVertex3f(appv->x,appv->y,appv->z);


                    }






                face4=face4->next;
                ix++;


            }
            }//glEnd();


        }





         if (mesh->_faces.size()>0)
        {

           // glBegin(GL_TRIANGLES);
            nIndex=0;
            pl3d_face3_struct face=mesh->_faces.find(nIndex);



            while(face)
            //for ( nIndex=0 ; nIndex < mesh->_faces.size() ; nIndex++ )
            {
                if(!face->_alone)
                {
                    face=face->next;
                    continue;
                }

                pl3d_vertex_fast app1,app2,app3;


                if( face->_erase || !face->_alone)
                {
                    nIndex++;
                    face=face->next;
                    continue;

                }


                l3d_uint a,b,c;
                l3d_bool ccw=false;
                switch(face->_insert)
                {
                case abcCW:
                    a=face->v0;
                    b=face->v1;
                    c=face->v2;

                    break;
                case abcCCW:
                    a=face->v0;
                    b=face->v2;
                    c=face->v1;
                    ccw=true;

                    break;
                }



            //    glColor4f(0.0F,1.0F,0.5F,alpha);

           //     if (face->_selected)
           //         glColor4f(0.0F,0.5F,1.0F,alpha);
           //     else
           //         glColor4f(0.0F,0.5F,0.5F,alpha);

                if(!ccw)
                {
                    app1=mesh->_vertex.find(a);
                    app2=mesh->_vertex.find(c);
                    app3=mesh->_vertex.find(b);

                }
                else
                {
                    app1=mesh->_vertex.find(a);
                    app2=mesh->_vertex.find(b);
                    app3=mesh->_vertex.find(c);

                }





                if(app1 && app2 && app3)
                {

           //         glVertex3f(app1->x,app1->y,app1->z);
//
           //         glVertex3f(app2->x,app2->y,app2->z);

           //         glVertex3f(app3->x,app3->y,app3->z);

                }












                nIndex++;
                face=face->next;
           //     glLineWidth(2.0F);


            }
          //  glEnd();





        }





        l3d_uint ip=0;

        pl3d_vertex_fast vert=mesh->_vertex.find(ip);
//
     //   glPointSize(2.0F);

     //   glBegin(GL_POINTS);
        while(vert)
        {


            if( vert->erase)
            {
                ip++;

                vert=vert->next;

                continue;                
            }


                //glPushMatrix();


        //        if(vert->_selected)
        //            glColor4f(1.0F,0.0F,0.0F,alpha);
        //        else
        //            glColor4f(1.0F,1.0F,0.0F,alpha);

        //        glVertex3f(vert->x,vert->y,vert->z);





                //glPopMatrix();
                ip++;
                vert=vert->next;



        }

        //glEnd();

        //glPopMatrix();
        //glPointSize(1.0F);




        //glEnable(GL_LIGHTING);
        //glDisable(GL_BLEND);

       // glEnable(GL_CULL_FACE);
       /// glEnable(GL_DEPTH_TEST);


}
void l3d_mesh::draw_vbo(pl3d_mesh_struct  m,SCENE::ModeDraw md)
{

/*
    glEnable(GL_DEPTH_TEST);

    if(mesh->_display->invert)
         glFrontFace(GL_CCW);
    else
         glFrontFace(GL_CW);

    glEnable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();


    if (mesh->_rotate.x>360) mesh->_rotate.x-=360;
    if (mesh->_rotate.y>360) mesh->_rotate.y-=360;
    if (mesh->_rotate.z>360) mesh->_rotate.z-=360;

    if(! mesh->_display->inmove)
        glTranslatef(mesh->_wp.x,mesh->_wp.y,mesh->_wp.z);
    else
        glTranslatef(mesh->_wp2.x,mesh->_wp2.y,mesh->_wp2.z);

    glRotatef(mesh->_rotate.x,1.0,0.0,0.0);
    glRotatef(mesh->_rotate.y,0.0,1.0,0.0);
    glRotatef(mesh->_rotate.z,0.0,0.0,1.0);
    glScalef( mesh->_scale.x, mesh->_scale.y, mesh->_scale.z);
    */
    if(m==l3d_null)
        return;
    if(m->_vbo==l3d_null)
        return;
  //  if(m->_display->invert)
  //       glFrontFace(GL_CCW);
  //  else
  //       glFrontFace(GL_CW);

    if(m->blend())
        m->use_blend();

 //   glEnable(GL_CULL_FACE);
 //   glEnable(GL_DEPTH_TEST);

//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();


    m->_transformation.draw();




  //  if( m->_display->smooth)
 //       glShadeModel(GL_SMOOTH);
 //   else
 //       glShadeModel(GL_FLAT);


    // Bind our buffers much like we would for texturing
    if(m->_vbo->_elementvbo!=NULL)
        m->_vbo->_elementvbo->bind();


    // Set the state of what we are drawing (I don't think order matters here, but I like to do it in the same
    // order I set the pointers


//    glEnableClientState(cap_texture_coord);
//    glEnableClientState(cap_color);
//    glEnableClientState(cap_normal);
//    glEnableClientState(cap_vertex);

//    glTexCoordPointer(3, GL_FLOAT, sizeof(l3d_VBO_element) , (float*)(sizeof(l3d_glfloat)*3));
//    glColorPointer(4,GL_FLOAT,sizeof(l3d_VBO_element),(float*)(sizeof(l3d_glfloat)*8));
//    glNormalPointer(GL_FLOAT, sizeof(l3d_VBO_element) , (float*)(sizeof(l3d_glfloat)*5));
//    glVertexPointer(3, GL_FLOAT, sizeof(l3d_VBO_element) , NULL);



    float val[]={0.5F,0.5F,0.5F,1.0F};
    float valsel[]={0.2F,0.2F,1.0F,1.0F};
    float val1[]={0.0F,0.0F,0.0F,1.0F};
    l3d_material_struct mat,matsel;

    for(int ix=0; ix < 4; ix++)
    {
        mat.mat_ambient[ix]=val[ix];
        matsel.mat_ambient[ix]=valsel[ix];

        mat.mat_diffuse[ix]=val[ix];
        matsel.mat_diffuse[ix]=valsel[ix];

        mat.mat_specular[ix]=val[ix];
        matsel.mat_specular[ix]=valsel[ix];

        mat.mat_emission[ix]=val1[ix];
        matsel.mat_emission[ix]=val1[ix];

    }


    if(md==SCENE::wireframe)
    {
        //glDisable(GL_LIGHTING);

        //glColor4f(0.4F,0.4F,0.4F,1.0F);

        if(!m->_pick._selected)
            mat.set();
        else
            //glEnable(GL_LIGHTING);
            matsel.set();

//        glPointSize(2.0F);

        if(m->_vbo->_elementvert!=NULL)
            m->_vbo->_elementvert->draw(draw_points);

        if(m->_vbo->_elementedge!=NULL)
            m->_vbo->_elementedge->draw(draw_lines);


        //glEnable(GL_LIGHTING);

    }
    if(md==SCENE::solid)
    {

  //      glDisable(GL_LIGHTING);

   //     if(!m->selected())
  //          glColor4f(0.2F,0.2F,1.0F,1.0F);
  //      else
  //          glColor4f(0.5F,0.5F,0.5F,1.0F);




        if(m->_vbo->_elementface==NULL)
        {
            if(m->_vbo->_elementedge!=NULL)
                m->_vbo->_elementedge->draw(draw_lines);

        }

        if(m->_vbo->_elementface!=l3d_null)
        {
            m->_vbo->_elementface->draw(draw_triangles);
        }

        //glEnable(GL_LIGHTING);

    }
    if(md==SCENE::color)
    {
        //aggiungere codice per i materiali to-do

        m->_material.use();

        //if(m->_pick.selected())
        //    matsel.set();

        //m->_material.set(1);

        if(m->_vbo->_elementface==NULL)
        {
            if(m->_vbo->_elementedge!=NULL)
                m->_vbo->_elementedge->draw(draw_lines);

        }

        if(m->_vbo->_elementface!=l3d_null)
        {
            m->_vbo->_elementface->draw(draw_triangles);
        }

    }


//    glDisableClientState(cap_texture_coord);
//    glDisableClientState(cap_color);
//    glDisableClientState(cap_normal);
//    glDisableClientState(cap_vertex);



 //   glPopMatrix();

//    glDisable(GL_BLEND);

}

void l3d_mesh::draw_vbo(l3d_uint _e)
{

    pl3d_mesh_struct mesh=find(_e);
    if(mesh==NULL)
        return;

    draw_vbo(mesh,SCENE::wireframe);

}
void l3d_mesh::init_material(pl3d_mesh_struct _mesh)
{
    pl3d_material_struct _mat=new l3d_material_struct;

    float app[4]={0.5F,0.5F,0.5F,1.0F};

    for(int ix=0; ix < 4 ; ix++)
    {


        _mat->mat_ambient[ix]=app[ix];
        _mat->mat_diffuse[ix]=app[ix];

        _mat->mat_specular[ix]=app[ix];
        _mat->mat_emission[ix]=0.0F;

    }

    _mat->mat_emission[3]=1.0F;

    _mat->m_bambientanddiffuse=true;
    _mat->_mface=front;
    _mat->mat_shininess[0]=.5F;

    _mesh->_material.add(_mat);
    _mesh->_material.set(1);

    _mesh->blend(false);



}

l3d_uint l3d_mesh::size()
{
    return _nmeshes;
}
void l3d_mesh::setselected(l3d_uint _s)
{
    pl3d_mesh_struct ms=this->find(_s);
    ms->selected();
    _selected=ms;
    _iselected=_s;
}
pl3d_mesh_struct l3d_mesh::getselected()
{
    return _selected;
}
l3d_uint l3d_mesh::getiselected()
{
    return _iselected;
}
