#include <stdio.h>
#include <stdlib.h>
#include "jpeg.h"
#include "l3d_image.h"

l3d_image::l3d_image()
{
    loaded=false;
}
TEXTYPE l3d_image::getFileType( char *filename )
{
    BYTE    head[0x36];
    FILE    *file = fopen( filename, "rb" );
    DWORD   bpp;

    #define GETHEADER   {   fseek(file,0,SEEK_SET);\
                            ZEROMEM(head);\
                            fread(head,0x36,1,file); }
    //#define TT_RETURN(t)    {fclose(file);type=(t);goto end;}

    TEXTYPE type;
    type = TT_UNKNOWN;
    if( !file )
    {
        fclose(file);
        type=(TT_UNKNOWN);
        return type;
    }


    // bitmap
    GETHEADER;
    if( head[0] == 'B' && head[1] == 'M' && !CTOI( head[0x1E] ) )
    {
        bpp = CTOI( head[0x1C] );
        if( bpp == 8 )
        {
            fclose(file);
            type=TT_BMP8;
            return type;
        }

        if( bpp == 24 )
            if( bpp == 8 )
            {
                fclose(file);
                type=TT_BMP24;
                return type;
            }

        fclose(file);
        type=TT_UNKNOWN;
            return type;

    }

    // true targa
    GETHEADER;
    bpp = head[16];
    if( !memcmp( head, cTGAcompare, 12 ) )
    {
        if( bpp == 24 )
        {
            fclose(file);
            type=TT_CTGA24;
            return type;
        }

        if( bpp == 32 )
        {
            fclose(file);
            type=TT_CTGA32;
            return type;
        }

        fclose(file);
        type=TT_UNKNOWN;
        return type;

    }
    if( !memcmp( head, uTGAcompare, 12 ) )
    {
        if( bpp == 24 )
        {
            fclose(file);
            type=TT_UTGA24;
            return type;
        }

        if( bpp == 32 )
        {
            fclose(file);
            type=TT_UTGA32;
            return type;
        }

        fclose(file);
        type=TT_UNKNOWN;
        return type;

    }

    // PCX
    GETHEADER;
    if( head[0] == 10 )
    {
        if( head[3] == 8 )
        {
            fclose(file);
            type=TT_PCX;
            return type;
        }

        fclose(file);
        type=TT_UNKNOWN;
        return type;
    }

    // JPEG
    fclose( file );
    Cjpg _jpg;
    _jpg.jpgFile.file = fopen( filename, "rb" );
    if( _jpg.jpeg_readmarkers() )
    {
        fclose( _jpg.jpgFile.file );
        fclose(file);
        type=TT_JPEG;
        return type;
    }

    #undef GETHEADER


}
void l3d_image::freeData( void )
{
    if( data )
        delete [] data;
    data = NULL;
}

// discharge texture
void l3d_image::unload( void )
{
    freeData();
    ZEROMEM( this );
}
