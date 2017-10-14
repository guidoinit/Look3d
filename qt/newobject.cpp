

#include "mesh/l3d_mesh.h"



#include "newobject.h"
#include "ui_newobject.h"


using namespace l3d::mesh;

newobject::newobject(int page,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newobject)
{
    m_page=page;

    ui->setupUi(this);
    //m_gl=new objectGL(this);

    //m_gl->m_page=page;
    //ui->vLayoutogl->addWidget(m_gl);

    ui->stackedWidget->setCurrentIndex(m_page);


    //m_timer= new QTimer(this);
    //connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    //m_timer->start(10);

}
void newobject::getline(int * p,float *s)
{
    *p=ui->sbLinepoints->value();
    *s=ui->splineside->value();
}
void newobject::getcircle(int * p,float *s)
{
    *p=ui->sbcirclepoints->value();
    *s=ui->sbcircleradius->value();

}
void newobject::getdisck(int * p,float *s)
{
    *p=ui->sbdisckpoints->value();
    *s=ui->sbdisckradius->value();

}
void newobject::getplane(int * p,float *s,int *f)
{
    *p=ui->sbplaneside->value();
    *s=ui->sbplaneradius->value();
    if(ui->cbplanefunction->currentIndex()==0)
        *f=-1;
    else
        *f=ui->cbplanefunction->currentIndex();

}
void newobject::getcube(int * s,float *r)
{
    *s=ui->sbcubeside->value();
    *r=ui->sbcuberadius->value();


}
void newobject::getsphere(int * u,int*v,float *r)
{
    *u=ui->sbsphereu->value();
    *v=ui->sbspherev->value();
    *r=ui->sbspherer->value();


}
void newobject::getcone(float* height,int* segments)
{
    *height=ui->sb_coneheght->value();
    *segments=ui->sb_conebase->value();
}

void newobject::gettube(float *height,int* segments, int * sidesegments)
{
    *height=ui->sb_tube_height->value();
    *segments=ui->sb_tube_segmentsbase->value();
    *sidesegments=ui->sb_tube_segmentsside->value();

}
void newobject::gettuben(float *height,float *radius,int* segments, int * sidesegments)
{
    *height=ui->sb_tube_height->value();
    *segments=ui->sb_tube_segmentsbase->value();
    *sidesegments=ui->sb_tube_segmentsside->value();

}
void newobject::gettorus(float* maxr,float*minr,int*maxs,int*mins)
{
    *maxr=ui->sb_torus_maxr->value();
    *minr=ui->sb_torus_minr->value();
    *maxs=ui->sb_torus_maxs->value();
    *mins=ui->sb_torus_mins->value();

}

void newobject::update()
{
    m_gl->updateGL();
}
newobject::~newobject()
{
    delete ui;
}
objectGL::objectGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //m_oline=new objline();
    //m_circle=new circle();
    //m_disck= new disck();
    //m_plane= new plane();
    //m_cube= new cube();
    //m_sphere=new sphereuv();
    //m_cone=new cone();
   // m_tube= new tubes();
    //m_torus= new torus();
/*    newsphere= new sphereuv();
    newsphere->SetUV(32,32);

    newsphere->create(32,32,10.0F);

    newsphere->SetColor(1.0,0.0,0.0,1.0);


*/


}

objectGL::~objectGL()
{
 //   delete m_oline;
 //   delete m_circle;
 //   delete m_disck;
 //   delete m_plane;
 //   delete m_cube;
 //   delete m_sphere;
 //   delete m_cone;
 //   delete m_tube;
 //   delete m_torus;
}

void objectGL::update()
{
    //paintGL();
}

