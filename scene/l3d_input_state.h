#ifndef L3D_INPUT_STATE_H
#define L3D_INPUT_STATE_H

#include "mesh/l3d_vertex.h"

using namespace l3d::vertex3f;

enum MouseMoviment
{
    mouse_xzy=1,
    mouse_xyz=2,
    mouse_yxz=3,
    mouse_yzx=4,
    mouse_zxy=5,
    mouse_zyx=6,
    mouse_last=10000
};


typedef struct _l3d_input_state
{
    l3d_vertex_fast _offset;
    l3d_double _offsetval;

    l3d_bool _scale,_rotate,_move;
    l3d_bool _scalevertex,_rotatevertex,_movevertex;

    l3d_uint _rotatexyz;
    l3d_bool _movemesh[3];

    l3d_bool _scalewhere[4],_rotatewhere[4],_movewhere[4];
    l3d_bool _scalevertex_where[4],_rotatevertex_where[4],_movevertex_where[4];


    l3d_bool _shift;
    l3d_bool _ctrl;
    l3d_bool _alt;

    l3d_bool _isupdown,_isleftright,_isfrontback;
    MouseMoviment _mouse_move;

    void init_clean()
    {
        //_shift=false; ?? is correct?
        //_isupdown=false; ?? is correct?
        _ctrl=false;
        //_alt=false;
        _rotatexyz=-1;
        //_isleftright=false;

        _movemesh[0]=false;
        _movemesh[1]=false;
        _movemesh[2]=false;
        _offset.set(0.0F,0.0F,0.0F);
        _offsetval=1.0F;
        _scale=_rotate=_move=false;
        _scalevertex=_rotatevertex=_movevertex=false;

        for(int ix=0; ix < 4; ix++)
        {
            _scalewhere[ix]=_rotatewhere[ix]=_movewhere[ix]=false;
            _scalevertex_where[ix]=_rotatevertex_where[ix]=_movevertex_where[ix]=false;
        }
    }
    void move_mesh(l3d_bool _val,l3d_uint _im)
    {
        if(_im>=0 && _im<=2)
            _movemesh[_im]=_val;

    }

    l3d_bool isnot_movevertex()
    {
        return((!_movevertex_where[0] && !_movevertex_where[1] && !_movevertex_where[2]	));
    }
    l3d_bool is_movevertex()
    {
        return((_movevertex_where[0] || _movevertex_where[1] || _movevertex_where[2]	));
    }

    void set_offset(l3d_double _val)
    {
        _offsetval=_val;
    }

    void scale(l3d_bool _val,l3d_uint _p)
    {
        _scale=_val;
        if(_p>=0 && _p<4)
            _scalewhere[_p]=true;

    }
    void rotate(l3d_bool _val,l3d_uint _p)
    {
        _rotate=_val;
        if(_p>=0 && _p<4)
            _rotatewhere[_p]=true;

    }
    void move(l3d_bool _val,l3d_uint _p)
    {
        _move=_val;
        if(_p>=0 && _p<4)
        {
            _movewhere[_p]=true;
            _movemesh[_p]=true;

        }


    }
    void scale_vertex(l3d_bool _val,l3d_uint _p)
    {
        _scalevertex=_val;
        if(_p>=0 && _p<4)
            _scalevertex_where[_p]=true;

    }
    void rotate_vertex(l3d_bool _val,l3d_uint _p)
    {
        _rotatevertex=_val;
        if(_p>=0 && _p<4)
            _rotatevertex_where[_p]=true;

    }
    void move_vertex(l3d_bool _val,l3d_uint _p)
    {
        _movevertex=_val;
        if(_p>=0 && _p<4)
            _movevertex_where[_p]=true;

    }

    void addx(l3d_double _val)
    {
        if(!_shift)
            _offset.x+=_val;
        else
            _offset.x+=(_val/10.0F);

    }
    void addy(l3d_double _val)
    {
        if(!_shift)
            _offset.y+=_val;
        else
            _offset.y+=(_val/10.0F);
    }
    void addz(l3d_double _val)
    {
        if(!_shift)
            _offset.z+=_val;
        else
            _offset.z+=(_val/10.0F);
    }
    void addx()
    {
        if(_shift)
            _offset.x+=(_offsetval/10.0F);
        else
            _offset.x+=_offsetval;
    }
    void addy()
    {
        if(_shift)
            _offset.y+=(_offsetval/10.0F);
        else
            _offset.y+=_offsetval;
    }
    void addz()
    {
        if(_shift)
            _offset.z+=(_offsetval/10.0F);
        else
            _offset.z+=_offsetval;
    }

    void remx()
    {
        if(_shift)
            _offset.x-=(_offsetval/10.0F);
        else
            _offset.x-=_offsetval;
    }
    void remy()
    {
        if(_shift)
            _offset.y-=(_offsetval/10.0F);
        else
            _offset.y-=_offsetval;
    }
    void remz()
    {
        if(_shift)
            _offset.z-=(_offsetval/10.0F);
        else
            _offset.z-=_offsetval;
    }


}l3d_input_state,*pl3d_input_state;


#endif // L3D_INPUT_STATE_H
