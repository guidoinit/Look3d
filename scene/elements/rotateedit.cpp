#define GLEW_STATIC
#include <GL/glew.h>
#include <QtOpenGL>
#include <stdlib.h>
#include <math.h>



#include "mesh/object3dinclude.h"
#include "mesh/mesh3d/cone.h"

#include "scene/animation/frame.h"
#include "scene/animation/animate.h"
#include "rotateedit.h"



rotateedit::rotateedit(void)
    : m_radius(30.0F)
{

        m_max=10.0F;

        create();

}
void rotateedit::create()
{
    local_vertex.clear();
    m_line.clear();
    m_poly.clear();
    m_poly3.clear();
    m_poly4.clear();

    m_rot.local_vertex.clear();
    m_rot.m_line.clear();
    m_rot.m_poly.clear();
    m_rot.m_poly3.clear();
    m_rot.m_poly4.clear();

    float stepa=(float)(360.0F/(float)360.0F);

    float px,py,pz;

    vertex appv(0.0F,0.0F,0.0F);

    world_pos=appv;

    py=0.0F;
    float fdim=1.0F;
    for(float fx=0.0F; fx < 360.0F; fx+=stepa)
    {
        px=sin(fx/180.0F*3.1415F)*m_radius;
        pz=cos(fx/180.0F*3.1415F)*m_radius;

        appv.SetVertex(px,py-(fdim/2.0F),pz);

        m_rot.local_vertex.push_back(appv);


        appv.SetVertex(px,py+(fdim/2.0F),pz);

        m_rot.local_vertex.push_back(appv);

    }
    int v1,v2,v3,v4;

    v1=0;
    v2=1;
    v3=2;
    v4=3;

    for(float fx=0.0F; fx < 360.0F-stepa; fx+=stepa)
    {
        m_rot.AddPoligon(v1,v3,v2,v4);
        m_rot.AddPoligon(v3,v1,v4,v2);
        v1+=2;
        v3+=2;
        v2+=2;
        v4+=2;
    }
    //creare la linee

    //m_rot.AddPoligon(v1++,v3++,0,1);


    /*line appl;
    int startv=0;
    for(int ix=1;ix < m_rot.local_vertex.size(); ix++)
    {

        appl.SetLine(startv,ix);
        startv++;
        m_rot.m_line.push_back(appl);
    }
    appl.SetLine(0,local_vertex.size()-1);

    m_rot.m_line.push_back(appl);
    */

}

rotateedit::~rotateedit(void)
{
}

void rotateedit::Draw(bool inmove)
{

        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);

        //calcola la scala del puntatore in base a m_radius

        m_Scale[0]=1.0F;

        //qDebug() << "max:" <<m_max;

      //  if(m_max!=-1.0F);
      //      m_Scale[0]=(0.1F * m_max)+(1.0F/m_max);//m_radius/100.0F;


        glScalef(m_Scale[0],m_Scale[0],m_Scale[0]);


        m_rot.m_angolo[2]=0.0F;
        m_rot.m_angolo[1]=0.0F;
        m_rot.m_angolo[0]=0.0F;

        m_rot.SetColor(1.0F,0.0F,0.0F,1.0F);

        m_rot.DrawColor(true);


        m_rot.m_angolo[0]=90.0F;
        m_rot.m_angolo[1]=0.0F;
        m_rot.m_angolo[2]=0.0F;

        m_rot.SetColor(0.0F,1.0F,0.0F,1.0F);

        //m_rot.DrawLines();
        m_rot.DrawColor(true);

        m_rot.m_angolo[0]=90.0F;

        m_rot.m_angolo[1]=0.0F;

        m_rot.m_angolo[2]=90.0F;

        m_rot.SetColor(0.0F,0.0F,1.0F,1.0F);

        m_rot.DrawColor(true);

        //m_rot.DrawLines();

        glPopMatrix();

        glEnable(GL_LIGHTING);

}

void rotateedit::DrawSelect()
{
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    if (m_angolo[0]>360) m_angolo[0]-=360;
    if (m_angolo[1]>360) m_angolo[1]-=360;
    if (m_angolo[2]>360) m_angolo[2]-=360;

    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


    glRotatef(m_angolo[0],1.0,0.0,0.0);
    glRotatef(m_angolo[1],0.0,1.0,0.0);
    glRotatef(m_angolo[2],0.0,0.0,1.0);

    //calcola la scala del puntatore in base a m_radius

    m_Scale[0]=1.0F;//m_radius/100.0F;



    //if(m_max!=-1.0F)
    //   m_Scale[0]=(0.1F * m_max)+(1.0F/m_max);//m_radius/100.0F;


    glScalef(m_Scale[0],m_Scale[0],m_Scale[0]);

    float step=5.0F;

    m_rot.m_angolo[0]=90.0F;
    m_rot.m_angolo[1]=0.0F;
    m_rot.m_angolo[2]=0.0F;

    glLoadName(MOVES+2);

    //m_rot.SetColor(1.0F,0.0F,0.0F,1.0F);

    m_rot.DrawColor(false);


    m_rot.m_angolo[0]=0.0F;
    m_rot.m_angolo[2]=0.0F;
    m_rot.m_angolo[1]=90.0F;

    glLoadName(MOVES+1);


    m_rot.DrawColor(false);

    m_rot.m_angolo[0]=90.0F;
    m_rot.m_angolo[1]=0.0F;
    m_rot.m_angolo[2]=90.0F;

    glLoadName(MOVES);

    m_rot.DrawColor(false);

    glPopMatrix();

    glEnable(GL_LIGHTING);

}
void rotateedit::setmax(float m)
{
    m_max=m;
}
