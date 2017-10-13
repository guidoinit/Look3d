#ifndef OBJECTVBA_H
#define OBJECTVBA_H


#include <mesh/l3d_vertex.h>
#include <mesh/l3d_line.h>
#include "mesh/l3d_face4.h"

#include <vector>


//#include "mesh/object3dinclude.h"

using namespace std;
using namespace l3d::vertex3f;
using namespace l3d::face4;
using namespace l3d::edge;

typedef struct
{
        GLfloat location[3];
        GLfloat tex[2];
        GLfloat normal[3];
        GLfloat color[4];
        GLubyte padding[16]; //riempie la struttura di 64bit per incrementare le performance
} VertexVBO;
class objectVBO
{

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

public:


    /*
    objectVBO (  object3d *obj)
    {

        m_bbuild=false;
        _mesh=obj;
        BuildVBO();
        _mesh=NULL;


    }*/

    objectVBO ( const objectVBO& obj)
    {
        m_bbuild=obj.m_bbuild;
        m_vboid=obj.m_vboid;
        m_iboid=obj.m_iboid;

        m_ivertex=obj.m_ivertex;
        m_nindex=obj.m_nindex;

        if(m_bbuild)
        {
            VertexVBO* m_buffer=(VertexVBO*) &obj.m_buffer;
            GLuint * m_index=(GLuint*) &obj.m_index;

            //strncpy((char*)&m_buffer,(char*)&obj.m_buffer,sizeof(VertexVBO)*obj.m_ivertex);
            //strncpy((char*)&m_index,(char*)&obj.m_index,sizeof(GLuint)*obj.m_nindex);
        }
    }




    objectVBO& operator=(const objectVBO &obj)

    {


        m_bbuild=obj.m_bbuild;
        m_vboid=obj.m_vboid;
        m_iboid=obj.m_iboid;
        m_ivertex=obj.m_ivertex;
        m_nindex=obj.m_nindex;
        if(m_bbuild)
        {
            VertexVBO* m_buffer=(VertexVBO*) &obj.m_buffer;
            GLuint * m_index=(GLuint*) &obj.m_index;

            //strncpy((char*)&m_buffer,(char*)&obj.m_buffer,sizeof(VertexVBO)*obj.m_ivertex);
            //strncpy((char*)&m_index,(char*)&obj.m_index,sizeof(GLuint)*obj.m_nindex);
        }
        return (*this);
    }




    GLuint m_vboid;
    GLuint m_lboid;
    GLuint m_sboid;
    GLuint m_sboid2;
    GLuint m_nboid;
    GLuint m_matboid;


    GLuint m_iboid;


    unsigned int m_ivertex,m_inormal;
    VertexVBO *m_buffer;
    GLfloat* m_fbuffer;

    GLuint *m_index;
    GLuint *m_index3;
    GLuint *m_ibuffer;
    GLuint *m_lbuffer;
    GLuint *m_nbuffer;
    GLuint *m_matbuffer;
    unsigned int m_nindex,m_nindex3;
    unsigned int m_nlines;
    unsigned int m_nmaterial;

    objectVBO();


    ~objectVBO();

    void realisevbo();
    void createbuffer();
    void creatematerialbuffer(l3d_vertex local_vertex);
    void createbuffer(l3d_vertex local_vertex);
    void createindex();
    void createindex(l3d_face4 m_poly);
    void createpoly3buffer(l3d_face4 m_poly,l3d_face4 m_poly2);
    void createlinebuffer(l3d_line m_line);
    void createnormalbuffer(l3d_vertex local_vertex);
    void initbuffer();
    void initbuffer_onlyvertex();
    void initbuffer_wireframe();
    void initbuffer_solid();
    void initbuffer_material();
    void initbuffer_normals();

    void setvertex(int ivertex);
    void updatebuffer();
    bool isbuild();
    bool BuildVBO();

    void DrawVBO();
private:
    bool m_bbuild;


    //object3d *_mesh;

};

#endif // OBJECTVBA_H
