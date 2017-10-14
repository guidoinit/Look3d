/*
 * texture loader
 *
 * Author:      Andrea "TexZK" Zoppi
 * Homepage:    http://texzk.gameprog.it
 *      for:    Game Programming Italia - http://gameprog.it
 * E-mail:      texzk@gameprog.it or gnegno88@libero.it
 *
 */

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/glu.h>
#include "jpeg.h"
#include "texture.h"

const BYTE  cTGAcompare[12] = { 0,0,10,0,0,0,0,0,0,0,0,0 };
const BYTE  uTGAcompare[12] = { 0,0, 2,0,0,0,0,0,0,0,0,0 };

///////////////////////////////
//  texture CLASS
//

texture::texture()
{
    loaded = false;
    data = NULL;
}

texture::~texture()
{
    unload();
}

texture::texture( char *filename )
{
    load( filename, true );
}

texture::texture(const string &filename )
{


    char * _filename=new char[filename.length()+1];

    strcpy(_filename, filename.c_str());

    load( _filename, false );
}


// returns the texture file type
TEXTYPE texture::getFileType( char *filename )
{
    BYTE    head[0x36];
    FILE    *file = fopen( filename, "rb" );
    DWORD   bpp;

    #define GETHEADER   {   fseek(file,0,SEEK_SET);\
                            ZEROMEM(head);\
                            fread(head,0x36,1,file); }
    #define TT_RETURN(t)    {fclose(file);type=(t);goto end;}
    
    type = TT_UNKNOWN;
    if( !file )
        TT_RETURN( TT_UNKNOWN );
    
    // bitmap
    GETHEADER;
    if( head[0] == 'B' && head[1] == 'M' && !CTOI( head[0x1E] ) )
    {
        bpp = CTOI( head[0x1C] );
        if( bpp == 8 )
            TT_RETURN( TT_BMP8 );
        if( bpp == 24 )
            TT_RETURN( TT_BMP24 );
        TT_RETURN( TT_UNKNOWN );
    }
    
    // true targa
    GETHEADER;
    bpp = head[16];
    if( !memcmp( head, cTGAcompare, 12 ) )
    {
        if( bpp == 24 )
            TT_RETURN( TT_CTGA24 );
        if( bpp == 32 )
            TT_RETURN( TT_CTGA32 );
        TT_RETURN( TT_UNKNOWN );
    }
    if( !memcmp( head, uTGAcompare, 12 ) )
    {
        if( bpp == 24 )
            TT_RETURN( TT_UTGA24 );
        if( bpp == 32 )
            TT_RETURN( TT_UTGA32 );
        TT_RETURN( TT_UNKNOWN );
    }
    
    // PCX
    GETHEADER;
    if( head[0] == 10 )
    {
        if( head[3] == 8 )
            TT_RETURN( TT_PCX );
        TT_RETURN( TT_UNKNOWN );
    }
    
    // JPEG
    fclose( file );
    _jpg.jpgFile.file = fopen( filename, "rb" );
    if( _jpg.jpeg_readmarkers() )
    {
        fclose( _jpg.jpgFile.file );
        TT_RETURN( TT_JPEG );
    }
    
    #undef GETHEADER
    #undef TT_RETURN
end:
    return type;
}

// loads a texture
void texture::bind()
{

    glBindTexture(GL_TEXTURE_2D, id);

}

void texture::loadnull()

{
    BYTE     temp[8][8][3];

    // build the temp texture
    ZEROMEM( temp );
    for( int i = 0; i < 8; i++ )
    {
        temp[ i ][0][0] = temp[ i ][0][1] = temp[ i ][0][2] = 0xFF;
        temp[ i ][7][0] = temp[ i ][7][1] = temp[ i ][7][2] = 0xFF;
        temp[0][ i ][0] = temp[0][ i ][1] = temp[0][ i ][2] = 0xFF;
        temp[7][ i ][0] = temp[7][ i ][1] = temp[7][ i ][2] = 0xFF;
    }

    unload();
    Bpp = 3;
    w = h = 8;
    size = w * h * Bpp;
    data = new BYTE[ size ];
    memcpy( data, temp, size );

    mode = GL_RGB;


    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glGenTextures( 1, &id );
    glBindTexture( GL_TEXTURE_2D, id );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TEX_MAG_FILTER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TEX_MIN_FILTER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexImage2D( GL_TEXTURE_2D, 0, mode, w, h, 0, mode, GL_UNSIGNED_BYTE, data );
    //gluBuild2DMipmaps( GL_texture_2D, mode, w, h, mode, GL_UNSIGNED_BYTE, data );



}

