#include <QDebug>
#include <QFile>
#include "l3d_shader.h"

l3d_shader::l3d_shader(l3d_const_string _source, l3d_shader_type _type)
{
   _id=0;
   this->_source=_source;
   this->_type=_type;
   create();
}

l3d_shader::l3d_shader(l3d_const_string _source)
{
    _id=0;
    this->_source=_source;
}
l3d_shader::l3d_shader()
{

}
void l3d_shader::load(l3d_const_string _filename,l3d_shader_type _type)
{
    load(_filename);
    this->_type=_type;
    create();

}

void l3d_shader::load(l3d_const_string _filename)
{
    QString fileName=QString(_filename);
    QFile inputFile(fileName);
    QStringList appshared;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          appshared << line;
       }
       inputFile.close();
    }
    QString appsource=appshared.join("");
    _source=appsource.toStdString().c_str();
}

int l3d_shader::getId()
{
    return _id;
}
void l3d_shader::create()
{
   _id = glCreateShader(_type);
   glShaderSource(_id, 1, &_source, NULL);
   glCompileShader(_id);
   glGetShaderiv(_id, GL_COMPILE_STATUS, &_success);
}
l3d_bool l3d_shader::success()
{
    l3d_char infoLog[512];
    if (!_success)
    {
       glGetShaderInfoLog(_id, 512, NULL, infoLog);
       qDebug() <<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
       return (false);

    }
    return (true);
}
void l3d_shader::set_source(l3d_const_string _source)
{
    this->_source=_source;
}

