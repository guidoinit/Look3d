#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include <math.h>
#include <vector>



#include "frame.h"

#include "baseframe.h"
#include "locx.h"
#include "locy.h"
#include "locz.h"

#include "keyframe.h"
#include "animate.h"

#include "scene/animation/frame.h"
#include "scene/animation/keyframe.h"


#include "mesh/animation/actionvertex.h"
#include "mesh/animation/meshanimation.h"
#include "mesh/animation/meshkeyframe.h"
#include "mesh/animation/meshframe.h"
#include "scene/elements/telecamera.h"
#include "scene/animation/animatedcamera.h"
#include "scene/elements/l3d_light.h"
#include "scene/animation/animatedlight.h"


#include "scene/animation/animationmanager_state.h"

class animationmanager
{
public:
    animationmanager();

    void setstate(animationmanager_state*);
    animationmanager *getmanageranimation();
    void play(int);
    void SetScaleAnimationObject(int aindex,int oindex,float scale[3]);
    void SetInitialState();
    void SetAnimation(int index);
    void SelectObjectAnimation(int ns);
    void DrawEdit();
    void DrawPointer(int*,int*,int*,int*);
    void InitAnimation(int index);
    void PlayAnimation(int nplay);
    void DrawAnimation(int);
    void ViewAnimationFrame(int aindex,int findex);
    void AddNewAnimation(string name, int nframe);
    void AddAnimation(animate);

    void DeleteAnimationFramesAction(int index,int start , int end , int  nobj);
    void DeleteAnimation(int index);
    void ClearAnimationFrame(int index, int findex );
    void ClearAnimationFrameMove(int index, int findex );
    void ClearAnimationFrameScale(int index, int findex );
    void ClearAnimationFrameRotate(int index, int findex );
    void DeleteAnimationFrame(int index,int findex);
    void DeleteAnimationFrames(int index);
    void DeleteAnimationFrameAction(int aindex , int findex , int  nobj);


    //void AddAnimationObject(animatedmesh o3, int index);
    void AddAnimationFrameActionHide(int index,int findex,bool hide);
    void AddAnimationFramesScale(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos );
    void AddAnimationFramesRotate(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos );
    void AddAnimationFramesMove(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos );
    void AddAnimationKeyFrame(int findex);
    void AddAnimationKeyFrameLoc(int findex);
    void AddAnimationFrame(frame frame, int index);
    void AddAnimationFrameAction(action maction,int aindex,int findex);
    animate GetAnimation(int index);
    animate* GetpAnimation(int index);
    int GetSizeAnimation();
    int GetSizeAnimationFrames(int index);
    int GetSizeAnimationObjects(int index);
    l3d_vertex_fast GetWPAnimationObject(int aindex,int index);
    int GetSizeAnimationFrameAction(int aindex,int findex);

    //animatedmesh GetAnimationObject(int aindex,int index);
    //animatedmesh* GetAnimationpObject(int aindex,int index);

    void ScaleAnimation(int index,float fscale[3]);
    void ApplyAnimationFrame(int aindex,int findex);
    void ApplyAnimationFrameActions(int aindex,int findex,int acindex);

    void ApplyScaleAnimationObject(int aindex,int oindex);
    void RotateAnimation(float frotate[3],int index);
    void MoveAnimation(l3d_vertex_fast move, int index);
    void SelectAllObjectsAnimation(int index);
    void UnselectAllObjectsAnimation(int index);
    void SelectAllAnimationObjects(int index);
    void UnselectAllAnimationObjects(int index);
    bool IsPresentAnimationFrame(int aindex, int index);
    bool IsSelectedAnimationObject(int aindex,int oindex);
    void SetWPAppAnimationObject(int aindex,int index,l3d_vertex_fast v);
    void SetWPAnimationObject(int aindex,int index,l3d_vertex_fast v);
    void SetInMoveAnimationObject(int aindex,int oindex,bool bval);
    l3d_vertex_fast gettoolpos(int aindex);
private:
    vector<animate>  m_Animate;
    vector<animatedcamera> m_telecamera;
    vector<animatedlight> m_light;

    animationmanager_state* m_state;

};

#endif // ANIMATIONMANAGER_H
