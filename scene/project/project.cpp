#define GLEW_STATIC
#include <GL/glew.h>

#include <vector>

#include <math.h>


#include "scene/animation/frame.h"
#include "scene/animation/animate.h"

#include "scene/elements/l3d_light.h"





#include "scene/animation/baseframe.h"
#include "scene/animation/locx.h"
#include "scene/animation/locy.h"
#include "scene/animation/locz.h"


#include "scene/project/project.h"

#include "scene/sceneenum.h"
#include "scene/sceneproperty.h"


#include "project.h"


Project::Project(void)
{

}


Project::Project(char * name)
{
	m_name=name;
}

Project::Project(char * name,PROJECT::ProjectType type)
{
	m_name=name;
	_projecttype=type;
}

void Project::SetType(PROJECT::ProjectType type)
{
	_projecttype=type;
}
char * Project::GetName()
{
	return m_name;
}
void Project::SetName(char * name)
{
	m_name=name;
}

void Project::AddObject(int iobject)
{

}


void Project::AddTelecamera(telecamera tel)
{
        //m_telecamera.push_back(tel);
}

void Project::AddAnimation(animate ani)
{
        //m_animate.push_back(ani);
}
void Project::AddLigth(pl3d_light l)
{
    //addlight(l);
}
void Project::AddAnimation(int iani)
{
    //m_animvector.push_back(iani);
	
}


void Project::AddMaterial(pl3d_material_struct m)
{
        //m_material.push_back(m);
}

int Project::GetObject(int index)
{
    /*
	if(index >=0 && index < m_objectvector.size())
		return m_objectvector[index];
	else
		return (-1);
                */
}

int Project::GetAnimation(int index)
{
    /*
	if(index >=0 && index < m_animvector.size())
		return m_animvector[index];
	else
                return (-1);*/
}


Project::~Project(void)
{
    //m_groups.clear();
    //m_object.clear();
        //m_animvector.clear();
}

void Project::Save(string filename)
{
	// save the project
	
        //CFile file(filename,CFile::modeCreate);

        //file.Write(m_name,sizeof(m_name));
	
	// save the objects to-do

	// save the animation to-do


        //file.Close();
}

void Project::Draw()
{
	//disegna la scena del progetto
}


void Project::Pipeline()
{

}
