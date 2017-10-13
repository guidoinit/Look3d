#include "shadervariable.h"
#include "shader.h"
#include "shaderprogram.h"

shaderprogram::shaderprogram()
{
}
shaderprogram::shaderprogram(void)
{
        m_idprogram=-1;
        //create();
}


shaderprogram::~shaderprogram(void)
{
        //glDeleteProgram(m_idprogram);
}

void shaderprogram::init()
{



        GLfloat waveval= 0.0F;
        GLfloat min=0.0F,max=10.0F,step=0.1F;
        add_variable_min_max("waveval",ShaderVariableType::vfloat,(void *)&waveval,(void*)&min,(void*)&max,(void*)&step);
//	add_variable("waveWidth",ShaderVariableType::vfloat,(void *)&waveWidth);
//	add_variable("waveHeight",ShaderVariableType::vfloat,(void *)&waveHeight);


//	loc1 = glGetUniformLocation(m_idprogram,"specIntensity");
//	glUniform1f(loc1,specIntensity);

//	add_variable("specColor",ShaderVariableType::vvector4,(void*)&sc);
//	loc2 = glGetUniformLocation(m_idprogram,);
//	glUniform4fv(loc2,1,sc);
//	glUniform4f(loc2,sc[0],sc[1],sc[2],sc[3]);
//	loc3 = glGetUniformLocation(m_idprogram,"t");
//	glUniform1fv(loc3,2,threshold);
//	add_variable("colors",ShaderVariableType::vvectornf,(void *)&colors);
//	m_variable[2].set_vectorn(3,4);

        for(int iv=0; iv <m_variable.size(); iv++)
                m_variable[iv].Update();


//	loc4 = glGetUniformLocation(m_idprogram,"colors");
//	glUniform4fv(loc4,3,colors);
}

void shaderprogram::pipe()
{
        for(int ix=0; ix < m_variable.size(); ix++)
                m_variable[ix].Update();
}

void shaderprogram::create()
{
        m_idprogram=glCreateProgram();
}

void shaderprogram::link()
{
        glLinkProgram(m_idprogram);
}

void shaderprogram::use()
{
        if(m_idprogram!=-1)
                glUseProgram(m_idprogram);

}
void shaderprogram::unuse()
{
        if(m_idprogram!=-1)
                glUseProgram(0);

}
void shaderprogram::AttachShader(GLuint shader_id)
{
        ASSERT(m_idprogram!=-1);

        glAttachShader(m_idprogram, shader_id);
}

void shaderprogram::add_variable(char *name,ShaderVariableType type,void * val)
{
        shadervariable nvar(name,type);

        nvar.set_location(m_idprogram);
        nvar.set_value(val);

        m_variable.push_back(nvar);

}

void shaderprogram::add_variable_min_max(char *name,ShaderVariableType type,void * val,void* min,void* max,void* step)
{
        shadervariable nvar(name,type);

        nvar.set_location(m_idprogram);
        nvar.set_value(val);
        nvar.set_minmax(min,max,step);

        m_variable.push_back(nvar);

}

void shaderprogram::update_variables()
{
        if(m_variable.size()==0)
                return;

        for(int iv=0; iv < m_variable.size(); iv++)
                m_variable[iv].Update();
}

void shaderprogram::add_value(int vindex,void *value)
{
        if(vindex >=0 && vindex < m_variable.size())
        {
                m_variable[vindex].set_value(value);
                m_variable[vindex].Update();

        }
}
