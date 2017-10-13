#ifndef L3D_IMAGEBMP_H
#define L3D_IMAGEBMP_H
#include "l3d_image.h"
class l3d_imagebmp:public l3d_image
{
public:
    l3d_imagebmp();



    bool load( char *filename );


    bool loadBMP8( char *filename );

    bool loadBMP24( char *filename );

};

#endif // L3D_IMAGEBMP_H
