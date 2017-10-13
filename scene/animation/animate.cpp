#define GLEW_STATIC
#include <GL/glew.h>

#include <math.h>
#include <vector>



#include "frame.h"

#include "baseframe.h"
#include "locx.h"
#include "locy.h"
#include "locz.h"

#include "keyframe.h"
#include "animate.h"


animate::animate()
{
        m_nNumFrame=0;
}

animate::animate(string name)
{
        m_nNumFrame=0;
        m_StrName=name;
}

animate::~animate()
{

}
int animate::GetPrevFrame(int oindex,int iframe, int aindex)
{
        if(!(oindex >=0 && oindex < m_ostate.size()))
                return -1;

        if(m_keyframe.size()==0)
                return 0;

        int ix=0,count=0;
        /*while( ix < m_keyframe.size())
        {
                if(m_keyframe[ix].GetAction().GetAction()==aindex)
                        count++;
                ix++;
        }
        if(count==0)
                return (0);
        */

        ix=0;
        while(ix < m_keyframe.size())
        {
                if(//aindex==m_keyframe[ix].GetAction().GetAction() &&
                        iframe >  m_keyframe[ix].GetNumFrame())
                        count=ix;
                if(iframe==m_keyframe[ix].GetNumFrame())
                        return m_keyframe[ix].GetfirstFrame();

                if(iframe > m_keyframe[ix].GetfirstFrame() &&
                        iframe <  m_keyframe[ix].GetNumFrame() )//&& 	aindex==m_keyframe[ix].GetAction().GetAction()) //azione uguale
                {
                        int fp=m_keyframe[ix].GetfirstFrame();
                        //if(aindex==m_keyframe[ix].GetAction().GetAction())
                                m_keyframe[ix].SetnFrame(iframe,m_keyframe[ix].GetNumFrame());
                        return fp;
                }
                ix++;
        }


        return (m_keyframe[count].GetNumFrame());

}
int animate::GetSizeObject()
{
        return m_ostate.size();
}
pl3d_mesh_struct animate::GetObject(int index)
{
        pl3d_mesh_struct obj=NULL;
        if(index <0 || index > m_ostate.size())
                return obj;
        return (m_ostate.find(index));

}
l3d_vertex_fast animate::GetScaleObjectFrame(int findex,int oindex)
{
        l3d_vertex_fast pver;
        pver.set(0.0F,0.0F,0.0F);

        if(!(oindex >=0 && oindex < m_ostate.size()))
            return pver;

        pver=(l3d_vertex_fast)*m_ostatescale.find(oindex);

        for(int ic=0; ic <= findex; ic++)
        {

                for (int ia=0; ia <m_frames.get(ic)->_size; ia++)
                    ;
                        /*if(m_frames.get(ic)->m_vaction[ia].m_nObject==oindex && m_frames[ic].m_vaction[ia].GetAction()==3)
                        {
                                float *f=m_frames[ic].m_vaction[ia].GetScale();
                                pver.AddX(*f++);
                                pver.AddY(*f++);
                                pver.AddZ(*f);
                        }*/

        }

        return pver;

}

l3d_vertex_fast animate::GetRotateObjectFrame(int findex,int oindex)
{
        l3d_vertex_fast pver;pver.set(0.0F,0.0F,0.0F);

        if(!(oindex >=0 && oindex < m_ostate.size()))
            return pver;

        //pver=this->m_ostateangolo[oindex];

        for(int ic=0; ic <= findex; ic++)
        {
                /*for (int ia=0; ia <m_frames[ic].m_vaction.size(); ia++)
                        if(m_frames[ic].m_vaction[ia].m_nObject==oindex && m_frames[ic].m_vaction[ia].GetAction()==2)
                        {
                                pver.AddX(m_frames[ic].m_vaction[ia].m_rangolo[0]);
                                pver.AddY(m_frames[ic].m_vaction[ia].m_rangolo[1]);
                                pver.AddZ(m_frames[ic].m_vaction[ia].m_rangolo[2]);
                        }
*/
        }




        return pver;


}

