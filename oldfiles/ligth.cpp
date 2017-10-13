#define GLEW_STATIC
#include <GL/glew.h>
#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "mesh/object3dinclude.h"


#include "ligth.h"


ligth::ligth()
        : m_radius(0)
{
        type=LIGTH::l_lamp;//normal light to default

        type=LIGTH::l_lamp;//normal light to default

        on=true;
        diffuse[0]=0.0f;
        diffuse[1]=0.0f;
        diffuse[2]=0.0f;
        diffuse[3]=1.0f;

        specular[0]=0.0F;
        specular[1]=0.0F;
        specular[2]=0.0F;
        specular[3]=1.0F;

        ambient[0]=0.0F;
        ambient[1]=0.0F;
        ambient[2]=0.0F;
        ambient[3]=1.0F;

        m_angoloa=90.0F;m_angolob=-90.0F;
        spot_exponent=128.0F;
        spot_cutoff=45.0F;
        spot_distance=20.0F;
        spot_cutoff=45.0F;
        spot_distance=20.0F;
        costant_attenuation=1.0F;
        linear_attenuation=0.0F;
        quadratic_attenuation=0.0F;
        m_circle= new circle();


        m_sphere= new sphereuv();
        m_sphere->create(8,8,1.0F);
        m_sphere->SetColor(1.0F,1.0F,0.0F,1.0F);
        //m_sphere->SetWorldPos(pos.GetX(),pos.GetY(),pos.GetZ());

        m_bselected=false;
        calculate();


}
ligth::ligth(vertex pos)
{
    m_pos=pos;
    type=LIGTH::l_lamp;//normal light to default

    on=true;
    diffuse[0]=0.0f;
    diffuse[1]=0.0f;
    diffuse[2]=0.0f;
    diffuse[3]=1.0f;

    specular[0]=0.0F;
    specular[1]=0.0F;
    specular[2]=0.0F;
    specular[3]=1.0F;

    ambient[0]=0.0F;
    ambient[1]=0.0F;
    ambient[2]=0.0F;
    ambient[3]=1.0F;

    m_angoloa=90.0F;m_angolob=-90.0F;
    spot_exponent=128.0F;
    spot_cutoff=45.0F;
    spot_distance=20.0F;
    costant_attenuation=1.0F;
    linear_attenuation=0.0F;
    quadratic_attenuation=0.0F;

    m_circle= new circle();


    m_sphere= new sphereuv();
    m_sphere->create(8,8,1.0F);
    m_sphere->SetColor(1.0F,1.0F,0.0F,1.0F);
    m_sphere->SetWorldPos(pos.GetX(),pos.GetY(),pos.GetZ());

    m_bselected=false;
    calculate();
}

void ligth::onoff(bool lon)
{
    on=!on;
}
ligth::~ligth()
{
}
void ligth::selected(bool value)
{
    m_bselected=value;
}
bool ligth::getonoff()
{
    return on;
}

bool ligth::selected()
{
    return(m_bselected);
}
void ligth::setcutoff(float value)
{
    spot_cutoff=value;
    calculate();
}

void ligth::setinternalname(GLuint name)
{
    m_nlight=name;
}

