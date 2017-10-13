#define GLEW_STATIC
#include <GL/glew.h>

#include "l3d_modifier_draw.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_material.h"
#include "mesh/l3d_mesh.h"

#include "scene/elements/l3d_light.h"

using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;
using namespace l3d::material;
using namespace l3d::light;

l3d_modifier_draw::l3d_modifier_draw()
{
    _mesh=l3d_null;
}
void l3d_modifier_draw::draw_edit(pl3d_mesh_struct  mesh)
{


    if(!mesh)
        return;

       l3d_glfloat alpha=.4F;

       int nIndex=0;

       glDisable(GL_CULL_FACE);
       glDisable(GL_DEPTH_TEST);


       if(mesh->_display->invert)
            glFrontFace(GL_CCW);
       else
            glFrontFace(GL_CW);


       glDisable(GL_LIGHTING);


       mesh->use_blend_edit();


       glMatrixMode(GL_MODELVIEW);


       glPushMatrix();


       if(mesh->_lgroup==l3d_null)
       {
           mesh->_transformation.draw();

       }
       else
       {
           group * pg=mesh->_lgroup;

           mesh->_transformation.draw_group(&pg->_transformation);


       }


       pl3d_face4_struct face4;
       if (mesh->_quad.size()==0 && mesh->_faces.size()==0)
       {


           pl3d_line_struct pl=mesh->_edges.find(0);

           while( pl)
           {

               if (pl->selected())
                   glColor4f(0.0F,0.5F,1.0F,alpha);
               else
                   glColor4f(0.0F,0.5F,0.5F,alpha);

               l3d_uint v0,v1;
               pl3d_vertex_fast vp;
               v0=pl->v0;
               v1=pl->v1;



               glBegin(GL_LINES);

                vp=mesh->_vertex.find(v0);

                glVertex3f(vp->x,vp->y,vp->z);

                vp=mesh->_vertex.find(v1);

                glVertex3f(vp->x,vp->y,vp->z);




               glEnd();


               pl=pl->next;

           }


       }

       if (mesh->_quad.size()>0){

            glBegin(GL_QUADS);

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




                glColor4f(0.0F,1.0F,0.5F,alpha);


                if (face4->_selected)

                    glColor4f(0.0F,0.5F,1.0F,alpha);

                else

                    glColor4f(0.0F,0.5F,0.5F,alpha);





                pl3d_vertex_fast appv;






                if(!ccw)
                    {
                        //d----c
                        //|    |
                        //|    |
                        //a----b
                        //cw:  d,c,b,a

                        appv=mesh->_vertex.find(d);

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(c);

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(b);

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(a);

                        glVertex3f(appv->x,appv->y,appv->z);


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

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(b);

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(c);

                        glVertex3f(appv->x,appv->y,appv->z);

                        appv=mesh->_vertex.find(d);

                        glVertex3f(appv->x,appv->y,appv->z);



                    }








                ix++;
                face4=face4->next;

            }
            glEnd();

            ix=0;
            face4=mesh->_quad.find(ix);

            glBegin(GL_LINES);
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

                glLineWidth(2.0F);


                    l0=face4->_l0;
                    l1=face4->_l1;
                    l2=face4->_l2;
                    l3=face4->_l3;

                    if(!l0->erase)
                    {
                        if(l0->selected())
                            glColor4f(0.0F,1.0F,1.0F,alpha);
                        else
                            glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l0->_v0;
                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l0->_v1;
                        glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l1->erase)
                    {
                        if(l1->selected())
                            glColor4f(0.0F,1.0F,1.0F,.2F);
                        else
                            glColor4f(0.0F,0.0F,0.0F,.2F);




                        appv=l1->_v0;
                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l1->_v1;
                        glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l2->erase)
                    {
                        if(l2->selected())
                            glColor4f(0.0F,1.0F,1.0F,alpha);
                        else
                            glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l2->_v0;
                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l2->_v1;
                        glVertex3f(appv->x,appv->y,appv->z);


                    }
                    if(!l3->erase)
                    {
                        if(l3->selected())
                            glColor4f(0.0F,1.0F,1.0F,alpha);
                        else
                            glColor4f(0.0F,0.0F,0.0F,alpha);




                        appv=l3->_v0;
                        glVertex3f(appv->x,appv->y,appv->z);
                        appv=l3->_v1;
                        glVertex3f(appv->x,appv->y,appv->z);


                    }






                face4=face4->next;
                ix++;


            }
            }glEnd();


        }





         if (mesh->_faces.size()>0)
        {

            glBegin(GL_TRIANGLES);
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



                glColor4f(0.0F,1.0F,0.5F,alpha);

                if (face->_selected)
                    glColor4f(0.0F,0.5F,1.0F,alpha);
                else
                    glColor4f(0.0F,0.5F,0.5F,alpha);

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

                    glVertex3f(app1->x,app1->y,app1->z);

                    glVertex3f(app2->x,app2->y,app2->z);

                    glVertex3f(app3->x,app3->y,app3->z);

                }












                nIndex++;
                face=face->next;
                glLineWidth(2.0F);


            }
            glEnd();





        }





        l3d_uint ip=0;

        pl3d_vertex_fast vert=mesh->_vertex.find(ip);

        glPointSize(2.0F);

        glBegin(GL_POINTS);
        while(vert)
        {


            if( vert->erase)
            {
                ip++;

                vert=vert->next;

                continue;
            }


                //glPushMatrix();


                if(vert->_selected)
                    glColor4f(1.0F,0.0F,0.0F,alpha);
                else
                    glColor4f(1.0F,1.0F,0.0F,alpha);

                glVertex3f(vert->x,vert->y,vert->z);





                //glPopMatrix();
                ip++;
                vert=vert->next;



        }

        glEnd();

        glPopMatrix();
        glPointSize(1.0F);




        glEnable(GL_LIGHTING);
        glDisable(GL_BLEND);

        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
}

