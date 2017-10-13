#ifndef UPDATEINTERFACE_H
#define UPDATEINTERFACE_H
#include "qt/opengl.h"
#include "insertobject.h"
class updateinterface
{
public:
    updateinterface();
    updateinterface(insertObject *);

    void update();
private:
    insertObject * m_insert;
};

#endif // UPDATEINTERFACE_H
