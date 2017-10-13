#ifndef MESHKEYFRAME_H
#define MESHKEYFRAME_H
#include "actionvertex.h"
#include "locx_vertex.h"
#include "locy_vertex.h"
#include "locz_vertex.h"



namespace KEYFRAMEMESH
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
class meshkeyframe
{
public:
    meshkeyframe();
    ~meshkeyframe();
    meshkeyframe(actionvertex*,int,int,int );

    meshkeyframe(KEYFRAMEMESH::KeyFrameType keyframetype,int nframe_start, int nframe_end);
    meshkeyframe(KEYFRAMEMESH::KeyFrameType keyframetype,int nframe_start, int nframe_end,locx_vertex * loc);
    meshkeyframe(KEYFRAMEMESH::KeyFrameType keyframetype,int nframe_start, int nframe_end,locy_vertex * loc);
    meshkeyframe(KEYFRAMEMESH::KeyFrameType keyframetype,int nframe_start, int nframe_end,locz_vertex * loc);
    meshkeyframe( const meshkeyframe &frm )
{

            _type=frm._type;

            _start=frm._start;
            _end=frm._end;
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

            _action=frm._action;




    }
meshkeyframe& operator=( const meshkeyframe &frm )
{



            _type=frm._type;


            _start=frm._start;
            _end=frm._end;
            _nframe=_end-_start;

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

            _action=frm._action;


            return *this;
    }
    bool operator>( const meshkeyframe &frm )
    {

            if(_nframe>frm._nframe)
                    return true;


            return false;
    }

    void settype(KEYFRAMEMESH::KeyFrameType type);

    KEYFRAMEMESH::KeyFrameType gettype();
    void setobject(int io);
    int getobject();

    //move action
    void setloc(locx_vertex *loc);
    void setloc(locy_vertex *loc);
    void setloc(locz_vertex *loc);
    void setlocx(float val);
    void setlocy(float val);
    void setlocz(float val);

    void setdloc(locx_vertex *loc);
    void setdloc(locy_vertex *loc);
    void setdloc(locz_vertex *loc);
    void setdlocx(float val);
    void setdlocy(float val);
    void setdlocz(float val);

    locx_vertex * getlocx();
    locy_vertex * getlocy();
    locz_vertex * getlocz();

    locx_vertex * getdlocx();
    locy_vertex * getdlocy();
    locz_vertex * getdlocz();


    //scale action
    void setsloc(locx_vertex *loc);
    void setsloc(locy_vertex *loc);
    void setsloc(locz_vertex *loc);
    void setslocx(float val);
    void setslocy(float val);
    void setslocz(float val);

    void setsdloc(locx_vertex *loc);
    void setsdloc(locy_vertex *loc);
    void setsdloc(locz_vertex *loc);
    void setsdlocx(float val);
    void setsdlocy(float val);
    void setsdlocz(float val);

    locx_vertex * getslocx();
    locy_vertex * getslocy();
    locz_vertex * getslocz();

    locx_vertex * getsdlocx();
    locy_vertex * getsdlocy();
    locz_vertex * getsdlocz();

    //rotate action
    void setrloc(locx_vertex *loc);
    void setrloc(locy_vertex *loc);
    void setrloc(locz_vertex *loc);
    void setrlocx(float val);
    void setrlocy(float val);
    void setrlocz(float val);

    void setrdloc(locx_vertex *loc);
    void setrdloc(locy_vertex *loc);
    void setrdloc(locz_vertex *loc);
    void setrdlocx(float val);
    void setrdlocy(float val);
    void setrdlocz(float val);

    locx_vertex * getrlocx();
    locy_vertex * getrlocy();
    locz_vertex * getrlocz();

    locx_vertex * getrdlocx();
    locy_vertex * getrdlocy();
    locz_vertex * getrdlocz();



    void SetAction(actionvertex* vaction);
    void SetnFrame(int start, int end);
    actionvertex*GetAction();
    int GetNumFrame();
    int GetfirstFrame();

private:
    KEYFRAMEMESH::KeyFrameType _type;
    actionvertex* _action;
    int _start;
    int _end;
    int _nframe;
    int _idanimation;

    //move
    locx_vertex * _locx;
    locy_vertex * _locy;
    locz_vertex * _locz;

    locx_vertex * _dlocx;
    locy_vertex * _dlocy;
    locz_vertex * _dlocz;

    //scale

    locx_vertex * _slocx;
    locy_vertex * _slocy;
    locz_vertex * _slocz;

    locx_vertex * _sdlocx;
    locy_vertex * _sdlocy;
    locz_vertex * _sdlocz;

    //rotate

    locx_vertex * _rlocx;
    locy_vertex * _rlocy;
    locz_vertex * _rlocz;

    locx_vertex * _rdlocx;
    locy_vertex * _rdlocy;
    locz_vertex * _rdlocz;


};

#endif // MESHKEYFRAME_H
