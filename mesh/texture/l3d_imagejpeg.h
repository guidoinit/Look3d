#ifndef L3D_IMAGEJPEG_H
#define L3D_IMAGEJPEG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l3d_image.h"

typedef unsigned char   JBYTE;
typedef unsigned short  JWORD;
typedef unsigned long   JDWORD;
/*
typedef struct
{
    JBYTE   bits[16];
    JBYTE   hval[256];
    JBYTE   size[256];
    JWORD   code[256];
} JHUFF;






const int jpeg_zigzag[64] =
{
     0,  1,  5,  6, 14, 15, 27, 28,
     2,  4,  7, 13, 16, 26, 29, 42,
     3,  8, 12, 17, 25, 30, 41, 43,
     9, 11, 18, 24, 31, 40, 44, 53,
    10, 19, 23, 32, 39, 45, 52, 54,
    20, 22, 33, 38, 46, 51, 55, 60,
    21, 34, 37, 47, 50, 56, 59, 61,
    35, 36, 48, 49, 57, 58, 62, 63
};

const float aanscale[8] =
{
    1.0f, 1.387039845f, 1.306562965f, 1.175875602f,
    1.0f, 0.785694958f, 0.541196100f, 0.275899379f
};*/
class l3d_imagejpeg:public l3d_image
{
public:
    l3d_imagejpeg();
    JHUFF   hac[4];
    JHUFF   hdc[4];
    long    qtable[4][64];
    struct {
        long    ss,se;
        long    ah,al;
    } scan;
    long    dc[3];
    long    curbit;
    JBYTE   curbyte;
    FILE    *file;
    long    width;
    long    height;
    JBYTE   *data;
    long    data_precision;
    long    num_components;
    long    restart_interval;
    struct {
        long    id;
        long    h;
        long    v;
        long    t;
        long    td;
        long    ta;
    } component_info[3];

    bool    loadJPEG( char *filename );
    int jpeg_read_byte( void )
    {
        fread( &curbyte, 1, 1,  file );
       curbit = 0;
        return curbyte;
    }

    int jpeg_read_word( void )
    {
        JWORD   i;
        fread( &i, 2, 1,file );
        i = ( ( i << 8 ) & 0xFF00 ) + ( ( i >> 8 ) & 0x00FF );
        return i;
    }

    int jpeg_read_bit( void )
    {
        register int    i;
        if( curbit == 0 )
        {
            jpeg_read_byte();
            if( curbyte == 0xFF )
            {
                while( curbyte == 0xFF )
                    jpeg_read_byte();
                if(  curbyte >= 0xD0 &&  curbyte <= 0xD7 )
                    ::memset(  dc, 0, sizeof( long ) * 3 );
                if(  curbyte == 0 )
                     curbyte = 0xFF;
                else jpeg_read_byte();
            }
        }
        i = (  curbyte >> ( 7 -  curbit++ ) ) & 0x01;
        if(  curbit == 8 )
             curbit = 0;
        return i;
    }

    int jpeg_read_bits( int num )
    {
        register int    i, j;
        for( i = 0, j = 0; i < num; i++ )
        {
            j <<= 1;
            j |= jpeg_read_bit();
        }
        return j;
    }

    int jpeg_bit2int( int bit, int i )
    {
        if( ( i & ( 1 << ( bit - 1 ) ) ) > 0 )
            return i;
        return -( i ^ ( ( 1 << bit ) - 1 ) );
    }

    int jpeg_huffmancode( JHUFF *table )
    {
        register int    i, size, code;
        for( size = 1, code = 0, i = 0; size < 17; size++ )
        {
            code <<= 1;
            code |= jpeg_read_bit();
            for( ; table->size[ i ] <= size ;i++ )
                if( table->code[ i ] == code )
                    return table->hval[ i ];
        }
        return code;
    }

