#include "l3d_modifier_draw.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_material.h"
#include "mesh/l3d_mesh.h"

#include "l3d_modifier_save.h"

using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;
using namespace l3d::material;



l3d_modifier_save::l3d_modifier_save()
{
}


void l3d_modifier_save::write_mesh(pl3d_mesh_struct _mesh, string _filename)
{

    std::ofstream * fsave= new std::ofstream();
    fsave->open(_filename.c_str(),ios::binary);



    if(fsave->is_open())
    {
        write_header(hmesh,fsave);

        _mesh->serialize(fsave);

    }

    fsave->close();
}

ReadError l3d_modifier_save::read_mesh(pl3d_mesh_struct _mesh, string _filename)
{
    ReadError _error=read_noerror;

    std::ifstream * fload= new std::ifstream();
    fload->open(_filename.c_str(),ios::binary);

    HeaderType _header=read_header(fload);



    if(_header==hclose)
    {

        return(read_header_name);

    }
    if( _header==hlast)
    {
        return(read_header_element);
    }

    if(fload->is_open() && _header==hmesh)
    {

        _mesh->serialize(fload);
        _mesh->_vbo=l3d_null;

    }

    fload->close();

    return(_error);
}
void l3d_modifier_save::write_header(HeaderType _head,std::ofstream * _f)
{
    //save the hesder of the file of program

    char * nameapp= new char[7];
    char * type= new char[50];
    l3d_uint v1,v2,v3;

    strcpy(nameapp,"LOOK3D");

    v1=0;
    v2=0;
    v3=3;



    //definisce il tipo di elemento del file

    switch(_head)
    {

    case hmesh:

        strcpy(type,"MESH");

        break;

    case hgroup:

        strcpy(type,"GROUP");

        break;
    }

    //  nome del programma e versione dell'applicazione

    _f->write((char*)nameapp ,sizeof(char)*7);
    _f->write((char*)&v1 ,sizeof(l3d_uint));
    _f->write((char*)&v2 ,sizeof(l3d_uint));
    _f->write((char*)&v3 ,sizeof(l3d_uint));

    _f->write((char*)type ,sizeof(char)*50);





}

HeaderType l3d_modifier_save::read_header( std::ifstream * _f)
{
    //save the hesder of the file of program
    char * nameapp= new char[7];
    char * type= new char[50];
    l3d_uint v1,v2,v3;




    //  nome del programma e versione dell'applicazione

    _f->read((char*)nameapp ,sizeof(char)*7);
    _f->read((char*)&v1 ,sizeof(l3d_uint));
    _f->read((char*)&v2 ,sizeof(l3d_uint));
    _f->read((char*)&v3 ,sizeof(l3d_uint));


    //controlla se nameapp e v1,v2,v3 corrispondono al file del programma
    if(!strcmp(nameapp,"LOOK3D")  && v1==0 && v2==0 && v3==3)
    {//coincidono
        _f->read((char*)type ,sizeof(char)*50);//legge il tipo

        if(!strcmp(type,"MESH"))//type coincide con un tipo di file
            return(hmesh);
        if(!strcmp(type,"GROUP"))
            return(hgroup);
        if(!strcmp(type,"SCENE"))
            return(hscene);
        if(!strcmp(type,"ANIMATION"))
            return(hanimation);

        _f->close();
        return(hlast);



    }
    else//non coincidono
    {
        _f->close();//chiude il file
        return(hclose);

    }








}
