#ifndef L3D_BLEND_H
#define L3D_BLEND_H
#include <QOpenGLFunctions>

#include "l3d_include.h"

namespace l3d
{
namespace mesh
{
enum blendFunction
{
/*
GL_ZERO
GL_ONE
GL_SRC_COLOR
GL_ONE_MINUS_SRC_COLOR
GL_DST_COLOR
GL_ONE_MINUS_DST_COLOR
GL_SRC_ALPHA
GL_ONE_MINUS_SRC_ALPHA
GL_DST_ALPHA
GL_ONE_MINUS_DST_ALPHA
GL_CONSTANT_COLOR
GL_ONE_MINUS_CONSTANT_COLOR
GL_CONSTANT_ALPHA
GL_ONE_MINUS_CONSTANT_ALPHA
GL_SRC_ALPHA_SATURATE
GL_SRC1_COLOR
GL_ONE_MINUS_SRC1_COLOR
GL_SRC1_ALPHA
GL_ONE_MINUS_SRC1_ALPHA
*/
    zero=GL_ZERO,
    one=GL_ONE,
    src_color=GL_SRC_COLOR,
    one_minus_src_color=GL_ONE_MINUS_SRC_COLOR,
    dst_color=GL_DST_COLOR,
    one_minus_dst_color=GL_ONE_MINUS_DST_COLOR,
    src_alpha=GL_SRC_ALPHA,
    one_minus_src_alpha=GL_ONE_MINUS_SRC_ALPHA,
    dst_alpha=GL_DST_ALPHA,
    one_minus_dst_alpha=GL_ONE_MINUS_DST_ALPHA,
    constant_color=GL_CONSTANT_COLOR,
    one_minus_constant_color=GL_ONE_MINUS_CONSTANT_COLOR,
    constant_alpha=GL_CONSTANT_ALPHA,
    one_minus_constant_alpha=GL_ONE_MINUS_CONSTANT_ALPHA,
    src_alpha_saturate=GL_SRC_ALPHA_SATURATE,
    src1_color=GL_SRC1_COLOR,
    one_minus_src1_color=GL_ONE_MINUS_SRC1_COLOR,
    src1_alpha=GL_SRC1_ALPHA,
    one_minus_src1_alpha=GL_ONE_MINUS_SRC1_ALPHA,

    last=123456789
};

class l3d_blend
{
private:

    blendFunction _sfactor,_dfactor;

    l3d_bool _iscull;
    l3d_bool _blend;
public:
    l3d_blend();
    l3d_blend(blendFunction _f);

    l3d_bool blend();
    void blend(l3d_bool _b);
    void use();
    void use_edit();
    void use(l3d_bool _cull);
    void use(blendFunction _f,l3d_bool _cull);
    void set(blendFunction _f,l3d_bool _cull);

    void set_factor(blendFunction _s,blendFunction _d);
};

}
}


#endif // L3D_BLEND_H
