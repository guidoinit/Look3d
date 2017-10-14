#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <vector>

#include "mesh/l3d_vertex.h"

#include "bezierbase.h"
#include "bezierline.h"

using namespace l3d::vertex3f;

bezierline::bezierline()
{
    m_selected=false;
    m_scale.set(1.0F,1.0F,1.0F);
    m_rotate.set(0.0F,0.0F,0.0F);
    m_wp.set(0.0F,0.0F,0.0F);
    bezierbase();
}

bezierline::bezierline(l3d_vertex _v)
{
    m_selected=false;
    m_scale.set(1.0F,1.0F,1.0F);
    m_rotate.set(0.0F,0.0F,0.0F);
    m_wp.set(0.0F,0.0F,0.0F);

    _cpoint=_v;


}
void bezierline::setid(int i)
{

}

void bezierline::setwp(l3d_vertex_fast wp)
{
    m_wp=wp;
}
void bezierline::setscale(l3d_vertex_fast s)
{
    m_scale=s;
}
void bezierline::setrotate(l3d_vertex_fast r)
{
    m_rotate=r;
}

void bezierline::selected(bool fl)
{
    m_selected=fl;
}
bool bezierline::selected()
{
    return (m_selected);
}
void bezierline::init()
{
    int size=_cpoint.size();
    float points[size][3];
    for(int ix=0; ix < size; ix++)
    {
        points[ix][0]=_cpoint.get(ix)->x;
        points[ix][1]=_cpoint.get(ix)->y;
        points[ix][2]=_cpoint.get(ix)->z;
    }
    //glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, size, &points[0][0]);
    //glEnable(GL_MAP1_VERTEX_3);
}
void bezierline::drawselect()
{

    //glLoadName(iname);
    draw();
}

void bezierline::draw()
{

    //glDisable(GL_LIGHTING);

    //glPushMatrix();

    //glColor3f(1.0, 1.0, 1.0);

    //glTranslatef(m_wp.x,m_wp.y,m_wp.z);

    //glRotatef(m_rotate.x,1.0F,0.0F,0.0F);

   // glRotatef(m_rotate.y,0.0F,1.0F,0.0F);

   // glRotatef(m_rotate.z,0.0F,0.0F,1.0F);

    //glScalef(1.0F,1.0F,1.0F);//m_scale.GetX(),m_scale.GetY(),m_scale.GetZ());
   // glScalef(m_scale.x,m_scale.y,m_scale.z);

   // glBegin(GL_LINE_STRIP);
       for (int i = 0; i <= 30; i++);
   //       glEvalCoord1f((GLfloat) i/30.0);
   // glEnd();

    int size=_cpoint.size();

    float points[size][3];

    for(int ix=0; ix < size; ix++)
    {
        points[ix][0]=_cpoint.get(ix)->x;
        points[ix][1]=_cpoint.get(ix)->y;
        points[ix][2]=_cpoint.get(ix)->z;
    }

   // glPointSize(5.0);

   // if(m_selected)
    //    glColor3f(1.0, 1.0, 0.0);
  //  else
  //      glColor3f(1.0, 0.0, 0.0);

   // glBegin(GL_POINTS);

   //     for (int i = 0; i < size; i++)
  //        glVertex3fv(&points[i][0]);

  //  glEnd();

 //   glPopMatrix();
  //  glEnable(GL_LIGHTING);
}
void bezierline::applyscale()
{
    for(int ix=0; ix < _cpoint.size();ix++)
    {
        pl3d_vertex_fast appv;
        appv=_cpoint.get(ix);
        appv->x=m_scale.x;
        appv->y=m_scale.y;
        appv->z=m_scale.z;
    }

    m_scale.set(1.0F,1.0F,1.0F);
}
void bezierline::applyrotate()
{
    rotatex();
    rotatey();
    rotatez();

    m_rotate.set(0.0F,0.0F,0.0F);

}
void bezierline::rotatex()
{
    int x;
    float gr=360.0F-m_rotate.x;

    for(x=0; x < _cpoint.size();  x++)
    {
            float appx,appy,appy2,appz;

            appx=_cpoint.get(x)->x;
            appy=_cpoint.get(x)->y;
            appz=_cpoint.get(x)->z;



            appy2 = appy *    cos(gr * 3.1415F/180.0F)    + appz *  sin(gr * 3.1415F/180.0F);
            appz  = appy *  (-sin(gr * 3.1415F/180.0F)) + appz *  cos(gr * 3.1415F/180.0F);

            _cpoint.get(x)->y=appy2;
            _cpoint.get(x)->z=appz;


    }
}


void bezierline::rotatey()
{
    int x;
    float gr=360.0F-m_rotate.y;

    for(x=0; x < _cpoint.size();  x++)
    {
            float appx,appx2,appy,appz;

            appx=_cpoint.get(x)->x;
            appy=_cpoint.get(x)->y;
            appz=_cpoint.get(x)->z;



            appx2 =(float) appx * cos((float) gr * 3.1415F / 180.0F ) + appz *    (-sin( (float) gr * 3.1415F/180.0F  ) );
            appz =(float) appx * sin((float) gr * 3.1415F / 180.0F ) + appz * cos( (float) gr * 3.1415F/180.0F      );

            _cpoint.get(x)->x=appx2;
            _cpoint.get(x)->z=appz;







    }


}
void bezierline::rotatez()
{
    int x;
    float gr=360.0F-m_rotate.z;

    for(x=0; x < _cpoint.size();  x++)
    {
            float appx,appx2,appy,appz;

            appx=_cpoint.get(x)->x;
            appy=_cpoint.get(x)->y;
            appz=_cpoint.get(x)->z;


            appx2 =appx * cos(gr * 3.1415F/180.0F) + appy * sin(gr * 3.1415F/180.0F);
            appy  =appx * (-sin(gr * 3.1415F/180.0F)) + appy * cos(gr * 3.1415F/180.0F);

            _cpoint.get(x)->x=(appx2);
            _cpoint.get(x)->y=(appy);







    }


}