void l3d_modifier_draw::draw_light(pl3d_light _plight)
{



    glDisable(GL_LIGHTING);
    //draw the ligth
    glColor4f(1.0F,1.0F,0.0F,1.0F);
    switch (_plight->type)
    {

            case l_sun://disegna solo una sfera
                draw(&_plight->_sphere,SCENE::color);

            break;

            case l_lamp://disegna solo una sfera
                draw(&_plight->_sphere,SCENE::color);

            break;

            case l_spot://disegna una sfera e una linea per la direzione
                draw(&_plight->_sphere,SCENE::color);
                _plight->drawspot();

                //drawSpot();
            break;
            case l_directional:
               draw(&_plight->_sphere,SCENE::color);
               // m_sphere->Draw(2);
            break;

    }
    glEnable(GL_LIGHTING);

}

void l3d_modifier_draw::draw(pl3d_mesh_struct _pmesh,SCENE::ModeDraw _mode)
{
    if(_pmesh)
    {
        _mesh=_pmesh;
        _mesh->_display=_pmesh->_display;
    }
    else
        return;




    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    if(_mesh->_display->invert)
         glFrontFace(GL_CCW);
    else
         glFrontFace(GL_CW);

    if(_mesh->blend())
        _mesh->use_blend();

    if( _mesh->_display->smooth)
        glShadeModel(GL_SMOOTH);
    else
        glShadeModel(GL_FLAT);

    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();

    if(_mesh->_lgroup==l3d_null)
    {
        _mesh->_transformation.draw();

    }
    else
    {
        group * pg=_mesh->_lgroup;

        _mesh->_transformation.draw_group(&pg->_transformation);


    }


    switch(_mode)
    {
    case SCENE::box:
        glColor4f(0.0F,0.0F,0.0F,1.0F);
        glDisable(GL_LIGHTING);

        if(_mesh->selected())
            glColor4f(1.0F,1.0F,0.0F,1.0F);

        _mesh->_bbox.draw_cube();

        glEnable(GL_LIGHTING);
        break;
    case SCENE::solid:
        glDisable(GL_BLEND);
        glDisable(GL_LIGHTING);
        if(_mesh->selected())
            glColor4f(0.7F,.7F,0.7F,1.0F);
        else
            glColor4f(0.5F,0.5F,0.5F,1.0F);
        draw_face3_solid();
        glEnable(GL_LIGHTING);
        break;
    case SCENE::color:
        draw_face3();
        break;
    case SCENE::wireframe:
        draw_wireframe();
        break;
    case SCENE::mtexture:
        draw_texture();
        break;
    }
    glPopMatrix();

    glDisable(GL_BLEND);
}
void l3d_modifier_draw::draw_select(pl3d_mesh_struct mesh)
{
    pl3d_vertex_fast v0,v1,v2,normal;
    pl3d_face3_struct f3;


    if(!mesh)
        return;

    _mesh=mesh;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    if(_mesh->_lgroup==l3d_null)
    {
        _mesh->_transformation.draw();

    }
    else
    {
        group * pg=_mesh->_lgroup;

        _mesh->_transformation.draw_group(&pg->_transformation);


    }

    f3=_mesh->_faces.first();

    if(!_mesh->selected())
    {
        glLoadName(_mesh->_iname);
        _mesh->_bbox.draw_cube_select();

    }
    /*glBegin(GL_TRIANGLES);

    while(f3)
    {
        if(f3->_erase)
        {
            f3=f3->next;
            continue;
        }

        pl3d_vertex_fast a,b,c;
        l3d_bool ccw=false;
        switch(f3->_insert)
        {
        case abcCW:
            a=f3->_pv0;
            b=f3->_pv1;
            c=f3->_pv2;

            break;
        case abcCCW:
            a=f3->_pv0;
            b=f3->_pv2;
            c=f3->_pv1;
            ccw=true;

            break;
        }
        if(a->erase || b->erase || c->erase)
        {
            f3=f3->next;
            continue;
        }



        if(!ccw)
        {
            if(a && b && c)
            {
                draw_vertex_solid(a);
                draw_vertex_solid(c);
                draw_vertex_solid(b);
            }

        }
        else
        {
            if(a && b && c)
            {
                draw_vertex_solid(a);
                draw_vertex_solid(b);
                draw_vertex_solid(c);

            }


        }






        f3=f3->next;
    }

    glEnd();*/

    glPopMatrix();
}

