#include "l3d_image.h"
#include "l3d_imagetga.h"

l3d_imagetga::l3d_imagetga()
{
}
bool l3d_imagetga::load( char *filename )
{
    if( !type )
        getFileType( filename );
    switch( type )
    {
    case TT_CTGA32:
    case TT_CTGA24:
        return loadCTGA( filename );
    case TT_UTGA32:
    case TT_UTGA24:
        return loadUTGA( filename );
    default: break;
    }
    return false;
}
// loads a RLE compressed TGA as texture
bool l3d_imagetga::loadCTGA( char *filename )
{
    BYTE    TGAheader[12], header[6];
    FILE    *file;

    if( !type )
        getFileType( filename );
    if( type != TT_CTGA24 && type != TT_CTGA32 )
        return false;

    file = fopen( filename, "rb" );
    fread( TGAheader, 1, 12, file );
    fread( header, 1, 6, file );

    w = ( header[1] << 8 ) + header[0];
    h = ( header[3] << 8 ) + header[2];
    Bpp = header[4] >> 3;

    size = w * h * Bpp;
    if( !( data = new BYTE[ size ] ) )
        XTF( file );

    DWORD   pixelcount  = w * h,
            currentpixel = 0,
            currentbyte = 0;
    BYTE    *colorbuffer = new BYTE[ Bpp ];
    if( !colorbuffer )
    {
        freeData();
        XTF( file );
    }

    do
    {
        BYTE chunkheader = 0;

        if( fread( &chunkheader, sizeof( BYTE ), 1, file ) == 0 )
        {
            freeData();
            XTF( file );
        }

        if( chunkheader < 128 )
        {
            chunkheader++;
            for( short counter = 0; counter < chunkheader; counter++ )
            {
                if( fread( colorbuffer, 1, Bpp, file ) != Bpp )
                {
                    delete [] colorbuffer;
                    freeData();
                    XTF( file );
                }

                data[ currentbyte ] = colorbuffer[2];
                data[ currentbyte + 1 ] = colorbuffer[1];
                data[ currentbyte + 2 ] = colorbuffer[0];
                if( Bpp == 4 )
                    data[ currentbyte + 3 ] = colorbuffer[3];

                currentbyte += Bpp;
                currentpixel++;

                if( currentpixel > pixelcount )
                {
                    delete [] colorbuffer;
                    freeData();
                    XTF( file );
                }
            }
        }
        else
        {
            chunkheader -= 127;
            if( fread( colorbuffer, 1, Bpp, file ) != Bpp )
            {
                delete [] colorbuffer;
                freeData();
                XTF( file );
            }

            for( WORD counter = 0; counter < chunkheader; counter++ )
            {
                data[ currentbyte ] = colorbuffer[2];
                data[ currentbyte + 1 ] = colorbuffer[1];
                data[ currentbyte + 2 ] = colorbuffer[0];
                if( Bpp == 4 )
                    data[ currentbyte + 3 ] = colorbuffer[3];

                currentbyte += Bpp;
                currentpixel++;

                if( currentpixel > pixelcount )
                {
                    delete [] colorbuffer;
                    freeData();
                    XTF( file );
                }
            }
        }
    } while( currentpixel < pixelcount );

    delete [] colorbuffer;
    fclose( file );
    return true;
}

// loads an uncompressed TGA as texture
bool l3d_imagetga::loadUTGA( char *filename )
{
    BYTE    TGAheader[12], header[6];
    FILE    *file;

    if( !type )
        getFileType( filename );
    if( type != TT_UTGA24 && type != TT_UTGA32 )
        return false;

    file = fopen( filename, "rb" );
    fread( TGAheader, 1, 12, file );
    fread( header, 1, 6, file );

    w = ( header[1] << 8 ) + header[0];
    h = ( header[3] << 8 ) + header[2];
    Bpp = header[4] >> 3;

    size = w * h * Bpp;
    if( !( data = new BYTE[ size ] ) )
        XTF( file );

    if( !data || fread( data, 1, size, file ) != size )
    {
        freeData();
        XTF( file );
    }

    for( DWORD cswap = 0; cswap < size; cswap += Bpp )
        data[ cswap ] ^= data[ cswap+2 ] ^=
        data[ cswap ] ^= data[ cswap+2 ];

    fclose( file );
    return true;
}