void objectGL::initializeGL()
{


    //glewInit();
    glClearColor(0.5,0.5,0.5,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0.0, 10.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
void objectGL::paintGL()
{
    static float rot[3]={0.0,0.0,0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);
    //gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    if(preview)
    {
        switch(m_page)
        {
        case 0://line
            //m_oline->DrawLines();
            //m_oline->m_angolo[0]=rot[0];
            //m_oline->m_angolo[1]=rot[1];
            //m_oline->m_angolo[2]=rot[2];
            break;
        case 1://circle
            //m_circle->DrawLines();
            //m_circle->m_angolo[0]=rot[0];
            //m_circle->m_angolo[1]=rot[1];
            //m_circle->m_angolo[2]=rot[2];
            break;
        case 2://disck
            //m_disck->DrawLines();
            //m_disck->m_angolo[0]=rot[0];
            //m_disck->m_angolo[1]=rot[1];
            //m_disck->m_angolo[2]=rot[2];
            break;
        case 3://plane
            //m_plane->DrawLines();
            //m_plane->m_angolo[0]=rot[0];
            //m_plane->m_angolo[1]=rot[1];
            //m_plane->m_angolo[2]=rot[2];
            break;
        case 4://cube
            //m_cube->DrawLines();
            //m_cube->m_angolo[0]=rot[0];
            //m_cube->m_angolo[1]=rot[1];
            //m_cube->m_angolo[2]=rot[2];

            break;
        case 5://sphere
            //m_sphere->DrawLines();
            //m_sphere->m_angolo[0]=rot[0];
            //m_sphere->m_angolo[1]=rot[1];
            //m_sphere->m_angolo[2]=rot[2];
            break;
        case 6://cylinder
            //m_cone->DrawLines();
            //m_cone->m_angolo[0]=rot[0];
            //m_cone->m_angolo[1]=rot[1];
            //m_cone->m_angolo[2]=rot[2];
            break;
        case 7://tubo
            //m_tube->DrawLines();
            //m_tube->m_angolo[0]=rot[0];
            //m_tube->m_angolo[1]=rot[1];
            //m_tube->m_angolo[2]=rot[2];
            break;
        case 8:
            //m_torus->DrawLines();
            //m_torus->m_angolo[0]=rot[0];
            //m_torus->m_angolo[1]=rot[1];
            //m_torus->m_angolo[2]=rot[2];
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        }


    }
    rot[0]++;
    rot[1]++;
    rot[2]++;


}
void objectGL::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);
    glMatrixMode(GL_MODELVIEW);
}



void newobject::on_pbpreview_clicked()
{
    int func;
    switch (m_page)
    {
    case 0://line
        //m_gl->m_oline->create(ui->sbLinepoints->value(),ui->splineside->value());
        //nobj=*m_gl->m_oline;
        break;
    case 1:
        //m_gl->m_circle->create(ui->sbcirclepoints->value(),ui->sbcircleradius->value());
        //nobj=*m_gl->m_circle;
        break;
    case 2:
        //m_gl->m_disck->create(ui->sbdisckradius->value(),ui->sbdisckpoints->value());
        //nobj=*m_gl->m_disck;
        break;
    case 3:
        func=0;
        if(ui->cbplanefunction->currentIndex()==0)
            func=-1;
        else
            func=ui->cbplanefunction->currentIndex();

        //m_gl->m_plane->create_function(ui->sbplaneside->value(),ui->sbplaneradius->value(),func);
        //nobj=*m_gl->m_plane;
        break;
    case 4:
        //m_gl->m_cube->create(ui->sbcubeside->value(),ui->sbcuberadius->value());
        //nobj=*m_gl->m_cube;
        break;
    case 5:
        //m_gl->m_sphere->create(ui->sbsphereu->value(),ui->sbspherev->value(),ui->sbspherer->value());
        //nobj=*m_gl->m_sphere;
        break;
    case 6:
        //m_gl->m_cone->create(ui->sb_conebase->value(),ui->sb_coneheght->value());
        //nobj=*m_gl->m_cone;
        break;
    case 7:
        //m_gl->m_tube->create(ui->sb_tube_height->value(),ui->sb_tube_segmentsbase->value(),ui->sb_tube_segmentsside->value());
        //nobj=*m_gl->m_tube;
        break;
    case 8:
        //m_gl->m_torus->create(ui->sb_torus_maxr->value(),ui->sb_torus_minr->value(),ui->sb_torus_maxs->value(),ui->sb_torus_mins->value());
        //nobj=*m_gl->m_tube;
        break;

    }


}
l3d_mesh_struct newobject::getobject()
{
    return nobj;
}

void newobject::on_insertline_2_clicked()
{
    m_page=0;
    m_gl->m_page=0;
    ui->stackedWidget->setCurrentIndex(m_page);
}

void newobject::on_tbinsertcircle_clicked()
{
    m_page=1;
    m_gl->m_page=1;
    ui->stackedWidget->setCurrentIndex(m_page);

}

void newobject::on_tbinsertdisck_clicked()
{
    m_page=2;
    m_gl->m_page=2;
    ui->stackedWidget->setCurrentIndex(m_page);
}

void newobject::on_tbinsertplane_clicked()
{
    m_page=3;
    m_gl->m_page=3;
    ui->stackedWidget->setCurrentIndex(m_page);
}

void newobject::on_tbinsertcube_clicked()
{
    m_page=4;
    m_gl->m_page=4;
    ui->stackedWidget->setCurrentIndex(m_page);
}
