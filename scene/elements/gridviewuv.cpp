#include <QGLWidget>

#include <vector>
#include "mesh/vertex2f.h"
#include "gridviewuv.h"

using namespace std;

gridviewuv::gridviewuv()
{
    m_vertexgrid.clear();
    m_fdimgrid=10.0F;
    m_fstep=1.0F;
    creategrid();
}

void gridviewuv::creategrid()
{
    float fdim=m_fdimgrid;
    float fstep=m_fstep;
    m_vertexgrid.clear();
    //create the grid

    for(float ix=-fdim; ix < fdim ; ix+=fstep)
    {
        for(float iy=-fdim; iy < fdim ; iy+=fstep)
        {

            vertex2f appv(ix,iy);

            m_vertexgrid.push_back(appv);



        }
    }

}

void gridviewuv::draw()
{    
    vector<vertex2f>::iterator it;




    glBegin(GL_POINTS);

    for(int ix=0; ix < m_vertexgrid.size(); ix++)
    {
        float x,y;

        m_vertexgrid[ix].get(&x,&y);


        glVertex2f(x,y);

    }




    glEnd();



}
