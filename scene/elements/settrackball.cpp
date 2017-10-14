#include <QOpenGLFunctions>
#include "mesh/l3d_vertex.h"
#include "settrackball.h"
using namespace l3d::vertex3f;

static GLfloat objectXform[4][4] = {
    {1.0, 0.0, 0.0, 0.0},
    {0.0, 1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0, 0.0},
    {0.0, 0.0, 0.0, 1.0}
};
settrackball::settrackball()
{
    m_gldata.beginx = 0.0f;
    m_gldata.beginy = 0.0f;
    m_gldata.zoom   = 25.0f;

    trackball(m_gldata.quat, 0.0f, 0.0f, 0.0f, 0.0f);

    m_btrack=false;
}
l3d_vertex_fast settrackball::mapping(int sx,int sy,int wx,int wy)
{
    l3d_vertex_fast v;
    float d,vx,vy,vz;

    vx = (2.0*sx - wx) / wx;
    vy = (wy - 2.0*sy) / wy;
    vz = 0.0;
    v.set(vx,vy,vz);

    //d = v.length();
    d = (d < 1.0) ? d : 1.0;  // If d is > 1, then clamp it at one.

    vz = sqrtf( 1.001 - d*d );  // project the line segment up to the surface of the sphere.

    v.z=vz;

    v.normalize();  // We forced d to be less than one, not v, so need to normalize somewhere.


    return v;


}

void settrackball::run(float sx,float sy,float wx, float wy)
{



    lastpoint=mapping (sx,sy,wx,wy);



}

void settrackball::set(float sx,float sy,float wx, float wy)
{
    l3d_vertex_fast curpoint,direction;

    if(m_btrack)
    {
        curpoint=mapping (sx,sy,wx,wy);
        direction=lastpoint;
        direction-=curpoint;
        float velocity;// = direction.length();
        if( velocity > 0.0001 )
        {
        //
        // Rotate about the axis that is perpendicular to the great circle connecting the mouse movements.
        //

        l3d_vertex_fast rotAxis;
        //rotAxis.crossprod( lastpoint, curpoint );
        float rot_angle = velocity *90.0F;
        //
        // We need to apply the rotation as the last transformation.
        //   1. Get the current matrix and save it.
        //   2. Set the matrix to the identity matrix (clear it).
        //   3. Apply the trackball rotation.
        //   4. Pre-multiply it by the saved matrix.
        //
        GLfloat objectXform2[4][4];
        //glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat *) objectXform2 );
        //glLoadIdentity();
        //glRotatef( rot_angle, rotAxis.x, rotAxis.y, rotAxis.z );
        //glMultMatrixf( (GLfloat *) objectXform2 );


        }
    }
     //   GLfloat m[4][4];
     //   build_rotmatrix( m, m_gldata.quat );
     //   glMultMatrixf( &m[0][0] );
    lastpoint=curpoint;
}
void settrackball::init(float inx, float iny)
{
    m_gldata.beginx=inx;
    m_gldata.beginy=iny;
}


void  settrackball::build_rotmatrix(float m[4][4], float q[4])
{
    m[0][0] = 1.0f - 2.0f * (q[1] * q[1] + q[2] * q[2]);
    m[0][1] = 2.0f * (q[0] * q[1] - q[2] * q[3]);
    m[0][2] = 2.0f * (q[2] * q[0] + q[1] * q[3]);
    m[0][3] = 0.0f;

    m[1][0] = 2.0f * (q[0] * q[1] + q[2] * q[3]);
    m[1][1]= 1.0f - 2.0f * (q[2] * q[2] + q[0] * q[0]);
    m[1][2] = 2.0f * (q[1] * q[2] - q[0] * q[3]);
    m[1][3] = 0.0f;

    m[2][0] = 2.0f * (q[2] * q[0] - q[1] * q[3]);
    m[2][1] = 2.0f * (q[1] * q[2] + q[0] * q[3]);
    m[2][2] = 1.0f - 2.0f * (q[1] * q[1] + q[0] * q[0]);
    m[2][3] = 0.0f;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
