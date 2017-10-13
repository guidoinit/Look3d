//    This file is part of Look3D program.

//    Look3D is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Look3D is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
//
//
#ifndef L3D_MATERIAL_H
#define L3D_MATERIAL_H

#include <QGLWidget>
#include <iostream>
#include <fstream>

#include "l3d_include.h"

namespace l3d
{
    namespace material
    {
    enum MaterialFace
    {
        front=GL_FRONT,
        back=GL_BACK,
        front_and_back=GL_FRONT_AND_BACK
    };

    typedef struct _l3d_material
    {
        char * name;

        _l3d_material * prev;
        _l3d_material * next;


        GLfloat mat_ambient[4] ;
        GLfloat mat_diffuse[4] ;
        l3d_bool m_bambientanddiffuse;
        GLfloat mat_specular[4];
        GLfloat mat_emission[4];
        GLfloat mat_shininess[1];

        MaterialFace _mface;

        void set()
        {
            if(m_bambientanddiffuse)
                    glMaterialfv (_mface, GL_AMBIENT_AND_DIFFUSE, mat_ambient);
            else
            {
                    glMaterialfv (_mface, GL_AMBIENT, mat_ambient);
                    glMaterialfv (_mface, GL_DIFFUSE, mat_diffuse);
            }
            glMaterialfv (_mface, GL_SPECULAR, mat_specular);
            glMaterialfv (_mface, GL_EMISSION, mat_emission);
            glMaterialf (_mface, GL_SHININESS, mat_shininess[0]);

        }
        _l3d_material operator=(const _l3d_material& _m)
        {
            m_bambientanddiffuse=_m.m_bambientanddiffuse;
            mat_shininess[0]=_m.mat_shininess[0];
            _mface=_m._mface;
            for(int ix=0; ix < 5; ix++)
            {
                mat_ambient[ix]=_m.mat_ambient[ix];
                mat_diffuse[ix]=_m.mat_diffuse[ix];
                mat_specular[ix]=_m.mat_specular[ix];
                mat_emission[ix]=_m.mat_emission[ix];
            }

            next=prev=l3d_null;
        }

        void serialize(std::ifstream *ar)
        {
            if(ar->is_open())
            {
                ar->read((char*)&mat_ambient,sizeof(l3d_float)*4);
                ar->read((char*)&mat_diffuse,sizeof(l3d_float)*4);
                ar->read((char*)&mat_specular,sizeof(l3d_float)*4);
                ar->read((char*)&mat_emission,sizeof(l3d_float)*4);
                ar->read((char*)&mat_shininess,sizeof(l3d_float)*1);
                ar->read((char*)&m_bambientanddiffuse,sizeof(l3d_bool));
                ar->read((char*)&_mface,sizeof(MaterialFace));
            }
            else
            {



            }

        }
        void serialize(std::ofstream *ar)
        {
            if(ar->is_open())
            {
                ar->write((char*)&mat_ambient,sizeof(l3d_float)*4);
                ar->write((char*)&mat_diffuse,sizeof(l3d_float)*4);
                ar->write((char*)&mat_specular,sizeof(l3d_float)*4);
                ar->write((char*)&mat_emission,sizeof(l3d_float)*4);
                ar->write((char*)&mat_shininess,sizeof(l3d_float)*1);
                ar->write((char*)&m_bambientanddiffuse,sizeof(l3d_bool));
                ar->write((char*)&_mface,sizeof(MaterialFace));



            }
            else
            {



            }

        }


    }l3d_material_struct,*pl3d_material_struct;

    class l3d_material
    {
    private:

        l3d_uint _size;
        l3d_uint _isel;
        pl3d_material_struct _first;
        pl3d_material_struct _last;


    public:
        l3d_material();
        ~l3d_material(void);
        pl3d_material_struct first();
        pl3d_material_struct last();
        pl3d_material_struct get_at(l3d_uint index);
        l3d_bool empty();

        void add(pl3d_material_struct);
        void addnew();
        void del(l3d_uint index);
        void set(l3d_uint index);
        void use();
        pl3d_material_struct get(l3d_uint);

        pl3d_material_struct find(l3d_uint index);
        l3d_uint size();


    };


    }

}


#endif // L3D_MATERIAL_H
