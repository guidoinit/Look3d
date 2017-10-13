#ifndef L3D_SCENE_H
#define L3D_SCENE_H
#include "l3d_include.h"
#include "mesh/l3d_id.h"

#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "scene/elements/l3d_light.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::light;


namespace l3d
{
    typedef struct _l3d_scene_property
    {
        l3d_uint id;

        l3d_string name;

        l3d_string file;



    }l3d_scene_property,*pl3d_scene_property;

    typedef struct _l3d_scene
    {
        l3d_scene_property property;
        l3d_id_list elements;
        l3d_uint imesh;
        l3d_uint ilight;

        void init()
        {
            imesh=0;
            ilight=0;
            elements.init();
        }

        void add_element(pl3d_id e)
        {

            elements.add(e);

        }
        l3d_uint mesh_size()
        {
            return imesh;
        }

        void del_mesh(l3d_uint ix)
        {
            if(ix<0 || ix>imesh)
                return;
            elements.del_mesh(ix);

        }

        void add_light(pl3d_light l)
        {
            if(l==l3d_null)
                return;

            l->_id_layer=-1;

            pl3d_id e=new l3d_id;

            e->next_type=l3d_null;
            e->prev_type=elements.find_last_type(id_light);

            l3d_mesh _mesh;

            l3d_float fpar[3]={8.0F,8.0F,1.0F};
            l3d_float cpar[2]={32.0F,10.0F};
            l3d_float *par=fpar,*parc=cpar;

            _mesh.create_circle(&l->_circle,parc);
            _mesh.create_sphereuv(par,&l->_sphere);
            l->_sphere._lgroup=l3d_null;
            l->_circle._lgroup=l3d_null;

            l->_sphere.make_box();

            l->_sphere._transformation._wp.set(l->m_pos.x,l->m_pos.y,l->m_pos.z );


            pl3d_material_struct lm=new l3d_material_struct;
            lm->mat_ambient[0]=1.0F;
            lm->mat_ambient[1]=1.0F;
            lm->mat_ambient[2]=0.0F;
            lm->mat_ambient[3]=1.0F;

            lm->mat_diffuse[0]=1.0F;
            lm->mat_diffuse[1]=1.0F;
            lm->mat_diffuse[2]=0.0F;
            lm->mat_diffuse[3]=1.0F;

            lm->mat_specular[0]=0.0F;
            lm->mat_specular[1]=0.0F;
            lm->mat_specular[2]=0.0F;
            lm->mat_specular[3]=1.0F;



            l->_sphere._material.add(lm);
            l->_sphere._material.set(2);


            e->object=(l3d_void)l;

            e->_type=id_light;

            e->next=l3d_null;
            e->prev=l3d_null;

            elements.add(e);

            ilight++;


        }

        void add_mesh(pl3d_mesh_struct m)
        {
            if(m==l3d_null)
                return;

            m->_id_group=-1;
            m->_id_layer=-1;

            pl3d_id e=new l3d_id;
            //pl3d_id evbo=new l3d_id;

            e->next_type=l3d_null;
            e->prev_type=elements.find_last_type(id_mesh);

            //evbo->next_type=l3d_null;
            //evbo->prev_type=elements.find_last_type(id_vbo);

            e->object=(l3d_void)m;
            //evbo->object=(l3d_void)m->_vbo;

            e->_type=id_mesh;
            //evbo->type=id_vbo;

            e->next=l3d_null;
            e->prev=l3d_null;

            //evbo->next=l3d_null;
            //evbo->prev=l3d_null;

            //e->link=evbo;

            elements.add(e);
            //elements.add(evbo);
            imesh++;

        }

    }l3d_scene,*pl3d_scene;
}
#endif // L3D_SCENE_H
