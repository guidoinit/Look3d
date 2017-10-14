

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


#include "document.h"

document::document()
{

    m_projectManager= new projectManager();

    Q_ASSERT(m_projectManager!=NULL);

    m_mainscenedoc = new l3d_mainscenedocument();

    Q_ASSERT(m_mainscenedoc!=NULL);


}

document::~document()
{

    delete(m_projectManager);
    delete(m_mainscenedoc);

}

projectManager *document::getProjectManager()
{

    return m_projectManager;
}


l3d_mainscenedocument * document::getmainscenedoc()
{

    return m_mainscenedoc;

}
