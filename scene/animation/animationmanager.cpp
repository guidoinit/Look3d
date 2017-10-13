#include <cmath>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

//#include "mesh/object3dinclude.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_uv.h"
#include "mesh/l3d_transform.h"
#include "mesh/l3d_material.h"
#include "mesh/l3d_vertex_group.h"
#include "l3d_blend.h"
#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "frame.h"

#include "baseframe.h"
#include "locx.h"
#include "locy.h"
#include "locz.h"

#include "keyframe.h"
#include "animate.h"




#include "animationmanager.h"

animationmanager::animationmanager()
{
}

void animationmanager::setstate(animationmanager_state* s)
{
    m_state=s;



}
animationmanager *animationmanager::getmanageranimation()
{
    //return(this);
}

void animationmanager::play(int np)
{
    if( np < 0 || np >= m_Animate.size() )
    {
            m_state->m_bplay=false;

            m_state->m_iframe=-1;

            m_state->m_iplay=-1;

            return;
    }

    m_state->m_iframe=0;

    m_state->m_iplay=np;

    m_state->m_bplay=true;
}

void animationmanager::SetScaleAnimationObject(int aindex,int oindex,float scale[3])
{
    Q_ASSERT(aindex >=0 && aindex < m_Animate.size());
    Q_ASSERT(oindex >=0 && oindex < GetSizeAnimationObjects(aindex));

    if(std::abs(1.0F-scale[0])!=0)
            m_Animate[aindex].GetObject(oindex)->_transformation._scale.x=scale[0];
    if(std::abs(1.0F-scale[1])!=0)
            m_Animate[aindex].GetObject(oindex)->_transformation._scale.y=scale[1];
    if(std::abs(1.0F-scale[2])!=0)
            m_Animate[aindex].GetObject(oindex)->_transformation._scale.z=scale[2];

}

void animationmanager::SetInitialState()
{
        if(m_Animate.size()==0)
                return;
        if(m_state->m_ianiselect>=0 && m_state->m_ianiselect< m_Animate.size())
        {
                int size=m_Animate[m_state->m_ianiselect].GetSizeObject();

                for(int ix=0; ix < size; ix++)
                {
                        if(m_Animate[m_state->m_ianiselect].GetObject(ix)->_pick._selected)
                        {
                                m_Animate[m_state->m_ianiselect].SetInitialState(ix);
                        }
                }
        }
}
void animationmanager::SetAnimation(int index)
{
        m_state->m_ianiselect=index;
}


void animationmanager::SelectObjectAnimation(int ns)
{


        int osel=-1;



        if(m_state->m_ianiselect==-1)
                return;
        int nSize=m_Animate[m_state->m_ianiselect].GetSizeObject();

        if(m_state->m_moveobj[0] || m_state->m_moveobj[1] || m_state->m_moveobj[2])
        {
                action cact;
                l3d_vertex_fast vapp;

                for (int nIndex=0; nIndex<nSize; nIndex++)
                {
                        if(m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick._selected)
                        {
                                //vapp=m_Animate[m_state->m_ianiselect].GetObject(nIndex)->world_pos;

                                //cact.SetActionSposta(vapp);
                                cact.m_nObject=nIndex;

                                //m_Animate[m_state->m_ianiselect].GetObject(nIndex)->AddAction(cact);

                        }
                }


        }
        m_state->m_moveobj[0]=false;
        m_state->m_moveobj[1]=false;
        m_state->m_moveobj[2]=false;
        if(ns!=20000 && ns!=20001 && ns!=20002)
        {
                for (int nIndex=0; nIndex<nSize; nIndex++)

                {


                        //pDoc->m_object[nIndex].Selected=false;
                        if (ns == m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick._iname)
                        {
                                m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick.selected(true);


                                osel=nIndex;
                        }



                }	//verificare se una m_telecamera  stata selezionata
                nSize=m_telecamera.size();

                for (int nIndex=0; nIndex<nSize; nIndex++)

                {
                        m_telecamera[nIndex].SetSelected(false);
                        if (ns == m_telecamera[nIndex].GetName())
                                m_telecamera[nIndex].SetSelected(true);


                }

        }
        else if (ns==20000)
        {

                m_state->m_moveobj[0]=true;

        }
        else if (ns==20001)

                m_state->m_moveobj[1]=true;

        else if (ns==20002)

                m_state->m_moveobj[2]=true;

        if(m_state->m_moveobj[0]||m_state->m_moveobj[1]||m_state->m_moveobj[2])
        {
               m_state-> m_bmove=true;
                nSize=m_Animate[m_state->m_ianiselect].GetSizeObject();

                for (int nIndex=0; nIndex<nSize; nIndex++)

                        if ( m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick.selected())

                                ;//m_Animate[m_state->m_ianiselect].GetObject(nIndex)->RecPos();



        }

        nSize=m_Animate[m_state->m_ianiselect].GetSizeObject();

        if(osel!=-1 && !m_state->m_bShift)

                for (int nIndex=0; nIndex<nSize; nIndex++)

                        if(nIndex!=osel)

                                m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick.selected(false);


}
void animationmanager::DrawEdit()
{


        if(!(m_state->m_ianiselect >=0 && m_state->m_ianiselect<m_Animate.size()))
                return;



        int nSize=m_Animate[m_state->m_ianiselect].GetSizeObject();
        int nSizet,nIndex;


        //m_oMoveEdit.DrawSelect();



        for (nIndex=0; nIndex<nSize; nIndex++)
        {
            //to-do aggiungere meshselect per la selezione
            //_select.setname(nIndex+1);
            m_Animate[m_state->m_ianiselect].GetObject(nIndex)->_pick._iname=nIndex+1;



            //_select.selectobject(m_Animate[m_state->m_ianiselect].GetObject(nIndex));



        }
        nSizet=nIndex+100;
/*	nSize=m_mash.size();
        for (nIndex=0; nIndex<nSize; nIndex++)

        {

                m_mash[nIndex].SetName(nSizet++);
                m_mash[nIndex].DrawSelect();

                m_oMove.SetWorldPos(pDoc->m_mash[nIndex].world_pos.GetX(),pDoc->m_mash[nIndex].world_pos.GetY(),pDoc->m_mash[nIndex].world_pos.GetZ());
                m_oMove.DrawSelect();


        }*/

        nSizet+=100;
        //disegna le telecamere
        nSize=m_telecamera.size();
        for (nIndex=0; nIndex<nSize; nIndex++)

        {
                glLoadName(nSizet);
                m_telecamera[nIndex].SetName(nSizet++);
                m_telecamera[nIndex].Draw();


        }
        //disegna le luci

        nSizet+=100;

        /*nSize=m_light.size();

        for (nIndex=0; nIndex<nSize; nIndex++)

        {

                m_light[nIndex].SetName(nSizet+=5);

                m_light[nIndex].DrawSelect();

        }
        */





}
void animationmanager::DrawPointer(int* first,int* wp0,int*wp1,int*wp2)
{
    if(m_state->m_ianiselect < 0 || m_state->m_ianiselect> m_Animate.size())
        return;
    int nSize=m_Animate[m_state->m_ianiselect].GetSizeObject();
    for (int x=0 ; x < nSize ; x++)
    {
        if(m_Animate[m_state->m_ianiselect].GetObject(x)->_pick.selected())
        {
               *wp0+=m_Animate[m_state->m_ianiselect].GetObject(x)->_transformation._wp.x;
               *wp1+=m_Animate[m_state->m_ianiselect].GetObject(x)->_transformation._wp.y;
               *wp2+=m_Animate[m_state->m_ianiselect].GetObject(x)->_transformation._wp.z;
                *first++;

        }
    }

    if(*first>1)
    {

        (*wp0)/=*first;
        (*wp1)/=*first;
        (*wp2)/=*first;

    }
}

