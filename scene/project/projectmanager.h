#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
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

class projectManager
{

public:
    projectManager();
    ~projectManager();
    int pselected;


    void CreateProject(Project *prj);

    void AddProject(Project prj);
    //void AddProjectObject(int pindex,object3d);

    int GetProject();
    void FreeProject();
    void Pipeline();

    void DrawProject(int nindex);

    Project *GetProject(int index);

    SceneProperty _sceneproperty;


    std::vector<Project> m_project;




};

#endif // PROJECTMANAGER_H
