#define GLEW_STATIC
#include <GL/glew.h>

#include "loadpackage.h"
#include "ui_loadpackage.h"
#include "fastinsert.h"
#include "ui_fastinsert.h"
#include "newobject.h"
fastinsert::fastinsert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fastinsert)
{
    ui->setupUi(this);

    m_insertgl= new insertGL();

    ui->layoutGL->addWidget(m_insertgl);

    m_bwireframe=true;
    m_timer= new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));


}

fastinsert::~fastinsert()
{
    delete m_insertgl;
    delete ui;
}
void fastinsert::starttimer()
{
    m_insertgl->makeCurrent();
    m_timer->start(5);

}
void fastinsert::stoptimer()
{
    m_timer->stop();
}
void fastinsert::update()
{

    m_insertgl->update();

}

insertGL::insertGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

   /* newsphere= new sphereuv();
    newsphere->SetUV(32,32);

    newsphere->create(32,32,10.0F);

    newsphere->SetColor(1.0,0.0,0.0,1.0);

    //if(newsphere->BuildVBO())
    //    qDebug()  << "vbo created";

*/
    //m_insert= new insert();

    //m_insert->Create();


}

insertGL::~insertGL()
{
    //delete m_insert;

}

void insertGL::update()
{
    paintGL();

    this->swapBuffers();

}

void insertGL::initializeGL()
{

   // logo = new QtLogo(this, 64);
   // logo->setColor(qtGreen.dark());
    glClearColor(0.5,0.5,0.5,1.0);

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
    //glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void insertGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);





    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);

    glMatrixMode(GL_MODELVIEW);

    //if(preview)
     //   m_insert->Draw();



}
void insertGL::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    float aspect=(float)(width/height);
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,1.5F,1.0F,10000.0F);
    glMatrixMode(GL_MODELVIEW);
}

void fastinsert::on_pushButton_2_clicked()
{
    //m_insertgl->m_insert->next();
}

void fastinsert::on_pushButton_clicked()
{
     //m_insertgl->m_insert->prev();
}

void fastinsert::on_view_wireframe_clicked()
{
    m_bwireframe=true;
    ui->view_wireframe->setChecked(true);
    ui->view_solid->setChecked(false);
    //m_insertgl->m_insert->iswireframe=true;
}

void fastinsert::on_view_solid_clicked()
{
    m_bwireframe=false;
    ui->view_wireframe->setChecked(false);
    ui->view_solid->setChecked(true);
    //m_insertgl->m_insert->iswireframe=false;
}

/*object3d fastinsert::getobject()
{
    return (m_insertgl->m_insert->GetObjectSelected());
}
*/
void fastinsert::on_loadpackage_clicked()
{
    //carica un package precostruito nella cartella package dell'applicazione
    //implementare dialogo per il caricamento del package
    //deve soltanto passare alla classe insert il file che rappresena il package
    //la classe insert deve caricare gli oggetti del package e visualizzarli nella finestra
    loadpackage lp;

    lp.exec();
    //da fare
}

void fastinsert::on_pbAddObject_clicked()
{
   /* m_timer->stop();
    newobject* no=new newobject(6);
    if(no->exec()== QDialog::Accepted)
       m_insertgl->m_insert->addobject(no->getobject());
    delete no;
    m_timer->start(5);*/
}
