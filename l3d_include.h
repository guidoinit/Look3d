#ifndef L3D_INCLUDE_H
#define L3D_INCLUDE_H

#include <QOpenGLFunctions>

typedef double l3d_double;
typedef float l3d_float;
typedef char l3d_char;
typedef unsigned char l3d_uchar;
typedef char * l3d_string;
typedef const char * l3d_const_string;
typedef int l3d_int16;
typedef GLfloat l3d_glfloat;
typedef GLuint l3d_gluint;
typedef unsigned int l3d_uint;
typedef short l3d_short;
typedef unsigned short l3d_ushort;
typedef GLboolean l3d_bool;
typedef void* l3d_void;
enum l3d_buffertype
{
    buffer_array=GL_ARRAY_BUFFER,
    buffer_atomic_counter=GL_ATOMIC_COUNTER_BUFFER,
    buffer_copy_read=  GL_COPY_READ_BUFFER,
    buffer_copy_write=  GL_COPY_WRITE_BUFFER,
    buffer_draw_indirect= GL_DRAW_INDIRECT_BUFFER,
    buffer_dispatch_indirect= GL_DISPATCH_INDIRECT_BUFFER,
    buffer_element_array=GL_ELEMENT_ARRAY_BUFFER,
    buffer_pixel_pack= GL_PIXEL_PACK_BUFFER,
    buffer_pixel_unpak=GL_PIXEL_UNPACK_BUFFER,
    buffer_shader_storage=GL_SHADER_STORAGE_BUFFER,
    buffer_texture= GL_TEXTURE_BUFFER,
    buffer_transform_feedback= GL_TRANSFORM_FEEDBACK_BUFFER,
    buffer_uniform=  GL_UNIFORM_BUFFER,


    buffer_last=65535
};
enum l3d_capabilities
{
    cap_color=GL_COLOR_ARRAY,
    cap_edge_flag=GL_EDGE_FLAG_ARRAY,
    cap_fog_coord=GL_FOG_COORD_ARRAY,
    cap_index=GL_INDEX_ARRAY,
    cap_normal=GL_NORMAL_ARRAY,
    cap_secondary_color=GL_SECONDARY_COLOR_ARRAY,
    cap_texture_coord=GL_TEXTURE_COORD_ARRAY,
    cap_vertex=GL_VERTEX_ARRAY,

    cap_last=65535
};

enum l3d_bufferusage
{
    usage_stream_draw= GL_STREAM_DRAW,
    usage_stream_read=GL_STREAM_READ,
    usage_stream_copy=GL_STREAM_COPY,
    usage_static_draw=GL_STATIC_DRAW,
    usage_static_read=GL_STATIC_READ,
    usage_static_copy=GL_STATIC_COPY,
    usage_dynamic_draw=GL_DYNAMIC_DRAW,
    usage_dynamic_read=GL_DYNAMIC_READ,
    usage_dynamic_copy= GL_DYNAMIC_COPY,

    usage_last=65535


};
enum l3d_access
{
    access_read_only=GL_READ_ONLY,
    access_write_only=GL_WRITE_ONLY,
    access_read_write=GL_READ_WRITE,

    acess_last=65535

};

enum l3d_mode_draw
{
    draw_points=GL_POINTS,
    draw_line_strip=GL_LINE_STRIP,
    draw_line_loop=GL_LINE_LOOP,
    draw_lines=GL_LINES,
    draw_triangles_strip=GL_TRIANGLE_STRIP,
    draw_triangles_fan=GL_TRIANGLE_FAN,
    draw_triangles=GL_TRIANGLES,
    draw_quad_strip=GL_QUAD_STRIP,
    draw_quads=GL_QUADS,
    draw_poligon= GL_POLYGON ,

    draw_last=65535


};
enum l3d_shader_type
{
    vertex_shader=GL_VERTEX_SHADER,
    fragment_shader=GL_FRAGMENT_SHADER,
    shader_null=65535
};

#define l3d_idnull -1
#define l3d_null NULL
#define l3d_link 10000
//typedef 0 l3d_notfound;


#endif // L3D_INCLUDE_H