void animationmanager::InitAnimation(int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());

        for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)
        {
                //animatedmesh * obj=m_Animate[index].GetObject(ix);

               // Q_ASSERT(obj!=0);

                //imposta lo stato iniziale worldpos
                //obj->world_pos=*m_Animate[index].GetWPObject(ix);

                //imposta l'angolo iniziale

                //obj->m_angolo[0]=m_Animate[index].GetObjectAngolo(ix).GetX();
                /*obj->m_angolo[1]=m_Animate[index].GetObjectAngolo(ix).GetY();
                obj->m_angolo[2]=m_Animate[index].GetObjectAngolo(ix).GetZ();
                //imposta il f. scala iniziale

                obj->m_Scale[0]=m_Animate[index].GetObjectScale(ix).GetX();
                obj->m_Scale[1]=m_Animate[index].GetObjectScale(ix).GetY();
                obj->m_Scale[2]=m_Animate[index].GetObjectScale(ix).GetZ();


                obj->m_bhide=false;

                obj=NULL;*/

        }

}

void animationmanager::PlayAnimation(int nplay)
{
        Q_ASSERT(nplay>=0 && nplay <m_Animate.size());

        if(nplay <0 || nplay > m_Animate.size())
                return;
        if(m_state->m_iframe==0)
        {
                InitAnimation(nplay);

        }

        for(int ix=0; ix < m_Animate[nplay].GetSizeObject(); ix++)
        {
                /*object3d * obj=m_Animate[nplay].GetObject(ix);
                if(obj->m_bhide)
                        continue;
                switch(m_state->m_mode)
                {
                case SCENE::solid:
                        obj->DrawSolid(true);
                        break;
                case SCENE::wireframe:
                        obj->DrawWireframe(true);
                        break;
                case SCENE::color:
                        obj->DrawColor(true);
                        break;
                case SCENE::mtexture:
                        obj->DrawTexture();
                        break;
                }*/

        }

        ApplyAnimationFrame(nplay,m_state->m_iframe);

        m_state->m_iframe++;

        if(m_state->m_iframe > m_Animate[nplay].m_frames.size())
                m_state->m_iframe=0;



}
void animationmanager::DrawAnimation(int index)
{



    if(index>=0 && index < m_Animate.size())
    {


        //disegna tutti gli oggetti della scena

        for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)

        {
                //animatedmesh *obj=m_Animate[index].GetObject(ix);

                //obj->DrawVBO(m_state->m_mode);
                /*switch(m_state->m_mode)

                {
                        case SCENE::solid:
                                glDisable(GL_LIGHTING);

                                obj->DrawPoligon4();
                                obj->DrawPoligon3();
                                glEnable(GL_LIGHTING);
                        break;
                        case SCENE::wireframe:
                                obj->DrawLines();

                                //obj->DrawLines();
                        break;
                        case SCENE::color:
                                obj->DrawMaterial(true);
                        break;
                        case SCENE::mtexture:
                                obj->DrawTexture();
                        break;
                }*/

        }

        //disegna le luci

    /*    for(int ix=0; ix < m_aligth.size(); ix++)
        {

                ligth pligth=m_aligth.at(ix);

                pligth.Draw();

        }

        //disegna le telecamere
        for(int ix=0; ix < m_telecamera.size() ; ix++)
        {

                telecamera ptel=m_telecamera.at(ix);

                ptel.Draw();

        }
    */
    }

}
void animationmanager::ViewAnimationFrame(int aindex,int findex)
{
        Q_ASSERT(aindex >=0 && aindex < m_Animate.size());

        Q_ASSERT(findex >= 0 && findex < m_Animate[aindex].m_frames.size());

        for(int ix=0; ix <= findex; ix++)
        {
                if(ix==0)
                {
                        InitAnimation(aindex);
                }
                else
                        ApplyAnimationFrame(aindex,ix);
        }



}
void animationmanager::AddNewAnimation(string name, int nframe)
{
        animate nani;
        nani.m_StrName=name;

        //for(int ix=0; ix < nframe; ix7++)
          //      nani.m_frames.add();
        //m_Animate.push_back(nani);

}

