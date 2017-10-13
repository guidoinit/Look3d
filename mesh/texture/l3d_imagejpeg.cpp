#include "l3d_imagejpeg.h"

l3d_imagejpeg::l3d_imagejpeg()
{
}
bool l3d_imagejpeg::loadJPEG( char *filename )
{
    if(  data )
        delete []  data;
    //memset( & jpgFile, 0, sizeof(  jpgFile ) );

    if( !type )
        getFileType( filename );
    if( type != TT_JPEG )
        return false;

     file = fopen( filename, "rb" );
     jpeg_readmarkers();

    w =  width;
    h =  height;
    Bpp =  num_components;
    size = w * h * Bpp;

    if( !(    data = new BYTE[ w * h * Bpp ] ) )
        XTF(    file );
     jpeg_decompress();
    if(    num_components == 3 )
         jpeg_ycbcr2rgb();
    fclose(    file );

    if( !( data = new BYTE[ size ] ) )
    {
        delete []    data;
           data = NULL;
        return false;
    }
    memcpy( data,    data, size );
    delete []    data;
       data = NULL;
    return true;
}
