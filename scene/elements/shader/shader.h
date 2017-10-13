#ifndef SCHADER_H
#define SCHADER_H

namespace SHADER
{
enum ShaderType
{
        nullo=-1,
        svertex=GL_VERTEX_SHADER,
        fragment=GL_FRAGMENT_SHADER
};
}
class shader
{
private:
        SHADER::ShaderType m_type;
        string m_codeshader;
        GLuint m_idshader;

public:
        char * m_source;
        shader();
        shader(SHADER::ShaderType);
        virtual ~shader();
        void create();
        void compile();
        void compile(char *);
        GLuint getid();
        void textFileRead(char *);
        static char *textFileRead2(char *);
};


#endif // SCHADER_H
