#include "vertex.h"
#include "poligon4.h"


// poligon4

poligon4::poligon4()
{
        lista_vertici[0]=-1;
        lista_vertici[1]=-1;
        lista_vertici[2]=-1;
        lista_vertici[3]=-1;

        //coordinate uv

        m_iu[0]=0.0F;
        m_iv[0]=0.0F;

        m_iu[1]=0.0F;
        m_iv[1]=1.0F;

        m_iu[2]=1.0F;
        m_iv[2]=0.0F;

        m_iu[3]=1.0F;
        m_iv[3]=1.0F;

        m_bselected=false;
        m_berase=false;
        m_btorem=false;
}
poligon4::poligon4(int v1,int v2,int v3,int v4)
{
        lista_vertici[0]=v1;
        lista_vertici[1]=v2;
        lista_vertici[2]=v3;
        lista_vertici[3]=v4;

        m_iu[0]=0.0F;
        m_iv[0]=0.0F;

        m_iu[1]=0.0F;
        m_iv[1]=1.0F;

        m_iu[2]=1.0F;
        m_iv[2]=0.0F;

        m_iu[3]=1.0F;
        m_iv[3]=1.0F;
        m_bselected=false;
        m_berase=false;
        m_btorem=false;
}
poligon4::poligon4(int v1,int v2,int v3,int v4,float u[4],float v[4])
{
        lista_vertici[0]=v1;
        lista_vertici[1]=v2;
        lista_vertici[2]=v3;
        lista_vertici[3]=v4;

        for(int ix=0; ix < 4; ix++)
        {
            m_iu[ix]=u[ix];
            m_iv[ix]=v[ix];


        }

        m_bselected=false;
        m_btorem=false;
        m_berase=false;
}
void poligon4::Set(float u[4],float v[4])
{
    for(int ix=0; ix < 4; ix++)
    {
        m_iu[ix]=u[ix];
        m_iv[ix]=v[ix];


    }


}
void poligon4::setline(int v1,int v2,int v3,int v4)
{
    lista_line[0]=v1;
    lista_line[1]=v2;
    lista_line[2]=v3;
    lista_line[3]=v4;
}
int poligon4::getline(int il)
{
    if(il >=0 && il <4)
        return(lista_line[il]);
    else
        return(-1);
}

void poligon4::Set(int v1,int v2,int v3,int v4)
{
        lista_vertici[0]=v1;
        lista_vertici[1]=v2;
        lista_vertici[2]=v3;
        lista_vertici[3]=v4;


        m_iu[0]=0.0F;
        m_iv[0]=0.0F;

        m_iu[1]=0.0F;
        m_iv[1]=1.0F;

        m_iu[2]=1.0F;
        m_iv[2]=0.0F;

        m_iu[3]=1.0F;
        m_iv[3]=1.0F;

        m_bselected=false;
}
poligon4::~poligon4()
{
}
/*
void poligon4::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code
                ar << lista_vertici[0];
                ar << lista_vertici[1];
                ar << lista_vertici[2];
                ar << lista_vertici[3];
        }
        else
        {	// loading code
                ar >> lista_vertici[0];
                ar >> lista_vertici[1];
                ar >> lista_vertici[2];
                ar >> lista_vertici[3];
        }
}
*/
// poligon4 member functions


int poligon4::Get(int n)
{
        if(n>=0 && n<4)
                return lista_vertici[n];
        return -1;
}
void poligon4::SetName(int n)
{
        name=n;
}
int poligon4::GetName()
{
        return name;
}
void poligon4::SetSelected(bool sel)
{
        m_bselected=sel;
}
bool poligon4::IsSelected()
{
        return m_bselected;
}
void poligon4::selected(bool sel)
{
        m_bselected=sel;
}
bool poligon4::selected()
{
        return m_bselected;
}


bool poligon4::Present(int v)
{
        if(lista_vertici[0]==v || lista_vertici[1]==v || lista_vertici[2]==v || lista_vertici[3]==v )
                return true;
        return false;
}
void poligon4::invertdraw()
{
    int appv,appv1;

    appv=lista_vertici[2];
    appv1=lista_vertici[1];

    lista_vertici[2]=appv1;
    lista_vertici[1]=appv;

    //appv=lista_vertici[2];
    //appv1=lista_vertici[3];

    //lista_vertici[0]=appv1;
    //lista_vertici[1]=appv;




}
void poligon4::settriangles(int t1, int t2)
{
    m_itriangles[0]=t1;
    m_itriangles[1]=t2;
}
int poligon4::gettriangle(int value)
{
    if (value <0 || value >= 2)
        return -1;
    else
        return m_itriangles[value];

}
void poligon4::clearlist()
{
    m_sin.clear();
    m_des.clear();
    m_up.clear();
    m_down.clear();
}
void poligon4::addup(int v)
{
    m_up.push_back(v);
}

void poligon4::adddown(int v)
{
    m_down.push_back(v);
}

void poligon4::addsin(int v)
{
    m_sin.push_back(v);
}

void poligon4::adddes(int v)
{
    m_des.push_back(v);
}
void poligon4::torem(bool rm)
{
    m_btorem=rm;
}

bool poligon4::torem()
{
    return(m_btorem);
}
