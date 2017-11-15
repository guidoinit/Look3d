#ifndef L3D_VETEXARRAYOBJECT_H
#define L3D_VETEXARRAYOBJECT_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include "l3d_include.h"

#include "l3d_vertexbufferobjectvao.h"

using namespace l3d;

class l3d_vetexarrayobject:protected QOpenGLFunctions
{
private:
    GLuint _vboId;
    GLuint _vibId;
    GLint _vaoId;
    GLint _vertex_count;
    QOpenGLVertexArrayObject _qt_vao;
    GLint createVAO();
    void createVboPoints();
    void createVboVertex();
    void createVboTriangles();
    void createVboLines();
    void createVboQuad();

public:
    l3d_vetexarrayobject();
    l3d_vetexarrayobject(GLint vboId,GLint vertex_count);
    GLint getVboId();
    GLint getVertexCount();

    void load();
    void unbindVAO();
    void clean();
    void render();
    l3d_vertexbufferobjectVAO * _elementvbo;
    l3d_vertexbufferobjectVAO * _elementvert;
    l3d_vertexbufferobjectVAO * _elementedge;
    l3d_vertexbufferobjectVAO * _elementface;
    l3d_vertexbufferobjectVAO * _elementquad;
};

#endif // L3D_VETEXARRAYOBJECT_H
