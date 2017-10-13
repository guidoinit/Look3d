#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H

class bufferobject
{
public:
    bufferobject();
    bufferobject(void *);
    void setsize(unsigned int size);
    void setlenght(unsigned int type);
    void setbuffer(void*);
    void *getbuffer();
private:
    void *_buffer;
    unsigned int _lenght;
};

#endif // BUFFEROBJECT_H
