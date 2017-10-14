#include <QGLWidget>
#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    gl_about= new AboutGL(this);

    gl_aboutgame= new AboutGameGL(this);


    ui->AboutLayout->addWidget(gl_about);
    ui->vlAboutGame->addWidget(gl_aboutgame);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}


AboutGL::AboutGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

}

AboutGL::~AboutGL()
{

}


void AboutGL::initializeGL()
{

   // logo = new QtLogo(this, 64);
   // logo->setColor(qtGreen.dark());
    //glClearColor(0.0,0.5,0.0,0.0);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
//! [6]

//! [7]
void AboutGL::paintGL()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    //glTranslatef(0.0, 0.0, -10.0);
    //glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
   // logo->draw();
}
//! [7]

//! [8]
void AboutGL::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);

    //glMatrixMode(GL_PROJECTION);
   // glLoadIdentity();
#ifdef QT_OPENGL_ES_1
   // glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
   // glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
   // glMatrixMode(GL_MODELVIEW);
}

AboutGameGL::AboutGameGL(QWidget *parent )
 : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

}

AboutGameGL::~AboutGameGL()
{

}


void AboutGameGL::initializeGL()
{

   // logo = new QtLogo(this, 64);
   // logo->setColor(qtGreen.dark());
    //glClearColor(0.0,0.0,0.0,0.0);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
//! [6]

//! [7]
void AboutGameGL::paintGL()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    //glTranslatef(0.0, 0.0, -10.0);
    //glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
   // logo->draw();
}
//! [7]

//! [8]
void AboutGameGL::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    //glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
    //glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
    //glMatrixMode(GL_MODELVIEW);
}

