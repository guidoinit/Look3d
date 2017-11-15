#ifndef L3D_SHADERPROGRAM_H
#define L3D_SHADERPROGRAM_H

#include <QOpenGLFunctions>
#include "l3d_shader.h"
class l3d_shaderprogram:protected QOpenGLFunctions
{
private:
    int _id;
    l3d_shader * _fragment_shader;
    l3d_shader * _vertex_shader;
public:
    int getId();
    void create();
    l3d_shaderprogram();
};

#endif // L3D_SHADERPROGRAM_H
