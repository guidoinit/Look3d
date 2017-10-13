#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_line.h"
#include "l3d_face3.h"
#include "l3d_face4.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;

l3d_face4::l3d_face4()
{
    _first=NULL;
    _last=NULL;
    _nfaces=0;
}

l3d_face4::l3d_face4(pl3d_face4_struct faces,l3d_uint nfaces)
{
    //si assume che nfaces corrisponde al numero di facce da aggiungere
    _first=faces;
    _nfaces+=nfaces;

}

void l3d_face4::add(pl3d_face4_struct face)
{
    pl3d_face4_struct nf=new l3d_face4_struct;

    *nf=*face;
    if(_first==l3d_null && _last==l3d_null && _nfaces==0)
    {

        _first=nf;
        _first->next=l3d_null;
        _first->prev=l3d_null;
        _last=_first;


    }
    else
    {

        _last->next=nf;
        nf->prev=_last;
        nf->next=l3d_null;
        _last=nf;



    }
    _nfaces++;
}
l3d_bool l3d_face4::isfirst()
{
    return(_first==NULL && _last==NULL && _nfaces==0);
}

void l3d_face4::del(l3d_uint index)
{
    if(isfirst())
        return;
    else
    {
        pl3d_face4_struct vf=find(index),plast=_last;


        if(vf != NULL)
        {
            if(vf == _last)
            {
                plast->prev->next=NULL;
                _last=plast->prev;
                plast->purge();
                delete plast;
            }
            else if(_first ==_last && _nfaces==1)
            {
                _first->purge();
                delete(_first);

                _first= NULL;
                _last = NULL;

            }
            else
            {

                vf->prev->next=vf->next;
                vf->purge();
                delete (vf);
            }

            _nfaces--;

        }
    }

}
pl3d_face4_struct l3d_face4::first()
{
    return _first;

}

pl3d_face4_struct l3d_face4::find(l3d_uint index)
{
    int ix=0;

    if(index < 0 || index > _nfaces)
        return l3d_null;

    pl3d_face4_struct pfirst=_first;

    while(  pfirst && ix++ < index)
        pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return l3d_null;

}
int l3d_face4::size()
{
    return _nfaces;
}

void l3d_face4::clear()
{
    pl3d_face4_struct pf=_last;

    while(_last)
    {
        pf->_pv0=NULL;
        pf->_pv1=NULL;
        pf->_pv2=NULL;
        pf->_pv3=NULL;

        pf->_l0=NULL;
        pf->_l1=NULL;
        pf->_l2=NULL;
        pf->_l3=NULL;

        pf->_f0=NULL;
        pf->_f1=NULL;

        _last=_last->prev;

        delete(pf);

        pf=_last;
    }

    _first=NULL;
    _last=NULL;
    _nfaces=0;



}

