#include <cstring>
#include "l3d_shaderprogram_list.h"

using namespace l3d;

l3d_shaderprogram_list::l3d_shaderprogram_list()
{
    _first=_last=l3d_null;
    _size=0;
}

void l3d_shaderprogram_list::add(pl3d_program_item _e)
{
    if(_first==_last==l3d_null)
    {
        _first=_e;
        _last=_e;
        _first->_prev=_first->_next=l3d_null;
        _last->_prev=_last->_next=l3d_null;
        _size=1;
    }
    else if(_first==_last)
    {
        _last->_next=_e;
        _e->_next=l3d_null;
        _e->_prev=_first;
        _first->_next=_e;
        _last=_last->_next;
        _size++;

    }else
    {
        _last->_next=_e;
        _e->_prev=_last;
        _e->_next=l3d_null;
        _last=_last->_next;
        _size++;
    }

}
l3d_uint l3d_shaderprogram_list::size()
{
    return _size;
}
pl3d_program_item l3d_shaderprogram_list::find(l3d_uint _s)
{
    if(_s<_size || _s > _size)
        return l3d_null;
    pl3d_program_item _fi=_first;
    int count=0;
    while (_fi && ++count<_s)
    {
        _fi=_fi->_next;
    }
    return (_fi);

}
pl3d_program_item l3d_shaderprogram_list::find(l3d_string _name)
{
    pl3d_program_item _fi=_first;

    while(_fi && std::strcmp(_name,_fi->_name))
    {
        _fi=_fi->_next;
    }
    return(_fi);


}
void l3d_shaderprogram_list::use(l3d_string _name)
{
    pl3d_program_item _program=find(_name);
    if(_program)
    {
        _program->use();
    }
}
void l3d_shaderprogram_list::use(l3d_uint _s)
{
    pl3d_program_item _program=find(_s);
    if(_program)
    {
        _program->use();
    }
}