l3d_vertex_fast animate::GetWPObjectFrame(int findex,int oindex)
{
        l3d_vertex_fast pver;pver.set(0.0F,0.0F,0.0F);

        if(!(oindex >=0 && oindex < m_ostate.size()))
            return pver;


        pver=*m_ostatevertex.find(oindex);

        for(int ic=0; ic <= findex; ic++)
        {
               /* for (int ia=0; ia <m_frames[ic].m_vaction.size(); ia++)
                        if(m_frames[ic].m_vaction[ia].m_nObject==oindex && m_frames[ic].m_vaction[ia].GetAction()==1)
                        {
                                pver.AddX(m_frames[ic].m_vaction[ia].m_fsposta[0]);
                                pver.AddY(m_frames[ic].m_vaction[ia].m_fsposta[1]);
                                pver.AddZ(m_frames[ic].m_vaction[ia].m_fsposta[2]);
                        }*/

        }




        return pver;
}

l3d_vertex_fast *animate::GetWPObject(int index)
{
        l3d_vertex_fast *vobj=NULL;
        if(index <0 || index > m_ostatevertex.size())
                return vobj;
        return (m_ostatevertex.find(index));

}
void animate::AddObject(l3d_mesh_struct obj)
{
        m_ostate.add(&obj);
        m_ostatevertex.add(&obj._transformation._wp);
        m_ostateangolo.add(&obj._transformation._rotate);
        m_ostatescale.add(&obj._transformation._scale);
}
/*
void animate::Serialize(CArchive& ar)
{
        int x,y,nobj;
        CFrame appframe;
        if (ar.IsStoring())
        {	// storing code
                ar << m_StrName;

                ar << m_frames.size();

                ar << m_keyframe.GetSize();

                for(x=0; x< m_keyframe.GetSize(); x++)
                        m_keyframe[x].Serialize(ar);

                ar << m_ostate.GetSize();
                for (x=0 ;  x < m_ostate.GetSize() ; x ++)
                {
                        m_ostatevertex[x].Serialize(ar);
                        m_ostateangolo[x].Serialize(ar);
                        m_ostatescale[x].Serialize(ar);
                        m_ostate[x].Serialize(ar);
                }




        }
        else
        {

        // loading code

                int appc;

                ar >> m_StrName;

                ar >> appc;

                m_frames.SetSize(appc);

                ar >>appc;

                m_keyframe.SetSize(appc);

                for(x=0; x< m_keyframe.GetSize(); x++)
                        m_keyframe[x].Serialize(ar);

                ar >>appc;

                m_ostate.SetSize(appc);
                m_ostatevertex.SetSize(appc);
                m_ostateangolo.SetSize(appc);
                m_ostatescale.SetSize(appc);
                for (x=0 ;  x < m_ostate.GetSize() ; x ++)
                {
                        m_ostatevertex[x].Serialize(ar);
                        m_ostateangolo[x].Serialize(ar);
                        m_ostatescale[x].Serialize(ar);
                        m_ostate[x].Serialize(ar);
                }

                GenerateAction();



        }

}
*/

l3d_vertex_fast animate::GetObjectAngolo(int index)
{
        return(*m_ostateangolo.get(index));
}
l3d_vertex_fast animate::GetObjectScale(int index)
{
        return (*m_ostatescale.get(index));
}


