#include <iostream>

#include "vertex2f.h"

vertex2f::vertex2f()
{
    m_dx=m_dy=0.0F;
}
vertex2f::vertex2f(float x, float y)
{
    m_dx=x;
    m_dy=y;
}

void vertex2f::get(float *x, float *y)
{
    *x=m_dx;
    *y=m_dy;
}

void vertex2f::set(float x, float y)
{
    m_dx=x;
    m_dy=y;
}
