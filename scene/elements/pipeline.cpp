#define GLEW_STATIC
#include <GL/glew.h>

#include <QGLWidget>
#include "pipeline.h"


pipeline::pipeline()
{
}
pipeline::pipeline(telecamera t , viewport v)
{
    m_cam=t;

    m_view=v;

}
void pipeline::setviewport(viewport v)
{
    m_view=v;
}

void pipeline::projection()
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();


    glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);
}
void pipeline::modelview()
{
    glPushMatrix();
        //m_mainviewport[0].set();
        m_view.set();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        m_cam.SetPos();

        //m_mainviewport[0].m_cam.SetPos();

        draw();

    glPopMatrix();
}
/*
void pipeline::setdraw(void (*_f)())
{
    _func=_f;

}
*/
void pipeline::draw()
{
    //(*_func)();
}
void pipeline::run()
{
    projection();
    modelview();


}