void animationmanager::AddAnimation(animate newani)
{
        //m_Animate.push_back(newani);

}

void animationmanager::DeleteAnimationFramesAction(int index,int start , int end , int  nobj)
{
    Q_ASSERT(index >=0 && index < m_Animate.size());

    for(int ix=start; ix <end; ix++)
            DeleteAnimationFrameAction(index,ix,nobj);


}
void animationmanager::DeleteAnimation(int index)
{
    Q_ASSERT(index >=0 && index < m_Animate.size());

    //m_Animate.erase(m_Animate.begin()+index);
}
 void animationmanager::ClearAnimationFrame(int index, int findex )
 {
     Q_ASSERT(index >=0 && index < m_Animate.size());

     Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());

     //m_Animate[index].m_frames[findex].m_vaction.clear();

 }
 void animationmanager::ClearAnimationFrameMove(int index, int findex )
 {
     Q_ASSERT(index >=0 && index < m_Animate.size());

     Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());

     //std::vector <action> * paction=*m_Animate[index].m_frames[findex].m_vaction;

     /*
     for(int ix=0;ix <paction->size(); ix++)
             if(paction[ix]->GetAction()==1)
             {
                     paction->erase(paction->begin()+ix);
                     ix--;
             }
     */
     /*for(int ix=0;ix <m_Animate[index].m_frames[findex].m_vaction.size(); ix++)
             if(m_Animate[index].m_frames[findex].m_vaction[ix].GetAction()==1)
             {
                     m_Animate[index].m_frames[findex].m_vaction.erase(m_Animate[index].m_frames[findex].m_vaction.begin()+ix);
                     ix--;
             }

*/
 }
void animationmanager::ClearAnimationFrameScale(int index, int findex )
 {
    Q_ASSERT(index >=0 && index < m_Animate.size());

    Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());

    /*for(int ix=0;ix <m_Animate[index].m_frames[findex].m_vaction.size(); ix++)
            if(m_Animate[index].m_frames[findex].m_vaction[ix].GetAction()==3)
            {
                    m_Animate[index].m_frames[findex].m_vaction.erase(m_Animate[index].m_frames[findex].m_vaction.begin()+ix);
                    ix--;
            }

*/

 }
void animationmanager::ClearAnimationFrameRotate(int index, int findex )
 {
    Q_ASSERT(index >=0 && index < m_Animate.size());

    Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());

  /*  for(int ix=0;ix <m_Animate[index].m_frames[findex].m_vaction.size(); ix++)
            if(m_Animate[index].m_frames[findex].m_vaction[ix].GetAction()==2)
            {
                    m_Animate[index].m_frames[findex].m_vaction.erase(m_Animate[index].m_frames[findex].m_vaction.begin()+ix);
                    ix--;
            }

*/
 }
void animationmanager::DeleteAnimationFrame(int index,int findex)
{
    Q_ASSERT(index >=0 && index < m_Animate.size());

    Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());


  //  m_Animate[index].m_frames.erase( m_Animate[index].m_frames.begin()+findex);


}
void animationmanager::DeleteAnimationFrames(int index)
{
    Q_ASSERT(index >=0 && index < m_Animate.size());

    //m_Animate[index].m_frames.clear();

}
void animationmanager::DeleteAnimationFrameAction(int aindex , int findex , int  nobj)
{
    Q_ASSERT(aindex >=0 && aindex < m_Animate.size());
    //Q_ASSERT(findex >=0 && findex < m_Animate[aindex].m_frames.size());
    if(findex <0 || findex >= m_Animate[aindex].m_frames.size())
            return;
    int ia=0;
    //int nact=m_Animate[aindex].m_frames[findex].m_vaction.size();
    /*for(ia=0; ia < nact &&  nact > 0 ;ia++)
    {
            if(m_Animate[aindex].m_frames[findex].m_vaction[ia].m_nObject == nobj)
            {
                    m_Animate[aindex].m_frames[findex].m_vaction.erase(m_Animate[aindex].m_frames[findex].m_vaction.begin()+ia);
                    nact=m_Animate[aindex].m_frames[findex].m_vaction.size();
                    ia--;
            }
    }*/


}


