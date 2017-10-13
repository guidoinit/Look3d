#ifndef ANIMATE_H
#define ANIMATE_H
#include <math.h>
#include <vector>

#include "scene/animation/frame.h"
#include "scene/animation/keyframe.h"

#include "mesh/animation/actionvertex.h"
#include "mesh/animation/meshanimation.h"
#include "mesh/animation/meshkeyframe.h"
#include "mesh/animation/meshframe.h"

#include "mesh/l3d_mesh.h"
#include "mesh/l3d_action.h"
#include "scene/animation/l3d_frame.h"


using namespace l3d::mesh;

class animate
{
public:

    int m_nNumFrame;
    string m_StrName;


    animate();
    animate(string);
    ~animate();
    l3d_frame_list m_frames;
    void AddObject(l3d_mesh_struct);
    int GetSizeObject();
    void GenerateAction();
    int GetPrevFrame(int iobject,int iframe ,int iaction);
    l3d_vertex_fast *GetWPObject(int index);
    l3d_vertex_fast GetWPObjectFrame(int findex,int oindex);
    l3d_vertex_fast GetScaleObjectFrame(int findex,int oindex);
    l3d_vertex_fast GetRotateObjectFrame(int findex,int oindex);
    l3d_mesh_struct * GetObject(int);
    int IsKFPresent(keyframe kf);
    keyframe *GetKeyFrame(int kindex);
    animate( const animate &ani )
    {

            l3d_uint x,nindex;
            m_nNumFrame= ani.m_nNumFrame;
            m_StrName=ani.m_StrName;

            nindex=m_frames.size();

            //for (x=0; x< nindex ; x++)
            //        m_frames.add((pl3d_frame)ani.m_frames.get(x));

            /*nindex=m_ostate.size();
            for (x=0; x< nindex ; x++)
                    m_ostate.push_back((object3d &)ani.m_ostate.at(x));

            nindex=m_ostatevertex.size();
            for (x=0; x< nindex ; x++)
                    m_ostatevertex.push_back((vertex &)ani.m_ostatevertex.at(x));

            nindex=m_keyframe.size();
            for (x=0; x< nindex ; x++)
                    m_keyframe.push_back((keyframe&)ani.m_keyframe.at(x));*/

     }
    animate& operator=( const animate &ani )
    {
            l3d_uint x;
            m_nNumFrame= ani.m_nNumFrame;
            m_StrName=ani.m_StrName;

            //l3d_uint nindex=ani.m_frames.size();
            //for (x=0; x< nindex ; x++)
              //      m_frames.add(ani.m_frames.get(x));
/*
            nindex=m_ostate.size();
            for (x=0; x< nindex ; x++)
                    m_ostate.push_back((object3d &)ani.m_ostate.at(x));

            nindex=m_ostatevertex.size();
            for (x=0; x< nindex ; x++)
                    m_ostatevertex.push_back((vertex &)ani.m_ostatevertex.at(x));

            nindex=m_keyframe.size();
            for (x=0; x< nindex ; x++)
                    m_keyframe.push_back((keyframe&)ani.m_keyframe.at(x));
*/
            return *this;
    }


    //virtual void Serialize(CArchive& ar);
    l3d_vertex_fast GetObjectAngolo(int index);
    l3d_vertex_fast GetObjectScale(int index);
    void SetInitialState(int io);

    void AddKeyFrame(keyframe mkeyframe);


private:
    l3d_mesh m_ostate;
    l3d_vertex m_ostatevertex;
    l3d_vertex m_ostateangolo;
    l3d_vertex m_ostatescale;
    std::vector<keyframe> m_keyframe;

    void DeleteActionKeyframe();
    void SortKeyframe();

    void GenerateActionMove();
    void GenerateActionRotate();
    void GenerateActionScale();

protected:

};
#endif // ANIMATE_H
