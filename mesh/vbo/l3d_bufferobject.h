#ifndef L3D_BUFFEROBJECT_H
#define L3D_BUFFEROBJECT_H
#define GLEW_STATIC

#include <GL/glew.h>
#include <QGLWidget>

#include "l3d_include.h"

namespace l3d
{
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


    class l3d_bufferobject
    {
    private:
        l3d_void buffer;
        l3d_uint lenght_element;
        l3d_uint lenght_buffer;
        l3d_uint idb;
        l3d_buffertype target;
        l3d_bufferusage usage;
        l3d_access access;
    public:
        l3d_bufferobject();
        void setsize(l3d_uint size);
        void setlenght(l3d_uint type);
        void setbuffer(l3d_void);
        void set_target(l3d_buffertype);
        void set_access(l3d_access);
        l3d_void getbuffer();
        l3d_void getbufferobject(l3d_access);
        void unmapbuffer();
        void create();
        void create_sub();
        void create(l3d_buffertype,l3d_bufferusage);
        void create_sub(l3d_buffertype,l3d_bufferusage);
        l3d_uint size();
        l3d_uint getid();
        void bind();
        void deletebuffer();
        void draw(l3d_mode_draw dm);

    };

}


#endif // L3D_BUFFEROBJECT_H
