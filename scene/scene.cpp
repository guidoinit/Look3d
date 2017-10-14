

#include <cmath>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <QtOpenGL>
#include <QtDebug>
#include <QtGlobal>

#include "sceneinclude.h"


#include "scene/elements/lightmodel.h"


#include "scene/elements/viewport.h"
#include "scene/elements/pipeline.h"


#include "scene/project/project.h"

#include "scene/project/projectmanager.h"
#include "scene/elements/gridviewuv.h"
#include "scene/document.h"

#include "qt/insertobject.h"
#include "scene/exports/md2/Md2Model.h"
#include "scene/exports/md2/Md2Player.h"
#include "scene/imports/3ds/lib3dsimporter.h"



#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"

#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "scene.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;

extern insertObject * Main_insert;

scene::scene()
{
        m_scene=SCENE::s3d;
        _main_view.setScene(SCENE::s3d);
        m_modedoc=SCENE::normal;
        m_modeedit=SCENE::polygon;
        numcubo=0;
        numpir=0;
        numsphere=0;
        numdisc=0;
        numplane=0;
        numcone=0;

        //m_maincamera.m_track.m_btrack=false;
        m_animationstate= new animationmanager_state();


        m_animationstate->m_bisrotate=false;
        m_itelecamera=-1;

        float m_angolo[3]={45.0F,0.0F,0.0F};
        m_frotate[0]=0.0F;
        m_frotate[1]=0.0F;
        m_frotate[2]=0.0F;
        m_fortho=0.0F;
        //m_maincamera.SetAngolo(m_angolo);
        //m_maincamera.Update(100.0F);
        //m_maincamera.SetUp(0.0F,1.0F,0.0F);


        m_animationstate->m_ianiselect=-1;
        m_animationstate->m_iframe=-1;
        m_animationstate->m_bplay=false;
        m_animationstate->m_moveobj[0]=false;
        m_animationstate->m_moveobj[1]=false;
        m_animationstate->m_moveobj[2]=false;
        m_animationstate->m_bisscale=false;


        _input._isupdown=false;
        _input._isleftright=false;
        _input._mouse_move=mouse_xzy;
        _input.init_clean();




        m_btrackball=false;
        m_btop=false;
        m_ftop[0]=0.0F;
        m_ftop[1]=0.0F;

        m_bligthselected=false;

        m_bctrl=false;
        m_bplay=false;
        m_bmultiselect=false;
        m_bisrotate=false;
         m_bismove=false;
        m_bisscale=false;

       // m_binsert=false;
        //m_insert=NULL;
        m_baltleft=false;
        m_bupdown=false;
        m_bisupdown=false;
        //pdlgLight=NULL;
        //_pmanager=NULL;

        //m_object.clear();

        m_docselect=SCENE::dsmainscene;

        m_griduv=new gridviewuv();

        // m_pipelinetop= new pipeline(telecamera(vertex(0.0F,0.0F,0.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,1.0F,0.0F)),viewport());

        //void pipeline::draw()
        //m_pipelinetop->_func=Draw();

        //m_pipelinetop->setdraw( Draw());

        //m_mainviewport[0].m_cam.Create(vertex(0.0F,0.0F,0.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,1.0F,0.0F));
        //m_mainviewport[1].m_cam.Create(vertex(0.0F,0.0F,50.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,1.0F,0.0F));
        //m_mainviewport[2].m_cam.Create(vertex(0.0F,-50.0F,0.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,0.0F,-1.0F));

        initview();
        //m_mainviewport[3].m_cam.Create(vertex(),vertex());

        //add a ligth

        //getdocument()->getmainscenedoc()->getmanageranimation()->setstate(m_animationstate);
      //  getdocument()->getmainscenedoc()->addlight(LIGTH::l_sun,vertex(0.0F,200.0F,0.0F));

/*

        m_aligth.push_back(l);

*/
       // m_svbo->BuildVBOs();


}

scene::scene(SCENE::SceneType st)
{
        m_scene=st;
        _main_view.setScene(st);
        m_modedoc=SCENE::normal;
        m_modeedit=SCENE::polygon;

        numcubo=0;
        numpir=0;
        numsphere=0;
        numdisc=0;
        numplane=0;
        numcone=0;

        m_itelecamera=-1;

        float m_angolo[3]={45.0F,0.0F,0.0F};
        m_frotate[0]=0.0F;
        m_frotate[1]=0.0F;
        m_frotate[2]=0.0F;
        m_fortho=0.0F;

       // m_maincamera.SetAngolo(m_angolo);
       // m_maincamera.Update(100.0F);
       // m_maincamera.SetUp(0.0F,1.0F,0.0F);

       // m_maincamera.m_track.m_btrack=false;


        _input._isupdown=false;
        _input._isleftright=false;
        _input._mouse_move=mouse_xzy;
        _input.init_clean();




        m_btrackball=false;
        m_btop=false;
        m_ftop[0]=0.0F;
        m_ftop[1]=0.0F;

        m_bligthselected=false;

        m_bctrl=false;
        m_bplay=false;
        m_bmultiselect=false;
        m_bisrotate=false;
        m_bismove=false;
        m_bisscale=false;
        m_binsert=false;
        //m_insert=NULL;
        m_baltleft=false;
        m_bupdown=false;
        m_bisupdown=false;

        m_docselect=SCENE::dsmainscene;

        m_griduv=new gridviewuv();

        //m_mainviewport[0].m_cam.Create(vertex(0.0F,50.0F,0.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,0.0F,1.0F));
        //m_mainviewport[1].m_cam.Create(vertex(0.0F,0.0F,50.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,1.0F,0.0F));
       // m_mainviewport[2].m_cam.Create(vertex(0.0F,-50.0F,0.0F),vertex(0.0F,0.0F,0.0F),vertex(0.0F,0.0F,-1.0F));
        //m_mainviewport[3].m_cam.Create(vertex(),vertex());

        m_animationstate= new animationmanager_state();

        m_animationstate->m_bisrotate=false;

        m_animationstate->m_ianiselect=-1;
        m_animationstate->m_iframe=-1;
        m_animationstate->m_bplay=false;
        m_animationstate->m_moveobj[0]=false;
        m_animationstate->m_moveobj[1]=false;
        m_animationstate->m_moveobj[2]=false;

        initview();
        //getdocument()->getmainscenedoc()->getmanageranimation()->setstate(m_animationstate);
        //pdlgLight=NULL;
        //_pmanager=NULL;
/*
        ligth l(vertex(0.0F,20.0F,0.0F));
        l.SetType(LIGTH::lnormal);
        l.setinternalname(GL_LIGHT0);
        m_aligth.push_back(l);
        */
}
void scene::initview()
{
    l3d_vertex_fast eye,center,up;
    eye.set(0.0F,50.0F,-50.0F);
    center.set(0.0F,0.0F,0.0F);
    up.set(0.0F,1.0F,0.0F);

    _main_view.setCamera(eye,center,up);
    _main_view.setCameraAlphaBeta(0.0F,0.0F);
    _main_view.setCameraFree(false);
    _main_view.setProspectiveOrtho(false,-50.0F,50.0F,-50.0F,50.0F,-1000.0F,1000.0F);

    _main_view.setProspectiveNormal(true,45.0f,1.0f,1.0f,1000.0f);
    _main_view.setDocumentSelect(SCENE::dsmainscene);
    _main_view.setInput(&_input);

}

scene::~scene()
{

        //m_object.clear();
       // m_ocopy.clear();
        //getdocument()->getmainscenedoc()->getmanageranimation()->clear();
        //m_telecamera.clear();
        //m_aligth.clear();
        //if(_pmanager!=NULL)
        //        _pmanager->FreeProject();

}
/*
void scene::CreatePovFile(CStdioFile * file)
{
        if(m_object.size()==0)
                return;
        for(int ix=0; ix < 0; ix++)
        {
                m_object[ix].CreatePov(file);
        }

}
*/
void scene::Play(int np)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->play(np);

}


void scene::RemoveAll()
{
        ///m_object.clear();
        ///m_ocopy.clear();
        //to-do m_animate
        ///m_telecamera.clear();
        //m_aligth.clear();
}
bool scene::InitScene()
{
        //opengl.Init(hDC);

        //_DC=hDC;
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    /*
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat mat_shininess[] = { 50.0 };
        GLfloat ambient[4]={0.3f,0.3f,0.3f,1.0f};
        GLfloat diffuse[4]={0.5f,0.5f,0.5f,1.0f};

        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);
        glShadeModel(GL_SMOOTH);

       // glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
       // glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        glEnable(GL_LIGHTING);
        glFrontFace(GL_CW);
        glEnable(GL_DEPTH_FUNC);
        glEnable(GL_DEPTH_TEST);
        //glEnable(GL_BLEND);
*/
        return true;
}
/*
void scene::setMainWindow(Ui::MainWindow *value)
{
    m_ui=value;
}
*/
void scene::ResetScene(void)
{
        //opengl.Init(_DC);
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    /*

        GLfloat ambient[4]={0.3f,0.3f,0.3f,1.0f};
        GLfloat diffuse[4]={0.5f,0.5f,0.5f,1.0f};
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glFrontFace(GL_CW);
        glEnable(GL_DEPTH_FUNC);
        ///glEnable(GL_BLEND);
*/
        //return true;
}

void scene::setdocument(document *ndoc)
{
    m_maindocument=ndoc;
    _main_view.setDocument(m_maindocument);
    m_maindocument->getmainscenedoc()->getmanageranimation()->setstate(m_animationstate);


}

document * scene::getdocument()
{
    return(m_maindocument);
}





void scene::SetRadius(float nr)
{
        //m_maincamera.Update(nr);
}
void scene::SetDcoumentSelect(SCENE::DocumentSelect dselect)
{
    m_docselect=dselect;
}

void scene::SetScene(SCENE::SceneType st)
{
        m_scene=st;
        _main_view.setScene(st);
        m_maindocument->getmainscenedoc()->settype(st);
        //m_maincamera.InitTrackball();
        float heigth=m_view_heigth;
        float width=m_view_width;
        if(m_scene==SCENE::sall)
        {

           SetViewportSize(width,heigth);


        }
        if(m_scene==SCENE::s3d)
        {
                float a[3]={90.0F,0.0F,0.0F};
                //m_maincamera.SetAngolo(a);
                //m_maincamera.Update(100.0F);
        }
        if(m_scene==SCENE::stelecamera && m_maindocument->getmainscenedoc()->getsizecamera()==0)
                m_scene=SCENE::s3d;
        if(m_scene==SCENE::stop)
        {
                float a[3]={90.0F,0.0F,0.0F};
                m_fortho=0.0F;

                //m_maincamera.SetAngolo(a);
                //m_maincamera.Update(100.0F);
        }
        if(m_scene==SCENE::sleft)
        {
                float a[3]={0.0F,0.0F,0.0F};
                m_fortho=0.0F;

                //m_maincamera.SetAngolo(a);
                //m_maincamera.Update(100.0F);
        }


}
void scene::SetAnimationObjectsHide()
{
        /*if(m_object.size()<=0)
                return;

        for(int ix=0; ix < m_object.size(); ix++)
                if(m_object[ix].m_bselected)
                        m_object[ix].Hide(true);
*/
}
void scene::SetAnimationObjectsUnHide()
{
      /*  if(m_object.size()<=0)
                return;

        for(int ix=0; ix < m_object.size(); ix++)
                if(m_object[ix].m_bhide)
                        m_object[ix].Hide(false);
*/
}
void scene::SetScaleAnimationObject(int aindex,int oindex,float scale[3])
{
       getdocument()->getmainscenedoc()->getmanageranimation()->SetScaleAnimationObject(aindex,oindex,scale);

}
void scene::SetInitialState()
{
       getdocument()->getmainscenedoc()->getmanageranimation()->SetInitialState();
}
void scene::SetAnimation(int index)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->SetAnimation(m_ianiselect);
}
void scene::InitPipeline()
{
        float aspect;//=opengl.m_view_aspect;

        //glewInit();
        float forthox=(300.0F/2.0F*aspect);
        float forthoy=(300.0F/2.0F*aspect);
        switch(m_scene)
        {
        case SCENE::sall:
            //gluPerspective(45.0f,1.5F,1.0F,10000.0F);
            break;
        case SCENE::s3d:

               // gluPerspective(45.0f,1.5F,1.0F,10000.0F);
            break;
        case SCENE::stelecamera:

               // gluPerspective(45.0f,1.5F,1.0F,10000.0F);
            break;
        //case SCENE::sleft:
        //	break;
        //case SCENE::sright:
        //	break;
        case SCENE::stop:
                //glOrtho(-(opengl.m_view_width/2),(opengl.m_view_width/2),-(opengl.m_view_height/2),(opengl.m_view_height/2),1.0F,1000.0F);
                glOrtho((-forthox+m_fortho+m_ftop[0])*aspect,(forthox-m_fortho+m_ftop[0])*aspect,(-forthoy+m_fortho+m_ftop[1])*aspect,(forthoy-m_fortho+m_ftop[1])*aspect,1.0F+m_fortho,1000.0F+m_fortho);

            break;
        case SCENE::sleft:
                //glOrtho(-(opengl.m_view_width/2),(opengl.m_view_width/2),-(opengl.m_view_height/2),(opengl.m_view_height/2),1.0F,1000.0F);
                glOrtho((-forthox+m_fortho+m_ftop[0])*aspect,(forthox-m_fortho+m_ftop[0])*aspect,(-forthoy+m_fortho+m_ftop[1])*aspect,(forthoy-m_fortho+m_ftop[1])*aspect,1.0F+m_fortho,1000.0F+m_fortho);

            break;


        }

        //glViewport(0, 0, opengl.m_view_width, opengl.m_view_height);






}
void scene::DoUserAction()
{

        if(_input._move || _input._scale || _input._rotate || m_animationstate->m_bismove)
        {
                if(_input._move || m_animationstate->m_bismove)
                {
                        Move(_input._offset);
                        _input._offset.set(0.0F,0.0F,0.0F);

                }
                if(_input._scale)
                {
                        //Scale(m_fscale);

                }
                if(_input._rotate)
                {
                        //Rotate(m_frotate);
                        // this->Rotate(); to-do

                }

        }
}
bool scene::SetTelecamera(int index)
{
        /*if(index <0 || index > m_telecamera.size())
        {
                m_scene=SCENE::s3d;
                m_itelecamera=-1;
                return false;
        }
        else
        {
                m_scene=SCENE::stelecamera;
                m_itelecamera=index;
                return true;
        }*/
}
void scene::DrawTelecamera()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_itelecamera=m_maindocument->getmainscenedoc()->getcameraselected();
            //if(m_itelecamera < 0 || m_itelecamera > m_maindocument->getmainscenedoc()->getsizecamera())
            //    m_maincamera.Draw();
            //else
            //    m_maindocument->getmainscenedoc()->getpcamera(m_itelecamera)->SetPos();

        break;
    }

}
void scene::DrawSceneLigths()
{
    //for(int ix=0; ix < m_aligth.size(); ix++)
    {
    //    m_aligth[ix].Draw();

    }

}

