#define GLEW_STATIC
#include <GL/glew.h>
//#include <QGLWidget>
#include <QDebug>

#include "mesh/l3d_face4.h"
#include "mesh/l3d_line.h"
#include "l3d_include.h"
#include "l3d_bufferobject.h"

using namespace l3d;
using namespace l3d::face4;


#include "mesh/l3d_vertex.h"

#include "mesh/vbo/objectvbo.h"


objectVBO::objectVBO()
{
    //m_pTextureImage = NULL;
     m_bbuild=false;
    m_ivertex=0;
    m_nindex=0;
    m_nindex3=0;


}



objectVBO::~objectVBO()
{
    m_bbuild=false;
    delete [] m_buffer;
    delete [] m_index;

}


void objectVBO::realisevbo()
{

}
void objectVBO::createnormalbuffer(l3d_vertex local_vertex)
{
    m_inormal=local_vertex.size();

    if(m_inormal==0)
        return;
    m_nbuffer=new GLuint[m_inormal*3];
    int sb=0;
    for(int ix=0; ix < m_inormal; ix++)
    {
        m_nbuffer[sb++]=local_vertex.get(ix)->normals[0];
        m_nbuffer[sb++]=local_vertex.get(ix)->normals[1];
        m_nbuffer[sb++]=local_vertex.get(ix)->normals[2];
    }
}
void objectVBO::initbuffer_normals()
{
    glGenBuffers(1, &m_nboid);

    glBindBuffer(GL_NORMAL_ARRAY, m_nboid);

    glBufferData(GL_NORMAL_ARRAY, sizeof(GLuint)*m_inormal*3,m_nbuffer,GL_STATIC_DRAW);

    delete[] m_nbuffer;
}

void objectVBO::createbuffer(l3d_vertex local_vertex)
{

       int creal=0;
       m_ivertex=local_vertex.size();

       if (m_ivertex==0)
           return;

       //m_buffer=new VertexVBO[m_ivertex];
       m_ibuffer=new GLuint[m_ivertex];
       m_fbuffer=new GLfloat[m_ivertex*3];

       int ifb=0;
       for(int ix=0; ix < m_ivertex; ix++)
       {
           if(local_vertex.get(ix)->erase)
               continue;

           m_ibuffer[ix]=ix;


           m_fbuffer[ifb++]=local_vertex.get(ix)->x;
           m_fbuffer[ifb++]=local_vertex.get(ix)->y;
           m_fbuffer[ifb++]=local_vertex.get(ix)->z;

           creal++;

       }
       m_ivertex=creal;


}

void objectVBO::createbuffer()
{
    /*

       int nsizev=_mesh->local_vertex.size();

       if (nsizev==0)
           return;

       m_buffer[nsizev];

       //riempie il buffer dei vertici dell'oggetto
       for(int ix=0; ix < nsizev; ix++)
       {
           float n0,n1,n2;
           m_buffer[ix].location[0]=_mesh->local_vertex[ix].GetX();
           m_buffer[ix].location[1]=_mesh->local_vertex[ix].GetY();
           m_buffer[ix].location[2]=_mesh->local_vertex[ix].GetZ();

           m_buffer[ix].tex[0]=_mesh->local_vertex[ix].m_ntx;
           m_buffer[ix].tex[1]=_mesh->local_vertex[ix].m_nty;

           _mesh->local_vertex[ix].getnormal(&n0,&n1,&n2);
           m_buffer[ix].normal[0]=n0;
           m_buffer[ix].normal[1]=n1;
           m_buffer[ix].normal[2]=n2;

           m_buffer[ix].color[0]=0.5F;
           m_buffer[ix].color[1]=0.5F;
           m_buffer[ix].color[2]=0.5F;
           m_buffer[ix].color[3]=1.0F;

       }
       */
}
void objectVBO::createpoly3buffer(l3d_face4 m_poly,l3d_face4 m_poly2)
{

    int allindex=(m_poly.size()*3)+(m_poly2.size()*3);// + (m_poly3.size()*3);

    if(allindex==0)
       return;

    m_nindex=m_poly.size();

    m_nindex3=m_poly2.size();
    int lastp=0;

    m_index= new  GLuint[m_poly.size()*3];
    m_index3= new  GLuint[m_poly2.size()*3];



    for(int ix=0, ixp=0 ; ixp < (m_poly.size()*3); ix++,ixp+=3)
    {


        m_index[ixp]=m_poly.find(ix)->get(0);
        m_index[ixp+1]=m_poly.find(ix)->get(1);
        m_index[ixp+2]=m_poly.find(ix)->get(2);
        lastp=ixp;
    }
    for(int ix=0, ixp=0 ; ixp < (m_poly2.size()*3); ix++,ixp+=3)
    {
        m_index3[ixp]=m_poly2.find(ix)->get(0);
        m_index3[ixp+1]=m_poly2.find(ix)->get(1);
        m_index3[ixp+2]=m_poly2.find(ix)->get(2);
        lastp+=3;

    }




}
void objectVBO::creatematerialbuffer(l3d_vertex local_vertex)
{
    m_nmaterial=local_vertex.size();

    if(m_nmaterial<=0)
        return;

    m_matbuffer= new GLuint[m_nmaterial];
    for(int ix=0; ix < m_nmaterial; ix++)
    {
        int imat=local_vertex.get(ix)->_imaterial;
        m_matbuffer[ix]=imat;

    }

}

