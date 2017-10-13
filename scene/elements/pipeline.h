#ifndef PIPELINE_H
#define PIPELINE_H

#include "telecamera.h"
#include "viewport.h"

class pipeline
{
public:
    pipeline();
    pipeline(telecamera t,viewport v);

    //void setdraw(void (scene::*_f)());
    void setviewport(viewport);
    void projection();
    void modelview();
    void draw();

    //void (scene::*_func)(void);

    void run();

    telecamera m_cam;
    viewport m_view;
};

#endif // PIPELINE_H
