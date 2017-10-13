#include <list>

#include "vertexlist.h"

vertexlist::vertexlist()
{
    _list.clear();
}

vertexlist::vertexlist(list<int> _l)
{
    _list=_l;
}
vertexlist::~vertexlist()
{
    _list.clear();
}
void vertexlist::add(int e)
{
    _list.push_back(e);

}
int vertexlist::get(int i)
{
    std::list<int>::iterator il;

    int count=0;
    if(!_list.empty())
        il=_list.begin();
    while(++il!=_list.end() && count++ < i);

    if(il!=_list.end() && count==i)
        return (*il);
    else
        return (-1);
}

void vertexlist::empty()
{
    _list.clear();
}

int vertexlist::size()
{
    return (_list.size());
}
