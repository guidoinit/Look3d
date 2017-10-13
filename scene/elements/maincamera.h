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


#ifndef MAINCAMERA_H
#define MAINCAMERA_H

#define TRACKBALLSIZE  (0.8f)

#pragma once

#include "math.h"



#include "scene/elements/telecamera.h"

#include "scene/elements/settrackball.h"






class maincamera :public telecamera
{
private:
        float m_angolo[3];
        float alpha;
        float beta;
        float m_radius;
        bool m_bfree;
        bool m_btrack;
        int m_iposmouse[2];

public:
        maincamera(void);
        maincamera(l3d_vertex_fast);
        maincamera(l3d_vertex_fast,l3d_vertex_fast);
        l3d_vertex_fast vposold,vposwhereold,vposupold;
        void setfree(bool value);
        void Update(float);
        void Update();
        settrackball m_track;

        void trackball(bool);
        void TrackBall(int,int);
        void Set(l3d_vertex_fast,l3d_vertex_fast,l3d_vertex_fast);
        void SetAngolo(float []);
        void SetUp(float,float,float);
        void SetTrackball(int,int);
        void Draw();
        void Draw(l3d_vertex_fast p,l3d_vertex_fast w,l3d_vertex_fast u);
        ~maincamera(void);
        void AddAngles(float []);

        float GetRadius(void);
        void InitTrackball(void);
};



#endif // MAINCAMERA_H