/*void animationmanager::AddAnimationObject(animatedmesh o3, int index)
{
    o3.makevbo();
    if(index>=0 && index <m_Animate.size())
        m_Animate[index].AddObject(o3);

}*/
void animationmanager::AddAnimationFrameActionHide(int index,int findex,bool hide)
{
        Q_ASSERT(index>=0 && index < m_Animate.size());

        Q_ASSERT(findex >=0 && findex < m_Animate[index].m_frames.size());

        if(GetSizeAnimationObjects(index) <=0 )
                return;

        for(int ix=0; ix < GetSizeAnimationObjects(index); ix++)
        {
                if(this->IsSelectedAnimationObject(index,ix))
                {
                        action act;

                        act.SetActionHide(hide);

                        act.m_nObject=ix;

                        AddAnimationFrameAction(act,index,findex);
                }
        }
}
void animationmanager::AddAnimationFramesScale(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos )
{
        if(fstart > fend)
                return;

        if(index <0 || index >= m_Animate.size())
                return;

        if(oindex <0 || oindex >= m_Animate[index].GetSizeObject())
                return;

        if (fstart > GetSizeAnimationFrames(index))
                return;

        float step[3]={0.0F,0.0F,0.0F};
        float apstep[3];

        step[0]=(finalpos.x-1.0F)/(fend-fstart);
        step[1]=(finalpos.y-1.0F)/(fend-fstart);
        step[2]=(finalpos.z-1.0F)/(fend-fstart);

        apstep[0]=step[0];
        apstep[1]=step[1];
        apstep[2]=step[2];


        //DeleteAnimationFramesAction(index,fstart,fend,oindex);

        int ic=0;
        for(int ix=fstart; ix < fend; ix++)
        {
                action maction;



                apstep[0]=(step[0]);
                apstep[1]=(step[1]);
                apstep[2]=(step[2]);


                maction.SetActionScala(apstep);

                maction.m_nObject=oindex;


                ic++;


                if(!IsPresentAnimationFrame(index,ix))
                {
                        AddAnimationFrame(frame(),index);
                        AddAnimationFrameAction(maction,index,GetSizeAnimationFrames(index)-1);
                }
                else
                        AddAnimationFrameAction(maction,index,ix);

        }

}


