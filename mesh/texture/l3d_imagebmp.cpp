#include "l3d_image.h"
#include "l3d_imagebmp.h"

l3d_imagebmp::l3d_imagebmp()
{
}

bool l3d_imagebmp::loadBMP8( char *filename )
{
    BYTE        *img, *pal, head[0x36];
    DWORD       colors, isize;
    FILE        *file;

    if( !type )
        getFileType( filename );
    if( type != TT_BMP8 )
        return false;

    file = fopen( filename, "rb" );
    fread( head, 1, 0x36, file );

    Bpp = 3;
    w = CTOI( head[0x12] );
    h = CTOI( head[0x16] );
    isize = w * h;
    size = isize * 3;
    colors = CTOI( head[0x2E] );
    if( !colors || colors > 256 ) colors = 256;

    if( !( pal = new BYTE[ colors * 3 ] ) )
        XTF( file );
    for( WORD i = 0; i < colors; i++ )
    {
        DWORD   offset = i * 3;
        pal[ offset + 2 ] = fgetc( file );
        pal[ offset + 1 ] = fgetc( file );
        pal[ offset ] = fgetc( file );
        fgetc( file );
    }

    if( !( img = new BYTE[ isize ] ) )
    {
        delete [] pal;
        XTF( file );
    }
    fread( img, 1, isize, file );

    if( !( data = new BYTE[ size ] ) )
    {
        delete [] pal;
        delete [] img;
        XTF( file );
    }

    for( WORD i = 0; i < h; i++ )
        for( WORD j = 0; j < w; j++ )
        {
            DWORD   ioff = ( ( h - i - 1 ) * w * Bpp ) + ( j * Bpp ),
                    poff = img[ i * w + j ] * 3;
            data[ ioff + 0 ] = pal[ poff ];
            data[ ioff + 1 ] = pal[ poff + 1 ];
            data[ ioff + 2 ] = pal[ poff + 2 ];
        }

    delete [] pal;
    delete [] img;
    fclose( file );
    return true;
}

bool l3d_imagebmp::loadBMP24( char *filename )
{
    BYTE    head[0x36];
    FILE    *file;

    if( !type )
        getFileType( filename );
    if( type != TT_BMP24 )
        return false;

    file = fopen( filename, "rb" );
    fread( head, 1, 0x36, file );

    w = CTOI( head[0x12] );
    h = CTOI( head[0x16] );
    Bpp = 3;
    size = w * h * Bpp;

    if( !( data = new BYTE[ size ] ) )
        XTF( file );

    for( WORD i = 0; i < h; i++ )
        fread( data + ( ( h - i - 1 ) * w * Bpp ), w * Bpp, 1, file );

    for( DWORD cswap = 0; cswap < size; cswap += 3 )
        data[ cswap ] ^= data[ cswap + 2 ] ^=
        data[ cswap ] ^= data[ cswap + 2 ];

    fclose( file );
    return true;
}
