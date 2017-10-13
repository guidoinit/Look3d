#include "makeuv.h"

makeuv::makeuv()
{
    m_obj=NULL;
    m_fpol=0.0F;
}
makeuv::makeuv(object3d * obj)
{
    m_obj=obj;
    m_fpol=0.0F;
}

makeuv::makeuv(object3d * obj,ALG_UV alg)
{
    m_obj=obj;
    m_alg=alg;
    m_fpol=0.0F;
}

void makeuv::selalgoritm(ALG_UV alg)
{
    m_alg=alg;
    m_fpol=0.0F;


}
void makeuv::setobj(object3d *nobj)
{
    m_obj=nobj;
    m_fpol=0.0F;

}
void makeuv::poligonal(ALG_UV alg,float val)
{
    m_fpol=val;
    poligonal(alg);

}

void makeuv::poligonal(ALG_UV alg)
{
    m_alg=alg;

    if(m_obj==NULL)
        return;



    int nvert=m_obj->local_vertex.size();

    if(nvert==0)
        return;

    m_obj->m_uv.clear();//clear uv coordinate

    float  maxx=0.0F,maxy=0.0F,maxz=0.0F;
    for(int ix=0; ix < nvert; ix ++)
    {
        float x,y,z;


        x=m_obj->local_vertex[ix].GetX();

        y=m_obj->local_vertex[ix].GetY();

        z=m_obj->local_vertex[ix].GetZ();


        if (maxx < fabs(x))
            maxx=fabs(x);

        if (maxy < fabs(y))
            maxy=fabs(y);

        if (maxz < fabs(z))
            maxz=fabs(z);
    }
    for(int ix=0; ix < nvert; ix ++)
    {
        float x,y,z,u=-1.0F,v=-1.0F;
        vertexuv uvapp;

        x=m_obj->local_vertex[ix].GetX()/maxx;
        y=m_obj->local_vertex[ix].GetY()/maxy;
        z=m_obj->local_vertex[ix].GetZ()/maxz;



        switch(m_alg)
        {
        case poligonalx:
            if(x>=m_fpol)
            {
                u = (y / 2.0F) + 0.25F;
                v = (z / 2.0F ) + 0.5F;
            }
            else if(x<m_fpol)
            {
                u = (y / 2.0F) + 0.75F;
                v = (z ) + 0.5F;
            }

            uvapp.set(u,v);
            break;
        case poligonaly:
            if(y>=m_fpol)
            {
                u = (x / 2.0F) + 0.25F;
                v = (z / 2.0F) + 0.5F;
            }
            else if(y<m_fpol)
            {
                u = (x / 2.0F) + 0.75F;
                v = (z / 2.0F) + 0.5F;
            }

            uvapp.set(u,v);
            break;
        case poligonalz:

            if(z>=m_fpol)
            {
                u = (x / 2.0F) + 0.25F;
                v = (y / 2.0F) + 0.5F;
            }
            else if(z<m_fpol)
            {
                u = (x / 2.0F) + 0.75F;
                v = (y / 2.0F) + 0.5F;
            }
            uvapp.set(u,v);
            break;

        }


        m_obj->m_uv.push_back(uvapp);


    }




}

makeuv::~makeuv()
{

}