void ligth::init()
{
        //CString str=pDoc->m_alight[ix].GetLight();

        float lpos[4];
        lpos[0]=m_pos.GetX();
        lpos[1]=m_pos.GetY();
        lpos[2]=m_pos.GetZ();
        lpos[3]=pos;
        //m_sphere->world_pos=m_pos;

        glLightfv(m_nlight,GL_POSITION,lpos);
        glLightfv(m_nlight,GL_DIFFUSE,diffuse);
        glLightfv(m_nlight,GL_AMBIENT,ambient);
        glLightfv(m_nlight,GL_SPECULAR,specular);

        if(type==LIGTH::l_lamp || type==LIGTH::l_sun)
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
        if(type==LIGTH::l_spot)
        {
            glLightfv(m_nlight,GL_POSITION,lpos);
            glLightf(m_nlight,GL_SPOT_CUTOFF,spot_cutoff);
            glLightf(m_nlight,GL_SPOT_EXPONENT,spot_exponent);
            glLightfv(m_nlight,GL_SPOT_DIRECTION,spotdir);
            glLightf(m_nlight, GL_CONSTANT_ATTENUATION, costant_attenuation);
            glLightf(m_nlight, GL_LINEAR_ATTENUATION,linear_attenuation);
            glLightf(m_nlight, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

        }
        if(type==LIGTH::l_directional)
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
float ligth::getanglea()
{
    return m_angoloa;
}

float ligth::getangleb()
{
    return m_angolob;
}

void ligth::setanglea(float value)
{
    m_angoloa=value;
    calculate();
}

void ligth::setangleb(float value)
{
    m_angolob=value;
    calculate();

}

vertex ligth::GetVertex()
{
        return(m_pos);
}
void ligth::SetDiffuse(GLfloat * df)
{
        this->diffuse[0]=*df++;
        this->diffuse[1]=*df++;
        this->diffuse[2]=*df++;
        this->diffuse[3]=*df;
}
void ligth::SetVertex(vertex nv)
{
        m_pos=nv;
        m_sphere->world_pos=m_pos;
        calculate();

}
// funzioni membro ligth
void ligth::SetNum(int nl)
{
      m_nlight=nl;
}
int ligth::GetNum(void)
{

    return(m_nlight);

}

string ligth::GetLight()
{
        string str;

        str.append("GL_LIGHT%d",m_nlight);

        return (str);
}
void ligth::SetName(int n)
{
        sname=n;
        m_name=n;
        m_sphere->SetName(n);
}
void ligth::SetType(LIGTH::LigthType t)
{
        //t==0 normale
        type=t;
        switch(t)
        {
        case LIGTH::l_sun:
                pos=0.0f;
                break;
        case LIGTH::l_lamp:
                pos=1.0f;
                break;
        case LIGTH::l_spot:
                pos=1.0f;

                m_angoloa=90.0F;m_angolob=-90.0F;
                spot_exponent=128.0F;
                spot_cutoff=45.0F;
                spot_distance=20.0F;
                costant_attenuation=1.0F;
                linear_attenuation=0.0F;
                quadratic_attenuation=0.0F;
                calculate();

                break;
        case LIGTH::l_directional:
            pos=1.0F;
            spot_cutoff=180.0F;
            m_angoloa=90.0F;m_angolob=-90.0F;
            costant_attenuation=1.0F;
            linear_attenuation=0.0F;
            quadratic_attenuation=0.0F;
            calculate();

            break;
        }
        //t==1 spot
}
void ligth::drawSpot()
{
    vertex appv;
    glPushMatrix();

    glBegin(GL_LINES);

        m_pos.Draw();
        m_pos2.Draw();

      /*  m_pos.Draw();
        appv=m_circle->local_vertex[0];
        appv+=m_circle->world_pos;
        appv.Draw();

        m_pos.Draw();
        appv=m_circle->local_vertex[16];
        appv+=m_circle->world_pos;
        appv.Draw();

        m_pos.Draw();

        appv=m_circle->local_vertex[32];
        appv+=m_circle->world_pos;
        appv.Draw();

        m_pos.Draw();
        appv=m_circle->local_vertex[48];
        appv+=m_circle->world_pos;
        appv.Draw();
*/
    glEnd();

    m_circle->m_angolo[0]=m_angoloa-90.0F;
    m_circle->m_angolo[1]=m_angolob+90.0F;
    //m_circle->m_angolo[2]=


    m_circle->DrawLines();


    glPopMatrix();

}

void ligth::Draw()
{

        m_sphere->m_Scale[0]=m_sphere->m_Scale[1]=m_sphere->m_Scale[2]=1.0F;//m_radius/100.0F;
        glDisable(GL_LIGHTING);
        //draw the ligth
        switch (type)
        {

                case LIGTH::l_sun://disegna solo una sfera
                    m_sphere->Draw(2);
                break;

                case LIGTH::l_lamp://disegna solo una sfera
                    m_sphere->Draw(2);
                break;

                case LIGTH::l_spot://disegna una sfera e una linea per la direzione
                    m_sphere->Draw(2);
                    drawSpot();
                break;
                case LIGTH::l_directional:
                    m_sphere->Draw(2);
                break;

        }
        glEnable(GL_LIGHTING);


}
void ligth::DrawSelect()
{
        //glMatrixMode(GL_MODELVIEW);
        //glPushMatrix();
        //glTranslatef(this->m_pos.GetX(),this->m_pos.GetY(),this->m_pos.GetZ());

        m_sphere->m_Scale[0]=m_sphere->m_Scale[1]=m_sphere->m_Scale[2]=m_radius/100.0F;




        //glColor4f(0.0F,1.0F,1.0F,0.5F);


        //glLoadName(this->sname);


        //draw the ligth
        switch (type)
        {

                case LIGTH::l_lamp://disegna solo una sfera
                        m_sphere->DrawSelect();
                        break;
                case LIGTH::l_spot://disegna una sfera e una linea per la direzione

                break;
        }
        glPopMatrix();
}

void ligth::move(vertex value)
{
    m_pos=value;

    m_sphere->world_pos=value;


    calculate();



}
void ligth::setdistance(float value)
{
    spot_distance=value;

    calculate();

}

void ligth::calculate()
{
    float pos[3];

    spotdir[0]=(1.0F * sin(m_angoloa/180.0F*3.141592F)*cos(m_angolob/180.0F*3.141592F));
    spotdir[1]=(1.0F * sin(m_angoloa/180.0F*3.141592F)*sin(m_angolob/180.0F*3.141592F));
    spotdir[2]=(1.0F * cos(m_angoloa/180.0F*3.141592F));
    spotdir[3]=1.0f;



    pos[0]=m_pos.GetX()+(spot_distance * sin(m_angoloa/180.0F*3.141592F)*cos(m_angolob/180.0F*3.141592F));
    pos[1]=m_pos.GetY()+(spot_distance * sin(m_angoloa/180.0F*3.141592F)*sin(m_angolob/180.0F*3.141592F));
    pos[2]=m_pos.GetZ()+(spot_distance * cos(m_angoloa/180.0F*3.141592F));

    m_pos2.SetX(pos[0]);
    m_pos2.SetY(pos[1]);
    m_pos2.SetZ(pos[2]);

    m_dis=sqrt(pow((m_pos.GetX()-m_pos2.GetX()),2)+
                                   pow((m_pos.GetY()-m_pos2.GetY()),2)+
                                   pow((m_pos.GetZ()-m_pos2.GetZ()),2));

    m_radius=m_dis*tan(spot_cutoff/180.0F*3.141592F);


    m_circle->create(64,m_radius);
    m_circle->SetWorldPos(m_pos2.GetX(),m_pos2.GetY(),m_pos2.GetZ());

}

/*void ligth::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code

                ar << this->m_nlight;

                ar << m_pos.GetX();
                ar << m_pos.GetY();
                ar << m_pos.GetZ();

                ar << ambient[0];
                ar << ambient[1];
                ar << ambient[2];
                ar << ambient[3];

                ar << diffuse[0];
                ar << diffuse[1];
                ar << diffuse[2];
                ar << diffuse[3];

                ar << specular[0];
                ar << specular[1];
                ar << specular[2];
                ar << specular[3];
        }
        else
        {	// loading code
                float appf;

                ar >> this->m_nlight;


                ar >> appf;
                m_pos.SetX(appf);
                ar >> appf;
                m_pos.SetY(appf);
                ar >> appf;
                m_pos.SetZ(appf);

                ar >> ambient[0];
                ar >> ambient[1];
                ar >> ambient[2];
                ar >> ambient[3];

                ar >> diffuse[0];
                ar >> diffuse[1];
                ar >> diffuse[2];
                ar >> diffuse[3];

                ar >> specular[0];
                ar >> specular[1];
                ar >> specular[2];
                ar >> specular[3];
        }
}
*/
