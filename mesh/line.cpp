#include <iostream>
#include <fstream>
#include <list>

#include "line.h"


line::line()
{
        m_vertice[0]=-1;
        m_vertice[1]=-1;
        m_iname=-1;
        m_bselected=false;
        m_berase=false;
}

line::line(int v1,int v2)
{
        m_vertice[0]=v1;
        m_vertice[1]=v2;
        m_iname=-1;
        m_bselected=false;
        m_berase=false;
}

line::line(int v[2])
{
        m_vertice[0]=v[0];
        m_vertice[1]=v[1];
        m_iname=-1;
        m_bselected=false;
        m_berase=false;
}
void line::SetName(int nm)
{
        m_iname=nm;
}
int line::GetName()
{
        return m_iname;
}
void line::SetLine(int v1, int v2)
{
        m_vertice[0]=v1;
        m_vertice[1]=v2;
}
int line::GetVertice(int nv)
{
        if(nv >=0 && nv <2)
                return(m_vertice[nv]);
        return -1;
}
int line::get(int nv)
{
        if(nv >=0 && nv <2)
                return(m_vertice[nv]);
        return -1;
}
line::~line()
{
}
bool line::selected()
{
    return m_bselected;
}

void line::selected(bool value)
{
    m_bselected=value;
}

void line::SetSelected(bool sel)
{
        m_bselected=sel;
}
bool line::IsSelected()
{
        return m_bselected;
}
void line::addprev(int value)
{
    m_prev.push_back(value);
}
void line::addnext(int value)
{
    m_next.push_back(value);
}
int line::nextsize()
{
    return m_next.size();
}
int line::prevsize()
{
    return m_prev.size();

}
int line::getnext(int val)
{
    std::list<int>::iterator it=m_next.begin();
    for(int ix=0; ix < val; ix++)
        it++;
    return (*it);
}
int line::getprev(int val)
{
    std::list<int>::iterator it=m_prev.begin();
    for(int ix=0; ix < val; ix++)
            it++;

    return (*it);

}

void line::clear_np()
{
    m_prev.clear();
    m_next.clear();
}