void objectVBO::createindex(l3d_face4 m_poly)
{

    int allindex=(m_poly.size()*3);// + (m_poly3.size()*3);

    //if(allindex==0)
     //   return;

    m_nindex=m_poly.size();


    int lastp=0;

    m_index= new  GLuint[allindex];
    m_ibuffer= new  GLuint[m_ivertex];

    for(int ix=0, ixp=0 ; ixp < allindex; ix++,ixp+=3)
    {


        m_index[ixp]=m_poly.find(ix)->get(0);
        m_index[ixp+1]=m_poly.find(ix)->get(1);
        m_index[ixp+2]=m_poly.find(ix)->get(2);
        lastp=ixp;
    }

    for(int ix=0; ix < m_ivertex; ix++)
    {
        m_ibuffer[ix]=ix;

    }

    /*
    nindex=(m_poly3.size()*3)+lastp;

    for(int ix=0, ixp=lastp ; ixp < nindex; ix++,ixp+=3)
    {

        m_index[ixp]=m_poly3[ix].lista_vertici[0];
        m_index[ixp+1]=m_poly3[ix].lista_vertici[1];
        m_index[ixp+2]=m_poly3[ix].lista_vertici[2];

    }
    */

}
void objectVBO::createindex()
{
/*
    int allindex=(_mesh->m_poly.size()*3);// + (m_poly3.size()*3);

    if(allindex==0)
        return;

    m_nindex=allindex;

    int nindex=_mesh->m_poly.size()*3;
    int lastp=0;
    m_index[allindex];

    for(int ix=0, ixp=0 ; ixp < nindex; ix++,ixp+=3)
    {
        m_index[ixp]=_mesh->m_poly[ix].lista_vertici[0];
        m_index[ixp+1]=_mesh->m_poly[ix].lista_vertici[1];
        m_index[ixp+2]=_mesh->m_poly[ix].lista_vertici[2];
        lastp=ixp;
    }

    /*
    nindex=(m_poly3.size()*3)+lastp;

    for(int ix=0, ixp=lastp ; ixp < nindex; ix++,ixp+=3)
    {

        m_index[ixp]=m_poly3[ix].lista_vertici[0];
        m_index[ixp+1]=m_poly3[ix].lista_vertici[1];
        m_index[ixp+2]=m_poly3[ix].lista_vertici[2];

    }
    */

}
void objectVBO::setvertex(int vx)
{
    /*
    float n0,n1,n2;
    if(!(vx>0 && vx < _mesh->local_vertex.size()))
        return;

    m_buffer[vx].location[0]=_mesh->local_vertex[vx].GetX();
    m_buffer[vx].location[1]=_mesh->local_vertex[vx].GetY();
    m_buffer[vx].location[2]=_mesh->local_vertex[vx].GetZ();

    m_buffer[vx].tex[0]=_mesh->local_vertex[vx].m_ntx;
    m_buffer[vx].tex[1]=_mesh->local_vertex[vx].m_nty;
    _mesh->local_vertex[vx].getnormal(&n0,&n1,&n2);

    m_buffer[vx].normal[0]=n0;
    m_buffer[vx].normal[1]=n1;
    m_buffer[vx].normal[2]=n2;

    m_buffer[vx].color[0]=0.5F;
    m_buffer[vx].color[1]=0.5F;
    m_buffer[vx].color[2]=0.5F;
    m_buffer[vx].color[3]=1.0F;

    updatebuffer();*/
}

