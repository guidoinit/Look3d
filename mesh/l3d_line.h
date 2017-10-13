#ifndef L3D_LINE_H
#define L3D_LINE_H


#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_list.h"

namespace l3d
{
    using namespace vertex3f;
    namespace edge
    {


        typedef struct _l3d_line_fast
        {
            /*_l3d_line_fast(l3d_uint l0,l3d_uint l1)
            {
                v0=l0;
                v1=l1;
            }*/

            _l3d_line_fast * next;
            _l3d_line_fast * prev;

            pl3d_list_int list_next;
            l3d_uint next_size;

            pl3d_list_int list_prev;
            l3d_uint prev_size;




            l3d_uint v0;
            l3d_uint v1;

            l3d_uint iname;

            l3d_bool _selected,erase;

            pl3d_vertex_fast _v0;
            pl3d_vertex_fast _v1;

            _l3d_line_fast operator=(const _l3d_line_fast& l)
            {
                next=l.next;
                prev=l.prev;
                v0=l.v0;
                v1=l.v1;
                _v0=l._v0;
                _v1=l._v1;

                _selected=l._selected;
                erase=l.erase;

            }

            void purge()
            {
                next=prev=NULL;
                _v0=_v1=NULL;
            }
            void serialize(std::ifstream *ar)
            {
                if(ar->is_open())
                {
                    ar->read((char*)&v0,sizeof(l3d_uint));
                    ar->read((char*)&v1,sizeof(l3d_uint));

                    ar->read((char*)&erase,sizeof(l3d_bool));

                    _selected=false;

                    next=prev=l3d_null;

                    iname=-1;

                    _v0=_v1=l3d_null;

                }
                else
                {



                }

            }
            void serialize(std::ofstream *ar)
            {
                if(ar->is_open())
                {
                    //ar->write((char*)this,sizeof(_l3d_line_fast));


                    ar->write((char*)&v0,sizeof(l3d_uint));
                    ar->write((char*)&v1,sizeof(l3d_uint));

                    ar->write((char*)&erase,sizeof(l3d_bool));




                }
                else
                {



                }

            }
            void selected(l3d_bool v)
            {
                _selected=v;
            }
            l3d_bool selected()
            {
                return _selected;
            }

            l3d_uint nextsize()
            {
                return (next_size);

            }
            l3d_uint prevsize()
            {
                return(prev_size);
            }
            void delnext(l3d_uint x)
            {
                if(next_size==0)
                    return;
                pl3d_list_int appl=list_next,appl2;
                if(x==0)
                {
                    list_next=list_next->next;
                    delete(appl);

                }
                else
                    {
                    int ix=0;

                    while(appl && ix++<(x-1))
                    {
                        appl2=appl;
                        appl=appl->next;
                    }

                    if(appl)
                    {
                        appl2->next=appl->next;
                        delete(appl);

                    }



                }


                next_size--;
            }
            void delprev(l3d_uint x)
            {
                if(prev_size==0)
                    return;
                pl3d_list_int appl=list_prev,appl2;
                if(x==0)
                {
                    list_prev=list_prev->next;
                    delete(appl);

                }
                else
                    {
                    int ix=0;

                    while(appl && ix++<(x-1))
                    {
                        appl2=appl;
                        appl=appl->next;
                    }

                    if(appl)
                    {
                        appl2->next=appl->next;
                        delete(appl);

                    }



                }


                prev_size--;
            }

            l3d_uint getnext(l3d_uint x)
            {
                if(x<0 || x > next_size)
                    return(-1);
                pl3d_list_int appl=list_next;
                l3d_uint ix=0;
                while(appl && ix++ < x)
                {
                    appl=appl->next;
                }
                if(appl)
                    return(appl->info);
                else
                    return (-1);


            }
            l3d_uint getprev(l3d_uint x)
            {
                if(x<0 || x > prev_size)
                    return(-1);

                pl3d_list_int appl=list_prev;
                l3d_uint ix=0;
                while(appl && ix++ < x)
                {
                    appl=appl->next;
                }
                if(appl)
                    return(appl->info);
                else
                    return (-1);

            }
            void clear_np()
            {


                pl3d_list_int appn,appn2;

                if(next_size==1)
                {
                    delete list_next;
                    list_next=l3d_null;
                    next_size=0;
                }
                else if(next_size > 1)
                {
                    appn=list_next;
                    appn2=appn->next;

                    while(appn2)
                    {
                        appn->next=l3d_null;
                        delete(appn);

                        appn=appn2;
                        appn2=appn2->next;
                    }

                }

                if(prev_size==1)
                {
                    delete list_prev;
                    list_prev=l3d_null;
                    prev_size=0;
                }
                else if(prev_size > 1)
                {
                    appn=list_prev;
                    appn2=appn->next;

                    while(appn2)
                    {
                        appn->next=l3d_null;
                        delete(appn);

                        appn=appn2;
                        appn2=appn2->next;
                    }

                }



                prev_size=0;
                next_size=0;
                list_next=l3d_null;
                list_prev=l3d_null;

            }
            void addprev(l3d_uint p)
            {
                if(prev_size==0)
                {
                    list_prev= new l3d_list_int;

                    list_prev->info=p;

                    list_prev->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_prev;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=p;
                    app->next->next=l3d_null;

                }

                prev_size++;



            }
            void addnext(l3d_uint n)
            {
                if(next_size==0)
                {
                    list_next= new l3d_list_int;

                    list_next->info=n;

                    list_next->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_next;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=n;
                    app->next->next=l3d_null;

                }
                next_size++;

            }


        }l3d_line_struct,*pl3d_line_struct;

        class l3d_line
        {
        private:
            pl3d_line_struct _first;
            pl3d_line_struct _last;

            l3d_uint _nlines;

        public:
            l3d_line();
            l3d_line(pl3d_line_struct first,l3d_uint nlines);

            void add(pl3d_line_struct line);
            void del(l3d_uint index);
            void del(pl3d_line_struct l);
            void clear();
            l3d_uint size();

            pl3d_line_struct find(l3d_uint index);
            pl3d_line_struct find(l3d_uint v0,l3d_uint v1);
            l3d_uint findindex(l3d_uint v0,l3d_uint v1);
            l3d_uint index(l3d_uint v0,l3d_uint v1);
            pl3d_line_struct first();
            l3d_bool isfirst();

        };

    }

}


#endif // L3D_LINE_H
