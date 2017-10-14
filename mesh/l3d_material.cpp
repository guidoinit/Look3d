//    This file is part of Look3D program.

//    Look3D is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Look3D is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
//
//

#include "l3d_material.h"

using namespace l3d;
using namespace l3d::material;



l3d_material::l3d_material()
{
    _first=_last=l3d_null;
    _isel=0;
    _size=0;
}
l3d_material::~l3d_material()
{
    if(empty())
        return;
    pl3d_material_struct l=_last;

    if(_last!=l3d_null)
        while(l->prev)
        {
            l=l->prev;
            delete (l->next);
            l->next=l3d_null;
        }

    delete(l);

}

l3d_bool l3d_material::empty()
{
    return(_first==_last&& _last==l3d_null);
}

pl3d_material_struct l3d_material::first()
{
    return(_first);
}
pl3d_material_struct l3d_material::get(l3d_uint ix)
{
    pl3d_material_struct _m=_first;
    l3d_uint ic=0;
    while(_m && ic++<ix)
    {

        _m=_m->next;
    }
    return(_m);


}

pl3d_material_struct l3d_material::last()
{
    return (_last);
}
void l3d_material::addnew()
{
    pl3d_material_struct nmat= new l3d_material_struct;


    float val[4]={0.5F,0.5F,0.5F,1.0F};

    for(int ix=0; ix < 4; ix++)
    {
        nmat->mat_ambient[ix]=val[ix];
        nmat->mat_diffuse[ix]=val[ix];

        nmat->mat_specular[ix]=val[ix];
        nmat->mat_emission[ix]=0.0F;
    }
    nmat->mat_emission[3]=1.0F;

    nmat->m_bambientanddiffuse=false;
    nmat->_mface=front;
    nmat->mat_shininess[0]=.5F;

    //l3d_uint old=_size; ?? delete?
    add(nmat);

    //set(old); ?? is correct??






}

void l3d_material::add(pl3d_material_struct l3d_add)
{
    if(empty())
    {
        _first=l3d_add;
        _first->next=NULL;
        _first->prev=NULL;
        _last=_first;


    }
    else
    {
        l3d_add->prev=_last;
        l3d_add->next=NULL;
        _last->next=l3d_add;
        _last=l3d_add;



    }
    _size++;
}
void l3d_material::use()
{
    pl3d_material_struct pm=find(_isel);

    if(pm)
        pm->set();
}

void l3d_material::del(l3d_uint index)
{

    if(empty())
        return;

    pl3d_material_struct m=find(index),plast=_last;

    if(m != l3d_null)
    {
        if(m == _last)
        {
            _last->prev->next=NULL;
            _last=_last->prev;
            delete plast;
        }
        else if(_first ==_last && _size==1)
        {
            delete(_first);

            _first= NULL;

            _last = NULL;


        }
        else
        {
            m->prev->next=m->next;
            m->next->prev=m->prev;
            delete (m);

        }
        _size--;

    }
}

void l3d_material::set(l3d_uint index)
{
    pl3d_material_struct pm=find(index);


    if(pm!=l3d_null)
    {
        pm->set();
        _isel=index;
    }

}
pl3d_material_struct l3d_material::get_at(l3d_uint index)
{
    if ( empty() || index > _size )
        return l3d_null;

    pl3d_material_struct _m=_first;

    //(*_m)+=index;

    return _m;
}

pl3d_material_struct l3d_material::find(l3d_uint index)
{
    pl3d_material_struct pm=_first;
    l3d_uint ix=0;

    while(pm && ix++ < index)
        pm=pm->next;

    return(pm);
}
l3d_uint l3d_material::size()
{
    return _size;

}
