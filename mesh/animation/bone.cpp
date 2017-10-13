#define GLEW_STATIC
#include <GL/glew.h>

#include <list>


#include "bone.h"

bone::bone()
{
    _first=_second=NULL;
    _id=-1;
    _box=NULL;
}
bone::bone(join* f, join *s)
{
    _first=f;
    _second=s;
    _id=-1;
    _box=NULL;
}
bone::bone(join* f, join *s,int id)
{
    _first=f;
    _second=s;
    _id=id;
    _box=NULL;
}


void bone::addnext(bone *_nb,int id)
{
    if(_nb!=NULL && _id==id)
        _next.push_back(_nb);
    else if(find(this,id))
    {
        bone *_fb=get(this,id);

        _fb->_next.push_back(_nb);

    }


}

void bone::setbox(bbox *_bb)
{
    _box=_bb;
}

bool bone::find(bone * _b,int id)
{
    if(_b->_id==id)
        return (true);

    else
    {

        static list<bone*>::iterator ib=_b->_next.begin();

        while(++ib!=_b->_next.end())
            return(find((*ib),id));

        return (false);
    }


}
bone * bone::get(bone * _b,int id)
{
    if(_b->_id==id)
        return (_b);

    else
    {

        static list<bone*>::iterator ib=_b->_next.begin();

        while(++ib!=_b->_next.end())
            return(get((*ib),id));

        return (NULL);
    }


}
void bone::setid(bone * _b,int nid)
{
    _b->setid(nid);

    static list<bone*>::iterator ib=_b->_next.begin();

    while(++ib!=_b->_next.end())
        setid((*ib),nid++);




}

void bone::setid(int nid)
{
    _id=nid;
}
/*
void bone::draw(bone * _bone,object3d * join,object3d * obone)
{
    //to-do
    //1 disegna la bone in base alle join

    vertex appv;
    if(_bone==NULL)
        return;

    if(_bone->_first!=NULL)
    {
        appv=*_bone->_first->get();
        join->world_pos=*_bone->_first->get();
        join->DrawColor(false);

    }



    if(_bone->_second!=NULL)
    {
        appv+=*_bone->_second->get();
        join->world_pos=*_bone->_second->get();
        join->DrawColor(false);

    }

    if(_bone->_first!=NULL && _bone->_second!=NULL)
    {
        obone->world_pos.SetVertex(appv.GetX()/2.0F,appv.GetY()/2.0F,appv.GetZ()/2.0F);
        obone->DrawColor(false);
    }
    else
    {
        obone->world_pos=appv;
        obone->DrawColor(false);

    }

    if(_next.size()==0)
        return;

    static list<bone*>::iterator ib=_next.begin();

    while(++ib!=_next.end())
        draw((*ib),join,obone);



}*/

void bone::draw_select()
{
    //to-do
}
