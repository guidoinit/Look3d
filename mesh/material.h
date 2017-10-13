#ifndef MATERIAL_H
#define MATERIAL_H
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
#pragma once

#include <QGLWidget>
#include <iostream>
#include <fstream>


class material
{
    enum MaterialFace
    {
            front=GL_FRONT,
            back=GL_BACK,
            front_and_back=GL_FRONT_AND_BACK
    };
private:

        char * name;




        MaterialFace _mface;

public:
        GLfloat mat_ambient[4] ;
        GLfloat mat_diffuse[4] ;
        bool m_bambientanddiffuse;
        GLfloat mat_specular[4];
        GLfloat mat_emission[4];
        GLfloat mat_shininess[1];
        material(void);
        material(MaterialFace);
        material(MaterialFace,bool,GLfloat [],GLfloat [],GLfloat [],GLfloat[],GLfloat[]);
        ~material(void);

        void Set();
        //void Save(CString path);//MFC function
        //virtual void Serialize(CArchive &); //MFC function

        material (const material &mat)
        {
                for(int ix=0; ix < 4; ix++)
                {
                        mat_ambient[ix]=	mat.mat_ambient[ix];
                        mat_diffuse[ix]=	mat.mat_diffuse[ix];
                        mat_specular[ix]=	mat.mat_specular[ix];
                        mat_emission[ix]=	mat.mat_emission[ix];
                }
                mat_shininess[0]=mat.mat_shininess[0];
                _mface=mat._mface;
                m_bambientanddiffuse=mat.m_bambientanddiffuse;

        }
        material& operator=( const material &mat )
        {
                for(int ix=0; ix < 4; ix++)
                {
                        mat_ambient[ix]=	mat.mat_ambient[ix];
                        mat_diffuse[ix]=	mat.mat_diffuse[ix];
                        mat_specular[ix]=	mat.mat_specular[ix];
                        mat_emission[ix]=	mat.mat_emission[ix];
                }
                mat_shininess[0]=mat.mat_shininess[0];
                _mface=mat._mface;
                m_bambientanddiffuse=mat.m_bambientanddiffuse;

                return *this;
        }
        void serialize(std::ifstream*  ar)
        {
            //int face;
            if(ar->is_open())
            {
                ar->read((char*)this,sizeof(material));
                /*for(int ix=0; ix < 4; ix++)
                {
                        (*ar) >> mat_ambient[ix];
                        (*ar) >> mat_diffuse[ix];
                        (*ar) >> mat_specular[ix];
                        (*ar) >> mat_emission[ix];
                }
                (*ar) >> mat_shininess[0];
                (*ar) >>face;
                switch(face)
                {
                case 0:
                    _mface=front;
                    break;
                case 1:
                    _mface=back;
                    break;
                case 2:
                    _mface=front_and_back;
                    break;
                }
                _mface=(MaterialFace)face;
                (*ar) >> m_bambientanddiffuse;*/
            }
            else
            {


            }


        }
        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {
                ar->write((char*)this,sizeof(material));
                /*
                    for(int ix=0; ix < 4; ix++)
                    {
                            (*ar) << mat_ambient[ix];
                            (*ar) << mat_diffuse[ix];
                            (*ar) << mat_specular[ix];
                            (*ar) << mat_emission[ix];
                    }
                    (*ar) << mat_shininess[0];
                    switch(_mface)
                    {
                    case front:
                        (*ar) <<(int)0;
                        break;
                    case back:
                        (*ar) <<(int)1;
                        break;
                    case front_and_back:
                        (*ar) <<(int)2;
                        break;
                    }


                    (*ar) << m_bambientanddiffuse;*/

            }
            else
            {


            }


        }
};




#endif // MATERIAL_H
