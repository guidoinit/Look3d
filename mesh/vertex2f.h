#ifndef VERTEX2F_H
#define VERTEX2F_H

#include <iostream>
#include <vector>
class vertex2f
{
public:
    vertex2f();
    vertex2f(float x,float y);

    vertex2f(const vertex2f& v)
    {
        m_dx=v.m_dx;
        m_dy=v.m_dy;

    }

    vertex2f& operator=(const vertex2f& v)
    {
        m_dx=v.m_dx;
        m_dy=v.m_dy;

        return (*this);
    }
    vertex2f& operator+=(const vertex2f& v)
    {
        m_dx+=v.m_dx;
        m_dy+=v.m_dy;

        return (*this);

    }
    vertex2f& operator-=(const vertex2f& v)
    {
        m_dx-=v.m_dx;
        m_dy-=v.m_dy;

        return (*this);

    }

    void get(float *x, float *y);

    void set(float x, float y);


private:
    float m_dx,m_dy;
};

#endif // VERTEX2F_H
