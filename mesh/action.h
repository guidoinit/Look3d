#ifndef ACTION_H
#define ACTION_H
#include <QOpenGLFunctions>

#include "l3d_vertex.h"

using namespace l3d::vertex3f;
class action
{

public:

        action();
        action(int,int);
        ~action();
        //definisce l'azione
        //1)	Spostamento
        //		vettore x,y,z
        //2)	Scala
        //		array di 3
        //3)	Rotazione
        //		array di tre float
        //4)	Hide/Unhide
        //		bool






        void SetAction(int , l3d_vertex_fast,float [],float [] );
        l3d_vertex_fast GetVertex();
        l3d_vertex_fast m_vsposta;
        int m_nObject;
        int m_nframe;
        float m_rangolo[3];
        float m_fsposta[3];
        float* GetAngoli();
        float* GetScale();
        action ( const action &obj )
        {
                m_vsposta=obj.m_vsposta;

                m_fsposta[0]=obj.m_fsposta[0];
                m_fsposta[1]=obj.m_fsposta[1];
                m_fsposta[2]=obj.m_fsposta[2];

                m_fscala[0]=obj.m_fscala[0];
                m_fscala[1]=obj.m_fscala[1];
                m_fscala[2]=obj.m_fscala[2];

                m_rangolo[0]=obj.m_rangolo[0];
                m_rangolo[1]=obj.m_rangolo[1];
                m_rangolo[2]=obj.m_rangolo[2];

                m_bhide=obj.m_bhide;
                m_nObject=obj.m_nObject;

                m_nframe=obj.m_nframe;

                m_nAction = obj.m_nAction;

                m_bkeyframe=obj.m_bkeyframe;


        }

        action& operator=( const action &obj )
    {
                m_vsposta=obj.m_vsposta;

                m_fsposta[0]=obj.m_fsposta[0];
                m_fsposta[1]=obj.m_fsposta[1];
                m_fsposta[2]=obj.m_fsposta[2];

                m_fscala[0]=obj.m_fscala[0];
                m_fscala[1]=obj.m_fscala[1];
                m_fscala[2]=obj.m_fscala[2];

                m_rangolo[0]=obj.m_rangolo[0];
                m_rangolo[1]=obj.m_rangolo[1];
                m_rangolo[2]=obj.m_rangolo[2];

                m_bhide=obj.m_bhide;
                m_nObject=obj.m_nObject;

                m_nframe=obj.m_nframe;
                m_nAction = obj.m_nAction;

                m_bkeyframe=obj.m_bkeyframe;

                return (*this);

        }

        void SetActionSposta(l3d_vertex_fast );

        void SetActionSposta(float[] );

        void SetActionRuota(float[] );

        void SetActionScala(float []);

        void SetActionHide(bool);

        int GetAction();

        int GetSpostaDir();

        int GetSpostaVal();

        float GetScaleVal();

        void KeyFrame();

        bool IsKey();

        int SetSposta(char dir, int q);
        int SetScale(char dir, float q);
        int SetRotate(char dir, float q);
        bool GetHide();

private:

        int m_nAction;

        bool dirx,diry,dirz;

        bool m_bhide;

        bool m_bkeyframe;

        int q;

        float fq;





        float m_fscala[3];



        //numero dell'oggetto a cui  riferita l'azione

};

#endif // ACTION_H
