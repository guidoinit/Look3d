#include "l3d_uv.h"

l3d_uv::l3d_uv()
{
    _size=0;
    _first=NULL;
}

void l3d_uv::add(pl3d_uv_struct _e)
{
    if(!_e)
        return;

    _e->_next=NULL;

    if(_first==NULL)
    {

        _first=_e;
    }
    else
    {
        pl3d_uv_struct _f=_first;

        while(_f->_next)
            _f=_f->_next;

        _f->_next=_e;


    }

    _size++;

}
void l3d_uv::add(UVTYPE _type, l3d_uint _index, l3d_uint _index2)
{
    pl3d_uv_struct nuv= new l3d_uv_struct;

    nuv->_type=_type;

    switch(_type)
    {
    case uvvertex:
        nuv->_index_vertex=_index;
        nuv->_index_triangle=0;
        nuv->_index_quad=0;

    break;
    case uvtriangle:
        nuv->_index_vertex=_index;
        nuv->_index_triangle=_index2;
        nuv->_index_quad=0;

    break;
    case uvquad:
        nuv->_index_vertex=_index;
        nuv->_index_triangle=0;
        nuv->_index_quad=_index2;
    break;
    }

    add(nuv);

}


pl3d_uv_struct l3d_uv::get(UVTYPE _t,l3d_uint _index,l3d_uint _index2)
{
    if(_first==NULL && _size==0)
        return NULL;

    pl3d_uv_struct _f=_first;

    while(_f)
    {
        switch(_t)
        {
        case uvvertex:
            if(_index==_f->_index_vertex)
                return(_f);

        break;
        case uvtriangle:
            if(_index==_f->_index_vertex &&
                    _index2==_f->_index_triangle)
                return(_f);

        break;
        case uvquad:
            if(_index==_f->_index_vertex &&
                    _index2==_f->_index_quad)
                return(_f);
        break;

        }




        _f=_f->_next;

    }
    return (NULL);

}

pl3d_uv_struct l3d_uv::get(l3d_uint _index)
{
    if(_first==NULL && _size==0)
        return NULL;

    if(_index > _size)
        return NULL;

    pl3d_uv_struct _f=_first;
    l3d_uint icount=0;

    while(_f && icount++!=_index)
        _f=_f->_next;

    if(_f)
        return(_f);

    return(NULL);



}

pl3d_uv_struct l3d_uv::first()
{
    return(_first);
}

l3d_bool l3d_uv::empty()
{
    return(_size==0 && _first==NULL);

}

l3d_uint l3d_uv::size()
{

    return _size;
}
void l3d_uv::clear()
{
    pl3d_uv_struct _f=_first,_f2;

    while(_f)
    {
        _f2=_f;

        _f=_f->_next;

        if(_f2)
        {

            _f2->_next=NULL;
            delete(_f2);

        }


    }

    _first=NULL;
    _size=0;
}
