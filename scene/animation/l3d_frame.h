#ifndef L3D_FRAME_H
#define L3D_FRAME_H

#include "../../mesh/l3d_action.h"


namespace l3d
{
    using namespace vertex3f;

    typedef struct l3d_action_list_struct
    {
        pl3d_action _action;
        l3d_action_list_struct* next;

    }l3d_action_list,*pl3d_action_list;

    typedef struct l3d_frame_struct
    {
        pl3d_action_list _first;
        pl3d_action_list _list;
        l3d_int16 _size;

        void init()
        {
            _first=l3d_null;
            _list=l3d_null;
            _size=0;
        }

        void addaction(pl3d_action _action)
        {
            if(_size==0)
            {
                _list=(pl3d_action_list)::malloc(sizeof(l3d_action_list));

                _first=_list;
                _list->_action=_action;
                _list->next=l3d_null;
            }
            else
            {
                pl3d_action_list applist=_first;

                while(applist->next!=l3d_null)
                    applist=applist->next;

                applist->next=(pl3d_action_list)::malloc(sizeof(l3d_action_list));
                applist=applist->next;
                applist->_action=_action;
                applist->next=l3d_null;
            }

            _size++;
        }
        void delaction(l3d_int16 index)
        {
            if(_size==0)
                return;

            l3d_int16 count=0;
            pl3d_action_list applist=_first;
            pl3d_action_list applist2=applist;
            pl3d_action_list applist3=applist;

            while(count++<index && applist)
            {
                applist3=applist2;
                applist2=applist;
                applist=applist->next;
            }

            if(applist)
            {
                if(applist2)
                {
                    applist3->next=applist;
                    ::free((void*)applist2);
                    _size--;
                }
            }
            else if (applist2)
            {
                _size--;
                ::free(applist2);
                if(applist3)
                    applist3->next=l3d_null;

            }



        }



    }l3d_frame,*pl3d_frame;
    typedef struct _l3d_frame_ele
    {
        pl3d_frame _frame;
        _l3d_frame_ele * _next;
    }l3d_frame_ele,*pl3d_frame_ele;
    typedef struct _l3d_frame_list
    {
        pl3d_frame_ele _first;
        pl3d_frame_ele _last;
        l3d_uint _size;
        void init()
        {
            _size=-1;
            _first=l3d_null;
            _last=l3d_null;
        }

        void add(pl3d_frame _nframe)
        {



        }
        pl3d_frame get(l3d_uint x)
        {

        }

        l3d_uint size()
        {
            return(_size);
        }
    }l3d_frame_list,*pl3d_frame_list;
}

#endif // L3D_FRAME_H
