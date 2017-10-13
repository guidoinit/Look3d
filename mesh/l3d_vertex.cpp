#include "l3d_vertex.h"

using namespace l3d::vertex3f;

l3d_vertex::l3d_vertex()
{
    _first=NULL;
    _last=NULL;
    _nvertex=0;
}

l3d_vertex::l3d_vertex(pl3d_vertex_fast l3d_first)
{
    _first=l3d_first;
}
void l3d_vertex::add(pl3d_vertex_fast l3d_add,l3d_uint nvertex)
{
    //si assume che nvertex contenga il numero esatto di vertici contenuti in l3d_add
    //e che l'ultimo elemento in l3d_add punti a NULL

    _last->next=l3d_add;
    _nvertex+=nvertex;

}
void l3d_vertex::add(l3d_float v0,l3d_float v1 ,l3d_float v2)
{
    pl3d_vertex_fast pv= new l3d_vertex_fast;

    pv->x=v0;
    pv->y=v1;
    pv->z=v2;

    pv->normals[0]=0.0F;
    pv->normals[1]=0.0F;
    pv->normals[2]=0.0F;

    pv->picking_name=-1;

    pv->next=NULL;
    pv->prev=NULL;

    add(pv);
    delete(pv);

}
pl3d_vertex_fast l3d_vertex::first()
{
    return _first;

}

pl3d_vertex_fast l3d_vertex::get(l3d_uint index)
{
    pl3d_vertex_fast v=find(index);

    pl3d_vertex_fast vr=new l3d_vertex_fast;

    vr->x=v->x;
    vr->y=v->y;
    vr->z=v->z;

    vr->normals[0]=v->normals[0];
    vr->normals[1]=v->normals[1];
    vr->normals[2]=v->normals[2];



    vr->next=NULL;
    vr->prev=NULL;

    return(vr);

}
l3d_bool l3d_vertex::isfirst()
{
    return(_first==NULL && _last==NULL && _nvertex==0);
}



void l3d_vertex::add(pl3d_vertex_fast l3d_add)
{
    pl3d_vertex_fast nv= new l3d_vertex_fast;
    *nv=*l3d_add;

    nv->erase=false;
    nv->selected(false);

    if(isfirst())
    {

        _first=nv;
        _first->next=l3d_null;
        _first->prev=l3d_null;
        _last=_first;


    }
    else
    {
        nv->prev=_last;
        nv->next=l3d_null;
        _last->next=nv;
        _last=nv;



    }
    _nvertex++;


}

void l3d_vertex::del(l3d_uint index)
{
    if(isfirst())
        return;
    else
    {
        pl3d_vertex_fast vf=find(index),plast=_last;
        if(vf != NULL)
        {
            if(vf == _last)
            {
                _last->prev->next=NULL;

                _last=_last->prev;

                delete plast;
            }
            else if(_first ==_last && _nvertex==1)
            {
                delete(_first);
                _first= NULL;
                _last = NULL;

            }
            else
            {
                vf->prev->next=vf->next;
                delete (vf);
            }

            _nvertex--;

        }




    }

}
l3d_uint l3d_vertex::size()
{
    return(_nvertex);
}

void l3d_vertex::clear()
{

    pl3d_vertex_fast pfirst=_last;

    while(_last)
    {

        _last=_last->prev;

        delete pfirst;

        pfirst=_last;

    }
    _first=NULL;
    _last=NULL;
    _nvertex=0;

}

pl3d_vertex_fast l3d_vertex::find(l3d_uint index)
{
    l3d_uint ix=0;
    if(index < 0 || index > _nvertex)
        return NULL;

    pl3d_vertex_fast pfirst=_first;

    while(ix++ != index && pfirst)
        pfirst=pfirst->next;

    if(pfirst)
        return (pfirst);
    else
        return NULL;



}