void scene::Pipeline()
{

    _main_view.PipeLine();
    DoUserAction();
    return;
        glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glClearColor(0.5f,0.5f,0.5f,0.0F);
        glEnable(GL_LIGHTING);
       //glEnable(GL_BLEND);


        {
             InitLigth();
        }

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();



        InitPipeline();


        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glShadeModel(GL_SMOOTH);


        //if(_pmanager!=NULL)
        //{
        //        _pmanager->Pipeline();

                //opengl.Finish_Render();

        //        return;
        //}



        if(m_scene==SCENE::stelecamera)
                DrawTelecamera();
        else if (m_scene!=SCENE::sall)

        {
            //m_maincamera.Draw();
            //if( m_maincamera.m_track.m_btrack)
                 //m_maincamera.m_track.set(m_mousecord.x,m_mousecord.y,m_view.getwidth(),m_view.getheigth());

        }

/* da eliminare ???
        if(m_binsert)
        {

                if(m_insert==NULL)
                {
                        m_insert=new insert();
                        m_insert->Create();
                }
                m_insert->Draw();
                if(m_insert->Selected())
                {
                        m_binsert=false;
                        AddObject(m_insert->GetObjectSelected());
                }
                //opengl.Finish_Render();

                return;

        }
*/
        glDrawBuffer(GL_BACK);

        DoUserAction();

        //to-do aggiungere codice per disegnare puntatori:

        // di movimento DrawPointer();
        // di scalatura
        // di rotazione

        //DrawPointer();


        //DrawSceneLigths();

        if(m_scene==SCENE::sall)
        {

            /*
                void glOrtho(	GLdouble left,
                GLdouble right,
                GLdouble bottom,
                GLdouble top,
                GLdouble nearVal,
                GLdouble farVal);
            Parameters

            left, right
                Specify the coordinates for the left and right vertical clipping planes.

            bottom, top
                Specify the coordinates for the bottom and top horizontal clipping planes.

            nearVal, farVal
                Specify the distances to the nearer and farther depth clipping planes. These values are negative if the plane is to be behind the viewer.
            */

            //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

            //init view
            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            glOrtho(-1.0F,1.0F,-1.0F,1.0F,-100.0F,100.0F);

            glPushMatrix();
                glDisable(GL_LIGHTING);
                //m_view.set();

                glLineWidth(4.0F);
                glColor3f(1.0F,1.0F,1.0F);
                glBegin(GL_LINES);

                    glVertex2f(0.0F,1.0F);
                    glVertex2f(0.0F,-1.0F);

                    glVertex2f(-1.0F,0.0F);
                    glVertex2f(1.0F,0.0F);

                glEnd();
                glLineWidth(6.0F);
                glColor3f(0.2F,0.2F,0.2F);
                glBegin(GL_LINES);

                    glVertex2f(0.0F,1.0F);
                    glVertex2f(0.0F,-1.0F);

                    glVertex2f(-1.0F,0.0F);
                    glVertex2f(1.0F,0.0F);

                glEnd();

            glPopMatrix();

            //init view 1
            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

            glPushMatrix();
                //m_mainviewport[0].set();

                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                //m_mainviewport[0].m_cam.SetPos();

                Draw();
            glPopMatrix();

            //init view 2

            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

            glPushMatrix();

                //m_mainviewport[1].set();
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                //m_mainviewport[1].m_cam.SetPos();

                Draw();

            glPopMatrix();

            //init view 3

            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

            glPushMatrix();
                //m_mainviewport[2].set();
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                //m_mainviewport[2].m_cam.SetPos();

                Draw();
            glPopMatrix();


            //init view 4

            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

            glPushMatrix();

                //m_mainviewport[3].set();
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();

                //m_maincamera.Draw();
                //m_mainviewport[0].set();

                Draw();

            glPopMatrix();

            return;
        }//else
            //m_view.set();

        if(m_modedoc==SCENE::fastinsert)
        {
            /*if(m_insert==NULL)
            {
                m_insert=new insert();
                m_insert->Create();
            }
            m_insert->Draw();*/
        }
        if(m_modedoc==SCENE::normal || m_modedoc==SCENE::edit || m_modedoc==SCENE::paint || m_modedoc==SCENE::texture )
        {
            //m_view.set();
            Draw();

            glMatrixMode(GL_PROJECTION);

            glLoadIdentity();

            //gluPerspective(45.0f,1.5F,1.0F,10000.0F);
            /*
              GLdouble  left,  GLdouble  right,  GLdouble  bottom,  GLdouble  top,  GLdouble  nearVal,  GLdouble  farVal);
              */
            glFrustum(-1.0F,1.0F,-1.0F,1.0F,1.0F,10000.0F);
//            glOrtho(-100.0F,100.0F,-100.0F,100.0F,1.0F,10000.0F);

            glPushMatrix();

                //m_view.set();
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();

                //m_maincamera.Draw();
                //m_mainviewport[0].set();
                //trovare la funzione che ti permette di trasfrmare
                //coordinate in ortho da prospettiva

                //Drawtool(m_maindocument->getmainscenedoc()->gettoolpos());
                draw_multy_select_pointer(m_mousecord.x,m_mousecord.y);
            glPopMatrix();

        }

        /*if(m_modedoc==SCENE::texture)
        {
            m_mainviewport[0].set();
            Draw();
            m_mainviewport[1].set();
            gluOrtho2D(0.0,m_mainviewport[1].getwidth(),m_mainviewport[1].getheigth(),0.0);
            m_griduv->draw();


        }*/

        if(m_modedoc==SCENE::animation)
            DrawAnimation(m_animationstate->m_ianiselect);


        if(m_modedoc==SCENE::container)
        {

                DrawContainer();

                //opengl.Finish_Render();

                return;

        }



        //opengl.Finish_Render();


}

void scene::InitLigth()
{
    glEnable(GL_LIGHTING);

    m_light_model.set();


}
void scene::draw_multy_select_pointer(l3d_uint x,l3d_uint y)
{
    l3d_vertex_fast appv=getpoint3d(x,y);

    l3d_vertex_fast v0,v1,v2,v3;
    l3d_uint side=2.0F;

    v0=appv;
    //v0.y+=20.0F;
    v0.x-=side;
    v0.z+=side;


    v1=appv;
    //v1.y+=20.0F;
    v1.x+=side;
    v1.z+=side;

    v2=appv;
    //v2.y+=20.0F;
    v2.x+=side;
    v2.z-=side;

    v3=appv;
    //v3.y+=20.0F;
    v3.x-=side;
    v3.z-=side;
    glPushMatrix();

    glScalef(1.0F,1.0F,1.0F);
    glDisable(GL_LIGHTING);

    glEnable(GL_BLEND);

    glFrontFace(GL_CW);

    glDisable(GL_CULL_FACE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0F,1.0F,0.0F,.3F);
    glBegin(GL_QUADS);

    glVertex3f(v0.x,v0.y,v0.z);

    glVertex3f(v3.x,v3.y,v3.z);

    glVertex3f(v2.x,v2.y,v2.z);

    glVertex3f(v1.x,v1.y,v1.z);


    /*glVertex3f(v0.x,v0.y,v0.z);
    glVertex3f(v1.x,v1.y,v1.z);

    glVertex3f(v1.x,v1.y,v1.z);
    glVertex3f(v2.x,v2.y,v2.z);

    glVertex3f(v2.x,v2.y,v2.z);
    glVertex3f(v3.x,v3.y,v3.z);

    glVertex3f(v3.x,v3.y,v3.z);
    glVertex3f(v0.x,v0.y,v0.z);
    */

    glEnd();

    glPopMatrix();

    glEnable(GL_LIGHTING);

    glEnable(GL_CULL_FACE);

    glDisable(GL_BLEND);


}

void scene::DrawMultiSelect(int x,int y, int x1, int y1)
{
    GLuint *buffer=(GLuint*) ::malloc(sizeof(GLuint)*10000);

    GLint viewport[4];



    glSelectBuffer(10000,buffer );


    glRenderMode(GL_SELECT);

    glMatrixMode(GL_PROJECTION);





    //glPushMatrix ();
    {
    //inserimento della definizione della viewport per gli hint del mouse
    glLoadIdentity();

    glGetIntegerv( GL_VIEWPORT , viewport );

    qDebug() << "viewport:" << viewport[0] << " " << viewport[1]<<" " << viewport[2] << " " << viewport[3];

   // gluPickMatrix(x,viewport[3]-y,x1,y1,viewport);
    qDebug() << "x:"<< x << "y:" <<  viewport[3]-y << "x1" << x1 << "y1" << y1;

    InitPipeline();

    //if(m_scene==SCENE::s3d)
    //	gluPerspective(45.0f,1.5f,10,10000);


    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //initNames();


    //m_maincamera.Update(100.0F);
    //m_maincamera.Draw();


//	PosizionaLuce();


    glInitNames();
    glPushName(0);
    //if (m_nModality==2)

    switch(m_modedoc)
    {
    case SCENE::normal:

            qDebug() << "Edit mode: select";

            DrawEdit();

            break;
    case SCENE::animation:
            DrawEditAnimation();

            break;
    case SCENE::edit:
            switch(this->m_modeedit)
            {

            case SCENE::vertex:

                    DrawEditVertex();

                    break;

            case SCENE::line:

                    DrawEditLine();

                    break;

            case SCENE::polygon:

                    DrawEditPoligon();

                    break;
            }

            if(_input.isnot_movevertex())
                //m_oMoveEdit.DrawSelect();

            break;


    }

    }//glPopMatrix();

    //glMatrixMode(GL_MODELVIEW);
    //glFlush();

    m_hint=glRenderMode(GL_RENDER);

    int ns=-1;
    qDebug() << "hint select:" << m_hint;


        if (m_hint)
    {
                int n=0;double minz=buffer[1];
        for(int i=1;i<m_hint;i++)
        {
                        ns=buffer[3+i*4];

                        switch(m_modedoc)
                        {
                        case SCENE::normal:
                                SelectObject(ns);
                        break;
                        case SCENE::animation:
                                SelectObjectAnimation(ns);
                        break;
                        case SCENE::edit:

                                switch(m_modeedit)
                                {
                                case SCENE::vertex:

                                        SelectObjectVertex(ns);
                                        break;

                                case SCENE::line:

                                        SelectObjectLine(ns);
                                        break;
                                case SCENE::polygon:

                                        SelectObjectPoligon(ns);
                                        break;
                                }
                        break;
                }
                        /*
            if ( buffer[1+i*4] < minz )

                        {
                                n=i;
                                minz=buffer[1+i*4];
                        }
                        */
        }

        //ns=buffer[3+n*4];

    }
        else
                return;





}
int scene::SelectTools(int x,int y, int x1, int y1)
{
    l3d_vertex_fast pos;
    GLuint *buffer=(GLuint*) ::malloc(sizeof(GLuint)*10000);

    GLint viewport[4];



    glSelectBuffer(10000,buffer );


    glRenderMode(GL_SELECT);


    glMatrixMode(GL_PROJECTION);



    glLoadIdentity();

    glPushMatrix ();
    {
        glGetIntegerv( GL_VIEWPORT , viewport );

        qDebug() << "viewport:" << viewport[0] << " " << viewport[1]<<" " << viewport[2] << " " << viewport[3];

        //gluPickMatrix(x,viewport[3]-y,5,5,viewport);
        qDebug() << "x:"<< x << "y:" <<  viewport[3]-y << "x1" << x1 << "y1" << y1;

        _main_view.Prospective();
        //InitPipeline();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        _main_view.Camera();




        glInitNames();
        glPushName(~0);

        pos=m_maindocument->getmainscenedoc()->gettoolpos();




        switch(m_selecttool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected

                     if(_input.isnot_movevertex())
                        _main_view.drawTool(pos,true);


                break;

               case SCENE::st_scale://move tool selected

                    //if(!m_movevertex[0] && !m_movevertex[1] && !m_movevertex[2])

                    _main_view.drawTool(pos,true);

                break;

                case SCENE::st_rotate://move tool selected

                    //if(!m_movevertex[0] && !m_movevertex[1] && !m_movevertex[2])
                     _main_view.drawTool(pos,true);

                 break;
            }




    }

    glPopMatrix();


//    glFlush();

    m_hint=glRenderMode(GL_RENDER);

    int ns=-1;
    qDebug() << "hint select:" << m_hint;

    if (m_hint)
    {
        int n=0;double minz=buffer[1];

        for(int i=1 ; i <m_hint ; i++)
        {
            if ( buffer[1+i*4] < minz )
            {
                n=i;
                minz=buffer[1+i*4];
            }
        }

        ns=buffer[3+n*4];

    }
    else
    {
        free(buffer);
        return (-1);

    }


    if (ns==20000 || ns==20001 || ns==20002 || ns==20003)
    {
        switch(m_modedoc)
        {
        case SCENE::normal:

            switch(m_selecttool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected


                   _input.move(true,ns-20000);

                   //m_moveobj[ns-20000]=true;

               break;

               case SCENE::st_scale://move tool selected

                   _input.scale(true,ns-20000+1);
                   //m_bscale=true;
                   //m_scalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://move tool selected

                    _input.rotate(true,ns-20000+1);
                    //m_brotate=true;
                    //m_rotatexyz=ns-20000+1;

                break;
            }
            break;
        case SCENE::edit:
            switch(m_selecttool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected

                    _input.move_vertex(true,ns-20000);
                   //m_bmove=true;

                   //m_movevertex[ns-20000]=true;

               break;

               case SCENE::st_scale://scale tool selected

                    _input.scale_vertex(true,ns-20000+1);
                   //m_bscale=true;
                   //m_scalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://rotate tool selected

                    _input.rotate_vertex(true,ns-20000+1);
                    //m_brotate=true;
                    //m_rotatexyz=ns-20000+1;

                break;
            }
            break;

        case SCENE::animation:
            switch(m_selecttool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected


                   m_animationstate->m_bismove=true;

                   m_animationstate->m_moveobj[ns-20000]=true;

               break;

               case SCENE::st_scale://scale tool selected

                   m_animationstate->m_bisscale=true;
                   m_animationstate->m_iscalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://rotate tool selected

                    m_animationstate->m_bisrotate=true;
                    m_animationstate->m_irotatexyz=ns-20000+1;

                break;
            }
            break;
        }
    }
    free(buffer);

    return(ns);


}

void scene::DrawSelect(int x,int y, int x1, int y1)
{
    //int st=SelectTools(x,y,x1,y1);

    //if(st==20000 || st==20001 || st==20002|| st==20003)
    //    return;
/*
    GLuint *buffer=(GLuint*) ::malloc(sizeof(GLuint)*10000);

    GLint viewport[4];



        glSelectBuffer(10000,buffer );


        glRenderMode(GL_SELECT);

        glMatrixMode(GL_PROJECTION);



        glLoadIdentity();

        glPushMatrix ();
        {
        //inserimento della definizione della viewport per gli hint del mouse


        glGetIntegerv( GL_VIEWPORT , viewport );

        qDebug() << "viewport:" << viewport[0] << " " << viewport[1]<<" " << viewport[2] << " " << viewport[3];

        gluPickMatrix(x,viewport[3]-y,5,5,viewport);
        qDebug() << "x:"<< x << "y:" <<  viewport[3]-y << "x1" << x1 << "y1" << y1;

        //InitPipeline();
        _main_view.Prospective();

        //if(m_scene==SCENE::s3d)
        //	gluPerspective(45.0f,1.5f,10,10000);


        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //initNames();


        //m_maincamera.Update(100.0F);
        _main_view.Camera();
        //m_maincamera.Draw();


//	PosizionaLuce();


        glInitNames();
        glPushName(~0);
        //if (m_nModality==2)

        switch(m_modedoc)
        {
        case SCENE::normal:

                qDebug() << "Edit mode: select";

                DrawEdit();

                break;
        case SCENE::animation:
                DrawEditAnimation();

                break;
        case SCENE::paint:
                switch(this->m_modeedit)
                {

                case SCENE::vertex:

                        DrawEditVertex();

                        break;

                case SCENE::line:

                        DrawEditLine();

                        break;

                case SCENE::polygon:

                        DrawEditPoligon();

                        break;
                }

                break;
        case SCENE::edit:
                switch(this->m_modeedit)
                {

                case SCENE::vertex:

                        DrawEditVertex();

                        break;

                case SCENE::line:

                        DrawEditLine();

                        break;

                case SCENE::polygon:

                        DrawEditPoligon();

                        break;
                }

                break;


        }

        }glPopMatrix();

        //glMatrixMode(GL_MODELVIEW);
        //glFlush();

         m_hint=glRenderMode(GL_RENDER);

        int ns=-1;
        qDebug() << "hint select:" << m_hint;

        if (m_hint)
        {
            int n=0;double minz=buffer[1];

            for(int i=1 ; i <m_hint ; i++)
            {
                if ( buffer[1+i*4] < minz )
                {
                    n=i;
                    minz=buffer[1+i*4];
                }
            }

            ns=buffer[3+n*4];

        }
        else
        {
            if(m_modedoc==SCENE::normal)
                UnselectAllObjects();
            Main_insert->update();
            return;

        }*/
    //int ns=SelectTools(x,y,x1,y1);

    //if(ns==20000 || ns==20001 || ns==20002|| ns==20003)
    //    return;

    int ns=_main_view.drawSelect(x,y,x1,y1);
    if(ns==-1)
        return;


        qDebug() << "ns:" << ns;
        switch(m_modedoc)
        {
        case SCENE::normal:
                SelectObject(ns);
                break;
        case SCENE::animation:
                SelectObjectAnimation(ns);
                break;
        case SCENE::paint:
                switch(m_modeedit)
                {
                case SCENE::vertex:
                     SelectObjectVertex(ns);
                     break;

                case SCENE::line:
                    SelectObjectLine(ns);
                    break;
                case SCENE::polygon:
                    SelectObjectPoligon(ns);
                    break;
                }
                break;
        case SCENE::edit:
                switch(m_modeedit)
                {
                case SCENE::vertex:
                        SelectObjectVertex(ns);
                        break;

                case SCENE::line:
                        SelectObjectLine(ns);
                        break;
                case SCENE::polygon:
                        SelectObjectPoligon(ns);
                        break;
                }
                break;
        }

        //free(buffer);

        Main_insert->update();

}
void scene::SelectAllLines(int index,int lindex)
{
    /*
        Q_ASSERT(index >=0 && index < m_object.size());

        if (lindex <0 || lindex > m_object[index].m_line.size())
                return;

        if(m_object[index].m_bselected)
        {
                line mline=m_object[index].m_line[lindex];

                if(abs(mline.GetVertice(0) - mline.GetVertice(1)) == 1)
                {
                        //caso in cui la linea  orizzontale selezionare tutte le linee consecutive orizzontali a destra
                        int vstart=mline.GetVertice(0);
                        int vend=mline.GetVertice(1);
                        for(int ix=0; ix < m_object[index].m_line.size(); ix++)
                        {
                                if(m_object[index].m_line[ix].GetVertice(0)==vstart && abs(m_object[index].m_line[ix].GetVertice(0) - m_object[index].m_line[ix].GetVertice(1)) == 1)
                                {
                                        m_object[index].m_line[ix].SetSelected(true);
                                        m_object[index].local_vertex[m_object[index].m_line[ix].GetVertice(0)].SetSelected(true);
                                        m_object[index].local_vertex[m_object[index].m_line[ix].GetVertice(1)].SetSelected(true);
                                        vstart=m_object[index].m_line[ix].GetVertice(1);
                                }

                        }
                        for(int ix= m_object[index].m_line.size()-1; ix >=0 ; ix--)
                        {
                                if(m_object[index].m_line[ix].GetVertice(1)==vend && abs(m_object[index].m_line[ix].GetVertice(0) - m_object[index].m_line[ix].GetVertice(1)) == 1)
                                {
                                        m_object[index].m_line[ix].SetSelected(true);
                                        m_object[index].local_vertex[m_object[index].m_line[ix].GetVertice(0)].SetSelected(true);
                                        m_object[index].local_vertex[m_object[index].m_line[ix].GetVertice(1)].SetSelected(true);
                                        vend=m_object[index].m_line[ix].GetVertice(0);
                                }
                        }
                }


        }*/


}
void scene::SelectObjectPoligon(int ns)
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->selecteditpoligon(ns,_input._shift,m_bctrl);
        break;
    }

    {

        //m_oMoveEdit.SetWorldPos(wpapp[0],wpapp[1],wpapp[2]); da reimplamentare

    }
    if (_input._shift)
    {
        if (ns==20000)
            _input.move_vertex(true,0);

        else if (ns==20001)
            _input.move_vertex(true,1);

        else if (ns==20002)
            _input.move_vertex(true,2);


    }

}
void scene::SelectObjectPoligonPaint(int ns)
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->selecteditpoligonpaint(ns,_input._shift,m_bctrl);
        break;
    }


}

