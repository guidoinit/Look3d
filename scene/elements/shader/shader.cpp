#include "schader.h"


shader::shader()
{
        m_type=ShaderType::null;
}

shader::shader(ShaderType _sht)
{
        m_type=_sht;
}

shader::~shader()
{
        glDeleteShader(m_idshader);
}

void shader::create()
{
        ASSERT(m_type==ShaderType::svertex || m_type==ShaderType::fragment);

        m_idshader=glCreateShader(m_type);
}
void shader::compile()
{
        ASSERT(m_source!=NULL);
        const char *ps=m_source;
        glShaderSource(m_idshader, 1,&ps, NULL);
        glCompileShader(m_idshader);
}

void shader::compile(char *src)
{

        glShaderSource(m_idshader, 1,(const char **)src, NULL);
        glCompileShader(m_idshader);

        free(src);
}
void shader::textFileRead(char *fn) {


        FILE *fp;
        char *content = NULL;

        int count=0;

        if (fn != NULL) {
                fp = fopen(fn,"rt");

                if (fp != NULL) {

      fseek(fp, 0, SEEK_END);
      count = ftell(fp);
      rewind(fp);

                        if (count > 0) {
                                m_source = (char *)malloc(sizeof(char) * (count+1));
                                count = fread(m_source,sizeof(char),count,fp);
                                m_source[count] = '\0';
                        }
                        fclose(fp);
                }
        }

}
char * shader::textFileRead2(char *fn) {


        FILE *fp;
        char *content = NULL;

        int count=0;

        if (fn != NULL) {
                fp = fopen(fn,"rt");

                if (fp != NULL) {

      fseek(fp, 0, SEEK_END);
      count = ftell(fp);
      rewind(fp);

                        if (count > 0) {
                                content = (char *)malloc(sizeof(char) * (count+1));
                                count = fread(content,sizeof(char),count,fp);
                                content[count] = '\0';
                        }
                        fclose(fp);
                }
        }
        return content;
}
GLuint shader::getid()
{
        return m_idshader;
}
// shader member functions
