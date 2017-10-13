#include "shadervariable.h"


shadervariable::shadervariable(void)
{
        _name=NULL;
        _val=NULL;
        _location=-1;
        rmat=-1;
        cmat=-1;
}

shadervariable::shadervariable(char *name,unsigned int var_size)
{
        _name=name;
        _val=malloc(sizeof(var_size));
        _location=-1;
        rmat=-1;
        cmat=-1;
}

shadervariable::shadervariable(char *name,ShaderVariableType type)
{
        _name=name;
        _type=type;
        switch(type)
        {
        case ShaderVariableType::vinteger:
                _val=malloc(sizeof(int));
                break;
        case ShaderVariableType::vchar:
                _val=malloc(sizeof(char));
                break;
        case ShaderVariableType::vfloat:
                _val=malloc(sizeof(float));
        break;
        case ShaderVariableType::vvector2:
                _val=malloc(sizeof(float)*2);
                break;
        case ShaderVariableType::vvector3:
                _val=malloc(sizeof(float)*3);
                break;
        case ShaderVariableType::vvector4:
                _val=malloc(sizeof(float)*4);
                break;


        }

        rmat=-1;
        cmat=-1;
}

shadervariable::~shadervariable(void)
{
}

void shadervariable::set_vectorn(int nv1,int nv2)
{
        _nvector1=nv1;
        _nvector2=nv2;

}
void shadervariable::Update()
{
        GLint pval;
        GLfloat fval;
        GLfloat *fval_v;
        float *pfval=NULL;
        if(_location==-1)
                return;
        switch(_type)
        {
        case ShaderVariableType::vinteger:
                pval=(GLint)_val;
                glUniform1i(_location, pval);

                break;
        case ShaderVariableType::vchar:
                pval=(GLint)_val;
                //glUniform1s(_location, pval);
                //to-do
                break;
        case ShaderVariableType::vvectornf:
                pfval=(float *)malloc(sizeof(float)*_nvector1*_nvector2);

                strncpy((char*)pfval,(char*)_val,sizeof(float)*_nvector1*_nvector2);

                fval_v=(GLfloat *)pfval;

                glUniform4fv(_location,_nvector1,fval_v);

                break;
        case ShaderVariableType::vfloat:
        //	float pf=(float )_val;
                //=(GLfloat)_val;
                pfval=(float *)malloc(sizeof(float));
                if(_bminmax)
                {
                        float *appval=(float*)_val;
                        float *step=(float*)_step;

                        *appval+=*step;

                        if((float)*appval > *(float*)_max)
                                *appval=*(float*)_min;
                        if((float)*appval < *(float*)_min)
                                *appval=*(float*)_max;

                }
                pfval=(float*)_val;

                fval=(GLfloat)*pfval;

                glUniform1f(_location, fval);

                //free(pfval);

                pfval=NULL;

                //to-do
        break;
        case ShaderVariableType::vvector2:
                //GLfloat pval[2]=(GLfloat)*_val;
                glUniform2f(_location, fval , fval);
                //to-do
                break;
        case ShaderVariableType::vvector3:
                //to-do
                glUniform3f( _location, fval , fval , fval );
                break;
        case ShaderVariableType::vvector4:
                //to-do

                glUniform4f( _location, fval , fval , fval , fval );

                break;


        }


}

void shadervariable::set_location(GLuint prog_id)
{
        _location=glGetUniformLocation(prog_id,(GLchar*) _name );
}

void shadervariable::set_value(void * val)
{
        _val = val;
}
void *shadervariable::get_value()
{
        return _val;
}
void shadervariable::add_value(void * value)
{

}

void shadervariable::set_minmax(void * min, void *max,void *step)
{
        float * appf;
        _min=(void*)malloc(sizeof(float));
        appf=(float*)_min;
        *appf=*(float*)min;

        _max=(void*)malloc(sizeof(float));
        appf=(float*)_max;
        *appf=*(float*)max;


        _step=(void*)malloc(sizeof(float));

        appf=(float*)_step;
        *appf=*(float*)step;


        _bminmax=true;
}