void animate::SetInitialState(int io)
{

        m_ostatevertex.get(io)->x=m_ostate.find(io)->_vertex.get(io)->x;
        m_ostatevertex.get(io)->y=m_ostate.find(io)->_vertex.get(io)->y;
        m_ostatevertex.get(io)->z=m_ostate.find(io)->_vertex.get(io)->z;
        m_ostateangolo.get(io)->set(m_ostate.find(io)->_transformation._rotate.x,m_ostate.find(io)->_transformation._rotate.y,m_ostate.find(io)->_transformation._rotate.z);
        m_ostatescale.get(io)->set(m_ostate.find(io)->_transformation._scale.x,m_ostate.find(io)->_transformation._scale.y,m_ostate.find(io)->_transformation._scale.z);
        GenerateAction();
}
void animate::AddKeyFrame(keyframe mkeyframe)
{
        int ip=IsKFPresent(mkeyframe);//da aggiungere il tipo di frame

        if(ip>=0)
        {
                keyframe* kf= &m_keyframe[ip];

                kf->settype(mkeyframe.gettype());

                kf->setloc(mkeyframe.getlocx());
                kf->setloc(mkeyframe.getlocy());
                kf->setloc(mkeyframe.getlocz());

                kf->setdloc(mkeyframe.getdlocx());
                kf->setdloc(mkeyframe.getdlocy());
                kf->setdloc(mkeyframe.getdlocz());

                kf->setrloc(mkeyframe.getrlocx());
                kf->setrloc(mkeyframe.getrlocy());
                kf->setrloc(mkeyframe.getrlocz());

                kf->setrdloc(mkeyframe.getrdlocx());
                kf->setrdloc(mkeyframe.getrdlocy());
                kf->setrdloc(mkeyframe.getrdlocz());

                kf->setsloc(mkeyframe.getslocx());
                kf->setsloc(mkeyframe.getslocy());
                kf->setsloc(mkeyframe.getslocz());

                kf->setsdloc(mkeyframe.getsdlocx());
                kf->setsdloc(mkeyframe.getsdlocy());
                kf->setsdloc(mkeyframe.getsdlocz());



        }
        else
                m_keyframe.push_back(mkeyframe);

        //to-do sort keyframe
        if(m_keyframe.size()>1)
                SortKeyframe();

}
void animate::SortKeyframe()
{
        keyframe ftemp;

        for(int ix=0; ix < m_keyframe.size(); ix++)
                for(int iy=0; iy < (m_keyframe.size() - ix - 1); iy++)
                {
                        if(m_keyframe[iy]>m_keyframe[iy+1])
                        {
                                ftemp=m_keyframe[iy];
                                m_keyframe[iy]=m_keyframe[iy+1];
                                m_keyframe[iy+1]=ftemp;
                        }
                }

}
void animate::DeleteActionKeyframe()
{

        if(m_keyframe.size()<=0)
                return;
        for(int ixf=0; ixf <m_frames.size(); ixf++)
        {
           /*     for(int ify=0; ify<m_frames[ixf].m_vaction.size(); ify++)
                {
                //	m_frames[ixf].m_vaction.RemoveAll();
                        if(m_frames[ixf].m_vaction[ify].IsKey())
                        {
                            m_frames[ixf].m_vaction.erase(m_frames[ixf].m_vaction.begin() + ify );
                                ify--;
                        }

                }*/
        }
}

void animate::GenerateActionMove()
{
        float fmove[3]={0.0F,0.0F,0.0F};
        float fmoveold[3]={0.0F,0.0F,0.0F};


        int nframe,sframe;

        int firstframe=0;

        std::vector<int> vkey;

        for(int io=0; io < m_ostate.size();io++)
        {
                vkey.clear();

                for(int ik=0; ik <m_keyframe.size(); ik++)
                {
                        if(m_keyframe[ik].getobject()==io && (m_keyframe[ik].gettype()==KEYFRAME::kf_moverelative	||	m_keyframe[ik].gettype()==KEYFRAME::kf_movelocal))
                                vkey.push_back(ik);
                }

                int oldobj=-1;

                for(int ik=0; ik <vkey.size(); ik++)
                {

                        //firstact=m_keyframe[vkey[ik]].GetAction();

                        //int taction=firstact.GetAction();

                        int nobj=m_keyframe[vkey[ik]].getobject();

                        nframe = m_keyframe[vkey[ik]].GetNumFrame();
                        sframe = m_keyframe[vkey[ik]].GetfirstFrame();


                        l3d_vertex_fast pver=GetWPObjectFrame(sframe,nobj);

                        fmoveold[0]=pver.x;
                        fmoveold[1]=pver.y;
                        fmoveold[2]=pver.z;



                        /*if(m_keyframe[vkeys[ik]].gettype()==KEYFRAME::kf_moverelative)
                        {

                                fmove[0]=(m_keyframe[vkey[ik]].getdlocx()->get())/(nframe-sframe);

                                fmove[1]=(m_keyframe[vkey[ik]].getdlocy()->get())/(nframe-sframe);

                                fmove[2]=(m_keyframe[vkey[ik]].getdlocz()->get())/(nframe-sframe);


                        }
                        if(m_keyframe[vkey[ik]].gettype()==KEYFRAME::kf_movelocal)
                        {

                                fmove[0]=(m_keyframe[vkey[ik]].getlocx()->get()-fmoveold[0])/(nframe-firstframe);

                                fmove[1]=(m_keyframe[vkey[ik]].getlocy()->get()-fmoveold[1])/(nframe-firstframe);

                                fmove[2]=(m_keyframe[vkey[ik]].getlocz()->get()-fmoveold[2])/(nframe-firstframe);


                        }*/


                        for(int ix=sframe+1 ; ix < nframe+1 ; ix++)
                        {

                                action pact;

                                pact.KeyFrame();



                                pact.SetActionSposta(fmove);
                                pact.m_nObject=io;

                                //m_frames[ix].m_vaction.push_back(pact);


                        }


                        oldobj=nobj;

                        firstframe=nframe;



                }
        }
}


