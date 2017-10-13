#include "vertexgroup.h"

vertexgroup::vertexgroup()
{
}
vertexgroup::vertexgroup(string name,int id,list<int> _l)
{
    _name=name;
    _id=id;
    _list=_l;

}

void vertexgroup::add(int v)
{
    _list.push_back(v);
}

int vertexgroup::get(int index)
{
    if(index <0 || index >_list.size())
        return -1;

    list<int>::iterator it=_list.begin();

    int ix=0;

    while(it++!=_list.end() && ix++<_list.size())
        ;

    if(ix <_list.size())
         return(*it);
    else
        return -1;

    return -1;
}

void vertexgroup::set(list<int> l)
{
    _list=l;
}
void vertexgroup::setline(list<int> ln)
{
    _list_line=ln;
}
void vertexgroup::setpoly(list<int> p)
{
    _list_poly=p;
}
void vertexgroup::clear()
{
    _list.clear();
}
list<int> vertexgroup::getlist()
{
    return _list;
}
list<int> vertexgroup::getlist_line()
{
    return _list_line;
}
list<int> vertexgroup::getlist_poly()
{
    return _list_poly;
}
string vertexgroup::getname()
{
    return (_name);
}
