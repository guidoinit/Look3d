#include "action.h"

action::action()
: m_nAction(0)
, m_nObject(0)
{
        m_bhide=false;
        m_bkeyframe=false;
}

action::action(int no,int nf)
: m_nAction(0)
, m_nObject(0)
{

        m_nObject= no ;
        m_nframe = nf ;
        dirx=diry=dirz=false;
        m_bhide=false;
        m_bkeyframe=false;

}

void action::SetActionSposta(l3d_vertex_fast v)
{

        m_nAction=1;
        m_vsposta=v;

        m_fsposta[0]=v.x;
        m_fsposta[1]=v.y;
        m_fsposta[2]=v.z;

}
l3d_vertex_fast action::GetVertex()
{

        return( m_vsposta );




}
void action::SetActionHide(bool b)
{

        m_bhide=b;

        m_nAction=4;
}
void action::SetActionSposta(float v[3])
{

        m_nAction=1;

        m_fsposta[0]=v[0];
        m_fsposta[1]=v[1];
        m_fsposta[2]=v[2];

}

void action::SetActionRuota(float v[3] )
{

        m_nAction=2;

        m_rangolo[0]=v[0];

        m_rangolo[1]=v[1];

        m_rangolo[2]=v[2];

}

void action::SetActionScala(float v[3])
{

        m_nAction=3;

        m_fscala[0] = v[0];

        m_fscala[1] = v[1];

        m_fscala[2] = v[2];


}

action::~action()
{

}


// funzioni membro action

void action::SetAction(int na, l3d_vertex_fast v,float sposta[],float ruota[])
{


}

bool action::GetHide()
{
        return m_bhide;
}
int action::GetAction()
{

        return(m_nAction);

}

int action::GetSpostaVal()
{

        return(q);

}
float action::GetScaleVal()
{

        return(fq);

}
int action::GetSpostaDir()
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

int action::SetScale(char dir, float q)

{

        m_nAction=2;

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
int action::SetRotate(char dir, float q)
{

        m_nAction=3;

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

bool action::IsKey()
{
        return m_bkeyframe;
}
int action::SetSposta(char dir, int q)
{
        m_nAction=1;
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

void action::KeyFrame()
{
        m_bkeyframe=true;
}

/*void action::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code
                ar << m_nAction;
                ar << m_nObject;
                ar << m_nframe;

                ar << m_vsposta.GetX();
                ar << m_vsposta.GetY();
                ar << m_vsposta.GetZ();

                ar << m_rangolo[0];

                ar << m_rangolo[1];

                ar << m_rangolo[2];

                ar << m_fscala[0];

                ar << m_fscala[1];

                ar << m_fscala[2];

                ar << m_fsposta[0];

                ar << m_fsposta[1];

                ar << m_fsposta[2];

                ar << m_bkeyframe;
        }

        else

        {	// loading code
                float appf;

                ar >> m_nAction;
                ar >> m_nObject;
                ar >> m_nframe;

                ar >> appf;
                m_vsposta.SetX(appf);

                ar >> appf;
                m_vsposta.SetY(appf);

                ar >> appf;
                m_vsposta.SetZ(appf);

                ar >> m_rangolo[0];

                ar >> m_rangolo[1];

                ar >> m_rangolo[2];

                ar >> m_fscala[0];

                ar >> m_fscala[1];

                ar >> m_fscala[2];

                ar >> m_fsposta[0];

                ar >> m_fsposta[1];

                ar >> m_fsposta[2];

                ar >> m_bkeyframe;
        }

}
*/

float* action::GetAngoli()
{
        return (m_rangolo);
}
float* action::GetScale()
{
        return (m_fscala);
}
