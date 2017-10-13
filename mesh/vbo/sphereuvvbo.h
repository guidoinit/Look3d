#ifndef SPHEREUVVBO_H
#define SPHEREUVVBO_H

#include "./mesh/vbo/objectvbo.h"

class sphereuvvbo: public objectVBO
{
public:
        sphereuvvbo();
        ~sphereuvvbo();
        void create();
        void create(int,int,float);
public:
        void Draw(int);
        void SetColor(float r,float g,float b,float a);
        void setRadius(float);
        void SetUV(int,int);
/*
        object3d& operator=( const sphereuvvbo *obj )
        {
            int x;

            //m_shaderprogram=obj.m_shaderprogram;

            for (x=0; x<4; x++)
                    m_fMaterial[x]=obj->m_fMaterial[x];
            for (x=0; x<3; x++)
            {
                    m_color[x]=obj->m_color[x];
                    m_Scale[x]=obj->m_Scale[x];
                    m_ScaleVertex[x]=obj->m_ScaleVertex[x];
                    m_angolo[x]=obj->m_angolo[x];
            }
            m_bSel=obj->m_bSel;
            m_nType=obj->m_nType;

            setName(obj->getname(),obj->getsubname());

            m_name=obj->m_name;

            for(x=0; x< obj->m_poly.size() ; x++)
            {
                    m_poly.push_back(poligon());
                    m_poly[x]= obj->m_poly[x];
            }

            for(x=0; x< obj->m_poly3.size() ; x++)
            {
                    m_poly3.push_back(poligon());
                    m_poly3[x]= obj->m_poly3[x];
            }

            for(x=0; x< obj->m_poly4.size() ; x++)
            {
                    m_poly4.push_back(poligon4());
                    m_poly4[x]= obj->m_poly4[x];
            }

            m_Worldpos=obj->m_Worldpos;

            m_nGruppoID=obj->m_nGruppoID;



            for(x=0; x< obj->m_Vertice.size()  ; x++)
            {
                    m_Vertice.push_back(vertex());
                    m_Vertice[x]=obj->m_Vertice[x];
            }

            m_bModificato=obj->m_bModificato;
            m_b2D=obj->m_b2D;

            m_bselected=obj->m_bselected;
            m_bhide=obj->m_bhide;
            m_binvert=obj->m_binvert;
            m_bsmooth=obj->m_bsmooth;

            world_pos=obj->world_pos;
            world_pos_app=obj->world_pos_app;

            for (x=0; x < obj->local_vertex.size() ; x++)
            {

                    local_vertex.push_back(vertex());

                    local_vertex[x]=obj->local_vertex[x];

            }
            for(x=0; x< obj->m_line.size(); x++)
            {
                    m_line.push_back(line());
                    m_line[x]=obj->m_line[x];
            }

            return *this;
        }
        sphereuvvbo& operator=( const object3d *obj )
        {
            int x;

                                //m_shaderprogram=obj.m_shaderprogram;

                                for (x=0; x<4; x++)
                                        m_fMaterial[x]=obj->m_fMaterial[x];
                                for (x=0; x<3; x++)
                                {
                                        m_color[x]=obj->m_color[x];
                                        m_Scale[x]=obj->m_Scale[x];
                                        m_ScaleVertex[x]=obj->m_ScaleVertex[x];
                                        m_angolo[x]=obj->m_angolo[x];
                                }
                                m_bSel=obj->m_bSel;
                                m_nType=obj->m_nType;


                                setName(obj->getname(),obj->getsubname());

                                for(x=0; x< obj->m_poly.size() ; x++)
                                {
                                        m_poly.push_back(poligon());
                                        m_poly[x]= obj->m_poly[x];
                                }

                                for(x=0; x< obj->m_poly3.size() ; x++)
                                {
                                        m_poly3.push_back(poligon());
                                        m_poly3[x]= obj->m_poly3[x];
                                }

                                for(x=0; x< obj->m_poly4.size() ; x++)
                                {
                                        m_poly4.push_back(poligon4());
                                        m_poly4[x]= obj->m_poly4[x];
                                }

                                m_Worldpos=obj->m_Worldpos;

                                m_nGruppoID=obj->m_nGruppoID;



                                for(x=0; x< obj->m_Vertice.size()  ; x++)
                                {
                                        m_Vertice.push_back(vertex());
                                        m_Vertice[x]=obj->m_Vertice[x];
                                }

                                m_bModificato=obj->m_bModificato;
                                m_b2D=obj->m_b2D;

                                m_bselected=obj->m_bselected;
                                m_bhide=obj->m_bhide;
                                m_binvert=obj->m_binvert;
                                m_bsmooth=obj->m_bsmooth;

                                world_pos=obj->world_pos;
                                world_pos_app=obj->world_pos_app;

                                for (x=0; x < obj->local_vertex.size() ; x++)
                                {

                                        local_vertex.push_back(vertex());

                                        local_vertex[x]=obj->local_vertex[x];

                                }
                                for(x=0; x< obj->m_line.size(); x++)
                                {
                                        m_line.push_back(line());
                                        m_line[x]=obj->m_line[x];
                                }

                                return *this;


        }
*/
private:

        float m_raggio;
        int uvx,uvy;
};

#endif // SPHEREUVVBO_H
