#include <QOpenGLFunctions>
#include "color.h"

color::color()
{
    r=g=b=a=0.0F;
}

color::color(float nr,float ng,float nb,float na)
{

    r=nr;
    b=nb;
    g=ng;
    a=na;

}
color::~color()
{

}

void color::set(float nr,float ng,float nb,float na)
{
    r=nr;
    b=nb;
    g=ng;
    a=na;

}
void color::draw()
{

    glColor4f(r,g,b,a);
}
