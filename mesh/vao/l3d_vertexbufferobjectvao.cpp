#include "l3d_vertexbufferobjectvao.h"
#include "l3d_include.h"

using namespace l3d;
l3d_vertexbufferobjectVAO::l3d_vertexbufferobjectVAO()
{

}
void l3d_vertexbufferobjectVAO::setsize(l3d_uint _size)
{
    if(buffer!=NULL)
        delete buffer;

    lenght_buffer=_size;

    buffer=malloc(lenght_element * lenght_buffer);
}
void l3d_vertexbufferobjectVAO::setlenght(l3d_uint type)
{
    lenght_element=type;
}
void l3d_vertexbufferobjectVAO::setbuffer(l3d_void _buffer)
{
    delete buffer;
    buffer=_buffer;
}
void l3d_vertexbufferobjectVAO::set_target(l3d_buffertype _target)
{
    target=_target;
}
void l3d_vertexbufferobjectVAO::set_access(l3d_access _access)
{
    access=_access;
}
l3d_void l3d_vertexbufferobjectVAO::getbuffer()
{
    return buffer;
}
GLuint * l3d_vertexbufferobjectVAO::getId()
{
    return (&_vboId);
}
l3d_uint l3d_vertexbufferobjectVAO::getsize()
{
    return (lenght_buffer);
}