void animationmanager::AddAnimationFramesRotate(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos )
{
        if(fstart > fend)
                return;

        if(index <0 || index >= m_Animate.size())
                return;

        if(oindex <0 || oindex >= m_Animate[index].GetSizeObject())
                return;

        if (fstart > GetSizeAnimationFrames(index))
                return;

        float step[3]={0.0F,0.0F,0.0F};
        float apstep[3];

        step[0]=finalpos.x/(fend-fstart);
        step[1]=finalpos.y/(fend-fstart);
        step[2]=finalpos.z/(fend-fstart);

        apstep[0]=step[0];
        apstep[1]=step[1];
        apstep[2]=step[2];


        //DeleteAnimationFramesAction(index,fstart,fend,oindex);

        int ic=0;
        for(int ix=fstart; ix < fend; ix++)
        {
                action maction;



                apstep[0]=(step[0]);
                apstep[1]=(step[1]);
                apstep[2]=(step[2]);


                maction.SetActionRuota(apstep);
                maction.m_nObject=oindex;


                ic++;


                if(!IsPresentAnimationFrame(index,ix))
                {
                        AddAnimationFrame(frame(),index);
                        AddAnimationFrameAction(maction,index,GetSizeAnimationFrames(index)-1);
                }
                else
                        AddAnimationFrameAction(maction,index,ix);

        }

}
void animationmanager::AddAnimationFramesMove(int index,int oindex, int fstart, int fend, l3d_vertex_fast finalpos )
{
        if(fstart > fend)
                return;

        if(index <0 || index >= m_Animate.size())
                return;

        if(oindex <0 || oindex >= m_Animate[index].GetSizeObject())
                return;

        if (fstart > GetSizeAnimationFrames(index))
                return;

        float step[3]={0.0F,0.0F,0.0F};
        float apstep[3];

        step[0]=finalpos.x/(fend-fstart);
        step[1]=finalpos.y/(fend-fstart);
        step[2]=finalpos.z/(fend-fstart);

        apstep[0]=step[0];
        apstep[1]=step[1];
        apstep[2]=step[2];


        //DeleteAnimationFramesAction(index,fstart,fend,oindex);

        int ic=0;
        for(int ix=fstart; ix < fend; ix++)
        {
                action maction;



                //vertex wp=GetWPAnimationObject(index,oindex); ?? da rivedere

                apstep[0]=(step[0]);
                apstep[1]=(step[1]);
                apstep[2]=(step[2]);


                maction.SetActionSposta(apstep);
                maction.m_nObject=oindex;


                ic++;


                if(!IsPresentAnimationFrame(index,ix))
                {
                        AddAnimationFrame(frame(),index);
                        AddAnimationFrameAction(maction,index,GetSizeAnimationFrames(index)-1);
                }
                else
                        AddAnimationFrameAction(maction,index,ix);

        }


}
void animationmanager::AddAnimationKeyFrame(int findex)
{
        Q_ASSERT(m_state->m_ianiselect>=0);
        Q_ASSERT(findex >=0  &&  findex < m_Animate[m_state->m_ianiselect].m_frames.size());



        for(int ix=0; ix < GetSizeAnimationObjects(m_state->m_ianiselect); ix++)
        {
                //if(GetAnimationpObject(m_state->m_ianiselect,ix)->m_bselected)
                {
                        //trovare il frame precedente
                        int fprev;


                        action act;
                        l3d_vertex_fast vmove;
                        float krotate[3]={0.0F,0.0F,0.0F};
                        float kscale[3]={1.0F,1.0F,1.0F};



                  //      object3d *pobj=GetAnimationpObject(m_state->m_ianiselect,ix);


                        if(m_state->m_bismove)
                        {
                                //passare differenza dell'oggetto all'ultimo keyframe con posizione attuale



                                //act.SetActionSposta(vmove);

                                act.m_nObject=ix;
                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,1);


                                //l3d_vertex_fast pver=m_Animate[m_state->m_ianiselect].GetWPObjectFrame(fprev,ix);

                    //            vmove.set(pobj->world_pos.x-pver.x,pobj->world_pos.y-pver.y,pobj->world_pos.z-pver.z);


                                //relative loc

                                locx *nlocx=new locx(fprev,findex,vmove.x);
                                locy *nlocy=new locy(fprev,findex,vmove.y);
                                locz *nlocz=new locz(fprev,findex,vmove.z);


                                keyframe kframe(KEYFRAME::kf_moverelative,fprev,findex);

                                kframe.setobject(ix);

                                kframe.setdloc(nlocx);
                                kframe.setdloc(nlocy);
                                kframe.setdloc(nlocz);

                                //kframe.SetAction(act);

                                m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe);
                        }



                        //krotate[0]=pobj->m_angolo[0];
                        //krotate[1]=pobj->m_angolo[1];
                        //krotate[2]=pobj->m_angolo[2];



                        if(m_state->m_bisrotate)
                        {
                                act.SetActionRuota(krotate);

                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,2);
                                act.m_nObject=ix;


                                //l3d_vertex_fast pver=m_Animate[m_state->m_ianiselect].GetRotateObjectFrame(fprev,ix);

                                keyframe kframe2(KEYFRAME::kf_rotaterelative,fprev,findex);


                                //locx *nlocx=new locx(fprev,findex,pobj->m_angolo[0]-pver.x);
                                //locy *nlocy=new locy(fprev,findex,pobj->m_angolo[1]-pver.y);
                                //locz *nlocz=new locz(fprev,findex,pobj->m_angolo[2]-pver.z);

                                kframe2.setobject(ix);

                               // kframe2.setrdloc(nlocx);
                                //kframe2.setrdloc(nlocy);
                                //kframe2.setrdloc(nlocz);



                                m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe2);

                        }



                        //kscale[0]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[0];
                        //kscale[1]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[1];
                        //kscale[2]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[2];




                        if(m_state->m_bisscale)
                        {
                                act.SetActionScala(kscale);

                                act.m_nObject=ix;

                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,3);

                                //l3d_vertex_fast pver=m_Animate[m_state->m_ianiselect].GetScaleObjectFrame(fprev,ix);

                                keyframe kframe3(KEYFRAME::kf_scalerelative,fprev,findex);

                                //locx *nlocx=new locx(fprev,findex,pobj->m_Scale[0]-pver.x);
                                //locy *nlocy=new locy(fprev,findex,pobj->m_Scale[1]-pver.y);
                                //locz *nlocz=new locz(fprev,findex,pobj->m_Scale[2]-pver.z);

                                kframe3.setobject(ix);

                                //kframe3.setsdloc(nlocx);
                                //kframe3.setsdloc(nlocy);
                                //kframe3.setsdloc(nlocz);

                                m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe3);
                        }



                }
        }
        //to-do eseguire il controllo in CAnimate dell'inserimento dei keyframe
        m_state->m_bismove=false;
        m_state->m_bisrotate=false;
        m_state->m_bisscale=false;

        m_Animate[m_state->m_ianiselect].GenerateAction();






}
void animationmanager::AddAnimationKeyFrameLoc(int findex)
{
        Q_ASSERT(m_state->m_ianiselect>=0);
        Q_ASSERT(findex >=0  &&  findex < m_Animate[m_state->m_ianiselect].m_frames.size());



        for(int ix=0; ix < GetSizeAnimationObjects(m_state->m_ianiselect); ix++)
        {
                //if(GetAnimationpObject(m_state->m_ianiselect,ix)->m_bselected)
                {

                        int fprev;


                        action act;
                        l3d_vertex_fast vmove;
                        float krotate[3]={0.0F,0.0F,0.0F};
                        float kscale[3]={1.0F,1.0F,1.0F};



                  //      object3d *pobj=GetAnimationpObject(m_state->m_ianiselect,ix);


                //	if(m_bismove)
                        {
                    //            vmove.Set(pobj->world_pos.x,pobj->world_pos.y,pobj->world_pos.z);

                                act.SetActionSposta(vmove);

                                act.m_nObject=ix;
                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,1);

                                //relative loc
                                locx *nlocx=new locx(fprev,findex,vmove.x);
                                locy *nlocy=new locy(fprev,findex,vmove.y);
                                locz *nlocz=new locz(fprev,findex,vmove.z);


                                keyframe kframe(KEYFRAME::kf_movelocal,fprev,findex);

                                kframe.setobject(ix);

                                kframe.setloc(nlocx);
                                kframe.setloc(nlocy);
                                kframe.setloc(nlocz);



                                m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe);
                        }

                        m_state->m_bismove=false;

                        //krotate[0]=pobj->m_angolo[0];
                        //krotate[1]=pobj->m_angolo[1];
                        //krotate[2]=pobj->m_angolo[2];



                //	if(m_bisrotate)
                        {
                                act.SetActionRuota(krotate);

                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,2);
                                act.m_nObject=ix;
                                keyframe kframe2(KEYFRAME::kf_rotatelocal,fprev,findex);

                                kframe2.setobject(ix);

                                //locx *nlocx=new locx(fprev,findex,pobj->m_angolo[0]);
                                //locy *nlocy=new locy(fprev,findex,pobj->m_angolo[1]);
                                //locz *nlocz=new locz(fprev,findex,pobj->m_angolo[2]);

                               // kframe2.setrloc(nlocx);
                               // kframe2.setrloc(nlocy);
                               // kframe2.setrloc(nlocz);

                               // m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe2);

                        }

                        m_state->m_bisrotate=false;

                        //kscale[0]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[0];
                        //kscale[1]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[1];
                        //kscale[2]=GetAnimationpObject(m_state->m_ianiselect,ix)->m_Scale[2];




                //	if(m_bisscale)
                        {

                                fprev=m_Animate[m_state->m_ianiselect].GetPrevFrame(ix,findex,3);

                                keyframe kframe3(KEYFRAME::kf_scalelocal,fprev,findex);

                                kframe3.setobject(ix);

                               // locx *nlocx=new locx(fprev,findex,pobj->m_Scale[0]);
                                //locy *nlocy=new locy(fprev,findex,pobj->m_Scale[1]);
                                //locz *nlocz=new locz(fprev,findex,pobj->m_Scale[2]);

                                //kframe3.setsloc(nlocx);
                               // kframe3.setsloc(nlocy);
                               // kframe3.setsloc(nlocz);

                               // m_Animate[m_state->m_ianiselect].AddKeyFrame(kframe3);

                        }



                }
        }
        //to-do eseguire il controllo in CAnimate dell'inserimento dei keyframe

        m_Animate[m_state->m_ianiselect].GenerateAction();






}
void animationmanager::AddAnimationFrame(frame frame, int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());
        //if(index>=0 && index < m_Animate[index].m_frames.size())
    //    m_Animate[index].m_frames.push_back(frame);
}
void animationmanager::AddAnimationFrameAction(action maction,int aindex,int findex)
{
        Q_ASSERT(aindex >=0 && aindex < m_Animate.size());
        Q_ASSERT(findex >=0 && findex < m_Animate[aindex].m_frames.size());

      //  m_Animate[aindex].m_frames[findex].m_vaction.push_back(maction);

}
animate animationmanager::GetAnimation(int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());

        return (m_Animate.at(index));


}

