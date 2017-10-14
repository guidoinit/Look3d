#ifndef L3D_MESH_H
#define L3D_MESH_H
#include "l3d_include.h"
#include "l3d_id_picking.h"
#include "l3d_vertex.h"
#include "l3d_line.h"
#include "l3d_face3.h"
#include "l3d_face4.h"
#include "l3d_uv.h"
#include "l3d_transform.h"
#include "l3d_material.h"
#include "l3d_vertex_group.h"
#include "l3d_blend.h"
#include "vbo/l3d_bufferobject.h"
#include "vbo/l3d_vertexbufferobject.h"
#include "group.h"
#include "scene/sceneenum.h"

namespace l3d
{
    using namespace vertex3f;
    using namespace edge;
    using namespace face3;
    using namespace face4;
    using namespace material;
    using namespace vertex_group;




    namespace mesh
    {
        enum l3d_mesh_type
        {
            mesh_line=0,
            mesh_circle=1,
            mesh_bezier_line=2,
            mesh_bezier_circle=3,
            mesh_null=4,
            mesh_plane=5,
            mesh_cube=6,
            mesh_sphereuv=7,
            mesh_cone=8,
            mesh_tube=9,
            mesh_tube_n=10,
            mesh_torus=11,
            mesh_disck=12,
            mesh_logo=13,

            mesh_last=1024

        };


        typedef struct _l3d_mesh_display
        {
            l3d_bool isnull;
            l3d_bool inmove;
            l3d_bool smooth;
            l3d_bool hide;
            l3d_bool invert;

            l3d_blend blend;

        }l3d_mesh_display_struct,*pl3d_mesh_display_struct;

        typedef struct _bbox
        {





            void init(l3d_vertex_fast vi[8])
            {

                _v[0]=vi[0];
                _v[1]=vi[1];
                _v[2]=vi[2];
                _v[3]=vi[3];
                _v[4]=vi[4];
                _v[5]=vi[5];
                _v[6]=vi[6];
                _v[7]=vi[7];

            }

            void draw_cube_select()
            {
                //glBegin(GL_QUADS);
                {
                    //0-----1
                    //|     |
                    //|     |
                    //|     |
                    //2-----3
                    //base of box down

                    //          4-----5
                    //          |     |
                    //          |     |
                    //          |     |
                    //          6-----7
                    //base of box up
                    //

//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);
//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);
//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);
//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);

//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);


//                    //4-6-2-0
//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);
//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);
//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);

//                    //6-7-2-3
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);
//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);
//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);

//                    //5-4-0-1
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);
//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);
//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);
//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);

//                    //7-5-1-3
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);
//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);
//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);





                }
       //         glEnd();
            }

            void draw_cube()
            {


          //      glBegin(GL_LINES);

                {
                    //a-----b
                    //|     |
                    //|     |
                    //|     |
                    //c-----d
                    //base of box down

                    //draw lines a-b b-d d-c c-a

                    //a=0,b=1,c=2,d=3

                    //0-1
//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);
//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);

//                    //1-2
//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);
//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);

//                    //3-2
//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);
//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);

//                    //2-0
//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);
//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);

                    //a-----b
                    //|     |
                    //|     |
                    //|     |
                    //c-----d
                    //base of box down

                    //draw lines a-b b-d d-c c-a

                    //a=4,b=5,c=6,d=7

                    //4-5
//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);

//                    //5-7
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);

//                    //7-6
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);

//                    //6-4
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);
//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);

//                    //0-----1
                    //|     |
                    //|     |
                    //|     |
                    //2-----3

                    //          4-----5
                    //          |     |
                    //          |     |
                    //          |     |
                    //          6-----7
                    //

                    //draw lines 0-4 1-5 3-7 2-6


//                    glVertex3f(_v[0].x,_v[0].y,_v[0].z);
//                    glVertex3f(_v[4].x,_v[4].y,_v[4].z);


//                    glVertex3f(_v[1].x,_v[1].y,_v[1].z);
//                    glVertex3f(_v[5].x,_v[5].y,_v[5].z);


//                    glVertex3f(_v[3].x,_v[3].y,_v[3].z);
//                    glVertex3f(_v[7].x,_v[7].y,_v[7].z);


//                    glVertex3f(_v[2].x,_v[2].y,_v[2].z);
//                    glVertex3f(_v[6].x,_v[6].y,_v[6].z);



                }

