#include "sphereuvvbo.h"

sphereuvvbo::sphereuvvbo()
{
   m_raggio=10.0f;
   uvx=uvy=32;
}

sphereuvvbo::~sphereuvvbo()
{
}
void sphereuvvbo::create(int ux,int uy,float r)
{
        uvx=ux;
        uvy=uy;
        m_raggio=r;
        create();

}

void sphereuvvbo::SetUV(int u,int v)
{
    uvx=u;
    uvy=v;
}


void sphereuvvbo::setRadius(float nr)
{
    m_raggio=nr;
}


void sphereuvvbo::create()
{
   static int numsphere=0;
   int count1 , count2 ;
   int nIndInf , nIndInf1;
   int v1,v2,v3,v4;
   float n, f, t=0.0F;
   float dimobj=m_raggio;
   float xapp,yapp,zapp,raggioapp;
   float raggio=m_raggio;
   vertex va;
   world_pos.SetVertex(0.0F,0.0F,0.0F);

  // name.append("object%d",numsphere++);
   local_vertex.clear();
   m_poly.clear();
   m_poly3.clear();
   m_poly4.clear();
   m_line.clear();

   va.SetVertex(0.0F,dimobj,0.0F);
   local_vertex.push_back(va);
        //local_vertex[0].SetVertex(0.0F,dimobj,0.0F);
   int vert=1;
      //  uvx=16;
      //  uvy=16;
   double angoloy=(180.0F/(double)(uvy));
   double angolox=(360.0F/(double)(uvx));
   int nvertx=(int) (180.0F / angolox);
   int nverty=(int) (360.0F / angoloy);
   float stepx=180.0F/(180.0F/(float)uvx);
   float stepy=360.0F/(360.0F/(float)uvy);
   for (double angolo=(angoloy/2.0F); angolo<(180.0f); angolo+=angoloy)
   {
        xapp=(float)sin((float)angolo*3.1415f/180.0f)*raggio;
        yapp=(float)cos((float)angolo*3.1415f/180.0f)*raggio;
        raggioapp=xapp;

        for (double a=(angolox/2.0F); a<360.0F; a+=angolox)
        {

            float x,y,z;
            x=y=z=0;

            x=(float)sin((float)a * 3.1415F / 180.0F)*raggioapp;
            y=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp *(float)cos((float)90.0F*3.1415F/180.0F);
            z=(float)cos((float)a * 3.1415F / 180.0F)*raggioapp * (float)(-sin((float)90.0F*3.1415F/180.0F));

            y=y+yapp;
            va.SetVertex(x,y,z);
            local_vertex.push_back(va);
                vert++;
        }
    }
        va.SetVertex(0.0F,-dimobj,0.0F);
        local_vertex.push_back(va);
        int lastm_poly=vert;

        //definizione della parte superiore

        int nm_poly=0;
        int nIndSup=0;

        poligon vp;

        line line;

        for (int iy=0; iy < uvx-1 ; iy++)
        {
                v1=nIndSup;
                v2=iy+2;
                v3=iy+1;

                vp.lista_vertici[0]=v1;
                vp.lista_vertici[1]=v2;
                vp.lista_vertici[2]=v3;

                if(v1<v2)
                        line.SetLine(v1,v2);
                else
                        line.SetLine(v2,v1);

                m_line.push_back(line);

                if(v2<v3)
                        line.SetLine(v2,v3);
                else
                        line.SetLine(v3,v2);

                m_line.push_back(line);

                if(v3<v1)
                        line.SetLine(v3,v1);
                else
                        line.SetLine(v1,v3);


                m_line.push_back(line);

                m_poly3.push_back(vp);

                nm_poly++;

        }
        v1=nIndSup;
        v2=nIndSup+1;
        v3=nIndSup+uvx;

        if(v1<v2)
                line.SetLine(v1,v2);
        else
                line.SetLine(v2,v1);
        m_line.push_back(line);

        if(v2<v3)
                line.SetLine(v2,v3);
        else
                line.SetLine(v3,v2);

        m_line.push_back(line);

        if(v3<v1)
                line.SetLine(v3,v1);
        else
                line.SetLine(v1,v3);

        m_line.push_back(line);

        vp.lista_vertici[0]=v1;
        vp.lista_vertici[1]=v2;
        vp.lista_vertici[2]=v3;

        m_poly3.push_back(vp);
        //definizione della parte inferiore

        nIndInf  = local_vertex.size() - 1 ;

        nIndInf1 = nIndInf - 1 ;

        for (int x=0; x< uvx-1;x++)
        {

                v1=nIndInf;
                v2=nIndInf1-1;
                v3=nIndInf1;

                nIndInf1--;

                vp.lista_vertici[0]=v1;
                vp.lista_vertici[1]=v2;
                vp.lista_vertici[2]=v3;

                if(v1<v2)
                        line.SetLine(v1,v2);
                else
                        line.SetLine(v2,v1);
                m_line.push_back(line);

                if(v2<v3)
                        line.SetLine(v2,v3);
                else
                        line.SetLine(v3,v2);

                m_line.push_back(line);

                if(v3<v1)
                        line.SetLine(v3,v1);
                else
                        line.SetLine(v1,v3);

                m_line.push_back(line);


                m_poly3.push_back(vp);

                nm_poly++;

        }
        v1=nIndInf;
        v2=nIndInf-1;
        v3=nIndInf-uvx;

        vp.lista_vertici[0]=v1;
        vp.lista_vertici[1]=v2;
        vp.lista_vertici[2]=v3;

        if(v1<v2)
                line.SetLine(v1,v2);
        else
                line.SetLine(v2,v1);
        m_line.push_back(line);

        if(v2<v3)
                line.SetLine(v2,v3);
        else
                line.SetLine(v3,v2);

        m_line.push_back(line);

        if(v3<v1)
                line.SetLine(v3,v1);
        else
                line.SetLine(v1,v3);

        m_line.push_back(line);

        m_poly3.push_back(vp);

        //definizione del corpo

        int nIndex=1;
        int nIndex1=uvx + 1;
        for ( int n=1 ; n < uvy; n++)//nvertx-1; n++ )

        {
            count1=nIndex;
                count2=nIndex1;
                for (int x=0;x < uvx -1 ; x++ ){

                    //Primo poligono
                    v1 = count1   ;
                    v2 = count1+1 ;
                    v3 = count2   ;
                    v4 = count2+1 ;

                    AddPoligon (v1,v2,v3,v4);
                    nm_poly++;
                    count1++;
                    count2++;
                }
                v1=nIndex;
                v2=nIndex1;
                v3=v1 + uvx -1;
                v4=v2 + uvx -1;

            AddPoligon (v1,v2,v3,v4);

                nm_poly++;
                nIndex=nIndex1;
                nIndex1+=uvx;

        }

        RemoveDoubleLines();
        //m_poly.Clear();
        nm_poly++;

        //SetShaders(); da reimpostare in base alla gestione degli shaders


}
void sphereuvvbo::Draw(int nmod)
{
        object3d::Draw(nmod);
        return;
        int ix,iy;
        float angx,angy;
        float stepx,stepy,raggiox;
        angx=angy=0.0F;
        stepx = 180.0F / uvx;
        stepy = 360.0F / uvy;
        float hh=-m_raggio+(m_raggio/uvy);
        angx=stepx;
        raggiox=m_raggio/uvx;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        glRotatef(m_angolo[0],1.0F,0.0F,0.0F);
        for ( iy=-(m_raggio-(m_raggio*2/uvy)) ; iy < (m_raggio) ; iy+=(m_raggio*2/uvy) )

        {
              raggiox=m_raggio/iy;

              angy=0.0F;
              //glScalef(2.0F,1.0F,2.0F);
              //glRotatef(90.0F,1.0F,0.0F,0.0F);
              glPushMatrix();
              glScalef(2.0F,1.0F,2.0F);
              for(ix=0; ix < uvx ; ix++)

              {

                float appx,appy,appz;
                appx=sin(angy * 3.1415F/180.0F)* (m_raggio-iy);
                appz=cos(angy * 3.1415F/180.0F)* (m_raggio-iy);
                appy=iy;
                glPushMatrix();
                //glTranslatef(0.0F , hh  , 0.0F);
                //glScalef(2.0F,1.0F,2.0F);
                glBegin(GL_POINTS);
                glVertex3f(appx,appy,appz);
                glEnd();

                glPopMatrix();

                angy+=stepy;

              }
              hh+=m_raggio/uvy;
              glPopMatrix();

           //   raggioy  += m_raggio/uvy;

        }
        glPopMatrix();

       // C3DObject::Draw(nmod);

}

void sphereuvvbo::SetColor(float r,float g,float b,float a)
{
        int nv=local_vertex.size();
        for(int ix=0; ix < nv; ix++)
        {
              //  local_vertex[ix].m_color[0]=r;
              //  local_vertex[ix].m_color[1]=g;
              //  local_vertex[ix].m_color[2]=b;
        }


}
