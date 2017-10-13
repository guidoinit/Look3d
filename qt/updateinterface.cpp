#define GLEW_STATIC
#include <GL/glew.h>

#include "updateinterface.h"
#include "insertobject.h"
updateinterface::updateinterface()
{
}

updateinterface::updateinterface(insertObject * value)
{
    m_insert=value;
}

void updateinterface::update()
{
    m_insert->update();
}
