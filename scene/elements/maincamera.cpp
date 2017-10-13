#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>
#include <GL/glu.h>

#include "math.h"

#include "mesh/vertex.h"

#include "scene/elements/telecamera.h"

#include "maincamera.h"

static float tb_project_to_sphere(float, float, float);
static void normalize_quat(float [4]);

maincamera::maincamera(void)
{
    alpha=beta=0.0F;

    m_bfree=false;


}

maincamera::maincamera(vertex npos,vertex pwhere)
{
        ::telecamera(npos,pwhere);



}

maincamera::maincamera(vertex movepos)
{
    m_bfree=false;

}



maincamera::~maincamera(void)
{
}
void maincamera::SetAngolo(float an[3])
{
        m_angolo[0]=an[0];
        m_angolo[1]=an[1];
        m_angolo[2]=an[2];
}
void maincamera::setfree(bool value)
{
    m_bfree=value;
}

void maincamera::SetTrackball(int oldx,int oldy)
{

}
void maincamera::Set(vertex pos,vertex pwhere,vertex pup)
{
        this->vpos=pos;
        this->vposwhere=pwhere;
        this->vposup=pup;

}
void maincamera::SetUp(float ux,float uy,float uz)
{
        this->vposup.SetVertex(ux,uy,uz);
}
void maincamera::Draw()
{
    glMatrixMode(GL_MODELVIEW);
    if(!m_bfree)
    {


        gluLookAt(vpos.GetX(),vpos.GetY(),vpos.GetZ(),vposwhere.GetX(),vposwhere.GetY(),vposwhere.GetZ(),vposup.GetX(),vposup.GetY(),vposup.GetZ());

       // glRotatef(alpha,0.0F,1.0F,0.0F);
       // glRotatef(beta ,1.0F,0.0F,0.0F);
       /* GLfloat m[4][4];

        build_rotmatrix( m, m_gldata.quat );

        glMultMatrixf( &m[0][0] );*/

    }
    else
    {
        telecamera::Updatefree();
        gluLookAt(vpos.GetX(),vpos.GetY(),vpos.GetZ(),vposwhere.GetX(),vposwhere.GetY(),vposwhere.GetZ(),vposup.GetX(),vposup.GetY(),vposup.GetZ());

    }



}
void maincamera::Draw(vertex p, vertex w, vertex u)
{
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(p.GetX(),p.GetY(),p.GetZ(),w.GetX(),w.GetY(),w.GetZ(),u.GetX(),u.GetY(),u.GetZ());



}


void maincamera::Update(float radius)
{

        float posx=vpos.GetX(),posy=vpos.GetY(),posz=vpos.GetZ();

        m_radius=radius;

        posx	=	cos(m_angolo[1]*3.1415f/180.0F)		*		cos(m_angolo[0]*3.1415f/180.0F)	*	radius;


        posy	=	cos(m_angolo[1]*3.1415f/180.0F)		*		sin(m_angolo[0]*3.1415f/180.0F)	*	radius;


        posz	=	sin(m_angolo[1]*3.1415f/180.0F)		*		radius;




        vpos.SetVertex(posx,posy,posz);

}
void maincamera::Update()
{
        Update(m_radius);
}
void maincamera::trackball(bool t)
{
    m_track.m_btrack=t;
}

void maincamera::TrackBall(int x, int y)
{
        //xSize sz(GetClientSize());

    float fval=1.0F;
    if(!m_btrack)
    {
        m_iposmouse[0]=x;
        m_iposmouse[1]=y;

    }
    else
    {
        if(x>m_iposmouse[0])
        {
             alpha+=fval;

             m_iposmouse[0]=x;
             m_iposmouse[1]=y;
             return;
        }
        else if(x<m_iposmouse[0])
        {
             alpha-=fval;

             m_iposmouse[0]=x;
             m_iposmouse[1]=y;
             return;
        }

        if(y>m_iposmouse[1])
        {
             beta+=fval;
             m_iposmouse[0]=x;
             m_iposmouse[1]=y;
             return;

        }
        else if(y<m_iposmouse[1])
        {
             beta-=fval;
             m_iposmouse[0]=x;
             m_iposmouse[1]=y;
             return;

        }



    }


    /* drag in progress, simulate trackball */

}

void maincamera::AddAngles(float an[3])
{
        m_angolo[0]+=an[0];
        m_angolo[1]+=an[1];
        m_angolo[2]+=an[2];
}

float maincamera::GetRadius(void)
{
    return m_radius;
}
void maincamera::InitTrackball(void)
{

}
