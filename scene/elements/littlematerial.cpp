
#include "littlematerial.h"


littlematerial::littlematerial(QWidget *parent )
 : QOpenGLWidget( parent)
{


    //m_cube= new cube();

    //m_cube->create(5,10.0F);



}

void littlematerial::update()
{
    paintGL();

    //this->swapBuffers();

}

void littlematerial::initializeGL()
{

    glClearColor(0.5,0.5,0.5,1.0);



    static GLfloat lightPosition[4] = { 0.0, 25.0, 30.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);


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

}
void littlematerial::paintGL()
{
    static float rot[3]={0.0,0.0,0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    //glEnable(GL_MULTISAMPLE);
    /*static GLfloat lightPosition[4] = { 0.0, 5.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    float par[4]={0.7F,0.6F,0.7F,1.0F};
    glLightfv(GL_LIGHT0,GL_DIFFUSE,par);
    glLightfv(GL_LIGHT0,GL_AMBIENT,par);
    glLightfv(GL_LIGHT0,GL_SPECULAR,par);
*/







    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    //gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);

    glMatrixMode(GL_MODELVIEW);

    //m_cube->m_angolo[0]=rot[0]++;
    //m_cube->m_angolo[1]=rot[1]++;
    //m_cube->m_angolo[2]=rot[2]++;

    m_material->set();
    //m_cube->DrawColor(true);

}
void littlematerial::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    float aspect=(float)(width/height);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0,0,width,height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45.0f,aspect,1.0F,10000.0F);
    glMatrixMode(GL_MODELVIEW);
}