void animate::GenerateActionRotate()
{
        float frotate[3]={0.0F,0.0F,0.0F};
        float frotateold[3]={0.0F,0.0F,0.0F};

        action firstact;
        int sframe,nframe;
        std::vector<int> vkey;

        int firstframe=0;

        firstframe=0;
        for(int io=0; io < m_ostate.size();io++)
        {
                vkey.clear();

                for(int ik=0; ik <m_keyframe.size(); ik++)
                {
                        if(m_keyframe[ik].getobject()==io && (m_keyframe[ik].gettype()==KEYFRAME::kf_rotatelocal || m_keyframe[ik].gettype()==KEYFRAME::kf_rotaterelative))
                                vkey.push_back(ik);
                }



                for(int ik=0; ik <vkey.size(); ik++)
                {





                        int nobj=firstact.m_nObject;


                        sframe = m_keyframe[vkey[ik]].GetfirstFrame();
                        nframe = m_keyframe[vkey[ik]].GetNumFrame();

                        //vertex pver=GetRotateObjectFrame(sframe,m_keyframe[vkey[ik]].getobject());

                        /*if(m_keyframe[vkey[ik]].gettype()==KEYFRAME::kf_rotaterelative)
                        {

                                frotate[0]=(m_keyframe[vkey[ik]].getrdlocx()->get())/(nframe-sframe);

                                frotate[1]=(m_keyframe[vkey[ik]].getrdlocy()->get())/(nframe-sframe);

                                frotate[2]=(m_keyframe[vkey[ik]].getrdlocz()->get())/(nframe-sframe);

                        }

                        if(m_keyframe[vkey[ik]].gettype()==KEYFRAME::kf_rotatelocal )
                        {
                                frotate[0]=(m_keyframe[vkey[ik]].getrlocx()->get()-pver.GetX())/(nframe-sframe);

                                frotate[1]=(m_keyframe[vkey[ik]].getrlocy()->get()-pver.GetY())/(nframe-sframe);

                                frotate[2]=(m_keyframe[vkey[ik]].getrlocz()->get()-pver.GetZ())/(nframe-sframe);
                        }


                        frotateold[0]=firstact.m_rangolo[0];
                        frotateold[1]=firstact.m_rangolo[1];
                        frotateold[2]=firstact.m_rangolo[2];

                        for(int ix=sframe+1; ix < nframe+1; ix++)
                        {

                                action pact;

                                pact.KeyFrame();


                                pact.SetActionRuota(frotate);
                                pact.m_nObject=io;

                                //m_frames[ix].m_vaction.push_back(pact);


                        }
*/




                }

        }
}