void objectVBO::updatebuffer()
{
    //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VertexVBO) * _mesh->local_vertex.size(), m_buffer);

}
void objectVBO::createlinebuffer(l3d_line m_line)
{
    int nl=m_line.size(),lreal=0;
    m_nlines=nl;
    m_lbuffer=new GLuint[nl*2];

    int start=0;
    for(int ix=0; ix<nl;ix++)
    {
        if(m_line.find(ix)->erase)
            continue;
        m_lbuffer[start++]=m_line.find(ix)->v0;
        m_lbuffer[start++]=m_line.find(ix)->v1;
        lreal++;

    }
    m_nlines=lreal;


}



void objectVBO::initbuffer_wireframe()
{
    //make line buffer



    glGenBuffers(1, &m_lboid);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_lboid);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*m_nlines*2,m_lbuffer,GL_STATIC_DRAW);

    delete[] m_lbuffer;



}
void objectVBO::initbuffer_material()
{
    if(m_nmaterial>0)
    {
        glGenBuffers(1, &m_matboid);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_matboid);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_nmaterial,m_matbuffer,GL_STATIC_DRAW);

        delete[] m_matbuffer;

    }


}

void objectVBO::initbuffer_solid()
{
    //make line buffer


    if(m_nindex>0)
    {
        glGenBuffers(1, &m_sboid);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_sboid);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_nindex *3,m_index,GL_STATIC_DRAW);

        delete[] m_index;

    }


    if(m_nindex3>0)
    {

        glGenBuffers(1, &m_sboid2);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_sboid2);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_nindex3 *3,m_index3,GL_STATIC_DRAW);

        delete[] m_index3;


    }



}


void objectVBO::initbuffer_onlyvertex()
{
    glGenBuffers(1, &m_vboid);// Create the buffer ID, this is basically the same as generating texture ID's

    qDebug() << "vboid:" << m_vboid;

    glBindBuffer(GL_ARRAY_BUFFER, m_vboid); // Bind the buffer (vertex array data)

    // Allocate space.  We could pass the mesh in here (where the NULL is), but it's actually faster to do it as a
    // seperate step.  We also define it as GL_STATIC_DRAW which means we set the data once, and never
    // update it.  This is not a strict rule code wise, but gives hints to the driver as to where to store the data
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_ivertex*3,m_fbuffer,GL_STATIC_DRAW);

    glVertexPointer(3, GL_FLOAT, 0, 0);

    delete [] m_fbuffer;
    //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VertexVBO) * m_ivertex, m_buffer); // Actually upload the data

    // Set the pointers to our data.  Except for the normal value (which always has a size of 3), we must pass
    // the size of the individual component.  ie. A vertex has 3 points (x, y, z), texture coordinates have 2 (u, v) etc.
    // Basically the arguments are (ignore the first one for the normal pointer), Size (many components to
    // read), Type (what data type is it), Stride (how far to move forward - in bytes - per vertex) and Offset
    // (where in the buffer to start reading the data - in bytes)

    // Make sure you put glVertexPointer at the end as there is a lot of work that goes on behind the scenes
    // with it, and if it's set at the start, it has to do all that work for each gl*Pointer call, rather than once at
    // the end.
    //glTexCoordPointer(2, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(12));
    //glNormalPointer(GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(20));
    //glColorPointer(4, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(32));
    //glVertexPointer(3, GL_FLOAT, sizeof(GLfloat),0);

    // When we get here, all the vertex data is effectively on the card

    // Our Index Buffer, same as above, the variable needs to be accessible wherever we draw

    glGenBuffers(1, &m_iboid); // Generate buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboid); // Bind the element array buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_ivertex,m_ibuffer,GL_STATIC_DRAW);

    delete[] m_ibuffer;
    //Upload the index array, this can be done the same way as above (with NULL as the data, then a
    // glBufferSubData call, but doing it all at once for convenience)
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_nindex * sizeof(GLubyte), m_index, GL_STATIC_DRAW);
}

