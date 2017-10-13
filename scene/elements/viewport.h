#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "telecamera.h"

class viewport
                      {
private:
    float m_width;
    float m_height;
    float m_x,m_y;
public:
    viewport();
    viewport(float x, float y,float w, float h);
    viewport& operator=(const viewport& v)
    {
        m_width=v.m_width;
        m_height=v.m_height;
        m_x=v.m_x;
        m_y=v.m_y;
        m_cam=v.m_cam;

        return (*this);
    }

    void init(float x, float y, float w, float h);

    float getwidth();
    float getheigth();
    void set();
    telecamera m_cam;

};

#endif // VIEWPORT_H
