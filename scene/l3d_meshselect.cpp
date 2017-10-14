

#include "mesh/l3d_mesh.h"

#include "l3d_meshselect.h"


using namespace l3d;
using namespace l3d::mesh;




l3d_meshselect::l3d_meshselect()
{
    m_istartname=1;
}


l3d_meshselect::l3d_meshselect(pl3d_mesh_struct  value)
{
    m_istartname=1;
    m_pobject=value;
}



void l3d_meshselect::set(pl3d_mesh_struct value)
{
    m_pobject=value;
    m_istartname=1;

}

void l3d_meshselect::setname(int value)
{
    m_istartname=value;
}


void l3d_meshselect::selectvertex()
{
    int iname=m_istartname;

  //  glMatrixMode(GL_MODELVIEW);

  //  glPushMatrix();





    if(m_pobject->_lgroup==l3d_null)
    {
        m_pobject->_transformation.draw();

    }
    else
    {
        group * pg=m_pobject->_lgroup;

        m_pobject->_transformation.draw_group(&pg->_transformation);


    }


    if(m_pobject->_vertex.size() > 0)
    {
            vertex3f::pl3d_vertex_fast appv;


            for (int ix=0; ix < m_pobject->_vertex.size();ix++)
            {
                appv=m_pobject->_vertex.find(ix);

                if(!appv) continue;

                if(appv->erase)
                {
                    iname++;
                    continue;
                }

                appv->picking_name=iname;

                //glLoadName(iname);//da definire

                iname++;

               // glPointSize(20.0F);

                //glBegin(GL_POINTS);

                //    glVertex3f(appv->x,appv->y,appv->z);


               // glEnd();
            }
           // glPointSize(1.0F);
    }

   // glPopMatrix();

}

void l3d_meshselect::selectvertex(pl3d_mesh_struct value)
{
    m_pobject=value;
    selectvertex();

}

void l3d_meshselect::selectedge()
{
    int iname=m_istartname;
  //  glMatrixMode(GL_MODELVIEW);

  //  glPushMatrix();




    if(m_pobject->_lgroup==l3d_null)
    {
        m_pobject->_transformation.draw();

    }
    else
    {
        group * pg=m_pobject->_lgroup;

        m_pobject->_transformation.draw_group(&pg->_transformation);


    }


    if(m_pobject->_edges.size() > 0)
    {



            for (int ix=0; ix < m_pobject->_edges.size();ix++)
            {
                l3d::edge::pl3d_line_struct line=m_pobject->_edges.find(ix);

                if(!line) continue;

                if(line->erase)
                {
                    iname++;
                    continue;

                }
                line->iname=iname;

  //              glLoadName(iname);
                iname++;

 //               glBegin(GL_LINES);


 //                   glVertex3f(m_pobject->_vertex.find(line->v0)->x,
  //                         m_pobject->_vertex.find(line->v0)->y,
  //                         m_pobject->_vertex.find(line->v0)->z);

 //                   glVertex3f(m_pobject->_vertex.find(line->v1)->x,
  //                         m_pobject->_vertex.find(line->v1)->y,
 //                          m_pobject->_vertex.find(line->v1)->z);

 //               glEnd();



            }

    }


 //   glPopMatrix();



}

void l3d_meshselect::selectedge(pl3d_mesh_struct value)
{
    m_pobject=value;
    selectedge();

}