bool texture::load( char *filename, bool freemem )
{
    bool    good = false;
    unload();
    
    switch( getFileType( filename ) )
    {
    case TT_BMP8:   good = loadBMP8( filename ); break;
    case TT_BMP24:  good = loadBMP24( filename ); break;
    case TT_CTGA24: good = loadCTGA( filename ); break;
    case TT_CTGA32: good = loadCTGA( filename ); break;
    case TT_UTGA24: good = loadUTGA( filename ); break;
    case TT_UTGA32: good = loadUTGA( filename ); break;
    case TT_PCX:    good = loadPCX8( filename ); break;
    case TT_JPEG:   good = loadJPEG( filename ); break;
    default: break;
    }
    
    if( !good )
    {
        BYTE     temp[8][8][3];
        
        // build the temp texture
        ZEROMEM( temp );
        for( int i = 0; i < 8; i++ )
        {
            temp[ i ][0][0] = temp[ i ][0][1] = temp[ i ][0][2] = 0xFF;
            temp[ i ][7][0] = temp[ i ][7][1] = temp[ i ][7][2] = 0xFF;
            temp[0][ i ][0] = temp[0][ i ][1] = temp[0][ i ][2] = 0xFF;
            temp[7][ i ][0] = temp[7][ i ][1] = temp[7][ i ][2] = 0xFF;
        }
        
        unload();
        Bpp = 3;
        w = h = 8;
        size = w * h * Bpp;
        data = new BYTE[ size ];
        memcpy( data, temp, size );
        #ifdef __gl_h_
        mode = GL_RGB;
        #endif
        build();
        return false;
    }
    
    #ifdef __gl_h_
    mode = ( Bpp == 4 ) ? GL_RGBA : GL_RGB;
    #endif
    
    build();
    loaded = true;
    
    if( freemem )
        freeData();
    
    return true;
}

bool texture::load( char *filename )
{
    return load( filename,
    #ifdef __gl_h_
    true
    #else
    false
    #endif
    );
}

// discharge texture data
void texture::freeData( void )
{
    if( data )
        delete [] data;
    data = NULL;
}

// discharge texture
void texture::unload( void )
{
    freeData();
    ZEROMEM( this );
}

// builds the texture in the OpenGL memory
int texture::getid()
{
	return id;
}
void texture::build( void )
{
    if( !data ) return;
    

    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glGenTextures( 1, &id );
    glBindTexture( GL_TEXTURE_2D, id );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TEX_MAG_FILTER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TEX_MIN_FILTER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexImage2D( GL_TEXTURE_2D, 0, mode, w, h, 0, mode, GL_UNSIGNED_BYTE, data );
    gluBuild2DMipmaps( GL_TEXTURE_2D, mode, w, h, mode, GL_UNSIGNED_BYTE, data );

}

// load a BMP 24bit as texture
bool texture::loadBMP24( char *filename )
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

// loads a BMP 8bit as texture
bool texture::loadBMP8( char *filename )
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

// loads a generic TGA file
bool texture::loadTGA( char *filename )
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
bool texture::loadCTGA( char *filename )
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
bool texture::loadUTGA( char *filename )
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

// loads a JPEG image
bool texture::loadJPEG( char *filename )
{
    if( _jpg.jpgFile.data )
        delete [] _jpg.jpgFile.data;
    memset( &_jpg.jpgFile, 0, sizeof( _jpg.jpgFile ) );
    
    if( !type )
        getFileType( filename );
    if( type != TT_JPEG )
        return false;
    
    _jpg.jpgFile.file = fopen( filename, "rb" );
    _jpg.jpeg_readmarkers();
    
    w = _jpg.jpgFile.width;
    h = _jpg.jpgFile.height;
    Bpp = _jpg.jpgFile.num_components;
    size = w * h * Bpp;
    
    if( !( _jpg.jpgFile.data = new BYTE[ w * h * Bpp ] ) )
        XTF( _jpg.jpgFile.file );
    _jpg.jpeg_decompress();     
    if( _jpg.jpgFile.num_components == 3 )
        _jpg.jpeg_ycbcr2rgb();
    fclose( _jpg.jpgFile.file );
    
    if( !( data = new BYTE[ size ] ) )
    {
        delete [] _jpg.jpgFile.data;
        _jpg.jpgFile.data = NULL;
        return false;
    }
    memcpy( data, _jpg.jpgFile.data, size );
    delete [] _jpg.jpgFile.data;
    _jpg.jpgFile.data = NULL;
    return true;
}

