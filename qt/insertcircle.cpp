#include "insertcircle.h"
#include "ui_insertcirlce.h"

insertcircle::insertcircle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertcircle)
{
    ui->setupUi(this);

    m_gl= new circleGL(this);

    m_gl->m_circle->set(32,10.0F);

    m_gl->m_circle->create();

    ui->vLayoutogl->addWidget(m_gl);

    m_timer= new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

    m_timer->start(10);


}

insertcircle::~insertcircle()
{
    delete ui;
}
void insertcircle::getcircle(int * p, float * r)
{
    *p=m_gl->m_p;
    *r=m_gl->m_r;
}

void insertcircle::update()
{
     m_gl->updateGL();
}

void insertcircle::on_checkBoxPreview_clicked()
{
    m_gl->preview=ui->checkBoxPreview->isChecked();
}

void insertcircle::on_spinBoxRadius_valueChanged(int arg1)
{
    m_gl->m_r=(float)arg1;
    m_gl->m_circle->set(m_gl->m_r,m_gl->m_p);
    m_gl->m_circle->create();
}

void insertcircle::on_spinBoxV_valueChanged(int arg1)
{
    m_gl->m_p=arg1;
    m_gl->m_circle->set(m_gl->m_r,m_gl->m_p);
    m_gl->m_circle->create();
}

circleGL::circleGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    m_circle= new circle();

    m_circle->create(32,10.0F);

    m_circle->SetColor(1.0,0.0,0.0,1.0);





}

circleGL::~circleGL()
{
    delete m_circle;
}

void circleGL::update()
{
    paintGL();
}

void circleGL::initializeGL()
{

    glClearColor(0.5,0.5,0.5,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0.0, 0.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void circleGL::paintGL()
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
        m_circle->DrawLines();

    m_circle->m_angolo[0]=rot[0]++;
    m_circle->m_angolo[1]=rot[1]++;
    m_circle->m_angolo[2]=rot[2]++;


}

void circleGL::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    glMatrixMode(GL_MODELVIEW);
}
