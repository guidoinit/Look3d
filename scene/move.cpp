#define GLEW_STATIC

#include <GL/glew.h>
#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "mesh/object3dinclude.h"

#include "move.h"


move::move()
{
        m_b2D=false;
        m_angolo[0]=0.0;
        m_angolo[1]=0.0;
        m_angolo[2]=0.0;

        m_nType=0;
        m_bSel=false;
        m_Worldpos.SetVertex(0.0F,0.0F,0.0F);

        int x=0;
        for(x=0; x < 6 ; x++)
                local_vertex.push_back(vertex());

        local_vertex[0].SetVertex(0.0F,  0.0F,  0.0F);
        local_vertex[1].SetVertex( 100.0F,  0.0F,   0.0F);
        local_vertex[2].SetVertex(0.0F,  0.0F,  0.0F);
        local_vertex[3].SetVertex( 0.0F, 100.0F  , 0.0F   );
        local_vertex[4].SetVertex(0.0F,  0.0F,  0.0F);
        local_vertex[5].SetVertex(0.0F,  0.0F,  100.0F);


}

move::~move()
{

}

void move::Draw(bool inmove)
{
        int nIndex=0;
        static int contav=0;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
//f (m_b2D)
        //	glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //glTranslatef(0.0,0.0,-5.0);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);



        glBegin(GL_LINES);

        glColor3f(0.0F,1.0F,0.0F);
        glVertex3f(local_vertex[0].GetX(),local_vertex[0].GetY(),local_vertex[0].GetZ());
        glVertex3f(local_vertex[1].GetX(),local_vertex[1].GetY(),local_vertex[1].GetZ());

        glColor3f(0.0F,0.0F,1.0F);
        glVertex3f(local_vertex[2].GetX(),local_vertex[2].GetY(),local_vertex[2].GetZ());
        glVertex3f(local_vertex[3].GetX(),local_vertex[3].GetY(),local_vertex[3].GetZ());

        glColor3f(1.0F,0.0F,0.0F);
        glVertex3f(local_vertex[4].GetX(),local_vertex[4].GetY(),local_vertex[4].GetZ());
        glVertex3f(local_vertex[5].GetX(),local_vertex[5].GetY(),local_vertex[5].GetZ());
        if(inmove)
        {

                glLineWidth(5.0F);
                //glPointSize(2.0F);
                glLineStipple(5	, 5);
                glColor3f(1.0f,1.0f,1.0f);

                glVertex3f(local_vertex[0].GetX(),local_vertex[0].GetY(),local_vertex[0].GetZ());

                glVertex3f(world_pos_app.GetX(),world_pos_app.GetY(),world_pos_app.GetZ());



        }
        glEnd();

        glPopMatrix();


}

void move::DrawSelect()
{
        int nIndex=0;
        static int contav=0;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
//f (m_b2D)
        //	glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //glTranslatef(0.0,0.0,-5.0);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);


        glLoadName(MOVES);
        glBegin(GL_LINES);

        glColor3f(1.0F,0.0F,0.0F);

        glVertex3f(local_vertex[0].GetX(),local_vertex[0].GetY(),local_vertex[0].GetZ());
        glVertex3f(local_vertex[1].GetX(),local_vertex[1].GetY(),local_vertex[1].GetZ());

        glEnd();


        glLoadName(MOVES+1);

        glBegin(GL_LINES);

        glColor3f(0.0F,1.0F,0.0F);
        glVertex3f(local_vertex[2].GetX(),local_vertex[2].GetY(),local_vertex[2].GetZ());
        glVertex3f(local_vertex[3].GetX(),local_vertex[3].GetY(),local_vertex[3].GetZ());

        glEnd();

        glLoadName(MOVES+2);

        glBegin(GL_LINES);

        glColor3f(0.0F,0.0F,1.0F);

        glVertex3f(local_vertex[4].GetX(),local_vertex[4].GetY(),local_vertex[4].GetZ());
        glVertex3f(local_vertex[5].GetX(),local_vertex[5].GetY(),local_vertex[5].GetZ());

        glEnd();

        glPopMatrix();

}
