#ifndef L3D_FACE3_H
#define L3D_FACE3_H
#include "l3d_include.h"
#include "l3d_vertex.h"
#include "l3d_line.h"


namespace l3d
{
    using namespace vertex3f;
    using namespace edge;
    namespace face3
    {
    enum l3d_face_insert
    {
        //a----b
        //|   /
        //|  /
        //| /
        //|/
        //c

        abcCW =0,
        bcaCW =1,
        cabCW =2,
        acbCW =3,
        cbaCW =4,
        bacCW =5,

        abcCCW =6,
        bcaCCW =7,
        cabCCW =8,
        acbCCW =9,
        cbaCCW =10,
        bacCCW =11,


        last_face=200

    };
        typedef struct _face3
        {
            _face3 * next;
            _face3 * prev;

            pl3d_line_struct _l0;
            pl3d_line_struct _l1;
            pl3d_line_struct _l2;

            pl3d_vertex_fast _pv0;
            pl3d_vertex_fast _pv1;
            pl3d_vertex_fast _pv2;

            l3d_vertex_fast _normal;

            l3d_uint v0,v1,v2;
            l3d_uint l0,l1,l2;

            l3d_bool _selected;
            l3d_bool _erase;
            l3d_uint _iname;
            l3d_bool _alone;

            l3d_face_insert _insert;

            l3d_uint get(l3d_uint n)
            {
                switch(n)
                {
                case 0:return(v0);
                    break;
                case 1:return(v1);
                    break;
                case 2:return(v2);
                    break;

                }
                return(-1);
            }

            _face3 operator=(const _face3& f)
            {
                next=f.next;
                prev=f.prev;

                v0=f.v0;
                v1=f.v1;
                v2=f.v2;

                _selected=f._selected;
                _erase=f._erase;
                _alone=f._alone;
                _insert=f._insert;

                _l0=f._l0;
                _l1=f._l1;
                _l2=f._l2;

                _pv0=f._pv0;
                _pv1=f._pv1;
                _pv2=f._pv2;

                _normal=f._normal;



            }

            void selected(l3d_bool val)
            {
                _selected=val;
            }
            void purge()
            {
                next=prev=NULL;
                _l0=_l1=_l2=NULL;
                _pv0=_pv1=_pv2=NULL;
            }
            void serialize(std::ifstream *ar)
            {
                if(ar->is_open())
                {
                    ar->read((char*)&v0,sizeof(l3d_uint));
                    ar->read((char*)&v1,sizeof(l3d_uint));
                    ar->read((char*)&v2,sizeof(l3d_uint));

                    ar->read((char*)&l0,sizeof(l3d_uint));
                    ar->read((char*)&l1,sizeof(l3d_uint));
                    ar->read((char*)&l2,sizeof(l3d_uint));

                    _normal.serialize(ar);

                    ar->read((char*)&_erase,sizeof(l3d_bool));
                    ar->read((char*)&_alone,sizeof(l3d_bool));
                    ar->read((char*)&_selected,sizeof(l3d_bool));

                    ar->read((char*)&_insert,sizeof(l3d_face_insert));

                }
                else
                {



                }

            }
            void serialize(std::ofstream *ar)
            {
                if(ar->is_open())
                {


                    ar->write((char*)&v0,sizeof(l3d_uint));
                    ar->write((char*)&v1,sizeof(l3d_uint));
                    ar->write((char*)&v2,sizeof(l3d_uint));

                    ar->write((char*)&l0,sizeof(l3d_uint));
                    ar->write((char*)&l1,sizeof(l3d_uint));
                    ar->write((char*)&l2,sizeof(l3d_uint));

                    _normal.serialize(ar);

                    ar->write((char*)&_erase,sizeof(l3d_bool));
                    ar->write((char*)&_alone,sizeof(l3d_bool));
                    ar->write((char*)&_selected,sizeof(l3d_bool));

                    ar->write((char*)&_insert,sizeof(l3d_face_insert));







                    /*

                    (*ar) >> x;

                    (*ar) >> y;

                    (*ar) >> z;

                    (*ar) >> m_imaterial;*/

                }
                else
                {



                }

            }

        }l3d_face3_struct,*pl3d_face3_struct;

        class l3d_face3
        {
        private:
            pl3d_face3_struct _first;
            pl3d_face3_struct _last;
            l3d_uint _nfaces;
        public:
            l3d_face3();
            l3d_face3(pl3d_face3_struct faces,l3d_uint nfaces);
            l3d_bool isfirst();
            void add(pl3d_face3_struct face);
            void del(l3d_uint index);
            void clear();
            pl3d_face3_struct find(l3d_uint index);
            pl3d_face3_struct first();
            l3d_uint size();

        };
    }
}

#endif // L3D_FACE3_H
