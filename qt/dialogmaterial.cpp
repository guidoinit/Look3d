#include <QTimer>
#include <QMouseEvent>

#include "dialogmaterial.h"
#include "ui_dialogmaterial.h"
#include "modifier/l3d_modifier_draw.h"

using namespace l3d::modifier;

DialogMaterial::DialogMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMaterial)
{
    ui->setupUi(this);

    m_preview= new previewmaterial();
    float par[3],*fpar;
    par[0]=par[1]=32.0F;par[2]=15.0F;
    fpar=&par[0];

    l3d::mesh::l3d_mesh::create_sphereuv(fpar,&m_preview->m_sphere);


    ui->materiallayout->addWidget(m_preview);

    m_timer= new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));



    initdialog();
}

DialogMaterial::~DialogMaterial()
{
    delete ui;
}
pl3d_material_struct DialogMaterial::getmaterial()
{
    pl3d_material_struct mat=m_material;
    return mat;
}
void DialogMaterial::setmaterial(pl3d_material_struct mat)
{

    pl3d_material_struct _nmat=new l3d_material_struct;

    *_nmat=*mat;
    m_preview->m_sphere._material.add(_nmat);
    m_preview->m_sphere._material.set(1);



    m_preview->m_sphere._transformation._rotate.set(0.0F,45.0F,0.0F);



}

void DialogMaterial::initdialog()
{


}

void DialogMaterial::starttimer()
{
    m_preview->makeCurrent();
    m_timer->start(5);

}
void DialogMaterial::stoptimer()
{
    m_timer->stop();
}
void DialogMaterial::update()
{

    m_preview->update();

}
void previewmaterial::mouseReleaseEvent ( QMouseEvent * event )
{
    if(event->button()==Qt::LeftButton)
    {
        mpress=false;
    }
}

void previewmaterial::mousePressEvent ( QMouseEvent * event )
{
    if(event->button()==Qt::LeftButton)
    {
        pmouse=event->pos();
        mpress=true;
    }

}
void previewmaterial::mouseMoveEvent ( QMouseEvent * e )
{
    if(mpress)
    {
        int deltax=(e->x()-pmouse.x());
        int deltay=(e->y()-pmouse.y());

        if(deltax>0)
            m_sphere._transformation._rotate.x--;
        else if(deltax<0)
            m_sphere._transformation._rotate.y++;

         if(deltay>0)
             m_sphere._transformation._rotate.z--;
         else if(deltay<0)
            m_sphere._transformation._rotate.y++;
         pmouse=e->pos();

         //m_cube->Scale();
    }
}

previewmaterial::previewmaterial(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{


    mpress=false;


}

previewmaterial::~previewmaterial()
{
    //delete(m_sphere);
}

void previewmaterial::update()
{
    paintGL();

    this->swapBuffers();

}

void previewmaterial::initializeGL()
{

    glClearColor(0.5,0.5,0.5,1.0);



    static GLfloat lightPosition[4] = { 0.0F, 100.0F, 0.0F, 1.0F };
    static GLfloat lightvalue[4]={ 0.2F, 0.2F, 0.2F, 1.0F };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightvalue);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightvalue);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightvalue);



    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHT5);
    glDisable(GL_LIGHT6);
    glDisable(GL_LIGHT7);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    //gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);


}
void previewmaterial::paintGL()
{

    l3d_modifier_draw _draw;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static GLfloat lightPosition[4] = { 0.0F, 100.0F, 50.0F, 1.0F };
    static GLfloat lightvalue[4]={ 0.5F, 0.5F, 0.5F, 1.0F };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightvalue);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightvalue);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightvalue);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);
    //gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();

    _draw.draw(&m_sphere,SCENE::color);

    //m_sphere->DrawMaterial(false);

    glPopMatrix();

}
void previewmaterial::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    float aspect=(float)(width/height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   // gluPerspective(45.0f,aspect,1.0F,10000.0F);
    glMatrixMode(GL_MODELVIEW);
}



void DialogMaterial::on_buttonBox_accepted()
{

}
