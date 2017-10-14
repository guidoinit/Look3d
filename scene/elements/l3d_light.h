#ifndef L3D_LIGHT_H
#define L3D_LIGHT_H


#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "scene/sceneenum.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;
namespace l3d
{
namespace light
{
    enum LigthType
    {
        l_lamp=1,
        l_spot=2,
        l_sun=3,
        l_directional=4
    };
    typedef struct _l3d_light_struct
    {
        l3d_uint _id_layer;
        l3d_float diffuse[4];
        l3d_float ambient[4];
        l3d_float specular[4];
        l3d_float spotdir[4];
        l3d_float spot_cutoff;
        l3d_float spot_distance;

        l3d_float degree;
        l3d_float spot_exponent;
        l3d_float costant_attenuation;
        l3d_float linear_attenuation;
        l3d_float quadratic_attenuation;

        l3d_uint m_nlight;
        l3d_uint sname;
        LigthType type;
        float pos;

        float m_dis;
        l3d_vertex_fast m_pos;
        l3d_vertex_fast m_pos2;
        l3d_string m_name;

        l3d_float m_radius;
        l3d_bool on;
        l3d_bool m_bselected;
        l3d_float m_angoloa;
        l3d_float m_angolob;

        //sphere
        l3d_mesh_struct _sphere;
        l3d_mesh_struct _circle;

        //metodi
        bool selected()
        {
            return(m_bselected);
        }

        void selected(bool _bval)
        {
            m_bselected=_bval;
        }

        bool getonoff()
        {
            return(on);
        }

        void init()
        {
            float lpos[4];
            lpos[0]=m_pos.x;
            lpos[1]=m_pos.y;
            lpos[2]=m_pos.z;
            lpos[3]=pos;
            //m_sphere->world_pos=m_pos;

            glLightfv(m_nlight,GL_POSITION,lpos);
            glLightfv(m_nlight,GL_DIFFUSE,diffuse);
            glLightfv(m_nlight,GL_AMBIENT,ambient);
            glLightfv(m_nlight,GL_SPECULAR,specular);

            if(type==l_lamp || type==l_sun)
            {
                glLightf(m_nlight,GL_SPOT_CUTOFF,180.0F);
                //valori predefiniti
                float dir[4]={0.0F,0.0F,-1.0F,0.0F};
                glLightf(m_nlight,GL_SPOT_EXPONENT,0.0F);
                glLightfv(m_nlight,GL_SPOT_DIRECTION,dir);
                glLightf(m_nlight, GL_CONSTANT_ATTENUATION, 1.0F);
                glLightf(m_nlight, GL_LINEAR_ATTENUATION,0.0F);
                glLightf(m_nlight, GL_QUADRATIC_ATTENUATION, 0.0F);

            }
            if(type==l_spot)
            {
                glLightfv(m_nlight,GL_POSITION,lpos);
                glLightf(m_nlight,GL_SPOT_CUTOFF,spot_cutoff);
                glLightf(m_nlight,GL_SPOT_EXPONENT,spot_exponent);
                glLightfv(m_nlight,GL_SPOT_DIRECTION,spotdir);
                glLightf(m_nlight, GL_CONSTANT_ATTENUATION, costant_attenuation);
                glLightf(m_nlight, GL_LINEAR_ATTENUATION,linear_attenuation);
                glLightf(m_nlight, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

            }
            if(type==l_directional)
            {
                    glLightf(m_nlight,GL_SPOT_CUTOFF,180.0F);
                    glLightf(m_nlight,GL_SPOT_EXPONENT,spot_exponent);
                    glLightfv(m_nlight,GL_SPOT_DIRECTION,spotdir);
                    glLightf(m_nlight, GL_CONSTANT_ATTENUATION, costant_attenuation);
                    glLightf(m_nlight, GL_LINEAR_ATTENUATION,linear_attenuation);
                    glLightf(m_nlight, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

            }
            if(on)
                glEnable(m_nlight);
            else
                glDisable(m_nlight);



        }

        void calculate()
        {
            float pos[3];

            spotdir[0]=(1.0F * sin(m_angoloa/180.0F*3.141592F)*cos(m_angolob/180.0F*3.141592F));
            spotdir[1]=(1.0F * sin(m_angoloa/180.0F*3.141592F)*sin(m_angolob/180.0F*3.141592F));
            spotdir[2]=(1.0F * cos(m_angoloa/180.0F*3.141592F));
            spotdir[3]=1.0f;



            pos[0]=m_pos.x+(spot_distance * sin(m_angoloa/180.0F*3.141592F)*cos(m_angolob/180.0F*3.141592F));
            pos[1]=m_pos.y+(spot_distance * sin(m_angoloa/180.0F*3.141592F)*sin(m_angolob/180.0F*3.141592F));
            pos[2]=m_pos.z+(spot_distance * cos(m_angoloa/180.0F*3.141592F));

            m_pos2.x=(pos[0]);
            m_pos2.y=(pos[1]);
            m_pos2.z=(pos[2]);

            _circle._transformation._wp.set(pos[0],pos[1],pos[2]);

            m_dis=sqrt(pow((m_pos.x-m_pos2.x),2)+
                                           pow((m_pos.y-m_pos2.y),2)+
                                           pow((m_pos.z-m_pos2.z),2));

            m_radius=m_dis*tan(spot_cutoff/180.0F*3.141592F);

            //_circle._transformation._scale.x*=m_radius;
            //_circle._transformation._scale.z*=m_radius;
        }

        float getanglea()
        {
            return(m_angoloa);
        }

        float getangleb()
        {
            return(m_angolob);

        }

        void setanglea(float _a)
        {
            m_angoloa=_a;
        }

        void setangleb(float _a)
        {
            m_angolob=_a;
        }

        void move(l3d_vertex_fast _v)
        {
            m_pos=_v;

            calculate();
        }

        void setname(l3d_uint _n)
        {
            sname=_n;

        }

        void setvertex(l3d_vertex_fast _v)
        {
            m_pos=_v;
            calculate();
        }

        void setnum(int _n)
        {
            m_nlight=_n;

        }

        void setinternalname(GLuint _in)
        {
            m_nlight=_in;

        }

        void settype(LigthType _t)
        {
            type=_t;

        }

        void setdiffuse(GLfloat * _d)
        {
            this->diffuse[0]=*_d++;
            this->diffuse[1]=*_d++;
            this->diffuse[2]=*_d++;
            this->diffuse[3]=*_d;

        }

        void setcutoff(float _val)
        {
            spot_cutoff=_val;

        }

        void setdistance(float _val)
        {
            this->spot_distance=_val;

        }

        void draw()
        {

        }

        void drawspot()
        {
            calculate();

//            glPushMatrix();

//            glBegin(GL_LINES);

//                glVertex3f(m_pos.x,m_pos.y,m_pos.z);
//                glVertex3f(m_pos2.x,m_pos2.y,m_pos2.z);



//            glEnd();

            _circle._transformation._rotate.x=-(m_angoloa+90.0F);
            _circle._transformation._rotate.z=m_angolob-90.0F;

            _circle._transformation._scale.x=m_radius;
            _circle._transformation._scale.z=m_radius;

            pl3d_line_struct _line=_circle._edges.first();

            _circle._transformation.draw();

            while(_line)
            {

                l3d_uint v0,v1;

                pl3d_vertex_fast pv0,pv1;
                v0=_line->v0;
                v1=_line->v1;

                pv0=_circle._vertex.get(v0);
                pv1=_circle._vertex.get(v1);

//                glBegin(GL_LINES);


//                    glVertex3f(pv0->x,pv0->y,pv0->z);
//                    glVertex3f(pv1->x,pv1->y,pv1->z);

//                    glVertex3f(pv0->x,pv0->y,pv0->z);
//                    glVertex3f(m_pos.x,m_pos.y,m_pos.z);


//                glEnd();

                _line=_line->next;
            }





//            glPopMatrix();

        }

        void drawselect()
        {

        }

        void onoff(bool _val)
        {
            on=!on;

        }

        int getnum(void)
        {
            return(m_nlight);

        }

        std::string getlight()
        {
            std::string str;

            str.append("GL_LIGHT%d",m_nlight);

            return (str);

        }

        l3d_vertex_fast getvertex()
        {
            return(m_pos);

        }

    }l3d_light,*pl3d_light;

    class l3d_light_class
    {
    public:
        l3d_light_class();
    };

}
}
#endif // L3D_LIGHT_H