void scene::Spin()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
        //m_maindocument->getmainscenedoc()->spin();
        break;
    }

}
void scene::Spin(l3d_uint v)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
        //m_maindocument->getmainscenedoc()->spin(v);
        break;
    }

}
void scene::SelectObjectLine(int ns)
{
        switch(m_docselect)
        {
            case SCENE::dsmainscene:
                m_maindocument->getmainscenedoc()->selecteditline(ns,_input._shift,m_bctrl);
            break;
        }





        if (ns==0)
                return;

        if (_input._shift)
        {


                if (ns==20000)
                    _input.move_vertex(true,0);

                else if (ns==20001)
                    _input.move_vertex(true,1);

                else if (ns==20002)
                    _input.move_vertex(true,1);


        }
}
void scene::SelectObjectVertex(int ns)
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->selecteditvertex(ns,_input._shift,m_bctrl);
        break;
    }
        int osel=-1;

        int xo;




        int nSize,obsel=-1;
        if (ns==0)
                return;

        if (_input._shift)
        {


                if (ns==20000)
                    _input.move_vertex(true,0);

                else if (ns==20001)
                    _input.move_vertex(true,1);

                else if (ns==20002)
                    _input.move_vertex(true,1);


        }
}
void scene::SelectObjectAnimation(int ns)
{


        getdocument()->getmainscenedoc()->getmanageranimation()->SelectObjectAnimation(ns);


}
void scene::SelectObjectDocument(int no)
{
    if(no<0 || no >m_maindocument->getmainscenedoc()->getSizeObjects())
        return;
    pl3d_mesh_struct obj=m_maindocument->getmainscenedoc()->getObject(no);

    obj->selected(true);

}
void scene::SelectObjectMainScene(int ns)
{
  //   m_maindocument->getmainscenedoc()->draw();
   //  m_maindocument->getmainscenedoc()->selectobject(ns);
    /*
     int nSize=m_maindocument->getmainscenedoc()->getSizeObjects();
     if(m_moveobj[0] || m_moveobj[1] || m_moveobj[2])
     {
             action cact;
             vertex vapp;

             for (int nIndex=0; nIndex<nSize; nIndex++)
             {
                 object3d obj=*m_maindocument->getmainscenedoc()->getObject(nIndex);
                     if(obj.m_bselected)
                     {
                             vapp=obj.world_pos;

                             cact.SetActionSposta(vapp);
                             cact.m_nObject=nIndex;

                             obj.AddAction(cact);

                     }
             }


     }*/
    _input._movemesh[0]=false;
    _input._movemesh[1]=false;
    _input._movemesh[2]=false;

     if(ns!=20000 && ns!=20001 && ns!=20002 && ns!=20003)
     {
         if(!_input._shift)
            m_maindocument->getmainscenedoc()->unselectobject();

         m_maindocument->getmainscenedoc()->selectobject(ns);



         //to-do spedire un messaggio per aggiornare la view object dell'interfaccia
         //principale


            /*
             for (int nIndex=0; nIndex<nSize; nIndex++)

             {
                 object3d obj=m_maindocument->getmainscenedoc()->getObject(nIndex);

                     if(!_input._shift)
                             obj.SetSelected(false);
                     qDebug() << "object:" << obj.m_name;
                     if (ns == obj.m_name)
                     {
                            obj.m_bselected=true;


                             osel=nIndex;
                     }



             }
             // da inserire  ??
             /*nSize=m_mash.size();
             for (int nIndex=0; nIndex<nSize; nIndex++)
             {
                     if(ns == pDoc->m_mash[nIndex].GetName())
                             pDoc->m_mash[nIndex].SetSelect(true);



             }
             */

             //verificare se una m_telecamera  stata selezionata
             /*
             nSize=m_telecamera.size();

             for (int nIndex=0; nIndex<nSize; nIndex++)

             {
                     m_telecamera[nIndex].SetSelected(false);
                     if (ns == m_telecamera[nIndex].GetName())
                             m_telecamera[nIndex].SetSelected(true);


             }
             nSize=m_aligth.size();
             //m_bligthselected=false;
             for (int nIndex=0; nIndex<nSize; nIndex++)
             {
                     if(!_input._shift)
                             m_aligth[nIndex].m_bselected=false;
                     if(ns==m_aligth[nIndex].sname || ns==m_aligth[nIndex].sname+1
                             || ns==m_aligth[nIndex].sname+2 || ns==m_aligth[nIndex].sname+3)
                     {


                             m_aligth[nIndex].m_bselected=true;
                             m_bligthselected=true;
                     }



             }*/


     }


     if(_input._movemesh[0] || _input._movemesh[1] || _input._movemesh[2] && !m_bligthselected)
     {
             //nSize=m_object.size();
             //aggoiungere codice per le luci
        /*     for (int nIndex=0; nIndex<nSize; nIndex++)
             {
                 object3d obj=*m_maindocument->getmainscenedoc()->getObject(nIndex);
                 if ( obj.m_bselected)
                       obj.RecPos();

             }

        */

     }

     if(_input._move && m_bligthselected)
     {
             /*int nSize=m_aligth.size();

             for(int nIndex=0 ; nIndex < nSize ; nIndex++ )
             {
                     if(m_aligth[nIndex].m_sphere->m_bselected)
                             m_aligth[nIndex].m_sphere->RecPos();
             }
             */

     }

/*	if(osel!=-1 && !_input._shift)	da rivedere

             for (int nIndex=0; nIndex<nSize; nIndex++)

                     if(nIndex!=osel)

                             m_object[nIndex].m_bselected=false;
*/
}

void scene::SelectObject(int ns)
{
        //int nSize=m_object.size();
        switch(m_docselect)
        {
            case SCENE::dsmainscene:
               SelectObjectMainScene(ns);
            break;
        }



}
void scene::DrawEditPoligon()
{
        switch(m_docselect)
        {
            case SCENE::dsmainscene:
                m_maindocument->getmainscenedoc()->draweditpoligon();
            break;
        }

}
void scene::DrawEditLine()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->draweditline();
        break;
    }

}

void scene::DrawEditVertex()
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->draweditvertex();
        break;
    }


}

void scene::DrawEditAnimation()
{

        getdocument()->getmainscenedoc()->getmanageranimation()->DrawEdit();




}
void scene::DrawEdit()
{

        //to-do inserire codice per la selezione dei puntatori


        //vertex appv;// =   m_maindocument->getmainscenedoc()->gettoolpos();

        switch(m_docselect)
        {
            case SCENE::dsmainscene:
                m_maindocument->getmainscenedoc()->drawedit();
                //appv=m_maindocument->getmainscenedoc()->gettoolpos();
            break;
        }
        switch(m_selecttool)
        {
            case SCENE::st_normal:
            break;
            case SCENE::st_move://move tool selected

                //m_oMoveEdit.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
                //m_oMoveEdit.DrawSelect();

            break;
        case SCENE::st_scale://move tool selected

            //m_toolscale.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
            //m_toolscale.DrawSelect();

        break;
        }





}

void scene::DrawPiano()
{
        int nIndex=0;
        int nVert=0,ix;
        float fx=0.0F,fz=0.0F;

        float width=300.0F;
        float densita;

        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glPushMatrix();

        glTranslatef(0.0F,0.0F,0.0F);

        glRotatef(0.0F,1.0,0.0,0.0);
        glRotatef(0.0F,0.0,1.0,0.0);
        glRotatef(0.0F,0.0,0.0,1.0);

        //glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
        //int nNorm= sqrt((double) pdoc->m_plane.num_vertici);
        //glColor3f(pdoc->m_plane.m_color[0],pdoc->m_plane.m_color[1],pdoc->m_plane.m_color[2]);

        glLineWidth(1.0F);

        glBegin(GL_LINES);

        fx=0.0F;
        fz=0.0F;

        //densita=m_maincamera.vpos.GetY() * 0.2F;

        densita=width*4.0f;

        glColor3f(0.6F,0.6F,0.6F);

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {

                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx+width,0.0F,fz-width);


                fz+=(densita/width);
        }
        fx=0.0F;
        fz=0.0F;

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {
                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx-width,0.0F,fz+width);

                fx+=(densita/width);
        }

        //Disegno frecce x,y,z

        glColor3f(0.0F,1.0F,0.0F);

        glVertex3f(-width,0.0F,0.0F);
        glVertex3f(width,0.0F,0.0F);

        glColor3f(0.0F,0.0F,1.0F);

        //glVertex3f(0.0F,0.0F,0.0F);
        //glVertex3f(0.0F,20.0F,0.0F);

        glColor3f(1.0F,0.0F,0.0F);

        glVertex3f(0.0F ,0.0F ,-width);
        glVertex3f(0.0F ,0.0F , width);


        glEnd();
        glPopMatrix();

        glEnable(GL_LIGHTING);

}
void scene::DrawPointer()
{
        int first=0,x;
        int nSize=0;//m_object.size();
        //vertex wp;
        float wpapp[3]={0.0f,0.0f,0.0f};

        //calcolo della nuova posizione
        if(m_modedoc==SCENE::normal)
        {

                for (x=0 ; x < nSize ; x++)
                {
                        //if(m_object[x].m_bselected)
                        {
                              //  wpapp[0]+=m_object[x].world_pos.GetX();
                              //  wpapp[1]+=m_object[x].world_pos.GetY();
                              //  wpapp[2]+=m_object[x].world_pos.GetZ();
                                first++;

                        }
                }

                if(first>1)
                {

                        wpapp[0]/=first;
                        wpapp[1]/=first;
                        wpapp[2]/=first;

                }
                first=0;

                /*nSize=this->m_aligth.size();

                for(x=0; x < nSize; x++)
                {
                        if(m_aligth[x].m_sphere->m_bselected)
                        {
                                if(first == 0 )
                                {
                                        wpapp[0]=0.0f;
                                        wpapp[1]=0.0f;
                                        wpapp[2]=0.0f;
                                }
                                wpapp[0] += m_aligth[x].m_pos.GetX();
                                wpapp[1] += m_aligth[x].m_pos.GetY();
                                wpapp[2] += m_aligth[x].m_pos.GetZ();
                                first++;
                        }
                }/*/
                if(first>1)
                {

                        wpapp[0]/=first;
                        wpapp[1]/=first;
                        wpapp[2]/=first;

                }
        }
        if(m_modedoc==SCENE::animation)
        {


        }
        if(m_modedoc==SCENE::edit)
        {
                /*nSize=m_object.size();

                for (x=0 ; x < nSize ; x++)
                {
                        if(m_object[x].m_bselected)
                        {
                                //calcolo della nuova posizione
                                first=0;

                                /*for (int ix=0 ; ix < this->m_object[x].local_vertex.size() ; ix++)
                                {
                                        if(m_object[x].local_vertex[ix].IsSelected())
                                        {

                                                wpapp[0]+=m_object[x].local_vertex[ix].GetX();
                                                wpapp[1]+=m_object[x].local_vertex[ix].GetY();
                                                wpapp[2]+=m_object[x].local_vertex[ix].GetZ();

                                                first++;
                                        }
                                }
                                if(first>1)
                                {
                                        wpapp[0]/=first;
                                        wpapp[1]/=first;
                                        wpapp[2]/=first;
                                }
                                wpapp[0]  += m_object[x].world_pos.GetX() ;
                                wpapp[1]  += m_object[x].world_pos.GetY() ;
                                wpapp[2]  += m_object[x].world_pos.GetZ() ;



                        }
                }*/


        }

        //wp.SetVertex(wpapp[0],wpapp[1],wpapp[2]);

        //m_oMoveEdit.world_pos.SetVertex(wpapp[0],wpapp[1],wpapp[2]);
        //m_oMoveEdit.m_radius=m_maincamera.GetRadius();
        //m_oMoveEdit.Draw(true);

}

void scene::DrawContainer()
{

        //m_container.Draw();

}
void scene::Draw()
{
        //piano
        //vertex appv ;

        DrawPiano();

        switch(m_docselect)
        {
            case SCENE::dsmainscene:
                m_maindocument->getmainscenedoc()->draw();
                //appv = m_maindocument->getmainscenedoc()->gettoolpos();
                //fmax= m_maindocument->getmainscenedoc()->getmax();

            break;
        }

        //Drawtool(appv);



}
void scene::Drawtool(l3d_vertex_fast appv)
{
    float fmax=-1.0F;
    switch(m_selecttool)
    {
        case SCENE::st_normal:

        break;
        case SCENE::st_move://move tool selected

            //m_oMoveEdit.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
            //m_oMoveEdit.Draw(false);

        break;
        case SCENE::st_scale:

            //m_toolscale.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
            //m_toolscale.Draw(true);

        break;
        case SCENE::st_rotate:

            //m_toolrotate.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
            //m_toolrotate.setmax(fmax);
            //m_toolrotate.Draw(true);

        break;

    }


}

void scene::Drawtexture()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->drawtexture();
            //appv = m_maindocument->getmainscenedoc()->gettoolpos();


        break;
    }

}

void scene::InitAnimation(int index)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->InitAnimation(index);

}
void scene::ViewAnimationFrame(int aindex,int findex)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->ViewAnimationFrame(aindex,findex);


}
void scene::PlayAnimation(int nplay)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->PlayAnimation(nplay);


}
void scene::DrawAnimation(int index)
{
        DrawPiano();

        if(m_bplay)
        {
                PlayAnimation(m_iplay);
                return;
        }

        getdocument()->getmainscenedoc()->getmanageranimation()->DrawAnimation(index);

        //vertex appv=getdocument()->getmainscenedoc()->getmanageranimation()->gettoolpos(index);

        //Drawtool(appv);

}
void scene::AddProject(string name,PROJECT::ProjectType type)
{
    /*
        if(_pmanager=NULL)
                _pmanager= new projectManager();
        char *cname=(char*)name.data();

        Project newp(cname,type);

        _pmanager->AddProject(newp);
        _pmanager->CreateProject(&newp);
    */
}
/*void scene::AddProjectObject(int pindex, object3d obj)
{
       // _pmanager->AddProjectObject(pindex,obj);
}*/
void scene::AddMaterial(l3d_material_struct mat)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->addmaterial(mat);
        break;
    }
}
void scene::AddObjectMaterial(l3d_material_struct mat)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            //m_maindocument->getmainscenedoc()->addmaterialandset(&mat);
        break;
    }
}
void scene::AddMaterialMainScene(l3d_material_struct mat)
{
    m_maindocument->getmainscenedoc()->addmaterial(mat);
}

