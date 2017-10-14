//    This file is part of Look3D program.

//    Look3D is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Look3D is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
//
//

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/glu.h>
#include <math.h>

#include "./mesh/l3d_vertex.h"

#include "telecamera.h"


telecamera::telecamera(l3d_vertex_fast v)
{
        vpos=v;
        vposwhere.set(0.0F,0.0F,0.0F);
        vposup.set(0.0F,1.0F,0.0F);
        name=0;
        m_angolox=0.0F;
        m_angoloy=180.0F;
        selected=false;
}
telecamera::telecamera(l3d_vertex_fast v,l3d_vertex_fast w)
{
        vpos=v;
        vposwhere=w;
        vposup.set(0.0F,1.0F,0.0F);
        name=0;
        m_angolox=0.0F;
        m_angoloy=180.0F;
        selected=false;
}
telecamera::telecamera(l3d_vertex_fast v,l3d_vertex_fast w,l3d_vertex_fast u)
{
        vpos=v;
        vposwhere=w;
        vposup=u;
        name=0;
        m_angolox=0.0F;
        m_angoloy=180.0F;
        selected=false;
}
telecamera::telecamera(void)
{
        vposup.set(0.0F,1.0F,0.0F);
        name=0;
        m_angolox=0.0F;
        m_angoloy=180.0F;
        selected=false;

}

telecamera::~telecamera(void)
{
}
void telecamera::Create(l3d_vertex_fast v,l3d_vertex_fast w)
{

        vpos=v;
        vposwhere=w;
        vposup.set(0.0F,1.0F,0.0F);

        float dim=10.0F;

        vertici[0].set(dim , dim  ,dim);
        vertici[1].set(dim , -dim ,dim);
        vertici[2].set(-dim, -dim ,dim);
        vertici[3].set(-dim, dim  ,dim);
        vertici[4].set(0.0F,0.0F,-dim);
        name=0;
        selected=false;

}
void telecamera::Create(l3d_vertex_fast v,l3d_vertex_fast w,l3d_vertex_fast u)
{

        vpos=v;
        vposwhere=w;
        vposup=u;

        float dim=10.0F;

        vertici[0].set(dim , dim  ,dim);
        vertici[1].set(dim , -dim ,dim);
        vertici[2].set(-dim, -dim ,dim);
        vertici[3].set(-dim, dim  ,dim);
        vertici[4].set(0.0F,0.0F,-dim);
        name=0;
        selected=false;

}
void telecamera::Move(l3d_vertex_fast vmove)
{
        vpos.x +=vmove.x;
        vpos.y += (vmove.y);
        vpos.z += (vmove.z);
}
void telecamera::Draw()
{
        //disegna in OpenGL la telecamera

//    glDisable(GL_LIGHTING);
//        glPushMatrix();
//        glTranslatef(vpos.x,vpos.y,vpos.z);
//        glRotatef(m_angolox,1.0F,0.0F,0.0F);
//        glRotatef(m_angoloy,0.0F,1.0F,0.0F);

//        glColor3f(0.0F,0.0F,0.0F);
//        if(selected)
//                glColor3f(1.0F,1.0F,0.0F);

//        glPointSize(.5F);


//        glBegin(GL_LINES);
//        //disegno della telecamera
//        //0-1 1-2 2-3 3-1
//        glVertex3f(vertici[0].x,vertici[0].y,vertici[0].z);
//        glVertex3f(vertici[1].x,vertici[1].y,vertici[1].z);

//        glVertex3f(vertici[1].x,vertici[1].y,vertici[1].z);
//        glVertex3f(vertici[2].x,vertici[2].y,vertici[2].z);

//        glVertex3f(vertici[2].x,vertici[2].y,vertici[2].z);
//        glVertex3f(vertici[3].x,vertici[3].y,vertici[3].z);

//        glVertex3f(vertici[3].x,vertici[3].y,vertici[3].z);
//        glVertex3f(vertici[0].x,vertici[0].y,vertici[0].z);

//        glVertex3f(vertici[0].x,vertici[0].y,vertici[0].z);
//        glVertex3f(vertici[4].x,vertici[4].y,vertici[4].z);

//        glVertex3f(vertici[1].x,vertici[1].y,vertici[1].z);
//        glVertex3f(vertici[4].x,vertici[4].y,vertici[4].z);

//        glVertex3f(vertici[2].x,vertici[2].y,vertici[2].z);
//        glVertex3f(vertici[4].x,vertici[4].y,vertici[4].z);

//        glVertex3f(vertici[3].x,vertici[3].y,vertici[3].z);
//        glVertex3f(vertici[4].x,vertici[4].y,vertici[4].z);



//        glEnd();



//        glPopMatrix();
//        glEnable(GL_LIGHTING);

}
void telecamera::SetName(int nn)
{

        name=nn;

}
int telecamera::GetName()
{
        return name;
}
void telecamera::SetSelected(bool sel)
{
        selected=sel;

}
bool telecamera::isSelected()
{
        return selected;
}
/*
void telecamera::Serialize(CArchive& ar)
{
        if(ar.IsStoring())
        {

                        ar << vpos.x;
                        ar << vpos.y;
                        ar << vpos.z;

                        ar << vposwhere.x;
                        ar << vposwhere.y;
                        ar << vposwhere.z;

                        ar << vposup.x;
                        ar << vposup.y;
                        ar << vposup.z;
        }
        else
        {
                float appx,appy,appz;

                ar>>appx;

                ar>>appy;

                ar>>appz;

                vpos.set(appx,appy,appz);

                ar>>appx;

                ar>>appy;

                ar>>appz;

                vposwhere.set(appx,appy,appz);

                ar>>appx;

                ar>>appy;

                ar>>appz;

                vposup.set(appx,appy,appz);


        }
}
*/