animate* animationmanager::GetpAnimation(int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());

        return (&m_Animate.at(index));


}

int animationmanager::GetSizeAnimation()
{
    return	(m_Animate.size());
}
int animationmanager::GetSizeAnimationFrames(int index)
{
        if(index >=0 && index < GetSizeAnimation())
                return m_Animate[index].m_frames.size();
        return -1;
}

int animationmanager::GetSizeAnimationObjects(int index)
{
        if(index >=0 && index < GetSizeAnimation())
                return m_Animate[index].GetSizeObject();
        return -1;
}

l3d_vertex_fast animationmanager::GetWPAnimationObject(int aindex,int index)
{
        pl3d_vertex_fast pver=NULL;

        if(aindex <0 || aindex >= GetSizeAnimation())
                return *pver;
        if(index <0 || index >= GetSizeAnimationObjects(aindex))
                return *pver;

        return (*pver);//m_Animate[aindex].GetObject(index)->world_pos);


}

int animationmanager::GetSizeAnimationFrameAction(int aindex,int findex)
{
        if(aindex <0 || aindex >= GetSizeAnimation())
                return -1;
        if(findex <0 || findex >= GetSizeAnimationFrames(aindex))
                return -1;

        //return (m_Animate[aindex].m_frames[findex].m_vaction.size());
        return(0);

}
/*
animatedmesh animationmanager::GetAnimationObject(int aindex,int index)
{

        Q_ASSERT(aindex >=0 && aindex < GetSizeAnimation());
        Q_ASSERT(index >=0 && index < GetSizeAnimationObjects(aindex));

        return (*m_Animate[aindex].GetObject(index));
}

animatedmesh *animationmanager::GetAnimationpObject(int aindex,int index)
{

        Q_ASSERT(aindex >=0 && aindex < GetSizeAnimation());
        Q_ASSERT(index >=0 && index < GetSizeAnimationObjects(aindex));


        return (m_Animate[aindex].GetObject(index));
}
*/

