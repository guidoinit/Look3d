#include "qt/opengl.h"
#include <QDebug>
#include <QWheelEvent>
OpenGL::OpenGL(QWidget *parent )
 : QOpenGLWidget(parent)
{


    pscene= new scene();

    //setMouseTracking(true);

    //pscene->m_binsert=true;
    setFocus();
    //setMouseTracking(true);
    start_timer();

}

OpenGL::~OpenGL()
{
    delete pscene;

}
void OpenGL::start_timer()
{
    ntimer=startTimer(5);
}
void OpenGL::stop_timer()
{
    killTimer(ntimer);

}
void OpenGL::timerEvent(QTimerEvent *event)
 {
    static int count=0;
   // qDebug() << "Timer ID:" << event->timerId() << " " << count++;
    pscene->Pipeline();

    //this->swapBuffers();
 }



void OpenGL::WheelEvent(QWheelEvent *event)
{
    qDebug() << "in mousewhell:";
    pscene->OnMouseWheel(0,event->delta(),event->pos().x(),event->pos().y());
}
void OpenGL::keyReleaseEvent(QKeyEvent *event)
{
    pscene->OnKeyUp(event->key(),0,0);

}

void OpenGL::keyPressEvent(QKeyEvent *event)
{
    pscene->OnKeyDown(event->key(),0,0);
}
void OpenGL::mouseMoveEvent ( QMouseEvent * e )
{
    static int count=0;
     pscene->OnMouseMove(0,e->pos().x(),e->pos().y());
    QPoint pglobal=mapToGlobal(QPoint(0,0));

    bool istrue=pscene->isActions();
    if(istrue && (count++%10)==0)
        cursor().setPos((m_width/2)+pglobal.x(),(m_heigth/2)+pglobal.y());


 }
void OpenGL::mouseReleaseEvent ( QMouseEvent * event )
{
    setFocus();
    if(event->button()==Qt::LeftButton)
    {
        pscene->OnLButtonUp(0,event->x(),event->y());
        qDebug() << "mouse press:Left->("<<event->x() << "," << event->y() << ")";
        //to-do
    }
    else if (event->button()==Qt::RightButton)
    {
        qDebug() << "mouse press:Right";
        pscene->OnLButtonUp(1,event->x(),event->y());
        //to-do
    }
    else if (event->button()==Qt::MiddleButton)
    {
        qDebug() << "mouse press:Right";
        pscene->OnLButtonUp(2,event->x(),event->y());
        //to-do
    }
}

void OpenGL::mousePressEvent ( QMouseEvent * event )
{

    setFocus();
    if(event->button()==Qt::LeftButton)
    {
        pscene->OnLButtonDown(0,event->x(),event->y());
        qDebug() << "mouse press:Left->("<<event->x() << "," << event->y() << ")";
        //to-do
    }
    else if (event->button()==Qt::RightButton)
    {
        qDebug() << "mouse press:Right";
        pscene->OnLButtonDown(1,event->x(),event->y());
        //to-do
        //prelevare l'oggetto selezionato


    }
    else if (event->button()==Qt::MiddleButton)
    {
        qDebug() << "mouse press:Right";
        pscene->OnLButtonDown(2,event->x(),event->y());
        //to-do
    }
}

void OpenGL::buttonclicked()
{

}


void OpenGL::initializeGL()
{

    initializeOpenGLFunctions();

    pscene->InitScene();



    /*
    QColor color(1.0,0,0,1.0);
    qglClearColor(color.cyan());

   // logo = new QtLogo(this, 64);
   // logo->setColor(qtGreen.dark());
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);*/
}
//! [6]

//! [7]
void OpenGL::paintGL()
{
    pscene->Pipeline();
    /*
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    //glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
   // logo->draw();*/
}
//! [7]

//! [8]
void OpenGL::resizeGL(int width, int heigth)
{
    m_width=width;
    m_heigth=heigth;

    //glViewport(0,0,width , heigth);
    pscene->SetViewportSize(m_width,m_heigth);
   /* glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    pscene->InitPipeline();

    glMatrixMode(GL_MODELVIEW);*/
}
