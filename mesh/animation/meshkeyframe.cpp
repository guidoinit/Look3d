#include "meshkeyframe.h"




meshkeyframe::meshkeyframe(actionvertex* action,int start,int end,int idani)
{

    _action=action;
    _start=start;
    _end=end;
    _idanimation=idani;

}
void  meshkeyframe::settype(KEYFRAMEMESH::KeyFrameType type)
{
        _type=type;
        meshkeyframe();
}
meshkeyframe::meshkeyframe()
{
       // m_nframe=-1;
       // m_iobject=-1;

        _start=_end=-1;
        _action=NULL;

        _locx=NULL;
        _locy=NULL;
        _locz=NULL;
        _dlocx=NULL;
        _dlocy=NULL;
        _dlocz=NULL;

        _slocx=NULL;
        _slocy=NULL;
        _slocz=NULL;
        _sdlocx=NULL;
        _sdlocy=NULL;
        _sdlocz=NULL;

        _rlocx=NULL;
        _rlocy=NULL;
        _rlocz=NULL;
        _rdlocx=NULL;
        _rdlocy=NULL;
        _rdlocz=NULL;

}
meshkeyframe::meshkeyframe(KEYFRAMEMESH::KeyFrameType type,int nframe_start,int nframe_end)
{

        //m_nframe=-1;
        ///m_iobject=-1;

        _locx=NULL;
        _locy=NULL;
        _locz=NULL;
        _dlocx=NULL;
        _dlocy=NULL;
        _dlocz=NULL;

        _slocx=NULL;
        _slocy=NULL;
        _slocz=NULL;
        _sdlocx=NULL;
        _sdlocy=NULL;
        _sdlocz=NULL;

        _rlocx=NULL;
        _rlocy=NULL;
        _rlocz=NULL;
        _rdlocx=NULL;
        _rdlocy=NULL;
        _rdlocz=NULL;

        _type=type;
        _end=nframe_end;
        _start=nframe_start;
        _nframe=_end-_start;
}

meshkeyframe::meshkeyframe(KEYFRAMEMESH::KeyFrameType type,int nframe_start,int nframe_end,locx_vertex *loc)

{

        _locx=NULL;
        _locy=NULL;
        _locz=NULL;
        _dlocx=NULL;
        _dlocy=NULL;
        _dlocz=NULL;

        _slocx=NULL;
        _slocy=NULL;
        _slocz=NULL;
        _sdlocx=NULL;
        _sdlocy=NULL;
        _sdlocz=NULL;

        _rlocx=NULL;
        _rlocy=NULL;
        _rlocz=NULL;
        _rdlocx=NULL;
        _rdlocy=NULL;
        _rdlocz=NULL;

        _type=type;
        _end=nframe_end;
        _start=nframe_start;
        _nframe=_end-_start;

        _locx=loc;
        _locx->setstart(nframe_start);
        _locx->setend(nframe_end);

}
meshkeyframe::meshkeyframe(KEYFRAMEMESH::KeyFrameType type,int nframe_start,int nframe_end,locy_vertex *loc)
{
        _locx=NULL;
        _locy=NULL;
        _locz=NULL;
        _dlocx=NULL;
        _dlocy=NULL;
        _dlocz=NULL;

        _slocx=NULL;
        _slocy=NULL;
        _slocz=NULL;
        _sdlocx=NULL;
        _sdlocy=NULL;
        _sdlocz=NULL;

        _rlocx=NULL;
        _rlocy=NULL;
        _rlocz=NULL;
        _rdlocx=NULL;
        _rdlocy=NULL;
        _rdlocz=NULL;

        _type=type;
        _end=nframe_end;
        _start=nframe_start;
        _nframe=_end-_start;

        _locy=loc;
        _locy->setstart(nframe_start);
        _locy->setend(nframe_end);
}
meshkeyframe::meshkeyframe(KEYFRAMEMESH::KeyFrameType type,int nframe_start,int nframe_end,locz_vertex *loc)
{
        _type=type;
        _end=nframe_end;
        _start=nframe_start;
        _nframe=_end-_start;

        _locx=NULL;
        _locy=NULL;
        _locz=NULL;
        _dlocx=NULL;
        _dlocy=NULL;
        _dlocz=NULL;

        _slocx=NULL;
        _slocy=NULL;
        _slocz=NULL;
        _sdlocx=NULL;
        _sdlocy=NULL;
        _sdlocz=NULL;

        _rlocx=NULL;
        _rlocy=NULL;
        _rlocz=NULL;
        _rdlocx=NULL;
        _rdlocy=NULL;
        _rdlocz=NULL;

        _locz=loc;
        _locz->setstart(nframe_start);
        _locz->setend(nframe_end);
}
KEYFRAMEMESH::KeyFrameType meshkeyframe::gettype()
{
        return _type;
}
//move action
void meshkeyframe::setlocx(float val)
{
        if(_locx==NULL)
                _locx=new locx_vertex();
        _locx->set(val);
}
void meshkeyframe::setlocy(float val)
{
        if(_locy != NULL)
                delete(_locy);
        _locy->set(val);

}
void meshkeyframe::setlocz(float val)
{
        if(_locz != NULL)
                delete(_locz);
        _locz->set(val);

}
void meshkeyframe::setloc(locx_vertex *loc)
{
        if(_locx != NULL)
                delete(_locx);
        _locx=loc;

}

