#ifndef TELECAMERA_H
#define TELECAMERA_H

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

#include "./mesh/l3d_vertex.h"

using namespace l3d::vertex3f;
class telecamera

{
public:
        telecamera(void);
        telecamera(l3d_vertex_fast);
        telecamera(l3d_vertex_fast,l3d_vertex_fast);
        telecamera(l3d_vertex_fast,l3d_vertex_fast,l3d_vertex_fast);

        ~telecamera(void);
        void SetName(int);
        void SetSelected(bool);
        bool isSelected();
        void Move(l3d_vertex_fast );
        void up();
        void down();
        void left();
        void right();
        int GetName();
        //virtual void Serialize(CArchive& ar);
        telecamera ( const telecamera &tel )
        {
                vpos=tel.vpos;
                vposwhere=tel.vposwhere ;
                vposup=tel.vposup;
                m_angolox=tel.m_angolox;
                m_angoloy=tel.m_angoloy;
                selected=tel.selected;
                name=tel.name;

                vertici[0]=tel.vertici[0];
                vertici[1]=tel.vertici[1];
                vertici[2]=tel.vertici[2];
                vertici[3]=tel.vertici[3];
                vertici[4]=tel.vertici[4];

        }
        telecamera& operator=( const telecamera &tel )
        {
                vpos=tel.vpos;
                vposwhere=tel.vposwhere ;
                vposup=tel.vposup;
                m_angolox=tel.m_angolox;
                m_angoloy=tel.m_angoloy;
                selected=tel.selected;
                name=tel.name;

                vertici[0]=tel.vertici[0];
                vertici[1]=tel.vertici[1];
                vertici[2]=tel.vertici[2];
                vertici[3]=tel.vertici[3];
                vertici[4]=tel.vertici[4];


                return *this;
        }
        void Draw();
        void Create(l3d_vertex_fast,l3d_vertex_fast);
        void Create(l3d_vertex_fast,l3d_vertex_fast,l3d_vertex_fast);
        l3d_vertex_fast vpos;
        l3d_vertex_fast vposwhere;
        l3d_vertex_fast vposup;
private:
        bool selected;

        l3d_vertex_fast vertici[5];

        int name;

        float m_angolox, m_angoloy;

public:
        void SetPos(void);
        void Updatefree(void);
        void Updatefree(float x, float y);
        void SetAngols(float x, float y);
        void AddAngles(float x, float y);
};


#endif // TELECAMERA_H