/*void scene::AddObject(object3d obj)
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            if(m_modedoc==SCENE::animation)
            {
                animatedmesh am(obj);

                AddAnimationObject(am,m_animationstate->m_ianiselect);
            }
            else ;
                //m_maindocument->getmainscenedoc()->addObject(obj);
        break;
    }




}*/
/*
void scene::AddObjectMainScene(object3d obj)
{
    string mname,msubname;

    mname="object";
    mname.append("%d",m_maindocument->getmainscenedoc()->getSizeObjects());
    msubname=obj.getsubname();

    //obj.setName(mname,msubname);

    if(this->m_modedoc==SCENE::animation)
    {
        animatedmesh am(obj);

        AddAnimationObject(am,m_animationstate->m_ianiselect);
    }
    else ;
        //m_maindocument->getmainscenedoc()->addObject(obj);

}
*/
/*void scene::AddObject(object3d *obj)
{
        /*object3d no;
        string name;
        //no=*obj;
        name="";
        name.append("object%d",m_object.size());
        obj->setName(name,"");
        no=*obj;
        m_object.push_back(no);

}*/
void scene::AddObject(l3d_mesh_type _type,float * objpar)
{







        if(m_modedoc==SCENE::animation)
        {
            //animatedmesh am(obj);

            //AddAnimationObject(am,m_animationstate->m_ianiselect);
        }
        else
        {
            m_maindocument->getmainscenedoc()->addmesh(_type,objpar);

            //m_maindocument->getmainscenedoc()->addObject(obj);

        }
}
/*void scene::AddTelecamera(telecamera tel)
{
        m_telecamera.push_back(tel);
}
*/
// scene member functions
void scene::AddLight(LigthType t)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->addlight(t);
        break;
    }
}


void scene::AddLigth(pl3d_light ligth)
{

       // m_aligth.push_back(ligth);

}
void scene::AddNewAnimation(string name, int nframe)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->AddNewAnimation(name,nframe);

}
void scene::AddAnimation(animate newani)
{
    if(getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimation()==0)
        m_animationstate->m_ianiselect=0;
    else
        m_animationstate->m_ianiselect=getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimation()-1;

    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimation(newani);


}

void scene::AddMainCameraAngle(float ang[3])
{
        //m_maincamera.AddAngles(ang);
        //m_maincamera.Update();
}
void scene::AddAnimationObjectNew(int *pobj,int no)
{
        int *appo;
        bool isp;
        int nSizeObj=GetSizeObject();

        for (int x=0; x < nSizeObj ; x++)
        {
                int nobj;
                bool isp=false;

                appo=pobj;
                for(int ix=0; ix < no; ix++)
                        if(*appo++==x)
                                isp=true;

                if(isp)
                {
                        /*object3d  appobj;

                        appobj=GetObject(x);


                        AddAnimationObject(appobj,GetSizeAnimation()-1);
                        */



                }
        }
}
void scene::Delete()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:

           switch(m_modedoc)
           {
            case SCENE::normal:
                   m_maindocument->getmainscenedoc()->deleteobjects();

            break;
            case SCENE::animation:

               break;
            case SCENE::edit:
               DeleteEdit();
               break;

            }
        break;
    }
}

void scene::DeleteAnimationFramesAction(int index,int start , int end , int  nobj)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->DeleteAnimationFramesAction(index,start,end,nobj);


}
void scene::DeleteAnimation(int index)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->DeleteAnimation(index);
}
 void scene::ClearAnimationFrame(int index, int findex )
 {
        getdocument()->getmainscenedoc()->getmanageranimation()->ClearAnimationFrame(index,findex);

 }
 void scene::ClearAnimationFrameMove(int index, int findex )
 {
        getdocument()->getmainscenedoc()->getmanageranimation()->ClearAnimationFrameMove(index,findex);

 }
void scene::ClearAnimationFrameScale(int index, int findex )
 {
        getdocument()->getmainscenedoc()->getmanageranimation()->ClearAnimationFrameScale(index,findex);

 }
void scene::ClearAnimationFrameRotate(int index, int findex )
 {
        getdocument()->getmainscenedoc()->getmanageranimation()->ClearAnimationFrameRotate(index,findex);

 }
void scene::DeleteAnimationFrame(int index,int findex)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->DeleteAnimationFrame(index,findex);
}
void scene::DeleteAnimationFrames(int index)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->DeleteAnimationFrames(index);

}
void scene::DeleteAnimationFrameAction(int aindex , int findex , int  nobj)
{

    getdocument()->getmainscenedoc()->getmanageranimation()->DeleteAnimationFrameAction(aindex,findex,nobj);
}

/*void scene::AddAnimationObject(animatedmesh o3, int index)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationObject(o3,index);

}*/
void scene::AddAnimationFrameActionHide(int index,int findex,bool hide)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFrameActionHide(index,findex,hide);

}
void scene::AddAnimationFramesScale(int index,int oindex, int fstart, int fend,l3d_vertex_fast finalpos )
{
    //getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFramesScale(index,oindex,fstart,fend,finalpos);


}


/*void scene::AddAnimationFramesRotate(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos )
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFramesRotate(index,oindex,fstart,fend,finalpos);


}*/
void scene::AddAnimationFramesMove(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos )
{
    //getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFramesMove(index,oindex,fstart,fend,finalpos);


}
void scene::AddAnimationKeyFrame(int findex)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationKeyFrame(findex);



}
void scene::AddAnimationKeyFrameLoc(int findex)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationKeyFrameLoc(findex);


}
void scene::AddAnimationFrame(frame frame, int index)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFrame(frame,index);

}
void scene::AddAnimationFrameAction(action maction,int aindex,int findex)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->AddAnimationFrameAction(maction,aindex,findex);

}
animate scene::GetAnimation(int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->GetAnimation(index));


}

animate* scene::GetpAnimation(int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->GetpAnimation(index));


}

void scene::SetEditMode(SCENE::ModeEdit mode)
{
        m_modeedit=mode;
        switch(m_docselect)
        {
            case SCENE::dsmainscene:
                m_maindocument->getmainscenedoc()->setedit(mode);
            break;
        }

}
SCENE::ModeEdit scene::GetEditMode()
{
        return m_modeedit;
}
void scene::SetDocument(SCENE::ModeDraw mode)
{

        m_mode=mode;
        m_animationstate->m_mode=mode;
        m_maindocument->getmainscenedoc()->setmodedraw(m_mode);

}
void scene::setColorObject(color ncolor)
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            //m_maindocument->getmainscenedoc()->setcolor(ncolor);
        break;
    }

}

void scene::SetMode(SCENE::ModeDocument md)
{
        m_modedoc=md;
        m_maindocument->getmainscenedoc()->setmodedocument(md);

        if(m_modedoc==SCENE::texture)
        {


            //m_mainviewport[0].init(0.0F,0.0F,m_view.getwidth()/2,m_view.getheigth());
            //m_mainviewport[1].init(m_view.getwidth()/2,0.0F,m_view.getwidth(),m_view.getheigth());

        }//else
           // m_mainviewport[0].init(0.0F,0.0F,m_view.getwidth(),m_view.getheigth());



}
SCENE::ModeDocument scene::GetMode()
{
        return (m_modedoc);

}

int scene::GetSizeObject(void)
{
        return 0;//m_object.size();
}
int scene::GetSizeObjectMainScene(void)
{
        return m_maindocument->getmainscenedoc()->getSizeObjects();
}
int scene::GetSizeLigth()
{
        //return m_aligth.size();
}
int scene::GetSizeTelecamera()
{
        return 0;//m_telecamera.size();
}
int scene::GetSizeAnimation()
{
    return	(getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimation());
}
int scene::GetSizeAnimationFrames(int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimationFrames(index));
}

int scene::GetSizeAnimationObjects(int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimationObjects(index));
}


l3d_vertex_fast scene::GetWPAnimationObject(int aindex,int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->GetWPAnimationObject(aindex,index));


}

int scene::GetSizeAnimationFrameAction(int aindex,int findex)
{

        return (getdocument()->getmainscenedoc()->getmanageranimation()->GetSizeAnimationFrameAction(aindex,findex));


}
pl3d_light scene::GetpLightSelected(int index)
{
    pl3d_light lres=l3d_null;
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            lres=getdocument()->getmainscenedoc()->getlight(index);
        break;
    case SCENE::dsproject:
        //to-do
        break;
    }
    return lres;
}
/*
object3d * scene::GetpObject(int index)
{
        Q_ASSERT(index>=0 && index <m_object.size());

        object3d *obj=NULL;
        if(index >=0 && index <	m_object.size())
                obj =  &m_object[index];

        return obj;
}
*/
pl3d_mesh_struct scene::GetpObjectMainScene(int index)
{
        Q_ASSERT(index>=0 && index < m_maindocument->getmainscenedoc()->getSizeObjects());

        pl3d_mesh_struct obj=l3d_null;
        if(index >=0 && index <	m_maindocument->getmainscenedoc()->getSizeObjects())
                obj =  m_maindocument->getmainscenedoc()->getObject(index);

        return obj;
}
pl3d_mesh_struct  scene::getpobjectmainscene(int index)
{
        //Q_ASSERT(index>=0 && index < m_maindocument->getmainscenedoc()->mscene.mesh_size());

        //pl3d_mesh_struct *obj=NULL;
        //if(index >=0 && index <	m_maindocument->getmainscenedoc()->getSizeObjects())
        //        obj =  m_maindocument->getmainscenedoc()->mscene.elements.find(index);

        //return obj;
}
/*object3d scene::GetObject(int index)
{
        Q_ASSERT(index>=0 && index <m_object.size());

        object3d *obj=NULL;
        if(index >=0 && index <	m_object.size())
                obj =  &m_object[index];
        return *obj;
}
*/
/*animatedmesh scene::GetAnimationObject(int aindex,int index)
{


        return (getdocument()->getmainscenedoc()->getmanageranimation()->GetAnimationObject(aindex,index));
}

animatedmesh *scene::GetAnimationpObject(int aindex,int index)
{
    return (getdocument()->getmainscenedoc()->getmanageranimation()->GetAnimationpObject(aindex,index));


}*/
l3d_material * scene::GetMainSceneMaterials()
{
    return m_maindocument->getmainscenedoc()->getmaterials();
}


void scene::Group()
{

    l3d_vertex_fast v;

    //v.set(m_oMoveEdit.world_pos.x,m_oMoveEdit.world_pos.y,m_oMoveEdit.world_pos.z);
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->addGroup(v);
        break;
    }

}

void scene::UnGroup()
{
    switch(m_docselect)
    {
       case SCENE::dsmainscene:
           m_maindocument->getmainscenedoc()->unGroup();

       break;
    }

}

void scene::SetSmoothGroup(int index)
{
    switch(m_docselect)
    {
       case SCENE::dsmainscene:
           m_maindocument->getmainscenedoc()->setSmoothGroup(index);

       break;
    }


}
void scene::SetFlatGroup(int index)
{
    switch(m_docselect)
    {
       case SCENE::dsmainscene:
          // m_maindocument->getmainscenedoc()->setFlatGroup(index);

       break;
    }


}
void scene::SetScale(bool bscale)
{

    _input.scale(bscale,5);

}

void scene::SetInsert(bool ni)
{
    m_binsert=ni;
}

void scene::SetScaleValue(float fscale[3])
{
        m_fscale[0]=fscale[0];
        m_fscale[1]=fscale[1];
        m_fscale[2]=fscale[2];

}

void scene::SetMove(bool bmove)
{

    _input.move(bmove,4);


}
void scene::SetMoveValue(l3d_vertex_fast vmove)
{
    _input._offset=vmove;



}

void scene::SetRotate(bool brotate)
{

        _input._rotate=brotate;

}
void scene::SetRotateValue(float frotate[3])
{
        m_frotate[0]=frotate[0];
        m_frotate[1]=frotate[1];
        m_frotate[2]=frotate[2];

}
void scene::MoveObjectsVertex(l3d_vertex_fast val)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->MoveObjectsVertex(val);
        break;
    }

}

void scene::MoveObjectVertex(int index, l3d_vertex_fast val)
{
/*        Q_ASSERT(index >=0 && index < GetSizeObject());

        if(!m_object[index].m_bselected)
                return;

        MoveObjectVertexX(index,val.GetX());
        MoveObjectVertexY(index,val.GetY());
        MoveObjectVertexZ(index,val.GetZ());
*/
}
void scene::MoveObjectVertexX(int index, float val)
{
       /* Q_ASSERT(index >=0 && index < GetSizeObject());

        if(!m_object[index].m_bselected)
                return;

        for(int ix=0; ix < m_object[index].local_vertex.size(); ix++)
        {
                if(m_object[index].local_vertex[ix].IsSelected())
                        m_object[index].local_vertex[ix].AddX(val);
        }*/

}
void scene::MoveObjectVertexY(int index, float val)
{
        //Q_ASSERT(index >=0 && index < GetSizeObject());

        /*if(!m_object[index].m_bselected)
                return;

        for(int ix=0; ix < m_object[index].local_vertex.size(); ix++)
        {
                if(m_object[index].local_vertex[ix].IsSelected())
                        m_object[index].local_vertex[ix].AddY(val);
        }*/

}
void scene::MoveObjectVertexZ(int index, float val)
{
        /*Q_ASSERT(index >=0 && index < GetSizeObject());

        if(!m_object[index].m_bselected)
                return;

        for(int ix=0; ix < m_object[index].local_vertex.size(); ix++)
        {
                if(m_object[index].local_vertex[ix].IsSelected())
                        m_object[index].local_vertex[ix].AddZ(val);
        }*/
}
void scene::Scale(float fscale[3])
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->scale(fscale);
        break;
    }


}
void scene::ScaleVertex(float fscale[3])
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->scalevertex(fscale);
        break;
    }


}
void scene::InvertObjectSelect()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->invertselect();
        break;
    }
}
void scene::ScaleObject(float fscale[3],int index)
{
        /*if(index <0 || index >= m_object.size())
                return;

        m_object[index].m_Scale[0]+=fscale[0];
        m_object[index].m_Scale[1]+=fscale[1];
        m_object[index].m_Scale[2]+=fscale[2];
*/
}

void scene::ScaleAnimation(int index,float fscale[3])
{
        getdocument()->getmainscenedoc()->getmanageranimation()->ScaleAnimation(index,fscale);

}
void scene::ApplyAnimationFrame(int aindex,int findex)
{
        getdocument()->getmainscenedoc()->getmanageranimation()->ApplyAnimationFrame(aindex,findex);

}
void scene::ApplyAnimationFrameActions(int aindex,int findex,int acindex)
{

    getdocument()->getmainscenedoc()->getmanageranimation()->ApplyAnimationFrameActions(aindex,findex,acindex);

}

void scene::ApplyScale()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->applyscale();
        break;
    }

}
void scene::ApplyScaleEdit()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->applyscaleedit();
        break;
    }

}
void scene::ApplyRotate()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->applyrotate();
        break;
    }


}
void scene::ApplyScaleObject(int index)
{
        /*if(index <0 || index >= m_object.size())
                return;
        m_object[index].Scale();*/
}
void scene::ApplyScaleAnimationObject(int aindex,int oindex)
{
      getdocument()->getmainscenedoc()->getmanageranimation()->ApplyScaleAnimationObject(aindex,oindex);

}
void scene::Rotate(float frotate[3])
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->rotate(frotate);
        break;
    }

}
void scene::RotateVertex(float frotate[3])
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            //m_maindocument->getmainscenedoc()->rotatevertex(frotate);
        break;
    }
}

void scene::RotateAnimation(float frotate[3],int index)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->RotateAnimation(frotate,index);


}
void scene::Move(l3d_vertex_fast vmove)
{
        int nSize;

        switch(m_modedoc)
        {
        case SCENE::normal:
               m_maindocument->getmainscenedoc()->move(vmove);

        break;
        case SCENE::animation:
                nSize=GetSizeAnimationObjects(m_animationstate->m_ianiselect);
                m_bismove=false;
                for(int ix=0; ix < nSize; ix++)
                {
                        //if(GetAnimationpObject(m_animationstate->m_ianiselect,ix)->m_bselected)
                        {
                                //GetAnimationpObject(m_animationstate->m_ianiselect,ix)->world_pos.Move(vmove); //to-do da reimpostare

                                m_animationstate->m_bismove=true;
                        }
                }
                break;

        }

}
void scene::MoveObject(l3d_vertex_fast vmove,int index)
{

        /*if(index <0 || index >= m_object.size())
                return;

        m_object[index].world_pos.Move(vmove);
*/

}
void scene::MoveTelecamera(l3d_vertex_fast vmove,int index)
{

        /*if(index <0 || index > m_telecamera.size())
                return;

        m_telecamera[index].Move(vmove);
*/

}

l3d_vertex_fast scene::GetWPTelecamera(int index)
{
        l3d_vertex_fast ver;
       /* if(index <0 || index >=m_telecamera.size())
                return ver;
        else
                return m_telecamera[index].vpos;
*/

}

