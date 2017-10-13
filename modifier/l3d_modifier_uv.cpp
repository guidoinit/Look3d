#include "l3d_modifier_uv.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_uv.h"
#include "mesh/l3d_mesh.h"

using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;


l3d_modifier_uv::l3d_modifier_uv()
{
}

l3d_modifier_uv::l3d_modifier_uv(pl3d_mesh_struct _m,ALG_UV _a)
{
    _mesh=_m;
    _alg=_a;
}

void l3d_modifier_uv::make()
{
    if(!_mesh)
        return;
    switch(_alg)
    {
    case normal:
        poligonal();
        break;
    case poligonalinx:
        poligonal_x();
        break;
    case poligonaliny:
        poligonal_y();
        break;
    case poligonalinz:
        poligonal_z();
        break;
    case poligonalinx_move:
        poligonal_x_move();
        break;
    }

}

void l3d_modifier_uv::make(pl3d_mesh_struct _m, ALG_UV _a)
{
    _mesh=_m;
    _alg=_a;

    make();


}

void l3d_modifier_uv::poligonal()
{
    _mesh->_uv.clear();
    pl3d_face4_struct _q=_mesh->_quad.first();

    _mesh->_uv.clear();
    l3d_uint _qcont=0;
    while(_q)
    {
        pl3d_uv_struct puv0=new l3d_uv_struct;

        l3d_uint a,b,c,d;
        l3d_double u[4],v[4];

        //a----b
        //|    |
        //|    |
        //c----d
        //
        //a=1,1
        //b=0,1
        //c=1,0
        //d=0,0

        switch(_q->_insert)
        {
        case abcdCW:
            a=_q->_v0;
            b=_q->_v1;
            c=_q->_v2;
            d=_q->_v3;
            //d----c
            //|    |
            //|    |
            //a----b

            //d=0,0
            //c=0,1
            //b=1,1
            //a=1,0

            u[0]=1.0F;//a
            u[1]=0.0F;//b
            u[2]=1.0F;//c
            u[3]=0.0F;//d

            v[0]=0.0F;//a
            v[1]=1.0F;//b
            v[2]=1.0F;//c
            v[3]=0.0F;//d
            break;
        case abcdCCW:
            a=_q->_v0;
            b=_q->_v1;
            c=_q->_v2;
            d=_q->_v3;

            u[0]=1.0F;
            u[1]=0.0F;
            u[2]=1.0F;
            u[3]=0.0F;

            v[0]=1.0F;
            v[1]=1.0F;
            v[2]=0.0F;
            v[3]=0.0F;
            break;
        }


        puv0->u=u[0];
        puv0->v=v[0];
        puv0->_index_vertex=a;
        puv0->_index_quad=_qcont;
        puv0->_index_triangle=-1;

        _mesh->_uv.add(puv0);

        pl3d_uv_struct puv1=new l3d_uv_struct;

        puv1->u=u[1];
        puv1->v=v[1];
        puv1->_index_vertex=b;
        puv1->_index_quad=_qcont;
        puv1->_index_triangle=-1;

        _mesh->_uv.add(puv1);

        pl3d_uv_struct puv2=new l3d_uv_struct;

        puv2->u=u[2];
        puv2->v=v[2];
        puv2->_index_vertex=c;
        puv2->_index_quad=_qcont;
        puv2->_index_triangle=-1;

        _mesh->_uv.add(puv2);

        pl3d_uv_struct puv3=new l3d_uv_struct;

        puv3->u=u[3];
        puv3->v=v[3];
        puv3->_index_vertex=d;
        puv3->_index_quad=_qcont;
        puv3->_index_triangle=-1;

        _mesh->_uv.add(puv3);


        _qcont++;
        _q=_q->next;
    }

}
void l3d_modifier_uv::poligonal_x_move()
{

    _mesh->_uv.clear();
    //1. trovare il valore in x maggiore

    pl3d_vertex_fast f= _mesh->_vertex.first();
    l3d_float maxx=0,scalex,maxz=0,scalez;
    while(f)
    {
        if(f->x>maxx)
            maxx=f->x;
        if(f->z>maxz)
            maxz=f->z;
        f=f->next;
    }

    //2. scalarlo

    scalex=1.0/maxx;
    scalez=1.0F/maxz;

    //3. assegnare i valori u,v dividendo la mesh in due

    pl3d_face4_struct q=_mesh->_quad.first();
    l3d_uint _index=0;
    while(q)
    {
        pl3d_uv_struct _uv=new l3d_uv_struct;

        if(q->_pv0->x < 0.0F)
            _uv->u=q->_pv0->x*scalex;

        _uv->v=q->_pv0->z*scalez;

        _uv->_index_quad=_index;
        _uv->_index_vertex=q->_v0;
        _uv->_index_triangle=-1;

        _mesh->_uv.add(_uv);



        pl3d_uv_struct _uv1=new l3d_uv_struct;

        _uv1->u=q->_pv1->y*scalex;

        _uv1->v=q->_pv1->z*scalez;

        _uv1->_index_quad=_index;
        _uv1->_index_vertex=q->_v1;
        _uv1->_index_triangle=-1;

        _mesh->_uv.add(_uv1);

        pl3d_uv_struct _uv2=new l3d_uv_struct;

        _uv2->u=q->_pv2->y*scalex;

        _uv2->v=q->_pv2->z*scalez;

        _uv2->_index_quad=_index;
        _uv2->_index_vertex=q->_v2;
        _uv2->_index_triangle=-1;

        _mesh->_uv.add(_uv2);

        pl3d_uv_struct _uv3=new l3d_uv_struct;

        _uv3->u=q->_pv3->y*scalex;

        _uv3->v=q->_pv3->z*scalez;

        _uv3->_index_quad=_index++;
        _uv3->_index_vertex=q->_v3;
        _uv3->_index_triangle=-1;

        _mesh->_uv.add(_uv3);



        q=q->next;

    }

}
void l3d_modifier_uv::poligonal_x()
{

    _mesh->_uv.clear();
    //1. trovare il valore in x maggiore

    pl3d_vertex_fast f= _mesh->_vertex.first();
    l3d_float maxy=0,scaley,maxz=0,scalez;
    while(f)
    {
        if(f->y>maxy)
            maxy=f->x;
        if(f->z>maxz)
            maxz=f->z;
        f=f->next;
    }

    //2. scalarlo

    scaley=1.0/maxy;
    scalez=1.0F/maxz;

    //3. assegnare i valori u,v dividendo la mesh in due

    pl3d_face4_struct q=_mesh->_quad.first();
    l3d_uint _index=0;
    while(q)
    {
        pl3d_uv_struct _uv=new l3d_uv_struct;

        _uv->u=q->_pv0->y*scaley;

        _uv->v=q->_pv0->z*scalez;

        _uv->_index_quad=_index;
        _uv->_index_vertex=q->_v0;
        _uv->_index_triangle=-1;

        _mesh->_uv.add(_uv);



        pl3d_uv_struct _uv1=new l3d_uv_struct;

        _uv1->u=q->_pv1->y*scaley;

        _uv1->v=q->_pv1->z*scalez;

        _uv1->_index_quad=_index;
        _uv1->_index_vertex=q->_v1;
        _uv1->_index_triangle=-1;

        _mesh->_uv.add(_uv1);

        pl3d_uv_struct _uv2=new l3d_uv_struct;

        _uv2->u=q->_pv2->y*scaley;

        _uv2->v=q->_pv2->z*scalez;

        _uv2->_index_quad=_index;
        _uv2->_index_vertex=q->_v2;
        _uv2->_index_triangle=-1;

        _mesh->_uv.add(_uv2);

        pl3d_uv_struct _uv3=new l3d_uv_struct;

        _uv3->u=q->_pv3->y*scaley;

        _uv3->v=q->_pv3->z*scalez;

        _uv3->_index_quad=_index++;
        _uv3->_index_vertex=q->_v3;
        _uv3->_index_triangle=-1;

        _mesh->_uv.add(_uv3);



        q=q->next;

    }

}
void l3d_modifier_uv::poligonal_y()
{
    _mesh->_uv.clear();
    //1. trovare il valore in x maggiore
    pl3d_vertex_fast f= _mesh->_vertex.first();
    l3d_float maxx=0,scalex,maxz=0,scalez;
    while(f)
    {
        if(f->x>maxx)
            maxx=f->x;
        if(f->z>maxz)
            maxz=f->z;
        f=f->next;
    }
    //2. scalarlo
    scalex=1.0/maxx;
    scalez=1.0F/maxz;
    //3. assegnare i valori u,v dividendo la mesh in due
    pl3d_face4_struct q=_mesh->_quad.first();
    l3d_uint _index=0;
    while(q)
    {
        pl3d_uv_struct _uv=new l3d_uv_struct;

        _uv->u=q->_pv0->x*scalex;

        _uv->v=q->_pv0->z*scalez;

        _uv->_index_quad=_index;
        _uv->_index_vertex=q->_v0;
        _uv->_index_triangle=-1;

        _mesh->_uv.add(_uv);



        pl3d_uv_struct _uv1=new l3d_uv_struct;

        _uv1->u=q->_pv1->x*scalex;

        _uv1->v=q->_pv1->z*scalez;

        _uv1->_index_quad=_index;
        _uv1->_index_vertex=q->_v1;
        _uv1->_index_triangle=-1;

        _mesh->_uv.add(_uv1);

        pl3d_uv_struct _uv2=new l3d_uv_struct;

        _uv2->u=q->_pv2->x*scalex;

        _uv2->v=q->_pv2->z*scalez;

        _uv2->_index_quad=_index;
        _uv2->_index_vertex=q->_v2;
        _uv2->_index_triangle=-1;

        _mesh->_uv.add(_uv2);

        pl3d_uv_struct _uv3=new l3d_uv_struct;

        _uv3->u=q->_pv3->x*scalex;

        _uv3->v=q->_pv3->z*scalez;

        _uv3->_index_quad=_index++;
        _uv3->_index_vertex=q->_v3;
        _uv3->_index_triangle=-1;

        _mesh->_uv.add(_uv3);



        q=q->next;

    }

}
void l3d_modifier_uv::poligonal_z()
{
    _mesh->_uv.clear();
    //1. trovare il valore in x maggiore
    pl3d_vertex_fast f= _mesh->_vertex.first();
    l3d_float maxx=0,scalex,maxy=0,scaley;
    while(f)
    {
        if(f->x>maxx)
            maxx=f->x;
        if(f->y>maxy)
            maxy=f->y;
        f=f->next;
    }
    //2. scalarlo
    scalex=1.0/maxx;
    scaley=1.0F/maxy;
    //3. assegnare i valori u,v dividendo la mesh in due
    pl3d_face4_struct q=_mesh->_quad.first();
    l3d_uint _index=0;
    while(q)
    {
        pl3d_uv_struct _uv=new l3d_uv_struct;

        _uv->u=q->_pv0->x*scalex;

        _uv->v=q->_pv0->y*scaley;

        _uv->_index_quad=_index;
        _uv->_index_vertex=q->_v0;
        _uv->_index_triangle=-1;

        _mesh->_uv.add(_uv);



        pl3d_uv_struct _uv1=new l3d_uv_struct;

        _uv1->u=q->_pv1->x*scalex;

        _uv1->v=q->_pv1->y*scaley;

        _uv1->_index_quad=_index;
        _uv1->_index_vertex=q->_v1;
        _uv1->_index_triangle=-1;

        _mesh->_uv.add(_uv1);

        pl3d_uv_struct _uv2=new l3d_uv_struct;

        _uv2->u=q->_pv2->x*scalex;

        _uv2->v=q->_pv2->y*scaley;

        _uv2->_index_quad=_index;
        _uv2->_index_vertex=q->_v2;
        _uv2->_index_triangle=-1;

        _mesh->_uv.add(_uv2);

        pl3d_uv_struct _uv3=new l3d_uv_struct;

        _uv3->u=q->_pv3->x*scalex;

        _uv3->v=q->_pv3->y*scaley;

        _uv3->_index_quad=_index++;
        _uv3->_index_vertex=q->_v3;
        _uv3->_index_triangle=-1;

        _mesh->_uv.add(_uv3);



        q=q->next;

    }
}
