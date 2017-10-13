#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <vector>
#include "shadervariable.h"

class shaderprogram
{

private:
        GLuint m_idprogram;
        std::vector<shadervariable> m_variable;
public:
        shaderprogram(void);
        ~shaderprogram(void);

        void create();
        void link();
        void use();
        void unuse();
        void AttachShader(GLuint );
        void init();
        void pipe();
        void add_value(int vindex,void * val);
        void add_variable(char *name,ShaderVariableType type,void * val);
        void add_variable_min_max(char *name,ShaderVariableType type,void * val,void *min,void *max,void *step);
        void update_variables();
        shaderprogram (const shaderprogram& sp)
        {
                m_idprogram=sp.m_idprogram;
        }
};

#endif // SHADERPROGRAM_H
