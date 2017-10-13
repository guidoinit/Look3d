#ifndef LIGTH_H
#define LIGTH_H
#include "./mesh/object3dinclude.h"

#include "./mesh/mesh3d/circle.h"
#include "./mesh/mesh3d/sphereuv.h"

namespace LIGTH
{
    enum LigthType
    {
        l_lamp=1,
        l_spot=2,
        l_sun=3,
        l_directional=4
    };
}
class ligth
{
public:
        ligth();
        ligth(vertex );
        bool selected();
        void selected(bool);
        bool getonoff();
        void init();
        float getanglea();
        float getangleb();
        void setanglea(float);
        void setangleb(float);
        void move(vertex);
        void SetName(int);
        void SetVertex(vertex);
        void SetNum(int);
        void setinternalname(GLuint);
        void SetType(LIGTH::LigthType);
        void SetDiffuse(GLfloat *);
        void setcutoff(float);
        void setdistance(float);
        void Draw();
        void drawSpot();
        void DrawSelect();
        void onoff(bool);
        int GetNum(void);
        string GetLight();
        vertex GetVertex();
        GLuint m_nlight;
        int sname;
        virtual ~ligth();
        GLfloat diffuse[4];
        GLfloat ambient[4];
        GLfloat specular[4];
        GLfloat spotdir[4];
        GLfloat spot_cutoff;
        GLfloat spot_distance;

        GLfloat degree;
        GLfloat spot_exponent;
        GLfloat costant_attenuation;
        GLfloat linear_attenuation;
        GLfloat quadratic_attenuation;

        LIGTH::LigthType type;
        float pos;

        float m_dis;
        vertex m_pos;
        vertex m_pos2;
        string m_name;
        sphereuv * m_sphere;

        /*ligth ( const ligth &obj )
        {
                m_name=obj.m_name;
                m_nlight=obj.m_nlight;
                m_color=obj.m_color;
                m_pos=obj.m_pos;
                type=obj.type;
                m_sphere=obj.m_sphere;

        }

        ligth& operator=( const ligth &obj )
        {
                m_name=obj.m_name;
                m_nlight=obj.m_nlight;
                m_color=obj.m_color;
                m_pos=obj.m_pos;
                type=obj.type;
                m_sphere=obj.m_sphere;

                return (*this);

        }*/

private:
        //virtual void Serialize(CArchive& ar);
        float m_radius;
        bool on;
        bool m_bselected;
        void calculate();
        float m_angoloa;
        float m_angolob;
        circle *m_circle;
};



#endif // LIGTH_H