locx_vertex * meshkeyframe::getlocx()
{
        return _locx;
}
locy_vertex * meshkeyframe::getlocy()
{
        return _locy;
}
locz_vertex * meshkeyframe::getlocz()
{
        return _locz;
}
void meshkeyframe::setloc(locy_vertex *loc)
{
        if(_locy != NULL)
                delete(_locy);
        _locy=loc;
}

void meshkeyframe::setloc(locz_vertex *loc)
{
        if(_locz != NULL)
                delete(_locz);
        _locz=loc;
}

void meshkeyframe::setdlocx(float val)
{
        if(_dlocx != NULL)
                delete(_dlocx);
        _dlocx->set(val);
}
void meshkeyframe::setdlocy(float val)
{
        if(_dlocy != NULL)
                delete(_dlocy);
        _dlocy->set(val);

}
void meshkeyframe::setdlocz(float val)
{
        if(_dlocz != NULL)
                delete(_dlocz);

        _dlocz->set(val);

}
void meshkeyframe::setdloc(locx_vertex *loc)
{
        if(_dlocx != NULL)
                delete(_dlocx);

        _dlocx=loc;

}
locx_vertex * meshkeyframe::getdlocx()
{
        return _dlocx;
}
locy_vertex * meshkeyframe::getdlocy()
{
        return _dlocy;
}
locz_vertex * meshkeyframe::getdlocz()
{
        return _dlocz;
}
void meshkeyframe::setdloc(locy_vertex *loc)
{
        if(_dlocy != NULL)
                delete(_dlocy);
        _dlocy=loc;
}

void meshkeyframe::setdloc(locz_vertex *loc)
{
        if(_dlocz != NULL)
                delete(_dlocz);
        _dlocz=loc;
}
//scale action
void meshkeyframe::setslocx(float val)
{
        if(_slocx==NULL)
                _slocx=new locx_vertex();
        _slocx->set(val);
}
void meshkeyframe::setslocy(float val)
{
        if(_slocy != NULL)
                delete(_slocy);
        _slocy->set(val);

}
void meshkeyframe::setslocz(float val)
{
        if(_slocz != NULL)
                delete(_slocz);
        _slocz->set(val);

}
void meshkeyframe::setsloc(locx_vertex *loc)
{
        if(_slocx != NULL)
                delete(_slocx);
        _slocx=loc;

}

locx_vertex * meshkeyframe::getslocx()
{
        return _slocx;
}
locy_vertex * meshkeyframe::getslocy()
{
        return _slocy;
}
locz_vertex * meshkeyframe::getslocz()
{
        return _slocz;
}
void meshkeyframe::setsloc(locy_vertex *loc)
{
        if(_slocy != NULL)
                delete(_slocy);
        _slocy=loc;
}

void meshkeyframe::setsloc(locz_vertex *loc)
{
        if(_slocz != NULL)
                delete(_slocz);
        _slocz=loc;
}

