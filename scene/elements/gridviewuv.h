#ifndef GRIDVIEWUV_H
#define GRIDVIEWUV_H
#include <iostream>
#include <vector>
#include "./mesh/vertex2f.h"
using namespace std;


class gridviewuv
{
private:

    float m_fdimgrid,m_fstep;
    void creategrid();
public:
    gridviewuv();

    vector<vertex2f> m_vertexgrid;
    void draw();
};

#endif // GRIDVIEWUV_H