void animationmanager::ScaleAnimation(int index,float fscale[3])
{
        if(index<0 || index >= m_Animate.size())
                return;

        int nSize=m_Animate[index].GetSizeObject();
        m_state->m_bisscale=false;
        for(int ix=0; ix < nSize; ix++)
        {
  //              if(m_Animate[index].GetObject(ix)->m_bselected)
                {
    //                    m_Animate[index].GetObject(ix)->m_Scale[0]+=fscale[0];
      //                  m_Animate[index].GetObject(ix)->m_Scale[1]+=fscale[1];
        //                m_Animate[index].GetObject(ix)->m_Scale[2]+=fscale[2];
                        m_state->m_bisscale=true;
                }
        }

}
void animationmanager::ApplyAnimationFrame(int aindex,int findex)
{
        if(aindex<0 || aindex >= m_Animate.size())
                return;
        if(findex<0 || findex >= m_Animate[aindex].m_frames.size())
                return;

        //for(int ix=0; ix < m_Animate[aindex].m_frames[findex].m_vaction.size();ix++)
        //        ApplyAnimationFrameActions(aindex,findex,ix);


}
void animationmanager::ApplyAnimationFrameActions(int aindex,int findex,int acindex)
{
        if(aindex<0 || aindex >= m_Animate.size())
                return;
        if(findex<0 || findex >= m_Animate[aindex].m_frames.size())
                return;
       // if(acindex<0 || acindex >= m_Animate[aindex].m_frames[findex].m_vaction.size())
                return;

        for(int ix=0; ix < m_Animate[aindex].GetSizeObject(); ix++)
        {
         //       object3d* obj=NULL;
        //        obj=m_Animate[aindex].GetObject(ix);

          //      action act=m_Animate[aindex].m_frames[findex].m_vaction.at(acindex);

            //    if(obj!=NULL && act.m_nObject==ix)
              //          obj->DoAction(act);


        }





}
void animationmanager::ApplyScaleAnimationObject(int aindex,int oindex)
{
        if(aindex <0 || aindex >= m_Animate.size())
                return;
        if(oindex <0 || oindex >= m_Animate[aindex].GetSizeObject())
                return;

 //       m_Animate[aindex].GetObject(oindex)->Scale();


}


void animationmanager::RotateAnimation(float frotate[3],int index)
{

        if(index<0 || index >= m_Animate.size())
                return;

        int nSize=m_Animate[index].GetSizeObject();
        m_state->m_bisrotate=false;
        for(int ix=0; ix < nSize; ix++)
        {
   //             if(m_Animate[index].GetObject(ix)->m_bselected)
                {
     //                   m_Animate[index].GetObject(ix)->m_angolo[0]+=frotate[0];
       //                 m_Animate[index].GetObject(ix)->m_angolo[1]+=frotate[1];
         //               m_Animate[index].GetObject(ix)->m_angolo[2]+=frotate[2];
            //            m_state->m_bisrotate=true;
                }
        }

}
void animationmanager::MoveAnimation(l3d_vertex_fast move, int index)
{
        /*if(index<0 || index >= m_Animate.size())
                return;
        int nSize=m_Animate[index].GetSizeObject();

        for(int ix=0; ix < nSize; ix++)
        {
                if(m_Animate[index].GetObject(ix)->m_bselected)
                {
                        m_Animate[index].GetObject(ix)->world_pos.Move(move);

                }
        }*/

}
void animationmanager::SelectAllObjectsAnimation(int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());

        if(m_Animate[index].GetSizeObject()<=0)
                return;
      //  for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)
        //        m_Animate[index].GetObject(ix)->SetSelected(true);


}
void animationmanager::UnselectAllObjectsAnimation(int index)
{
        Q_ASSERT(index >=0 && index < m_Animate.size());

        if(m_Animate[index].GetSizeObject()<=0)
                return;
       // for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)
         //       m_Animate[index].GetObject(ix)->SetSelected(false);


}

void animationmanager::SelectAllAnimationObjects(int index)
{
        if(index<0 || index >= m_Animate.size())
                return;

        if(this->GetSizeAnimationObjects(index)<=0)
                return;

       // for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)
         //       m_Animate[index].GetObject(ix)->SetSelected(true);
}

