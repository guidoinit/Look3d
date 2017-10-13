#ifndef VECTOR_H
#define VECTOR_H
#include "mesh/l3d_vertex.h"
#include "scene/animation/schinningvector.h"
using namespace l3d::vertex3f;

class l3dvector
{
public:
    l3dvector();
    l3dvector(l3d_vertex_fast,l3d_vertex_fast);
    void draw();

private:
    l3d_vertex_fast m_start;
    l3d_vertex_fast m_end;

    schinningvector m_schinning;

};

#endif // VECTOR_H
