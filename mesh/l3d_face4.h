#ifndef L3D_FACE4_H
#define L3D_FACE4_H
#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_face3.h"
#include "l3d_line.h"

namespace l3d
{
    using namespace vertex3f;
    using namespace edge;
    using namespace face3;
    namespace face4
    {
    enum l3d_list_type
    {
        uplist=0,
        downlist=1,
        sinlist=2,
        deslist=3,

        lastlist=10000
    };

    enum l3d_quad_insert
    {
        //a----b
        //|    |
        //|    |
        //c----d

        abcdCW =0,
        abdcCW =1,
        badcCW =2,
        bacdCW =3,
        dcbaCW =4,
        dcabCW =5,

        abcdCCW =6,
        abdcCCW =7,
        badcCCW =8,
        bacdCCW =9,
        dcbaCCW =10,
        dcabCCW =11,


        last_quad=200

    };
        typedef struct _face4
        {
            _face4 * next;
            _face4 * prev;

            pl3d_line_struct _l0;
            pl3d_line_struct _l1;
            pl3d_line_struct _l2;
            pl3d_line_struct _l3;
            pl3d_line_struct _lf;

            pl3d_vertex_fast _pv0;
            pl3d_vertex_fast _pv1;
            pl3d_vertex_fast _pv2;
            pl3d_vertex_fast _pv3;

            pl3d_face3_struct _f0;
            pl3d_face3_struct _f1;

            l3d_uint _v0,_v1,_v2,_v3;

            l3d_uint f0,f1;

            l3d_uint l0,l1,l2,l3,l4;

            l3d_uint l[5];
            l3d_double u[4],v[4];

            l3d_bool _selected;
            l3d_bool _erase;
            l3d_uint _iname;

            l3d_quad_insert _insert;

            l3d_vertex_fast scalevertex;

            //liste per estrusione e altre azioni sui quad
            pl3d_list_int list_up;
            l3d_uint up_size;

            pl3d_list_int list_down;
            l3d_uint down_size;

            pl3d_list_int list_sin;
            l3d_uint sin_size;

            pl3d_list_int list_des;
            l3d_uint des_size;



            //funzioni per gestire le liste

            //restituiscono il numero di elementi delle liste
            l3d_uint upsize()
            {
                return (up_size);

            }
            l3d_uint downsize()
            {
                return (down_size);

            }
            l3d_uint sinsize()
            {
                return (sin_size);

            }
            l3d_uint dessize()
            {
                return (des_size);

            }
            //aggiungono un elemento

            l3d_uint add_up(l3d_uint value)
            {
                if(up_size==0)
                {
                    list_up= new l3d_list_int;

                    list_up->info=value;

                    list_up->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_up;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=value;
                    app->next->next=l3d_null;

                }
                up_size++;


            }
            l3d_uint add_down(l3d_uint value)
            {
                if(down_size==0)
                {
                    list_down= new l3d_list_int;

                    list_down->info=value;

                    list_down->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_down;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=value;
                    app->next->next=l3d_null;

                }
                down_size++;

            }
            l3d_uint add_sin(l3d_uint value)
            {
                if(sin_size==0)
                {
                    list_sin= new l3d_list_int;

                    list_sin->info=value;

                    list_sin->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_sin;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=value;
                    app->next->next=l3d_null;

                }
                sin_size++;

            }
            l3d_uint add_des(l3d_uint value)
            {
                if(des_size==0)
                {
                    list_des= new l3d_list_int;

                    list_des->info=value;

                    list_des->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=list_des;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=value;
                    app->next->next=l3d_null;

                }
                des_size++;

            }
            //aggiunge un elemento ad una lista in base a _list
            void add_list(l3d_list_type _list,l3d_uint value)
            {
                l3d_uint size=0;
                pl3d_list_int plist=l3d_null;

                switch(_list)
                {
                case uplist:
                    size=up_size;
                    plist=list_up;
                    break;
                case downlist:
                    size=down_size;
                    plist=list_down;
                    break;
                case sinlist:
                    size=sin_size;
                    plist=list_sin;
                    break;
                case deslist:
                    size=des_size;
                    plist=list_des;
                    break;

                }
                if(!plist)
                    return;

                if(size==0)
                {
                    plist= new l3d_list_int;

                    plist->info=value;

                    plist->next=l3d_null;

                }
                else
                    {
                    pl3d_list_int app=plist;

                    while(app->next)
                        app=app->next;

                    app->next=new l3d_list_int;
                    app->next->info=value;
                    app->next->next=l3d_null;

                }

                switch(_list)
                {
                case 0:
                    up_size++;

                    break;
                case 1:
                    down_size++;

                    break;
                case 2:
                    sin_size++;

                    break;
                case 3:
                    des_size++;

                    break;


                }

            }
            //funzioni per cancellare le liste del quad

            void del_list(l3d_list_type _list, l3d_uint value)
            {
                l3d_uint size=0;
                pl3d_list_int plist=l3d_null;

                switch(_list)
                {
                case uplist:
                    size=up_size;
                    plist=list_up;
                    break;
                case downlist:
                    size=down_size;
                    plist=list_down;
                    break;
                case sinlist:
                    size=sin_size;
                    plist=list_sin;
                    break;
                case deslist:
                    size=des_size;
                    plist=list_des;
                    break;

                }
                if(!plist)
                    return;


                if(size==0)
                    return;

                pl3d_list_int appl=plist,appl2=plist;

                if(value==0)
                {
                    plist=plist->next;
                    delete(appl2);

                }
                else

                {
                    int ix=0;

                    while(appl && ix++<(size-1))
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


                switch(_list)
                {
                case 0:
                    up_size--;

                    break;
                case 1:
                    down_size--;

                    break;
                case 2:
                    sin_size--;

                    break;
                case 3:
                    des_size--;

                    break;


                }
            }
            //inizializza le liste
            void init_lists()
            {
                up_size=down_size=sin_size=des_size=0;
                list_up=list_down=list_sin=list_des=l3d_null;
            }

            //funzione per cancellare tutte le liste del quad

            void clear_lists()
            {
                clear_list(uplist);
                clear_list(downlist);
                clear_list(sinlist);
                clear_list(deslist);

            }

            void clear_list(l3d_list_type _list)
            {
                l3d_uint size=0;
                pl3d_list_int plist=l3d_null;

                switch(_list)
                {
                case uplist:
                    size=up_size;
                    plist=list_up;
                    break;
                case downlist:
                    size=down_size;
                    plist=list_down;
                    break;
                case sinlist:
                    size=sin_size;
                    plist=list_sin;
                    break;
                case deslist:
                    size=des_size;
                    plist=list_des;
                    break;

                }
                if(!plist)
                    return;
                l3d_uint ic=0;
                pl3d_list_int appl=plist;
                while(ic++ < size && plist)
                {
                    plist=plist->next;
                    delete(appl);
                    appl=plist;

                }
                switch(_list)
                {
                case 0:
                    up_size=0;

                    break;
                case 1:
                    down_size=0;

                    break;
                case 2:
                    sin_size=0;

                    break;
                case 3:
                    des_size=0;

                    break;


                }
            }
            //funzione per prelevare un elemento nelle liste
            l3d_uint get_list(l3d_list_type _list, l3d_uint index)
            {
                l3d_uint size=0,ireturn=-1;
                pl3d_list_int plist=l3d_null;

                switch(_list)
                {
                case uplist:
                    size=up_size;
                    plist=list_up;
                    break;
                case downlist:
                    size=down_size;
                    plist=list_down;
                    break;
                case sinlist:
                    size=sin_size;
                    plist=list_sin;
                    break;
                case deslist:
                    size=des_size;
                    plist=list_des;
                    break;

                }

                if(!plist || (index<0 || index > size))
                    return(ireturn);


                pl3d_list_int appl=plist;
                l3d_uint ix=0;

                while(appl && ix++ < index)
                {
                    appl=appl->next;
                }

                if(appl)
                    ireturn=appl->info;


                return (ireturn);

            }

            _face4 operator=(const _face4& f)
            {

                next=f.next;
                prev=f.prev;

                list_up=f.list_up;
                list_down=f.list_down;
                list_sin=f.list_sin;
                list_des=f.list_des;

                up_size=f.up_size;
                down_size=f.down_size;
                sin_size=f.sin_size;
                des_size=f.des_size;

                _v0=f._v0;
                _v1=f._v1;
                _v2=f._v2;
                _v3=f._v3;

                _pv0=f._pv0;
                _pv1=f._pv1;
                _pv2=f._pv2;
                _pv3=f._pv3;

                _f0=f._f0;
                _f1=f._f1;

                f0=f.f0;
                f1=f.f1;

                _selected=f._selected;
                _erase=f._erase;


                _l0=f._l0;
                _l1=f._l1;
                _l2=f._l2;
                _l3=f._l3;
                _lf=f._lf;

                l0=f.l0;
                l1=f.l1;
                l2=f.l2;
                l3=f.l3;
                l4=f.l4;

                _insert=f._insert;

                scalevertex=f.scalevertex;

            }

            void set_edges(l3d_uint l0,l3d_uint l1,l3d_uint l2,l3d_uint l3)
            {
                l[0]=l0;
                l[1]=l1;
                l[2]=l2;
                l[3]=l3;



            }
            void set_edges(pl3d_line_struct l0,pl3d_line_struct l1,pl3d_line_struct l2,pl3d_line_struct l3)
            {
                _l0=l0;
                _l1=l1;
                _l2=l2;
                _l3=l3;



            }

            l3d_uint get(l3d_uint index)
            {
                l3d_uint v;
                switch(index)
                {
                case 0:v=_v0;
                    break;
                case 1:v=_v1;
                    break;
                case 2:v=_v2;
                    break;
                case 3:v=_v3;
                    break;
                }

                return v;
            }
            l3d_bool selected()
            {
                return(_selected);
            }

            void selected(l3d_bool val)
            {
                _selected=val;

                _pv0->selected(val);
                _pv1->selected(val);
                _pv2->selected(val);
                _pv3->selected(val);

                _l0->selected(val);
                _l1->selected(val);
                _l2->selected(val);
                _l3->selected(val);



            }

            void purge()
            {
                _l0=_l1=_l2=_l3=NULL;
                _pv0=_pv1=_pv2=_pv3=NULL;
                _f0=_f1=NULL;

            }
            void invertdraw()
            {


            }

            void serialize(std::ifstream *ar)
            {
                if(ar->is_open())
                {
                    ar->read((char*)&_v0,sizeof(l3d_uint));
                    ar->read((char*)&_v1,sizeof(l3d_uint));
                    ar->read((char*)&_v2,sizeof(l3d_uint));
                    ar->read((char*)&_v3,sizeof(l3d_uint));

                    ar->read((char*)&l0,sizeof(l3d_uint));
                    ar->read((char*)&l1,sizeof(l3d_uint));
                    ar->read((char*)&l2,sizeof(l3d_uint));
                    ar->read((char*)&l3,sizeof(l3d_uint));
                    ar->read((char*)&l4,sizeof(l3d_uint));

                    ar->read((char*)&f0,sizeof(l3d_uint));
                    ar->read((char*)&f1,sizeof(l3d_uint));

                    ar->read((char*)&u,sizeof(l3d_double)*4);
                    ar->read((char*)&v,sizeof(l3d_double)*4);

                    ar->read((char*)&_selected,sizeof(l3d_bool));
                    ar->read((char*)&_erase,sizeof(l3d_bool));

                    ar->read((char*)&_insert,sizeof(l3d_quad_insert));

                }
                else
                {



                }

            }
            void serialize(std::ofstream *ar)
            {
                if(ar->is_open())
                {


                    /*

            l3d_uint _v0,_v1,_v2,_v3;

            l3d_uint f0,f1;

            l3d_uint l0,l1,l2,l3,l4;

            l3d_uint l[5];
            l3d_double u[4],v[4];

            l3d_bool _selected;
            l3d_bool _erase;
            l3d_uint _iname;

            l3d_quad_insert _insert;

                    */
                    ar->write((char*)&_v0,sizeof(l3d_uint));
                    ar->write((char*)&_v1,sizeof(l3d_uint));
                    ar->write((char*)&_v2,sizeof(l3d_uint));
                    ar->write((char*)&_v3,sizeof(l3d_uint));

                    ar->write((char*)&l0,sizeof(l3d_uint));
                    ar->write((char*)&l1,sizeof(l3d_uint));
                    ar->write((char*)&l2,sizeof(l3d_uint));
                    ar->write((char*)&l3,sizeof(l3d_uint));
                    ar->write((char*)&l4,sizeof(l3d_uint));

                    ar->write((char*)&f0,sizeof(l3d_uint));
                    ar->write((char*)&f1,sizeof(l3d_uint));

                    ar->write((char*)&u,sizeof(l3d_double)*4);
                    ar->write((char*)&v,sizeof(l3d_double)*4);

                    ar->write((char*)&_selected,sizeof(l3d_bool));
                    ar->write((char*)&_erase,sizeof(l3d_bool));

                    ar->write((char*)&_insert,sizeof(l3d_quad_insert));





                }
                else
                {



                }

            }


        }l3d_face4_struct,*pl3d_face4_struct;

        class l3d_face4
        {
        private:
            pl3d_face4_struct _first;
            pl3d_face4_struct _last;
            l3d_uint _nfaces;
        public:
            l3d_face4();
            l3d_face4(pl3d_face4_struct faces,l3d_uint nfaces);
            l3d_bool isfirst();
            void add(pl3d_face4_struct face);
            void del(l3d_uint index);
            void clear();
            int size();
            pl3d_face4_struct find(l3d_uint index);
            pl3d_face4_struct first();

        };
    }
}

#endif // L3D_FACE4_H
