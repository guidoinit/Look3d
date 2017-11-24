#ifndef L3D_SHADERPROGRAM_H
#define L3D_SHADERPROGRAM_H

#include <QOpenGLFunctions>
#include "l3d_shader.h"
class l3d_shaderprogram:protected QOpenGLFunctions
{
private:
    int _id;
    l3d_bool _success;
    l3d_shader * _fragment_shader;
    l3d_shader * _vertex_shader;
public:
    int getId();
    void create();
    void create(l3d_const_string _filename_vertex,l3d_const_string _filename_fragment);
    void attach_vertex_shader(l3d_shader * _vertex_shader);
    void attach_fragment_shader(l3d_shader * _fragment_shader);
    void success();
    l3d_bool is_success();
    l3d_shaderprogram();
    void use();
};

#endif // L3D_SHADERPROGRAM_H
