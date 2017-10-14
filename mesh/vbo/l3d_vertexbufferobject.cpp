#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>
#include "l3d_bufferobject.h"
#include "l3d_vertexbufferobject.h"
using namespace l3d;

l3d_vertexbufferobject::l3d_vertexbufferobject()
{
    _elementedge=NULL;
    _elementface=NULL;
    _elementquad=NULL;
    _elementvert=NULL;
    _elementvbo=NULL;
}

void l3d_vertexbufferobject::clean()
{
    if(_elementvbo)
        _elementvbo->deletebuffer();
    if(_elementvert)
        _elementvert->deletebuffer();
    if(_elementedge)
        _elementedge->deletebuffer();
    if(_elementface)
        _elementface->deletebuffer();
    if(_elementquad)
        _elementquad->deletebuffer();

    _elementedge=NULL;
    _elementface=NULL;
    _elementquad=NULL;
    _elementvert=NULL;
    _elementvbo=NULL;

}
