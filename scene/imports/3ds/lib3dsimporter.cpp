#include <iostream>
#include <fstream>
#include <string>


#include "scene/lib/lib3ds-20080909/include/lib3ds.h"

#include "lib3dsimporter.h"

#include <string.h>

Lib3DSImporter::Lib3DSImporter()
{
}

Lib3DSImporter::Lib3DSImporter(string filename)
{
    m_TotalFaces = 0;

    m_model = lib3ds_file_open(filename.c_str());
    // If loading the model failed, we throw an exception
    if(!m_model)
    {
        throw strcat("Unable to load ", filename.c_str());
    }
}
Lib3dsMesh * Lib3DSImporter::getmesh(int i)
{
    Lib3dsMesh *pmesh;
    if(i>=0 && i<m_model->nmeshes)
    {
        pmesh=m_model->meshes[i];

    }
    return (pmesh);
}
int Lib3DSImporter::getmeshsize()
{
    return(m_model->nmeshes);
}
