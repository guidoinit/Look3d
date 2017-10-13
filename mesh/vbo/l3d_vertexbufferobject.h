#ifndef L3D_VERTEXBUFFEROBJECT_H
#define L3D_VERTEXBUFFEROBJECT_H

#include "l3d_include.h"

#include "l3d_bufferobject.h"


namespace l3d
{

    typedef struct _buffer_object
    {
        l3d_glfloat location[3];
        l3d_glfloat tex[2];
        l3d_glfloat normal[3];
        l3d_glfloat color[4];
        GLubyte imaterial;
        GLubyte padding[15]; //riempie la struttura di 64bit per incrementare le performance
    }l3d_VBO_element,*pl3d_VBO_element;

    class l3d_vertexbufferobject
    {
    private:



    public:
        l3d_vertexbufferobject();

        l3d_uint _id;
        l3d_uint _idindex;
        l3d_uint _vbosize;
        l3d_uint _linesize;
        pl3d_VBO_element _buffer;
        l3d_uint  *_index;
        l3d_bufferobject * _elementvbo;
        l3d_bufferobject * _elementvert;
        l3d_bufferobject * _elementedge;
        l3d_bufferobject * _elementface;
        l3d_bufferobject * _elementquad;

        void clean();

    };
}

#endif // L3D_VERTEXBUFFEROBJECT_H
