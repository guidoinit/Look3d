#define GLEW_STATIC

#include <GL/glew.h>

#include <QtOpenGL>

#include <math.h>
#include <vector>
#include "material.h"

#include "vertex.h"


#include "poligon.h"
#include "poligon4.h"

#include "variable.h"
#include "istruction.h"

#include "action.h"

#include "function.h"
#include "module.h"

#include "mesh/texture/texture.h"
#include "line.h"

//#include "shader.h"
//#include "shaderprogram.h"



#include "object3d.h"
#include "poligon.h"


void poligon::Set(int v1,int v2,int v3)
{
        lista_vertici[0]=v1;
        lista_vertici[1]=v2;
        lista_vertici[2]=v3;

}
poligon::poligon()
{
        visible=true;
        m_berase=false;
        Selected=false;
        material[0]=0.5f;
        material[1]=0.5f;
        material[2]=0.5f;
        material[3]=1.0F;
}

poligon::~poligon()
{

}
void poligon::CalcolaNormale()
{

}
/*
void poligon::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code
                ar << lista_vertici[0];
                ar << lista_vertici[1];
                ar << lista_vertici[2];
        }
        else
        {	// loading code
                ar >> lista_vertici[0];
                ar >> lista_vertici[1];
                ar >> lista_vertici[2];
        }
}

*/
int poligon::Get(int v)
{
        if(v>=0 && v < 3)
                return lista_vertici[v];
        else
                return -1;
}


bool poligon::isSelected(void)
{
        return this->Selected;
}

void poligon::SetSelected(bool val)
{
        this->Selected=val;
}
void poligon::selected(bool val)
{
        this->Selected=val;
}

void poligon::SetName(int name)
{
        m_name=name;
}


int poligon::GetName(void)
{
        return m_name;
}
void poligon::invertdraw()
{
    int appi=lista_vertici[1];

    lista_vertici[1]=lista_vertici[2];

    lista_vertici[2]=appi;


}