void l3d_meshselect::selectface()
{
    int iname=m_istartname;

  //  if(m_pobject->_display->invert)
  //          glFrontFace(GL_CCW);
  //  else
  //          glFrontFace(GL_CW);

  //  glEnable(GL_CULL_FACE);

 //   glMatrixMode(GL_MODELVIEW);
  //  glPushMatrix();




    if(m_pobject->_lgroup==l3d_null)
    {
        m_pobject->_transformation.draw();

    }
    else
    {
        group * pg=m_pobject->_lgroup;

        m_pobject->_transformation.draw_group(&pg->_transformation);


    }



    if (m_pobject->_quad.size()>0){





   //         glColor4f(1.0F,1.0F,1.0F,0.5F);

            l3d_uint nindex=0;
            pl3d_face4_struct pol4;
            pol4=m_pobject->_quad.find(nindex);


            while(pol4)
            {

                if(pol4->_erase)
                {
                    nindex++;
                    pol4=pol4->next;
                    iname++;
                    continue;
                }


                if(!pol4) continue;

                pl3d_vertex_fast v;

                pol4->_iname=iname;




                l3d_bool ccw=false;
                pl3d_vertex_fast a,b,c,d;


                switch(pol4->_insert)
                {
                case abcdCW:
                    a=pol4->_pv0;
                    b=pol4->_pv1;
                    c=pol4->_pv2;
                    d=pol4->_pv3;
                    break;
                case abdcCW:
                    a=pol4->_pv0;
                    b=pol4->_pv1;
                    d=pol4->_pv2;
                    c=pol4->_pv3;
                    break;
                case abcdCCW:
                    a=pol4->_pv0;
                    b=pol4->_pv1;
                    c=pol4->_pv2;
                    d=pol4->_pv3;
                    ccw=true;
                    break;
                case abdcCCW:
                    a=pol4->_pv0;
                    b=pol4->_pv1;
                    d=pol4->_pv2;
                    c=pol4->_pv3;
                    ccw=true;
                    break;

                }





   //             glLoadName(iname++);

  //              glBegin(GL_QUADS);
//
                if(!ccw)
                    {
                        //d----c
                        //|    |
                        //|    |
                        //a----b
                        //cw:  d,c,b,a



  //                  glVertex3f(d->x,d->y,d->z);
  //                  glVertex3f(c->x,c->y,c->z);
  //                  glVertex3f(b->x,b->y,b->z);
  //                  glVertex3f(a->x,a->y,a->z);





                    }


                else
                    {
                        //d----c
                        //|    |
                        //|    |
                        //a----b
                       //cw:  d,c,b,a
                        //ccw: a,b,c,d

//                    glVertex3f(a->x,a->y,a->z);
//                    glVertex3f(b->x,b->y,b->z);
//                    glVertex3f(c->x,c->y,c->z);
//                    glVertex3f(d->x,d->y,d->z);










                    }











//                glEnd();

                nindex++;
                pol4=pol4->next;

            }


    }


//    glPopMatrix();
}

void l3d_meshselect::selectface(pl3d_mesh_struct value)
{
    m_pobject=value;
    selectface();

}
void l3d_meshselect::selectobject(pl3d_mesh_struct value)
{
    m_pobject=value;
    selectobject();

}

void l3d_meshselect::selectobject()
{
    int iname=m_istartname;
//    if(m_pobject->_display->invert)
//            glFrontFace(GL_CW);
//    else
//            glFrontFace(GL_CCW);

//    glEnable(GL_CULL_FACE);
//
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();

    if(m_pobject->_lgroup==l3d_null)
    {
        m_pobject->_transformation.draw();

    }
    else
    {
        group * pg=m_pobject->_lgroup;

        m_pobject->_transformation.draw_group(&pg->_transformation);


    }

    m_pobject->_pick._iname=iname;

//    glLoadName(iname++);

    m_pobject->_bbox.draw_cube_select();
    /*

    if(m_pobject->_faces.size()==0)
    {
        l3d_uint sedges=m_pobject->_edges.size();

        glBegin(GL_LINES);
        for(int ix=0; ix < sedges;ix++)
        {
            pl3d_line_struct l=m_pobject->_edges.find(ix);
            pl3d_vertex_fast ve;
            l3d_uint v0,v1;

            v0=l->v0;v1=l->v1;

            ve=m_pobject->_vertex.find(v0);

            glVertex3f(ve->x,ve->y,ve->z);


            ve=m_pobject->_vertex.find(v1);

            glVertex3f(ve->x,ve->y,ve->z);




        }
        glEnd();


    }
    pl3d_face3_struct face=m_pobject->_faces.find(0);
    while(face)
    {

        l3d_uint a,b,c;
        l3d_bool ccw=false;

        switch(face->_insert)
        {
        case abcCCW:
            a=face->v0;
            b=face->v2;
            c=face->v1;

            break;
        case abcCW:
            a=face->v0;
            b=face->v1;
            c=face->v2;
            ccw=true;

            break;
        }

        glBegin(GL_TRIANGLES);


        pl3d_vertex_fast v=m_pobject->_vertex.find(a);



        glVertex3f(v->x,v->y,v->z);

        v=m_pobject->_vertex.find(b);

        glVertex3f(v->x,v->y,v->z);

        v=m_pobject->_vertex.find(c);

        glVertex3f(v->x,v->y,v->z);


        glEnd();

        face=face->next;
    }

    */


 //    glPopMatrix();

    m_istartname++;

}