    void jpeg_idct( float *data )
    {
        float   t0, t1, t2, t3, t4, t5, t6, t7,
                t10, t11, t12, t13,
                z5, z10, z11, z12, z13;
        float   *dataptr;
        int     i;
        dataptr = data;
        for( i = 0; i < 8; i++ )
        {
            t0 = dataptr[ 8 * 0 ];
            t1 = dataptr[ 8 * 2 ];
            t2 = dataptr[ 8 * 4 ];
            t3 = dataptr[ 8 * 6 ];
            t10 = t0 + t2;
            t11 = t0 - t2;
            t13 = t1 + t3;
            t12 = - t13 + ( t1 - t3 ) * 1.414213562f;
            t0 = t10 + t13;
            t3 = t10 - t13;
            t1 = t11 + t12;
            t2 = t11 - t12;
            t4 = dataptr[ 8 * 1 ];
            t5 = dataptr[ 8 * 3 ];
            t6 = dataptr[ 8 * 5 ];
            t7 = dataptr[ 8 * 7 ];
            z13 = t6 + t5;
            z10 = t6 - t5;
            z11 = t4 + t7;
            z12 = t4 - t7;
            t7 = z11 + z13;
            t11 = ( z11 - z13 ) * 1.414213562f;
            z5 = ( z10 + z12 ) * 1.847759065f;
            t10 = - z5 + z12 * 1.082392200f;
            t12 = z5 - z10 * 2.613125930f;
            t6 = t12 - t7;
            t5 = t11 - t6;
            t4 = t10 + t5;
            dataptr[ 8 * 0 ] = t0 + t7;
            dataptr[ 8 * 7 ] = t0 - t7;
            dataptr[ 8 * 1 ] = t1 + t6;
            dataptr[ 8 * 6 ] = t1 - t6;
            dataptr[ 8 * 2 ] = t2 + t5;
            dataptr[ 8 * 5 ] = t2 - t5;
            dataptr[ 8 * 4 ] = t3 + t4;
            dataptr[ 8 * 3 ] = t3 - t4;
            dataptr++;
        }
        dataptr = data;
        for( i = 0; i < 8; i++ )
        {
            t10 = dataptr[0] + dataptr[4];
            t11 = dataptr[0] - dataptr[4];
            t13 = dataptr[2] + dataptr[6];
            t12 = - t13 + ( dataptr[2] - dataptr[6] ) * 1.414213562f;
            t0 = t10 + t13;
            t3 = t10 - t13;
            t1 = t11 + t12;
            t2 = t11 - t12;
            z13 = dataptr[5] + dataptr[3];
            z10 = dataptr[5] - dataptr[3];
            z11 = dataptr[1] + dataptr[7];
            z12 = dataptr[1] - dataptr[7];
            t7 = z11 + z13;
            t11 = ( z11 - z13 ) * 1.414213562f;
            z5 = ( z10 + z12 ) * 1.847759065f;
            t10 = - z5 + z12 * 1.082392200f;
            t12 = z5 - z10 * 2.613125930f;
            t6 = t12 - t7;
            t5 = t11 - t6;
            t4 = t10 + t5;
            dataptr[0] = t0 + t7;
            dataptr[7] = t0 - t7;
            dataptr[1] = t1 + t6;
            dataptr[6] = t1 - t6;
            dataptr[2] = t2 + t5;
            dataptr[5] = t2 - t5;
            dataptr[4] = t3 + t4;
            dataptr[3] = t3 - t4;
            dataptr += 8;
        }
    }

