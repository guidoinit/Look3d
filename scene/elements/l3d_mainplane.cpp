#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"
#include "l3d_mainplane.h"
using namespace l3d::mesh;

l3d_mainplane::l3d_mainplane()
{
    l3d_float *par;
    float app[3]={
      10.0F,10.0F,0.0F
    };
    par=&app[0];
    init(par);
}


void l3d_mainplane::init(l3d_float *par)
{
    pl3d_mesh_struct newmesh= new l3d_mesh_struct;
    newmesh->_display= new l3d_mesh_display_struct;


    newmesh->_display->isnull=false;
    newmesh->_display->invert=false;

    newmesh->_transformation.init();


    newmesh->setname("mainplane",0);

    newmesh->_sub_name="plane object";

    l3d_float m_fraggio=10.0F;
    l3d_uint m_nstrati=2;
    l3d_uint m_function=0;
    if(par!=NULL)
    {
        m_nstrati=(l3d_uint)*par++;
        m_fraggio=(l3d_float)*par++;
        m_function=(l3d_uint)*par;
    }




    double step=(double)(m_fraggio*2.0F/(double)m_nstrati);
    int nvert=m_nstrati+1;
    float fy=0.0F;


    int vprevx=0,vprevy=0;
    int startv=0;
    double fx=-m_fraggio;

    for(int ix=0; ix <nvert; ix++ )
    {

            startv=newmesh->_vertex.size();

            double fz=-m_fraggio;

            for(int iy=0; iy <nvert; iy++)
            {
                    fy=0.0F;
                    switch(m_function)
                    {
                    case 1:
                            fy=sin(fx);
                            break;
                    case 2:
                            fy=sin(fz);
                            break;
                    case 3:
                            fy=sin(fx)*sin(fz);
                            break;
                    case 4:
                            fy=sin(fx * fz);
                            break;
                    case 5:
                            fy=sin(fx)+cos(fz);
                            break;
                    }

                    newmesh->addvertex(fx,fy,fz);

                    fz+=step;
                    vprevy++;
            }
            fx+=step;

            if(vprevx>0){

                    for(int ix=0; ix < nvert-1; ix++)
                    {
                        l3d_uint a,b,c,d;

                        a=startv-nvert+ix;
                        b=startv-nvert+ix+1;
                        c=startv+ix;
                        d=startv+ix+1;
                        //a,b,c,d
                        newmesh->addquad(a,b,c,d,abcdCW);

                    }

            }

            vprevy=0;
            vprevx++;

    }

    _plane=*newmesh;
}
