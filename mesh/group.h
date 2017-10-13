#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <fstream>
#include <vector>
#include "l3d_vertex.h"
#include "l3d_transform.h"

using namespace l3d;
using namespace l3d::vertex3f;

class group
{
private:
    int m_id;
    int m_iname;
    l3d_vertex_fast m_pos;

    bool m_bselected;
    std::vector<int> m_listobject;

public:
    group();
    group(l3d_vertex_fast pos);
    group(int id,l3d_vertex_fast pos);
    group(int id,l3d_vertex_fast pos,std::vector<int> lvalue);
    group(int id);

    l3d_transform _transformation;

    l3d_bool erase;

    void setlist(int index,int value);
    int getlist(int);
    int getId();
    int getname();
    void setname(int value);
    bool selected();
    void selected(bool);
    void setId(int);
    void setList(std::vector<int> * list);
    void addObject(int value,l3d_vertex_fast pos);
    int getObject(int ipos);
    std::vector<int> getList();
    l3d_vertex_fast getPos();
    void setPos(l3d_vertex_fast vpos);
    void remObject(int value);

    void scale(l3d_vertex_fast value);
    void add( group g);

    void smooth();
    void flat();

    group ( const group &g )
    {
        m_id=g.m_id;

        _transformation.set(g._transformation);
        m_bselected=g.m_bselected;


        std::vector<int> applist=g.m_listobject;

        m_listobject.clear();

        for(int ix=0;ix < applist.size(); ix++ )
            m_listobject.push_back(applist[ix]);


    }
    group& operator=(const group &g)
    {
        m_id=g.m_id;

        m_pos=g.m_pos;
        _transformation.set(g._transformation);
        m_bselected=g.m_bselected;


        std::vector<int> applist=g.m_listobject;

        m_listobject.clear();

        for(int ix=0;ix < applist.size(); ix++ )
            m_listobject.push_back(applist[ix]);



        return *this;
    }
    void serialize(std::ifstream*  ar);
    void serialize(std::ofstream*  ar);


};

#endif // GROUP_H