void scene::MoveAnimation(l3d_vertex_fast move, int index)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->MoveAnimation(move,index);

}
void scene::SelectAllObjectsVertex()
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->SelectAllObjectsVertex();
        break;
    }

}
void scene::UnselectAllObjectsVertex()
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->UnselectAllObjectsVertex();
        break;
    }



}
void scene::SelectAllObjectVertex(int index)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->UnselectAllObjectVertex(index);
        break;
    }


}
void scene::UnselectAllObjectVertex(int index)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->UnselectAllObjectVertex(index);
        break;
    }

}
void scene::SelectAllObjectsLines()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->SelectAllObjectsLines();
        break;
    }


}
void scene::SelectAllObjectLines(int index)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->SelectAllObjectLines(index);
        break;
    }

}
void scene::UnselectAllObjectsLines()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->UnselectAllObjectsLines();
        break;
    }


}
void scene::UnselectAllObjectsQuads()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            //m_maindocument->getmainscenedoc()->UnselectAllObjectsQuads();
        break;
    }
}

void scene::UnselectAllObjectsQuads(int index)
{

}

void scene::UnselectAllObjectLines(int index)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->UnselectAllObjectLines(index);
        break;
    }

}
void scene::SelectAll()
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:
          // mainscenedocument* mainscene=m_maindocument->getmainscenedoc();
           switch(m_modedoc)
           {
            case SCENE::normal:
               //mainscene->selectAll();


            break;
            case SCENE::edit:
               switch(m_modeedit)
               {

               case SCENE::vertex:
                   // mainscene->SelectAllObjectsVertex();

                       break;

               case SCENE::line:

                //mainscene->SelectAllObjectsLines();

                       break;

               case SCENE::polygon:
                   //mainscene->SelectAllObjectsQuads();


                       break;
               }
            break;

            }
        break;
    }
}

void scene::SelectAllObjects()
{

        if(m_maindocument->getmainscenedoc()->getSizeObjects()<=0)
            return;
        for(int ix=0; ix <m_maindocument->getmainscenedoc()->getSizeObjects(); ix++)
                if(!m_maindocument->getmainscenedoc()->getObject(ix)->_display->hide)
                        m_maindocument->getmainscenedoc()->getObject(ix)->selected(true);
        //if(m_object.size()<=0)
        //        return;
        //for(int ix=0; ix < m_object.size(); ix++)
        //        if(!m_object[ix].m_bhide)
        //                m_object[ix].SetSelected(true);
}
void scene::SelectAllObjectsAnimation(int index)
{
       getdocument()->getmainscenedoc()->getmanageranimation()->SelectAllObjectsAnimation(index);


}
void scene::UnselectAllObjects()
{
    m_maindocument->getmainscenedoc()->unselectobject();

}

void scene::UnselectAllObjectsAnimation(int index)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->UnselectAllObjectsAnimation(index);


}

void scene::SelectAllAnimationObjects(int index)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->SelectAllAnimationObjects(index);

}

void scene::UnselectAllAnimationObjects(int index)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->UnselectAllAnimationObjects(index);

}

void scene::MergeObjectsSelected()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->mergeObjectsSelected();
        break;
    }

}

void scene::CopyObjectsSelected()
{
        /*m_ocopy.clear();

        for(int index=0; index < GetSizeObject(); index++)
        {
                if(m_object[index].m_bselected)
                {
                        m_ocopy.push_back(m_object[index]);

                }
        }*/

}

void scene::PasteObjects()
{
        /*if(m_ocopy.size()==0)
                return;

        for(int index=0; index < m_ocopy.size(); index++)
                m_object.push_back(m_ocopy[index]);
*/
}
void scene::Duplicate()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:

           switch(m_modedoc)
           {
            case SCENE::normal:
                   DuplicateObjects();

            break;
            case SCENE::edit:
               switch(m_modeedit)
               {

               case SCENE::vertex:

                       m_maindocument->getmainscenedoc()->duplicatevertex();

                       break;

               case SCENE::line:

                       m_maindocument->getmainscenedoc()->duplicateedge();

                       break;

               case SCENE::polygon:

                       m_maindocument->getmainscenedoc()->duplicateface();

                       break;
               }
            break;

            }
        break;
    }
}

void scene::DuplicateObjects()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:

            m_maindocument->getmainscenedoc()->duplicate();

        break;

    }

}
void scene::SelectWave()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:

           // m_maindocument->getmainscenedoc()->selectwave();

        break;

    }


}
void scene::MergeObjectVertexSelected()
{

}
void scene::DeleteEdit()
{

    switch(m_docselect)
    {
        case SCENE::dsmainscene:

            switch(m_modeedit)
            {

            case SCENE::vertex:

                    m_maindocument->getmainscenedoc()->deleteeditvertex();

                    break;

            case SCENE::line:

                    m_maindocument->getmainscenedoc()->deleteeditedge();

                    break;

            case SCENE::polygon:

                    m_maindocument->getmainscenedoc()->deleteeditface();

                    break;
            }

            break;
        }

}

void scene::DeleteObjectsPolygonSelected()
{
        /*Q_ASSERT(m_object.size()>0);

        for(int ix=0; ix < m_object.size(); ix++)
                if(m_object[ix].m_bselected)
                        DeleteObjectPolygonSelected(ix);
*/
}

void scene::DeleteObjectPolygonSelected(int index)
{
       /* Q_ASSERT(index >=0 && index < m_object.size());

        for(int ix=0; ix < m_object[index].m_poly4.size(); ix++)
        {
                if(m_object[index].m_poly4[ix].IsSelected())
                {
                        //eliminare i poligoni 3 interni
                        int v1,v2,v3,v4;

                        v1=m_object[index].m_poly4[ix].Get(0);
                        v2=m_object[index].m_poly4[ix].Get(1);
                        v3=m_object[index].m_poly4[ix].Get(2);
                        v4=m_object[index].m_poly4[ix].Get(3);

                        for(int ip=0; ip < m_object[index].m_poly.size(); ip++)
                        {

                                int count=0;

                                for(int iv=0; iv <3; iv++)
                                {

                                        if(m_object[index].m_poly[ip].lista_vertici[iv]==v1 ||
                                                m_object[index].m_poly[ip].lista_vertici[iv]==v2 ||
                                                m_object[index].m_poly[ip].lista_vertici[iv]==v3 ||
                                                m_object[index].m_poly[ip].lista_vertici[iv]==v4)

                                                count++;

                                }
                                if(count >=3)
                                {
                                        m_object[index].m_poly.erase(m_object[index].m_poly.begin()+ip);
                                        ip--;
                                }
                        }
                        for(int il=0; il < m_object[index].m_line.size(); il++)
                        {
                                int count=0;
                                for(int iv=0; iv <2; iv++)
                                {
                                        if(m_object[index].m_line[il].GetVertice(iv)==v1 || m_object[index].m_line[il].GetVertice(iv)==v2
                                                || m_object[index].m_line[il].GetVertice(iv)==v3 || m_object[index].m_line[il].GetVertice(iv)==v4)
                                                count++;
                                }
                                if(count >=2)
                                {
                                        m_object[index].m_line.erase(m_object[index].m_line.begin()+il);
                                        il--;
                                }

                        }
                        //rimuovo il poligono
                        m_object[index].m_poly4.erase(m_object[index].m_poly4.begin()+ix);
                        ix=0;
                        // rimuovere vertici rimasti soli
                        int v[4]={v1,v2,v3,v4};
                        for(int iv=0; iv < 4; iv++)
                        {
                                bool fl=true;
                                for(int ip=0; ip < m_object[index].m_poly.size() && fl; ip++)
                                {
                                        if(m_object[index].m_poly[ip].lista_vertici[0]==v[iv] ||
                                                m_object[index].m_poly[ip].lista_vertici[1]==v[iv] ||
                                                m_object[index].m_poly[ip].lista_vertici[2]==v[iv] ||
                                                m_object[index].m_poly[ip].lista_vertici[3]==v[iv])
                                        {
                                                fl=false;

                                        }


                                }
                                for(int ip=0; ip < m_object[index].m_poly4.size() && fl; ip++)
                                {
                                        if(m_object[index].m_poly4[ip].Get(0)==v[iv] ||
                                                m_object[index].m_poly4[ip].Get(1)==v[iv] ||
                                                m_object[index].m_poly4[ip].Get(2)==v[iv] ||
                                                m_object[index].m_poly4[ip].Get(3)==v[iv])
                                        {
                                                fl=false;

                                        }


                                }
                                for(int il=0; il < m_object[index].m_line.size() && fl; il++)
                                {
                                        if(m_object[index].m_line[il].GetVertice(0)==v[iv] || m_object[index].m_line[il].GetVertice(1)==v[iv]
                                                || m_object[index].m_line[il].GetVertice(2)==v[iv] || m_object[index].m_line[il].GetVertice(3)==v[iv])
                                                        fl=false;

                                }
                                if(fl)
                                {
                                        //rimuove il vertice
                                        m_object[index].local_vertex.erase(m_object[index].local_vertex.begin()+v[iv]);

                                        if(v[0]>v[iv])
                                                v[0]--;
                                        if(v[1]>v[iv])
                                                v[1]--;
                                        if(v[2]>v[iv])
                                                v[2]--;
                                        if(v[3]>v[iv])
                                                v[3]--;

                                        for(int ip=0; ip < m_object[index].m_poly.size() ; ip++)
                                        {
                                                if(m_object[index].m_poly[ip].lista_vertici[0]>v[iv])
                                                        m_object[index].m_poly[ip].lista_vertici[0]--;
                                                if(m_object[index].m_poly[ip].lista_vertici[1]>v[iv])
                                                        m_object[index].m_poly[ip].lista_vertici[1]--;
                                                if(m_object[index].m_poly[ip].lista_vertici[2]>v[iv])
                                                        m_object[index].m_poly[ip].lista_vertici[2]--;
                                        }

                                        for(int ip=0; ip < m_object[index].m_poly4.size() ; ip++)
                                        {
                                                int apv[4];
                                                apv[0]=m_object[index].m_poly4[ip].Get(0);
                                                apv[1]=m_object[index].m_poly4[ip].Get(1);
                                                apv[2]=m_object[index].m_poly4[ip].Get(2);
                                                apv[3]=m_object[index].m_poly4[ip].Get(3);

                                                if(apv[0]>v[iv])
                                                        apv[0]--;
                                                if(apv[1]>v[iv])
                                                        apv[1]--;
                                                if(apv[2]>v[iv])
                                                        apv[2]--;
                                                if(apv[3]>v[iv])
                                                        apv[3]--;

                                                m_object[index].m_poly4[ip].Set(apv[0],apv[1],apv[2],apv[3]);

                                        }

                                        for(int il=0; il < m_object[index].m_line.size() ; il++)
                                        {

                                                int l1,l2;

                                                l1=m_object[index].m_line[il].GetVertice(0);
                                                l2=m_object[index].m_line[il].GetVertice(1);

                                                if(l1 > v[iv])
                                                        l1--;

                                                if(l2 > v[iv])
                                                        l2--;

                                                m_object[index].m_line[il].SetLine(l1,l2);

                                        }


                                }





                        }
                }
        }*/


}
void scene::DeleteObjectLinesSelected()
{
       /* Q_ASSERT(m_object.size() >0);
        for(int ix=0; ix < m_object.size();ix++)
                if(m_object[ix].m_bselected)
                        DeleteObjectLineSelected(ix);*/
}
void scene::DeleteObjectLineSelected(int index)
{
        /*Q_ASSERT(index >=0 && index < m_object.size());



        for(int ix=0; ix < m_object[index].m_line.size(); ix++)
                if(m_object[index].m_line[ix].IsSelected())
                {
                        //cancellare i poligoni associati alla linea
                        int v1,v2;
                        v1=m_object[index].m_line[ix].GetVertice(0);
                        v2=m_object[index].m_line[ix].GetVertice(1);

                        //trovare tutti i poligoni a 3 e 4 associati alla linea
                        for(int ip=0; ip<m_object[index].m_poly.size(); ip++)
                        {
                                int count=0;
                                for(int iv=0; iv < 3; iv++)
                                {
                                        if(m_object[index].m_poly[ip].lista_vertici[iv]==v1 || m_object[index].m_poly[ip].lista_vertici[iv]==v2  )
                                                count ++;
                                }

                                if(count>=2)
                                {
                                        m_object[index].m_poly.erase(m_object[index].m_poly.begin()+ip);
                                        ip--;

                                }
                        }
                        for(int ip=0; ip<m_object[index].m_poly4.size(); ip++)
                        {

                                int count=0;

                                for(int iv=0; iv < 4; iv++)
                                {
                                        if(m_object[index].m_poly4[ip].Get(iv)==v1 || m_object[index].m_poly4[ip].Get(iv)==v2)
                                                count ++;

                                }

                                if(count >= 2)
                                {
                                        m_object[index].m_poly4.erase(m_object[index].m_poly4.begin()+ip);
                                        ip--;
                                }

                        }
                        //elimino la linea
                        m_object[index].m_line.erase(m_object[index].m_line.begin()+ix);

                        //to-do cancellare i vertici rimasti soli


                }*/

}
void scene::DeleteObjectsVertexSelected()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            getdocument()->getmainscenedoc()->deleteeditvertex();
        break;
    }
}
void scene::DeleteObjectVertex(int index, int l3d_vertex_fast)
{




}
void scene::DeleteObjectVertexSelected(int index)
{



}
void scene::DeleteObjectsSelected()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            getdocument()->getmainscenedoc()->deleteobjects();
        break;
    }

}

void scene::DuplicateObjectsSelected()
{



}
void scene::PopObjectVertex(int index)
{
        /*if(index <0 || index  >= m_object.size())
                return;

        for (int nVert=0; nVert<m_object[index].local_vertex.size();nVert++)
        {

                m_object[index].local_vertex[nVert].Pop();

        }*/

}

void scene::PushObjectVertex(int index)
{
        /*if(index <0 || index >= m_object.size())
                return;

        for (int nVert=0; nVert<m_object[index].local_vertex.size();nVert++)
        {

                m_object[index].local_vertex[nVert].Push();

        }*/

}

/*void scene::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {
                // TODO: add storing code here
                //da serializzare tutti gli oggetti presenti all'interno
                //del documento
                ar << m_object.size();
                for (int indice=0;indice < m_object.size();indice ++)
                        m_object[indice].Serialize(ar);

                //salva telecamere
                ar << m_telecamera.size();
                for (int nm=0 ; nm<m_telecamera.size(); nm++ )
                {
                        m_telecamera[nm].Serialize(ar);
                }

                //salva animazione
                ar << getdocument()->getmainscenedoc()->getmanageranimation()->size();

                for (int nm=0 ; nm < getdocument()->getmainscenedoc()->getmanageranimation()->size(); nm++ )
                {
                        //ar << getdocument()->getmainscenedoc()->getmanageranimation()->m_frames.size();

                        m_Animate[nm].Serialize(ar);

                }

                //salva luci

                ar << m_aligth.size();

                for(int nl=0; nl <  m_aligth.size(); nl++)
                        m_aligth[nl].Serialize(ar);





        }
        else
        {
                // TODO: add loading code here
                int nmod;
                CMenu * pMenu= AfxGetApp()->m_pMainWnd->GetMenu();
        //	pMenu->CheckMenuItem(ID_MOD_NORMAL,MF_CHECKED);
        //	pMenu->CheckMenuItem(ID_MOD_ANIMAZIONE,MF_UNCHECKED);
                int nSize;
                ar >> nSize;
                m_object.SetSize(nSize);
                for (int indice=0;indice < nSize;indice ++)
                        m_object[indice].Serialize(ar);

                //salva telecamere
                ar >> nSize;
                m_telecamera.SetSize(nSize);

                for (int nm=0 ; nm<nSize; nm++ )
                        m_telecamera[nm].Serialize(ar);


                //salva animazione
                ar >> nSize;
                getdocument()->getmainscenedoc()->getmanageranimation()->SetSize(nSize);

                for (int nm=0 ; nm < nSize; nm++ )
                {
                        //ar << getdocument()->getmainscenedoc()->getmanageranimation()->m_frames.size();

                        m_Animate[nm].Serialize(ar);;

                }

                //salva luci
                ar >> nSize;
                m_aligth.SetSize(nSize);

                for(int nl=0; nl <  nSize; nl++)
                        m_aligth[nl].Serialize(ar);
        }
//		this->m_nframetoview=-1;
//		this->m_frametoview=NULL;
//		this->m_nModality=0;
/*		float x,y,z;
                int appi;
                x=y=z=0.0f;
                //ar >> m_nObjectNum;
                //m_object.SetSize(m_nObjectNum);
                //CMotore3D m_Motore;
                for (int indice=0;indice < m_nObjectNum;indice ++)
                {
                        m_object[indice].Serialize(ar);
                        //m_Motore.CreaNormale(&m_object[indice]);
                }

                ar >> nmod;
                m_telecamera.SetSize(nmod);
                for (int nm=0 ; nm<nmod; nm++ )
                {
                        ar >> x;
                        m_telecamera[nm].vpos.SetX(x);
                        ar >>y;
                        m_telecamera[nm].vpos.SetY(y);
                        ar >> z;
                        m_telecamera[nm].vpos.SetZ(z);

                        ar >> x;
                        m_telecamera[nm].vposwhere.SetX(x);
                        ar >>y;
                        m_telecamera[nm].vposwhere.SetY(y);
                        ar >> z;
                        m_telecamera[nm].vposwhere.SetZ(z);

                        ar >> x;
                        m_telecamera[nm].vposup.SetX(x);
                        ar >>y;
                        m_telecamera[nm].vposup.SetY(y);
                        ar >> z;
                        m_telecamera[nm].vposup.SetZ(z);

                        m_telecamera[nm].Create(m_telecamera[nm].vpos,m_telecamera[nm].vposwhere);








                }
                //carica animazione

                ar >> appi;
                getdocument()->getmainscenedoc()->getmanageranimation()->SetSize(appi);

                for (int nm=0 ; nm < getdocument()->getmainscenedoc()->getmanageranimation()->size(); nm++ )
                {
                        //ar << getdocument()->getmainscenedoc()->getmanageranimation()->m_frames.size();

                        m_Animate[nm].Serialize(ar);

                        for(int ix=0; ix <m_Animate[nm].m_ostate.size(); ix++)
                                ;//m_Motore.CreaNormale(&m_Animate[nm].m_ostate[ix]);

                }
                ar >> appi;
                m_alight.SetSize(appi);

                for(int nl=0; nl <  m_alight.size(); nl++)
                        m_alight[nl].Serialize(ar);




        }
}*/

