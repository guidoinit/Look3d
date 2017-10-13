#ifndef BEZIERLINE_H
#define BEZIERLINE_H
#include <vector>
#include <string>
#include <mesh/l3d_vertex.h>

#include "bezierbase.h"

using namespace std;
using namespace l3d::vertex3f;

class bezierline:public bezierbase
{
private:
    bool m_selected;
public:
    bezierline();
    bezierline(l3d_vertex _v);
    bezierline(const bezierline& b)
    {
        _cpoint=b._cpoint;
        m_wp=b.m_wp;
        m_rotate=b.m_rotate;
        m_scale=b.m_scale;
    }
    bezierline& operator=(const bezierline& b)
    {
        _cpoint=b._cpoint;
        m_wp=b.m_wp;
        m_rotate=b.m_rotate;
        m_scale=b.m_scale;

        return (*this);
    }
    string _name;
    int iname;
    int idmap;

    l3d_vertex_fast m_wp;//world pos
    l3d_vertex_fast m_scale;
    l3d_vertex_fast m_rotate;
    void setid(int);
    void init();
    void draw();
    void drawselect();
    bool selected();
    void selected(bool);
    void setwp(l3d_vertex_fast);
    void setscale(l3d_vertex_fast);
    void setrotate(l3d_vertex_fast);

    void applyscale();
    void applyrotate();
    void rotatex();
    void rotatey();
    void rotatez();
    void serialize(std::ifstream*  ar)
    {
        if(ar->is_open())
        {
            int size;
            ar->read((char*)&size,sizeof(int));
            pl3d_vertex_fast appv=_cpoint.first();
            appv->serialize(ar);
            _cpoint.add(appv);
            for(int ix=1; ix < size; ix++)
            {
                appv->serialize(ar);
                _cpoint.add(appv);
            }

        }
        else
        {


        }


    }
    void serialize(std::ofstream*  ar)
    {
        if(ar->is_open())
        {
            int size=_cpoint.size();
            ar->write((char*)&size,sizeof(int));
            for(int ix=0; ix < size; ix++)
                _cpoint.find(ix)->serialize(ar);



        }
        else
        {


        }


    }
};

#endif // BEZIERLINE_H
