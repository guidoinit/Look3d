#include "l3d_shaderprogram.h"

l3d_shaderprogram::l3d_shaderprogram()
{

}
int l3d_shaderprogram::getId()
{
    return _id;
}

void l3d_shaderprogram::create()
{
    _id=glCreateProgram();
}