void scene::SetViewportSize(int width, int heigth)
{
        //opengl.Set_Viewport_Size(width,heigth);

    m_view_width=width;
    m_view_heigth=heigth;

    _main_view.setViewport(0.0F,0.0F,width,heigth);

    //m_view.init(0.0,0.0,width,heigth);



    //m_mainviewport[0].init(0.0,heigth/2.0,width/2.0,heigth/2.0);

    //m_pipelinetop->setviewport(m_mainviewport[0]);

    //m_mainviewport[1].init(width/2.0,heigth/2.0,width/2.0,heigth/2.0);

    //m_mainviewport[2].init(0.0,0.0,width/2,heigth/2);

    //m_mainviewport[3].init(width/2.0,0.0,width/2,heigth/2);





}

void scene::TrackBall(int sx,int sy,int x,int y)
{
        int vsz[2];
        //opengl.Get_Viewport_Size(vsz);
        //sz.cx=vsz[0];
        //sz.cy=vsz[1];

        //m_maincamera.TrackBall(sx,sy,x,y);
}
void scene::SetTrackBall(int x,int y)
{
       // m_maincamera.SetTrackball(x,y);
}

void scene::SetTrackBall(bool fl)
{
        m_btrackball=fl;
}

void scene::OnLButtonUp(unsigned int flags,int pointx,int pointy)
{
    GLint viewport[4];

    glGetIntegerv( GL_VIEWPORT  ,  viewport);

    m_mousecord.x1=pointx;
    m_mousecord.y1=pointy;

    int delx,dely;
    int centerx,centery;

    if(m_bmultiselect && flags==0)
    {
            //DrawSelect(point.x,viewport[3]-point.y,5,5);

            delx=abs(m_mousecord.x-m_mousecord.x1)/2;
            dely=abs(m_mousecord.y-m_mousecord.y1)/2;

            centerx=m_mousecord.x;//+delx;
            centery=m_mousecord.y;//+dely;

            if(delx >0 && dely >0)
                    DrawMultiSelect(centerx,centery,delx,dely);//abs(m_mousecord.x-m_mousecord.x1),abs(m_mousecord.y-m_mousecord.y1));

            m_bmultiselect=false;

    }
    switch(flags)
    {
        case 0://left button
        break;
    case 1://right button
        if(m_baltleft)
            m_btrackball=false;
        break;
    case 2://middle button
        //if(m_baltleft)
            m_bupdown=false;
        break;
    }

   // qDebug() << "in up mouse";
  //  if(m_mousecord.x == m_mousecord.x1 && m_mousecord.y==m_mousecord.y1 && !m_bmultiselect)
    {
    //    qDebug() << "Select";
    //        DrawSelect(pointx,pointy,5,5);

    }

    _input.init_clean();


    _input._movemesh[0]=false;
    _input._movemesh[1]=false;
    _input._movemesh[2]=false;

}

void scene::OnLButtonDown(unsigned int flags,int pointx,int pointy)
{
    static int px=pointx,py=pointy;

    //GLint viewport[4];


    //glGetIntegerv( GL_VIEWPORT  ,  viewport);

    //DrawSelect(pointx,viewport[3]-pointy,5,5);
    //DrawSelect(pointx,pointy,5,5);

    //SetTrackBall(false); ?? da lasciare ?


    if(_input._alt)
    {
        if(flags==0)
            _input._isupdown=true;
        else
            _input._isupdown=false;
        if(flags==1)
            _input._isleftright=true;
        else
            _input._isleftright=false;
        if(flags==2)
            _input._isfrontback=true;
        else
            _input._isfrontback=false;

    }
    else
    {
        _input._isupdown=false;
        _input._isleftright=false;
        _input._isfrontback=false;
    }

    if(m_baltleft && flags==1)
        m_btrackball=true;

    if(m_modedoc==SCENE::animation)
    {
        if(m_animationstate->m_bismove)
        {
            m_animationstate->m_bismove=false;
            m_animationstate->m_moveobj[0]=false;
            m_animationstate->m_moveobj[1]=false;
            m_animationstate->m_moveobj[2]=false;

        }

        if(m_animationstate->m_bisrotate)
            m_animationstate->m_bisrotate=false;
        if(m_animationstate->m_bisscale)
            m_animationstate->m_bisscale=false;

    }
    if(_input._scale && m_modedoc==SCENE::normal)//applicare la scala all'oggetto
    {
            ApplyScale();
    }
    if(_input._scale && m_modedoc==SCENE::edit)//applicare la scala all'oggetto
    {
            //ApplyScaleEdit();
    }



    if(_input._rotate && m_modedoc==SCENE::normal)//applicare la rotazine all'oggetto
    {
            ApplyRotate();
    }






    m_mousecord.x=pointx;
    m_mousecord.y=pointy;

    m_bmultiselect=false;
    if(m_selecttool==SCENE::st_multiselect && flags==0)
    {
            m_bmultiselect=true;


    }
    if(flags==0 && !_input._scale && !_input._rotate && !_input._move && !m_btrackball && m_selecttool!=SCENE::st_multiselect)
        DrawSelect(pointx,pointy,5,5);
    else
    {




       _input.init_clean();

    }

    //m_maincamera.m_track.m_btrack=false;
    //m_maincamera.trackball(false);

    if(flags==2)
    {
       // m_track.m_btrack=true;
       // m_track.init(px,py);
       // m_maincamera.trackball(true);

       // m_maincamera.m_track.run(m_mousecord.x,m_mousecord.y,m_view.getwidth(),m_view.getheigth());

        //m_bupdown=true;
    }
 //   OnLButtonUp( flags, pointx, pointy);

    px=pointx;
    py=pointy;
}
void scene::OnMouseMove(unsigned int nFlags, int pointx,int pointy)
{
        static int px=pointx,py=pointy;
        float fval=10.0F;
        if(_input._isupdown)
        {
            double r=0.0F;

            float zDelta=px-pointx;

            if ( zDelta > 0 )
            {
                    //r += fvalminus;
                    r += fval;
                    m_fortho+=10.0F;
            }
            else
            {
                    //if ( r - fval > 0.0F )
                    {
                           // r -= fvalminus;

                            r -= fval;

                    }
                    m_fortho-=10.0F;
            }
           _main_view.set_prospective_distance(r);
            //if(SCENE::s3d)
            //    SetRadius(r);
        }
        if(_input._isleftright)
        {
            double r=0.0F;

            float zDelta=px-pointx;

            if ( zDelta > 0 )
            {
                    //r += fvalminus;
                    r += fval;
                    m_fortho+=10.0F;
            }
            else
            {
                    //if ( r - fval > 0.0F )
                    {
                           // r -= fvalminus;

                            r -= fval;

                    }
                    m_fortho-=10.0F;
            }
           _main_view.set_prospective_distance2(r);
            //if(SCENE::s3d)
            //    SetRadius(r);
        }
        if(_input._isfrontback)
        {
            double r=0.0F;

            float zDelta=px-pointx;

            if ( zDelta > 0 )
            {
                    //r += fvalminus;
                    r += fval;
                    m_fortho+=10.0F;
            }
            else
            {
                    //if ( r - fval > 0.0F )
                    {
                           // r -= fvalminus;

                            r -= fval;

                    }
                    m_fortho-=10.0F;
            }
           _main_view.set_prospective_distance3(r);
            //if(SCENE::s3d)
            //    SetRadius(r);
        }
        if(m_bupdown)//up and down
        {
            l3d_vertex_fast appv;//=m_maincamera.vpos;
            if(px!=pointx)
                {
            if(px>pointx)
            {
                appv.y+=(1.0F);
            }
            if(px<pointx)
            {
                appv.y+=(-1.0F);
            }
            //m_maincamera.vpos=appv;
            return;
            }
            if(px!=pointx)
            {
                if(py>pointy)
                {
                    appv.x+=(-1.0F);
                }
                if(py<pointy)
                {
                    appv.x+=(1.0F);
                }
                //m_maincamera.vpos=appv;
                return;
            }


        }
        /*
        if(m_maincamera.m_track.m_btrack)
        {
           // m_maincamera.m_track.run(px,py,m_view.getwidth(),m_view.getheigth());


        }
        */


        /*if (m_track.m_btrack ) ??
        {

            m_track.run(m_view_heigth,m_view_width,pointx,pointy);

        }
        */

        _input._offset.set(0.0F,0.0F,0.0F);
        m_fscale[0]=0.0F;
        m_fscale[1]=0.0F;
        m_fscale[2]=0.0F;


        if(_input._move ||  m_animationstate->m_bismove)
        {
            float mval=0.0F;
            if(px>pointx)
            {
                mval=1.0F;
            }
            if(px<pointx)
            {
                mval=-1.0F;

            }
            if(_input._movemesh[0] || m_animationstate->m_moveobj[0])
                _input.addx(mval);
            if(_input._movemesh[1]|| m_animationstate->m_moveobj[1])
                _input.addy(mval);
            if(_input._movemesh[2]|| m_animationstate->m_moveobj[2])
                _input.addz(mval);

        }
        if(_input._scale || m_animationstate->m_bisscale)
        {
                if(px>pointx)
                {
                        if(_input._scalewhere[0] || m_animationstate->m_iscalexyz==1)
                                m_fscale[0]=0.02F;
                        if(_input._scalewhere[1]|| m_animationstate->m_iscalexyz==2)
                                m_fscale[1]=0.02F;
                        if(_input._scalewhere[2]|| m_animationstate->m_iscalexyz==3)
                                m_fscale[2]=0.02F;
                        if(_input._scalewhere[3]|| m_animationstate->m_iscalexyz==4)
                        {
                                m_fscale[0]=0.02F;
                                m_fscale[1]=0.02F;
                                m_fscale[2]=0.02F;
                        }

                }
                if(px < pointx)
                {
                        if(_input._scalewhere[0]|| m_animationstate->m_iscalexyz==1)
                                m_fscale[0]=-0.02F;
                        if(_input._scalewhere[1]|| m_animationstate->m_iscalexyz==2)
                                m_fscale[1]=-0.02F;
                        if(_input._scalewhere[2]|| m_animationstate->m_iscalexyz==3)
                                m_fscale[2]=-0.02F;
                        if(_input._scalewhere[3]|| m_animationstate->m_iscalexyz==4)
                        {
                                m_fscale[0]=-0.02F;
                                m_fscale[1]=-0.02F;
                                m_fscale[2]=-0.02F;
                        }
                }
                if(m_modedoc==SCENE::normal)
                        Scale(m_fscale);
                if(m_modedoc==SCENE::edit)
                        ScaleVertex(m_fscale);
                if(m_modedoc==SCENE::animation)
                        ScaleAnimation(m_animationstate->m_ianiselect,m_fscale);

                m_fscale[0]=m_fscale[1]=m_fscale[2]=0.0F;

        }
        if(_input._rotate|| m_animationstate->m_bisrotate)
        {
                float valf=0.0F;
                m_frotate[0]=0.0F;
                m_frotate[1]=0.0F;
                m_frotate[2]=0.0F;
                if(px>pointx)
                {
                        valf=-1.0F;
                }
                if(px<pointx)
                {
                        valf=1.0F;
                }

                switch(_input._rotatexyz)
                {
                case 1:
                        m_frotate[0]=valf;
                        break;
                case 2:
                        m_frotate[1]=valf;
                        break;
                case 3:
                        m_frotate[2]=valf;
                        break;
                }
                switch(m_animationstate->m_irotatexyz)
                {
                case 1:
                        m_frotate[0]=valf;
                        break;
                case 2:
                        m_frotate[1]=valf;
                        break;
                case 3:
                        m_frotate[2]=valf;
                        break;
                }
                if(m_modedoc==SCENE::normal)
                        Rotate(m_frotate);
                if(m_modedoc==SCENE::edit)
                        RotateVertex(m_frotate);
                if(m_modedoc==SCENE::animation)
                        RotateAnimation(m_frotate,m_animationstate->m_ianiselect);
        }

        if(m_btop)
        {
                if(px>pointx)
                {
                        m_ftop[0]-=.5F;
                }
                if(px<pointx)
                {
                        m_ftop[0]+=.5F;
                }
                if(py>pointy)
                {
                        m_ftop[1]+=.5F;
                }
                if(py<pointy)
                {
                        m_ftop[1]-=.5F;
                }




        }
        if(_input.is_movevertex() )
        {
                l3d_vertex_fast vapp;vapp.set(0.0F,0.0F,0.0F);
                float fval=0.0F ;
                if(px>pointx)
                        fval=0.5F;
                if(px<pointx)
                        fval=-0.5F;

                if(_input._movevertex_where[0])
                    _input.addx(fval);

                if(_input._movevertex_where[1])
                    _input.addy(fval);

                if(_input._movevertex_where[2])
                    _input.addz(fval);


                MoveObjectsVertex(_input._offset);

        }
        m_mousecord.x=pointx;
        m_mousecord.y=pointy;

        //SetTrackBall(pointy,pointx);

        //draw_multy_select_pointer(pointx,pointy);

        px=pointx;
        py=pointy;

}
bool scene::isActions()
{
    return (_input._scale || _input._rotate || _input._move ||_input._alt || _input._isupdown);
}

