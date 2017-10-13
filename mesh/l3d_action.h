#ifndef L3D_ACTION_H

#define L3D_ACTION_H
#define GLEW_STATIC

#include <GL/glew.h>
#include <QtOpenGL>
#include "l3d_vertex.h"

namespace l3d
{
    using namespace vertex3f;

    typedef struct l3d_action_struct{
    l3d_vertex_fast vsposta;
    l3d_uint nobject;
    l3d_uint nframe;
    l3d_float fangolo[3];
    l3d_float fsposta[3];
    l3d_float fscala[3];
    l3d_uint naction;
    l3d_bool dirx,diry,dirz;
    l3d_bool bhide;
    l3d_bool bkeyframe;
    l3d_uint q;
    l3d_float fq;


    void serialize(std::ifstream *ar)
    {

        int size;

        if(ar->is_open())
        {
            vsposta.serialize(ar);
            size=sizeof(int);
            ar->read((char*)&nobject,sizeof(l3d_uint));
            ar->read((char*)&nframe,sizeof(l3d_uint));
            size=sizeof(float)*3;
            ar->read((char*)&fangolo,sizeof(l3d_float)*3);
            ar->read((char*)&fsposta,sizeof(l3d_float)*3);
            ar->read((char*)&fscala,sizeof(l3d_float)*3);

            ar->read((char*)&naction,sizeof(l3d_uint));

            ar->read((char*)&dirx,sizeof(l3d_bool));
            ar->read((char*)&diry,sizeof(l3d_bool));
            ar->read((char*)&dirz,sizeof(l3d_bool));

            ar->read((char*)&bhide,sizeof(l3d_bool));
            ar->read((char*)&bkeyframe,sizeof(l3d_bool));

            ar->read((char*)&q,sizeof(l3d_uint));
            ar->read((char*)&fq,sizeof(l3d_uint));



        }
    }
    void serialize(std::ofstream *ar)
    {

        int size;

        if(ar->is_open())
        {
            vsposta.serialize(ar);
            size=sizeof(int);
            ar->write((char*)&nobject,sizeof(l3d_uint));
            ar->write((char*)&nframe,sizeof(l3d_uint));
            size=sizeof(float)*3;
            ar->write((char*)&fangolo,sizeof(l3d_float)*3);
            ar->write((char*)&fsposta,sizeof(l3d_float)*3);
            ar->write((char*)&fscala,sizeof(l3d_float)*3);

            ar->write((char*)&naction,sizeof(l3d_uint));

            ar->write((char*)&dirx,sizeof(l3d_bool));
            ar->write((char*)&diry,sizeof(l3d_bool));
            ar->write((char*)&dirz,sizeof(l3d_bool));

            ar->write((char*)&bhide,sizeof(l3d_bool));
            ar->write((char*)&bkeyframe,sizeof(l3d_bool));

            ar->write((char*)&q,sizeof(l3d_uint));
            ar->write((char*)&fq,sizeof(l3d_uint));



        }
    }
    void setactionsposta(l3d_vertex_fast v)
    {

            naction=1;
            vsposta=v;

            fsposta[0]=v.x;
            fsposta[1]=v.y;
            fsposta[2]=v.z;

    }
    l3d_vertex_fast getvertex()
    {
        l3d_vertex_fast vret;
        vret.x=fsposta[0];
        vret.y=fsposta[1];
        vret.z=fsposta[2];
            return( vret );




    }
    void setactionhide(bool b)
    {

            bhide=b;

            naction=4;
    }
    void setactionsposta(float v[3])
    {

            naction=1;

            fsposta[0]=v[0];
            fsposta[1]=v[1];
            fsposta[2]=v[2];

    }

    void setactionruota(float v[3] )
    {

            naction=2;

            fangolo[0]=v[0];

            fangolo[1]=v[1];

            fangolo[2]=v[2];

    }

    void setactionscala(float v[3])
    {

            naction=3;

            fscala[0] = v[0];

            fscala[1] = v[1];

            fscala[2] = v[2];


    }




    // funzioni membro action



    bool gethide()
    {
            return bhide;
    }
    int getaction()
    {

            return(naction);

    }

    int getspostaval()
    {

            return(q);

    }
    float fetscaleval()
    {

            return(fq);

    }
    int getspostadir()
    {

            if(dirx && diry && dirz)

                    return(4);

            if(dirx)

                    return 1;

            if(diry)

                    return 2;

            if(dirz)

                    return 3;


            return(0);

    }

    int setscale(char dir, float q)

    {

            naction=2;

            dirx=diry=dirz=false;

            if(dir=='x')

                    dirx=true;

            if(dir=='y')

                    diry=true;

            if(dir=='z')

                    dirz=true;

            if(dir=='a')

                    dirx=diry=dirz=true;

            this->fq=q;

            return 0;

    }
    int setrotate(char dir, float q)
    {

            naction=3;

            dirx=diry=dirz=false;

            if(dir=='x')

                    dirx=true;

            if(dir=='y')

                    diry=true;

            if(dir=='z')

                    dirz=true;

            if(dir=='a')

                    dirx=diry=dirz=true;

            this->fq=q;

            return 0;

    }

    bool iskey()
    {
            return bkeyframe;
    }
    int setsposta(char dir, int q)
    {
            naction=1;
            dirx=diry=dirz=false;
            if(dir=='x')
                    dirx=true;
            if(dir=='y')
                    diry=true;
            if(dir=='z')
                    dirz=true;
            if(dir=='a')
                    dirx=diry=dirz=true;
            this->q=q;

            return 0;
    }

    void keyframe()
    {
            bkeyframe=true;
    }

}l3d_action,*pl3d_action;
}

#endif // L3D_ACTION_H
