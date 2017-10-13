#pragma once
#include <vector>

#include <math.h>


#include "scene/animation/frame.h"
#include "scene/animation/animate.h"

#include "scene/elements/l3d_light.h"




#include "scene/animation/baseframe.h"
#include "scene/animation/locx.h"
#include "scene/animation/locy.h"
#include "scene/animation/locz.h"

#include "scene/maindocument/l3d_mainscenedocument.h"

namespace PROJECT
{
enum ProjectType
{
	project_normal=1,
	project_game_generic=2,
	project_game_ipod=3,
	project_game_android=4,
	project_game_xna=5,
	project_game_opengl=6,
	project_game_directx=7
};
}
class Project:public l3d_mainscenedocument
{
public:
	Project(void);
	Project(char * m_name);

    Project(char * m_name,PROJECT::ProjectType type);
	void SetName(char *name);


    void SetType(PROJECT::ProjectType type);

	~Project(void);

        PROJECT::ProjectType _projecttype;
	

	
//	void AddObject(int iobject);
        //void AddObject(object3d object);
    void AddTelecamera(telecamera tel);
    void AddAnimation(animate ani);
    void AddLigth(pl3d_light l);
    void AddMaterial(pl3d_material_struct m);
	void AddAnimation(int);
    void AddObject(int iobject);
	void Draw();
	int GetObject(int ndex);
	int GetAnimation(int index);

	void Pipeline();

        void Save(string name);
	char*GetName();

private:
	char * m_name;
};

