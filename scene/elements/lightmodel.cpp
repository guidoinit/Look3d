#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "lightmodel.h"

lightmodel::lightmodel()
{
    m_ambient[0]=.2F;
    m_ambient[1]=.2F;
    m_ambient[2]=.2F;
    m_ambient[3]=1.0F;

    m_local_viewer=0.0F;

    m_two_side=0.0F;
}
void lightmodel::set()
{
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,m_ambient);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,m_local_viewer);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE,m_two_side);

    /*
GL_LIGHT_MODEL_AMBIENT
– GL_LIGHT_MODEL_LOCAL_VIEWER
– GL_LIGHT_MODEL_TWO_SIDE*/
}
