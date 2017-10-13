#include <stdlib.h>
#include "bufferobject.h"



bufferobject::bufferobject()
{
}

bufferobject::bufferobject(void * _bfr)
{
    _buffer=_bfr;

}
void bufferobject::setsize(unsigned int size)
{
    delete _buffer;

    _buffer=malloc(_lenght * size);

}
void bufferobject::setlenght(unsigned int type)
{
    _lenght=type;
}
void bufferobject::setbuffer(void *_b)
{
    delete _buffer;
    _buffer=_b;
}
void * bufferobject::getbuffer()
{
    return(_buffer);
}
