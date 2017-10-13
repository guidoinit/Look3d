#ifndef L3D_IMAGETGA_H
#define L3D_IMAGETGA_H
#include "l3d_image.h"
class l3d_imagetga:public l3d_image
{
public:
    l3d_imagetga();

    bool load(char *filename);
    bool loadCTGA( char *filename );
    bool loadUTGA( char *filename );
};

#endif // L3D_IMAGETGA_H
