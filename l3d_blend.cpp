#define GLEW_STATIC
#include <GL/glew.h>


#include "l3d_blend.h"
using namespace l3d::mesh;


l3d_blend::l3d_blend()
{
    _sfactor=one;
    _dfactor=zero;
    _iscull=false;
    _blend=true;
}
void l3d_blend::set_factor(blendFunction _s, blendFunction _d)
{
    _sfactor=_s;
    _dfactor=_d;
}

l3d_bool l3d_blend::blend()
{
    return(_blend);
}

void l3d_blend::blend(l3d_bool _b)
{
    _blend=_b;
}

l3d_blend::l3d_blend(blendFunction _f)
{
    _dfactor=_f;
}
void l3d_blend::set(blendFunction _f,l3d_bool _cull)
{
    _dfactor=_f;
    _iscull=_cull;

}

void l3d_blend::use(blendFunction _f,l3d_bool _cull)
{
    _dfactor=_f;
    _iscull=_cull;

    use();

}
void l3d_blend::use(l3d_bool _cull)
{
    _iscull=_cull;

    use();

}
void l3d_blend::use_edit()
{


    glEnable(GL_BLEND);

    //if(_iscull)
        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);
    //else
    //    glDisable(GL_CULL_FACE);

    glBlendFunc(src_color,dst_color);

}
void l3d_blend::use()
{

    if(!_blend)
        return;
    glEnable(GL_BLEND);

    if(_iscull)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    glBlendFunc(_sfactor,_dfactor);

}
