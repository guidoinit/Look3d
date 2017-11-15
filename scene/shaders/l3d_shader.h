#ifndef L3D_SHADER_H
#define L3D_SHADER_H
#include "l3d_include.h"
#include <QOpenGLFunctions>
class l3d_shader:protected QOpenGLFunctions
{
private:
    int _id;
    l3d_const_string _source;
    int _success;
    l3d_shader_type _type;
public:
    l3d_shader(l3d_const_string _source,l3d_shader_type _type);
    l3d_shader(l3d_const_string _source);
    void load(l3d_const_string _filename);
    void load(l3d_const_string _filename,l3d_shader_type _type);
    l3d_shader();
    int getId();
    void create();
    void set_source(l3d_const_string _source);
    l3d_bool success();
};

#endif // L3D_SHADER_H
