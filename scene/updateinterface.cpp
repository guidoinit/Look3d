#include "updateinterface.h"
#include "qt/insertobject.h"
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
