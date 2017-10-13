#ifndef VERTEXUV_H
#define VERTEXUV_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>
#include <iostream>
#include <fstream>

class vertexuv
{
public:
    vertexuv();
    vertexuv(float nu, float nv);
    ~vertexuv();

    vertexuv( const vertexuv &vert );
    vertexuv& operator=( const vertexuv &vert );

    void set(float nu, float nv);

    float getu();
    float getv();

    void getu(float *nu);
    void getv(float * nv);

    void setname(int);
    int getname();

    void serialize(std::ifstream*  ar)
    {
        if(ar->is_open())
        {
            ar->read((char*)this,sizeof(vertexuv));
            /*
            (*ar) >> x;
            (*ar) >> y;
            (*ar) >> z;
            (*ar) >> m_imaterial;*/
        }
        else
        {


        }


    }
    void serialize(std::ofstream*  ar)
    {
        if(ar->is_open())
        {

            ar->write((char*)this,sizeof(vertexuv));

            //(*ar) << x;
            //(*ar) << y;
            //(*ar) << z;
            //(*ar) << m_imaterial;
        }
        else
        {


        }


    }
private:
    float u,v;
    int m_iname;

};

#endif // VERTEXUV_H
