#ifndef L3D_TRANSFORM_H
#define L3D_TRANSFORM_H

#include "l3d_vertex.h"
#include <glm/glm.hpp>


using namespace l3d::vertex3f;

namespace l3d
{
    typedef struct _transform
    {
        l3d_vertex_fast _wp,_wp2,_wpgroup;
        l3d_vertex_fast _scale,_scalegroup,_scalevertex;
        l3d_vertex_fast _rotate,_rotategroup;
        glm::mat4 _mat_scale,_mat_rotate,_mat_translate;


        l3d_bool inmove;
        void init()
        {

            _wp.set(0.0F,0.0F,0.0F);
            _wp2.set(0.0F,0.0F,0.0F);
            _wpgroup.set(0.0F,0.0F,0.0F);

            _scale.set(1.0F,1.0F,1.0F);
            _scalegroup.set(1.0F,1.0F,1.0F);
            _scalevertex.set(1.0F,1.0F,1.0F);

            _rotate.set(0.0F,0.0F,0.0F);
            _rotategroup.set(0.0F,0.0F,0.0F);

            inmove=false;


        }
        void draw()
        {
            if (_rotate.x>360)_rotate.x-=360;
            if (_rotate.y>360) _rotate.y-=360;
            if (_rotate.z>360) _rotate.z-=360;

           // if(! inmove)
          //      glTranslatef(_wp.x,_wp.y,_wp.z);
          //  else
          //      glTranslatef(_wp2.x,_wp2.y,_wp2.z);

          //  glRotatef(_rotate.x,1.0,0.0,0.0);
         //   glRotatef(_rotate.y,0.0,1.0,0.0);
          //  glRotatef(_rotate.z,0.0,0.0,1.0);
         //   glScalef( _scale.x, _scale.y, _scale.z);
        }
        void draw_group()
        {
            if (_rotategroup.x>360)_rotategroup.x-=360;
            if (_rotategroup.y>360) _rotategroup.y-=360;
            if (_rotategroup.z>360) _rotategroup.z-=360;



           // glTranslatef(_wpgroup.x,_wpgroup.y,_wpgroup.z);
          //  glRotatef(_rotategroup.x,1.0,0.0,0.0);
          //  glRotatef(_rotategroup.y,0.0,1.0,0.0);
          //  glRotatef(_rotategroup.z,0.0,0.0,1.0);
          //  glScalef( _scalegroup.x,_scalegroup.y,_scalegroup.z);

        }
        void draw_group(_transform *pg)
        {
            if (_rotategroup.x>360)_rotategroup.x-=360;
            if (_rotategroup.y>360) _rotategroup.y-=360;
            if (_rotategroup.z>360) _rotategroup.z-=360;

        //    glTranslatef(pg->_wp.x,pg->_wp.y,pg->_wp.z);

        //    glRotatef(pg->_rotate.x,1.0,0.0,0.0);
        //    glRotatef(pg->_rotate.y,0.0,1.0,0.0);
        //    glRotatef(pg->_rotate.z,0.0,0.0,1.0);

         //   glScalef(pg->_scale.x,pg->_scale.y,pg->_scale.z);

        //    glTranslatef(_wpgroup.x,_wpgroup.y,_wpgroup.z);
       //     glRotatef(_rotategroup.x,1.0,0.0,0.0);
       //     glRotatef(_rotategroup.y,0.0,1.0,0.0);
       //     glRotatef(_rotategroup.z,0.0,0.0,1.0);
       //     glScalef( _scalegroup.x,_scalegroup.y,_scalegroup.z);

        }

        void set(l3d_double x,l3d_double y,l3d_double z)
        {
            _wp.set(x,y,z);
        }
        void set(_transform _t)
        {
            _wp=_t._wp;
            _wp2=_t._wp2;
            _wpgroup=_t._wpgroup;

            _scale=_t._scale;
            _scalegroup=_t._scalegroup;
            _scalevertex=_t._scalevertex;

            _rotate=_t._rotate;
            _rotategroup=_t._rotategroup;

        }
        void scale(l3d_double x,l3d_double y,l3d_double z)
        {
            _scale.set(x,y,z);
        }
        void rotate(l3d_double x,l3d_double y,l3d_double z)
        {
            _rotate.set(x,y,z);
        }
        void serialize(std::ifstream *ar)
        {
            if(ar->is_open())
            {
                _wp.serialize(ar);
                _wp2.serialize(ar);
                _wpgroup.serialize(ar);

                _scale.serialize(ar);
                _scalegroup.serialize(ar);
                _scalevertex.serialize(ar);

                _rotate.serialize(ar);
                _rotategroup.serialize(ar);
            }

        }
        void serialize(std::ofstream *ar)
        {
            if(ar->is_open())
            {
                _wp.serialize(ar);
                _wp2.serialize(ar);
                _wpgroup.serialize(ar);

                _scale.serialize(ar);
                _scalegroup.serialize(ar);
                _scalevertex.serialize(ar);

                _rotate.serialize(ar);
                _rotategroup.serialize(ar);
            }
        }

    }l3d_transform,*pl3d_transform;
}



#endif // L3D_TRANSFORM_H
