#define GLEW_STATIC

#include <GL/glew.h>
#include <QtOpenGL>
#include "viewport.h"

viewport::viewport()
{
}
viewport::viewport(float x,float y,float w, float h)
{
    m_x=x;
    m_y=y;
    m_width=w;
    m_height=h;
}

void viewport::set()
{
    glViewport(m_x,m_y,m_width,m_height);
}
void viewport::init(float x, float y, float w, float h)
{
    m_x=x;
     m_y=y;
    m_width=w;
    m_height=h;
   // set();
}
float viewport::getwidth()
{
    return m_width;
}
float viewport::getheigth()
{
    return m_height;
}