void telecamera::SetPos(void)
{

//        glMatrixMode(GL_MODELVIEW);

        Updatefree();

//        gluLookAt(vpos.x,vpos.y,vpos.z,vposwhere.x,vposwhere.y,vposwhere.z,vposup.x,vposup.y,vposup.z);


}

void MatMult(GLfloat M[16], GLfloat v[4])
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

void telecamera::Updatefree(void)
{
        float raggio,x1,y1,z1;

        raggio=5.0F;

//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();

//        glPushMatrix();

//        glLoadIdentity();

//        glTranslatef(vpos.x,vpos.y,vpos.z);

//        glRotatef(m_angolox,1.0F,0.0F,0.0F);
//        glRotatef(m_angoloy,0.0F,1.0F,0.0F);

        GLfloat mat[16];
        GLfloat m[4];


//        glGetFloatv(GL_MODELVIEW_MATRIX,mat);

        x1=sin(0.0F * 3.141592F /180.0F)*raggio;
        z1=cos(0.0F * 3.141592F /180.0F)*raggio;
        y1=0.0F;


        m[0]=x1;
        m[1]=y1;
        m[2]=z1;
        m[3]=1.0F;

        MatMult(mat,m);

//        glPopMatrix();




        vposwhere.set(m[0],m[1],m[2]);

}


void telecamera::Updatefree(float xa, float ya)
{float raggio,x1,y1,z1;

    raggio=5.0F;

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

//    glPushMatrix();

//    glLoadIdentity();

//    glTranslatef(vpos.x,vpos.y,vpos.z);

//    glRotatef(xa,1.0F,0.0F,0.0F);
//    glRotatef(ya,0.0F,1.0F,0.0F);

    GLfloat mat[16];
    GLfloat m[4];


//    glGetFloatv(GL_MODELVIEW_MATRIX,mat);

    x1=sin(m_angoloy * 3.1415F /180.0F)*raggio;
    z1=cos(m_angoloy * 3.1415F /180.0F)*raggio;
    y1=0.0F;


    m[0]=x1;
    m[1]=y1;
    m[2]=z1;
    m[3]=1.0F;

    MatMult(mat,m);

//    glPopMatrix();




    vposwhere.set(m[0],m[1],m[2]);


}


void telecamera::SetAngols(float x, float y)
{
        m_angolox=x;
        m_angoloy=y;

        Updatefree(x,y);
}


void telecamera::AddAngles(float x, float y)
{
        m_angolox+=x;
        m_angoloy+=y;

        Updatefree(m_angolox,m_angoloy);
}
void telecamera::up()
{
    m_angolox++;
}

void telecamera::down()
{
    m_angolox--;
}

void telecamera::left()
{
    m_angoloy++;
}

void telecamera::right()
{
    m_angoloy--;

}
