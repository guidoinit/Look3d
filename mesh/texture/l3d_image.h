#ifndef L3D_IMAGE_H
#define L3D_IMAGE_H

#include <QGLWidget>
#include "jpeg.h"
#undef  BYTE
#define BYTE    unsigned char
#undef  WORD
#define WORD    unsigned short
#undef  DWORD
#define DWORD   unsigned long


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

const BYTE  cTGAcompare[12] = { 0,0,10,0,0,0,0,0,0,0,0,0 };
const BYTE  uTGAcompare[12] = { 0,0, 2,0,0,0,0,0,0,0,0,0 };
class l3d_image
{
public:
    l3d_image();
    TEXTYPE getFileType( char *filename );


    WORD    w, h,
            Bpp,
            mode;
    GLuint  id;
    DWORD   size;
    BYTE    *data;
    bool    loaded,masked;
    TEXTYPE type;

    void    freeData( void );
    void    unload( void );


};

#endif // L3D_IMAGE_H
