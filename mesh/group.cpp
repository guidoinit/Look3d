#include "group.h"
#include <iostream>
#include <fstream>
#include <vector>

//rappresenta un gruppo di oggetto gestito da una lista di interi

group::group()
{
    m_listobject.clear();
    m_pos.set(0.0F,0.0F,0.0F);
    _transformation.init();
    m_bselected=false;
    erase=false;
}

group::group(int value)
{
    m_listobject.clear();
    m_id=value;
    m_pos.set(0.0F,0.0F,0.0F);
    _transformation.init();
    m_bselected=false;
    erase=false;
}

group::group(l3d_vertex_fast value)
{
    m_listobject.clear();

    _transformation.init();
    m_pos=value;
    m_bselected=false;
    erase=false;
}

group::group(int value,l3d_vertex_fast v)
{
    m_listobject.clear();
    m_id=value;
    _transformation.init();
    m_pos=v;

    m_bselected=false;
    erase=false;
}

group::group(int value,l3d_vertex_fast v,std::vector<int> lvalue)
{
    m_listobject=lvalue;
    m_id=value;
    _transformation.init();
    m_pos=v;
    m_bselected=false;
    erase=false;
}
void group::selected(bool value)
{
    m_bselected=value;
}

bool group::selected()
{
    return m_bselected;
}

int group::getname()
{
    return m_iname;
}

void group::setname(int value)
{
    m_iname=value;
}

int group::getId()
{
    return m_id;
}

void group::setId(int value)
{
    m_id=value;
}

void group::addObject(int value,l3d_vertex_fast pos)
{


    m_listobject.push_back(value);
}
l3d_vertex_fast group::getPos()
{
    return m_pos;
}

void group::setPos(l3d_vertex_fast vpos)
{
    m_pos=vpos;
}

int group::getObject(int ipos)
{
    if(ipos >=0 && ipos < m_listobject.size())
        return (m_listobject[ipos]);
}

void group::remObject(int value)
{
    if(value>=0 && value < m_listobject.size())
        m_listobject.erase(m_listobject.begin()+value);




}
std::vector<int> group::getList()
{
    return m_listobject;
}

void group::setList(std::vector<int> *list)
{

    m_listobject.clear();

    m_listobject=*list;
}
void group::add( group g)
{
    std::vector<int> applist=g.getList();

    for(std::vector<int>::iterator it=applist.begin();it != applist.end(); ++it)
    {
        m_listobject.push_back(*it);
    }

    m_bselected=m_bselected && g.m_bselected;
    //m_pos.SetVertex(((m_pos.GetX()+g.m_pos.GetX())/2.0F),
         //           ((m_pos.GetY()+g.m_pos.GetY())/2.0F),
         //           ((m_pos.GetZ()+g.m_pos.GetZ())/2.0F));
    //to-do applicare a tutti gli oggetti scalatura e rotazione prima di unire un gruppo

    _transformation._rotate.set(0.0F,0.0F,0.0F);
    _transformation._scale.set(1.0F,1.0F,1.0F);
}
void group::setlist(int index,int value)
{
    if(index>=0 && index <m_listobject.size())
        m_listobject[index]=value;
}
int group::getlist(int index)
{
    if(index>=0 && index <m_listobject.size())
        return (m_listobject[index]);
}

void group::serialize(std::ifstream *ar)
{
    if(ar->is_open())
    {
        std::vector<int>::iterator it;

        int size,value=0;
        ar->read((char*)&size,sizeof(int));

        m_listobject.clear();

        for(int ix=0; ix < size; ix++)
        {
            ar->read((char*)&value,sizeof(int));

            m_listobject.push_back(value);
        }

        _transformation.serialize(ar);



    }
    else
    {


    }

}

void group::serialize(std::ofstream *ar)
{
    if(ar->is_open())
    {
        std::vector<int>::iterator it;

        int size=m_listobject.size();
        ar->write((char*)&size,sizeof(int));

        for(it=m_listobject.begin();it!=m_listobject.end(); ++it)
        {
            int e=(*it);
            ar->write((char*)&e,sizeof(int));

        }



        _transformation.serialize(ar);
    }
    else
    {


    }

}

void group::scale(l3d_vertex_fast value)
{
    _transformation._scale+=value;
}
void group::smooth()
{


}
void group::flat()
{

}