void animate::GenerateActionScale()
{
        action firstact;
        int sframe,nframe;
        std::vector<int> vkey;

        float fscale[3]={1.0F,1.0F,1.0F};
        float fscaleold[3]={1.0F,1.0F,1.0F};

        int firstframe=0;

        firstframe=0;
        for(int io=0; io < m_ostate.size();io++)
        {
                vkey.clear();

                for(int ik=0; ik <m_keyframe.size(); ik++)
                {
                        if(m_keyframe[ik].getobject()==io && (m_keyframe[ik].gettype()==KEYFRAME::kf_scalerelative || m_keyframe[ik].gettype()==KEYFRAME::kf_scalelocal))
                                vkey.push_back(ik);
                }



                for(int ik=0; ik <vkey.size(); ik++)
                {


                        sframe = m_keyframe[vkey[ik]].GetfirstFrame();
                        nframe = m_keyframe[vkey[ik]].GetNumFrame();

                        float fs[3];

                        //vertex pver=GetScaleObjectFrame(sframe,io);


                        //fscaleold[0]=pver.GetX();
                        //fscaleold[1]=pver.GetY();
                        //fscaleold[2]=pver.GetZ();


                        /*if(m_keyframe[vkey[ik]].gettype()==KEYFRAME::kf_scalerelative)
                        {

                                fs[0]=(m_keyframe[vkey[ik]].getsdlocx()->get())/(nframe-sframe);

                                fs[1]=(m_keyframe[vkey[ik]].getsdlocy()->get())/(nframe-sframe);

                                fs[2]=(m_keyframe[vkey[ik]].getsdlocz()->get())/(nframe-sframe);


                        }
                        if(m_keyframe[vkey[ik]].gettype()==KEYFRAME::kf_scalelocal)
                        {

                                fs[0]=(m_keyframe[vkey[ik]].getslocx()->get()-fscaleold[0])/(nframe-sframe);

                                fs[1]=(m_keyframe[vkey[ik]].getslocy()->get()-fscaleold[1])/(nframe-sframe);

                                fs[2]=(m_keyframe[vkey[ik]].getslocz()->get()-fscaleold[2])/(nframe-sframe);


                        }




                        for(int ix=sframe+1; ix < nframe+1; ix++)
                        {

                                action pact;

                                pact.KeyFrame();


                                pact.SetActionScala(fs);
                                pact.m_nObject=io;

                                m_frames[ix].m_vaction.push_back(pact);




                        }
*/



                }

        }
}
void animate::GenerateAction()
{
        if(m_keyframe.size()<=0)
                return;


        DeleteActionKeyframe();

        GenerateActionMove();

        GenerateActionRotate();
        GenerateActionScale();


}

int animate::IsKFPresent(keyframe kf)
{
        for(int ik=0; ik < m_keyframe.size(); ik++)
        {
                if(m_keyframe[ik].GetNumFrame()==kf.GetNumFrame() &&
                       m_keyframe[ik].getobject()==kf.getobject() &&
                       m_keyframe[ik].gettype()==kf.gettype())

                    return ik;
        }
        KEYFRAME::KeyFrameType type;

        //find if is present a keyframe of the same action

        switch(kf.gettype())
        {
        case KEYFRAME::kf_movelocal:
                type=KEYFRAME::kf_moverelative;
                break;
        case KEYFRAME::kf_moverelative:
                type=KEYFRAME::kf_movelocal;
                break;
        case KEYFRAME::kf_rotatelocal:
                type=KEYFRAME::kf_rotaterelative;
                break;
        case KEYFRAME::kf_rotaterelative:
                type=KEYFRAME::kf_rotatelocal;
                break;
        case KEYFRAME::kf_scalelocal:
                type=KEYFRAME::kf_scalerelative;
                break;
        case KEYFRAME::kf_scalerelative:
                type=KEYFRAME::kf_scalelocal;
                break;
        }

        for(int ik=0; ik < m_keyframe.size(); ik++)
                if( m_keyframe[ik].GetNumFrame()==kf.GetNumFrame() && m_keyframe[ik].getobject()==kf.getobject() &&  type==kf.gettype())
                        return ik;

        return -1;
}

keyframe * animate::GetKeyFrame(int kindex)
{
        keyframe * kf=NULL;
        if(kindex >=0 && kindex < m_keyframe.size())
                kf=(keyframe *)&m_keyframe[kindex];
        return kf;
}
