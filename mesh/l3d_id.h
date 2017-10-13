#ifndef L3D_ID_H
#define L3D_ID_H

#include "l3d_mesh.h"

#include "l3d_include.h"

using namespace l3d::mesh;

namespace l3d
{
    enum l3d_idtype
    {

        id_mesh =0,
        id_vbo,
        id_color,
        id_material,
        id_texture,
        id_group,
        id_vertex_group,
        id_layer,
        id_light,


        id_last=65535

    };

    typedef struct __id_prop
    {

        l3d_uint iname;

        l3d_string name;
        l3d_string description;







    }_id_prop,*_pid_prop;

    typedef struct __id
    {

        l3d_uint _id;

        __id * link;


        __id * next;

        __id * prev;


        __id * next_type;

        __id * prev_type;


        __id* makefirst()
        {

            _id=l3d_idnull;


            next=l3d_null;

            prev=l3d_null;


            object=l3d_null;


            next_type=l3d_null;

            prev_type=l3d_null;


            _type=id_last;


            id_prop.name="";

            id_prop.iname=-1;

            id_prop.description="";


            return(this);



        }




        l3d_idtype _type;


        _id_prop id_prop;


        l3d_void object;




    }l3d_id,*pl3d_id;
    typedef struct __id_list
    {
        pl3d_id  _first;
        pl3d_id  _last;

        //_pid info;

        l3d_uint _size;

        void init()
        {
            _first=l3d_null;
            _last=l3d_null;
            _size=0;
        }

        void add(pl3d_id id)
        {
            if(empty())
            {

                id->next=l3d_null;
                id->prev=l3d_null;

                id->next_type=l3d_null;
                id->prev_type=l3d_null;

                _first=id;
                _last=id;

            }
            else
            {
                l3d_idtype t=id->_type;


                id->prev_type=find_last_type(t);
                if(id->prev_type!=l3d_null)
                    id->prev_type->next_type=id;

                id->next_type=l3d_null;


                id->prev=_last;
                id->next=l3d_null;

                _last->next=id;
                _last=id;

            }
            _size++;

        }

        l3d_uint size_type(l3d_idtype t)
        {
            if(empty())
                return 0;

            l3d_uint cm=0;

            pl3d_id e=find_first_type(t);

            //trova la mesh (n)

            while ( e )
            {
                cm++;
                e=e->next_type;

            }

            return (cm);





        }

        pl3d_id get_type(l3d_uint n,l3d_idtype t)
        {
            if(empty())
                return l3d_null;

            l3d_uint cm=0;

            pl3d_id e=find_first_type(t);

            while ( e && cm++ < n )
                e=e->next_type;

            return (e);

        }

        void del_type(l3d_uint n,l3d_idtype t)
        {
            if(empty())
                return;

            l3d_uint cm=0;

            pl3d_id e=find_first_type(t);

            //trova la mesh (n)

            while ( e && cm++ < n )
                e=e->next_type;

            if(e)
            {
                e->object=l3d_null;
                if(e==_first && _first==_last && _size==1)
                {
                    _first=_last=l3d_null;
                }

                else if(e==_first)

                {
                    _first=_first->next;
                    _first->prev=l3d_null;
                    _first->prev_type=l3d_null;
                }

                else if(e==_last)

                {
                    _last=_last->prev;
                    _last->next=l3d_null;
                    _last->next_type=l3d_null;

                }

                else

                {

                    e->prev->next=e->next;
                    e->next->prev=e->prev;
                    if(e->prev->next_type==e)
                    {
                        e->prev->next_type=e->next_type;

                    }
                    if(e->next->prev_type==e)
                    {
                        e->next->prev_type=e->prev_type;
                    }

                }



                delete (e);

                _size--;






            }




        }
        void del_group(group* _g)
        {
            l3d_uint ng=find(_g);

            if(ng==-1)
                return;

            del(ng);

        }

        void del_mesh(pl3d_mesh_struct _m)
        {
            l3d_uint nm=find(_m);

            if(nm==-1)
                return;

            del(nm);
        }

        void del_mesh(l3d_uint n)
        {
            if(empty())
                return;

            l3d_uint cm=0;

            pl3d_id e=find_first_type(id_mesh);
            pl3d_id plast=_last;
            //trova la mesh (n)

            while ( e && cm++ < n )
                e=e->next_type;

            //la elimina
            if(e != l3d_null)
            {
                if(e == _last && _size > 1)
                {
                    plast->prev->next=l3d_null;
                    _last=plast->prev;
                    delete plast;
                }
                else if(_first==_last && _size==1)
                {

                    delete(_first);

                    _first= l3d_null;
                    _last = l3d_null;

                }
                else
                {

                    e->prev->next=e->next;
                    e->next->prev=e->prev;

                    delete (e);
                }

                _size--;

            }

        }
        void del(pl3d_id n)
        {
            l3d_uint i=find(n);

            if(i!=-1)
                del(i);
        }

        void del(l3d_uint n)
        {

            if(empty())
                return;

            pl3d_id e=find(n);
            if(e)
            {
                e->object=l3d_null;
                if(e==_first && _first==_last && _size==1)
                {
                    _first=_last=l3d_null;
                }

                else if(e==_first)

                {
                    _first=_first->next;
                    _first->prev=l3d_null;
                    _first->prev_type=l3d_null;
                }

                else if(e==_last)

                {
                    _last=_last->prev;
                    _last->next=l3d_null;
                    _last->next_type=l3d_null;

                }

                else

                {

                    e->prev->next=e->next;
                    e->next->prev=e->prev;
                    if(e->prev->next_type==e)
                    {
                        e->prev->next_type=e->next_type;

                    }
                    if(e->next->prev_type==e)
                    {
                        e->next->prev_type=e->prev_type;
                    }

                }



                delete (e);




                _size--;



            }



        }
        l3d_uint find(group* _gid)
        {
            l3d_uint i=0;
            pl3d_id s=_first;

            while(s)
            {
                if(_gid==(group*)s->object)
                    return(i);
                i++;
                s=s->next;

            }
            return(-1);

        }

        l3d_uint find(pl3d_mesh_struct _mid)
        {
            l3d_uint i=0;
            pl3d_id s=_first;

            while(s)
            {
                if(_mid==(pl3d_mesh_struct)s->object)
                    return(i);
                i++;
                s=s->next;

            }
            return(-1);

        }
        l3d_uint find(pl3d_id _id)
        {
            l3d_uint i=0;
            pl3d_id s=_first;

            while(s)
            {
                if(_id==s)
                    return(i);
                i++;
                s=s->next;

            }
            return(-1);

        }

        pl3d_id find(l3d_uint n)
        {
            if(n<0 || n>_size)
                return l3d_null;
            pl3d_id ef=_first;
            l3d_uint ix=0;

            while(ix++ != n && ef)
                ef=ef->next;

            if(ef)
                return ef;

            return l3d_null;



        }
        pl3d_id find_next_type(l3d_idtype _type,pl3d_id _e)
        {
            if(!_e)
                return(l3d_null);

        }

        pl3d_id find_type(l3d_idtype _type,l3d_uint n)
        {
            pl3d_id _e=find_first_type(_type);

            if(!_e)
                return(l3d_null);

            if(n<0 || n>_size)
                return l3d_null;


            l3d_uint ix=0;

            while(ix++ != n && _e)
                _e=_e->next_type;

            if(_e)
                return _e;

            return l3d_null;



        }
        pl3d_id find_last_type(l3d_idtype _type)
        {
            pl3d_id  last_type=_last;

            while(last_type && last_type->_type!=_type)
                    last_type=last_type->prev;

            if(last_type)
                return(last_type);
            else
                return(l3d_null);


        }
        pl3d_id find_first_type(l3d_idtype _type)
        {
            pl3d_id  first_type=_first;

            if(!_first)
                return l3d_null;
            while(first_type)
                if(first_type->_type!=_type)
                    first_type=first_type->next;
                else
                    break;

            if(first_type)
                return(first_type);
            else
                return(l3d_null);


        }


        l3d_bool empty()
        {
            return(_first==_last && _size==0);

        }
        void clear()
        {
            pl3d_id e=_last,ep;

            while(e)
            {
                ep=e;

                e=e->prev;

                e->next=l3d_null;


                ep->next=l3d_null;
                ep->prev=l3d_null;
                ep->next_type=l3d_null;
                ep->prev_type=l3d_null;

                if(ep->object!=l3d_null)
                    delete(ep->object);

                delete(ep);


            }


        }

    }l3d_id_list,*pl3d_id_list;

}



#endif // L3D_ID_H
