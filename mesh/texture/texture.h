//    This file is part of Look3D program.

//    Look3D is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Look3D is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>
//	
//
/*
 * texture class
 */

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#define USING_OPENGL
#define __gl_h

#include <math.h>
#include <stdio.h>
//#include <mem.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include "jpeg.h"


#ifdef __gl_h_
#  define TEX_MIN_FILTER    GL_LINEAR_MIPMAP_NEAREST
#  define TEX_MAG_FILTER    GL_LINEAR
#endif

#undef  BYTE
#define BYTE    unsigned char
#undef  WORD
#define WORD    unsigned short
#undef  DWORD
#define DWORD   unsigned long
#ifndef __gl_h_
#  define GLuint DWORD
#endif

#ifdef  ZEROMEM
#  error Macro ZEROMEM already used!
#else
#  define   ZEROMEM(v)  memset((v),0,sizeof(v))
#endif

#ifdef  XTF
#  error Macro XTF already defined!
#else
#  define   XTF(f)      {fclose(f);return false;}
#endif

#ifdef  CTOI
#  error Macro CTOI already defined!
#else
#  define   CTOI(c)     (*((long*)&(c)))
#endif

typedef enum
{
    TT_UNCHECKED = 0,
    TT_UNKNOWN,
    TT_BMP24,
    TT_BMP8,
    TT_UTGA24,
    TT_UTGA32,
    TT_CTGA24,
    TT_CTGA32,
    TT_PCX,
    TT_JPEG
} TEXTYPE;

using namespace std;
///////////////////////////////
// texture CLASS
//

class texture
{
public:
    // constructors / destructors
    texture();
    texture(const texture& tex)
    {
        w=tex.w;
        h=tex.h;
        Bpp=tex.Bpp;
        mode=tex.mode;
        id=tex.id;
        size=tex.size;
        loaded=tex.loaded;
        masked=tex.masked;
        type=tex.type;


        //buffer
        data= (BYTE*)malloc(sizeof(tex.data));
        //memcpy(data,tex.data,sizeof(tex.data));




    }
    texture& operator=( const texture &tex )
    {
        w=tex.w;
        h=tex.h;
        Bpp=tex.Bpp;
        mode=tex.mode;
        id=tex.id;
        size=tex.size;
        loaded=tex.loaded;
        masked=tex.masked;
        type=tex.type;


        //buffer
        data= (BYTE*)malloc(sizeof(tex.data));
        //memcpy(data,tex.data,sizeof(tex.data));


        return *this;

    }

    texture( char *filename );
    texture(const string &filename );
    ~texture();
    Cjpg _jpg;
    // variables
    WORD    w, h,
            Bpp,
            mode;
    GLuint  id;
    DWORD   size;
    BYTE    *data;
    bool    loaded,
            masked;
    TEXTYPE type;
    
    // methods
    TEXTYPE getFileType( char *filename );
    bool    load( char *filename, bool freemem );
    bool    load( char *filename );
    bool    loadBMP8( char *filename );
    bool    loadBMP24( char *filename );
    bool    loadTGA( char *filename );
    bool    loadUTGA( char *filename );
    bool    loadCTGA( char *filename );
    bool    loadJPEG( char *filename );
    bool    loadPCX8( char *filename );
    bool    saveBMP( char *filename );
    void    freeData( void );
    void    unload( void );
    void    build( void );
    int getid();
    void bind();
    void loadnull();
};

#endif  /* !__texture_H__ */

