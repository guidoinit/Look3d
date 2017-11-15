#include "l3d_vetexarrayobject.h"


l3d_vetexarrayobject::l3d_vetexarrayobject()
{

}
l3d_vetexarrayobject::l3d_vetexarrayobject(GLint vaoId, GLint vertex_count)
{
    _vaoId=vaoId;
    _vertex_count=vertex_count;
}
GLint l3d_vetexarrayobject::getVboId()
{
    return (_vaoId);
}
GLint l3d_vetexarrayobject::getVertexCount()
{
    return (_vertex_count);
}

void l3d_vetexarrayobject::load()
{
    _vaoId=createVAO();

    createVboPoints();
    createVboLines();
    createVboTriangles();
    createVboQuad();

    createVboVertex();
    unbindVAO();

}

GLint l3d_vetexarrayobject::createVAO()
{
    _qt_vao.create();
    _qt_vao.bind();
    return(_qt_vao.objectId());
}

void l3d_vetexarrayobject::unbindVAO()
{
    _qt_vao.release();

}

void l3d_vetexarrayobject::createVboVertex()
{
    glGenBuffers(1,_elementvbo->getId());
    glBindBuffer(GL_ARRAY_BUFFER,*_elementvbo->getId());
    glBufferData(GL_ARRAY_BUFFER,sizeof(l3d_float)*_elementvbo->getsize(),_elementvbo->getbuffer(),GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,false,0,0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
void l3d_vetexarrayobject::createVboTriangles()
{
    glGenBuffers(1,_elementface->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_elementface->getId());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int)*_elementface->getsize(),_elementface->getbuffer(),GL_STATIC_DRAW);
}
void l3d_vetexarrayobject::createVboQuad()
{
    glGenBuffers(1,_elementquad->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_elementquad->getId());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int)*_elementquad->getsize(),_elementquad->getbuffer(),GL_STATIC_DRAW);

}

void l3d_vetexarrayobject::createVboLines()
{
    glGenBuffers(1,_elementedge->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_elementedge->getId());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int)*_elementedge->getsize(),_elementedge->getbuffer(),GL_STATIC_DRAW);
}
void l3d_vetexarrayobject::createVboPoints()
{

    glGenBuffers(1,_elementvert->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_elementvert->getId());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int)*_elementvert->getsize(),_elementvert->getbuffer(),GL_STATIC_DRAW);
}

void l3d_vetexarrayobject::clean()
{
    _qt_vao.destroy();
    glDeleteBuffers(1,_elementvbo->getId());
}
void l3d_vetexarrayobject::render()
{
    _qt_vao.bind();
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES,0,_elementvbo->getsize());
    glDisableVertexAttribArray(0);
    _qt_vao.release();
}