void scene::OnKeyUp(unsigned int nChar,unsigned int nRepCnt, unsigned int nFlags)
{
        switch(nChar)
        {
            case Qt::Key_Alt://alt left
                m_baltleft=false;
                m_bisupdown=false;
                _input._alt=false;
                _input._isupdown=false;
            break;
            case Qt::Key_Control:
                m_bctrl=false;
            break;
            case Qt::Key_Shift:
                _input._shift=false;
            break;

        }

}
void scene::OnKeyDown(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
        /* da reintrodurre telecamere
        if(btel)
        {
                switch(nChar)
                {
                case 32://switch m_telecamera space
                        if(ntel+1<pdoc->m_telecamera.size())
                                ntel++;
                        else
                                ntel=0;
                        break;

                case 109://-
                        pdoc->m_telecamera[ntel].vpos.SetZ(pdoc->m_telecamera[ntel].vpos.GetZ()+5.0F);
                        break;
                case 107://+
                        pdoc->m_telecamera[ntel].vpos.SetZ(pdoc->m_telecamera[ntel].vpos.GetZ()-5.0F);
                        break;
                case 39://sposta la m_telecamera a destra
                        pdoc->m_telecamera[ntel].vpos.SetX(pdoc->m_telecamera[ntel].vpos.GetX()+5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetX(pdoc->m_telecamera[ntel].vposwhere.GetX()+5.0F);

                        break;

                case 37://sposta la m_telecamera a sinistra
                        pdoc->m_telecamera[ntel].vpos.SetX(pdoc->m_telecamera[ntel].vpos.GetX()-5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetX(pdoc->m_telecamera[ntel].vposwhere.GetX()-5.0F);
                        break;
                case 38://sposta la m_telecamera in alto
                        pdoc->m_telecamera[ntel].vpos.SetY(pdoc->m_telecamera[ntel].vpos.GetY()+5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetY(pdoc->m_telecamera[ntel].vposwhere.GetY()+5.0F);
                        break;
                case 40://sposta la m_telecamera in basso
                        pdoc->m_telecamera[ntel].vpos.SetY(pdoc->m_telecamera[ntel].vpos.GetY()-5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetY(pdoc->m_telecamera[ntel].vposwhere.GetY()-5.0F);
                        break;
                }

        }
    */
        static bool sall=true;
        qDebug() <<"key:" << nChar;
        switch(nChar)
        {
                case Qt::Key_Alt://alt left
                    m_baltleft=true;
                    _input._alt=true;
                    _input._isupdown=true;

                break;
                case Qt::Key_Control://ctrl
                        m_bctrl=true;
                break;
                case 77://m
                        if(m_modedoc==SCENE::normal)
                        {
                                m_modedoc=SCENE::edit;
                                break;
                        }
                        if(m_modedoc==SCENE::edit)
                        {
                                m_modedoc=SCENE::normal;
                                break;
                        }

                break;
                case 78://n
                        m_modedoc=SCENE::normal;
                        break;
                case 13:
      //                  if(m_binsert)
      //                          m_insert->Select();
                break;
                case 37:

                break;
                case 39:
        //                if(m_binsert)
        //                        m_insert->next();
                break;
                case 73://i
                        //if(m_modedoc==SCENE::normal)
                        //        FastAddiction();

                        if(m_modedoc==SCENE::edit)
                                InvertObjectSelect();

                break;
                case 46://d

                        if(m_modedoc==SCENE::normal)
                                DeleteObjectsSelected();
                        if(m_modedoc==SCENE::edit)
                        {
                                switch(m_modeedit)
                                {
                                case SCENE::vertex:
                                        DeleteObjectsVertexSelected();
                                        break;
                                case SCENE::line:
//					DeleteObjectsVertexSelected();
                                        DeleteObjectLinesSelected();
                                        break;
                                case SCENE::polygon:
//					DeleteObjectsVertexSelected();
                                        DeleteObjectsPolygonSelected();
                                        break;
                                }
                        }
                break;
                case 65://a

                        if (_input._scale)
                                _input.scale(true,3);
                        sall=!sall;

                        if(m_modedoc==SCENE::normal)
                                if(sall)
                                        SelectAllObjects();
                                else
                                        UnselectAllObjects();
                        if(m_modedoc==SCENE::edit)
                                switch(m_modeedit)
                                {
                                case SCENE::vertex:
                                        if(sall)
                                                SelectAllObjectsVertex();
                                        else
                                                UnselectAllObjectsVertex();
                                break;
                                case SCENE::line:
                                        if(sall)
                                                SelectAllObjectsLines();
                                        else
                                                UnselectAllObjectsLines();
                                        break;
                                }
                break;
                case 69://e
                        m_modedoc=SCENE::edit;
                        break;
                case 79://o propriety object
                //	OnEditObjectproperty();
                break;

                case 27://esc per annullare spostamenti rotazione e scalatura
                        //annulla spostamento
                        /*if(m_moveobj[0]	||	m_moveobj[1]	||	m_moveobj[2])
                        {
                                m_moveobj[0]=false;
                                m_moveobj[1]=false;
                                m_moveobj[2]=false;

                                int ns=pdoc->m_object.size();
                                int x;

                                for(x=0; x<ns; x++)
                                        if(pdoc->m_object[x].m_bselected)
                                                pdoc->m_object[x].world_pos=pdoc->m_object[x].old_world_pos;





                        }
                        if(m_bRotate)
                        {
                                int ns=pdoc->m_object.size();
                                int x;

                                for(x=0; x<ns; x++)
                                        if(pdoc->m_object[x].m_bselected)
                                                pdoc->m_object[x].resetAng();

                                m_bRotate=false;
                        }

                break;*/
                case 68://d duplicate
                        if(_input._shift)
                                DuplicateObjectsSelected();

                break;

                case 84://m_telecamera
                        /*if(pdoc->m_telecamera.size()==0)
                                btel=false;
                        else
                        {
                                btel=!btel;
                                ntel=0;
                        }*/
                break;
                case 82:
                        _input._rotate=true;

                //	m_bRotate=!m_bRotate;
                //	m_rotatexyz=0;
                break;
                case 80://p
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::polygon);
                        break;
                case 76://l
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::line);
                        break;
                case 86://v
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::vertex);
                        break;
                case 83://s
                        _input.scale(true,3);


                //	m_bModScale=!m_bModScale;
                //	m_scalexyz=0;
                        break;
                case 88://scale x
                        if (_input._scale)
                                _input.scale(true,0);
                        if(_input._rotate)//inserire salvataggio
                                _input._rotatexyz=1;




                        break;
                case 89://scale y
                        if (_input._scale)
                            _input.scale(true,1);
                        if(_input._rotate)//inserire salvataggio
                                _input._rotatexyz=2;
                        break;
                case 90://scale z
                        if (_input._scale)
                            _input.scale(true,2);
                        if(_input._rotate)//inserire salvataggio
                                _input._rotatexyz=3;
                        break;
                case Qt::Key_Shift:
                        _input._shift=true;
                        break;

        }
}
void scene::OnMouseWheel(unsigned int flags,short zDelta,int pointx, int pointy)
{
    float r;//=m_maincamera.GetRadius();
    float fval,fvalminus;

    fval=30.0F;
    fvalminus=5.0F;

    if(m_binsert)
            return;
    if(!_input._shift)
    {
            if ( zDelta > 0 )
            {
                    //r += fvalminus;
                    r += fval;
                    m_fortho+=10.0F;
            }
            else
            {
                    if ( r - fval > 0.0F )
                    {
                            //r -= fvalminus;

                            r -= fval;

                    }
                    m_fortho-=10.0F;
            }
    }
    else
    {
            if ( zDelta > 0 )
            {
                    r += fvalminus;
                    //r += fval;
                    m_fortho+=10.0F;
            }
            else
            {
                    if ( r - fvalminus > 0.0F )
                    {
                            r -= fvalminus;

                            //r -= fval;

                    }
                    m_fortho-=10.0F;
            }
    }
    if(SCENE::s3d)
            SetRadius(r);


}

/*void scene::OnLButtonUpMFC(UINT nFlags, CPoint point)
{
        GLint viewport[4];

        glGetIntegerv( GL_VIEWPORT		   ,  viewport);

        m_mousecord.x1=point.x;
        m_mousecord.y1=point.y;

        int delx,dely;
        int centerx,centery;

        if(m_bmultiselect && _input._shift)
        {
                //DrawSelect(point.x,viewport[3]-point.y,5,5);

                delx=abs(m_mousecord.x-m_mousecord.x1)/2;
                dely=abs(m_mousecord.y-m_mousecord.y1)/2;

                centerx=m_mousecord.x+delx;
                centery=m_mousecord.y+dely;

                if(delx >0 && dely >0)
                        DrawMultiSelect(centerx,viewport[3]-centery,delx,dely);//abs(m_mousecord.x-m_mousecord.x1),abs(m_mousecord.y-m_mousecord.y1));

                m_bmultiselect=false;

        }

        if(m_mousecord.x == m_mousecord.x1 && m_mousecord.y==m_mousecord.y1 && !m_bmultiselect)
        {
                DrawSelect(point.x,viewport[3]-point.y,5,5);

        }

}
void scene::OnLButtonDownMFC(UINT nFlags, CPoint point)
{
        static int px=point.x,py=point.y;

        SetTrackBall(false);
        GLint viewport[4];

        glGetIntegerv( GL_VIEWPORT		   ,  viewport);

        m_bmove=false;

        if(m_bscale && m_modedoc==SCENE::normal)//applicare la scala all'oggetto
        {
                ApplyScale();
        }
        if(m_bscale && m_modedoc==SCENE::edit)//applicare la scala all'oggetto
        {
                ApplyScaleEdit();
        }

        m_bscale=false;
        m_scalexyz=0;

        if(m_brotate && m_modedoc==SCENE::normal)//applicare la rotazine all'oggetto
        {
                ApplyRotate();
        }

        m_brotate=false;



        m_movevertex[0]=false;
        m_movevertex[1]=false;
        m_movevertex[2]=false;
        m_mousecord.x=point.x;
        m_mousecord.y=point.y;

        if(_input._shift)
        {
                m_bmultiselect=true;


        }
        // DrawSelect(point.x,viewport[3]-point.y,5,5); lasciare??

        px=point.x;
        py=point.y;

}
void scene::OnKeyUpMFC(UINT nChar, UINT nRepCnt, UINT nFlags)
{
        switch(nChar)
        {
                case 17:
                        m_bctrl=false;
                break;
                case VK_SHIFT:
                                _input._shift=false;
                                break;

        }

}
void scene::OnKeyDownMFC(UINT nChar, UINT nRepCnt, UINT nFlags)
{
        /*
        if(btel)
        {
                switch(nChar)
                {
                case 32://switch m_telecamera space
                        if(ntel+1<pdoc->m_telecamera.size())
                                ntel++;
                        else
                                ntel=0;
                        break;

                case 109://-
                        pdoc->m_telecamera[ntel].vpos.SetZ(pdoc->m_telecamera[ntel].vpos.GetZ()+5.0F);
                        break;
                case 107://+
                        pdoc->m_telecamera[ntel].vpos.SetZ(pdoc->m_telecamera[ntel].vpos.GetZ()-5.0F);
                        break;
                case 39://sposta la m_telecamera a destra
                        pdoc->m_telecamera[ntel].vpos.SetX(pdoc->m_telecamera[ntel].vpos.GetX()+5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetX(pdoc->m_telecamera[ntel].vposwhere.GetX()+5.0F);

                        break;

                case 37://sposta la m_telecamera a sinistra
                        pdoc->m_telecamera[ntel].vpos.SetX(pdoc->m_telecamera[ntel].vpos.GetX()-5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetX(pdoc->m_telecamera[ntel].vposwhere.GetX()-5.0F);
                        break;
                case 38://sposta la m_telecamera in alto
                        pdoc->m_telecamera[ntel].vpos.SetY(pdoc->m_telecamera[ntel].vpos.GetY()+5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetY(pdoc->m_telecamera[ntel].vposwhere.GetY()+5.0F);
                        break;
                case 40://sposta la m_telecamera in basso
                        pdoc->m_telecamera[ntel].vpos.SetY(pdoc->m_telecamera[ntel].vpos.GetY()-5.0F);
                        pdoc->m_telecamera[ntel].vposwhere.SetY(pdoc->m_telecamera[ntel].vposwhere.GetY()-5.0F);
                        break;
                }

        }

        static bool sall=true;
        switch(nChar)
        {
                case 17://ctrl
                        m_bctrl=true;
                break;
                case 77://m
                        if(m_modedoc==SCENE::normal)
                        {
                                m_modedoc=SCENE::edit;
                                break;
                        }
                        if(m_modedoc==SCENE::edit)
                        {
                                m_modedoc=SCENE::normal;
                                break;
                        }

                break;
                case 78://n
                        m_modedoc=SCENE::normal;
                        break;
                case 13:
                        if(m_binsert)
                                m_insert->Select();
                break;
                case 37:

                break;
                case 39:
                        if(m_binsert)
                                m_insert->next();
                break;
                case 73://i
                        if(m_modedoc==SCENE::normal)
                                FastAddiction();

                        if(m_modedoc==SCENE::edit)
                                InvertObjectSelect();

                break;
                case 46:
                        if(m_modedoc==SCENE::normal)
                                DeleteObjectsSelected();
                        if(m_modedoc==SCENE::edit)
                        {
                                switch(m_modeedit)
                                {
                                case SCENE::vertex:
                                        DeleteObjectsVertexSelected();
                                        break;
                                case SCENE::line:
//					DeleteObjectsVertexSelected();
                                        DeleteObjectLinesSelected();
                                        break;
                                case SCENE::polygon:
//					DeleteObjectsVertexSelected();
                                        DeleteObjectsPolygonSelected();
                                        break;
                                }
                        }
                break;
                case 65://a

                        if (m_bscale)
                                m_scalexyz=4;
                        sall=!sall;
                        if(m_object.size() <=0)
                                return;
                        if(m_modedoc==SCENE::normal)
                                if(sall)
                                        SelectAllObjects();
                                else
                                        UnselectAllObjects();
                        if(m_modedoc==SCENE::edit)
                                switch(m_modeedit)
                                {
                                case SCENE::vertex:
                                        if(sall)
                                                SelectAllObjectsVertex();
                                        else
                                                UnselectAllObjectsVertex();
                                break;
                                case SCENE::line:
                                        if(sall)
                                                SelectAllObjectsLines();
                                        else
                                                UnselectAllObjectsLines();
                                        break;
                                }
                break;
                case 69://e
                        m_modedoc=SCENE::edit;
                        break;
                case 79://o propriety object
                //	OnEditObjectproperty();
                break;

                case 27://esc per annullare spostamenti rotazione e scalatura
                        //annulla spostamento
                        /*if(m_moveobj[0]	||	m_moveobj[1]	||	m_moveobj[2])
                        {
                                m_moveobj[0]=false;
                                m_moveobj[1]=false;
                                m_moveobj[2]=false;

                                int ns=pdoc->m_object.size();
                                int x;

                                for(x=0; x<ns; x++)
                                        if(pdoc->m_object[x].m_bselected)
                                                pdoc->m_object[x].world_pos=pdoc->m_object[x].old_world_pos;





                        }
                        if(m_bRotate)
                        {
                                int ns=pdoc->m_object.size();
                                int x;

                                for(x=0; x<ns; x++)
                                        if(pdoc->m_object[x].m_bselected)
                                                pdoc->m_object[x].resetAng();

                                m_bRotate=false;
                        }

                break;
                case 68://d duplicate
                        if(_input._shift)
                                DuplicateObjectsSelected();

                break;

                case 84://m_telecamera
                        /*if(pdoc->m_telecamera.size()==0)
                                btel=false;
                        else
                        {
                                btel=!btel;
                                ntel=0;
                        }

                break;
                case 82:
                        m_brotate=true;

                //	m_bRotate=!m_bRotate;
                //	m_rotatexyz=0;
                break;
                case 80://p
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::polygon);
                        break;
                case 76://l
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::line);
                        break;
                case 86://v
                        if(m_modedoc==SCENE::edit)
                                SetEditMode(SCENE::vertex);
                        break;
                case 83://s
                        m_bscale=!m_bscale;
                        m_scalexyz=4;
                //	m_bModScale=!m_bModScale;
                //	m_scalexyz=0;
                        break;
                case 88://scale x
                        if (m_bscale)
                                m_scalexyz=1;
                        if(m_brotate)//inserire salvataggio
                                m_rotatexyz=1;




                        break;
                case 89://scale y
                        if (m_bscale)
                                m_scalexyz=2;
                        if(m_brotate)
                                m_rotatexyz=2;
                        break;
                case 90://scale z
                        if (m_bscale)
                                m_scalexyz=3;
                        if(m_brotate)
                                m_rotatexyz=3;
                        break;
                case VK_SHIFT:
                                _input._shift=true;
                                break;

        }
}
void scene::OnMouseWheelMFC(UINT nFlags, short zDelta, CPoint pt)
{
        float r=m_maincamera.GetRadius();
        float fval,fvalminus;

        fval=30.0F;
        fvalminus=5.0F;

        if(m_binsert)
                return;
        if(!_input._shift)
        {
                if ( zDelta > 0 )
                {
                        //r += fvalminus;
                        r += fval;
                        m_fortho+=10.0F;
                }
                else
                {
                        if ( r - fval > 0.0F )
                        {
                                //r -= fvalminus;

                                r -= fval;

                        }
                        m_fortho-=10.0F;
                }
        }
        else
        {
                if ( zDelta > 0 )
                {
                        r += fvalminus;
                        //r += fval;
                        m_fortho+=10.0F;
                }
                else
                {
                        if ( r - fvalminus > 0.0F )
                        {
                                r -= fvalminus;

                                //r -= fval;

                        }
                        m_fortho-=10.0F;
                }
        }
        if(SCENE::s3d)
                SetRadius(r);




}
void scene::OnMButtonUpMFC(UINT nFlags, CPoint point)
{
        if(m_scene==SCENE::s3d)
        {
                SetTrackBall(false);

        }
        if(m_scene==SCENE::stop)
        {
                m_btop=false;
        }

}
void scene::OnMButtonDownMFC(UINT nFlags, CPoint point)
{
        if(m_scene==SCENE::s3d)
        {
                SetTrackBall(true);
                SetTrackBall(point.y,point.x);
        }
        if(m_scene==SCENE::stop)
        {
                m_btop=true;
        }

}
void scene::OnMouseMoveMFC(UINT nFlags, CPoint point)
{
        static int px=point.x,py=point.y;

        if (m_btrackball && !m_binsert)
        {
                CSize sz;
                CRect r;
                //this->GetClientRect(&r);

                sz.cx=r.Width();
                sz.cy=r.Height();

                TrackBall(sz,point.y,point.x);










        }
        m_vmove.SetVertex(0.0F,0.0F,0.0F);
        m_fscale[0]=0.0F;
        m_fscale[1]=0.0F;
        m_fscale[2]=0.0F;


        if(m_bmove)
        {
                if(m_moveobj[0])
                        m_vmove.AddX(point.x-px);
                if(m_moveobj[1])
                        m_vmove.AddY(point.y-py);
                if(m_moveobj[2])
                        m_vmove.AddZ(point.x-px);

        }
        if(m_bscale)
        {
                if(px>point.x)
                {
                        if(m_scalexyz==1)
                                m_fscale[0]=0.02F;
                        if(m_scalexyz==2)
                                m_fscale[1]=0.02F;
                        if(m_scalexyz==3)
                                m_fscale[2]=0.02F;
                        if(m_scalexyz==4)
                        {
                                m_fscale[0]=0.02F;
                                m_fscale[1]=0.02F;
                                m_fscale[2]=0.02F;
                        }

                }
                if(px < point.x)
                {
                        if(m_scalexyz==1)
                                m_fscale[0]=-0.02F;
                        if(m_scalexyz==2)
                                m_fscale[1]=-0.02F;
                        if(m_scalexyz==3)
                                m_fscale[2]=-0.02F;
                        if(m_scalexyz==4)
                        {
                                m_fscale[0]=-0.02F;
                                m_fscale[1]=-0.02F;
                                m_fscale[2]=-0.02F;
                        }
                }
                if(m_modedoc==SCENE::normal)
                        Scale(m_fscale);
                if(m_modedoc==SCENE::edit)
                        ScaleVertex(m_fscale);
                if(m_modedoc==SCENE::animation)
                        ScaleAnimation(m_ianiselect,m_fscale);

        }
        if(m_brotate)
        {
                float valf=0.0F;
                m_frotate[0]=0.0F;
                m_frotate[1]=0.0F;
                m_frotate[2]=0.0F;
                if(px>point.x)
                {
                        valf=-1.0F;
                }
                if(px<point.x)
                {
                        valf=1.0F;
                }

                switch(m_rotatexyz)
                {
                case 1:
                        m_frotate[0]=valf;
                        break;
                case 2:
                        m_frotate[1]=valf;
                        break;
                case 3:
                        m_frotate[2]=valf;
                        break;
                }
                if(m_modedoc==SCENE::normal)
                        Rotate(m_frotate);
                if(m_modedoc==SCENE::animation)
                        RotateAnimation(m_frotate,m_ianiselect);
        }

        if(m_btop)
        {
                if(px>point.x)
                {
                        m_ftop[0]-=.5F;
                }
                if(px<point.x)
                {
                        m_ftop[0]+=.5F;
                }
                if(py>point.y)
                {
                        m_ftop[1]+=.5F;
                }
                if(py<point.y)
                {
                        m_ftop[1]-=.5F;
                }




        }
        if(m_movevertex[0] || m_movevertex[1] || m_movevertex[2] )
        {
                vertex vapp(0.0F,0.0F,0.0F);
                float fval=0.0F ;
                if(px>point.x)
                        fval=0.5F;
                if(px<point.x)
                        fval=-0.5F;

                if(m_movevertex[0])
                        vapp.AddX(fval);
                if(m_movevertex[1])
                        vapp.AddY(fval);
                if(m_movevertex[2])
                        vapp.AddZ(fval);

                MoveObjectsVertex(vapp);

        }

        SetTrackBall(point.y,point.x);

        px=point.x;
        py=point.y;

}

void scene::OnSizeMFC(UINT nType, int cx, int cy)
{
        SetViewportSize(cx,cy);
}


*/

