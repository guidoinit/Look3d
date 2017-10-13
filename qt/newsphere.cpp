#define GLEW_STATIC
#include <GL/glew.h>

#include "qt/opengl.h"


#include "mesh/object3dinclude.h"
#include "mesh/mesh3d/sphereuv.h"

#include "newsphere.h"
#include "qt/ui_newsphere.h"

newSphere::newSphere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newSphere)
{


    u=v=32;
    radius=10.0F;
    preview=false;
    ui->setupUi(this);
    m_ogl= new SphereGL(this);
    m_ogl->preview=preview;
    ui->vLayoutogl->addWidget(m_ogl);
    //ui->widgetogl->setLayout(olayout);

    m_timer= new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(10);

}

newSphere::~newSphere()
{
    delete m_ogl;
    delete ui;
}
void newSphere::update()
{
    m_ogl->updateGL();
}

void newSphere::on_spinBoxU_valueChanged(int arg1)
{
    //to-do: prelevare il valore cambiato dall'utente
    u=arg1;

    m_ogl->newsphere->SetUV(u,v);
    if(preview)
        m_ogl->newsphere->create();

}

void newSphere::on_spinBoxV_valueChanged(int arg1)
{
     //to-do: prelevare il valore cambiato dall'utente
    v=arg1;

    m_ogl->newsphere->SetUV(u,v);
    if(preview)
        m_ogl->newsphere->create();
}

void newSphere::on_spinBoxRadius_valueChanged(int arg1)
{
     //to-do: prelevare il valore cambiato dall'utente
    radius=(float)arg1;
    m_ogl->newsphere->setRadius((float)arg1);
    if(preview)
        m_ogl->newsphere->create();
}

void newSphere::on_buttonBox_accepted()
{
    m_timer->stop();
    retobject=*m_ogl->newsphere;
}

object3d *newSphere::getsphereuv()
{
    object3d *reto=&retobject;
    if(preview)

        return reto;
    else
        return 0;
}

void newSphere::on_buttonBox_rejected()
{
    m_timer->stop();
}

void newSphere::on_checkBoxPreview_toggled(bool checked)
{
    preview=checked;
    m_ogl->preview=preview;

    m_ogl->newsphere->create(u,v,radius);

   // if(!preview)
   //     delete m_ogl->newsphere;
}

void newSphere::getuvr(int *u,int *v,float *r)
{
    *u=this->u;
    *v=this->v;
    *r=radius;
}



SphereGL::SphereGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    newsphere= new sphereuv();
    newsphere->SetUV(32,32);

    newsphere->create(32,32,10.0F);

    newsphere->SetColor(1.0,0.0,0.0,1.0);

    //if(newsphere->BuildVBO())
    //    qDebug()  << "vbo created";




}

SphereGL::~SphereGL()
{

}

void SphereGL::update()
{
    paintGL();
}

void SphereGL::initializeGL()
{

   // logo = new QtLogo(this, 64);
   // logo->setColor(qtGreen.dark());
    glClearColor(0.5,0.5,0.5,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
//! [6]

//! [7]
void SphereGL::paintGL()
{
    static float rot[3]={0.0,0.0,0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glTranslatef(0.0, 0.0, -10.0);
    //glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);
    //newsphere->DrawColor(true);
    if(preview)
        //newsphere->DrawVBO();
        newsphere->DrawLines();

    newsphere->m_angolo[0]=rot[0]++;
    newsphere->m_angolo[1]=rot[1]++;
    newsphere->m_angolo[2]=rot[2]++;

   // logo->draw();
}
//! [7]

//! [8]
void SphereGL::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,1.5F,1.0F,10000.0F);
/*#ifdef QT_OPENGL_ES_1
    glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
*/
    glMatrixMode(GL_MODELVIEW);
}