// loads a 8bit PCX
bool texture::loadPCX8( char *filename )
{
    struct {
        BYTE    id,
                version,
                coding,
                bits;
        WORD    minx,
                miny,
                maxx,
                maxy,
                risx,
                risy;
        BYTE    colormap[48],
                reserved,
                planes;
        WORD    rows,
                typecmap,
                screenx,
                screeny;
        BYTE    blank[54];
    } header;
    WORD    repeat, code, value;
    long    isize;
    BYTE    *img, *pal, *ptr;
    FILE    *file = fopen( filename, "rb" );
    
    if( !file )
        return false;
    
    fread( &header, sizeof( header ), 1, file );
    if( header.id != 10 || header.coding >> 1 || header.bits != 8 )
        XTF( file );

    w = header.maxx - header.minx + 1;
    h = header.maxy - header.miny + 1;
    Bpp = 3;
    size = w * h * Bpp;
    isize = w * h;
    
    if( !( img = new BYTE[ isize ] ) )
        XTF( file );
    
    if( header.coding == 0 )
    {
        if( fread( img, isize, 1, file ) != isize )
        {
            delete [] img;
            XTF( file );
        }
    }
    else
    {
        isize = w * h;
        ptr = img;
        while( isize > 0 && !feof( file ) )
        {
            code = fgetc( file );
            if( ( code & 0xC0 ) == 0xC0 )
            {
                repeat = code & 0x3F;
                value = fgetc( file );
            }
            else
            {
                repeat = 1;
                value = code;
            }
            isize -= repeat;
            
            while( repeat-- )
                *( ptr++ ) = value;
        }
    }
    
    if( !( pal = new BYTE[ 768 ] ) )
    {
        delete [] img;
        XTF( file );
    }
    fseek( file, -768, SEEK_END );
    for( WORD i = 0; i < 256; i++ )
    {
        DWORD   offset = i * 3;
        pal[ offset ] = fgetc( file ) >> 0;
        pal[ offset + 1 ] = fgetc( file ) >> 0;
        pal[ offset + 2 ] = fgetc( file ) >> 0;
    }
    fclose( file );
    
    data = new BYTE[ size ];
    for( WORD i = 0; i < h; i++ )
        for( WORD j = 0; j < w; j++ )
        {
            DWORD   ioff = ( i * w * Bpp ) + ( j * Bpp ),
                    poff = img[ i * w + j ] * 3;
            data[ ioff + 0 ] = pal[ poff ];
            data[ ioff + 1 ] = pal[ poff + 1 ];
            data[ ioff + 2 ] = pal[ poff + 2 ];
        }
    
    delete [] img;
    delete [] pal;
    return true;
}

// saves the texture as bitmap file
bool texture::saveBMP( char *filename )
{
    FILE    *out;
    DWORD   i, j;
    
    if( !data )
        return false;
    
    if( !( out = fopen( filename, "wb" ) ) )
        return false;
    
    fwrite( "BM", 2, 1, out );
    fwrite( &( i = 0x36 + size ), 4, 1, out );
    fwrite( &( i = 0 ), 2, 1, out );
    fwrite( &( i = 0 ), 2, 1, out );
    fwrite( &( i = 0x36 ), 4, 1, out );
    
    fwrite( &( i = 40 ), 4, 1, out );
    fwrite( &( i = w ), 4, 1, out );
    fwrite( &( i = h ), 4, 1, out );
    fwrite( &( i = 1 ), 2, 1, out );
    fwrite( &( i = 24 ), 2, 1, out );
    fwrite( &( i = 0 ), 4, 1, out );
    fwrite( &( i = size ), 4, 1, out );
    fwrite( &( i = 0x0AEB ), 4, 1, out );
    fwrite( &( i = 0x0AEB ), 4, 1, out );
    fwrite( &( i = 0 ), 4, 1, out );
    fwrite( &( i = 0 ), 4, 1, out );
    
    fseek( out, 0x36, SEEK_SET );
    for( i = 0; i < h; i++ )
        for( j = 0; j < w; j++ )
        {
            DWORD   offset = ( ( h - i - 1 ) * w * Bpp ) + ( j * Bpp );
            fputc( data[ offset + 2 ], out );
            fputc( data[ offset + 1 ], out );
            fputc( data[ offset + 0 ], out );
        }
    
    fclose( out );
    return true;
}

