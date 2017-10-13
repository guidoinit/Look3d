#ifndef LIB3DSIMPORTER_H
#define LIB3DSIMPORTER_H
#include <iostream>
#include <fstream>
#include <string>


#include "scene/lib/lib3ds-20080909/include/lib3ds.h"

using namespace std;

class Lib3DSImporter
{
public:
    Lib3DSImporter();
    Lib3DSImporter(string file);
    Lib3dsMesh *getmesh(int i);
    int getmeshsize();

private:

    Lib3dsFile * m_model;
    unsigned int m_TotalFaces;
};

#endif // LIB3DSIMPORTER_H