    int jpeg_readmarkers( void )
    {
        int     marker, length, i, j, k, l, m;
        JHUFF   *hptr;
        for( ; ; )
        {
            marker = jpeg_read_byte();
            if( marker != 0xFF )
                return 0;
            marker = jpeg_read_byte();
            if( marker != 0xD8 )
            {
                length = jpeg_read_word();
                length -= 2;
                switch( marker )
                {
                    case 0xC0:
                         data_precision = jpeg_read_byte();
                         height = jpeg_read_word();
                         width = jpeg_read_word();
                         num_components = jpeg_read_byte();
                        if( length - 6 !=  num_components * 3 )
                            return 0;
                        for( i = 0; i <  num_components; i++ )
                        {
                             component_info[ i ].id = jpeg_read_byte();
                            j = jpeg_read_byte();
                             component_info[ i ].h = ( j >> 4 ) & 0x0F;
                             component_info[ i ].v = j & 0x0F;
                             component_info[ i ].t = jpeg_read_byte();
                        }
                        break;
                    case 0xC1:
                    case 0xC2:
                    case 0xC3:
                    case 0xC5:
                    case 0xC6:
                    case 0xC7:
                    case 0xC8:
                    case 0xC9:
                    case 0xCA:
                    case 0xCB:
                    case 0xCD:
                    case 0xCE:
                    case 0xCF:
                        return 0;
                        break;
                    case 0xC4:
                        while( length > 0 )
                        {
                            k = jpeg_read_byte();
                            if( k & 0x10 )
                                hptr = & hac[ k & 0x0F ];
                            else
                                hptr = & hdc[ k & 0x0F ];
                            for( i = 0, j = 0; i < 16; i++ )
                            {
                                hptr->bits[ i ] = jpeg_read_byte();
                                j += hptr->bits[ i ];
                            }
                            length -= 17;
                            for( i = 0; i < j; i++ )
                                hptr->hval[ i ] = jpeg_read_byte();
                            length -= j;
                            for( i = 0, k = 0, l = 0; i < 16; i++ )
                            {
                                for( j = 0; j < hptr->bits[i]; j++, k++ )
                                {
                                    hptr->size[ k ] = i + 1;
                                    hptr->code[ k ] = l++;
                                }
                                l <<= 1;
                            }
                        }
                        break;
                    case 0xDB:
                        while( length > 0 )
                        {
                            j = jpeg_read_byte();
                            k = ( j >> 4 ) & 0x0F;
                            for( i = 0; i < 64; i++ )
                            {
                                if( k )  qtable[ j ][ i ] = jpeg_read_word();
                                else     qtable[ j ][ i ] = jpeg_read_byte();
                            }
                            length -= 65;
                            if( k ) length -= 64;
                        }
                        break;
                    case 0xD9:
                        return 0;
                    case 0xDA:
                        j = jpeg_read_byte();
                        for( i = 0; i < j; i++ )
                        {
                            k = jpeg_read_byte();
                            m = jpeg_read_byte();
                            for( l = 0; l <  num_components; l++ )
                                if(  component_info[ l ].id == k )
                                {
                                     component_info[ l ].td = ( m >> 4 ) & 0x0F;
                                     component_info[ l ].ta = m & 0x0F;
                                }
                        }
                         scan.ss = jpeg_read_byte();
                         scan.se = jpeg_read_byte();
                        k = jpeg_read_byte();
                         scan.ah = ( k >> 4 ) & 0x0F;
                         scan.al = k & 0x0F;
                        return 1;
                    case 0xDD:
                         restart_interval = jpeg_read_word();
                        break;
                    default:
                        fseek(  file, length, SEEK_CUR );
                        break;
                }
            }
        }
    }