void l3d_modifier_draw::draw_vertex_texture(pl3d_vertex_fast _v,l3d_double u,l3d_double v)
{

    if(!_mesh)
        return;


    glTexCoord2d(u,v);

    glNormal3f(_v->normals[0],_v->normals[1],_v->normals[2]);

    glVertex3f(_v->x,_v->y,_v->z);

}
void l3d_modifier_draw::draw_vertex_solid(pl3d_vertex_fast _v)
{

    if(!_mesh)
        return;


    glNormal3f(_v->normals[0],_v->normals[1],_v->normals[2]);

    glVertex3f(_v->x,_v->y,_v->z);

}
void l3d_modifier_draw::draw_vertex(pl3d_vertex_fast _v)
{
    pl3d_material_struct _mat;

    if(!_mesh)
        return;


    if(_v->_imaterial!=-1)
        _mat=_mesh->_material.get(_v->_imaterial);


    _mat->set();

    glNormal3f(_v->normals[0],_v->normals[1],_v->normals[2]);

    glVertex3f(_v->x,_v->y,_v->z);

}

void l3d_modifier_draw::draw_face3(pl3d_mesh_struct _pmesh)
{


    if(_pmesh)
        _mesh=_pmesh;
    else
        return;

    draw_face3();

}
void l3d_modifier_draw::draw_face3()
{
    pl3d_vertex_fast a,b,c;
    pl3d_face3_struct f3;



    f3=_mesh->_faces.first();

    glBegin(GL_TRIANGLES);

    while(f3)
    {
        if(f3->_erase)
        {
            f3=f3->next;
            continue;
        }

        l3d_bool ccw=false;
        switch(f3->_insert)
        {
        case abcCW:
            a=f3->_pv0;
            b=f3->_pv1;
            c=f3->_pv2;

            break;
        case abcCCW:
            a=f3->_pv0;
            b=f3->_pv2;
            c=f3->_pv1;
            ccw=true;

            break;
        }




        if(a->erase || b->erase || c->erase)
        {
            f3=f3->next;
            continue;
        }


        if(a && b && c)
        {
            draw_vertex(a);

            draw_vertex(c);

            draw_vertex(b);

        }







        f3=f3->next;
    }

    glEnd();


}
void l3d_modifier_draw::draw_face3_solid()
{
    pl3d_vertex_fast a,b,c;
    pl3d_face3_struct f3;



    f3=_mesh->_faces.first();

    glBegin(GL_TRIANGLES);

    while(f3)
    {
        if(f3->_erase)
        {
            f3=f3->next;
            continue;
        }
        l3d_bool ccw=false;
        switch(f3->_insert)
        {
        case abcCW:
            a=f3->_pv0;
            b=f3->_pv1;
            c=f3->_pv2;

            break;
        case abcCCW:
            a=f3->_pv0;
            b=f3->_pv2;
            c=f3->_pv1;
            ccw=true;

            break;
        }


        if(a->erase || b->erase || c->erase)
        {
            f3=f3->next;
            continue;
        }

        if(a && b && c)
        {
            draw_vertex(a);

            draw_vertex(c);

            draw_vertex(b);

        }





        f3=f3->next;
    }

    glEnd();


}
void l3d_modifier_draw::draw_wireframe()
{
    if(!_mesh)
        return;
    pl3d_vertex_fast v0,v1;
    pl3d_line_struct l=_mesh->_edges.first();
    glBegin(GL_LINES);
    {
        while(l)
        {

            v0=l->_v0;
            v1=l->_v1;


            if(l->erase || !(v0 && v1))
            {
                l=l->next;
                continue;
            }


            draw_vertex(v0);
            draw_vertex(v1);


            l=l->next;
        }
    }
    glEnd();

}
void l3d_modifier_draw::draw_quad(pl3d_face4_struct _q)
{
    if(!_q)
        return;

    pl3d_vertex_fast v0,v1,v2,v3;

    v0=_q->_pv0;
    v1=_q->_pv1;
    v2=_q->_pv2;
    v3=_q->_pv3;


    if(!(v0 && v1 && v2 && v3))
        return;

    //con coordinate texture q->u[4] q->v[4]

    glTexCoord2d(_q->u[0],_q->v[0]);
    draw_vertex(v0);

    glTexCoord2d(_q->u[1],_q->v[1]);
    draw_vertex(v1);

    glTexCoord2d(_q->u[2],_q->v[2]);
    draw_vertex(v2);

    glTexCoord2d(_q->u[3],_q->v[3]);
    draw_vertex(v3);


}

void l3d_modifier_draw::draw_texture()
{
    pl3d_face4_struct q;

    if(!_mesh)
        return;

    glEnable( GL_TEXTURE_2D );

    //glBindTexture( GL_TEXTURE_2D, texture ); to-do insert a texture

    q=_mesh->_quad.first();

    glBegin(GL_QUADS);
    while(q)
    {
        if(q->_erase)
        {
            q=q->next;
            continue;
        }

        draw_quad(q);

        q=q->next;
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);



}
