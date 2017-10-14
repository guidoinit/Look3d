

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
#include "projectmanager.h"


projectManager::projectManager(void)
{
        m_project.clear();
        pselected=-1;
}


projectManager::~projectManager(void)
{
        m_project.clear();
}


void projectManager::AddProject(Project prj)
{
        m_project.push_back(prj);
}
/*void projectManager::AddProjectObject(int pindex, object3d object)
{
        if(pindex >=0 && pindex < m_project.size())
                m_project[pindex].AddObject(object);

}*/
Project * projectManager::GetProject(int index)
{
        Project * retp;

        if(index >=0 && index < m_project.size())
                retp= (&m_project[index]);
        else
                retp =NULL;

        return retp;
}
int projectManager::GetProject()
{
        return pselected;
}

void projectManager::CreateProject(Project * prj)
{
        //add project
/*
        m_project.push_back(*prj);

        string fullPath,apppath,filename;

        apppath=AfxGetApp()->m_pszExeName;


        apppath.Append(_T(".exe"));
        HMODULE hmod = GetModuleHandle(apppath);

        char df='\\';
        DWORD pathLen = ::GetModuleFileName( hmod, fullPath.GetBufferSetLength(MAX_PATH+1), MAX_PATH); // hmod of zero gets the main EXE

        fullPath.ReleaseBuffer( pathLen );
        fullPath.Delete(fullPath.GetLength()-apppath.GetLength(),apppath.GetLength());

        //create directory e subdirectory
        char *pname=prj->GetName();

        CString strpname,strapp;

        strpname=fullPath;

        strpname.Append(_T("projects\\"));
        strapp.Format(_T("%s\\"),pname);
        strpname.Append(strapp);



        {
                //create main directory of project


                DWORD dwAttr = GetFileAttributes(strpname);

                if (dwAttr == 0xffffffff)
                {
                        DWORD dwError = GetLastError();

                        if (dwError == ERROR_PATH_NOT_FOUND)
                        {
                                // path not found
                                CreateDirectory(strpname,NULL);
                        }


                }
                //save the project file
                CString prjfile=strpname;
                prjfile.Append(_T("//"));
                strapp.Format(_T("%s.3dp"),pname);
                prjfile.Append(strapp);
                {
                        prj->Save(strapp);
                }

        }
*/
        //create project file

}
void projectManager::FreeProject()
{
        m_project.clear();
}
void projectManager::DrawProject(int nindex)
{
        if(nindex>0 && nindex <= m_project.size())
                return;
        else
                m_project[nindex].Draw();
}
void projectManager::Pipeline()
{

}