bool scene::IsPresentAnimationFrame(int aindex, int index)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->IsPresentAnimationFrame(aindex,index));


}
bool scene::IsSelectedAnimationObject(int aindex,int oindex)
{
    return(getdocument()->getmainscenedoc()->getmanageranimation()->IsSelectedAnimationObject(aindex,oindex));

}

void scene::SetObjectMaterial(pl3d_material_struct mat)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            //m_maindocument->getmainscenedoc()->addmaterialandset(mat);

        break;
    }
}

void scene::SetInMoveAnimationObject(int aindex,int oindex,bool bval)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->SetInMoveAnimationObject(aindex,oindex,bval);

}

void scene::SetWPAppAnimationObject(int aindex,int index,l3d_vertex_fast v)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->SetWPAppAnimationObject(aindex,index,v);

}
void scene::SetWPAnimationObject(int aindex,int index,l3d_vertex_fast v)
{
    getdocument()->getmainscenedoc()->getmanageranimation()->SetWPAnimationObject(aindex,index,v);

}
void scene::FastAddiction()
{
        m_binsert=!m_binsert;
}

void scene::Scalex(void)
{
    _input.scale(true,0);







}


void scene::Scaley(void)
{
    _input.scale(true,1);

}


void scene::Scalez(void)
{
    _input.scale(true,2);

}


void scene::ScaleAll(void)
{
       _input.scale(true,3);
}


void scene::Rotatex(void)
{

    _input._rotate=true;//inserire salvataggio
    _input._rotatexyz=1;

}


void scene::Rotatey(void)
{
    _input._rotate=true;//inserire salvataggio
    _input._rotatexyz=2;
}


void scene::Rotatez(void)
{
    _input._rotate=true;//inserire salvataggio
    _input._rotatexyz=3;
}


void scene::RotateAll(void)
{
    _input._rotate=true;//inserire salvataggio
    _input._rotatexyz=4;
}


void scene::EnableDisableLigth(bool enable)
{

}


void scene::OnLigthOptions(void)
{
        //if(this->m_aligth.size()==0)
         //       return;

        /*if(pdlgLight==NULL)
        {
                pdlgLight= new ligthOption();
                pdlgLight->Create(IDD_DIALOG_LIGHT);

                pdlgLight->SetLight(&m_aligth);



        }



        pdlgLight->ShowWindow(SW_SHOW);*/

}
void scene::ScaleEditObject(float scale[3])
{
        if(GetSizeObject() < 0 )
                return;
        int oselected=-1;
        int cobject=0;
        l3d_vertex_fast vscale; vscale.x=scale[0];vscale.y=scale[1];vscale.z=scale[2];

        while(oselected==-1 && cobject < GetSizeObject())
        {
                //if(GetpObject(cobject)->m_bselected)
                //        oselected=cobject;

                cobject++;
        }

        if(oselected==-1)
                return;
        else
                ScaleEditVertexAll(oselected,vscale);




}
void scene::ScaleEditVertexAll(int oindex,l3d_vertex_fast val)
{
        //scala i vertici selezionati in edit mode in x

        Q_ASSERT(oindex >=0 && oindex < GetSizeObject());

        float sc[3];

        sc[0]=val.x;
        sc[1]=val.y;
        sc[2]=val.z;


        //if(!GetpObject(oindex)->m_bselected)
        //        return;

        /*for(int vx=0 ; vx < GetpObject(oindex)->local_vertex.size() ; vx++)
                if(GetpObject(oindex)->local_vertex[vx].IsSelected())
                        GetpObject(oindex)->ScaleVertex(vx,sc);
*/
        //ScaleEditObjectVertexX(oindex,vindex,val.GetX());
        //ScaleEditObjectVertexY(oindex,vindex,val.GetY());
        //ScaleEditObjectVertexZ(oindex,vindex,val.GetZ());

}

void scene::ScaleEditVertex(int oindex,int vindex,l3d_vertex_fast val)
{
        //scala i vertici selezionati in edit mode in x

        /*Q_ASSERT(oindex >=0 && oindex < GetSizeObject());

        Q_ASSERT(vindex >=0 && vindex < GetpObject(oindex)->local_vertex.size());


        if(!m_object[oindex].m_bselected)
                return;

        GetpObject(oindex)->ScaleVertex(vindex);

        //ScaleEditObjectVertexX(oindex,vindex,val.GetX());
        //ScaleEditObjectVertexY(oindex,vindex,val.GetY());
        //ScaleEditObjectVertexZ(oindex,vindex,val.GetZ());
*/
}

void scene::ScaleEditObjectVertexX(int oindex,int vindex,float s)
{
        /*Q_ASSERT(oindex >=0 && oindex < GetSizeObject());

        Q_ASSERT(vindex >=0 && vindex < GetpObject(oindex)->local_vertex.size());


        if(!m_object[oindex].m_bselected)
                return;


        GetpObject(oindex)->ScaleVertex(vindex);
*/


}
void scene::ScaleEditObjectVertexY(int oindex,int vindex,float s)
{
        /*Q_ASSERT(oindex >=0 && oindex < GetSizeObject());

        Q_ASSERT(vindex >=0 && vindex < GetpObject(oindex)->local_vertex.size());


        if(!m_object[oindex].m_bselected)
                return;
*/
}
void scene::ScaleEditObjectVertexZ(int oindex,int vindex,float s)
{
  /*      Q_ASSERT(oindex >=0 && oindex < GetSizeObject());

        Q_ASSERT(vindex >=0 && vindex < GetpObject(oindex)->local_vertex.size());


        if(!m_object[oindex].m_bselected)
                return;
*/
}

//salva un ggetto con il nome
bool scene::SaveObject(int nobject,string name)
{

        string namesave;

        namesave=this->GetPath();

        namesave.append("objects\\");

        namesave.append(name);

        if(nobject==-1) //preleva l'oggetto selezionato
                nobject=this->GetiObjectSelected();



      /*  CFile theFile;

        theFile.Open(namesave, CFile::modeCreate | CFile::modeWrite);

        CArchive archive(&theFile, CArchive::store);


        Q_ASSERT(nobject >=0 && nobject < this->sizeObject());

        GetpObject(nobject)->Serialize(archive);

        archive.Close();

        theFile.Close();
*/

        return true;
}


string scene::GetPath(void)
{

        string fullPath,apppath,filename;

        //corona::File* cf;
        //salvare str in un file ".pov"
        /*apppath=AfxGetApp()->m_pszExeName;


        apppath.Append(_T(".exe"));
        HMODULE hmod = GetModuleHandle(apppath);




        char df='\\';
        DWORD pathLen = ::GetModuleFileName( hmod, fullPath.GetBufferSetLength(MAX_PATH+1), MAX_PATH); // hmod of zero gets the main EXE

        fullPath.ReleaseBuffer( pathLen );
        fullPath.Delete(fullPath.GetLength()-apppath.GetLength(),apppath.GetLength());

        return fullPath;
/*	fullPath.Append(_T("\\screenshots"));

        filename=this->pdoc->GetPathName();

        if(filename.GetLength()==0)
        {
                ::MessageBox(this->m_hWnd,_T("Save before the project..."),_T("Look3D"),NULL);
                return;
        }

        filename=filename.Right(filename.GetLength()-filename.ReverseFind(df));
        filename=filename.Left(filename.Find('.'));
        fullPath.Append(filename);
        */
}


void scene::SaveObjectSelected(int nobject)
{

}

//restituisce il primo oggetto selezionato nella scena in base all'indice dell'array degli ogggetti

int scene::GetiObjectSelected(void)
{
        int x=0;

        bool fl=false;

        //while(!fl && x< this->GetSizeObject())
        {
               // fl=GetpObject(x++)->m_bselected;


        }
        x--;
        if(fl)
                return x;

        return -1;
}
int scene::GetiGroupSelectedMainScene(void)
{
    return (getdocument()->getmainscenedoc()->getiGroupSelected());
}

int scene::GetiLightSelectedMainScene(void)
{
    return(getdocument()->getmainscenedoc()->getiLightSelected());

}
int scene::GetiCameraSelectedMainScene(void)
{
    return(getdocument()->getmainscenedoc()->getcameraselected());

}

int scene::GetiObjectSelectedMainScene(void)
{
        int x=0;

        bool fl=false;
        l3d_uint io=GetSizeObjectMainScene();

        while(!fl && x < io )
        {
            pl3d_mesh_struct appm=GetpObjectMainScene(x);
            if(appm)
                fl=appm->selected();
            else
                fl=false;

            x++;

        }
        x--;
        if(fl)

            return x;

        return -1;
}

void scene::AddObjectFromFile(string nfile)
{
        string namesave;

        namesave=this->GetPath();

        namesave.append("objects\\");

        namesave.append(nfile);

        //object3d fileobject;
/*
        CFile theFile;

        theFile.Open(namesave, CFile::modeRead);

        CArchive archive(&theFile, CArchive::load);

        fileobject.Serialize(archive);


        archive.Close();

        theFile.Close();


*/
        //AddObject(fileobject);

}

void scene::AddObjectFromFilePath(string nfile)
{

        //object3d fileobject;
/*
        CFile theFile;

        theFile.Open(nfile, CFile::modeRead);

        CArchive archive(&theFile, CArchive::load);

        fileobject.Serialize(archive);


        archive.Close();

        theFile.Close();
*/


        //AddObject(fileobject);

}
void scene::setTool(SCENE::SelectTool st)
{
    m_selecttool=st;
    _main_view.setTool(st);


}
void scene::addNull()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->addnull();
        break;
    }
}
void scene::AddTorus()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->addTorus();
        break;
    }
}
void scene::Extrude(int value)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->extrude();
            if(value>=0 && value <=2)
                _input.move_vertex(true,value);

            else
                ;//to-do normal
        break;
    }

}
void scene::Extrudevertex(int value)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->extrudevertex();
            if(m_maindocument->getmainscenedoc()->getObjectSelected()==-1)
                return;
            if(value>=0 && value <=2)
                _input.move_vertex(true,value);

            else
                ;//to-do normal
        break;
    }

}
void scene::Extrudeedge(int value)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
             m_maindocument->getmainscenedoc()->extrudeedge();
             if(m_maindocument->getmainscenedoc()->getObjectSelected()==-1)
                 return;
            if(value>=0 && value <=2)
                _input.move_vertex(true,value);
            else
                ;//to-do normal
        break;
    }

}
void scene::Extrudeedgeind(int value)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
             m_maindocument->getmainscenedoc()->extrudeedgeind();
             if(m_maindocument->getmainscenedoc()->getObjectSelected()==-1)
                 return;
            if(value>=0 && value <=2)
                _input.move_vertex(true,value);
            else
                ;//to-do normal
        break;
    }

}
void scene::Import3ds_file(std::string filename)
{

    Lib3DSImporter model(filename);

    int size=model.getmeshsize();
    for(int ix=0; ix < size;ix++)
    {

        //object3d appobject(model.getmesh(ix));



        //AddObjectMainScene(appobject);
    }

}

void scene::ImportModel_md2(std::string filename)
{
    Md2Model model(filename);

    //object3d appobject(&model);
    //appobject.m_angolo[0]-=90.0F;
    //appobject.ApplicaRotazione();

    //this->AddObjectMainScene(appobject);



}
void scene::ImportPlayer_md2(std::string filename)
{
    Md2Player modelplayer(filename);

    Md2Model* model;
    model=(Md2Model *)modelplayer.playerMesh();


    /*object3d appplayer(model);

    appplayer.m_bselected=true;

    appplayer.m_angolo[0]-=90.0F;

    appplayer.ApplicaRotazione();

    AddObjectMainScene(appplayer);

    model=(Md2Model *)modelplayer.weaponMesh();


    object3d appweapon(model);

    appweapon.m_bselected=true;

    appweapon.m_angolo[0]-=90.0F;

    appweapon.ApplicaRotazione();

    AddObjectMainScene(appweapon);

    */
    Group();



}
void scene::addvertexgroup(string name)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
             m_maindocument->getmainscenedoc()->addvertexgroup(name);

        break;
    }
}
void scene::remvertexgroup(int name)
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->remvertexgroup(name);
        break;
    }
}
void scene::vertexgroup_prev()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            int o=m_maindocument->getmainscenedoc()->getObjectSelected();
            if(o>=0)
                m_maindocument->getmainscenedoc()->getObject(o)->_vertex_group.prev_group();
        break;
    }
}
void scene::vertexgroup_next()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
        int o=m_maindocument->getmainscenedoc()->getObjectSelected();
        if(o>=0)
            m_maindocument->getmainscenedoc()->getObject(o)->_vertex_group.next_group();
        break;
    }

}
void scene::vertexgroup_set()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
        int o=m_maindocument->getmainscenedoc()->getObjectSelected();
        if(o>=0)
            m_maindocument->getmainscenedoc()->getObject(o)->set_group();
        break;
    }

}

string scene::vertexgroup_name()
{
    string ret="";
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            int o=m_maindocument->getmainscenedoc()->getObjectSelected();
            if(o>=0)
                ret=m_maindocument->getmainscenedoc()->getObject(o)->_vertex_group.get_sname();
        break;
    }
    return(ret);
}
void scene::subdivide()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->subdivide();

        break;
    }
}
void scene::subdivide_all()
{
    switch(m_docselect)
    {
        case SCENE::dsmainscene:
            m_maindocument->getmainscenedoc()->subdivide_all();

        break;
    }
}
void scene::UnselectAll()
{
    if(m_modedoc==SCENE::edit)
        switch(m_modeedit)
        {
        case SCENE::vertex:


            UnselectAllObjectsVertex();
        break;
        case SCENE::line:


            UnselectAllObjectsLines();
                break;
        case SCENE::polygon:

            UnselectAllObjectsQuads();
            break;
        }

}
l3d_vertex_fast scene::getpoint3d(l3d_uint x,l3d_uint y)
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
    l3d_vertex_fast myv;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    //gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    myv.x=posX;
    myv.y=posY;
    myv.z=posZ;

    return (myv);
}
void scene::setOrtho(l3d_bool _ortho)
{
    _main_view.setOrtho(_ortho);
}
l3d_bool scene::isOrtho(SCENE::SceneType _s)
{
    return(_main_view.isOrtho(_s));
}
