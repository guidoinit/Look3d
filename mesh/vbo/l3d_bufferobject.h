#ifndef L3D_BUFFEROBJECT_H
#define L3D_BUFFEROBJECT_H
#include <QOpenGLFunctions>

#include "l3d_include.h"

namespace l3d
{




    class l3d_bufferobject
    {
    private:
        l3d_void buffer;
        l3d_uint lenght_element;
        l3d_uint lenght_buffer;
        l3d_uint idb;
        l3d_buffertype target;
        l3d_bufferusage usage;
        l3d_access access;
    public:
        l3d_bufferobject();
        void setsize(l3d_uint size);
        void setlenght(l3d_uint type);
        void setbuffer(l3d_void);
        void set_target(l3d_buffertype);
        void set_access(l3d_access);
        l3d_void getbuffer();
        l3d_void getbufferobject(l3d_access);
        void unmapbuffer();
        void create();
        void create_sub();
        void create(l3d_buffertype,l3d_bufferusage);
        void create_sub(l3d_buffertype,l3d_bufferusage);
        l3d_uint size();
        l3d_uint getid();
        void bind();
        void deletebuffer();
        void draw(l3d_mode_draw dm);

    };

}


#endif // L3D_BUFFEROBJECT_H
