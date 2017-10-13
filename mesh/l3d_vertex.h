#ifndef L3D_VERTEX_H
#define L3D_VERTEX_H
#define GLEW_STATIC
#include <GL/glew.h>

#include "l3d_include.h"



#include <QtOpenGL>
#include <iostream>
#include <fstream>


namespace l3d
{
    typedef class vertex _classvertex;
    namespace vertex3f
    {
    typedef struct _l3d_vertex_fast
    {
        _l3d_vertex_fast *next;
        _l3d_vertex_fast *prev;

        l3d_double x,y,z;
        l3d_double normals[3];
        l3d_uint u,v;
        l3d_uint picking_name;
        l3d_bool _selected,erase;
        l3d_uint _iwave,_imaterial;

        void purge()
        {
            next=prev=NULL;
        }
        void selected(l3d_bool val)
        {
            _selected=val;
        }
        void setwave(l3d_uint w)
        {
            _iwave=w;
        }

        void set(l3d_glfloat _x,l3d_glfloat _y,l3d_glfloat _z)
        {
            x=_x;
            y=_y;
            z=_z;

        }
        void scale(_l3d_vertex_fast* s)
        {
            x*=s->x;
            y*=s->y;
            z*=s->z;
        }
        void rotate(_l3d_vertex_fast* vr)
        {
            rotatez(vr->z);
            rotatey(vr->y);
            rotatex(vr->x);
        }

        void rotatex(float gr)
        {



            gr=360.0F-gr;

            {

                float appx,appy,appy2,appz;


                appx=x;

                appy=y;

                appz=z;




                appy2 = appy *    cos(gr * 3.1415F/180.0F)    + appz *  sin(gr * 3.1415F/180.0F);

                appz  = appy *  (-sin(gr * 3.1415F/180.0F)) + appz *  cos(gr * 3.1415F/180.0F);


                y=appy2;

                z=appz;








            }

        }
        void rotatey(float gr)
        {

            gr=360.0F-gr;


            float appx,appx2,appy,appz;


            appx=x;

            appy=y;

            appz=z;

                /*z' = z*cos q - x*sin q
                x' = z*sin q + x*cos q
                y' = y*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);


            appx2 =(float) appx * cos((float) gr * 3.1415F / 180.0F ) + appz *    (-sin( (float) gr * 3.1415F/180.0F  ) );

            appz =(float) appx * sin((float) gr * 3.1415F / 180.0F ) + appz * cos( (float) gr * 3.1415F/180.0F      );


            x=appx2;

            z=appz;







        }

        void rotatez(float gr)
        {

            gr=360.0F-gr;


            float appx,appx2,appy,appz;


            appx=x;

            appy=y;

            appz=z;


            /*x' = x*cos q - y*sin q
            y' = x*sin q + y*cos q
            z' = z*/



            appx2 =appx * cos(gr * 3.1415F/180.0F) + appy * sin(gr * 3.1415F/180.0F);

            appy  =appx * (-sin(gr * 3.1415F/180.0F)) + appy * cos(gr * 3.1415F/180.0F);



            x=appx2;

            y=appy;








        }

        void normalize()
        {

            l3d_float d = (float)sqrt(x * x + y * y + z * z);

            if(d==0)
                d=1.0F;

            x/=d;
            y/=d;
            z/=d;

        }


        l3d_bool operator==(const _l3d_vertex_fast& l3dv)
        {
            return (x==l3dv.x && y==l3dv.y && z==l3dv.z);
        }

        void vectorproduct(_l3d_vertex_fast u,_l3d_vertex_fast v)
        {

            x=((u.y* v.z) - (u.z * v.y));
            y=((u.z * v.x) - (u.x * v.z));
            z=((u.x* v.y) - (u.y * v.x));




        }

        _l3d_vertex_fast operator=(const _l3d_vertex_fast& l3dv)
        {

            x=l3dv.x;
            y=l3dv.y;
            z=l3dv.z;
            u=l3dv.u;
            v=l3dv.v;

            //next=l3dv.next;
            //prev=l3dv.prev;
            _selected=l3dv._selected;
            erase=l3dv.erase;
            normals[0]=l3dv.normals[0];
            normals[1]=l3dv.normals[1];
            normals[2]=l3dv.normals[2];

            _imaterial=l3dv._imaterial;

        }
        _l3d_vertex_fast operator-=(const _l3d_vertex_fast& l3dv)
        {

            x=x-l3dv.x;
            y=y-l3dv.y;
            z=z-l3dv.z;

        }
        _l3d_vertex_fast operator+=(const _l3d_vertex_fast& l3dv)
        {

            x=x+l3dv.x;
            y=y+l3dv.y;
            z=z+l3dv.z;

        }
        _l3d_vertex_fast operator/=(const _l3d_vertex_fast& l3dv)
        {

            x=x/l3dv.x;
            y=y/l3dv.y;
            z=z/l3dv.z;

        }
        _l3d_vertex_fast operator/=(const int& val)
        {

            x/=(float)val;
            y/=(float)val;
            z/=(float)val;

        }
        _l3d_vertex_fast operator/=(const float& val)
        {

            x/=val;
            y/=val;
            z/=val;

        }
        _l3d_vertex_fast operator/=(const l3d_double val)
        {

            x/=val;
            y/=val;
            z/=val;

        }
        _l3d_vertex_fast operator*=(const _l3d_vertex_fast& l3dv)
        {

            x=x*l3dv.x;
            y=y*l3dv.y;
            z=z*l3dv.z;

        }

        void serialize(std::ifstream*  ar)
        {
            if(ar->is_open())
            {
                //ar->read((char*)this,sizeof(_l3d_vertex_fast));

                ar->read((char*)&x,sizeof(l3d_double));
                ar->read((char*)&y,sizeof(l3d_double));
                ar->read((char*)&z,sizeof(l3d_double));

                ar->read((char*)&normals,sizeof(l3d_double)*3);

                ar->read((char*)&u,sizeof(l3d_double));
                ar->read((char*)&v,sizeof(l3d_double));

                ar->read((char*)&erase,sizeof(l3d_bool));
                ar->read((char*)&_selected,sizeof(l3d_bool));



                ar->read((char*)&_imaterial,sizeof(l3d_uint));

                ar->read((char*)&_iwave,sizeof(l3d_uint));

            }
            else
            {



            }
        }

        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {

                //ar->write((char*)this,sizeof(_l3d_vertex_fast));


                ar->write((char*)&x,sizeof(l3d_double));
                ar->write((char*)&y,sizeof(l3d_double));
                ar->write((char*)&z,sizeof(l3d_double));

                ar->write((char*)&normals,sizeof(l3d_double)*3);

                ar->write((char*)&u,sizeof(l3d_double));
                ar->write((char*)&v,sizeof(l3d_double));

                ar->write((char*)&erase,sizeof(l3d_bool));
                ar->write((char*)&_selected,sizeof(l3d_bool));



                ar->write((char*)&_imaterial,sizeof(l3d_uint));

                ar->write((char*)&_iwave,sizeof(l3d_uint));

                //(*ar) << x;
                //(*ar) << y;
                //(*ar) << z;
                //(*ar) << m_imaterial;
            }
            else
            {


            }
        }


    }l3d_vertex_fast,*pl3d_vertex_fast;

    class l3d_vertex
    {
    private:
        pl3d_vertex_fast _first,_last;
        l3d_uint _nvertex;
    public:
        l3d_vertex();
        l3d_vertex(pl3d_vertex_fast);

        l3d_vertex &operator=(const l3d_vertex& v)
        {
            _first=v._first;
            _last=v._last;
            _nvertex=v._nvertex;

            return (*this);
        }

        void add(pl3d_vertex_fast);
        void add(pl3d_vertex_fast,l3d_uint nvertex);
        void add(l3d_float,l3d_float,l3d_float);

        void del(l3d_uint);
        void clear();
        pl3d_vertex_fast find(l3d_uint index);
        pl3d_vertex_fast first();
        l3d_bool isfirst();

        l3d_uint size();
        pl3d_vertex_fast get(l3d_uint index);

    };

}
}

#endif // L3D_VERTEX_H