    void jpeg_decompress( void )
    {
        register int    x, y, i, j, k, l, c;
        int             X, Y, H, V, plane, scaleh[3], scalev[3];
        static float    vector[64],dct[64];
        scaleh[0] = 1;
        scalev[0] = 1;
        if(  num_components == 3 )
        {
            scaleh[1] =  component_info[0].h /  component_info[1].h;
            scalev[1] =  component_info[0].v /  component_info[1].v;
            scaleh[2] =  component_info[0].h /  component_info[2].h;
            scalev[2] =  component_info[0].v /  component_info[2].v;
        }
        memset(  dc, 0, sizeof( long ) * 3 );
        for( Y = 0; Y <  height; Y +=  component_info[0].v << 3 )
        {
            if(  restart_interval > 0 )
                 curbit = 0;
            for( X = 0; X <  width; X +=  component_info[0].h << 3 )
            {
                for( plane = 0; plane <  num_components; plane++ )
                    for( V = 0; V <  component_info[ plane ].v; V++ )
                        for( H = 0; H <  component_info[ plane ].h; H++ )
                        {
                            i = jpeg_huffmancode( & hdc[ component_info[ plane ].td ] );
                            i &= 0x0F;
                            vector[0] =  dc[ plane ] + (float)jpeg_bit2int( i, jpeg_read_bits( i ) );
                             dc[ plane ] = (int)vector[0];
                            i = 1;
                            while( i < 64 )
                            {
                                j = jpeg_huffmancode( & hac[  component_info[ plane ].ta ] );
                                if( j == 0 )
                                    while( i < 64 )
                                        vector[ i++ ] = 0;
                                else
                                {
                                    k = i + ( ( j >> 4 ) & 0x0F );
                                    while( i < k )
                                        vector[ i++ ] = 0;
                                    j &= 0x0F;
                                    vector[ i++ ] = (float)jpeg_bit2int( j ,jpeg_read_bits( j ) );
                                }
                            }
                            k =  component_info[plane].t;
                            for( y = 0, i = 0; y < 8; y++ )
                                for( x = 0; x < 8; x++, i++ )
                                {
                                    j = jpeg_zigzag[ i ];
                                    dct[ i ] = vector[ j ] *  qtable[ k ][ j ] *
                                     aanscale[ x ] * aanscale[ y ];
                                }
                            jpeg_idct( dct );
                            for( y = 0; y < 8; y++ )
                                for( x = 0; x < 8; x++ )
                                {
                                    c = ( (int)dct[ ( y << 3 ) + x ] >> 3 ) + 128;
                                    if( c < 0 )
                                        c = 0;
                                    else if( c > 255 )
                                        c = 255;
                                    if( scaleh[ plane ] == 1 && scalev[ plane ] == 1 )
                                    {
                                        i = X + x + ( H << 3 );
                                        j = Y + y + ( V << 3 );
                                        if( i <  width && j <  height )
                                             data[ ( ( j *  width + i ) *  num_components ) + plane ] = c;
                                    }
                                    else for( l = 0; l < scalev[ plane ]; l++ )
                                        for( k = 0; k < scaleh[ plane ]; k++ )
                                        {
                                            i = X + ( x + ( H << 3 ) ) * scaleh[ plane ] + k;
                                            j = Y + ( y + ( V << 3 ) ) * scalev[ plane ] + l;
                                            if( i <  width && j <  height )
                                                 data[ ( ( j *  width + i ) *  num_components ) + plane ] = c;
                                    }
                                }
                        }
            }
        }
    }

    void jpeg_ycbcr2rgb( void )
    {
        int     i, Y, Cb, Cr, R, G, B;
        for( i = 0; i <  width *  height * 3; i += 3 )
        {
            Y =  data[ i ];
            Cb =  data[ i + 1 ] - 128;
            Cr =  data[ i + 2 ] - 128;
            R = (int)( Y + 1.40200f * Cr );
            G = (int)( Y - 0.34414f * Cb - 0.71414f * Cr );
            B = (int)( Y + 1.77200f * Cb );
            if( R < 0 ) R = 0;
            else if( R > 255 ) R = 255;
            if( G < 0 ) G = 0;
            else if( G > 255 ) G = 255;
            if( B < 0 ) B = 0;
            else if( B > 255 ) B = 255;
             data[ i ] = R;
             data[ i + 1 ] = G;
             data[ i + 2 ] = B;
        }
    }


};

#endif // L3D_IMAGEJPEG_H
