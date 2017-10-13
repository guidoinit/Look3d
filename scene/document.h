#ifndef DOCUMENT_H
#define DOCUMENT_H
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
#include "scene/project/projectmanager.h"
#include "scene/maindocument/l3d_mainscenedocument.h"


class document
{
public:
    document();
    ~document();
    l3d_mainscenedocument * getmainscenedoc();

    projectManager *getProjectManager();
private:
    l3d_mainscenedocument * m_mainscenedoc;
    projectManager * m_projectManager;



};

#endif // DOCUMENT_H
