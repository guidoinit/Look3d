
#ifndef KEYFRAME_H
#define KEYFRAME_H
#include <math.h>
#include <vector>



#include "frame.h"

#include "baseframe.h"
#include "locx.h"
#include "locy.h"
#include "locz.h"

#include "./mesh/action.h"

namespace KEYFRAME
{
    enum KeyFrameType
    {
        kf_movelocal=1,
        kf_moverelative=2,
        kf_scalelocal=3,
        kf_scalerelative=4,
        kf_rotatelocal=5,
        kf_rotaterelative=6
    };

}
class keyframe
{
private:
        KEYFRAME::KeyFrameType _type;
        //action m_action;
        int m_iobject;
        int m_nframe;
        int m_nframestart;

        //move
        locx * _locx;
        locy * _locy;
        locz * _locz;

        locx * _dlocx;
        locy * _dlocy;
        locz * _dlocz;

        //scale

        locx * _slocx;
        locy * _slocy;
        locz * _slocz;

        locx * _sdlocx;
        locy * _sdlocy;
        locz * _sdlocz;

        //rotate

        locx * _rlocx;
        locy * _rlocy;
        locz * _rlocz;

        locx * _rdlocx;
        locy * _rdlocy;
        locz * _rdlocz;



public:
        keyframe();
        keyframe(KEYFRAME::KeyFrameType keyframetype,int nframe_start, int nframe_end);
        keyframe(KEYFRAME::KeyFrameType keyframetype,int nframe_start, int nframe_end,locx * loc);
        keyframe(KEYFRAME::KeyFrameType keyframetype,int nframe_start, int nframe_end,locy * loc);
        keyframe(KEYFRAME::KeyFrameType keyframetype,int nframe_start, int nframe_end,locz * loc);
        ~keyframe(void);
        //virtual void Serialize(CArchive& ar);
        KEYFRAME::KeyFrameType gettype();
        void setobject(int io);
        int getobject();
        void settype(KEYFRAME::KeyFrameType type);
        //move action
        void setloc(locx *loc);
        void setloc(locy *loc);
        void setloc(locz *loc);
        void setlocx(float val);
        void setlocy(float val);
        void setlocz(float val);

        void setdloc(locx *loc);
        void setdloc(locy *loc);
        void setdloc(locz *loc);
        void setdlocx(float val);
        void setdlocy(float val);
        void setdlocz(float val);

        locx * getlocx();
        locy * getlocy();
        locz * getlocz();

        locx * getdlocx();
        locy * getdlocy();
        locz * getdlocz();


        //scale action
        void setsloc(locx *loc);
        void setsloc(locy *loc);
        void setsloc(locz *loc);
        void setslocx(float val);
        void setslocy(float val);
        void setslocz(float val);

        void setsdloc(locx *loc);
        void setsdloc(locy *loc);
        void setsdloc(locz *loc);
        void setsdlocx(float val);
        void setsdlocy(float val);
        void setsdlocz(float val);

        locx * getslocx();
        locy * getslocy();
        locz * getslocz();

        locx * getsdlocx();
        locy * getsdlocy();
        locz * getsdlocz();

        //rotate action
        void setrloc(locx *loc);
        void setrloc(locy *loc);
        void setrloc(locz *loc);
        void setrlocx(float val);
        void setrlocy(float val);
        void setrlocz(float val);

        void setrdloc(locx *loc);
        void setrdloc(locy *loc);
        void setrdloc(locz *loc);
        void setrdlocx(float val);
        void setrdlocy(float val);
        void setrdlocz(float val);

        locx * getrlocx();
        locy * getrlocy();
        locz * getrlocz();

        locx * getrdlocx();
        locy * getrdlocy();
        locz * getrdlocz();



        //void SetAction(action action);
        void SetnFrame(int start, int end);
        //action GetAction();
        int GetNumFrame();
        int GetfirstFrame();
        keyframe( const keyframe &frm )
    {

                _type=frm._type;
                m_iobject=frm.m_iobject;
                m_nframe=frm.m_nframe;
                m_nframestart=frm.m_nframestart;
                _locx=frm._locx;
                _locy=frm._locy;
                _locz=frm._locz;
                _dlocx=frm._dlocx;
                _dlocy=frm._dlocy;
                _dlocz=frm._dlocz;

                _slocx=frm._slocx;
                _slocy=frm._slocy;
                _slocz=frm._slocz;
                _sdlocx=frm._sdlocx;
                _sdlocy=frm._sdlocy;
                _sdlocz=frm._sdlocz;

                _rlocx=frm._rlocx;
                _rlocy=frm._rlocy;
                _rlocz=frm._rlocz;
                _rdlocx=frm._rdlocx;
                _rdlocy=frm._rdlocy;
                _rdlocz=frm._rdlocz;

                //m_action=frm.m_action;




        }
    keyframe& operator=( const keyframe &frm )
    {



                _type=frm._type;
                m_iobject=frm.m_iobject;
                m_nframe=frm.m_nframe;

                m_nframestart=frm.m_nframestart;

                _locx=frm._locx;
                _locy=frm._locy;
                _locz=frm._locz;
                _dlocx=frm._dlocx;
                _dlocy=frm._dlocy;
                _dlocz=frm._dlocz;

                _slocx=frm._slocx;
                _slocy=frm._slocy;
                _slocz=frm._slocz;
                _sdlocx=frm._sdlocx;
                _sdlocy=frm._sdlocy;
                _sdlocz=frm._sdlocz;

                _rlocx=frm._rlocx;
                _rlocy=frm._rlocy;
                _rlocz=frm._rlocz;
                _rdlocx=frm._rdlocx;
                _rdlocy=frm._rdlocy;
                _rdlocz=frm._rdlocz;

                //m_action=frm.m_action;


                return *this;
        }
        bool operator>( const keyframe &frm )
        {

                if(m_nframe>frm.m_nframe)
                        return true;


                return false;
        }
};



#endif // KEYFRAME_H
