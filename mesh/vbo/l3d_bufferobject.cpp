#define GLEW_STATIC
#include <GL/glew.h>
#include <QGLWidget>


#include "l3d_include.h"
#include "l3d_bufferobject.h"

using namespace l3d;

l3d_bufferobject::l3d_bufferobject()
{

    buffer=NULL;
    idb=0;

}
l3d_uint l3d_bufferobject::size()
{
    return (lenght_buffer );
}

void l3d_bufferobject::setsize(l3d_uint _size)
{
    if(buffer!=NULL)
        delete buffer;

    lenght_buffer=_size;
    buffer=malloc(lenght_element * lenght_buffer);

}
void l3d_bufferobject::setlenght(l3d_uint type)
{
    lenght_element=type;

}
void l3d_bufferobject::setbuffer(l3d_void _b)
{
    delete buffer;
    buffer=_b;
}

void l3d_bufferobject::bind()
{
    glBindBuffer(target, idb);

}
void l3d_bufferobject::deletebuffer()
{

    glDeleteBuffers(1,&idb);

    //delete buffer;
}

void l3d_bufferobject::draw(l3d_mode_draw mode)
{
    bind();

    glDrawElements(mode, size(), GL_UNSIGNED_INT, 0);

    glBindBuffer(target, 0);

}

void l3d_bufferobject::create()
{
    glGenBuffers(1, &idb);

    glBindBuffer(target, idb);

    glBufferData(target, lenght_element * lenght_buffer,buffer,usage);

    glBindBuffer(target, 0);

    delete buffer;

}
void l3d_bufferobject::create_sub()
{
    glGenBuffers(1, &idb);

    glBindBuffer(target, idb);

    glBufferData(target, lenght_element * lenght_buffer,NULL,usage);

    glBufferSubData(target, 0, lenght_element * lenght_buffer, buffer);

    glBindBuffer(target, 0);

    delete buffer;

}
void l3d_bufferobject::create(l3d_buffertype _target,l3d_bufferusage _usage)
{
    target=_target;
    usage=_usage;

    create();

}
void l3d_bufferobject::create_sub(l3d_buffertype _target,l3d_bufferusage _usage)
{
    target=_target;
    usage=_usage;

    create_sub();

}
l3d_uint l3d_bufferobject::getid()
{
    return (idb);

}

l3d_void l3d_bufferobject::getbuffer()
{
    return buffer;

}

l3d_void l3d_bufferobject::getbufferobject(l3d_access _access)
{

    access=_access;

    glBindBuffer(target, idb);

    l3d_void ptr = (l3d_void*)glMapBuffer(target,access);


    return(ptr);



}
void l3d_bufferobject::set_access(l3d_access _a)
{
    access=_a;
}

void l3d_bufferobject::set_target(l3d_buffertype _t)
{
    target=_t;

}

void l3d_bufferobject::unmapbuffer()
{

    glUnmapBuffer(target);

}
