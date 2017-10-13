#define GLEW_STATIC
#include <GL/glew.h>

#include <QtGlobal>
#include "l3d_include.h"
#include "l3d_vertex_group.h"

using namespace l3d;
using namespace l3d::vertex_group;


l3d_vertex_group::l3d_vertex_group()
{
    _first_group=_last_group=l3d_null;
    _size=0;
    _gselected=-1;
}

l3d_vertex_group::~l3d_vertex_group()
{

}


pl3d_vertex_group_struct l3d_vertex_group::first_group()
{
    return _first_group;
}

pl3d_vertex_group_struct l3d_vertex_group::last_group()
{
    return _last_group;
}
l3d_uint l3d_vertex_group::size()
{
    return _size;
}

l3d_bool l3d_vertex_group::empty()
{
    return(_first_group==_last_group && _last_group==l3d_null && _size==0);
}

void l3d_vertex_group::add_group(pl3d_vertex_group_struct ng)
{


    if( ng==l3d_null)
        return;
    if(empty())
    {
        _first_group=_last_group=ng;
        ng->next=ng->prev=l3d_null;

    }
    else
    {
        _last_group->next=ng;
        ng->prev=_last_group;
        ng->next=l3d_null;
        _last_group=ng;

    }

    _gselected=_size;
    _size++;



}
void l3d_vertex_group::del_group()
{
    del_group(_gselected);

}

void l3d_vertex_group::del_group(l3d_uint ng)
{
    Q_ASSERT(ng>=0 && ng<_size);

    pl3d_vertex_group_struct g=find_group(ng);
    if(_first_group ==_last_group && _size==1)
    {
        //to-do eliminare tutti gli  elementi del gruppo
        delete(_first_group);
        _first_group= NULL;
        _last_group = NULL;

    }
    else if(g == _last_group)
    {
        _last_group->prev->next=NULL;

        _last_group=_last_group->prev;

        //to-do eliminare tutti gli  elementi del gruppo
        delete (g);
    }
    else if(g == _first_group)
    {
        _first_group=_first_group->next;

        _first_group->prev=l3d_null;

        delete(g);


    }

    else
    {
        g->prev->next=g->next;
        g->next->prev=g->prev;

        //to-do eliminare tutti gli  elementi del gruppo
        delete (g);
    }

    _gselected=_size;
    _size--;


}

pl3d_vertex_group_struct l3d_vertex_group::find_group(l3d_uint index)
{
    Q_ASSERT(index>=0 && index<_size);

    pl3d_vertex_group_struct g=first_group();

    l3d_uint ix=0;

    while(g && ix++ < index)
        g=g->next;

    return(g);


}
void l3d_vertex_group::next_group()
{
    if(_size==0)
        return;
    if(_gselected+1<_size)
        _gselected++;


}

void l3d_vertex_group::prev_group()
{
    if(_size==0)
        return;
    if(_gselected-1 >=0)
        _gselected--;

}
void l3d_vertex_group::set_group()
{

}
l3d_uint l3d_vertex_group::get_name()
{
    return(_gselected);
}
std::string l3d_vertex_group::get_sname()
{

    pl3d_vertex_group_struct pg=find_group(_gselected);

    if(pg)
        return(pg->getname());
    else
        return("");


}
pl3d_vertex_group_struct l3d_vertex_group::get_group()
{

    pl3d_vertex_group_struct pg=find_group(_gselected);

    return(pg);


}
pl3d_group l3d_vertex_group::get_group_list()
{
    pl3d_vertex_group_struct pg=find_group(_gselected);

    return(pg->info->_first);
}
void l3d_vertex_group::serialize(std::ofstream*  ar)
{
    pl3d_vertex_group_struct appv=_first_group;

    ar->write((char*)&_size,sizeof(l3d_uint));

    while(appv)
    {

        appv->serialize(ar);


        appv=appv->next;
    }


}
void l3d_vertex_group::serialize(std::ifstream*  ar)
{

    l3d_uint appsize;
    ar->read((char*)&appsize,sizeof(l3d_uint));


    for(l3d_uint ix=0;  ix < appsize;ix++)
    {
        pl3d_vertex_group_struct appv= new l3d_vertex_group_struct;

        appv->serialize(ar);

        this->add_group(appv);

    }


}
