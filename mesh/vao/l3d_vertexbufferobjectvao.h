#ifndef L3D_VERTEXBUFFEROBJECTVAO_H
#define L3D_VERTEXBUFFEROBJECTVAO_H

#include <QOpenGLFunctions>
#include "l3d_include.h"

namespace l3d
{


    class l3d_vertexbufferobjectVAO:protected QOpenGLFunctions
    {
    private:
        GLuint _vboId;
        l3d_void buffer;
        l3d_uint lenght_element;
        l3d_uint lenght_buffer;
        l3d_buffertype target;
        l3d_bufferusage usage;
        l3d_access access;
    public:
        l3d_vertexbufferobjectVAO();
        GLuint * getId();
        void setsize(l3d_uint size);
        l3d_uint getsize();
        void setlenght(l3d_uint type);

        void setbuffer(l3d_void);
        void set_target(l3d_buffertype);
        void set_access(l3d_access);

        l3d_void getbuffer();
    };
}
#endif // L3D_VERTEXBUFFEROBJECTVAO_H