void objectVBO::initbuffer()
{
    glGenBuffers(1, &m_vboid);// Create the buffer ID, this is basically the same as generating texture ID's

    qDebug() << "vboid:" << m_vboid;

    glBindBuffer(GL_ARRAY_BUFFER, m_vboid); // Bind the buffer (vertex array data)

    // Allocate space.  We could pass the mesh in here (where the NULL is), but it's actually faster to do it as a
    // seperate step.  We also define it as GL_STATIC_DRAW which means we set the data once, and never
    // update it.  This is not a strict rule code wise, but gives hints to the driver as to where to store the data
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexVBO) * m_ivertex, NULL,GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VertexVBO) * m_ivertex, m_buffer); // Actually upload the data

    // Set the pointers to our data.  Except for the normal value (which always has a size of 3), we must pass
    // the size of the individual component.  ie. A vertex has 3 points (x, y, z), texture coordinates have 2 (u, v) etc.
    // Basically the arguments are (ignore the first one for the normal pointer), Size (many components to
    // read), Type (what data type is it), Stride (how far to move forward - in bytes - per vertex) and Offset
    // (where in the buffer to start reading the data - in bytes)

    // Make sure you put glVertexPointer at the end as there is a lot of work that goes on behind the scenes
    // with it, and if it's set at the start, it has to do all that work for each gl*Pointer call, rather than once at
    // the end.
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(12));
    glNormalPointer(GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(20));
    glColorPointer(4, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(32));
    glVertexPointer(3, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(0));

    // When we get here, all the vertex data is effectively on the card

    // Our Index Buffer, same as above, the variable needs to be accessible wherever we draw

    glGenBuffers(1, &m_iboid); // Generate buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboid); // Bind the element array buffer
    // Upload the index array, this can be done the same way as above (with NULL as the data, then a
    // glBufferSubData call, but doing it all at once for convenience)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_nindex * sizeof(GLubyte), m_index, GL_STATIC_DRAW);
}

void objectVBO::DrawVBO()
{
/*
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
//f (m_b2D)
    //	glDisable(GL_CULL_FACE);
    if (_mesh->m_angolo[0]>360) _mesh->m_angolo[0]-=360;
    if (_mesh->m_angolo[1]>360) _mesh->m_angolo[1]-=360;
    if (_mesh->m_angolo[2]>360) _mesh->m_angolo[2]-=360;
    if(!_mesh->inmove)
    //{
            glTranslatef(_mesh->world_pos.GetX(),_mesh->world_pos.GetY(),_mesh->world_pos.GetZ());
    //}
    else
    //{
            glTranslatef(_mesh->world_pos_app.GetX()+_mesh->world_pos.GetX(),_mesh->world_pos_app.GetY()+_mesh->world_pos.GetY(),_mesh->world_pos_app.GetZ()+_mesh->world_pos.GetZ());
    //}
    //isapp=!isapp;

    //glTranslatef(0.0,0.0,-5.0);
    glRotatef(_mesh->m_angolo[0],1.0,0.0,0.0);
    glRotatef(_mesh->m_angolo[1],0.0,1.0,0.0);
    glRotatef(_mesh->m_angolo[2],0.0,0.0,1.0);
    glScalef(_mesh->m_Scale[0],_mesh->m_Scale[1],_mesh->m_Scale[2]);
    if(_mesh->m_bsmooth)
            glShadeModel(GL_SMOOTH);
    else
            glShadeModel(GL_FLAT);


    // Bind our buffers much like we would for texturing
    glBindBuffer(GL_ARRAY_BUFFER, m_vboid);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboid);

    // Set the state of what we are drawing (I don't think order matters here, but I like to do it in the same
    // order I set the pointers
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    // Resetup our pointers.  This doesn't reinitialise any data, only how we walk through it
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(12));
    glNormalPointer(GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(20));
    glColorPointer(4, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(32));
    glVertexPointer(3, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(0));

    // Actually do our drawing, parameters are Primative (Triangles, Quads, Triangle Fans etc), Elements to
    // draw, Type of each element, Start Offset
    glDrawElements(GL_TRIANGLES, m_nindex, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

    // Disable our client state back to normal drawing
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);


    glPopMatrix();*/
}
bool objectVBO::isbuild()
{
    return(m_bbuild);
}

bool objectVBO::BuildVBO()
{

    if(m_bbuild)
        return true;
    createbuffer();
    qDebug() << "buffer";
    createindex();
    qDebug() << "index";
    initbuffer();
    qDebug() <<  "initbuffer";

    m_bbuild=true;

    return true;

    // Our Copy Of The Data Is No Longer Necessary, It Is Safe In The Graphics Card
    /*
    delete [] m_pVertices; m_pVertices = NULL;
    delete [] m_pTexCoords; m_pTexCoords = NULL;
    */
}
