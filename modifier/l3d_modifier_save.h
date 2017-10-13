#ifndef L3D_MODIFIER_SAVE_H
#define L3D_MODIFIER_SAVE_H
#include "mesh/l3d_mesh.h"
#include "mesh/l3d_vertex.h"
#include "l3d_include.h"

using namespace l3d;
using namespace l3d::mesh;




namespace l3d
{

using namespace vertex3f;
using namespace edge;
using namespace face3;
using namespace face4;
using namespace mesh;


    namespace modifier
    {
        enum ReadError
        {
            read_noerror=0,
            read_header_name=1,
            read_header_version=2,
            read_header_element=3,

            read_last=1000
        };

        enum HeaderType
        {
            hmesh=0,
            hgroup=1,
            hscene=2,
            hanimation=3,

            hclose=20,

            hlast=21//last header
        };

        class l3d_modifier_save
        {
        public:
            l3d_modifier_save();
            void write_header(HeaderType _head,std::ofstream * _file);
            HeaderType read_header(std::ifstream * _file);

            void write_mesh(pl3d_mesh_struct _mesh,std::string _filename);
            ReadError read_mesh(pl3d_mesh_struct _mesh,std::string _filename);

        };
    }
}

#endif // L3D_MODIFIER_SAVE_H