void animationmanager::UnselectAllAnimationObjects(int index)
{
        if(index<0 || index >= m_Animate.size())
                return;

        if(this->GetSizeAnimationObjects(index)<=0)
                return;

   //     for(int ix=0; ix < m_Animate[index].GetSizeObject(); ix++)
     //           m_Animate[index].GetObject(ix)->SetSelected(false);
}
bool animationmanager::IsPresentAnimationFrame(int aindex, int index)
{
        bool rf=false;

        if(aindex <0 || aindex >= m_Animate.size())
                return rf;
        if(index <0 || index >= m_Animate[aindex].m_frames.size())
                return rf;

        return true;


}
bool animationmanager::IsSelectedAnimationObject(int aindex,int oindex)
{
        bool rf=false;

        if(aindex <0 || aindex >= m_Animate.size())
                return rf;
        if(oindex <0 || oindex >= m_Animate[aindex].GetSizeObject())
                return rf;

       // return m_Animate[aindex].GetObject(oindex)->m_bselected;

}
void animationmanager::SetWPAppAnimationObject(int aindex,int index,l3d_vertex_fast v)
{
        if(aindex <0 || aindex >= m_Animate.size())
                return ;
        if(index <0 || index >= m_Animate[aindex].GetSizeObject())
                return ;

        //m_Animate[aindex].GetObject(index)->world_pos_app=v;

}
void animationmanager::SetWPAnimationObject(int aindex,int index,l3d_vertex_fast v)
{
        if(aindex <0 || aindex >= m_Animate.size())
                return ;
        if(index <0 || index >= m_Animate[aindex].GetSizeObject())
                return ;

        //m_Animate[aindex].GetObject(index)->world_pos=v;

}
void animationmanager::SetInMoveAnimationObject(int aindex,int oindex,bool bval)
{

        if(aindex <0 || aindex >= m_Animate.size())
                return ;
        if(oindex <0 || oindex >= m_Animate[aindex].GetSizeObject())
                return ;

       // m_Animate[aindex].GetObject(oindex)->SetInMove(bval);

}
l3d_vertex_fast animationmanager::gettoolpos(int aindex)

{

    l3d_vertex_fast tpos;

    if(aindex <0 || aindex >m_Animate.size())
        return tpos;

    animate * ani=&m_Animate[aindex];
    int first=0,firsto=0;



    float wpapp[3]={0.0f,0.0f,0.0f};
    float wpapp_wp[3]={0.0f,0.0f,0.0f};

//calcolo della nuova posizione

     /* quando aggiunta la gestione dei gruppi

        for(vector<group>::const_iterator it = m_groups.begin(); it != m_groups.end(); ++it)
        {
            group g=*it;
            if(g.selected())
            {
                wpapp[0]+=g.getPos().GetX();
                wpapp[1]+=g.getPos().GetY();
                wpapp[2]+=g.getPos().GetZ();
                first++;


            }


        }

    */

        for(int ix=0; ix < ani->GetSizeObject();ix++)
        {
         //   animatedmesh *obj=ani->GetObjectW(ix);

           /* if(obj->m_bselected && obj->getGroup()==-1)
            {
                wpapp[0]+=obj->m_Worldpos.GetX();
                wpapp[1]+=obj->m_Worldpos.GetY();
                wpapp[2]+=obj->m_Worldpos.GetZ();
                first++;
            }
        }
        /*
        for(int ix=0;ix < m_lights.size();ix++)
        {
            if(m_lights[ix].m_sphere->m_bselected)
            {

                wpapp[0]+=m_lights[ix].m_sphere->world_pos.GetX();
                wpapp[1]+=m_lights[ix].m_sphere->world_pos.GetY();
                wpapp[2]+=m_lights[ix].m_sphere->world_pos.GetZ();
                first++;

            }
        }
        for(int ix=0;ix < m_null.size();ix++)
        {
            if(m_null[ix].isselected())
            {

                wpapp[0]+=m_null[ix].m_worldpos.GetX();
                wpapp[1]+=m_null[ix].m_worldpos.GetY();
                wpapp[2]+=m_null[ix].m_worldpos.GetZ();
                first++;
            }
        }
        break;
    case SCENE::edit:
        for(vector<object3d>::const_iterator it = m_object.begin(); it != m_object.end(); ++it)
        {
            object3d obj=*it;
            if(obj.m_bselected)
            {
                wpapp_wp[0]+=obj.world_pos.GetX();
                wpapp_wp[1]+=obj.world_pos.GetY();
                wpapp_wp[2]+=obj.world_pos.GetZ();
                firsto++;
                for(int ix=0; ix < obj.local_vertex.size();ix++)
                {
                    if(obj.local_vertex[ix].IsSelected())
                    {
                        wpapp[0]+=obj.local_vertex[ix].GetX();
                        wpapp[1]+=obj.local_vertex[ix].GetY();
                        wpapp[2]+=obj.local_vertex[ix].GetZ();
                        first++;

                    }


                }

            }
        }

        break;

    }*/

    if(firsto>1)
    {
        wpapp_wp[0]/=firsto;
        wpapp_wp[1]/=firsto;
        wpapp_wp[2]/=firsto;
    }
    if(first>1)
    {
        wpapp[0]/=first;
        wpapp[1]/=first;
        wpapp[2]/=first;
    }

    wpapp[0]+=wpapp_wp[0];
    wpapp[1]+=wpapp_wp[1];
    wpapp[2]+=wpapp_wp[2];




    tpos.set(wpapp[0],wpapp[1],wpapp[2]);

    return tpos;

}
}
