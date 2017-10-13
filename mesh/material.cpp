#include <QGLWidget>
#include "material.h"




material::material(void)
{
        for(int ix=0; ix < 4; ix++)
        {
                mat_ambient[ix]=	0.0F;
                mat_diffuse[ix]=	0.0F;
                mat_specular[ix]=	0.0F;
                mat_emission[ix]=	0.0F;
        }
        mat_shininess[0]=0.0F;
        _mface=front;
        m_bambientanddiffuse=false;

}

material::material(MaterialFace mface)
{
        _mface=mface;

}
material::material(MaterialFace mface,bool ad,GLfloat a[4],GLfloat d[4],GLfloat s[4],GLfloat e[4],GLfloat sh[1])
{
        for(int ix=0; ix < 4; ix++)
        {
                mat_ambient[ix]=a[ix] ;
                mat_diffuse[ix]=d[ix];
                mat_specular[ix]=s[ix];
                mat_emission[ix]=e[ix];
        }
        mat_shininess[0]=sh[0];
        _mface=mface;
        m_bambientanddiffuse=ad;

}


material::~material(void)
{
}

void material::Set()
{
        if(m_bambientanddiffuse)
                glMaterialfv (_mface, GL_AMBIENT_AND_DIFFUSE, mat_ambient);
        else
        {
                glMaterialfv (_mface, GL_AMBIENT, mat_ambient);
                glMaterialfv (_mface, GL_DIFFUSE, mat_diffuse);
        }
        glMaterialfv (_mface, GL_SPECULAR, mat_specular);
        glMaterialfv (_mface, GL_EMISSION, mat_emission);
        glMaterialf (_mface, GL_SHININESS, mat_shininess[0]);

        //GL_COLOR_INDEXES to-do

}
/*

void material::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code

        }
        else
        {

        }
}


void material::Save(CString path)
{

        //path contiene la directory su cui salvare il materiale

        CString namesave=path;


        namesave.Append(_T("materials\\"));

        namesave.Append(name);

        namesave.Append(_T(".3dm"));

        CFile theFile;

        theFile.Open(namesave, CFile::modeCreate | CFile::modeWrite);

        CArchive archive(&theFile, CArchive::store);

        Serialize(archive);

        archive.Close();

        theFile.Close();


}
*/
