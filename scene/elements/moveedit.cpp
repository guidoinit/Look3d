
#include <stdlib.h>
#include <math.h>





#include "scene/animation/frame.h"
#include "scene/animation/animate.h"

#include "modifier/l3d_modifier_draw.h"




#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "moveedit.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;
using namespace l3d::tool;
using namespace l3d::modifier;

moveedit::moveedit(void)
        : m_radius(0)
{



    _wp.set(0.0F,0.0F,0.0F);
    _angolo.set(.0F,.0F,.0F);

    _v[0].set(0.0F,  0.0F,  0.0F);

    _v[1].set( LENGTH,  0.0F,   0.0F);

    _v[2].set(0.0F,  0.0F,  0.0F);

    _v[3].set( 0.0F, LENGTH  , 0.0F   );

    _v[4].set(0.0F,  0.0F,  0.0F);

    _v[5].set(0.0F,  0.0F,  LENGTH);


        float par[2],*fpar;
        par[0]=16.0F;
        par[1]=10.0F;
        fpar=&par[0];

        l3d::mesh::l3d_mesh::create_cone(fpar,&_cone);

        _cone._transformation.init();


        _cone._transformation._scale.set(0.1F,0.15F,0.1F);

        _cone._lgroup=l3d_null;
        _cone.init_material();



}


moveedit::~moveedit(void)
{
}

void moveedit::Draw(bool inmove)
{
    l3d_modifier_draw _draw;


        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (_angolo.x>360) _angolo.x-=360;
        if (_angolo.y>360) _angolo.y-=360;
        if (_angolo.z>360) _angolo.z-=360;

        glTranslatef(_wp.x,_wp.y,_wp.z);


        glRotatef(_angolo.x,1.0,0.0,0.0);
        glRotatef(_angolo.y,0.0,1.0,0.0);
        glRotatef(_angolo.z,0.0,0.0,1.0);

        //calcola la scala del puntatore in base a m_radius

        float _Scale=1.0F;//m_radius/100.0F;


        glScalef(_Scale,_Scale,_Scale);



        glLineWidth(2.0f);
        glBegin(GL_LINES);


        //m_cone.SetColor(0.0F,1.0F,0.0F,0.5F);
        glColor3f(0.0F,1.0F,0.0F);

        glVertex3f(_v[0].x,_v[0].y,_v[0].z);
        glVertex3f(_v[1].x,_v[1].y,_v[1].z);

        //glPushMatrix();



        //glPopMatrix();


        glColor3f(0.0F,0.0F,1.0F);
        glVertex3f(_v[2].x,_v[2].y,_v[2].z);
        glVertex3f(_v[3].x,_v[3].y,_v[3].z);

        //glPushMatrix();



        //glPopMatrix();


        glColor3f(1.0F,0.0F,0.0F);
        glVertex3f(_v[4].x,_v[4].y,_v[4].z);
        glVertex3f(_v[5].x,_v[5].y,_v[5].z);
        //glPushMatrix();



        //glPopMatrix();


        glEnd();
        glPushMatrix();

            glTranslatef(_v[1].x,_v[1].y,_v[1].z);
            glRotatef(-90.0F,0.0F,0.0F,1.0F);

            glColor4f(0.0F,1.0F,0.0F,1.0F);
            _draw.draw(&_cone,SCENE::color);



        glPopMatrix();

        glPushMatrix();
        //m_cone.SetColor(0.0F,0.0F,1.0F,0.5F);
        //m_cone.SetColor(color(0.0F,0.0F,1.0F,1.0F));
            glTranslatef(_v[3].x,_v[3].y,_v[3].z);
            glRotatef(-90.0F,0.0F,1.0F,0.0F);
            glColor4f(.0F,0.0F,1.0F,1.0F);
            _draw.draw(&_cone,SCENE::color);

        glPopMatrix();

        glPushMatrix();

        //m_cone.SetColor(1.0F,0.0F,0.0F,0.5F);
        //m_cone.SetColor(color(1.0F,0.0F,0.0F,1.0F));
            glTranslatef(_v[5].x,_v[5].y,_v[5].z);
            glRotatef(90.0F,1.0F,0.0F,0.0F);
            glColor4f(1.0F,0.0F,.0F,1.0F);
            _draw.draw(&_cone,SCENE::color);

        glPopMatrix();
        glPopMatrix();
        glEnable(GL_LIGHTING);

}

void moveedit::DrawSelect()
{
        int nIndex=0;
        static int contav=0;
         l3d_modifier_draw _draw;
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        {

            if (_angolo.x>360) _angolo.x-=360;
            if (_angolo.y>360) _angolo.y-=360;
            if (_angolo.z>360) _angolo.z-=360;

            glTranslatef(_wp.x,_wp.y,_wp.z);


            glRotatef(_angolo.x,1.0,0.0,0.0);
            glRotatef(_angolo.y,0.0,1.0,0.0);
            glRotatef(_angolo.z,0.0,0.0,1.0);

            //calcola la scala del puntatore in base a m_radius


            float _Scale=1.0F;//m_radius/100.0F;


            glScalef(_Scale,_Scale,_Scale);


                glLoadName(MOVES);

                glPushMatrix();

                    glTranslatef(_v[1].x,_v[1].y,_v[1].z);
                    glRotatef(-90.0F,0.0F,0.0F,1.0F);
                    _draw.draw(&_cone,SCENE::solid);

                glPopMatrix();

                glBegin(GL_LINES);

                        glColor3f(1.0F,0.0F,0.0F);

                        glVertex3f(_v[0].x,_v[0].y,_v[0].z);
                        glVertex3f(_v[1].x,_v[1].y,_v[1].z);

                glEnd();


                glLoadName(MOVES+1);

                glPushMatrix();

                        glTranslatef(_v[3].x,_v[3].y,_v[3].z);
                        glRotatef(-90.0F,0.0F,1.0F,0.0F);
                        _draw.draw(&_cone,SCENE::solid);

                glPopMatrix();

                glBegin(GL_LINES);

                        glColor3f(0.0F,1.0F,0.0F);
                        glVertex3f(_v[2].x,_v[2].y,_v[2].z);
                        glVertex3f(_v[3].x,_v[3].y,_v[3].z);

                glEnd();

                glLoadName(MOVES+2);

                glPushMatrix();


                    glTranslatef(_v[5].x,_v[5].y,_v[5].z);
                    glRotatef(90.0F,1.0F,0.0F,0.0F);
                    _draw.draw(&_cone,SCENE::solid);

                glPopMatrix();

                glBegin(GL_LINES);

                        glColor3f(0.0F,0.0F,1.0F);

                        glVertex3f(_v[4].x,_v[4].y,_v[4].z);
                        glVertex3f(_v[5].x,_v[5].y,_v[5].z);

                glEnd();
        }
        glPopMatrix();

}
void moveedit::setpos(l3d_vertex_fast _p)
{
    _wp=_p;
}