void meshkeyframe::setsdlocx(float val)
{
        if(_sdlocx == NULL)
                _sdlocx= new locx_vertex();
        _sdlocx->set(val);
}
void meshkeyframe::setsdlocy(float val)
{
        if(_dlocy == NULL)
                _sdlocy= new locy_vertex();
        _sdlocy->set(val);

}
void meshkeyframe::setsdlocz(float val)
{
        if(_sdlocz == NULL)
                _sdlocz= new locz_vertex();

        _sdlocz->set(val);

}
void meshkeyframe::setsdloc(locx_vertex *loc)
{
        if(_sdlocx != NULL)
                delete(_dlocx);

        _sdlocx=loc;

}
locx_vertex * meshkeyframe::getsdlocx()
{
        return _sdlocx;
}
locy_vertex * meshkeyframe::getsdlocy()
{
        return _sdlocy;
}
locz_vertex * meshkeyframe::getsdlocz()
{
        return _sdlocz;
}
void meshkeyframe::setsdloc(locy_vertex *loc)
{
        if(_sdlocy != NULL)
                delete(_sdlocy);
        _sdlocy=loc;
}

void meshkeyframe::setsdloc(locz_vertex *loc)
{
        if(_sdlocz != NULL)
                delete(_sdlocz);
        _sdlocz=loc;
}

//rotate action

void meshkeyframe::setrlocx(float val)
{
        if(_rlocx==NULL)
                _rlocx=new locx_vertex();
        _rlocx->set(val);
}
void meshkeyframe::setrlocy(float val)
{
        if(_rlocy != NULL)
                delete(_rlocy);
        _rlocy->set(val);

}
void meshkeyframe::setrlocz(float val)
{
        if(_rlocz != NULL)
                delete(_rlocz);
        _rlocz->set(val);

}
void meshkeyframe::setrloc(locx_vertex *loc)
{
        if(_rlocx != NULL)
                delete(_rlocx);
        _rlocx=loc;

}

locx_vertex * meshkeyframe::getrlocx()
{
        return _rlocx;
}
locy_vertex * meshkeyframe::getrlocy()
{
        return _rlocy;
}
locz_vertex * meshkeyframe::getrlocz()
{
        return _rlocz;
}
void meshkeyframe::setrloc(locy_vertex *loc)
{
        if(_rlocy != NULL)
                delete(_rlocy);
        _rlocy=loc;
}

void meshkeyframe::setrloc(locz_vertex *loc)
{
        if(_rlocz != NULL)
                delete(_rlocz);
        _rlocz=loc;
}

void meshkeyframe::setrdlocx(float val)
{
        if(_rdlocx == NULL)
                _rdlocx= new locx_vertex();
        _rdlocx->set(val);
}
void meshkeyframe::setrdlocy(float val)
{
        if(_rdlocy == NULL)
                _rdlocy= new locy_vertex();
        _rdlocy->set(val);

}
void meshkeyframe::setrdlocz(float val)
{
        if(_rdlocz == NULL)
                _rdlocz= new locz_vertex();

        _rdlocz->set(val);

}
void meshkeyframe::setrdloc(locx_vertex *loc)
{
        if(_rdlocx != NULL)
                delete(_rdlocx);

        _rdlocx=loc;

}
locx_vertex * meshkeyframe::getrdlocx()
{
        return _rdlocx;
}
locy_vertex * meshkeyframe::getrdlocy()
{
        return _rdlocy;
}
locz_vertex * meshkeyframe::getrdlocz()
{
        return _rdlocz;
}
void meshkeyframe::setrdloc(locy_vertex *loc)
{
        if(_rdlocy != NULL)
                delete(_rdlocy);
        _rdlocy=loc;
}

void meshkeyframe::setrdloc(locz_vertex *loc)
{
        if(_rdlocz != NULL)
                delete(_rdlocz);
        _rdlocz=loc;
}


meshkeyframe::~meshkeyframe(void)
{
        //delete(_locx);
        //delete(_locy);
        //delete(_locz);
        //delete(_dlocx);
        //delete(_dlocy);
        //delete(_dlocz);
}

void meshkeyframe::SetnFrame(int start, int end)
{
        _end=end;
        _start=start;

}

void meshkeyframe::SetAction(actionvertex* naction)
{
        _action=naction;
}

actionvertex* meshkeyframe::GetAction()
{
        return _action;
}
int meshkeyframe::GetNumFrame()
{
        return (_end-_start);
}

int meshkeyframe::GetfirstFrame()
{
        return _start;
}
