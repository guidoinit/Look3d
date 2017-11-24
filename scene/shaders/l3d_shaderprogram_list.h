#ifndef L3D_SHADERPROGRAM_LIST_H
#define L3D_SHADERPROGRAM_LIST_H
#include "l3d_shader.h"
#include "l3d_shaderprogram.h"

namespace l3d
{



    typedef struct _l3d_progrma_item{
        _l3d_progrma_item * _next;
        _l3d_progrma_item * _prev;
        l3d_shaderprogram  * _program;
        l3d_string _name;

        void init()
        {
            _next=_prev=l3d_null;
        }

        void setName(l3d_string _n)
        {
            _name=_n;
        }
        l3d_shaderprogram  * getprogram()
        {
            return _program;
        }
        void setprogram(l3d_shaderprogram  * _p)
        {
            _program=_p;
        }
        void use()
        {
            if(_program)
            {
                _program->use();
            }
        }

    }l3d_program_item,*pl3d_program_item;
    class l3d_shaderprogram_list
    {
    private:
        pl3d_program_item _first;
        pl3d_program_item _last;
        l3d_uint _size;
    public:
        l3d_shaderprogram_list();
        void add(pl3d_program_item _e);
        l3d_uint size();
        pl3d_program_item find(l3d_uint _s);
        pl3d_program_item find(l3d_string _name);
        void use(l3d_string _name);
        void use(l3d_uint _s);
    };


}





#endif // L3D_SHADERPROGRAM_LIST_H
