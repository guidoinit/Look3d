#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_line.h"


using namespace l3d::edge;
using namespace l3d::vertex3f;

l3d_line::l3d_line()
{
    _first=NULL;
    _last=NULL;
    _nlines=0;
}

l3d_line::l3d_line(pl3d_line_struct first,l3d_uint nlines)
{
    _first=first;
    _nlines=nlines;

}
l3d_bool l3d_line::isfirst()
{
    return(_first==NULL && _last==NULL && _nlines==0);
}
pl3d_line_struct l3d_line::find(l3d_uint index)
{
    l3d_uint ix=0;
    if(index < 0 || index > _nlines)
        return NULL;

    pl3d_line_struct pfirst=_first;

    while(ix++ != index && pfirst)
        pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return NULL;
}
pl3d_line_struct l3d_line::first()
{
    return (_first);
}
l3d_uint l3d_line::findindex(l3d_uint v0,l3d_uint v1)
{
    l3d_uint ix=0;
    l3d_uint index=_nlines;
    l3d_uint iret=-1;

    pl3d_line_struct pfirst=_first;

    while(ix < index && pfirst)
    {
        if((pfirst->v0==v0 && pfirst->v1==v1) || (pfirst->v0==v1 && pfirst->v1==v0))
            return (ix);
        else
        {
            pfirst=pfirst->next;
            ix++;
        }


    }

    if(pfirst)
        return (ix);
    else
        return iret;
}
pl3d_line_struct l3d_line::find(l3d_uint v0,l3d_uint v1)
{
    l3d_uint ix=0;
    l3d_uint index=_nlines;

    pl3d_line_struct pfirst=_first;

    while(ix++ < index && pfirst)
        if((pfirst->v0==v0 && pfirst->v1==v1) || (pfirst->v0==v1 && pfirst->v1==v0))
            return (pfirst);
        else
            pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return NULL;
}

void l3d_line::add(pl3d_line_struct line)
{
    //si assume che line->next=NULL e line->prev=NULL
    pl3d_line_struct nl=new l3d_line_struct;
    *nl=*line;
    nl->next_size=nl->prev_size=0;
    if(isfirst())
    {
        _first=nl;
        _first->next=l3d_null;
        _first->prev=l3d_null;
        _last=_first;

    }
    else
    {
        nl->prev=_last;
        nl->next=l3d_null;

        _last->next=nl;
        _last=nl;



    }
    _nlines++;


}
void l3d_line::clear()
{
    pl3d_line_struct lf=_last;

    while(_last)
    {
        _last=_last->prev;
        lf->_v0=NULL;
        lf->_v1=NULL;
        delete (lf);
        lf=_last;
    }
    _first=NULL;
    _last=NULL;
    _nlines=0;

}
void l3d_line::del(pl3d_line_struct l)
{
    pl3d_line_struct f=first();

    l3d_uint ix=0;

    while(f!=l && ix++<size())
        f=f->next;

    if(f==l)
        del(ix);

}

void l3d_line::del(l3d_uint index)
{
    if(isfirst())
        return;
    else
    {
        pl3d_line_struct lf=find(index),plast=_last;
        if(lf != NULL)
        {
            if(lf == _last)
            {
                _last->prev->next=NULL;
                _last=_last->prev;

                plast->purge();


                delete plast;
            }
            else if(_first ==_last && _nlines==1)
            {
                _first->purge();

                delete(_first);

                _first= NULL;
                _last = NULL;

            }
            else
            {
                lf->prev->next=lf->next;

                lf->purge();


                delete (lf);

            }

            _nlines--;

        }

    }

}
l3d_uint l3d_line::size()
{
    return _nlines;
}
l3d_uint l3d_line::index(l3d_uint v0,l3d_uint v1)
{
    l3d_uint ix=0;
    l3d_uint index=_nlines;

    pl3d_line_struct pfirst=_first;

    while(ix++ < index && pfirst)
        if(pfirst->v0==v0 && pfirst->v1==v1 || pfirst->v0==v1 && pfirst->v1==v0)
            return (ix-1);
        else
            pfirst=pfirst->next;

    return (-1);

}
