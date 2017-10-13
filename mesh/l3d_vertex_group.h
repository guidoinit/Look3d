#ifndef L3D_VERTEX_GROUP_H
#define L3D_VERTEX_GROUP_H


#include <iostream>
#include <fstream>

#include <string>
#include <string.h>

#include "l3d_include.h"

using namespace std;

namespace l3d
{

namespace vertex_group
{
    enum type_element
    {

        group_vertex=0,
        group_edge=1,
        group_face=2,
        group_quad=3,

        group_finish=255

    };

    typedef struct _list
    {

        l3d_uint info;

        _list * _first;
        _list * _last;
        _list * next;
        _list * prev;

        _list * next_type;
        _list * prev_type;

        type_element type;

        l3d_uint _size;

        void init()
        {
            _first=_last=l3d_null;
            next=prev=l3d_null;
            next_type=prev_type=l3d_null;
            _size=0;
        }
        void clean()
        {
            if(_size==0)
                return;
            else if(_size==1)
            {
                delete(_first);
                init();
            }
            else
            {
                _list * plist=next;
                if(plist)
                {
                    delete(plist->prev);

                    plist->prev=l3d_null;
                }

                while(plist)
                {

                    plist=plist->next;

                    if(plist)
                    {
                        delete(plist->prev);

                        plist->prev=l3d_null;
                    }


                }
                init();
            }
        }

        l3d_bool empty()
        {

            return(_size==0 && _first==_last && _last==l3d_null);

        }

        l3d_uint size()
        {

            return _size;

        }

        _list * find_first_type(type_element t)
        {
            _list * l=_first;

            while(l && l->type!=t)
                l=l->next_type;

            return(l);

        }

        _list * find_last_type(type_element t)
        {

            _list * l=find_first_type(t);

            if(l!=l3d_null)
                while(l->next_type)
                    l=l->next_type;

            return(l);

        }

        void add(l3d_uint _info,type_element t)
        {

            _list *nl= new _list;




            nl->info=_info;

            nl->type=t;

            if(empty())
            {

                nl->next=l3d_null;
                nl->prev=l3d_null;

                nl->next_type=l3d_null;
                nl->prev_type=l3d_null;

                _first=nl;
                _last=nl;



            }
            else
            {
                nl->prev_type=find_last_type(nl->type);
                if(nl->prev_type!=l3d_null)
                    nl->prev_type->next_type=nl;

                nl->next_type=l3d_null;


                nl->prev=_last;
                nl->next=l3d_null;

                _last->next=nl;
                _last=nl;




            }

            _size++;

        }
        void serialize(std::ifstream*  ar)
        {
            if(ar->is_open())
            {
                l3d_uint app_size;
                ar->read((char*)&app_size,sizeof(l3d_uint));
                for(l3d_uint ix=0; ix < app_size;ix++)
                {
                    type_element _type;
                    l3d_uint _ele;

                    ar->read((char*)&_type,sizeof(type_element));
                    ar->read((char*)&_ele,sizeof(l3d_uint));

                    add(_ele,_type);


                }

            }
        }
        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {
                ar->write((char*)&_size,sizeof(l3d_uint));

                _list * app_first=_first;

                while(app_first)
                {

                    ar->write((char*)&app_first->type,sizeof(type_element));
                    ar->write((char*)&app_first->info,sizeof(l3d_uint));

                    app_first=app_first->next;

                }




            }
        }

    }l3d_group,*pl3d_group;

    typedef struct _group_vertex
    {

        pl3d_group info;

        _group_vertex* _first;
        _group_vertex* next;
        _group_vertex* prev;

        l3d_string _name;
        l3d_uint _id;
        l3d_uint _size;

        void init()
        {
            next=prev=_first=l3d_null;
            info=new l3d_group;
            info->init();
            _size=0;
        }
        void clear()
        {
            if(_size==0)
                return;
            else if(_size==1)
            {
                _first->info->clean();
                delete(_first);
                _first=l3d_null;
                _size=0;
                init();
            }
            else
            {
                _group_vertex* appfirst=_first;

                while(appfirst)
                {

                    appfirst->info->clean();
                    appfirst=appfirst->next;


                    delete(appfirst->prev);

                }
                init();

            }

        }

        void setname(l3d_string _n)
        {
            _name=_n;
        }
        l3d_string getname()
        {
            return(_name);
        }

        l3d_bool empty()
        {
            return( _size==0);
        }

        //funzioni per aggiungere un elemento al gruppo

        void add(l3d_uint _info,type_element t)
        {
            info->add(_info,t);

        }

        void set_group(pl3d_group ng)
        {
            if(!ng)
                return;

            delete(info);

            info=ng;




        }
        void add(_group_vertex* g)
        {
            //continuare da qui

            _group_vertex* first=_first;

            if(g==l3d_null)
                    return;

            if(empty())
            {
                _first=g;
                g->next=l3d_null;
                g->prev=l3d_null;
            }
            else
            {
                while(first->next) first=first->next;

                first->next=g;

                g->next=l3d_null;
                g->prev=first;



            }
            _size++;









        }

        _group_vertex* first()
        {

            return _first;

        }
        void serialize(std::ifstream*  ar)
        {
            if(ar->is_open())
            {
                _name= new char[50];


                ar->read((char*)_name,sizeof(char)*50);
                ar->read((char*)&_id,sizeof(l3d_uint));

                info= new l3d_group;
                info->init();

                info->serialize(ar);





            }

        }
        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {
                char * appc= new char[50];

                ::strcpy(appc,_name);

                ar->write((char*)appc,sizeof(char)*50);
                ar->write((char*)&_id,sizeof(l3d_uint));


                if(info)
                {
                    info->serialize(ar);
                }



            }
        }


    }l3d_vertex_group_struct,*pl3d_vertex_group_struct;

    class l3d_vertex_group
    {
    public:
        l3d_vertex_group();
        ~l3d_vertex_group();
        pl3d_vertex_group_struct first_group();
        pl3d_vertex_group_struct last_group();
        l3d_uint size();


        void add_group(pl3d_vertex_group_struct);
        void del_group(l3d_uint);
        void del_group();
        void next_group();
        void prev_group();
        void set_group();
        l3d_uint get_name();
        std::string get_sname();
        pl3d_vertex_group_struct get_group();
        pl3d_group get_group_list();

        pl3d_vertex_group_struct find_group(l3d_uint index);

        l3d_bool empty();

        void serialize(std::ofstream*  ar);
        void serialize(std::ifstream*  ar);

    private:
        pl3d_vertex_group_struct _first_group;
        pl3d_vertex_group_struct _last_group;
        l3d_uint _size;
        int _gselected;

    };

}
}

#endif // L3D_VERTEX_GROUP_H