//                glEnd();

            }


             l3d_vertex_fast _v[8];

             l3d_double max_px,max_nx;//maxx positive negative
             l3d_double max_py,max_ny;//maxy positive negative
             l3d_double max_pz,max_nz;//maxz positive negative
        }bbox,*pbbox;
        typedef struct _l3d_mesh
        {

            _l3d_mesh * next;
            _l3d_mesh * prev;

            l3d_string _name;
            l3d_string _sub_name;
            l3d_string _description;
            l3d_string _description1;
            l3d_string _description2;

            l3d_id_picking _pick;


            l3d_uint _iname;
            l3d_uint _id;
            l3d_uint _id_group;
            group * _lgroup;
            void cleargroup()
            {
                _id_group=(l3d_uint)(-1);
            }

            void setgroup(l3d_uint g)
            {
                _id_group=g;
            }
            l3d_uint getgroup()
            {
                return(_id_group);
            }

            l3d_uint _id_layer;

            pl3d_mesh_display_struct _display;

            l3d_transform _transformation;

            //l3d_vertex_fast _wp,_wp2,_wpgroup;
            //l3d_vertex_fast _scale,_scalegroup,_scalevertex;
            //l3d_vertex_fast _rotate,_rotategroup;

            l3d_vertex _vertex;
            l3d_uv _uv;
            l3d_vertex_group _vertex_group;

            l3d_line _edges;
            l3d_face3 _faces;
            l3d_face4 _quad;

            bbox _bbox;
            l3d_vertexbufferobject *_vbo;

            l3d_material _material;
            void make_box()
            {
                //trovare i massimi della mesh





                _bbox.max_px=0.0F;
                _bbox.max_nx=0.0F;

                _bbox.max_py=0.0F;
                _bbox.max_ny=0.0F;

                _bbox.max_pz=0.0F;
                _bbox.max_nz=0.0F;



                pl3d_vertex_fast fv=_vertex.first();

                while(fv)
                {
                    if(fv->x > 0.0F)
                    {
                        if(_bbox.max_px < fv->x)
                            _bbox.max_px=fv->x;
                    }
                    else if(fv->x < 0.0F)
                    {
                        if(_bbox.max_nx > fv->x)
                            _bbox.max_nx=fv->x;
                    }

                    if(fv->y > 0.0F)
                    {
                        if(_bbox.max_py < fv->y)
                            _bbox.max_py=fv->y;

                    }
                    else if(fv->y < 0.0F)
                    {
                        if(_bbox.max_ny > fv->y)
                            _bbox.max_ny=fv->y;

                    }
                    if(fv->z > 0.0F)
                    {
                        if(_bbox.max_pz < fv->z)
                            _bbox.max_pz=fv->z;

                    }
                    else if(fv->z < 0.0F)
                    {
                        if(_bbox.max_nz > fv->z)
                            _bbox.max_nz=fv->z;

                    }
                    fv=fv->next;
                }
                //now i have the maxs of mesh
                //create the box

                //a-----b
                //|     |
                //|     |
                //|     |
                //c-----d
                //base of box down

                //a
                _bbox._v[0].set(_bbox.max_nx,_bbox.max_ny,_bbox.max_pz);
                //b
                _bbox._v[1].set(_bbox.max_px,_bbox.max_ny,_bbox.max_pz);
                //c
                _bbox._v[2].set(_bbox.max_nx,_bbox.max_ny,_bbox.max_nz);
                //d
                _bbox._v[3].set(_bbox.max_px,_bbox.max_ny,_bbox.max_nz);

                //a-----b
                //|     |
                //|     |
                //|     |
                //c-----d
                //base of box up

                //a
                _bbox._v[4].set(_bbox.max_nx,_bbox.max_py,_bbox.max_pz);
                //b
                _bbox._v[5].set(_bbox.max_px,_bbox.max_py,_bbox.max_pz);
                //c
                _bbox._v[6].set(_bbox.max_nx,_bbox.max_py,_bbox.max_nz);
                //d
                _bbox._v[7].set(_bbox.max_px,_bbox.max_py,_bbox.max_nz);


            }
            void setname(const char * _n,l3d_uint ic)
            {
                free(_name);
                _name=new char[25];
                char c[5],*pc;
                pc=&c[0];
                ::snprintf(pc,5,"%d",ic);

                ::strcpy(_name,_n);
                ::strcat(_name,pc);
            }
            void select_group()
            {
                pl3d_vertex_group_struct gr=_vertex_group.get_group();

                if (gr)
                {
                    pl3d_group fg=_vertex_group.get_group_list();

                    while(fg)
                    {
                        switch(fg->type)
                        {
                        case group_vertex:
                            _vertex.find(fg->info)->selected(true);
                            break;
                        case group_edge:
                            _edges.find(fg->info)->selected(true);
                            break;
                        case group_face:
                            _faces.find(fg->info)->selected(true);
                            break;
                        case group_quad:
                            _quad.find(fg->info)->selected(true);
                            break;
                        }

                        fg=fg->next;
                    }


                }
            }
            void del_group()
            {


                _vertex_group.del_group();

            }

            void set_group()
            {
                pl3d_vertex_group_struct gr=_vertex_group.get_group();

                std::string name= gr->getname();

                del_group();

                addvertexgroup(name);


            }

            l3d_bool selected()
            {
                return _pick._selected;
            }
            void selected(l3d_bool s)
            {
                _pick._selected=s;
            }
            l3d_bool blend()
            {
                return(_display->blend.blend());
            }

            void blend(l3d_bool _b)
            {
                _display->blend.blend(_b);

            }
            void blend(blendFunction _f,l3d_bool _cull)
            {
                _display->blend.set(_f,_cull);

            }
            void use_blend_edit()
            {
                _display->blend.use_edit();
            }

            void use_blend()
            {
                _display->blend.use();
            }

            pl3d_id_picking getpick()
            {
                return (&_pick);
            }
            void set_material(l3d_material mat)
            {
                _material=mat;

            }
            void set_material_all(l3d_uint _imat)
            {
                pl3d_vertex_fast fv=_vertex.first();

                while(fv)
                {

                    fv->_imaterial=_imat;

                    fv=fv->next;
                }

            }

            l3d_bool vertex_alone(int ix)
            {
                l3d_bool alone=true;
                pl3d_vertex_fast v=_vertex.find(ix);


                if(v!=NULL)
                {
                    pl3d_face4_struct face=_quad.first();

                    while(face && alone)
                    {
                        if(!face->_erase && (face->_v0==ix  ||
                                face->_v1==ix  || face->_v2==ix  ||
                                face->_v3==ix))

                            alone=false;



                        face=face->next;
                    }


                }
                return (alone);

            }
            void addvertexgroup(std::string name)
            {
                pl3d_vertex_group_struct ng= new l3d_vertex_group_struct;

                ng->init();

                l3d_string pname=new char[25];
                name.copy(pname,name.size());

                ng->setname(pname);

                pl3d_vertex_fast vf=_vertex.first();
                l3d_uint in=0;
                while(vf)
                {
                    if(vf->_selected)
                        ng->add(in,group_vertex);
                    in++;
                    vf=vf->next;
                }
                pl3d_line_struct pl=_edges.first();
                in=0;
                while(pl)
                {
                    if(pl->selected())
                        ng->add(in,group_edge);
                    in++;
                    pl=pl->next;
                }
                pl3d_face3_struct f=_faces.first();
                in=0;
                while(f)
                {
                    if(f->_selected && f->_alone)
                        ng->add(in,group_face);
                    in++;
                    f=f->next;
                }
                pl3d_face4_struct q=_quad.first();
                in=0;
                while(q)
                {
                    if(q->selected() )
                        ng->add(in,group_quad);
                    in++;
                    q=q->next;
                }



                _vertex_group.add_group(ng);
            }

            void addvertex(l3d_float x,l3d_float y,l3d_float z)
            {
                pl3d_vertex_fast v= new l3d_vertex_fast;
                v->x=x;
                v->y=y;
                v->z=z;
                v->_imaterial=0;
                _vertex.add(v);
                delete(v);
            }
            void addvertex(pl3d_vertex_fast v)
            {
                _vertex.add(v);

            }
            void addedge(l3d_uint v0,l3d_uint v1)
            {
                pl3d_line_struct l= new l3d_line_struct;

                if(_edges.find(v0,v1)!=NULL || _edges.find(v1,v0)!=NULL)
                    return;

                l->erase=false;
                l->selected(false);

                l->next_size=l->prev_size=0;
                l->list_next=l->list_prev=l3d_null;


                l->v0=v0;
                l->v1=v1;

                l->_v0=_vertex.find(v0);
                l->_v1=_vertex.find(v1);

                _edges.add(l);
                delete(l);

            }
            void addface3(l3d_uint v0,l3d_uint v1,l3d_uint v2,l3d_bool alone,l3d_face_insert insert)
            {
                pl3d_face3_struct f=new l3d_face3_struct;


                l3d_bool ccw=false;
                l3d_uint a,b,c;


                f->_insert=insert;

                f->_alone=alone;
                f->_erase=false;
                f->_selected=false;

                //a----b
                //|   /
                //|  /
                //| /
                //|/
                //c

                switch(insert)
                {
                case abcCW:
                    a=v0;
                    b=v1;
                    c=v2;
                    break;

                case abcCCW:
                    a=v0;
                    b=v1;
                    c=v2;
                    ccw=true;
                    break;

                }



                //a----b
                //|   /
                //|  /
                //| /
                //|/
                //c
                if(!ccw)
                {
                    f->v0=a;
                    f->v1=b;
                    f->v2=c;


                    f->_pv0=_vertex.find(a);
                    f->_pv1=_vertex.find(b);
                    f->_pv2=_vertex.find(c);


                }
                else
                {
                    f->v0=a;
                    f->v1=c;
                    f->v2=b;


                    f->_pv0=_vertex.find(a);
                    f->_pv1=_vertex.find(c);
                    f->_pv2=_vertex.find(b);


                }


                addedge(a,b);
                addedge(b,c);
                addedge(c,a);

                f->_l0=_edges.find(a,b);
                f->_l1=_edges.find(b,c);
                f->_l2=_edges.find(c,a);

                f->l0=_edges.findindex(a,b);
                f->l1=_edges.findindex(b,c);
                f->l2=_edges.findindex(c,a);


                _faces.add(f);

                delete(f);



            }
            void invert_quad()
            {
                pl3d_face4_struct _q=_quad.first();


                while(_q)
                {
                    if(_q->selected())
                    {
                        l3d_uint v0,v1,v2,v3;

                        v0=_q->_v0;
                        v1=_q->_v1;
                        v2=_q->_v2;
                        v3=_q->_v3;

                        _q->_v0=v1;
                        _q->_v1=v0;
                        _q->_v2=v3;
                        _q->_v3=v2;

                        _q->_pv0=_vertex.find(_q->_v0);
                        _q->_pv1=_vertex.find(_q->_v1);
                        _q->_pv2=_vertex.find(_q->_v2);
                        _q->_pv3=_vertex.find(_q->_v3);

                        pl3d_face3_struct pf=_q->_f0;

                        v0=pf->v0;
                        v1=pf->v1;
                        v2=pf->v2;

                        pf->v1=v2;
                        pf->v2=v1;

                        pf->_pv0=_vertex.find(pf->v0);
                        pf->_pv1=_vertex.find(pf->v1);
                        pf->_pv2=_vertex.find(pf->v2);


                        pf=_q->_f1;

                        v0=pf->v0;
                        v1=pf->v1;
                        v2=pf->v2;

                        pf->v1=v2;
                        pf->v2=v1;

                        pf->_pv0=_vertex.find(pf->v0);
                        pf->_pv1=_vertex.find(pf->v1);
                        pf->_pv2=_vertex.find(pf->v2);



                    }
                    _q=_q->next;
                }

            }
            void addquad(l3d_uint v0,l3d_uint v1,l3d_uint v2,l3d_uint v3,l3d_quad_insert insert)
            {
                pl3d_face4_struct f=new l3d_face4_struct;

                l3d_uint a,b,c,d;
                l3d_bool ccw=false;

                f->_insert=insert;
                f->_erase=false;
                f->_selected=false;
                f->init_lists();

                //a----b
                //|    |
                //|    |
                //c----d

                switch(insert)
                {
                case abcdCW:
                    a=v0;
                    b=v1;
                    c=v2;
                    d=v3;

                    break;
                case badcCW:
                    a=v1;
                    b=v0;
                    c=v3;
                    d=v2;
                    break;
                case badcCCW:
                    a=v1;
                    b=v0;
                    c=v3;
                    d=v2;
                    ccw=true;
                    break;
                case abcdCCW:
                    a=v0;
                    b=v1;
                    c=v2;
                    d=v3;
                    ccw=true;
                    break;
                }
                //a----b
                //|    |
                //|    |
                //c----d

                if(!ccw)
                {
                    f->_v0=a;
                    f->_v1=b;
                    f->_v2=d;
                    f->_v3=c;

                    f->_pv0=_vertex.find(a);
                    f->_pv1=_vertex.find(b);
                    f->_pv2=_vertex.find(d);
                    f->_pv3=_vertex.find(c);


                }
                else
                {
                    f->_v0=b;
                    f->_v1=a;
                    f->_v2=c;
                    f->_v3=d;

                    f->_pv0=_vertex.find(b);
                    f->_pv1=_vertex.find(a);
                    f->_pv2=_vertex.find(c);
                    f->_pv3=_vertex.find(d);


                }


                //?? da reinserire?
                l3d_uint numf=_faces.size();

                //a----b
                //|    |
                //|    |
                //c----d
                if(!ccw)
                {
                    addface3(a,b,c,false,abcCW);
                    addface3(c,b,d,false,abcCW);
                }
                else

                {
                    addface3(b,a,d,false,abcCCW);
                    addface3(b,c,d,false,abcCCW);

                }



                f->f0=numf;
                f->f1=numf+1;

                f->_f0=_faces.find(numf);
                f->_f1=_faces.find(numf+1);

                f->l0=_edges.findindex(a,b);
                f->l1=_edges.findindex(b,d);
                f->l2=_edges.findindex(d,c);
                f->l3=_edges.findindex(c,a);

                f->_l0=_edges.find(a,b);
                f->_l1=_edges.find(b,d);
                f->_l2=_edges.find(d,c);
                f->_l3=_edges.find(c,a);

                if(!ccw)
                    f->_lf=_edges.find(b,c);
                else
                    f->_lf=_edges.find(a,d);

                _quad.add(f);

                delete(f);

            }
            l3d_vertex_fast makevector(pl3d_vertex_fast v0,pl3d_vertex_fast v1)
            {
                l3d_vertex_fast  ris;

                ris.x=v0->x-v1->x;
                ris.y=v0->y-v1->y;
                ris.z=v0->z-v1->z;


                ris.normalize();

                return(ris);

            }

            void faces_normals()
            {
                l3d_uint indice=0;
                l3d_vertex_fast u,v;
                pl3d_vertex_fast vett0, vett1, vett2;


                for (indice=0; indice < _faces.size() ; indice++)
                {


                        pl3d_face3_struct f=_faces.find(indice);

                        vett0 = _vertex.find(f->v0);
                        vett1 = _vertex.find(f->v1);
                        vett2 = _vertex.find(f->v2);

                        u = makevector (vett0, vett1);
                        v = makevector (vett0, vett2);

                        f->_normal.vectorproduct(u, v);

                        f->_normal.normalize();




                }
                vertex_normal();






            }
            void clear()
            {
                //to-do

            }

            void vertex_normal()
            {

                for(l3d_uint ix=0; ix < _vertex.size(); ix++)
                {
                    pl3d_vertex_fast v=_vertex.find(ix);

                    l3d_uint count=0;

                    v->normals[0]=0.0F;
                    v->normals[1]=0.0F;
                    v->normals[2]=0.0F;

                    for(int iy=0; iy < _faces.size(); iy++)
                    {
                        pl3d_face3_struct f=_faces.find(iy);

                        if(ix==f->v0 || ix==f->v1 || ix==f->v2)
                        {
                            v->normals[0]+=f->_normal.x;
                            v->normals[1]+=f->_normal.y;
                            v->normals[2]+=f->_normal.z;

                            count++;
                        }
                    }
                    v->normals[0]/=(float)count;
                    v->normals[1]/=(float)count;
                    v->normals[2]/=(float)count;
                }

            }
            _l3d_mesh * get_copy()
            {
                _l3d_mesh * newmesh= new _l3d_mesh;


                newmesh->_name=_name;
                newmesh->_sub_name=_sub_name;
                newmesh->_vertex.clear();


                newmesh->_display= new l3d_mesh_display_struct;
                newmesh->_display->isnull=false;
                newmesh->selected(false);

                newmesh->_transformation.set(_transformation);

                //riempire i vertici
                pl3d_vertex_fast v=_vertex.first();
                while(v)
                {
                    pl3d_vertex_fast vcopy= new l3d_vertex_fast;

                    *vcopy=*v;

                    newmesh->_vertex.add(vcopy);

                    v=v->next;

                    delete (vcopy);

                }
                //riempire le linee

                pl3d_line_struct l=_edges.first();

                while(l)
                {

                    pl3d_line_struct nl= new l3d_line_struct;

                    *nl=*l;

                    nl->_v0=newmesh->_vertex.find(nl->v0);
                    nl->_v1=newmesh->_vertex.find(nl->v1);

                    newmesh->_edges.add(nl);

                    l=l->next;

                    delete(nl);

                }
                //riempire i triangoli


                pl3d_face3_struct f=_faces.first();

                while(f)
                {

                    pl3d_face3_struct nf=new l3d_face3_struct;

                    *nf=*f;
                    newmesh->_faces.add(nf);

                    f=f->next;

                    delete(nf);
                }

                //riempire i quad (quadrati)

                pl3d_face4_struct q=_quad.first();

                while(q)
                {

                    pl3d_face4_struct nq=new l3d_face4_struct;

                    *nq=*q;
                    newmesh->_quad.add(nq);

                    q=q->next;

                    delete(nq);
                }

                //newmesh->faces_normals();

                return (newmesh);


            }
            void scale_vbo()
            {
                l3d_vertexbufferobject *vbo=_vbo;

                if(!vbo)
                    return;

                pl3d_VBO_element vele=(pl3d_VBO_element)vbo->_elementvert->getbufferobject(access_write_only);


                pl3d_vertex_fast appv=_vertex.first();

                while(appv)
                {
                    vele->location[0]*=_transformation._scale.x;
                    vele->location[1]*=_transformation._scale.y;
                    vele->location[2]*=_transformation._scale.z;

                    *vele++;
                    appv=appv->next;
                }
                vbo->_elementvert->unmapbuffer();


            }

            void scale()
            {
                pl3d_vertex_fast appv=_vertex.first();

                while(appv)
                {
                    appv->scale(&_transformation._scale);
                    appv=appv->next;
                }
                //scale_vbo();
                _transformation._scale.set(1.0F,1.0F,1.0F);
            }
            void rotate()
            {
                pl3d_vertex_fast appv=_vertex.first();

                while(appv)
                {
                    appv->rotate(&_transformation._rotate);
                    appv=appv->next;
                }
                _transformation._rotate.set(0.0F,0.0F,0.0F);

            }
            void removedoubleedges()
            {
                    if (_edges.size()<=0)
                            return;

                    //std::list<int> ldel;
                    for(int ix=0; ix < _edges.size()-1; ix++)
                    {
                            pl3d_line_struct mline=_edges.find(ix);
                            for( int iy=ix+1; iy < _edges.size(); iy++)
                            {
                                pl3d_line_struct mline2=_edges.find(iy);

                                if((mline->v0 == mline2->v0 && mline->v1 == mline2->v1) ||
                                   (mline->v0 == mline2->v1 && mline->v1 == mline2->v0)
                                        && !mline2->erase)
                                {

                                        mline2->erase=true;

                                        iy--;
                                }

                            }
                    }
                    pl3d_line_struct e=_edges.first(),e2;
                    e2=e;

                    while(e)
                    {
                        if(e->erase)
                        {

                            e2=e->next;
                            _edges.del(e);
                            e=e2;

                        }else

                            e=e->next;

                    }

                    assignedge();
            }

            void assignedge()
            {
                for(int i=0; i < _quad.size() ;i++)
                {
                    int v[4];

                    pl3d_face4_struct mp=_quad.find(i);


                    v[0]=mp->_v0;
                    v[1]=mp->_v1;
                    v[2]=mp->_v2;
                    v[3]=mp->_v3;

                    int pline[4];
                    int lapp=-1;i=0;
                    for(int ix=0; ix<3; ix++)
                        for(int iy=ix+1; iy<4; iy++)
                            if((lapp=findedge(v[ix],v[iy]))!=-1 && !_edges.find(lapp)->erase)//trovata
                                pline[i++]=lapp;


                    if(i==4 && lapp!=-1)
                    {
                        mp->set_edges(pline[0],pline[1],pline[2],pline[3]);
                        mp->set_edges(_edges.find(pline[0]),_edges.find(pline[1]),_edges.find(pline[2]),_edges.find(pline[3]));
                    }



                }
            }

            l3d_uint findedge(l3d_uint v0,l3d_uint v1)
            {
                pl3d_line_struct l=_edges.first();
                l3d_uint ix=0;
                while(l)
                {
                    if((l->v0==v0 && l->v1==v1) || (l->v0==v1 && l->v1==v0))
                        return(ix);
                    ix++;
                    l=l->next;
                }

                return(-1);

            }

            void serialize(std::ifstream *ar)
            {
                int size;
                if(ar->is_open())
                {
                    //to-do prelevare informazioni della mesh
                    /*

                    char *cname =(char*) ::malloc(sizeof(char)*50);
                    char *csubname=(char*) ::malloc(sizeof(char)*50);

                    ar->read((char*)cname,sizeof(char)*50);
                    ar->read((char*)csubname,sizeof(char)*50);

                    string n(cname);
                    name=n;
                    string s(csubname);
                    subname=s;
                    */
                    //(*ar) >>m_binvert;
                    _display= new l3d_mesh_display_struct;

                    _display->isnull=false;
                    _display->smooth=false;
                    _display->blend.blend(false);

                    _lgroup=l3d_null;

                    _name= new char[255];
                    _sub_name= new char[255];
                    _description= new char[255];
                    _description1= new char[255];
                    _description2= new char[255];

                    ar->read(_name,sizeof(char)*255);
                    ar->read(_sub_name,sizeof(char)*255);
                    ar->read(_description,sizeof(char)*255);
                    ar->read(_description1,sizeof(char)*255);
                    ar->read(_description2,sizeof(char)*255);

                    ar->read((char*)&_id,sizeof(char)*4);
                    ar->read((char*)&_id_group,sizeof(char)*4);


                    //(*ar) >>name;
                    //(*ar) >>subname;

                    _transformation.serialize(ar);

                    //m_shaderprogram=NULL;




                    ar->read((char*)&size,sizeof(int));


                    for(int ix=0; ix < size; ix++)
                    {
                        pl3d_vertex_fast appv= new l3d_vertex_fast;
                        appv->serialize(ar);
                        _vertex.add(appv);
                    }

                    ar->read((char*)&size,sizeof(int));

                    for(int ix=0; ix < size; ix++)
                    {
                        pl3d_line_struct rl= new l3d_line_struct;

                        rl->serialize(ar);

                        rl->_v0=_vertex.find(rl->v0);
                        rl->_v1=_vertex.find(rl->v1);

                        _edges.add(rl);
                    }

                    ar->read((char*)&size,sizeof(int));

                    for(int ix=0; ix< size; ix++)
                    {
                        pl3d_face3_struct rf= new l3d_face3_struct;

                        rf->serialize(ar);

                        rf->_pv0=_vertex.find(rf->v0);
                        rf->_pv1=_vertex.find(rf->v1);
                        rf->_pv2=_vertex.find(rf->v2);

                        rf->_l0=_edges.find(rf->v0,rf->v1);
                        rf->_l1=_edges.find(rf->v1,rf->v2);
                        rf->_l2=_edges.find(rf->v2,rf->v0);


                        _faces.add(rf);
                    }


                    ar->read((char*)&size,sizeof(int));
                    for(int ix=0; ix< size; ix++)
                    {
                        pl3d_face4_struct rq=new l3d_face4_struct;

                        rq->serialize(ar);


                        rq->_pv0=_vertex.find(rq->_v0);
                        rq->_pv1=_vertex.find(rq->_v1);
                        rq->_pv2=_vertex.find(rq->_v2);
                        rq->_pv3=_vertex.find(rq->_v3);

                        rq->_l0=_edges.find(rq->l0);
                        rq->_l1=_edges.find(rq->l1);
                        rq->_l2=_edges.find(rq->l2);
                        rq->_l3=_edges.find(rq->l3);
                        rq->_lf=_edges.find(rq->l4);

                        rq->_f0=_faces.find(rq->f0);
                        rq->_f0=_faces.find(rq->f1);



                        _quad.add(rq);
                    }



                    ar->read((char*)&size,sizeof(int));
                    for(int ix=0; ix < size; ix++)
                    {
                        pl3d_material_struct rm= new l3d_material_struct;

                        rm->serialize(ar);

                        _material.add(rm);

                    }


                    ar->read((char*)&size,sizeof(int));
                    //textures to-do: add


                    _vertex_group.serialize(ar);








                }
                else
                {


                }
            }
            void serialize(std::ofstream *ar)
            {
                if(ar->is_open())
                {
                    //to-do salvare informazioni della mesh

                    /*
                    char *cname =(char*)name.c_str();
                    char *csubname=(char*)subname.c_str();
                    ar->write((char*)cname,sizeof(char)*50);
                    ar->write((char*)csubname,sizeof(char)*50);
                    */
                    //ar->write((char*)this,sizeof(object3d));

                    ar->write(_name,sizeof(char)*255);
                    ar->write(_sub_name,sizeof(char)*255);
                    ar->write(_description,sizeof(char)*255);
                    ar->write(_description1,sizeof(char)*255);
                    ar->write(_description2,sizeof(char)*255);

                    ar->write((char*)&_id,sizeof(char)*4);
                    ar->write((char*)&_id_group,sizeof(char)*4);




                    _transformation.serialize(ar);

                    //m_shaderprogram=NULL;



                    int size=_vertex.size();

                    ar->write((char*)&size,sizeof(int));

                    for(int ix=0; ix < size; ix++)
                        _vertex.find(ix)->serialize(ar);

                    size=_edges.size();

                    ar->write((char*)&size,sizeof(int));

                    for(int ix=0; ix < _edges.size(); ix++)
                        _edges.find(ix)->serialize(ar);
                    //copia i poligoni a 3

                    size=_faces.size();
                    ar->write((char*)&size,sizeof(int));

                    for(int ix=0; ix< _faces.size(); ix++)
                        _faces.find(ix)->serialize(ar);

                    size=_quad.size();
                    ar->write((char*)&size,sizeof(int));

                    for(int ix=0; ix< _quad.size(); ix++)
                        _quad.find(ix)->serialize(ar);

                    size=_material.size();
                    ar->write((char*)&size,sizeof(int));

                    for(int ix=0; ix < _material.size(); ix++)
                        _material.find(ix)->serialize(ar);

                    //textures to-do: add

                    size=0;

                    ar->write((char*)&size,sizeof(int));


                    _vertex_group.serialize(ar);



                    //for(int ix=0; ix < m_tex.size(); ix++)
                    //    ;//to-do m_tex.push_back(obj.m_tex[ix]);


                    //copia i vertici






                }
                else
                {


                }
            }
            void init_material()
            {
                pl3d_material_struct _mat=new l3d_material_struct;

                float app[4]={0.5F,0.5F,0.5F,1.0F};

                for(int ix=0; ix < 4 ; ix++)
                {


                    _mat->mat_ambient[ix]=app[ix];
                    _mat->mat_diffuse[ix]=app[ix];

                    _mat->mat_specular[ix]=app[ix];
                    _mat->mat_emission[ix]=0.0F;

                }

                _mat->mat_emission[3]=1.0F;

                _mat->m_bambientanddiffuse=true;
                _mat->_mface=front;
                _mat->mat_shininess[0]=.5F;

                _material.add(_mat);
                _material.set(1);

                blend(false);



            }



        }l3d_mesh_struct,*pl3d_mesh_struct;

        class l3d_mesh
        {
            private:
                l3d_uint _icount;
                l3d_uint _iselected;
                pl3d_mesh_struct _first;
                pl3d_mesh_struct _last;
                pl3d_mesh_struct _selected;
                l3d_uint _nmeshes;
            public:
                l3d_mesh();

                l3d_uint size();
                void init_material(pl3d_mesh_struct);
                void create_null();
                void create_line(l3d_float*);
                void create_circle(l3d_float*);
                void create_circle(pl3d_mesh_struct _m, l3d_float*);
                void create_disck(l3d_float*);
                void create_plane(l3d_float*);
                void create_cube(l3d_float*);
                void create_cone(l3d_float*);
                static void create_cone(l3d_float *,pl3d_mesh_struct );
                void create_cylinder(l3d_float*);
                void create_cylindern(l3d_float*);
                static void create_sphereuv(l3d_float*,pl3d_mesh_struct);
                void create_sphereuv(l3d_float*);
                void create_torus(l3d_float*);
                void create_logo(l3d_float *);
                void create_vbo(l3d_uint _e);
                void delete_vbo(l3d_uint _e);
                void delete_vbo(pl3d_mesh_struct _e);
                void create_vbo(pl3d_mesh_struct _e);
                void matmult(GLfloat M[], GLfloat v[]);
                l3d_bool isfirst();
                l3d_bool vertex_alone(int);
                void add(pl3d_mesh_struct _e);
                void del(l3d_uint _index);
                void del(pl3d_mesh_struct _m );
                void setselected(l3d_uint _s);
                pl3d_mesh_struct find(l3d_uint _index);
                l3d_uint find(pl3d_mesh_struct _m);
                pl3d_mesh_struct first();
                void clear();
                void draw_vbo(l3d_uint);

                void draw_vbo(l3d_vertexbufferobject *);
                void draw_vbo(pl3d_mesh_struct  m,SCENE::ModeDraw md);
                void draw_edit(pl3d_mesh_struct );
                void draw_edit(l3d_uint );
                void create(l3d_mesh_type _typem,l3d_float*);

                pl3d_mesh_struct getselected();
                l3d_uint getiselected();



        };

    }
}

#endif // L3D_MESH_H
