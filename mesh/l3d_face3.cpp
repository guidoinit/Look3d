#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_line.h"

#include "l3d_face3.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;

l3d_face3::l3d_face3()
{
    _first=NULL;
    _last=NULL;
    _nfaces=0;

}

l3d_face3::l3d_face3(pl3d_face3_struct faces,l3d_uint nfaces)
{
    //si assume che nfaces corrisponde al numero di facce da aggiungere
    _first=faces;
    _nfaces+=nfaces;

}

void l3d_face3::add(pl3d_face3_struct face)
{

    pl3d_face3_struct nf= new l3d_face3_struct;

    *nf=*face;

    if(_first==NULL && _last==NULL && _nfaces==0)
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
        nf->next=NULL;
        _last=nf;



    }
    _nfaces++;
}
l3d_bool l3d_face3::isfirst()
{
    return(_first==NULL && _last==NULL && _nfaces==0);
}

void l3d_face3::del(l3d_uint index)
{
    if(isfirst())
        return;
    else
    {
        pl3d_face3_struct vf=find(index),plast=_last;
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
pl3d_face3_struct l3d_face3::first()
{
    return _first;
}

pl3d_face3_struct l3d_face3::find(l3d_uint index)
{
    int ix=0;

    if(index < 0 || index > _nfaces)
        return NULL;

    pl3d_face3_struct pfirst=_first;

    while(ix++ != index && pfirst)
        pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return NULL;

}
void l3d_face3::clear()
{
    pl3d_face3_struct pf=_last;

    while(_last)
    {
        pf->_pv0=NULL;
        pf->_pv1=NULL;
        pf->_pv2=NULL;

        pf->_l0=NULL;
        pf->_l1=NULL;
        pf->_l2=NULL;

        _last=_last->prev;

        delete(pf);

        pf=_last;
    }

    _first=NULL;
    _last=NULL;
    _nfaces=0;



}
l3d_uint l3d_face3::size()
{
    return (_nfaces);
}
