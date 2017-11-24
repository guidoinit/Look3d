#include <QDebug>
#include "l3d_shaderprogram.h"

l3d_shaderprogram::l3d_shaderprogram()
{
    _vertex_shader=l3d_null;
    _fragment_shader=l3d_null;
    _success=false;
}
int l3d_shaderprogram::getId()
{
    return _id;
}
void l3d_shaderprogram::create(l3d_const_string _filename_vertex, l3d_const_string _filename_fragment)
{
    _id=glCreateProgram();
    if(!_vertex_shader)
    {
        _vertex_shader= new l3d_shader();
        _vertex_shader->load(_filename_vertex,l3d_shader_type::vertex_shader);
        if(_vertex_shader->success())
        {
            glAttachShader(_id,_vertex_shader->getId());
        }
    }
    if(!_fragment_shader)
    {
        _fragment_shader= new l3d_shader();
        _fragment_shader->load(_filename_fragment,l3d_shader_type::fragment_shader);
        if(_fragment_shader->success())
        {
            glAttachShader(_id,_fragment_shader->getId());
        }
    }
    if(!_vertex_shader->success() || !_fragment_shader->success())
        _success=false;
    else
    {
        glLinkProgram(_id);
        success();
        glDeleteShader(_vertex_shader->getId());
        glDeleteShader(_fragment_shader->getId());
    }

}

void l3d_shaderprogram::create()
{

    _id=glCreateProgram();
    if(_vertex_shader)
        glAttachShader(_id,_vertex_shader->getId());
    if(_fragment_shader)
        glAttachShader(_id,_fragment_shader->getId());
    if(!_vertex_shader || !_fragment_shader)
        _success=false;
    else
    {
        glLinkProgram(_id);
        success();
    }
}
l3d_bool l3d_shaderprogram::is_success()
{
    return (_success);
}

void l3d_shaderprogram::success()
{
    int success;
    char infoLog[512];
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success)
    {
        _success=false;
        glGetProgramInfoLog(_id, 512, NULL, infoLog);
        qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog ;
    }
    else
    {
        _success=true;
    }
}

void l3d_shaderprogram::attach_vertex_shader(l3d_shader *_vertex_shader)
{
    this->_vertex_shader=_vertex_shader;
}

void l3d_shaderprogram::attach_fragment_shader(l3d_shader *_fragment_shader)
{
    this->_fragment_shader=_fragment_shader;
}
void l3d_shaderprogram::use()
{
    glUseProgram(_id);
}
