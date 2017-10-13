#ifndef L3D_ID_PICKING_H
#define L3D_ID_PICKING_H
#include "l3d_include.h"

namespace l3d
{
    typedef struct _id_picking
    {
        l3d_bool _selected;
        l3d_uint _iname;

        void selected(l3d_bool s)
        {
            _selected=s;

        }

        l3d_bool selected()
        {
            return (_selected);
        }

    }l3d_id_picking,*pl3d_id_picking;


}





#endif // L3D_ID_PICKING_H
