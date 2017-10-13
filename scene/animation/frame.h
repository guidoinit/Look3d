#ifndef FRAME_H
#define FRAME_H


#include <vector>


#include "./mesh/action.h"

class frame
{
public:
        int m_nNumObj;

        std::vector <action> m_vaction;


        //void AddKeyFrame(CKeyFrame keyframe);

        frame();
        ~frame();
        frame( const frame &frm )
        {
                int x;



                m_nNumObj= frm.m_nNumObj;


                int nindex=frm.m_vaction.size();

                for(x=0; x < nindex ; x++)
                {
                        m_vaction.push_back(action());
                        m_vaction[x]=frm.m_vaction[x];


                }


        }
    frame& operator=( const frame &frm )
    {
                int x;



                m_nNumObj= frm.m_nNumObj;



                int nindex=frm.m_vaction.size();

                for(x=0; x < nindex ; x++)
                {
                        m_vaction.push_back(action());
                        m_vaction[x]=frm.m_vaction[x];


                }




                return *this;
        }

};

#endif // FRAME_H
