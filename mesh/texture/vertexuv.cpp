#include "vertexuv.h"

vertexuv::vertexuv()
{
}
vertexuv::vertexuv(float nu, float nv)
{
    u=nu;
    v=nv;
}
vertexuv::vertexuv( const vertexuv &vert )
{
    u=vert.u;
    v=vert.v;
}

vertexuv& vertexuv::operator=( const vertexuv &vert )
{
    u=vert.u;
    v=vert.v;

    return *this;
}

vertexuv::~vertexuv()
{

}
void vertexuv::set(float nu, float nv)
{
    u=nu;
    v=nv;
}

float vertexuv::getu()
{
    return u;
}

float vertexuv::getv()
{
    return v;
}
void vertexuv::getu(float *nu)
{
   *nu= u;
}

void vertexuv::getv(float * nv)
{
    *nv= v;
}
void vertexuv::setname(int name)
{
    m_iname=name;
}

int vertexuv::getname()
{
    return m_iname;
}
