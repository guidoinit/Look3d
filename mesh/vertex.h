#ifndef VERTEX_H
#define VERTEX_H

#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include "material.h"

#include "color.h"
class vertex
{
public:
        vertex();
        ~vertex();
        vertex(float,float,float);
        vertex(float,float,float,int);
        vertex ( const vertex &vert );
        vertex& operator=( const vertex &vert );
        vertex& operator-=( const vertex &vert );
        vertex& operator+=( const vertex &vert );

        void SetName(int);
        int GetName(void);
        bool selected();
        void selected(bool value);
        bool IsSelected(void);
        void SetSelected(bool newVal);

        // virtual void Serialize();//CArchive& ar);

        float m_ntx,m_nty;
        void SetTextXY(float tx, float ty);
        int DrawTexture(void);

        void Draw(float cr, float cg, float cb);
        void Draw(void);
        void DrawMaterial(material* mat);
        void DrawMaterialFlat(material *mat);
        void SetMaterial(int);
        int GetMaterial();

        void Add(vertex);
        void AddX(float x);
        void AddY(float y);
        void AddZ(float z);
        void Move(vertex );


        void DrawNormal();
        void Push();
        void Pop();
        float GetAppZ();
        float GetAppY();
        float GetAppX();
        void SetZ(float val);
        void SetY(float val);
        void SetX(float val);
        void SetVertex(float x1,float y1,float z1);
        void SetNormal(float[]);
        float GetZ();
        float GetY();
        float GetX();

        int GetColor();
        void SetColor(int);

        vertex *GetVertex();

        void serialize(std::ifstream*  ar)
        {
            if(ar->is_open())
            {
                ar->read((char*)this,sizeof(vertex));
                /*
                (*ar) >> x;
                (*ar) >> y;
                (*ar) >> z;
                (*ar) >> m_imaterial;*/
            }
            else
            {


            }


        }
        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {

                ar->write((char*)this,sizeof(vertex));

                //(*ar) << x;
                //(*ar) << y;
                //(*ar) << z;
                //(*ar) << m_imaterial;
            }
            else
            {


            }


        }


        /*
        {
                x= vert.x;
                y= vert.y;
                z= vert.z;

                m_color[0]=vert.m_color[0];
                m_color[1]=vert.m_color[1];
                m_color[2]=vert.m_color[2];

                m_normal[0]=vert.m_normal[0];
                m_normal[1]=vert.m_normal[1];
                m_normal[2]=vert.m_normal[2];

                appx= vert.appx;
                appy= vert.appy;
                appz= vert.appz;

                m_bSelected=vert.m_bSelected;
                m_name=vert.m_name;

        }*/

        /*
        {
                x= vert.x;
                y= vert.y;
                z= vert.z;

                m_color[0]=vert.m_color[0];
                m_color[1]=vert.m_color[1];
                m_color[2]=vert.m_color[2];

                m_normal[0]=vert.m_normal[0];
                m_normal[1]=vert.m_normal[1];
                m_normal[2]=vert.m_normal[2];

                appx= vert.appx;
                appy= vert.appy;
                appz= vert.appz;

                m_bSelected=vert.m_bSelected;
                m_name=vert.m_name;


                return *this;
            }*/
protected:
        float appz;
        float appy;
        float appx;
        float x,y,z;
        int vcolor;

private:
        int m_name;
        int m_imaterial;
        float m_normal[3];
        // Variabile che definise se un vertice  selezionato
        bool m_bSelected;

};

#endif // VERTEX_H
