
#include "baseframe.h"
#include "locx.h"
#include "locy.h"
#include "locz.h"


#include "keyframe.h"

void keyframe::setobject(int io)
{
        m_iobject=io;
}
int keyframe::getobject()
{
        return(m_iobject);
}
void  keyframe::settype(KEYFRAME::KeyFrameType type)
{
        _type=type;
}
keyframe::keyframe()
{
        m_nframe=-1;
        m_iobject=-1;

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
keyframe::keyframe(KEYFRAME::KeyFrameType type,int nframe_start,int nframe_end)
{

        m_nframe=-1;
        m_iobject=-1;

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
        m_nframe=nframe_end;
        m_nframestart=nframe_start;
}

keyframe::keyframe(KEYFRAME::KeyFrameType type,int nframe_start,int nframe_end,locx *loc)

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
        m_nframe=nframe_end;
        m_nframestart=nframe_start;

        _locx=loc;
        _locx->setstart(nframe_start);
        _locx->setend(nframe_end);

}
keyframe::keyframe(KEYFRAME::KeyFrameType type,int nframe_start,int nframe_end,locy *loc)
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
        m_nframe=nframe_end;
        m_nframestart=nframe_start;

        _locy=loc;
        _locy->setstart(nframe_start);
        _locy->setend(nframe_end);
}
keyframe::keyframe(KEYFRAME::KeyFrameType type,int nframe_start,int nframe_end,locz *loc)
{
        _type=type;
        m_nframe=nframe_end;
        m_nframestart=nframe_start;

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
KEYFRAME::KeyFrameType keyframe::gettype()
{
        return _type;
}
//move action
void keyframe::setlocx(float val)
{
        if(_locx==NULL)
                _locx=new locx();
        _locx->set(val);
}
void keyframe::setlocy(float val)
{
        if(_locy != NULL)
                delete(_locy);
        _locy->set(val);

}
void keyframe::setlocz(float val)
{
        if(_locz != NULL)
                delete(_locz);
        _locz->set(val);

}
void keyframe::setloc(locx *loc)
{
        if(_locx != NULL)
                delete(_locx);
        _locx=loc;

}

locx * keyframe::getlocx()
{
        return _locx;
}
locy * keyframe::getlocy()
{
        return _locy;
}
locz * keyframe::getlocz()
{
        return _locz;
}
void keyframe::setloc(locy *loc)
{
        if(_locy != NULL)
                delete(_locy);
        _locy=loc;
}

void keyframe::setloc(locz *loc)
{
        if(_locz != NULL)
                delete(_locz);
        _locz=loc;
}

void keyframe::setdlocx(float val)
{
        if(_dlocx != NULL)
                delete(_dlocx);
        _dlocx->set(val);
}
void keyframe::setdlocy(float val)
{
        if(_dlocy != NULL)
                delete(_dlocy);
        _dlocy->set(val);

}
void keyframe::setdlocz(float val)
{
        if(_dlocz != NULL)
                delete(_dlocz);

        _dlocz->set(val);

}
void keyframe::setdloc(locx *loc)
{
        if(_dlocx != NULL)
                delete(_dlocx);

        _dlocx=loc;

}
locx * keyframe::getdlocx()
{
        return _dlocx;
}
locy * keyframe::getdlocy()
{
        return _dlocy;
}
locz * keyframe::getdlocz()
{
        return _dlocz;
}
void keyframe::setdloc(locy *loc)
{
        if(_dlocy != NULL)
                delete(_dlocy);
        _dlocy=loc;
}

void keyframe::setdloc(locz *loc)
{
        if(_dlocz != NULL)
                delete(_dlocz);
        _dlocz=loc;
}
//scale action
void keyframe::setslocx(float val)
{
        if(_slocx==NULL)
                _slocx=new locx();
        _slocx->set(val);
}
void keyframe::setslocy(float val)
{
        if(_slocy != NULL)
                delete(_slocy);
        _slocy->set(val);

}
void keyframe::setslocz(float val)
{
        if(_slocz != NULL)
                delete(_slocz);
        _slocz->set(val);

}
void keyframe::setsloc(locx *loc)
{
        if(_slocx != NULL)
                delete(_slocx);
        _slocx=loc;

}

locx * keyframe::getslocx()
{
        return _slocx;
}
locy * keyframe::getslocy()
{
        return _slocy;
}
locz * keyframe::getslocz()
{
        return _slocz;
}
void keyframe::setsloc(locy *loc)
{
        if(_slocy != NULL)
                delete(_slocy);
        _slocy=loc;
}

void keyframe::setsloc(locz *loc)
{
        if(_slocz != NULL)
                delete(_slocz);
        _slocz=loc;
}

void keyframe::setsdlocx(float val)
{
        if(_sdlocx == NULL)
                _sdlocx= new locx();
        _sdlocx->set(val);
}
void keyframe::setsdlocy(float val)
{
        if(_dlocy == NULL)
                _sdlocy= new locy();
        _sdlocy->set(val);

}
void keyframe::setsdlocz(float val)
{
        if(_sdlocz == NULL)
                _sdlocz= new locz();

        _sdlocz->set(val);

}
void keyframe::setsdloc(locx *loc)
{
        if(_sdlocx != NULL)
                delete(_dlocx);

        _sdlocx=loc;

}
locx * keyframe::getsdlocx()
{
        return _sdlocx;
}
locy * keyframe::getsdlocy()
{
        return _sdlocy;
}
locz * keyframe::getsdlocz()
{
        return _sdlocz;
}
void keyframe::setsdloc(locy *loc)
{
        if(_sdlocy != NULL)
                delete(_sdlocy);
        _sdlocy=loc;
}

void keyframe::setsdloc(locz *loc)
{
        if(_sdlocz != NULL)
                delete(_sdlocz);
        _sdlocz=loc;
}

//rotate action

void keyframe::setrlocx(float val)
{
        if(_rlocx==NULL)
                _rlocx=new locx();
        _rlocx->set(val);
}
void keyframe::setrlocy(float val)
{
        if(_rlocy != NULL)
                delete(_rlocy);
        _rlocy->set(val);

}
void keyframe::setrlocz(float val)
{
        if(_rlocz != NULL)
                delete(_rlocz);
        _rlocz->set(val);

}
void keyframe::setrloc(locx *loc)
{
        if(_rlocx != NULL)
                delete(_rlocx);
        _rlocx=loc;

}

locx * keyframe::getrlocx()
{
        return _rlocx;
}
locy * keyframe::getrlocy()
{
        return _rlocy;
}
locz * keyframe::getrlocz()
{
        return _rlocz;
}
void keyframe::setrloc(locy *loc)
{
        if(_rlocy != NULL)
                delete(_rlocy);
        _rlocy=loc;
}

void keyframe::setrloc(locz *loc)
{
        if(_rlocz != NULL)
                delete(_rlocz);
        _rlocz=loc;
}

void keyframe::setrdlocx(float val)
{
        if(_rdlocx == NULL)
                _rdlocx= new locx();
        _rdlocx->set(val);
}
void keyframe::setrdlocy(float val)
{
        if(_rdlocy == NULL)
                _rdlocy= new locy();
        _rdlocy->set(val);

}
void keyframe::setrdlocz(float val)
{
        if(_rdlocz == NULL)
                _rdlocz= new locz();

        _rdlocz->set(val);

}
void keyframe::setrdloc(locx *loc)
{
        if(_rdlocx != NULL)
                delete(_rdlocx);

        _rdlocx=loc;

}
locx * keyframe::getrdlocx()
{
        return _rdlocx;
}
locy * keyframe::getrdlocy()
{
        return _rdlocy;
}
locz * keyframe::getrdlocz()
{
        return _rdlocz;
}
void keyframe::setrdloc(locy *loc)
{
        if(_rdlocy != NULL)
                delete(_rdlocy);
        _rdlocy=loc;
}

void keyframe::setrdloc(locz *loc)
{
        if(_rdlocz != NULL)
                delete(_rdlocz);
        _rdlocz=loc;
}


keyframe::~keyframe(void)
{
        //delete(_locx);
        //delete(_locy);
        //delete(_locz);
        //delete(_dlocx);
        //delete(_dlocy);
        //delete(_dlocz);
}

void keyframe::SetnFrame(int start, int end)
{
        m_nframe=end;
        m_nframestart=start;

}

/*void keyframe::SetAction(action naction)
{
        //m_action=naction;
}

action keyframe::GetAction()
{
       // return m_action;
}
*/
int keyframe::GetNumFrame()
{
        return m_nframe;
}

int keyframe::GetfirstFrame()
{
        return m_nframestart;
}
/*
void keyframe::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {
                ar << m_nframestart;
                ar << m_nframe;
                ar << _type;

                ar << m_iobject;

                ar  << (_locx!=NULL);
                if(_locx!=NULL)
                        _locx->Serialize(ar);

                ar  << (_locy!=NULL);
                if(_locy!=NULL)
                        _locy->Serialize(ar);

                ar  << (_locz!=NULL);
                if(_locz!=NULL)
                        _locz->Serialize(ar);

                ar  << (_dlocx!=NULL);
                if(_dlocx!=NULL)
                        _dlocx->Serialize(ar);
                ar  << (_dlocy!=NULL);
                if(_dlocy!=NULL)
                        _dlocy->Serialize(ar);

                ar  << (_dlocz!=NULL);
                if(_dlocz!=NULL)
                        _dlocz->Serialize(ar);

                ar  << (_slocx!=NULL);
                if(_slocx!=NULL)
                        _slocx->Serialize(ar);

                ar  << (_slocy!=NULL);
                if(_slocy!=NULL)
                        _slocy->Serialize(ar);
                ar  << (_slocz!=NULL);
                if(_slocz!=NULL)
                        _slocz->Serialize(ar);

                ar  << (_sdlocx!=NULL);
                if(_sdlocx!=NULL)
                        _sdlocx->Serialize(ar);

                ar  << (_sdlocy!=NULL);
                if(_sdlocy!=NULL)
                        _sdlocy->Serialize(ar);

                ar  << (_sdlocz!=NULL);
                if(_sdlocz!=NULL)
                        _sdlocz->Serialize(ar);

                ar  << (_rlocx!=NULL);
                if(_rlocx!=NULL)
                        _rlocx->Serialize(ar);

                ar  << (_rlocy!=NULL);
                if(_rlocy!=NULL)
                        _rlocy->Serialize(ar);

                ar  << (_rlocz!=NULL);
                if(_rlocz!=NULL)
                        _rlocz->Serialize(ar);

                ar  << (_rdlocx!=NULL);
                if(_rdlocx!=NULL)
                        _rdlocx->Serialize(ar);

                ar  << (_rdlocy!=NULL);
                if(_rdlocy!=NULL)
                        _rdlocy->Serialize(ar);

                ar  << (_rdlocz!=NULL);
                if(_rdlocz!=NULL)
                        _rdlocz->Serialize(ar);



        }
        else
        {
                int apps;
                ar >> m_nframestart;
                ar >> m_nframe;
                ar >> apps;

                ar >> m_iobject;
                _type=(KeyFrameType)apps;

                //_type; to-do impostare _type
                bool pr;
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

                ar  >> pr;
                locx *nlocx= new locx();
                locy *nlocy= new locy();
                locz *nlocz= new locz();

                locx *ndlocx= new locx();
                locy *ndlocy= new locy();
                locz *ndlocz= new locz();

                locx *nslocx= new locx();
                locy *nslocy= new locy();
                locz *nslocz= new locz();

                locx *nsdlocx= new locx();
                locy *nsdlocy= new locy();
                locz *nsdlocz= new locz();

                locx *nrlocx= new locx();
                locy *nrlocy= new locy();
                locz *nrlocz= new locz();

                locx *nrdlocx= new locx();
                locy *nrdlocy= new locy();
                locz *nrdlocz= new locz();

                if(pr)
                {
                        nlocx->Serialize(ar);
                        _locx=nlocx;
                }

                ar  >> pr;
                if(pr)
                {
                        nlocy->Serialize(ar);
                        _locy=nlocy;

                }

                ar  >> pr;
                if(pr)
                {
                        nlocz->Serialize(ar);
                        _locz=nlocz;
                }

                ar  >> pr;
                if(pr)
                {
                        ndlocx->Serialize(ar);
                        _dlocx=ndlocx;
                }

                ar  >> pr;
                if(pr)
                {
                        ndlocy->Serialize(ar);
                        _dlocy=ndlocy;
                }

                ar  >> pr;
                if(pr)
                {
                        ndlocz->Serialize(ar);
                        _dlocz=ndlocz;

                }

                ar  >> pr;
                if(pr)
                {
                        nslocx->Serialize(ar);
                        _slocx=nslocx;
                }

                ar  >> pr;
                if(pr)
                {
                        nslocy->Serialize(ar);
                        _slocy=nslocy;

                }

                ar  >> pr;
                if(pr)
                {
                        nslocz->Serialize(ar);
                        _slocz=nslocz;

                }
                ar  >> pr;
                if(pr)
                {
                        nsdlocx->Serialize(ar);
                        _sdlocx=nsdlocx;
                }

                ar  >> pr;
                if(pr)
                {
                        nsdlocy->Serialize(ar);
                        _sdlocy=nsdlocy;

                }

                ar  >> pr;
                if(pr)
                {
                        nsdlocz->Serialize(ar);
                        _sdlocz=nsdlocz;

                }

                ar  >> pr;
                if(pr)
                {
                        nrlocx->Serialize(ar);
                        _rlocx=nrlocx;
                }

                ar  >> pr;
                if(pr)
                {
                        nrlocy->Serialize(ar);
                        _rlocy=nrlocy;

                }

                ar  >> pr;
                if(pr)
                {
                        nrlocz->Serialize(ar);
                        _rlocz=nrlocz;

                }
                ar  >> pr;
                if(pr)
                {
                        nrdlocx->Serialize(ar);
                        _rdlocx=nrdlocx;
                }

                ar  >> pr;
                if(pr)
                {
                        nrdlocy->Serialize(ar);
                        _rdlocy=nrdlocy;

                }

                ar  >> pr;
                if(pr)
                {
                        nrdlocz->Serialize(ar);
                        _rdlocz=nrdlocz;

                }


        }
}
*/
