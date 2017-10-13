#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "l3d_include.h"
#include "color.h"
#include "material.h"

#include "vertex.h"
#include "l3d_vertex.h"
#include "./scene/elements/telecamera.h"

#include "poligon.h"
#include "poligon4.h"

#include "variable.h"
#include "istruction.h"

#include "action.h"

#include "function.h"
#include "module.h"

#include "./mesh/texture/texture.h"
#include "line.h"
#include "l3d_line.h"

//#include "shader.h"
//#include "shaderprogram.h"


#include "scene/lib/lib3ds-20080909/include/lib3ds.h"
#include "mesh/vbo/objectvbo.h"
#include "object3d.h"

#include <map>


using namespace std;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define STARTV 1000
//using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
GLuint v,f,f2,p;

object3d::object3d ( const object3d &obj )
{
    m_bselected=obj.m_bselected;
    m_idgroup=obj.m_idgroup;
    m_nType=obj.m_nType;
    m_angolo[0]=obj.m_angolo[0];
    m_angolo[1]=obj.m_angolo[1];
    m_angolo[2]=obj.m_angolo[2];
    m_Scale[0]=obj.m_Scale[0];
    m_Scale[1]=obj.m_Scale[1];
    m_Scale[2]=obj.m_Scale[2];
    m_ScaleVertex[0]=obj.m_ScaleVertex[0];
    m_ScaleVertex[1]=obj.m_ScaleVertex[1];
    m_ScaleVertex[2]=obj.m_ScaleVertex[2];
    m_bModificato=obj.m_bModificato;
    m_IDO=obj.m_IDO;
    m_binvert=obj.m_binvert;


    m_nAction=obj.m_nAction;
    m_nGruppoID=obj.m_nGruppoID;
    inmove=obj.inmove;
    m_bsmooth=obj.m_bsmooth;
    m_bhide=obj.m_bhide;

    m_maxx=obj.m_maxx;
    m_maxy=obj.m_maxy;
    m_maxz=obj.m_maxz;

    name=obj.name;
    subname=obj.subname;
    m_name=obj.m_name;
    m_Worldpos=obj.m_Worldpos;
    world_pos=obj.world_pos;

    world_pos_group=obj.world_pos_group;
    scale_group=obj.scale_group;
    rotate_group=obj.rotate_group;

    world_pos_app=obj.world_pos_app;
    world_vert=obj.world_vert;
    old_world_pos=obj.old_world_pos;
    //m_shaderprogram=NULL;

    m_vbo=obj.m_vbo;
    modulo=obj.modulo;

    smodulo.clear();
    for(int ix=0; ix < obj.smodulo.size(); ix++)
        smodulo.push_back(obj.smodulo[ix]);
    //impostare il materiale principale

    //free(m_material);


    m_material_vector.clear();

    for(int ix=0; ix < obj.m_material_vector.size(); ix++)
        m_material_vector.push_back(obj.m_material_vector[ix]);

    m_action.clear();
    for(int ix=0; ix < obj.m_action.size(); ix++)
        m_action.push_back(obj.m_action[ix]);

    m_tex.clear();
    for(int ix=0; ix < obj.m_tex.size(); ix++)
        m_tex.push_back(obj.m_tex[ix]);
    m_itex=obj.m_itex;

    //copia i vertici
    local_vertex.clear();

    for(int ix=0; ix < obj.local_vertex.size(); ix++)
        local_vertex.push_back(obj.local_vertex[ix]);
    //copia i poligoni a 3
    m_poly.clear();
    for(int ix=0; ix< obj.m_poly.size(); ix++)
        m_poly.push_back(obj.m_poly[ix]);

    m_poly3.clear();
    for(int ix=0; ix< obj.m_poly3.size(); ix++)
        m_poly3.push_back(obj.m_poly3[ix]);

    m_poly4.clear();
    for(int ix=0; ix< obj.m_poly4.size(); ix++)
        m_poly4.push_back(obj.m_poly4[ix]);

    m_line.clear();
    for(int ix=0; ix < obj.m_line.size(); ix++)
        m_line.push_back(obj.m_line[ix]);

    m_ivgroup=obj.m_ivgroup;
    for(int ix=0; ix < obj.m_vgroup.size(); ix++)
        m_vgroup.push_back(obj.m_vgroup[ix]);

    _vertex=obj._vertex;




}
object3d& object3d::operator=( const object3d &obj )
{

    m_bselected=obj.m_bselected;
    m_idgroup=obj.m_idgroup;
    m_nType=obj.m_nType;
    m_angolo[0]=obj.m_angolo[0];
    m_angolo[1]=obj.m_angolo[1];
    m_angolo[2]=obj.m_angolo[2];
    m_Scale[0]=obj.m_Scale[0];
    m_Scale[1]=obj.m_Scale[1];
    m_Scale[2]=obj.m_Scale[2];
    m_ScaleVertex[0]=obj.m_ScaleVertex[0];
    m_ScaleVertex[1]=obj.m_ScaleVertex[1];
    m_ScaleVertex[2]=obj.m_ScaleVertex[2];
    m_bModificato=obj.m_bModificato;
    m_IDO=obj.m_IDO;

    m_nAction=obj.m_nAction;
    m_nGruppoID=obj.m_nGruppoID;
    inmove=obj.inmove;
    m_bsmooth=obj.m_bsmooth;
    m_bhide=obj.m_bhide;

    m_maxx=obj.m_maxx;
    m_maxy=obj.m_maxy;
    m_maxz=obj.m_maxz;

    name=obj.name;
    subname=obj.subname;
    m_name=obj.m_name;
    m_Worldpos=obj.m_Worldpos;
    world_pos=obj.world_pos;

    world_pos_group=obj.world_pos_group;
    scale_group=obj.scale_group;
    rotate_group=obj.rotate_group;

    world_pos_app=obj.world_pos_app;
    world_vert=obj.world_vert;
    old_world_pos=obj.old_world_pos;
    //m_shaderprogram=NULL;

    m_vbo=obj.m_vbo;

    modulo=obj.modulo;

    smodulo.clear();
    for(int ix=0; ix < obj.smodulo.size(); ix++)
        smodulo.push_back(obj.smodulo[ix]);
    //impostare il materiale principale


    m_material_vector.clear();

    for(int ix=0; ix < obj.m_material_vector.size(); ix++)
        m_material_vector.push_back(obj.m_material_vector[ix]);

    m_action.clear();
    for(int ix=0; ix < obj.m_action.size(); ix++)
        m_action.push_back(obj.m_action[ix]);

    m_tex.clear();
    for(int ix=0; ix < obj.m_tex.size(); ix++)
        m_tex.push_back(obj.m_tex[ix]);


    //copia i vertici
    local_vertex.clear();

    for(int ix=0; ix < obj.local_vertex.size(); ix++)
        local_vertex.push_back(obj.local_vertex[ix]);
    //copia i poligoni a 3
    m_poly.clear();
    for(int ix=0; ix< obj.m_poly.size(); ix++)
        m_poly.push_back(obj.m_poly[ix]);

    m_poly3.clear();
    for(int ix=0; ix< obj.m_poly3.size(); ix++)
        m_poly3.push_back(obj.m_poly3[ix]);

    m_poly4.clear();
    for(int ix=0; ix< obj.m_poly4.size(); ix++)
        m_poly4.push_back(obj.m_poly4[ix]);

    m_line.clear();
    for(int ix=0; ix < obj.m_line.size(); ix++)
        m_line.push_back(obj.m_line[ix]);

    m_ivgroup=obj.m_ivgroup;
    for(int ix=0; ix < obj.m_vgroup.size(); ix++)
        m_vgroup.push_back(obj.m_vgroup[ix]);

    _vertex=obj._vertex;

    return *this;
}
object3d::object3d( Lib3dsMesh*  _mesh)
{
    m_bselected=FALSE;

    m_idgroup=-1;
    scale_group.SetVertex(1.0F,1.0F,1.0F);
    rotate_group.SetVertex(0.0F,0.0F,0.0F);

    m_nType=0;
    m_angolo[0]=0.0;
    m_angolo[1]=0.0;
    m_angolo[2]=0.0;
    m_Scale[0]=1.0;
    m_Scale[1]=1.0;
    m_Scale[2]=1.0;
    m_ScaleVertex[0]=1.0;
    m_ScaleVertex[1]=1.0;
    m_ScaleVertex[2]=1.0;
    m_bModificato=false;
    m_IDO=-1;
    m_fMaterial[0]=0.5F;
    m_fMaterial[1]=0.5F;
    m_fMaterial[2]=0.5F;
    m_fMaterial[3]=1.0F;
    m_nAction=0;
    m_nGruppoID=-1;
    inmove=false;
    m_bsmooth=false;
    m_bhide=false;
    m_itex=0;

    m_vbo=NULL;
    //loadtexturenull();
    m_maxx=m_maxy=m_maxz=0.0F;
    //m_shaderprogram=NULL;

    //impostare il materiale principale
    GLfloat val[4]={
        0.5F,0.5F,0.5F,1.0F
    };

    GLfloat val2[4]={
        1.0F,1.0F,1.0F,1.0F
    };

    GLfloat val3[4]={
        0.0F,0.0F,0.0F,1.0F
    };

    material * mat= new material(front,false,val,val2,val,val3,val);

    m_material_vector.push_back(*mat);


    InitModulo();

    /*
    float (*orig_vertices)[3];
    int export_texcos;
    int export_normals;
    int i, j;
    Lib3dsMesh *mesh;

    mesh = lib3ds_file_mesh_for_node(f, (Lib3dsNode*)node);
    if (!mesh || !mesh->vertices) return;

    fprintf(o, "# object %s\n", node->base.name);
    fprintf(o, "g %s\n", node->instance_name[0]? node->instance_name : node->base.name);

    //copia i vertici in origin_vertices
    orig_vertices = (float(*)[3])malloc(sizeof(float) * 3 * mesh->nvertices);
    memcpy(orig_vertices, mesh->vertices, sizeof(float) * 3 * mesh->nvertices);
     {
         float inv_matrix[4][4], M[4][4];
         float tmp[3];
         int i;

         lib3ds_matrix_copy(M, node->base.matrix);
         lib3ds_matrix_translate(M, -node->pivot[0], -node->pivot[1], -node->pivot[2]);
         lib3ds_matrix_copy(inv_matrix, mesh->matrix);
         lib3ds_matrix_inv(inv_matrix);
         lib3ds_matrix_mult(M, M, inv_matrix);

         for (i = 0; i < mesh->nvertices; ++i) {
             lib3ds_vector_transform(tmp, M, mesh->vertices[i]);
             lib3ds_vector_copy(mesh->vertices[i], tmp);
         }
     }

    export_texcos = (mesh->texcos != 0);
    export_normals = (mesh->faces != 0);

    for (i = 0; i < mesh->nvertices; ++i) {
        fprintf(o, "v %f %f %f\n", mesh->vertices[i][0],
                                   mesh->vertices[i][1],
                                   mesh->vertices[i][2]);
    }
    fprintf(o, "# %d vertices\n", mesh->nvertices);

    if (export_texcos) {
        for (i = 0; i < mesh->nvertices; ++i) {
            fprintf(o, "vt %f %f\n", mesh->texcos[i][0],
                                     mesh->texcos[i][1]);
        }
        fprintf(o, "# %d texture vertices\n", mesh->nvertices);
    }

    if (export_normals) {
        float (*normals)[3] = (float(*)[3])malloc(sizeof(float) * 9 * mesh->nfaces);
        lib3ds_mesh_calculate_vertex_normals(mesh, normals);
        for (i = 0; i < 3 * mesh->nfaces; ++i) {
            fprintf(o, "vn %f %f %f\n", normals[i][0],
                                        normals[i][1],
                                        normals[i][2]);
        }
        free(normals);
        fprintf(o, "# %d normals\n", 3 * mesh->nfaces);
    }

    {
        int mat_index = -1;
        for (i = 0; i < mesh->nfaces; ++i) {
            if (mat_index != mesh->faces[i].material) {
                mat_index = mesh->faces[i].material;
                if (mat_index != -1) {
                    fprintf(o, "usemtl %s\n", f->materials[mat_index]->name);
                }
            }

            fprintf(o, "f ");
            for (j = 0; j < 3; ++j) {
                fprintf(o, "%d", mesh->faces[i].index[j] + max_vertices + 1);
                if (export_texcos) {
                    fprintf(o, "/%d", mesh->faces[i].index[j] + max_texcos + 1);
                } else if (export_normals) {
                    fprintf(o, "/");
                }
                if (export_normals) {
                    fprintf(o, "/%d", 3 * i + j + max_normals + 1);
                }
                if (j < 3) {
                    fprintf(o, " ");
                }
            }
            fprintf(o, "\n");
        }
    }

    max_vertices += mesh->nvertices;
    if (export_texcos)
        max_texcos += mesh->nvertices;
    if (export_normals)
        max_normals += 3 * mesh->nfaces;

    memcpy(mesh->vertices, orig_vertices, sizeof(float) * 3 * mesh->nvertices);
    free(orig_vertices);

    */
    int frame= 0;
    int icount=0;

    float   (*vertices)[3];
    int totalfaces=0;

  //  for(mesh = _model->meshes;mesh != NULL;mesh = mesh->next)
    {
                   // Add the number of faces this mesh has to the total faces
        //totalfaces += _mesh->faces;
    }
    // Allocate memory for our vertices and normals
    //Lib3dsVector * vertices = new Lib3dsVector[totalfaces * 3];
    //Lib3dsVector * normals = new Lib3dsVector[totalfaces * 3];
    Lib3dsMesh *mesh;
    unsigned int FinishedFaces = 0;
    //importo i materiali
    string appname;
    appname.append(_mesh->name);
    name=appname;
    subname="3ds mesh";
    //for(mesh = m_model->meshes;mesh != NULL;mesh = mesh->next)
            {
                    //lib3ds_mesh_calculate_normals(_mesh, &normals[FinishedFaces*3]);
                    // Loop through every face
                    for(unsigned int cur_v = 0; cur_v < _mesh->nvertices;cur_v++)
                    {
                           // Lib3dsFace * face = &_mesh->faceL[cur_face];
                            //for(unsigned int i = 0;i < 3;i++)
                            {
                                local_vertex.push_back(vertex(_mesh->vertices[cur_v][0],_mesh->vertices[cur_v][1],_mesh->vertices[cur_v][2]));

                                //    memcpy(&vertices[FinishedFaces*3 + i], _mesh->pointL[face->points[ i ]].pos, sizeof(Lib3dsVector));
                            }
       //                     FinishedFaces++;
                    }
            }


    //vertices=_model->vertices;
    //add vertex
    /*
    for(int ix=0;ix < _model->nvertices; ix++)
    {
        local_vertex.push_back(vertex(*vertices[0],*vertices[1],*vertices[2]));
        vertices++;
    }*/
    //Lib3dsFace * face=_model->faces;
    for(int ix=0;ix < _mesh->nfaces; ix++)
    {

        AddPoligon3(_mesh->faces[ix].index[0],_mesh->faces[ix].index[2],_mesh->faces[ix].index[1]);

    }


    //RemoveDoubleLines();



}

object3d::object3d( Md2Model * _model)
    : m_nGruppoID(0)
    , m_nAction(0)
{
    m_bselected=FALSE;

    m_idgroup=-1;
    scale_group.SetVertex(1.0F,1.0F,1.0F);
    rotate_group.SetVertex(0.0F,0.0F,0.0F);

    m_nType=0;
    m_angolo[0]=0.0;
    m_angolo[1]=0.0;
    m_angolo[2]=0.0;
    m_Scale[0]=1.0;
    m_Scale[1]=1.0;
    m_Scale[2]=1.0;
    m_ScaleVertex[0]=1.0;
    m_ScaleVertex[1]=1.0;
    m_ScaleVertex[2]=1.0;
    m_bModificato=false;
    m_IDO=-1;
    m_fMaterial[0]=0.5F;
    m_fMaterial[1]=0.5F;
    m_fMaterial[2]=0.5F;
    m_fMaterial[3]=1.0F;
    m_nAction=0;
    m_nGruppoID=-1;
    inmove=false;
    m_bsmooth=false;
    m_bhide=false;
    m_itex=0;

    //loadtexturenull();
    m_maxx=m_maxy=m_maxz=0.0F;
    //m_shaderprogram=NULL;

    //impostare il materiale principale
    GLfloat val[4]={
        0.5F,0.5F,0.5F,1.0F
    };

    GLfloat val2[4]={
        1.0F,1.0F,1.0F,1.0F
    };

    GLfloat val3[4]={
        0.0F,0.0F,0.0F,1.0F
    };

    material * mat= new material(front,false,val,val2,val,val3,val);

    m_material_vector.push_back(*mat);


    InitModulo();

    int frame= 0;
    int icount=0;
    int j = 0,v1=0,v2=2,v3=5,v4=3;
    for (int i = 0; i < _model->getHeader()->num_vertices; ++i)
      {
        // Draw each vertex of this triangle


        //for (int j = 0; j < 3; ++j)
          {
            vertex appv;

            Md2Frame_t *pFrame = _model->getFrame(frame);
            Md2Vertex_t *pVert = &pFrame->verts[i];




            // Compute final texture coords.
            //GLfloat s = static_cast<GLfloat>(pTexCoords->s) / _header.skinwidth;
            //GLfloat t = static_cast<GLfloat>(pTexCoords->t) / _header.skinheight;

            //glTexCoord2f (s, 1.0f - t);

            // Send normal vector to OpenGL
            //appuv.set(_model->_kAnorms[pVert->normalIndex][0],_model->_kAnorms[pVert->normalIndex][1]);
            //glNormal3fv (_kAnorms[pVert->normalIndex]);
            appv.SetNormal(_model->_kAnorms[pVert->normalIndex]);
            //m_uv.push_back(appuv);
            // Uncompress vertex position and scale it
            vec3_t v;

            v[0] = (pFrame->scale[0] * pVert->v[0] + pFrame->translate[0]) * _model->getscale();
            v[1] = (pFrame->scale[1] * pVert->v[1] + pFrame->translate[1]) * _model->getscale();
            v[2] = (pFrame->scale[2] * pVert->v[2] + pFrame->translate[2]) * _model->getscale();


            appv.SetVertex(v[0],v[1],v[2]);

            local_vertex.push_back(appv);


          }


        icount+=3;
      }
    for (int i = 0; i < _model->getHeader()->num_tris; ++i)
    {
       // for (int j = 0; j < 3; ++j)
        {

            int index0 = _model->getTrianles()[i].vertex[0];
            int index1 = _model->getTrianles()[i].vertex[1];
            int index2 = _model->getTrianles()[i].vertex[2];
            Md2TexCoord_t *pTexCoords;

            pTexCoords = &_model->_texCoords[_model->getTrianles()[i].st[0]];

            GLfloat s = static_cast<GLfloat>(pTexCoords->s) / _model->getHeader()->skinwidth;
            GLfloat t = static_cast<GLfloat>(pTexCoords->t) / _model->getHeader()->skinheight;

            local_vertex[index0].SetTextXY(s, 1.0f - t);

            pTexCoords = &_model->_texCoords[_model->getTrianles()[i].st[1]];

            s = static_cast<GLfloat>(pTexCoords->s) / _model->getHeader()->skinwidth;
            t = static_cast<GLfloat>(pTexCoords->t) / _model->getHeader()->skinheight;

            local_vertex[index1].SetTextXY(s, 1.0f - t);

            pTexCoords = &_model->_texCoords[_model->getTrianles()[i].st[2]];

            s = static_cast<GLfloat>(pTexCoords->s) / _model->getHeader()->skinwidth;
            t = static_cast<GLfloat>(pTexCoords->t) / _model->getHeader()->skinheight;

            local_vertex[index2].SetTextXY(s, 1.0f - t);

            AddPoligon3(index0,index1,index2);

        }
    }
    texture *_tex=_model->gettexture();
    if(_tex!=NULL)
        m_tex.push_back(*_tex);
    m_itex=0;
}

object3d::object3d()
: m_nGruppoID(0)
, m_nAction(0)

, m_binvert(true)
{
        m_bselected=FALSE;

        m_idgroup=-1;
        scale_group.SetVertex(1.0F,1.0F,1.0F);
        rotate_group.SetVertex(0.0F,0.0F,0.0F);

        m_nType=0;
        m_angolo[0]=0.0;
        m_angolo[1]=0.0;
        m_angolo[2]=0.0;
        m_Scale[0]=1.0;
        m_Scale[1]=1.0;
        m_Scale[2]=1.0;
        m_ScaleVertex[0]=1.0;
        m_ScaleVertex[1]=1.0;
        m_ScaleVertex[2]=1.0;
        m_bModificato=false;
        m_IDO=-1;
        m_fMaterial[0]=0.5F;
        m_fMaterial[1]=0.5F;
        m_fMaterial[2]=0.5F;
        m_fMaterial[3]=1.0F;
        m_nAction=0;
        m_nGruppoID=-1;
        inmove=false;
        m_bsmooth=false;
        m_bhide=false;
        m_itex=0;
        m_vbo=NULL;
        loadtexturenull();
        m_maxx=m_maxy=m_maxz=0.0F;
        //m_shaderprogram=NULL;

        //impostare il materiale principale
        GLfloat val[4]={
            0.5F,0.5F,0.5F,1.0F
        };

        GLfloat val2[4]={
            1.0F,1.0F,1.0F,1.0F
        };

        GLfloat val3[4]={
            0.0F,0.0F,0.0F,1.0F
        };

        material * mat= new material(front,false,val,val2,val,val3,val);

        m_material_vector.push_back(*mat);

        //fast structure
        //_vertex=NULL;

        InitModulo();
}

object3d::~object3d()
{
        local_vertex.clear();

        world_vert.clear();

        m_poly.clear();
        m_poly3.clear();
        m_poly4.clear();

       // if(m_vbo!=NULL)
       //     delete m_vbo;




}
void object3d::save(string file)
{
    ofstream *fsave= new ofstream();

    fsave->open(file.c_str(),ios_base::binary);

    if(fsave->good())
    {
        //fsave->write((char*)this,sizeof(this));
        serialize(fsave);
        fsave->close();
    }
    else ;

}
void object3d::load(string file)
{
    ifstream* fload= new ifstream;

    fload->open(file.c_str(),ios_base::binary);

    if(fload->good())
    {
        //fload->read((char*)this,sizeof(object3d));
        serialize(fload);
        fload->close();
    }
    else ;
}



void object3d::serialize(std::ifstream *ar)
{
    int size;
    if(ar->is_open())
    {

        char *cname =(char*) ::malloc(sizeof(char)*50);
        char *csubname=(char*) ::malloc(sizeof(char)*50);

        ar->read((char*)cname,sizeof(char)*50);
        ar->read((char*)csubname,sizeof(char)*50);

        string n(cname);
        name=n;
        string s(csubname);
        subname=s;

        //(*ar) >>m_binvert;



        //(*ar) >>name;
        //(*ar) >>subname;


        world_pos.serialize(ar);
        world_pos_group.serialize(ar);
        scale_group.serialize(ar);
        rotate_group.serialize(ar);
        world_pos_app.serialize(ar);


        //m_shaderprogram=NULL;??

        //(*ar) >> m_material_vector.size();
        ar->read((char*)&size,sizeof(int));
        m_material_vector.resize(size);
        for(int ix=0; ix < m_material_vector.size(); ix++)
            m_material_vector[ix].serialize(ar);

        //da fare
        for(int ix=0; ix < m_tex.size(); ix++)
            ;//to-do m_tex.push_back(obj.m_tex[ix]);




        ar->read((char*)&size,sizeof(int));
        local_vertex.resize(size);
        for(int ix=0; ix < local_vertex.size(); ix++)
            local_vertex[ix].serialize(ar);

        ar->read((char*)&size,sizeof(int));
        m_poly.resize(size);
        for(int ix=0; ix< m_poly.size(); ix++)
            m_poly[ix].serialize(ar);

        ar->read((char*)&size,sizeof(int));
        m_poly3.resize(size);
        for(int ix=0; ix< m_poly3.size(); ix++)
            m_poly3[ix].serialize(ar);

        ar->read((char*)&size,sizeof(int));
        m_poly4.resize(size);
        for(int ix=0; ix< m_poly4.size(); ix++)
            m_poly4[ix].serialize(ar);

        ar->read((char*)&size,sizeof(int));
        m_line.resize(size);
        for(int ix=0; ix < m_line.size(); ix++)
            m_line[ix].serialize(ar);





    }
    else
    {


    }
}
void object3d::serialize(std::ofstream *ar)
{
    if(ar->is_open())
    {
        char *cname =(char*)name.c_str();
        char *csubname=(char*)subname.c_str();
        ar->write((char*)cname,sizeof(char)*50);
        ar->write((char*)csubname,sizeof(char)*50);

        //ar->write((char*)this,sizeof(object3d));


        world_pos.serialize(ar);
        world_pos_group.serialize(ar);
        scale_group.serialize(ar);
        rotate_group.serialize(ar);
        world_pos_app.serialize(ar);

        //m_shaderprogram=NULL;

        int size=m_material_vector.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix < m_material_vector.size(); ix++)
            m_material_vector[ix].serialize(ar);


        for(int ix=0; ix < m_tex.size(); ix++)
            ;//to-do m_tex.push_back(obj.m_tex[ix]);


        //copia i vertici

        size=local_vertex.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix < local_vertex.size(); ix++)
            local_vertex[ix].serialize(ar);
        //copia i poligoni a 3
        size=m_poly.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix< m_poly.size(); ix++)
            m_poly[ix].serialize(ar);

        size=m_poly3.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix< m_poly3.size(); ix++)
            m_poly3[ix].serialize(ar);

        size=m_poly4.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix< m_poly4.size(); ix++)
            m_poly4[ix].serialize(ar);

        size=m_line.size();
        ar->write((char*)&size,sizeof(int));
        for(int ix=0; ix < m_line.size(); ix++)
            m_line[ix].serialize(ar);


    }
    else
    {


    }
}

void object3d::loadtexturenull()
{
    texture * tnull= new texture();

    tnull->loadnull();

    m_tex.push_back(*tnull);

    m_itex=0;


}

void object3d::CreatePoligon(int v1,int v2,int v3,int v4)
{
        poligon ap1,ap2;
        ap1.Set(v1,v2,v3);
        ap2.Set(v2,v4,v3);
        m_poly.push_back(ap1);
        m_poly.push_back(ap2);

}
void object3d::SetInMove(bool nb)
{
        inmove=nb;
}
void object3d::SetWorldPos(float x1, float y1 , float z1)
{
        m_Worldpos.SetVertex(x1,y1,z1);
        world_pos.SetVertex(x1,y1,z1);
        m_nAction=1;
}
//disegna un vertice in modo da vedere quale vertice si sta puntando
void object3d::Explosion(int liv)
{
        /*int nIndex;
        int nrandom;
        srand(time(NULL));
        for ( nIndex=0 ; nIndex<num_poligoni ; nIndex++ )
        {
                nrandom=rand()%10+1;

                                int Vertice1=m_poly[nIndex].lista_vertici[0];

                                int Vertice2=m_poly[nIndex].lista_vertici[1];

                                int Vertice3=m_poly[nIndex].lista_vertici[2];

                                float appx1,appy1,appz1;
                                float appx2,appy2,appz2;
                                float appx3,appy3,appz3;

                                appx1 = local_vertex[Vertice1].GetX()*nrandom;
                                appy1 = local_vertex[Vertice1].GetY()*nrandom;
                                appz1 = local_vertex[Vertice1].GetZ()*nrandom;

                                local_vertex[Vertice1].SetVertex(appx1,appy1,appz1);

                                appx2 = local_vertex[Vertice2].GetX()*nrandom;
                                appy2 = local_vertex[Vertice2].GetY()*nrandom;
                                appz2 = local_vertex[Vertice2].GetZ()*nrandom;

                                local_vertex[Vertice1].SetVertex(appx2,appy2,appz2);

                                appx3 = local_vertex[Vertice3].GetX()*nrandom;
                                appy3 = local_vertex[Vertice3].GetY()*nrandom;
                                appz3 = local_vertex[Vertice3].GetZ()*nrandom;

                                local_vertex[Vertice1].SetVertex(appx3,appy3,appz3);







        }*/

}
void object3d::DrawMaterial(bool color)
{

    int nIndex=0;

    glColor4f(0.0,0.0,0.0,1.0);


    glEnable(GL_DEPTH_TEST);
    if(!m_binvert)
            glFrontFace(GL_CW);
    else
            glFrontFace(GL_CCW);


    glEnable(GL_CULL_FACE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();


    if (m_angolo[0]>360) m_angolo[0]-=360;
    if (m_angolo[1]>360) m_angolo[1]-=360;
    if (m_angolo[2]>360) m_angolo[2]-=360;

    if(m_idgroup==-1)
    {


        if(!inmove)
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        else
                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

    }
    else
    {
        glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
        glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
        glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
        glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
        glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

    }




    if(this->m_bsmooth)
            glShadeModel(GL_SMOOTH);
    else
            glShadeModel(GL_FLAT);

     if (m_poly.size()>0){


        for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
        {



           {

                if(m_poly[nIndex].m_berase)
                    continue;
                glBegin(GL_TRIANGLES);


                    if(this->m_bsmooth)
                        DrawPoligonMaterial(nIndex);
                    else
                        DrawPoligonMaterialFlat(nIndex);




                glEnd();
                           }

        }



    }
     if (m_poly3.size()>0){


        for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
        {

            if(m_poly3[nIndex].m_berase)
                continue;

           {
                glPushMatrix();

                glBegin(GL_TRIANGLES);


                    if(this->m_bsmooth)
                        DrawPoligon3Material(nIndex);
                    else
                        DrawPoligon3MaterialFlat(nIndex);




                glEnd();
                glPopMatrix();
            }

        }



    }
    glPopMatrix();

    if(m_bselected)
        DrawLines();




}
void object3d::DrawPoligon3Texture(int index)
{
        poligon *pol3=&m_poly3[index];
        int v;
        material mat=m_material_vector[0];
        mat.Set();
        glBegin(GL_TRIANGLES);


                v=pol3->Get(0);


                local_vertex[v].DrawTexture();

                v=pol3->Get(2);


                local_vertex[v].DrawTexture();

                v=pol3->Get(1);


                local_vertex[v].DrawTexture();



        glEnd();
}
void object3d::DrawPoligon4Texture(int index)
{
        poligon4 *pol4=&m_poly4[index];



        material mat=m_material_vector[0];
        mat.Set();
        glBegin(GL_QUADS);


                v=pol4->Get(0);


                local_vertex[v].DrawTexture();

                v=pol4->Get(1);


                local_vertex[v].DrawTexture();

                v=pol4->Get(3);


                local_vertex[v].DrawTexture();

                v=pol4->Get(2);


                local_vertex[v].DrawTexture();

        glEnd();
}
void object3d::DrawTexture(void)
{
    int nIndex=0;

    //Init();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    if (m_angolo[0]>360) m_angolo[0]-=360;
    if (m_angolo[1]>360) m_angolo[1]-=360;
    if (m_angolo[2]>360) m_angolo[2]-=360;
    glLineWidth(1.0F);

    if(m_idgroup==-1)
    {
        if(!inmove)
            glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        else
        {
            glBegin(GL_LINES);

            glColor4f(1.0f,1.0f,1.0f,0.5F);

            glVertex3f(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());

            glVertex3f(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


            glEnd();

            glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
        }

        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
    }

    if(this->m_bsmooth)
            glShadeModel(GL_SMOOTH);
    else
            glShadeModel(GL_FLAT);

    glEnable( GL_TEXTURE_2D );
    if (m_poly4.size()>0)
    {

        if(m_tex.size()>0)
            glBindTexture(GL_TEXTURE_2D,m_tex[m_itex].getid());


        {



            for ( nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
            {
                DrawPoligon4Texture(nIndex);


            }
        }

    }
    if (m_poly3.size()>0)
    {

        if(m_tex.size()>0)
            glBindTexture(GL_TEXTURE_2D,m_tex[m_itex].getid());


        {



            for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
            {
                DrawPoligon3Texture(nIndex);


            }
        }

    }
    glDisable(GL_TEXTURE_2D);
    //fine del disegna del puntatore che segnala il vertice
    glPopMatrix();
    if (m_b2D)
            glEnable(GL_CULL_FACE);


    //InitOff();


}
void object3d::DrawColor(bool color)
{
        //return;
        int nIndex=0,Vertice;
        //static bool isapp=true;
        static int contav=0;
        Init();
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();



//f (m_b2D)
        //	glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(!inmove)
        //{
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //}
        else
        //{
                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
        //}
        //isapp=!isapp;

        //glTranslatef(0.0,0.0,-5.0);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
        if(this->m_bsmooth)
                glShadeModel(GL_SMOOTH);
        else
                glShadeModel(GL_FLAT);

//	auxSolidSphere(5.0f);

        if (m_poly.size()>0){

                /*
                if (!m_bSel)
                        //glColor4f(m_color[0],m_color[1],m_color[2],m_color[3]);
                else
                        glColor4f(m_color[0]-0.5f,m_color[1]-0.5f,m_color[2]-0.5f,m_color[3]);
                da mantenere??*/





                                glBegin(GL_TRIANGLES);
                                if (m_bselected)
                                        glColor4f(m_fMaterial[0],m_fMaterial[1],m_fMaterial[2],0.5F);
                                else
                                        glColor4f(m_fMaterial[0]+0.1f,m_fMaterial[1]+0.1f,m_fMaterial[2]+0.1f,0.5F);
                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                        //
                                        m_fMaterial[0]=1.0F;
                                        m_fMaterial[1]=1.0F;
                                        m_fMaterial[2]=1.0F;


                                        //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_fMaterial);
                                        if(this->m_bsmooth)
                                                DrawPoligonSmooth(nIndex,color);
                                        else
                                                DrawPoligon(nIndex,color);



                                }
                                glEnd();




                        //inizio disegno dei vertici






        }
        if (m_poly3.size()>0){

                /*
                if (!m_bSel)
                        glColor4f(m_color[0],m_color[1],m_color[2],m_color[3]);
                else
                        glColor4f(m_color[0]-0.5f,m_color[1]-0.5f,m_color[2]-0.5f,m_color[3]);
                da mantenere??*/





                                glBegin(GL_TRIANGLES);
                                if (m_bselected)
                                        glColor4f(m_fMaterial[0],m_fMaterial[1],m_fMaterial[2],0.5F);
                                else
                                        glColor4f(m_fMaterial[0]+0.1f,m_fMaterial[1]+0.1f,m_fMaterial[2]+0.1f,0.5F);
                                for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
                                {


                                        m_fMaterial[0]=1.0F;
                                        m_fMaterial[1]=1.0F;
                                        m_fMaterial[2]=1.0F;


                                        //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_fMaterial);
                                        if(this->m_bsmooth)
                                                DrawPoligonSmooth3(nIndex,color);
                                        else
                                                DrawPoligon3(nIndex,color);



                                }
                                glEnd();




                        //inizio disegno dei vertici






        }



        glPopMatrix();
        //DrawVertex(color);
        glEnable(GL_LIGHTING);

        InitOff();
        //inizio del disegne del puntatore che segnala il vertice


}
void object3d::DrawSolid(bool color)
{
        int nIndex=0;

        Init();

        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }


        if(this->m_bsmooth)
                glShadeModel(GL_SMOOTH);
        else
                glShadeModel(GL_FLAT);



        if (m_poly.size()>0){


            glBegin(GL_TRIANGLES);

                if (m_bselected)
                    glColor4f(0.8f,0.8,1.0,0.5F);
                else
                    glColor4f(0.5f,0.5f,0.5f,0.5F);

                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                {


                    int Vertice1=m_poly[nIndex].lista_vertici[0];


                    int Vertice2=m_poly[nIndex].lista_vertici[1];


                    int Vertice3=m_poly[nIndex].lista_vertici[2];


                    glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                    glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                    glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());

                }

            glEnd();






        }

        glPopMatrix();

        glEnable(GL_LIGHTING);

        if (m_b2D)
                glEnable(GL_CULL_FACE);

}

void object3d::DrawWireframe(bool color)
{

        int nIndex=0,Vertice;

        static int contav=0;
        Init();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        glLineWidth(1.0F);

        if(m_idgroup==-1)
        {
            if(!inmove)
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
            {
                glBegin(GL_LINES);

                glColor4f(1.0f,1.0f,1.0f,0.5F);

                glVertex3f(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());

                glVertex3f(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


                glEnd();

                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
            }

            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
        }

        if(this->m_bsmooth)
                glShadeModel(GL_SMOOTH);
        else
                glShadeModel(GL_FLAT);


        if (m_poly.size()>0)
        {
            glBegin(GL_LINES);
            {

                float cr=0.0F,cg=0.0F,cb=0.0F;
                glColor4f(0.0f,0.0f,0.0f,0.5F);
                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                {
                    for (int indice=0; indice < MAX_VERTICI_PER_POLY-1; indice++)
                    {
                        Vertice=m_poly[nIndex].lista_vertici[indice];
                        local_vertex[Vertice].Draw();
                        Vertice=m_poly[nIndex].lista_vertici[indice+1];
                        local_vertex[Vertice].Draw();
                    }
                    local_vertex[Vertice].Draw();
                    Vertice= m_poly[nIndex].lista_vertici[0];
                    local_vertex[Vertice].Draw();
                }
            }
            glEnd();
        }
        //fine del disegna del puntatore che segnala il vertice
        glPopMatrix();
        if (m_b2D)
                glEnable(GL_CULL_FACE);

        DrawVertex(color);

        InitOff();
}

void object3d::DrawPoligonSmooth(int pol,bool c)
{
    m_maincolor.draw();
        //m_color[local_vertex[m_poly[pol].lista_vertici[0]].GetColor()].draw();
        local_vertex[m_poly[pol].lista_vertici[0]].DrawNormal();

        //m_color[local_vertex[m_poly[pol].lista_vertici[1]].GetColor()].draw();
        local_vertex[m_poly[pol].lista_vertici[1]].DrawNormal();

        //m_color[local_vertex[m_poly[pol].lista_vertici[2]].GetColor()].draw();
        local_vertex[m_poly[pol].lista_vertici[2]].DrawNormal();

}
void object3d::DrawPoligonSmooth3(int pol,bool c)
{
        m_maincolor.draw();
        //m_color[local_vertex[m_poly3[pol].lista_vertici[0]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[0]].DrawNormal();
        //m_color[local_vertex[m_poly3[pol].lista_vertici[1]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[1]].DrawNormal();
        //m_color[local_vertex[m_poly3[pol].lista_vertici[2]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[2]].DrawNormal();

}

float object3d::getMax()
{
    Max();

    if(m_maxx > m_maxy && m_maxx>m_maxy)
        return(m_maxx);
    if(m_maxy > m_maxz && m_maxy>m_maxx)
        return(m_maxy);
    if(m_maxz > m_maxx && m_maxz>m_maxy)
        return(m_maxz);
}

void object3d::Max()
{
    for(int ix=0; ix < local_vertex.size(); ix++)
    {
        int x=local_vertex[ix].GetX();
        int y=local_vertex[ix].GetY();
        int z=local_vertex[ix].GetZ();
        if(m_maxx < abs(x))
            m_maxx=abs(x);

        if(m_maxy < abs(y))
            m_maxy=abs(y);

        if(m_maxz < abs(z))
            m_maxz=abs(z);

    }


}

void object3d::DrawPoligon(int pol,bool c)
{

        glNormal3f(m_poly[pol].m_normale.GetX(),m_poly[pol].m_normale.GetY(),m_poly[pol].m_normale.GetZ());

        m_maincolor.draw();


        local_vertex[m_poly[pol].lista_vertici[0]].Draw();


        local_vertex[m_poly[pol].lista_vertici[1]].Draw();


        local_vertex[m_poly[pol].lista_vertici[2]].Draw();
}
void object3d::DrawPoligonMaterial(int pol)
{


    int nmat=local_vertex[m_poly[pol].lista_vertici[0]].GetMaterial();

    material mat=m_material_vector[nmat];
    local_vertex[m_poly[pol].lista_vertici[0]].DrawMaterial(&mat);;

    nmat=local_vertex[m_poly[pol].lista_vertici[1]].GetMaterial();

    mat=m_material_vector[nmat];
    local_vertex[m_poly[pol].lista_vertici[1]].DrawMaterial(&mat);;

    nmat=local_vertex[m_poly[pol].lista_vertici[2]].GetMaterial();

    mat=m_material_vector[nmat];
    local_vertex[m_poly[pol].lista_vertici[2]].DrawMaterial(&mat);;


}
void object3d::DrawPoligonMaterialFlat(int pol)
{

    int nmat=local_vertex[m_poly[pol].lista_vertici[0]].GetMaterial();

    material mat=m_material_vector[nmat];


    glNormal3f(m_poly[pol].m_normale.GetX(),m_poly[pol].m_normale.GetY(),m_poly[pol].m_normale.GetZ());

    local_vertex[m_poly[pol].lista_vertici[0]].DrawMaterialFlat(&mat);;

    nmat=local_vertex[m_poly[pol].lista_vertici[1]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly[pol].lista_vertici[1]].DrawMaterialFlat(&mat);;

    nmat=local_vertex[m_poly[pol].lista_vertici[2]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly[pol].lista_vertici[2]].DrawMaterialFlat(&mat);;

}
void object3d::DrawPoligon3Material(int pol)
{


    int nmat=local_vertex[m_poly3[pol].lista_vertici[0]].GetMaterial();

    material mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[0]].DrawMaterial(&mat);;

    local_vertex[m_poly3[pol].lista_vertici[1]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[1]].DrawMaterial(&mat);;

    local_vertex[m_poly3[pol].lista_vertici[2]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[2]].DrawMaterial(&mat);;


}
void object3d::DrawPoligon3MaterialFlat(int pol)
{
    glNormal3f(m_poly3[pol].m_normale.GetX(),m_poly3[pol].m_normale.GetY(),m_poly3[pol].m_normale.GetZ());

    int nmat=local_vertex[m_poly3[pol].lista_vertici[0]].GetMaterial();

    material mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[0]].DrawMaterialFlat(&mat);;

    local_vertex[m_poly3[pol].lista_vertici[1]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[1]].DrawMaterialFlat(&mat);;

    local_vertex[m_poly3[pol].lista_vertici[2]].GetMaterial();

    mat=m_material_vector[nmat];

    local_vertex[m_poly3[pol].lista_vertici[2]].DrawMaterialFlat(&mat);;

}
void object3d::DrawPoligon3(int pol,bool c)
{
//	if(!this->m_bsmooth)
        //glNormal3f(m_poly[pol].m_normale.GetX(),m_poly[pol].m_normale.GetY(),m_poly[pol].m_normale.GetZ());
        //if(this->m_bsmooth)
        //	glNormal3f(normal_vertex[pol].GetX(),normal_vertex[Vertice1].GetY(),normal_vertex[Vertice1].GetZ());
        glNormal3f(m_poly3[pol].m_normale.GetX(),m_poly3[pol].m_normale.GetY(),m_poly3[pol].m_normale.GetZ());

        m_maincolor.draw();
        //m_color[local_vertex[m_poly3[pol].lista_vertici[0]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[0]].Draw();

        //m_color[local_vertex[m_poly3[pol].lista_vertici[1]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[1]].Draw();

        //m_color[local_vertex[m_poly3[pol].lista_vertici[2]].GetColor()].draw();
        local_vertex[m_poly3[pol].lista_vertici[2]].Draw();
}


void object3d::Draw(int md)
{
        if(md==1)//solid
        {
                this->DrawSolid(false);
                return;
        }

        if(md==2)
        {
                this->DrawColor(false);
                return;

        }
        if(md==3)
        {
                this->DrawTexture();
                return;
        }
        if(md==0)//wireframe
        {
                this->DrawWireframe(false);
                return;
        }


        //return;
        /*int nIndex=0,Vertice;
        //static bool isapp=true;
        static int contav=0;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
//f (m_b2D)
        //	glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(!inmove)
        //{
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //}
        else
        //{
                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
        //}
        //isapp=!isapp;

        //glTranslatef(0.0,0.0,-5.0);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
        if(this->m_bsmooth)
                glShadeModel(GL_SMOOTH);
        else
                glShadeModel(GL_FLAT);

        /*if(inmove)
        {
                glBegin(GL_LINES);
                glLineWidth(5.0F);
                //glPointSize(2.0F);
                glColor3f(1.0f,1.0f,1.0f);

                glVertex3f(0.0f,0.0f,0.0f);

                glVertex3f(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


                glEnd();
        }*/
        /*
        if (m_poly.size()>0){

                int nNorm=0;
                if (!m_bSel)
                        glColor3f(m_color[0],m_color[1],m_color[2]);
                else
                        glColor3f(m_color[0]-0.5f,m_color[1]-0.5f,m_color[2]-0.5f);


                switch(m_nType)
                {
                case 0:
                        //md=0 fil di ferro

                        //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_fMaterial);
                        if(md==1)
                        {
                                glBegin(GL_TRIANGLES);

                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                                        //glColor3f(1.0f,0.0f,0.0f);

                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                        //glColor3f(0.0f,1.0f,0.0f);

                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                        //glColor3f(0.0f,0.0f,1.0f);

                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());

                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                        //glColor3f(0.0f,1.0f,0.0f);



                                        //glColor3f(0.0f,0.0f,1.0f);

                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());

                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                }

                                glEnd();
                        }
                        if(md==2)
                        {
                                glBegin(GL_TRIANGLES);

                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                                        //glColor3f(m_color[0],m_color[1],m_color[2]);

                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                        //glColor3f(0.0f,1.0f,0.0f);

                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                        //glColor3f(0.0f,0.0f,1.0f);

                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());

                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                        //glColor3f(0.0f,1.0f,0.0f);



                                        //glColor3f(0.0f,0.0f,1.0f);

                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());

                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                }

                                glEnd();
                        }
                break;
                case 1:
//			glShadeModel(GL_SMOOTH);




                        if(md==0)//wireframe
                        {

                                glBegin(GL_LINES);



                                glColor3f(0.0f,0.0f,0.0f);


                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {
                                        for (int indice=0; indice < MAX_VERTICI_PER_POLY-1; indice++)
                                        {
                                                float appx,appy,appz;
                                                Vertice=m_poly[nIndex].lista_vertici[indice];

                                                appx=local_vertex[Vertice].GetX();
                                                appy=local_vertex[Vertice].GetY();
                                                appz=local_vertex[Vertice].GetZ();

                                                glVertex3f(appx,appy,appz);

                                                Vertice=m_poly[nIndex].lista_vertici[indice+1];
                                                appx=local_vertex[Vertice].GetX();
                                                appy=local_vertex[Vertice].GetY();
                                                appz=local_vertex[Vertice].GetZ();

                                                glVertex3f(appx,appy,appz);
                                                //glVertex3f(local_vertex[Vertice].GetX(),local_vertex[Vertice].GetY(),local_vertex[Vertice].GetZ());

                                        }

                                        glVertex3f(local_vertex[Vertice].GetX(),local_vertex[Vertice].GetY(),local_vertex[Vertice].GetZ());

                                        Vertice= m_poly[nIndex].lista_vertici[0];

                                        glVertex3f(local_vertex[Vertice].GetX(),local_vertex[Vertice].GetY(),local_vertex[Vertice].GetZ());



//				glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());
                                }
                                glEnd();
                        }

                        if(md==1)//solido
                        {
                                glBegin(GL_TRIANGLES);
                                if (m_bselected)
                                        glColor3f(0.8f,0.8,1.0);

                                else
                                        glColor3f(0.5f,0.5f,0.5f);
                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                        //


                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                //glColor3f(1.0f,0.0,0.0);



                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                //glColor3f(1.0f,0.0,0.0);



                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());
                                }
                                glEnd();
                        }
                        //glLineWidth(2.0F);

                        if(md==2)//colore
                        {
                                glBegin(GL_TRIANGLES);
                                if (m_bselected)
                                        glColor3f(m_fMaterial[0],m_fMaterial[1],m_fMaterial[2]);
                                else
                                        glColor3f(m_fMaterial[0]+0.1f,m_fMaterial[1]+0.1f,m_fMaterial[2]+0.1f);
                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                        //
                                        m_fMaterial[0]=1.0F;
                                        m_fMaterial[1]=1.0F;
                                        m_fMaterial[2]=1.0F;


                                        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_fMaterial);
                                        if(!this->m_bsmooth)
                                                glNormal3f(m_poly[nIndex].m_normale.GetX(),m_poly[nIndex].m_normale.GetY(),m_poly[nIndex].m_normale.GetZ());


                                        if(this->m_bsmooth)
                                                glNormal3f(normal_vertex[Vertice1].GetX(),normal_vertex[Vertice1].GetY(),normal_vertex[Vertice1].GetZ());

                                        glColor3f(local_vertex[Vertice1].GetColor(0),local_vertex[Vertice1].GetColor(1),local_vertex[Vertice1].GetColor(2));


                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                        if(this->m_bsmooth)
                                                glNormal3f(normal_vertex[Vertice2].GetX(),normal_vertex[Vertice2].GetY(),normal_vertex[Vertice2].GetZ());

                                        //glColor3f(1.0f,0.0,0.0);

                                        glColor3f(local_vertex[Vertice2].GetColor(0),local_vertex[Vertice2].GetColor(1),local_vertex[Vertice2].GetColor(2));

                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                        //glColor3f(1.0f,0.0,0.0);

                                        glColor3f(local_vertex[Vertice3].GetColor(0),local_vertex[Vertice3].GetColor(1),local_vertex[Vertice3].GetColor(2));

                                        if(this->m_bsmooth)
                                                glNormal3f(normal_vertex[Vertice3].GetX(),normal_vertex[Vertice3].GetY(),normal_vertex[Vertice3].GetZ());

                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());
                                }
                                glEnd();
                        }



                        //inizio disegno dei vertici

                        glPointSize(1.5F);

                        glBegin(GL_POINTS);


                        for ( nIndex=0 ; nIndex<local_vertex.size() ; nIndex++ )
                        {
                                if (!local_vertex[nIndex].IsSelected())
                                        glColor3f(1.0f,0.8f,0.8f);
                                else
                                        glColor3f(1.0f,1.0f,0.0f);

                                glVertex3f(local_vertex[nIndex].GetX(),local_vertex[nIndex].GetY(),local_vertex[nIndex].GetZ());
                        }
                        glEnd();
                //	glShadeModel(GL_FLAT);


                break;
                case 2:
                /*	glPointSize(5.0F);
                        glDisable(GL_POINT_SMOOTH);

                        glColor3f(0.0f,0.0f,0.0f);

                        for ( nIndex=0 ; nIndex<num_vertici ; nIndex++ )
                        {

                                glBegin(GL_POINTS);

                                glVertex3f(local_vertex[nIndex].GetX(),local_vertex[nIndex].GetY(),local_vertex[nIndex].GetZ());
                                glEnd();
                        }

                        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_fMaterial);

                        if(md==1)
                        {
                        glBegin(GL_TRIANGLES);

                        if (m_bselected)

                                glColor3f(m_color[0],m_color[1],m_color[2]);

                        else

                                glColor3f(0.5f,0.5f,0.5f);

                        for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                        {

                                int Vertice1=m_poly[nIndex].lista_vertici[0];

                                int Vertice2=m_poly[nIndex].lista_vertici[1];

                                int Vertice3=m_poly[nIndex].lista_vertici[2];

                                float xn,yn,zn;

                                //glColor3f(0.8f,0.8,1.0);

                                glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                //glColor3f(1.0f,0.0,0.0);

                                glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                //glColor3f(1.0f,0.0,0.0);

                                glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());


                        }

                        glEnd();
                        }

                break;
                }


        }

        else

        {
                glColor3f(m_color[0],m_color[1],m_color[2]);

                glBegin(GL_LINES);

                for (nIndex=0; nIndex<local_vertex.size();nIndex+=2)
                {

                        glVertex3f(local_vertex[nIndex].GetX(),local_vertex[nIndex].GetY(),local_vertex[nIndex].GetZ());
                        glVertex3f(local_vertex[nIndex+1].GetX(),local_vertex[nIndex+1].GetY(),local_vertex[nIndex+1].GetZ());
                }

                glEnd();

        }




        //inizio del disegne del puntatore che segnala il vertice

        float m_fcursor[3];

        //m_fcursor[0]=local_vertex[m_vertexd].GetX();
        //m_fcursor[1]=local_vertex[m_vertexd].GetY();
        //m_fcursor[2]=local_vertex[m_vertexd].GetZ();


        //glBegin		(	GL_LINES	);

        //glColor3f	(	0.0F,	0.0F,	0.0F	);



        /*glVertex3f	(	m_fcursor[0]-3.0F	 ,	m_fcursor[1]	 ,	m_fcursor[2]);
        glVertex3f	(	m_fcursor[0]+3.0F	 ,	m_fcursor[1]	 ,	m_fcursor[2]);

        glVertex3f	(	m_fcursor[0]	 ,	m_fcursor[1]-3.0F	 ,	m_fcursor[2]);
        glVertex3f	(	m_fcursor[0]	 ,	m_fcursor[1]+3.0F	 ,	m_fcursor[2]);

        glVertex3f	(	m_fcursor[0]	 ,	m_fcursor[1]	 ,	m_fcursor[2]-3.0F);
        glVertex3f	(	m_fcursor[0]	 ,	m_fcursor[1]	 ,	m_fcursor[2]+3.0F);
*/
        /*glVertex3f	(	m_fcursor[0]	 ,	m_fcursor[1]	 ,	m_fcursor[2]);
        glVertex3f	(	m_fcursor[0]-1.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f	(	m_fcursor[0]+1.5F,	m_fcursor[1],	m_fcursor[2]+1.5F+1.5F);

        glVertex3f	(	m_fcursor[0]	 	 ,	m_fcursor[2],	m_fcursor[1]);
        glVertex3f	(	m_fcursor[0]-1.5F,	m_fcursor[2]+1.5F,	m_fcursor[1]);
        glVertex3f	(	m_fcursor[0]+1.5F,	m_fcursor[2]+1.5F+1.5F,	m_fcursor[1]);

        glVertex3f	(	m_fcursor[0],		m_fcursor[1]	 ,	m_fcursor[2]);
        glVertex3f	(	m_fcursor[0]+1.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f	(	m_fcursor[0]-1.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);





        glVertex3f(m_fcursor[0]-0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);
        glVertex3f(m_fcursor[0]-2.0F,	m_fcursor[1],	m_fcursor[2]+5.0F);

        glVertex3f(m_fcursor[0]-0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0]-2.0F,	m_fcursor[1],	m_fcursor[2]+5.0F);
        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);


        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);
        glVertex3f(m_fcursor[0]+0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0]+2.0F,	m_fcursor[1],	m_fcursor[2]+5.0F);

        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);
        glVertex3f(m_fcursor[0]+2.0F,	m_fcursor[1],	m_fcursor[2]+5.0F);
        glVertex3f(m_fcursor[0]+0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);



        glVertex3f(m_fcursor[0]-0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0]+0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);


        glVertex3f(m_fcursor[0]-0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);
        glVertex3f(m_fcursor[0],		m_fcursor[1],	m_fcursor[2]+3.5F);
        glVertex3f(m_fcursor[0]+0.5F,	m_fcursor[1],	m_fcursor[2]+1.5F);


*/



        /*

        //glEnd();

        //fine del disegna del puntatore che segnala il vertice
        glPopMatrix();
        if (m_b2D)
                glEnable(GL_CULL_FACE);

*/

}
void object3d::SelectVertex()
{

        if (m_vertexd!=0)
                local_vertex[m_vertexd].SetSelected(true);

}
void object3d::selectpoly4(int index)
{
    m_poly4[index].selected(true);



    for(int ix=0; ix < 4; ix++)
    {
        int v=m_poly4[index].Get(ix);
        local_vertex[v].selected(true);

        int l1=m_poly4[index].getline(ix);
        if(l1>=0 && l1<m_line.size())
            if(!m_line[l1].selected())
                m_line[l1].selected(true);
            else
                m_line[l1].selected(false);

    }

}

void object3d::DrawOgl()
{
        /*int nIndex;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        //if (m_b2D)
                glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        //glTranslatef(m_Worldpos.GetX(),m_Worldpos.GetY(),m_Worldpos.GetZ());
        glTranslatef(0.,0.,5.);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);
        /*if (m_nNumPoligoni!=0){
                //if (m_nType==0)
                //	glBegin(GL_TRIANGLES);
                //else
                        glBegin(GL_LINES);
                int nNorm=0;
                //if (!m_bSel)
                //	glColor3f(m_color[0],m_color[1],m_color[2]);
                //else
                //	glColor3f(m_color[0]-0.5f,m_color[1]-0.5f,m_color[2]-0.5f);
                glColor3f(0.0,0.0,0.0);
                for (nIndex=0;nIndex<m_nNumPoligoni;nIndex++)
                {
                        int Vertice1=m_poly[nIndex].lista_vertici[0];
                        int Vertice2=m_poly[nIndex].lista_vertici[1];
                        int Vertice3=m_poly[nIndex].lista_vertici[2];
                        float xn,yn,zn;

                        xn=m_Normale[nNorm].GetX();
                        yn=m_Normale[nNorm].GetY();
                        zn=m_Normale[nNorm].GetZ();
                        glNormal3f(xn,yn,zn);
                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());
                        glNormal3f(xn,yn,zn);
                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());
                        glNormal3f(xn,yn,zn);
                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());
                        nNorm++;
                }
                glEnd();
        }else
        {
                //glColor3f(m_color[0],m_color[1],m_color[2]);
                glColor3f(250.0,0.0,0.0);
                glBegin(GL_LINES);
                for (nIndex=0; nIndex<num_vertici+1;nIndex+=2)
                {
                        glNormal3f(0.0f,1.0f,0.0f);
                        glVertex3f(m_Vertice[nIndex].GetX(),m_Vertice[nIndex].GetY(),m_Vertice[nIndex].GetZ());
                        glVertex3f(m_Vertice[nIndex+1].GetX(),m_Vertice[nIndex+1].GetY(),m_Vertice[nIndex+1].GetZ());
                }
                glEnd();
        //}
        glPopMatrix();
        //if (m_b2D)
                glEnable(GL_CULL_FACE);
        */

}
void object3d::ComputeVerticeNormal(int nindex)
{


        // Store each face which has an intersection with the ixVertice'th vertex

        //prendere la normale di tutti i poligoni adiacenti e fare la media delle normali

        for(int ix=0; ix < local_vertex.size(); ix++)
        {
                int vertice=ix;
                int count=0;
                vertex normal;
                float n[3];
                normal.SetVertex(0.0F,0.0F,0.0F);
                for(int iy=0; iy < m_poly.size(); iy++)
                {
                        if(m_poly[iy].lista_vertici[0]==vertice ||m_poly[iy].lista_vertici[1]==vertice||m_poly[iy].lista_vertici[2]==vertice)
                        {
                                normal.Add(m_poly[iy].m_normale);
                                count++;
                        }
                }
                for(int iy=0; iy < m_poly3.size(); iy++)
                {
                        if(m_poly3[iy].lista_vertici[0]==vertice ||m_poly3[iy].lista_vertici[1]==vertice||m_poly3[iy].lista_vertici[2]==vertice)
                        {
                                normal.Add(m_poly3[iy].m_normale);
                                count++;
                        }
                }
                //normal.SetVertex(normal.GetX()/count,normal.GetY()/count,normal.GetZ()/count);
                n[0]=normal.GetX()/(float)count;
                n[1]=normal.GetY()/(float)count;
                n[2]=normal.GetZ()/(float)count;

                local_vertex[ix].SetNormal(n);
        }


}

// trasforma le coordinate da locali a coordinate mondo
void object3d::TrasformaL2W(void)
{
        //local_vertex to world_vert
        int index;
        float appx,appy,appz;

        for (index=0; index < local_vertex.size(); index++)
        {
                appx=local_vertex[index].GetX();
                appy=local_vertex[index].GetY();
                appz=local_vertex[index].GetZ();
                appx+=world_pos.GetX();
                appy+=world_pos.GetY();
                appz+=world_pos.GetZ();
                local_vertex[index].SetVertex(appx,appy,appz);

                //world_vert[index].SetVertex(appx,appy,appz);
        }

}

void object3d::move(int dir,int t, float n,bool vert)
{
        /*int s,x=0;
        int index;
        float appx,appy,appz;
        action.push_back(CAction());
        int na = action.size();


        if (dir==1)
                s=1;
        else
                s=-1;
        if(!vert)
        {
                switch(t)
                {
                case 1://x
                        appx=world_pos.GetX();
                        appx+=(n*s);
                        world_pos.SetX(appx);

                        break;
                case 2://y
                        appy=world_pos.GetY();
                        appy+=(n*s);
                        world_pos.SetY(appy);

                        break;
                case 3://z
                        appz=world_pos.GetZ();
                        appz+=(n*s);
                        world_pos.SetZ(appz);

                        break;
                }
        }
        else
        {
                for (index=0; index < num_vertici; index++)
                {
                        if (m_Vertice[index].IsSelected())
                        {
                        switch(t)
                        {
                        case 1:// x
                                appx=local_vertex[index].GetX();
                                appx+=(n*s);
                                local_vertex[index].SetX(appx);
                                break;
                        case 2:// y
                                appy=local_vertex[index].GetY();
                                appy+=(n*s);
                                local_vertex[index].SetY(appy);
                                break;
                        case 3:// z
                                appz=local_vertex[index].GetZ();
                                appz+=(n*s);
                                local_vertex[index].SetZ(appz);
                                break;

                        }
                        }
                }

        }*/

 }

void object3d::Scale(int tipo, float fscala)
{
        int nIndex;
        float appx,appy,appz;
        //float appxw,appyw,appzw;
        string str;
        //AfxMessageBox(str,MB_OK);
        m_nAction=2;
        int n=local_vertex.size();
        for (nIndex=0; nIndex< n ; nIndex++)
        {
                appx=fscala *	local_vertex[nIndex].GetX();
                appy=fscala *	local_vertex[nIndex].GetY();
                appz=fscala *	local_vertex[nIndex].GetZ();

                //appxw=fscala *world_vert[nIndex].GetX();
                //appyw=fscala *world_vert[nIndex].GetY();
                //appzw=fscala *world_vert[nIndex].GetZ();
                switch (tipo)
                {
                case 0:
                        local_vertex[nIndex].SetX(appx);
                //	world_vert[nIndex].SetX(appxw);
                        break;
                case 1:
                        local_vertex[nIndex].SetY(appy);
                //	world_vert[nIndex].SetX(appyw);
                        break;
                case 2:
                        local_vertex[nIndex].SetZ(appz);
                //	world_vert[nIndex].SetX(appzw);
                        break;
                case 3:
                        local_vertex[nIndex].SetVertex(appx,appy,appz);
                //	world_vert[nIndex].SetVertex(appxw,appyw,appzw);
                        break;
                }


        }
        TrasformaL2W();

}

bool object3d::RotateXpunto(int gr,vertex punto)
{
        int x;
        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appy,appz;

                appx=this->local_vertex[x].GetX()-punto.GetX();
                appy=this->local_vertex[x].GetY()-punto.GetY();
                appz=this->local_vertex[x].GetZ()-punto.GetZ();

                /*y' = y*cos q - z*sin q
z' = y*sin q + z*cos q
x' = x*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);

                appy=appy * cos(gr * 3.1415F/180.0F) - appz * sin(gr * 3.1415F/180.0F);
                appz=appy * sin(gr * 3.1415F/180.0F) + appz *cos(gr * 3.1415F/180.0F);

                appx+=punto.GetX();
                appy+=punto.GetY();
                appz+=punto.GetZ();

                this->local_vertex[x].SetX(appx);
                this->local_vertex[x].SetY(appy);
                this->local_vertex[x].SetZ(appz);







        }
        m_angolo[0]=0.0F;
        return false;

}
bool object3d::RotateX(float gr)
{
        int x;
        gr=360.0F-gr;
        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appy,appy2,appz;

                appx=this->local_vertex[x].GetX();
                appy=this->local_vertex[x].GetY();
                appz=this->local_vertex[x].GetZ();



                appy2 = appy *    cos(gr * 3.1415F/180.0F)    + appz *  sin(gr * 3.1415F/180.0F);
                appz  = appy *  (-sin(gr * 3.1415F/180.0F)) + appz *  cos(gr * 3.1415F/180.0F);

                this->local_vertex[x].SetY(appy2);
                this->local_vertex[x].SetZ(appz);







        }
        m_angolo[0]=0.0F;
        return false;
}
bool object3d::RotateZpunto(int gr,vertex punto)
{
        int x;
        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appy,appz;

                appx=this->local_vertex[x].GetX()-punto.GetX();
                appy=this->local_vertex[x].GetY()-punto.GetY();
                appz=this->local_vertex[x].GetZ()-punto.GetZ();

                /*x' = x*cos q - y*sin q
y' = x*sin q + y*cos q
z' = z*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);

                appx=appx * cos(gr * 3.1415F/180.0F) - appy * sin(gr * 3.1415F/180.0F);
                appy=appx * (-sin(gr * 3.1415F/180.0F)) + appy *cos(gr * 3.1415F/180.0F);

                appx+=punto.GetX();
                appy+=punto.GetY();
                appz+=punto.GetZ();

                this->local_vertex[x].SetX(appx);
                this->local_vertex[x].SetY(appy);
                this->local_vertex[x].SetZ(appz);







        }
        m_angolo[2]=0.0F;
        return false;
}
bool object3d::RotateZ(float gr)
{
        int x;
        gr=360.0F-gr;
        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appx2,appy,appz;

                appx=this->local_vertex[x].GetX();
                appy=this->local_vertex[x].GetY();
                appz=this->local_vertex[x].GetZ();

                /*x' = x*cos q - y*sin q
y' = x*sin q + y*cos q
z' = z*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);

                appx2 =appx * cos(gr * 3.1415F/180.0F) + appy * sin(gr * 3.1415F/180.0F);
                appy  =appx * (-sin(gr * 3.1415F/180.0F)) + appy * cos(gr * 3.1415F/180.0F);


                this->local_vertex[x].SetX(appx2);
                this->local_vertex[x].SetY(appy);







        }
        m_angolo[2]=0.0F;
        return false;
}
bool object3d::RotateYpunto(int gr,vertex punto)
{
        int x;

        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appy,appz;

                appx=this->local_vertex[x].GetX()-punto.GetX();
                appy=this->local_vertex[x].GetY()-punto.GetY();
                appz=this->local_vertex[x].GetZ()-punto.GetZ();

                /*z' = z*cos q - x*sin q
x' = z*sin q + x*cos q
y' = y*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);

                appz=appz * cos(gr * 3.1415F/180.0F) - appx * sin(gr * 3.1415F/180.0F);
                appx=appz * sin(gr * 3.1415F/180.0F) + appx *cos(gr * 3.1415F/180.0F);

                appx+=punto.GetX();
                appy+=punto.GetY();
                appz+=punto.GetZ();

                this->local_vertex[x].SetX(appx);
                this->local_vertex[x].SetY(appy);
                this->local_vertex[x].SetZ(appz);







        }
        m_angolo[1]=0.0F;
        return false;
}
bool object3d::RotateY(float gr)
{
        int x;
        gr=360.0F-gr;
        for(x=0; x < local_vertex.size();  x++)
        {
                float appx,appx2,appy,appz;

                appx=this->local_vertex[x].GetX();
                appy=this->local_vertex[x].GetY();
                appz=this->local_vertex[x].GetZ();

                /*z' = z*cos q - x*sin q
x' = z*sin q + x*cos q
y' = y*/

                //appx=appy * cos(m_angolo[0] * 3.1415F/180.0F) - appz * sin(m_angolo[0] * 3.1415F/180.0F);
                //appy=appy * sin(m_angolo[0] * 3.1415F/180.0F) + appz *cos(m_angolo[0] * 3.1415F/180.0F);

                appx2 =(float) appx * cos((float) gr * 3.1415F / 180.0F ) + appz *    (-sin( (float) gr * 3.1415F/180.0F  ) );
                appz =(float) appx * sin((float) gr * 3.1415F / 180.0F ) + appz * cos( (float) gr * 3.1415F/180.0F      );

                this->local_vertex[x].SetX(appx2);
                this->local_vertex[x].SetZ(appz);







        }
        m_angolo[1]=0.0F;
        return false;
}
void object3d::ApplicaRotazionePunto( vertex punto)
{
        RotateXpunto(this->m_angolo[0],punto);
        RotateYpunto(this->m_angolo[1],punto);
        RotateZpunto(this->m_angolo[2],punto);

}
void object3d::ApplicaRotazione(void)
{
    if(m_vbo!=NULL)
        return;

        RotateX(this->m_angolo[0]);
        RotateY(this->m_angolo[1]);
        RotateZ(this->m_angolo[2]);

}
bool object3d::Rotate(int gr)
{
        //RotateZ(45.0F);
        if(m_angolo[0])
                RotateX(this->m_angolo[0]);
        if(m_angolo[1])
                RotateY(this->m_angolo[1]);
        if(m_angolo[2])
                RotateZ(this->m_angolo[2]);
        return false;
}

void object3d::UnselectVert(void)
{
        int nIndex;
        int nSize=local_vertex.size();
        for (nIndex=0; nIndex < nSize ; nIndex++)
        {
                local_vertex[nIndex].SetSelected(false);
        }

}




void object3d::SetID(int mid)
{
        if (mid!= -1)
                m_IDO = mid ;
}
void object3d::setGroup(int value)
{
    m_idgroup=value;
}

int object3d::getGroup()
{
    return m_idgroup;
}

void object3d::SetGruppoID(int ngr)
{
        m_nGruppoID=ngr;
}

int object3d::GetID()
{
        return(m_IDO);
}
void object3d::DrawSelectPoligon()
{
        glEnable(GL_DEPTH_TEST);

        if(m_binvert)
                glFrontFace(GL_CW);
        else
                glFrontFace(GL_CCW);

        glEnable(GL_CULL_FACE);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }


        if (m_poly4.size()>0){





                glColor4f(1.0F,1.0F,1.0F,0.5F);

                for (int nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
                {
                        poligon4 pol4=m_poly4[nIndex];
                        int v;

                        glLoadName(nIndex+1);
                        m_poly4[nIndex].SetName(nIndex+1);

                        glBegin(GL_QUADS);

                                v=pol4.Get(0);
                                local_vertex[v].Draw();

                                v=pol4.Get(2);
                                local_vertex[v].Draw();

                                v=pol4.Get(3);
                                local_vertex[v].Draw();

                                v=pol4.Get(1);
                                local_vertex[v].Draw();

                        glEnd();




                }


    }

        if (m_poly3.size()>0){

                int nNorm=0;



                glColor4f(1.0F,1.0F,1.0F,0.5F);

                for (int nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
                {
                        poligon pol3=m_poly3[nIndex];
                        int v;

                        glLoadName(nIndex+m_poly4.size()+100);
                        m_poly3[nIndex].SetName(nIndex+m_poly4.size()+100);

                        glBegin(GL_TRIANGLES);

                                v=pol3.Get(0);
                                local_vertex[v].Draw();

                                v=pol3.Get(2);
                                local_vertex[v].Draw();

                                v=pol3.Get(1);
                                local_vertex[v].Draw();


                        glEnd();




                }


    }



        glPopMatrix();

}
void object3d::DrawSelectLine()
{


        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);

        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        if(m_line.size() > 0)
        {

                glLineWidth(5.00F);
                for (int ix=0; ix < m_line.size();ix++)
                {
                    line *appl;

                    appl=&m_line[ix];


                    appl->SetName(ix+1);

                    glLoadName(ix+1);

                    glBegin(GL_LINES);


                        local_vertex[appl->GetVertice(0)].Draw();
                        local_vertex[appl->GetVertice(1)].Draw();

                    glEnd();

                    appl=NULL;

                }

        }


        glPopMatrix();

        glLineWidth(1.0F);

}
void object3d::DrawSelectVertex()
{
        int nname=1,nIndex;

        //if(this->m_bselected)
        //	return;

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());


        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);

        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        if(local_vertex.size() > 0)
        {
                vertex *appv;


                for (int ix=0; ix < local_vertex.size();ix++)
                {
                    if( local_vertex[ix].m_berase)
                        continue;

                    appv=&local_vertex[ix];

                    glLoadName(ix+1);

                    glPointSize(20.0F);

                    glBegin(GL_POINTS);

                        appv->Draw();


                    glEnd();
                }
                glPointSize(1.0F);
        }

        glPopMatrix();

}
void object3d::DrawSelect()
{
        int nIndex;


        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }




        glLoadName(m_name);

        if (m_poly.size()>0 || m_poly3.size()>0 ){


                        if(m_poly.size()>0)
                        {
                            glBegin(GL_TRIANGLES);
                            for ( nIndex=0 ; nIndex < m_poly.size() ; nIndex++ )
                            {

                                int Vertice1=m_poly[nIndex].lista_vertici[0];

                                int Vertice2=m_poly[nIndex].lista_vertici[1];

                                int Vertice3=m_poly[nIndex].lista_vertici[2];



                                local_vertex[Vertice1].Draw();
                                local_vertex[Vertice2].Draw();
                                local_vertex[Vertice3].Draw();
                            }
                            glEnd();
                        }
                        if(m_poly3.size()>0)
                        {
                            glBegin(GL_TRIANGLES);
                            for ( nIndex=0 ; nIndex < m_poly3.size() ; nIndex++ )
                            {

                                int Vertice1=m_poly3[nIndex].lista_vertici[0];

                                int Vertice2=m_poly3[nIndex].lista_vertici[1];

                                int Vertice3=m_poly3[nIndex].lista_vertici[2];



                                local_vertex[Vertice1].Draw();
                                local_vertex[Vertice2].Draw();
                                local_vertex[Vertice3].Draw();


                            }

                            glEnd();
                        }



        }

        glPopMatrix();

}

void object3d::Scale()
{

    if(m_vbo!=NULL)
    {

        scalevbo();

        return;

    }


    int nIndex;


        //to-do applicare la scala ai vertici contenuti nel vbo

    for (nIndex=0; nIndex< local_vertex.size() ; nIndex++)
         ScaleVertex(nIndex);


    m_Scale[0]=1.0F;
    m_Scale[1]=1.0F;
    m_Scale[2]=1.0F;

    m_maxx=m_maxy=m_maxz=0.0F;

}

void object3d::ScaleEdit()
{

        int nIndex;
        float appx,appy,appz;


        for (nIndex=0; nIndex< local_vertex.size() ; nIndex++)
                if(local_vertex[nIndex].IsSelected())
                        ScaleVertex(nIndex,m_ScaleVertex);

        m_ScaleVertex[0]=1.0F;
        m_ScaleVertex[1]=1.0F;
        m_ScaleVertex[2]=1.0F;

}

void object3d::ScaleVertex(int vindex)
{
        Q_ASSERT(vindex >=0 && vindex < local_vertex.size());

        int nIndex;
        float appx,appy,appz;


        appx=m_Scale[0] *	local_vertex[vindex].GetX();
        appy=m_Scale[1] *	local_vertex[vindex].GetY();
        appz=m_Scale[2] *	local_vertex[vindex].GetZ();

        local_vertex[vindex].SetVertex(appx,appy,appz);

        //m_Scale[0]=1.0F;
        //m_Scale[1]=1.0F;
        //m_Scale[2]=1.0F;

}
void object3d::ScaleVertex(int vindex,float sc[3])
{
        Q_ASSERT(vindex >=0 && vindex < local_vertex.size());

        int nIndex;
        float appx,appy,appz;


        appx=sc[0] *	local_vertex[vindex].GetX();
        appy=sc[1] *	local_vertex[vindex].GetY();
        appz=sc[2] *	local_vertex[vindex].GetZ();

        local_vertex[vindex].SetVertex(appx,appy,appz);

        //m_Scale[0]=1.0F;
        //m_Scale[1]=1.0F;
        //m_Scale[2]=1.0F;

}
void object3d::SetName(int name)
{
        m_name=name;
}
void object3d::InitModulo(void)
{
        smodulo.push_back(string("//Objetc's module"));

}

void object3d::EseguiModulo(unsigned int nChar)
{
        int xf;
        int sp,val;
        float vald;
        int nf=modulo.funzioni.size();
        string as;
        as.append("%c",nChar);
        for(xf=0; xf < nf ; xf++)
        {
                if( modulo.funzioni[xf].key == as )
                {
                        int na=modulo.funzioni[xf].azione.size();
                        int xa;
                        for(xa=0; xa< na; xa++)
                        {
                                int ta=	modulo.funzioni[xf].azione[xa].GetAction();

                                switch(ta)
                                {
                                case 1://spostamento

                                        sp=modulo.funzioni[xf].azione[xa].GetSpostaDir();
                                        val=modulo.funzioni[xf].azione[xa].GetSpostaVal();

                                        float appx,appy,appz;

                                        appx=world_pos.GetX();

                                        appy=world_pos.GetY();

                                        appz=world_pos.GetZ();

                                        switch (sp)
                                        {

                                                case 1://x
                                                        appx+=val;

                                                        break;
                                                case 2://y
                                                        appy+=val;
                                                        break;
                                                case 3://z
                                                        appz+=val;
                                                        break;
                                                case 4://x-y-z
                                                        appx+=val;
                                                        appy+=val;
                                                        appz+=val;
                                                        break;
                                        }
                                        world_pos.SetX(appx);
                                        world_pos.SetY(appy);
                                        world_pos.SetZ(appz);




                                        break;

                                case 2://scalatura
                                        sp=modulo.funzioni[xf].azione[xa].GetSpostaDir();
                                        vald=modulo.funzioni[xf].azione[xa].GetScaleVal();

                                        Scale(sp-1,val);


                                        break;
                                case 3://rotazione
                                        sp=modulo.funzioni[xf].azione[xa].GetSpostaDir();
                                        vald=modulo.funzioni[xf].azione[xa].GetScaleVal();

                                        switch(sp)
                                        {
                                        case 1:
                                                this->m_angolo[0]+=vald;
                                                break;
                                        case 2:
                                                this->m_angolo[1]+=vald;
                                                break;
                                        case 3:
                                                this->m_angolo[2]+=vald;
                                                break;
                                        case 4:
                                                this->m_angolo[0]+=vald;
                                                this->m_angolo[1]+=vald;
                                                this->m_angolo[2]+=vald;
                                                break;
                                        }


                                        break;

                                }

                        }

                }

        }
}
vertex object3d::ProdottoVettoriale(vertex u, vertex v)
{

        vertex n;
        n.SetX((u.GetY()* v.GetZ()) - (u.GetZ() * v.GetY()));
        n.SetY((u.GetZ() * v.GetX()) - (u.GetX() * v.GetZ()));
        n.SetZ((u.GetX()* v.GetY()) - (u.GetY() * v.GetX()));
        return (n);
}

vertex object3d::CreaVettore(vertex start, vertex end)
{
        vertex  ris;
        ris.SetX(end.GetX() -start.GetX());
        ris.SetY(end.GetY() -start.GetY());
        ris.SetZ(end.GetZ() -start.GetZ());

        normalize(&ris);
        return(ris);
}
void object3d::CalcNormal()
{

        int indice=0;
        vertex u, v, vett0, vett1, vett2;


        for (indice=0; indice < m_poly.size() ; indice++)
        {
                vertex appnormale;
                int v1 = m_poly[indice].lista_vertici[0];
                int v2 = m_poly[indice].lista_vertici[1];
                int v3 = m_poly[indice].lista_vertici[2];

                vett0 = local_vertex[v1];
                vett1 = local_vertex[v2];
                vett2 = local_vertex[v3];

                u=CreaVettore (vett0, vett1);
                v=CreaVettore (vett0, vett2);

                appnormale=ProdottoVettoriale (u, v);

                normalize(&appnormale);

                m_poly[indice].m_normale=appnormale;

        }
        for (indice=0; indice < m_poly3.size() ; indice++)
        {
                vertex appnormale;
                int v1 = m_poly3[indice].lista_vertici[0];
                int v2 = m_poly3[indice].lista_vertici[1];
                int v3 = m_poly3[indice].lista_vertici[2];

                vett0 = local_vertex[v1];
                vett1 = local_vertex[v2];
                vett2 = local_vertex[v3];

                u=CreaVettore (vett0, vett1);
                v=CreaVettore (vett0, vett2);

                appnormale=ProdottoVettoriale (u, v);

                normalize(&appnormale);
                m_poly3[indice].m_normale=appnormale;


        }





        ComputeVerticeNormal(0);

}
string object3d::CreatePov(ofstream* myFile)
{
        /*
        int x,npoli;
        char * szbuffer;
        string str;
        string appstr,appstr1;
        int v1,v2,v3;
        float appx,appy,appz,appx1,appy1,appz1,appx2,appy2,appz2;
        //inserire per ogni vertice il colore associato
        for (x=0 ; x < local_vertex.size(); x++)
        {
                str.Format(_T("#declare color_v%d = texture { \npigment { color rgb<%f, %f, %f> } finish { ambient 1.0 diffuse 1.0 }}\n") ,x,this->local_vertex[x].GetColor(0),this->local_vertex[x].GetColor(1),this->local_vertex[x].GetColor(2));
                myFile->WriteString(str.GetBuffer());
        }


        //str.Format("#declare color%s = texture { \npigment { color rgb<%f, %f, %f> } finish { ambient 1.0 diffuse 1.0 }}\n" ,this->name,this->m_fMaterial[0],this->m_fMaterial[1],this->m_fMaterial[2]);
        //myFile->WriteString(str.GetBuffer());

        myFile->WriteString( _T("mesh {\n") );
        npoli=m_poly.size();


        for(x=0; x<npoli; x++)
        {

                v1=m_poly[x].lista_vertici[0];
                v2=m_poly[x].lista_vertici[1];
                v3=m_poly[x].lista_vertici[2];


                appx=local_vertex[v1].GetX()+world_pos.GetX();
                appy=local_vertex[v1].GetY()+world_pos.GetY();
                appz=local_vertex[v1].GetZ()+world_pos.GetZ();


                appx1=local_vertex[v2].GetX()+world_pos.GetX();
                appy1=local_vertex[v2].GetY()+world_pos.GetY();
                appz1=local_vertex[v2].GetZ()+world_pos.GetZ();



                appx2=local_vertex[v3].GetX()+world_pos.GetX();
                appy2=local_vertex[v3].GetY()+world_pos.GetY();
                appz2=local_vertex[v3].GetZ()+world_pos.GetZ();

                appstr1.Format(_T("triangle { <%f,%f,%f> , <%f,%f,%f> ,<%f,%f,%f>  texture { color_v%d } }\n"),appx,appy,appz,appx1,appy1,appz1,appx2,appy2,appz2,v1);

                szbuffer=(char*)appstr1.GetBuffer(256);
                myFile->WriteString((LPCTSTR)szbuffer);

                appstr.Append(appstr1);





        }
        appstr1.Format(_T("texture { pigment { color rgb<0.9, 0.9, 0.9> } finish { ambient 0.2 diffuse 0.7 }}\n"));

        szbuffer=(char*)appstr1.GetBuffer(256);
        myFile->WriteString((LPCTSTR)szbuffer);

        appstr.Append(appstr1);


        str.Append(appstr);

        str.Append(_T("}"));

        szbuffer="}";
        myFile->WriteString( _T("}\n"));
        */

        //return str;
}

string object3d::CreatePovAni(ofstream* myFile)
{
     /*   int x,npoli;
        char * szbuffer;
        CString str;
        CString appstr,appstr1;
        int v1,v2,v3;
        float appx,appy,appz,appx1,appy1,appz1,appx2,appy2,appz2;
        //inserire per ogni vertice il colore associato
        for (x=0 ; x < local_vertex.size(); x++)
        {
                str.Format(_T("#declare color_v%d = texture { \npigment { color rgb<%f, %f, %f> } finish { ambient 1.0 diffuse 1.0 }}\n") ,x,this->local_vertex[x].GetColor(0),this->local_vertex[x].GetColor(1),this->local_vertex[x].GetColor(2));
                myFile->WriteString(str.GetBuffer());
        }


        //str.Format("#declare color%s = texture { \npigment { color rgb<%f, %f, %f> } finish { ambient 1.0 diffuse 1.0 }}\n" ,this->name,this->m_fMaterial[0],this->m_fMaterial[1],this->m_fMaterial[2]);
        //myFile->WriteString(str.GetBuffer());

        myFile->WriteString((LPCTSTR) "mesh {\n" );
        npoli=m_poly.size();


        for(x=0; x<npoli; x++)
        {

                v1=m_poly[x].lista_vertici[0];
                v2=m_poly[x].lista_vertici[1];
                v3=m_poly[x].lista_vertici[2];


                appx=local_vertex[v1].GetX();
                appy=local_vertex[v1].GetZ();
                appz=local_vertex[v1].GetY();


                appx2=local_vertex[v2].GetX();
                appy2=local_vertex[v2].GetZ();
                appz2=local_vertex[v2].GetY();



                appx1=local_vertex[v3].GetX();
                appy1=local_vertex[v3].GetZ();
                appz1=local_vertex[v3].GetY();

                appstr1.Format(_T("triangle { <%f,%f,%f> , <%f,%f,%f> ,<%f,%f,%f>  texture { color_v%d } }\n"),appx,appy,appz,appx1,appy1,appz1,appx2,appy2,appz2,v1);

                szbuffer=(char *)appstr1.GetBuffer(256);
                myFile->WriteString((LPCTSTR)szbuffer);

                appstr.Append(appstr1);





        }
        appstr1.Format(_T("texture { pigment { color rgb<0.9, 0.9, 0.9> } finish { ambient 0.2 diffuse 0.7 }}\n"));

        szbuffer=(char*)appstr1.GetBuffer(256);
        myFile->WriteString((LPCTSTR)szbuffer);

        appstr.Append(appstr1);


        str.Append(appstr);

        str.Append(_T("}"));

        szbuffer="}";
        //myFile->WriteString( "}\n");


        return str;*/
}



/*
void object3d::Serialize(CArchive& ar)
{
        if (ar.IsStoring())
        {	// storing code
                ar << m_nType;

                ar << m_bsmooth;


                world_pos.Serialize(ar);

                ar << this->m_angolo[0];
                ar << this->m_angolo[1];
                ar << this->m_angolo[2];



                //materiale

                ar << m_fMaterial[0];
                ar << m_fMaterial[1];
                ar << m_fMaterial[2];
                ar << m_fMaterial[3];

                //nome oggetto
                ar << name;
                //ar << this->nmod;
                ar << local_vertex.size();

                for (int indvertici=0;indvertici<local_vertex.size();indvertici++)
                        local_vertex[indvertici].Serialize(ar);

                ar << m_poly.size();
                for (int indpoly=0; indpoly<m_poly.size();indpoly++)
                        m_poly[indpoly].Serialize(ar);

                ar << m_poly3.size();
                for (int indpoly=0; indpoly<m_poly3.size();indpoly++)
                        m_poly3[indpoly].Serialize(ar);

                ar << m_poly4.size();

                for(int ip=0; ip < m_poly4.size(); ip++)
                        m_poly4[ip].Serialize(ar);

                ar << m_line.size();

                for(int il=0;il< m_line.size(); il++)
                        m_line[il].Serialize(ar);


                //salva modulo
                ar << smodulo.size();

                for (int nm=0; nm < smodulo.size();nm++)
                        ar << smodulo[nm];

        }
        else
        {	// loading code
                float x,y,z;
                int appi;

                ar >> m_nType;

                ar >> m_bsmooth;

                world_pos.Serialize(ar);


                ar >> this->m_angolo[0];
                ar >> this->m_angolo[1];
                ar >> this->m_angolo[2];

                //materiale

                ar >> m_fMaterial[0];
                ar >> m_fMaterial[1];
                ar >> m_fMaterial[2];
                ar >> m_fMaterial[3];

                //nome oggetto
                ar >> name;
                //ar >> this->nmod;
                ar >> appi;

                local_vertex.SetSize(appi);

                for ( int indvertici=0 ; indvertici < local_vertex.size() ; indvertici++ )
                        local_vertex[indvertici].Serialize(ar);

                ar >> appi;

                m_poly.SetSize(appi);

                for (int indpoly=0; indpoly<m_poly.size();indpoly++)
                        m_poly[indpoly].Serialize(ar);

                ar >> appi;

                m_poly3.SetSize(appi);
                for (int indpoly=0; indpoly<m_poly3.size();indpoly++)
                        m_poly3[indpoly].Serialize(ar);

                ar >> appi;

                m_poly4.SetSize(appi);
                for(int ip=0; ip < appi; ip++)
                {

                        m_poly4[ip].Serialize(ar);
                }

                ar >> appi;
                m_line.SetSize(appi);

                for(int il=0;il< appi; il++)
                {
                        m_line[il].Serialize(ar);
                }



                //salva modulo

                ar >>appi;
                smodulo.SetSize(appi);

                for (int nm=0; nm < smodulo.size();nm++)
                        ar >> smodulo[nm];

                CalcNormal();



        }
}
*/
void object3d::subdivide()
{
   /*     vertex v1,v2,v3;
        vertex vn1,vn2,vn3;
        vertex v12,v23,v31;


        poligon polyapp;
        CArray <poligon,poligon&> newpoly;
        CArray <vertex ,vertex&> newvertex;
        int nSize=m_poly.size();

        int vstart=0;
        int x;

        for(x=0; x < nSize; x++)
        {
                int nv1,nv2,nv3;
                float appx,appy,appz;
                float appx1,appy1,appz1;

                /*

                void subdivide(ref float[] v1, ref float[] v2, ref float[] v3, int depth)
        {
            float[] v12 = new float[3], v23 = new float[3], v31 = new float[3];


            if (depth == 0)
            {
                if (flat == 1)
                    drawTriangleFlat(v1, v2, v3);
                else
                    drawTriangleSmooth(v1, v2, v3);

            }


           //calculate midpoints of each side
            for (int i = 0; i < 3; i++)
            {
                v12[i] = (v1[i] + v2[i]) / 2.0f;
                v23[i] = (v2[i] + v3[i]) / 2.0f;
                v31[i] = (v3[i] + v1[i]) / 2.0f;
            }
            // extrude midpoints to lie on unit sphere
            normalize(v12);
            normalize(v23);
            normalize(v31);

            // recursively subdivide new triangles
            if (depth != 0)
            {
                subdivide(ref v1, ref v12, ref v31, depth - 1);
                subdivide(ref v2, ref v23, ref v12, depth - 1);
                subdivide(ref v3, ref v31, ref v23, depth - 1);
                subdivide(ref v12, ref v23, ref v31, depth - 1);
            }

        }
               /
                nv1=m_poly[x].lista_vertici[0];

                nv2=m_poly[x].lista_vertici[1];

                nv3=m_poly[x].lista_vertici[2];

                v1=local_vertex[nv1];
                v2=local_vertex[nv2];
                v3=local_vertex[nv3];
                //	if (x==0)

                //crea nuovi vertici vertici

                v12.SetX(( v1.GetX() + v2.GetX()) / 2.0f);
        v23.SetX(( v2.GetX() + v3.GetX()) / 2.0f);
        v31.SetX(( v3.GetX() + v1.GetX()) / 2.0f);

                v12.SetY( v1.GetY() + v2.GetY() / 2.0f);
        v23.SetY( v2.GetY() + v3.GetY() / 2.0f);
        v31.SetY( v3.GetY() + v1.GetY() / 2.0f);

                v12.SetZ( v1.GetZ() + v2.GetZ() / 2.0f);
        v23.SetZ( v2.GetZ() + v3.GetZ() / 2.0f);
        v31.SetZ( v3.GetZ() + v1.GetZ() / 2.0f);


                normalize(&v12);
                normalize(&v23);
                normalize(&v31);

                //aggiungi i nuovi vertici e i nuovi poligoni


                //aggungi i nuovi vertici
                newvertex.push_back(v1);
                newvertex.push_back(v12);
                newvertex.push_back(v2);

                newvertex.push_back(v23);
                newvertex.push_back(v3);
                newvertex.push_back(v31);

                //aggiungi nuovi poligoni


                polyapp.lista_vertici[0]=vstart;
                polyapp.lista_vertici[1]=vstart+1;
                polyapp.lista_vertici[2]=vstart+5;

                newpoly.push_back(polyapp);

                polyapp.lista_vertici[0]=vstart+1;
                polyapp.lista_vertici[1]=vstart+2;
                polyapp.lista_vertici[2]=vstart+3;

                newpoly.push_back(polyapp);

                polyapp.lista_vertici[0]=vstart+1;
                polyapp.lista_vertici[1]=vstart+3;
                polyapp.lista_vertici[2]=vstart+5;

                newpoly.push_back(polyapp);

                polyapp.lista_vertici[0]=vstart+5;
                polyapp.lista_vertici[1]=vstart+3;
                polyapp.lista_vertici[2]=vstart+4;

                newpoly.push_back(polyapp);






                /*
                //inizio funzione copiata
                 void subdivide(ref float[] v1, ref float[] v2, ref float[] v3, int depth)
        {
            float[] v12 = new float[3], v23 = new float[3], v31 = new float[3];


            if (depth == 0)
            {
                if (flat == 1)
                    drawTriangleFlat(v1, v2, v3);
                else
                    drawTriangleSmooth(v1, v2, v3);

            }


            calculate midpoints of each side
            for (int i = 0; i < 3; i++)
            {
                v12[i] = (v1[i] + v2[i]) / 2.0f;
                v23[i] = (v2[i] + v3[i]) / 2.0f;
                v31[i] = (v3[i] + v1[i]) / 2.0f;
            }
            // extrude midpoints to lie on unit sphere
            normalize(v12);
            normalize(v23);
            normalize(v31);

            // recursively subdivide new triangles
            if (depth != 0)
            {
                subdivide(ref v1, ref v12, ref v31, depth - 1);
                subdivide(ref v2, ref v23, ref v12, depth - 1);
                subdivide(ref v3, ref v31, ref v23, depth - 1);
                subdivide(ref v12, ref v23, ref v31, depth - 1);
            }

        }

                //fine funzione copiata




                //aggiungi nuovi poligoni




                vstart+=6;












        }
        local_vertex.clear();
        m_poly.clear();
        for(x=0; x < newpoly.size(); x++)
                m_poly.push_back(newpoly.GetAt(x));
        newpoly.clear();

        for(x=0; x < newvertex.size(); x++)
                local_vertex.push_back(newvertex.GetAt(x));
        newvertex.clear();

*/
}
void object3d::swap(float *f1, float *f2)
{
        float  ff;

        if (*f1 < *f2)
        {
                ff=*f1;
                *f1=*f2;
                *f2=ff;
        }

}

void object3d::exportOGL(string name)
{
/*
        CStdioFile myFile;
        if(!name.Compare(_T("")))
        {
                name=this->name;
                name.Append(CString(_T(".h")));
        }


        CString nd;
        nd.Format(_T("Export\\"));

        nd.Append(name);


        char* pszFileName =(char*)nd.GetBuffer();

        CFileException fileException;

        CString str;

        if ( !myFile.Open((LPCTSTR)pszFileName, CFile::modeCreate | CFile::modeReadWrite, &fileException ) )

        {

                TRACE( "Can't open file %s, error = %u\n",pszFileName, fileException.m_cause );

                return ;

        }

        //int no=m_object.size(),c;
        /*camera {
location <0, 0, -100>
look_at <0,0, 0>
}
        int nv=local_vertex.size();

        str.Format(_T("float obj_%s[%d][3]={\n"),this->name.GetBuffer(),nv);

        myFile.WriteString(str.GetBuffer());

        //str.Format("light_source { <50, 50, -50> color rgb<1, 1, 1> }\n#declare Red = texture { \npigment { color rgb<0.8, 0.2, 0.2> } finish { ambient 0.2 diffuse 0.5 }}\n");
        //myFile.WriteString(str.GetBuffer());




        int x;


        for (x=0; x< nv-1; x++)

        {


                //str.Format("\" %ff , %ff , %ff \" ,\n" , local_vertex[x].GetX() , local_vertex[x].GetY() , local_vertex[x].GetZ() );
                str.Format(_T("{ %ff , %ff , %ff } ,\n") , local_vertex[x].GetX() , local_vertex[x].GetY() , local_vertex[x].GetZ() );

                myFile.WriteString(str.GetBuffer());


        }

        //str.Format("\" %ff , %ff , %ff \" };\n" , local_vertex[nv-1].GetX() , local_vertex[nv-1].GetY() , local_vertex[nv-1].GetZ() );
        str.Format(_T("{ %ff , %ff , %ff } };\n") , local_vertex[nv-1].GetX() , local_vertex[nv-1].GetY() , local_vertex[nv-1].GetZ() );


        myFile.WriteString(str.GetBuffer());


        int np=m_poly.size();


        str.Format(_T("int poly_%s[%d][3]={\n"),this->name.GetBuffer(),np);

        myFile.WriteString(str.GetBuffer());

        for ( x=0 ; x < np-1 ; x++ )

        {

                //str.Format("\" %d , %d , %d  \"  ,\n" , m_poly[x].lista_vertici[0] , m_poly[x].lista_vertici[1] , m_poly[x].lista_vertici[2] );
                str.Format(_T("{ %d , %d , %d  }  ,\n") , m_poly[x].lista_vertici[0] , m_poly[x].lista_vertici[1] , m_poly[x].lista_vertici[2] );

                myFile.WriteString ( str.GetBuffer() );

        }

        //str.Format("\" %d , %d , %d  \"  };\n" , m_poly[np-1].lista_vertici[0] , m_poly[np-1].lista_vertici[1] , m_poly[np-1].lista_vertici[2] );
        str.Format(_T("{ %d , %d , %d  }  };\n") , m_poly[np-1].lista_vertici[0] , m_poly[np-1].lista_vertici[1] , m_poly[np-1].lista_vertici[2] );

        myFile.WriteString(str.GetBuffer());


        str.Format(_T("int poly4_%s[%d][4]={\n"),this->name.GetBuffer(),m_poly4.size());

        myFile.WriteString(str.GetBuffer());

        for ( x=0 ; x < m_poly4.size()-1 ; x++ )
        {

                str.Format(_T("{ %d , %d , %d , %d  }  ,\n") , m_poly4[x].Get(0) , m_poly4[x].Get(1) , m_poly4[x].Get(2) , m_poly4[x].Get(3) );

                myFile.WriteString ( str.GetBuffer() );

        }

        str.Format(_T("{ %d , %d , %d , %d  }; \n") , m_poly4[x].Get(0) , m_poly4[x].Get(1) , m_poly4[x].Get(2) , m_poly4[x].Get(3) );

        myFile.WriteString(str.GetBuffer());

        myFile.Close();*/

}

void object3d::exportOGL2(string name,ofstream * mf)
{
/*

        if(!name.Compare(_T("")))
                return;


        char* pszFileName =(char *)name.GetBuffer();

        CFileException fileException;

        CString str;



        //int no=m_object.size(),c;
        /*camera {
location <0, 0, -100>
look_at <0,0, 0>
}
        int nv=local_vertex.size();

        str.Format(_T("float obj_%s[%d][3]={\n"),this->name.GetBuffer(),nv);

        mf->WriteString(str.GetBuffer());

        //str.Format("light_source { <50, 50, -50> color rgb<1, 1, 1> }\n#declare Red = texture { \npigment { color rgb<0.8, 0.2, 0.2> } finish { ambient 0.2 diffuse 0.5 }}\n");
        //myFile.WriteString(str.GetBuffer());




        int x;


        for (x=0; x< nv-1; x++)

        {


                str.Format(_T("\" %f , %f , %f \" ,\n") , local_vertex[x].GetX() , local_vertex[x].GetY() , local_vertex[x].GetZ() );

                mf->WriteString(str.GetBuffer());


        }

        str.Format(_T("\" %f , %f , %f \" };\n") , local_vertex[nv-1].GetX() , local_vertex[nv-1].GetY() , local_vertex[nv-1].GetZ() );

        mf->WriteString(str.GetBuffer());


        int np=m_poly.size();


        str.Format(_T("int poly_%s[%d][3]={\n"),this->name.GetBuffer(),np);

        mf->WriteString(str.GetBuffer());

        for ( x=0 ; x < np-1 ; x++ )

        {

                str.Format(_T("\" %d , %d , %d  \"  ,\n") , m_poly[x].lista_vertici[0] , m_poly[x].lista_vertici[1] , m_poly[x].lista_vertici[2] );

                mf->WriteString ( str.GetBuffer() );

        }

        str.Format(_T("\" %d , %d , %d  \"  };\n") , m_poly[np-1].lista_vertici[0] , m_poly[np-1].lista_vertici[1] , m_poly[np-1].lista_vertici[2] );

        mf->WriteString ( str.GetBuffer() );

*/

}
void object3d::RecPos()
{
        old_world_pos=world_pos;
}
void object3d::RecAng()
{
        m_oldangolo[0]=m_angolo[0];
        m_oldangolo[1]=m_angolo[1];
        m_oldangolo[2]=m_angolo[2];
}
void object3d::resetAng()
{
        m_angolo[0]=m_oldangolo[0];
        m_angolo[1]=m_oldangolo[1];
        m_angolo[2]=m_oldangolo[2];

}
void object3d::DrawVertex(bool color)
{
    int nIndex=0,Vertice;

        static int contav=0;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }


        glPointSize(1.5F);

        glBegin(GL_POINTS);
            float col[3]={1.0,1.0,0.0};


            for ( nIndex=0 ; nIndex<local_vertex.size() ; nIndex++ )
            {

                if(local_vertex[nIndex].m_berase)
                    continue;
                if(m_bselected)
                    local_vertex[nIndex].Draw(col[0],col[1],col[2]);
                else
                    local_vertex[nIndex].Draw(1.0,0.0,0.0);


            }
        glEnd();

    glPopMatrix();



}
void object3d::MatMult(GLfloat M[16], GLfloat v[4])
{
            GLfloat res[4];                                                       // Hold

            res[0]=M[ 0]*v[0]+M[ 4]*v[1]+M[ 8]*v[2]+M[12]*v[3];
            res[1]=M[ 1]*v[0]+M[ 5]*v[1]+M[ 9]*v[2]+M[13]*v[3];
            res[2]=M[ 2]*v[0]+M[ 6]*v[1]+M[10]*v[2]+M[14]*v[3];
            res[3]=M[ 3]*v[0]+M[ 7]*v[1]+M[11]*v[2]+M[15]*v[3];

            v[0]=res[0];                                                          // Results

            v[1]=res[1];
            v[2]=res[2];
            v[3]=res[3];

}

void object3d::AddAction(action act)
{
        m_action.push_back(act);
}
void object3d::SetSmooth(bool bval)
{
        this->m_bsmooth=bval;
}
void object3d::DrawShadow()
{
        glPushAttrib(GL_LIGHTING_BIT);
    //glDisable(GL_LIGHTING);


        // Multiply by shadow projection matrix


    // Now rotate the jet around in the new flattened space
    // Pass true to indicate drawing shadow
    int nIndex=0,Vertice;
        //static bool isapp=true;
        static int contav=0;
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glMultMatrixf((GLfloat *)shadow);
//f (m_b2D)
        //	glDisable(GL_CULL_FACE);
        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(!inmove)
        //{
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //}
        else
        //{
                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
        //}
        //isapp=!isapp;

        //glTranslatef(0.0,0.0,-5.0);
        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        glShadeModel(GL_FLAT);



        if (m_poly.size()>0){

                int nNorm=0;








                                glBegin(GL_TRIANGLES);
                            glColor4f(1.0f,1.0f,1.0f,0.5F);
                                for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
                                {

                                        int Vertice1=m_poly[nIndex].lista_vertici[0];

                                        int Vertice2=m_poly[nIndex].lista_vertici[1];

                                        int Vertice3=m_poly[nIndex].lista_vertici[2];

                                        float xn,yn,zn;

                        //


                                        glVertex3f(local_vertex[Vertice1].GetX(),local_vertex[Vertice1].GetY(),local_vertex[Vertice1].GetZ());

                                //glColor3f(1.0f,0.0,0.0);



                                        glVertex3f(local_vertex[Vertice2].GetX(),local_vertex[Vertice2].GetY(),local_vertex[Vertice2].GetZ());

                                //glColor3f(1.0f,0.0,0.0);



                                        glVertex3f(local_vertex[Vertice3].GetX(),local_vertex[Vertice3].GetY(),local_vertex[Vertice3].GetZ());
                                }
                                glEnd();


                        //inizio disegno dei vertici

                        /*glPointSize(1.5F);

                        glBegin(GL_POINTS);


                        for ( nIndex=0 ; nIndex<local_vertex.size() ; nIndex++ )
                        {
                                if (!local_vertex[nIndex].IsSelected())
                                        glColor3f(1.0f,0.8f,0.8f);
                                else
                                        glColor3f(1.0f,1.0f,0.0f);

                                glVertex3f(local_vertex[nIndex].GetX(),local_vertex[nIndex].GetY(),local_vertex[nIndex].GetZ());
                        }
                        glEnd();
                //	glShadeModel(GL_FLAT);
                */



        }





        //inizio del disegne del puntatore che segnala il vertice

        float m_fcursor[3];





        //fine del disegna del puntatore che segnala il vertice

        if (m_b2D)
                glEnable(GL_CULL_FACE);
    // Restore the projection to normal
    glPopMatrix();
        glPopAttrib();

}
void object3d::ApplyAction(void)
{
        int x,nact=m_action.size();

        for(x=0; x< nact ; x++)
                DoAction2(m_action.at(x));

        //action.push_back(act);
}
void object3d::DoAction2(action act)
{
        float *appangolo;
        if (act.GetAction()==1)
                this->world_pos=act.GetVertex();
        else if (act.GetAction()==2)
        {
                appangolo=act.GetAngoli();
                //this->m_angolo[0]=act
                this->m_angolo[0]=*appangolo++;
                this->m_angolo[1]=*appangolo++;
                this->m_angolo[2]=*appangolo;
                this->ApplicaRotazione();
        }
        else if (act.GetAction()==3)
                ;
}
void object3d::DoAction(action act)
{
        float *appangolo;
        float *appscale;
        vertex va;
        if (act.GetAction()==1)
        {
                va.SetVertex(act.m_fsposta[0],act.m_fsposta[1],act.m_fsposta[2]);
                world_pos.Add(va);
        }
        else if (act.GetAction()==2)
        {
                appangolo=act.GetAngoli();
                //this->m_angolo[0]=act
                this->m_angolo[0]+=*appangolo++;
                this->m_angolo[1]+=*appangolo++;
                this->m_angolo[2]+=*appangolo;
        }
        else if (act.GetAction()==3)
        {
                appscale=act.GetScale();
                //this->Scale(3,*appscale);
                this->m_Scale[0]+=*appscale++;
                this->m_Scale[1]+=*appscale++;
                this->m_Scale[2]+=*appscale;

                //this->m_Scale[0]=*appscale++;
                //this->m_Scale[1]=*appscale++;
                //this->m_Scale[2]=*appscale;
        }
        else if (act.GetAction()==4)//hide-unhide
        {
                m_bhide=act.GetHide();
        }

}
void object3d::normalize(vertex * cv)
{
        vertex vn = *cv;

        float d = (float)sqrt(vn.GetX() * vn.GetX() + vn.GetY() * vn.GetY() + vn.GetZ() * vn.GetZ());
    /* omit explict check for division by zero */

        if(d==0) d=1.0F;
        vn.SetX(vn.GetX() / d ) ;
        vn.SetY(vn.GetY() / d ) ;
        vn.SetZ(vn.GetZ() / d ) ;

        cv = &vn ;





}

void object3d::SetWorldPosOnly(float x, float y, float z)
{
        // spostare solamente il world pos

        int nv= this->local_vertex.size();

        int ix;
        this->world_pos.SetX ( this->world_pos.GetX() + x );
        this->world_pos.SetY ( this->world_pos.GetY() + y );
        this->world_pos.SetZ ( this->world_pos.GetZ() + z );

        for (ix=0; ix < nv; ix++)
        {
                float appx,appy,appz;

                appx=this->local_vertex[ix].GetX();
                appy=this->local_vertex[ix].GetY();
                appz=this->local_vertex[ix].GetZ();

                appx-=x;
                appy-=y;
                appz-=z;

                this->local_vertex[ix].SetVertex(appx,appy,appz);


        }

}



void object3d::setMaterialVector(vector<material> * _mat)
{
   // m_material_vector=_mat;
}
void object3d::setMaterial(material  _mat)
{
    //m_material=_mat;
}
void object3d::setMaterialVertex(int nmat)
{
    for(int ix=0; ix < local_vertex.size();ix++)
        local_vertex[ix].SetMaterial(nmat);
}
void object3d::setMaterialVertexSelected(int nmat)
{
    for(int ix=0; ix < local_vertex.size();ix++)
        if(local_vertex[ix].IsSelected())
            local_vertex[ix].SetMaterial(nmat);
}

void object3d::SetSelected(bool bsel)
{
        m_bselected=bsel;
}

void object3d::SetColor(color ncolor)
{
    int ix=0;

    //m_color.push_back(ncolor);

    //for(ix=0; ix < local_vertex.size();ix++)
    //    local_vertex[ix].SetColor(m_color.size()-1);
    m_maincolor=ncolor;

}
void object3d::SetColor(float r, float g, float b, float a)
{
    color appc(r,g,b,a);

/*    int ix=0;
    if(m_color.size()==0)
        m_color.push_back(appc);
    else
        while(m_color[ix]!=appc && ix++<m_color.size())
            ;
    qDebug() <<"x:" << ix;
    if(ix-1==m_color.size())//non presente
        m_color.push_back(appc);
    for(ix=0; ix < local_vertex.size();ix++)
        local_vertex[ix].SetColor(m_color.size()-1);
  */
    m_maincolor=appc;

}


void object3d::Hide(bool bhide)
{
        m_bhide=bhide;
}


void object3d::DrawLine(int nline)
{
        if(nline >=0 && nline < m_line.size())
        {
                glLineWidth(1.0F);
                int v1,v2;
                v1=m_line[nline].GetVertice(0);
                v2=m_line[nline].GetVertice(1);

                glBegin(GL_LINES);
                        glColor4f(0.0F,0.0F,0.0F,1.0F);
                        if(m_line[nline].IsSelected())
                                glColor4f(0.0F,1.0F,1.0F,1.0F);
                        if(m_bselected)
                            glColor4f(1.0F,0.0F,1.0F,1.0F);
                        local_vertex[v1].Draw();

                        local_vertex[v2].Draw();

                glEnd();


        }
}
void object3d::DrawPoligon4(int index)
{
        poligon4 *pol4=&m_poly4[index];
        int v;


        glBegin(GL_QUADS);


                v=pol4->Get(0);
                local_vertex[v].Draw();

                v=pol4->Get(1);
                local_vertex[v].Draw();

                v=pol4->Get(3);
                local_vertex[v].Draw();

                v=pol4->Get(2);
                local_vertex[v].Draw();

        glEnd();
}
void object3d::DrawPoligon3(int index)
{
        poligon *pol=&m_poly3[index];
        int v;
        if (pol->m_berase)
            return;
        glBegin(GL_TRIANGLES);

                v=pol->Get(0);
                local_vertex[v].Draw();

                v=pol->Get(1);
                local_vertex[v].Draw();

                v=pol->Get(2);
                local_vertex[v].Draw();



        glEnd();
}
void object3d::DrawPoligon4Wireframe(int index)
{
        poligon4 pol4=m_poly4[index];
        int v;

        glBegin(GL_LINES);

                glColor4f(0.0F,0.0F,0.0F,0.5F);




                if(pol4.IsSelected())
                        glColor4f(0.0F,1.0F,1.0F,0.5F);

                v=pol4.Get(0);
                local_vertex[v].Draw();

                v=pol4.Get(1);
                local_vertex[v].Draw();

                v=pol4.Get(1);
                local_vertex[v].Draw();

                v=pol4.Get(3);
                local_vertex[v].Draw();

                v=pol4.Get(3);
                local_vertex[v].Draw();

                v=pol4.Get(2);
                local_vertex[v].Draw();



                v=pol4.Get(2);
                local_vertex[v].Draw();

                v=pol4.Get(0);
                local_vertex[v].Draw();


        glEnd();
}
void object3d::DrawPoligon4(void)
{
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }

        if (m_poly4.size()>0){





                glColor4f(1.0F,1.0F,1.0F,0.5F);
                if(m_bselected)
                    glColor4f(1.0F,0.0F,1.0F,1.0F);
                for (int nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
                {
                   if(m_poly4[nIndex].m_berase)
                        continue;
                    DrawPoligon4(nIndex);
                }


    }



        glPopMatrix();



}
void object3d::DrawPoligon3(void)
{
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }

        if (m_poly3.size()>0){





                glColor4f(1.0F,1.0F,1.0F,0.5F);
                if(m_bselected)
                    glColor4f(1.0F,0.0F,1.0F,1.0F);
                for (int nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
                {
                    if(m_poly3[nIndex].m_berase)
                        continue;

                    DrawPoligon3(nIndex);



                }


    }



        glPopMatrix();



}
void object3d::DrawPoligon4Wireframe(void)
{
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;
        if(!inmove)
        //{
                glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
        //}
        else
        //{
                glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());
        //}



        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        if (m_poly4.size()>0){

                int nNorm=0;



                //glColor4f(1.0F,1.0F,1.0F,0.5F);

                for (int nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
                {
                        if(!m_poly4[nIndex].IsSelected())
                                DrawPoligon4Wireframe(nIndex);



                }

                for (int nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
                {
                        if(m_poly4[nIndex].IsSelected())
                                DrawPoligon4Wireframe(nIndex);



                }


    }



        glPopMatrix();

        DrawVertex(true);

}

void object3d::DrawLines(void)
{
        Init();
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();

        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;


        if(m_idgroup==-1)
        {


            if(!inmove)
                    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());
            else
                    glTranslatef(world_pos_app.GetX()+world_pos.GetX(),world_pos_app.GetY()+world_pos.GetY(),world_pos_app.GetZ()+world_pos.GetZ());


            glRotatef(m_angolo[0],1.0,0.0,0.0);
            glRotatef(m_angolo[1],0.0,1.0,0.0);
            glRotatef(m_angolo[2],0.0,0.0,1.0);
            glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);

        }
        else
        {
            glTranslatef(world_pos_group.GetX(),world_pos_group.GetY(),world_pos_group.GetZ());
            glRotatef(rotate_group.GetX(),1.0,0.0,0.0);
            glRotatef(rotate_group.GetY(),0.0,1.0,0.0);
            glRotatef(rotate_group.GetZ(),0.0,0.0,1.0);
            glScalef(scale_group.GetX(),scale_group.GetY(),scale_group.GetZ());

        }

//        qDebug() << "selected:" << m_bselected;

        if (m_line.size()>0){






                for (int nIndex=0 ; nIndex<m_line.size() ; nIndex++ )
                {
                    if(m_line[nIndex].m_berase)
                        continue;

                    DrawLine(nIndex);



                }


        }
        glPopMatrix();




        DrawVertex(true);

        glEnable(GL_LIGHTING);
}


void object3d::AddLine(int v1, int v2)
{
        line l(v1,v2);
        m_line.push_back(l);
}

void object3d::AddPoligon3(int v1, int v2, int v3)
{

        Q_ASSERT(v1>=0 && v1 < local_vertex.size());
        Q_ASSERT(v2>=0 && v2 < local_vertex.size());
        Q_ASSERT(v3>=0 && v3 < local_vertex.size());

        poligon pol3;
        line mline;

        pol3.Set(v1,v2,v3);
        m_poly3.push_back(pol3);

        if(v1>v2)
                mline.SetLine(v2,v1);
        else
                mline.SetLine(v1,v2);


        m_line.push_back(mline);

        if(v2>v3)
                mline.SetLine(v3,v2);
        else
                mline.SetLine(v2,v3);

        m_line.push_back(mline);

        if(v3>v1)
                mline.SetLine(v1,v3);
        else
                mline.SetLine(v3,v1);


        m_line.push_back(mline);


}
void object3d::AddPoligon(int v1, int v2, int v3, int v4)
{

        Q_ASSERT(v1>=0 && v1 < local_vertex.size());
        Q_ASSERT(v2>=0 && v2 < local_vertex.size());
        Q_ASSERT(v3>=0 && v3 < local_vertex.size());
        Q_ASSERT(v4>=0 && v4 < local_vertex.size());

        poligon pol;
        poligon4 pol4;

        int psize=m_poly.size();

        pol.Set(v1,v2,v3);
        m_poly.push_back(pol);
        pol.Set(v2,v4,v3);
        m_poly.push_back(pol);

        pol4.Set(v1,v2,v3,v4);
        pol4.settriangles(psize,psize+1);

        int nline=m_line.size();

        if(v1>v2)
            m_line.push_back(line(v2,v1));

        else
            m_line.push_back(line(v1,v2));






        if(v2>v4)
            m_line.push_back(line(v4,v2));

        else
            m_line.push_back(line(v2,v4));


        if(v3>v4)
            m_line.push_back(line(v4,v3));

        else
            m_line.push_back(line(v3,v4));


        if(v3>v1)
            m_line.push_back(line(v1,v3));

        else
            m_line.push_back(line(v3,v1));

        pol4.setline(nline,nline+1,nline+2,nline+3);

        m_poly4.push_back(pol4);

        //to-do add and edit poligon4
}




void object3d::RemoveDoubleLines(void)
{
        if (m_line.size()<=0)
                return;

        list<int> ldel;
        for(int ix=0; ix < m_line.size()-1; ix++)
        {
                line mline=m_line[ix];
                for( int iy=ix+1; iy < m_line.size(); iy++)
                {

                    if(mline.GetVertice(0) == m_line[iy].GetVertice(0)&& mline.GetVertice(1) == m_line[iy].GetVertice(1) && !m_line[iy].m_berase)
                    {
                            //m_line.erase(m_line.begin()+iy);
                            m_line[iy].m_berase=true;
                            // ldel.push_back(iy);
                            iy--;
                    }

                }
        }

        assignline();
}
int object3d::findline(int v0, int v1)
{
    int l=-1;
    bool find=false;
    int size=m_line.size();
    for(int ix=0;ix<size && !find;ix++)
    {
        find=(m_line[ix].get(0)==v0 || m_line[ix].get(0)==v1)&&(m_line[ix].get(1)==v0 || m_line[ix].get(1)==v1);

        if(find)
            l=ix;

    }

    return(l);

}
void object3d::assignline(int np)
{

    int v[4];

        v[0]=m_poly4[np].Get(0);
        v[1]=m_poly4[np].Get(1);
        v[2]=m_poly4[np].Get(2);
        v[3]=m_poly4[np].Get(3);

        int pline[4];
        int lapp=-1,i=0;
        for(int ix=0; ix<3; ix++)
            for(int iy=ix+1; iy<4; iy++)
                if((lapp=findline(v[ix],v[iy]))!=-1 && !m_line[lapp].m_berase)//trovata
                    pline[i++]=lapp;

        if(i==4 && lapp!=-1)
            m_poly4[np].setline(pline[0],pline[1],pline[2],pline[3]);



}
void object3d::assignline()
{
    for(int ix=0; ix < m_poly4.size(); ix++)
    {
        assignline(ix);

    }
}
void object3d::finddoublevertex()
{


    map<int,int> vdouble;

    int size=local_vertex.size();
    for (int ix=0; ix<(size-1); ix++)
        for(int iy=ix+1; iy<size;iy++)
            if(local_vertex[ix]==local_vertex[iy] && ix!=iy)
            {
                local_vertex[ix].m_berase=true;
                vdouble.insert(vdouble.begin(),pair<int,int>(ix,iy));

            }

    //scollegare le linee dal primo vertice
    map<int,int>::iterator iv;

    for(iv=vdouble.begin();iv!=vdouble.end();++iv)
    {
        int ix=(*iv).first;
        int ix2=(*iv).second;

        //da ottimizzare

        for(int il=0;il<m_line.size();il++)
        {
            if(m_line[il].get(0)==ix)
                m_line[il].SetLine(ix2,m_line[il].get(1));
            if(m_line[il].get(1)==ix)
                m_line[il].SetLine(m_line[il].get(0),ix2);

        }
        //da ottimizzare
        for(int ip=0;ip<m_poly.size();ip++)
        {
            int point[3];
            for(int iy=0; iy<3;iy++)
            {
                point[iy]=m_poly[ip].Get(iy);

                if(point[iy] == ix)
                {
                    point[iy]=ix2;
                }

            }
            m_poly[ip].Set(point[0],point[1],point[2]);
        }
        //da ottimizzare
        for(int ip=0;ip<m_poly4.size();ip++)
        {
            int point[4];
            for(int iy=0; iy<4;iy++)
            {
                point[iy]=m_poly4[ip].Get(iy);

                if(point[iy]  ==  ix)
                {

                    point[iy] = ix2;


                }

            }

            m_poly4[ip].Set(point[0],point[1],point[2],point[3]);

        }






    }



}

void object3d::SetInvert()
{
        m_binvert=!m_binvert;
}
void object3d::DrawPaint()
{
    int nIndex=0;


    glEnable(GL_LIGHTING);

    glEnable(GL_DEPTH_TEST);

    if(m_binvert)
            glFrontFace(GL_CW);
    else
            glFrontFace(GL_CCW);

    glEnable(GL_CULL_FACE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();


    if (m_angolo[0]>360) m_angolo[0]-=360;
    if (m_angolo[1]>360) m_angolo[1]-=360;
    if (m_angolo[2]>360) m_angolo[2]-=360;

    glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());

    glRotatef(m_angolo[0],1.0,0.0,0.0);
    glRotatef(m_angolo[1],0.0,1.0,0.0);
    glRotatef(m_angolo[2],0.0,0.0,1.0);
    glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);


    float val[4]={1.0F,0.0F,0.0F,1.0F};
    MaterialFace face=front;
    material mat(face,false,val,val,val,val,val);
    val[0]=0.0F;
    material mat2(front,false,val,val,val,val,val);
    if (m_poly4.size()>0){


        glBegin(GL_TRIANGLES);
            for ( nIndex=0 ; nIndex<m_poly.size() ; nIndex++ )
            {
                int V1=m_poly[nIndex].Get(0);
                int V2=m_poly[nIndex].Get(2);
                int V3=m_poly[nIndex].Get(1);

                local_vertex[V1].DrawMaterial(&m_material_vector[local_vertex[V1].GetMaterial()]);
                local_vertex[V2].DrawMaterial(&m_material_vector[local_vertex[V2].GetMaterial()]);
                local_vertex[V3].DrawMaterial(&m_material_vector[local_vertex[V3].GetMaterial()]);

            }
        glEnd();

    }

    if (m_poly3.size()>0){
        glBegin(GL_TRIANGLES);
            for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
            {
                int V1=m_poly3[nIndex].Get(0);
                int V2=m_poly3[nIndex].Get(2);
                int V3=m_poly3[nIndex].Get(1);

                local_vertex[V1].DrawMaterial(&m_material_vector[local_vertex[V1].GetMaterial()]);
                local_vertex[V2].DrawMaterial(&m_material_vector[local_vertex[V2].GetMaterial()]);
                local_vertex[V3].DrawMaterial(&m_material_vector[local_vertex[V3].GetMaterial()]);

            }
        glEnd();

    }

    if(m_line.size()>0)
    {
        glBegin(GL_LINES);

        glLineWidth(2.0F);

        for ( nIndex=0 ; nIndex<m_line.size() ; nIndex++ )
        {
            int v1=m_line[nIndex].GetVertice(0);
            int v2=m_line[nIndex].GetVertice(1);
            if(local_vertex[v1].IsSelected())
                local_vertex[v1].DrawMaterial(&mat);
            else
                local_vertex[v1].DrawMaterial(&mat2);

            if(local_vertex[v2].IsSelected())
                local_vertex[v2].DrawMaterial(&mat);
            else
                local_vertex[v2].DrawMaterial(&mat2);



       }
       glEnd();

       glLineWidth(1.0F);

    }

    glPointSize(5.0F);



    for(int ip=0; ip < local_vertex.size(); ip++)
    {
        glBegin(GL_POINTS);

            if(local_vertex[ip].IsSelected())
                local_vertex[ip].DrawMaterial(&mat);
            else
                local_vertex[ip].DrawMaterial(&mat2);


        glEnd();



    }



    glPointSize(1.0F);


    glPopMatrix();





}

void object3d::DrawEditMode(SCENE::ModeEdit edit)
{

        int nIndex=0;


        glEnable(GL_DEPTH_TEST);

        if(m_binvert)
                glFrontFace(GL_CW);
        else
                glFrontFace(GL_CCW);

        glEnable(GL_CULL_FACE);
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();


        if (m_angolo[0]>360) m_angolo[0]-=360;
        if (m_angolo[1]>360) m_angolo[1]-=360;
        if (m_angolo[2]>360) m_angolo[2]-=360;

        glTranslatef(world_pos.GetX(),world_pos.GetY(),world_pos.GetZ());

        glRotatef(m_angolo[0],1.0,0.0,0.0);
        glRotatef(m_angolo[1],0.0,1.0,0.0);
        glRotatef(m_angolo[2],0.0,0.0,1.0);
        glScalef(m_Scale[0],m_Scale[1],m_Scale[2]);


        if (m_poly4.size()>0){


                                //glBegin(GL_QUADS);



                                for ( nIndex=0 ; nIndex<m_poly4.size() ; nIndex++ )
                                {
                                    if( m_poly4[nIndex].m_berase)
                                        continue;

                                        int V1=m_poly4[nIndex].Get(0);

                                        int V2=m_poly4[nIndex].Get(2);

                                        int V3=m_poly4[nIndex].Get(3);

                                        int V4=m_poly4[nIndex].Get(1);


                                        glColor4f(0.0F,1.0F,0.5F,1.0F);

                                        if (m_poly4[nIndex].IsSelected())
                                                glColor4f(0.0F,0.5F,1.0F,1.0F);
                                        else
                                                glColor4f(0.0F,0.5F,0.5F,1.0F);


                                        if(m_poly4[nIndex].IsSelected())
                                        {
                                                glPushMatrix();

                                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                                glBegin(GL_QUADS);

                                                local_vertex[V1].Draw();
                                                local_vertex[V2].Draw();
                                                local_vertex[V3].Draw();
                                                local_vertex[V4].Draw();

                                                glEnd();
                                                glPopMatrix();
                                        }else

                                        {
                                                glBegin(GL_QUADS);

                                                local_vertex[V1].Draw();
                                                local_vertex[V2].Draw();
                                                local_vertex[V3].Draw();
                                                local_vertex[V4].Draw();

                                                glEnd();
                                        }


                                }

                                /*
                                glLineWidth(2.0F);



                                glColor4f(0.0F,0.0F,0.0F,1.0F);

                                for ( nIndex=0 ; nIndex<m_line.size() ; nIndex++ )
                                {
                                        int v1=m_line[nIndex].GetVertice(0);
                                        int v2=m_line[nIndex].GetVertice(1);

                                        if(m_line[nIndex].IsSelected())
                                        {
                                                glPushMatrix();

                                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                                glBegin(GL_LINES);

                                                local_vertex[v1].Draw();
                                                local_vertex[v2].Draw();

                                                glEnd();

                                                glPopMatrix();


                                        }
                                        else
                                        {
                                                glBegin(GL_LINES);

                                                local_vertex[v1].Draw();
                                                local_vertex[v2].Draw();

                                                glEnd();
                                        }
                                        */


                                        /*glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());
                                        glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());
                                        glEnd();

                                        glBegin(GL_LINES);
                                        glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());
                                        glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());
                                        glEnd();

                                        glBegin(GL_LINES);
                                        glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());
                                        glVertex3f(local_vertex[V4].GetX(),local_vertex[V4].GetY(),local_vertex[V4].GetZ());
                                        glEnd();

                                        glBegin(GL_LINES);
                                        glVertex3f(local_vertex[V4].GetX(),local_vertex[V4].GetY(),local_vertex[V4].GetZ());
                                        glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());
                                        glEnd();


                                        */

                                //}
                                //glEnd();

                                //glLineWidth(1.0F);






        }

        if (m_poly3.size()>0){


                                glBegin(GL_TRIANGLES);



                                for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
                                {
                                    if( m_poly3[nIndex].m_berase)
                                        continue;

                                        int V1=m_poly3[nIndex].Get(0);

                                        int V2=m_poly3[nIndex].Get(2);

                                        int V3=m_poly3[nIndex].Get(1);




                                        glColor4f(0.0F,1.0F,0.5F,1.0F);
                                        if (m_poly3[nIndex].isSelected())
                                                glColor4f(0.0F,0.5F,1.0F,1.0F);
                                        else
                                                glColor4f(0.0F,0.5F,0.5F,1.0F);


                                        if(local_vertex[V1].IsSelected())
                                        {
                                                glPushMatrix();

                                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                                glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());

                                                glPopMatrix();
                                        }
                                        else
                                                glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());

                                        if(local_vertex[V2].IsSelected())
                                        {
                                                glPushMatrix();

                                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                                glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());

                                                glPopMatrix();
                                        }
                                        else
                                                glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());

                                        if(local_vertex[V3].IsSelected())
                                        {
                                                glPushMatrix();

                                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                                glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());

                                                glPopMatrix();
                                        }
                                        else
                                                glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());

//					glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());
//					glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());
//					glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());





                                }
                                glEnd();
                                /*
                                glLineWidth(2.0F);


                                glBegin(GL_LINES);

                                glColor4f(0.0F,0.0F,0.0F,1.0F);

                                for ( nIndex=0 ; nIndex<m_poly3.size() ; nIndex++ )
                                {

                                        int V1=m_poly3[nIndex].Get(0);

                                        int V2=m_poly3[nIndex].Get(1);

                                        int V3=m_poly3[nIndex].Get(2);






                                        glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());
                                        glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());

                                        glVertex3f(local_vertex[V2].GetX(),local_vertex[V2].GetY(),local_vertex[V2].GetZ());
                                        glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());

                                        glVertex3f(local_vertex[V3].GetX(),local_vertex[V3].GetY(),local_vertex[V3].GetZ());
                                        glVertex3f(local_vertex[V1].GetX(),local_vertex[V1].GetY(),local_vertex[V1].GetZ());






                                }
                                glEnd();
                    */



        }

        if(m_line.size()>0)
        {
            glLineWidth(2.0F);



            for ( nIndex=0 ; nIndex<m_line.size() ; nIndex++ )
            {
                if( m_line[nIndex].m_berase)
                    continue;

                    int v1=m_line[nIndex].GetVertice(0);
                    int v2=m_line[nIndex].GetVertice(1);

                    if(m_line[nIndex].IsSelected())
                        glColor4f(0.0F,1.0F,0.5F,1.0F);
                    else
                        glColor4f(0.0F,0.0F,0.0F,1.0F);


                    if(m_line[nIndex].IsSelected() )
                    {
                            glPushMatrix();

                                glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                                glBegin(GL_LINES);

                                    local_vertex[v1].Draw();
                                    local_vertex[v2].Draw();

                                glEnd();

                            glPopMatrix();


                    }
                    else
                    {
                            glBegin(GL_LINES);

                                local_vertex[v1].Draw();
                                local_vertex[v2].Draw();

                            glEnd();
                    }


           }


            glLineWidth(1.0F);

        }

        glPointSize(5.0F);




        glColor4f(1.0F,1.0F,0.0F,1.0F);

        for(int ip=0; ip < local_vertex.size(); ip++)
        {
            if( local_vertex[ip].m_berase)
                continue;

                if(local_vertex[ip].IsSelected())
                {

                    glPushMatrix();

                    glScalef(m_ScaleVertex[0],m_ScaleVertex[1],m_ScaleVertex[2]);

                    glBegin(GL_POINTS);

                       local_vertex[ip].Draw(1.0F,1.0F,0.0F);

                            //glVertex3f(local_vertex[ip].GetX(),local_vertex[ip].GetY(),local_vertex[ip].GetZ());
                    glEnd();

                    glPopMatrix();
                }
                else
                {
                        glBegin(GL_POINTS);

                            local_vertex[ip].Draw(1.0F,1.0F,0.0F);

                        glEnd();
                }


        }



        glPointSize(1.0F);


        glPopMatrix();

        glEnable(GL_LIGHTING);




}


void object3d::Init(void)
{
        glEnable(GL_DEPTH_TEST);

        glFrontFace(GL_CCW);

        glEnable(GL_CULL_FACE);

        static GLfloat wt=0.0F;

        glEnable(GL_LIGHTING);
        //glUseProgram(0);

        /*
        if(m_shaderprogram!=NULL)
        {
                m_shaderprogram->use();
                m_shaderprogram->pipe();
                //m_shaderprogram->add_value(0,(void*)&wt);
                wt+=0.002F;
                if(wt>100.0F)
                        wt=0.0F;
        }
        */
}


void object3d::SetShaders(void)
{
        //char *vs,*fs,*fs2;

        /*
        v = glCreateShader(GL_VERTEX_SHADER);
        f = glCreateShader(GL_FRAGMENT_SHADER);
        f2 = glCreateShader(GL_FRAGMENT_SHADER);


        vs = Cshader::textFileRead2("toon.vert");
        fs = Cshader::textFileRead2("toon.frag");
        fs2 = Cshader::textFileRead2("toon2.frag");

        const char * ff = fs;
        const char * ff2 = fs2;
        const char * vv = vs;

        glShaderSource(v, 1, &vv,NULL);
        glShaderSource(f, 1, &ff,NULL);
        glShaderSource(f2, 1, &ff2,NULL);

        free(vs);free(fs);

        glCompileShader(v);
        glCompileShader(f);
        glCompileShader(f2);

        p = glCreateProgramObjectARB();
        glAttachShader(p,f);
        glAttachShader(p,f2);
        glAttachShader(p,v);

        glLinkProgram(p);
        glUseProgram(p);
        */
    /*
        char *vs = NULL,*fs = NULL ,*fs2 = NULL;
        Cshader* v;
        Cshader* f;
        Cshader* f2;

        v= new Cshader(ShaderType::svertex);
        f= new Cshader(ShaderType::fragment);
        f2= new Cshader(ShaderType::fragment);

        //toon.vert");
        //fs = textFileRead("toon.frag");
        //fs2 = textFileRead("toon2.frag"
        v->textFileRead("shaders/bluewave.vert");
        //f->textFileRead("shaders/brick.frag");
        //f2->textFileRead("toon2.frag");

        v->create();
        //f->create();
//	f2->create();

        v->compile();
        //f->compile();
//	f2->compile();

        m_shaderprogram= new Cshaderprogram();
        m_shaderprogram->create();

        m_shaderprogram->AttachShader(v->getid());
        //m_shaderprogram->AttachShader(f->getid());
//	m_shaderprogram.AttachShader(f2->getid());

        m_shaderprogram->link();



        m_shaderprogram->init();
*/
}


void object3d::InitOff(void)
{
        //if(m_shaderprogram!=NULL)
          //      m_shaderprogram->unuse();
}
void object3d::usecolor(int ncolor)
{
  /*  if(ncolor<0 || ncolor>m_color.size())
        return;
    for(int ix=0; ix < local_vertex.size();ix++)
        local_vertex[ix].SetColor(ncolor);*/
}

void object3d::setName(string pname,string psubname)
{
    name=pname;
    subname=psubname;

}
string object3d::getname()
{
    return name;

}
string object3d::getsubname()
{
    return subname;

}
material * object3d::getmaterial()
{
    if(m_material_vector.size()>=1)
        return &m_material_vector[0];
    else
        return NULL;
}
void object3d::addMaterial(material value)
{
    m_material_vector.push_back(value);
}
void object3d::delMaterials()
{
    m_material_vector.clear();
}
void object3d::delMaterials(int index)
{
    if(index>=0 && index < m_material_vector.size())
        ;
        //m_material_vector.erase(index);
    for(int ix=0; ix < local_vertex.size();ix++)
        if(local_vertex[ix].GetMaterial()==index)
            local_vertex[ix].SetMaterial(0);
}
material *object3d::getmaterial(int index)
{
    if (index>=0 && index < m_material_vector.size())
        return (&m_material_vector[index]);
    else
        return NULL;
}
int object3d::getiMaterial()
{
    return(m_material_vector.size());
}

material *object3d::getmaterialvector(int index)
{
    if (index>=0 && index < m_material_vector.size())
        return NULL;
    else
        return (&m_material_vector[index]);
}

void object3d::invertface()
{
    int size=m_poly4.size();

    for(int ix=0; ix < size; ix++)
        if(m_poly4[ix].selected())
        {

            m_poly4[ix].invertdraw();

            int t1,t2;
            t1=m_poly4[ix].gettriangle(0);
            t2=m_poly4[ix].gettriangle(1);

            m_poly[t1].invertdraw();
            m_poly[t2].invertdraw();


        }
}

void object3d::extrude()
{

}

void object3d::extrudevertex()
{
    std::list<int> vadded;
    std::list<int>::iterator it;
    int nsize=local_vertex.size();
    for(int ix=0; ix<local_vertex.size();ix++)
        if(local_vertex[ix].selected())
        {
            vadded.push_back(nsize++);
            extrudevertex(ix);
        }

    for(it=vadded.begin();it!=vadded.end();++it)
    {
        local_vertex[(*it)].selected(true);
    }

}

void object3d::extrudevertex(int v)
{
    vertex appv=local_vertex[v];
    local_vertex[v].selected(false);

    local_vertex.push_back(appv);
    int nsize=local_vertex.size()-1;
    local_vertex[nsize].selected(false);

    AddLine(v,nsize);



}
bool object3d::islinealone(int value)
{
    bool fl=false;

    int ix=0;
    while(!fl && ix<m_line[value].nextsize() )
        fl=m_line[m_line[value].getnext(ix++)].selected();
    ix=0;
    while(!fl && ix<m_line[value].prevsize() )
        fl=m_line[m_line[value].getprev(ix++)].selected();

    return (!fl);

}
bool object3d::islinealonesin(int value)
{
    bool fls=false,fld=false;

    int ix=0;

    while(!fld && ix<m_line[value].nextsize() )
        fld=m_line[m_line[value].getnext(ix++)].selected();
    ix=0;

    while(!fls && ix<m_line[value].prevsize() )
        fls=m_line[m_line[value].getprev(ix++)].selected();

    if(!fls && fld)
        return(true);
    else
        return (false);

}
bool object3d::islinealonedes(int value)
{
    bool fls=false,fld=false;

    int ix=0;

    while(!fld && ix<m_line[value].nextsize() )
        fld=m_line[m_line[value].getnext(ix++)].selected();

    ix=0;

    while(!fls && ix<m_line[value].prevsize() )
        fls=m_line[m_line[value].getprev(ix++)].selected();

    if(fls && !fld)
        return(true);
    else
        return (false);

}
bool object3d::islineall()
{
    bool fl=true;

    int ix=0;

    while(fl && ix<m_line.size() )
        fl=m_line[ix++].selected();

    return (fl);

}
void object3d::extrudelineind()
{
    int lsize=m_line.size();
    for(int ix=0; ix<lsize;ix++)
    {
        if(m_line[ix].selected())
            extrudeline(ix);

    }


}

void object3d::extrudeline()
{
    std::list<int> ladded;
    std::list<int> lper;
    std::list<int>::iterator it;
    int nsize=m_line.size()+2;
    int lsize=m_line.size();

    makeindex();

    if(islineall())
    {

        lper.clear();

        for(int ix=0; ix<lsize;ix++)
        {
            m_line[ix].selected(false);

            lper.push_back(ix);


        }
        extrudeline(lper);

        return;


    }

    for(int ix=0; ix<lsize;ix++)
    {
        if(m_line[ix].selected())
        {
            //verificare se la linea è singola

            if(islinealone(ix))
            {

                ladded.push_back(nsize);
                nsize+=4;
                extrudeline(ix);

            }
            else if ( islinealonesin(ix) || islinealonedes(ix))
            {


                lper.clear();

                lper.push_back(ix);

                m_line[ix].selected(false);


                bool fl=false,fl2=false,endline;

                int in=0,in2,iy;

                iy=ix;
                endline=false;
                do
                {
                    fl=false;
                    fl2=false;
                    in=0;

                    while(!fl && in< m_line[iy].nextsize())
                        fl=m_line[m_line[iy].getnext(in++)].selected();

                    in2=0;

                    while(!fl2 && in2< m_line[iy].prevsize())
                        fl2=m_line[m_line[iy].getprev(in2++)].selected();


                    if(fl || fl2)
                    {
                        if(fl)
                        {
                            lper.push_back(m_line[iy].getnext(in-1));

                        //  m_line[m_line[iy].getnext(in-1)].selected(false);

                            iy=m_line[iy].getnext(in-1);
                        }
                        if(fl2)
                        {
                            lper.push_back(m_line[iy].getprev(in2-1));

                          //  m_line[m_line[iy].getprev(in2-1)].selected(false);

                            iy=m_line[iy].getprev(in2-1);


                        }


                        in=0;

                        fl=false;

                        while(!fl && in<m_line[iy].nextsize())
                            fl=m_line[m_line[iy].getnext(in++)].selected();

                        in2=0;

                        fl2=false;

                        while(!fl2 && in2< m_line[iy].prevsize())
                            fl2=m_line[m_line[iy].getprev(in2++)].selected();

                        if(!fl && !fl2)

                            endline=true;

                        m_line[iy].selected(false);


                    }



                }while(!endline);



                extrudeline(lper);

            }


        }

    }
    for(it=ladded.begin();it!=ladded.end();++it)
    {
        m_line[(*it)].selected(true);
        local_vertex[m_line[(*it)].GetVertice(0)].selected(true);
        local_vertex[m_line[(*it)].GetVertice(1)].selected(true);
    }
}

void object3d::extrudeline(std::list<int> l)
{
    //prelevo i vertici dalla lista
    std::list<int>::iterator il;

    std::vector<int> vertici;
    std::vector<int>::iterator iv;
    int v1,v2;
    for(il=l.begin();il!=l.end();++il)
    {

        v1=m_line[(*il)].GetVertice(0);
        v2=m_line[(*il)].GetVertice(1);

        if(vertici.size()==0)
        {
            vertici.push_back(v1);
            vertici.push_back(v2);
        }
        else if(v1==vertici[vertici.size()-1])
            vertici.push_back(v2);
        else if(v1==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v2);
        }

        else if(v2==vertici[vertici.size()-1])
            vertici.push_back(v1);

        else if(v2==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v1);
        }



    }
    int vsize=local_vertex.size();

    for(iv=vertici.begin(); iv != vertici.end(); ++iv)
    {
        vertex appv=local_vertex[(*iv)];
        appv.selected(true);
        local_vertex[(*iv)].selected(false);
        local_vertex.push_back(appv);
    }
    int iy=0;
    int lsize=m_line.size()+2;
    for(int ix=vsize; ix < local_vertex.size()-1; ix++)
    {
        AddPoligon(vertici[iy],vertici[iy+1],ix,ix+1);
        m_line[lsize].selected(true);
        lsize+=4;

        iy++;
    }





}

void object3d::extrudeline(int l)
{
    int v1,v2,i1,i2;

    vertex app1,app2;

    v1=m_line[l].GetVertice(0);
    v2=m_line[l].GetVertice(1);

    m_line[l].selected(false);

    local_vertex[v1].selected(false);
    local_vertex[v2].selected(false);

    app1=local_vertex[v1];
    app2=local_vertex[v2];


    i1=local_vertex.size();
    local_vertex.push_back(app1);
    local_vertex[i1].selected(false);
    i2=local_vertex.size();
    local_vertex.push_back(app2);
    local_vertex[i2].selected(false);

    //int nl=m_line.size();
    //AddLine(i1,i2);
    //m_line[nl].selected(false);
    //nl=m_line.size();
    //AddLine(i1,v1);
    //m_line[nl].selected(false);
    //nl=m_line.size();
    //AddLine(i2,v2);
    //m_line[nl].selected(false);

    //controllare il verso

    int ip=m_poly4.size();
    int nl=m_line.size();
    AddPoligon(v1,v2,i1,i2);

    m_poly4[ip].setline(nl,nl+1,nl+2,nl+3);

    //RemoveDoubleLines();











}

void object3d::extrudeface()
{

}

void object3d::extrudeface(int value)
{

}

void object3d::makeindex()
{

    if(local_vertex.size()==0)
        return;


    int lsize=m_line.size();

    if (lsize==0)
        return;

    for(int ix=0; ix < lsize;ix++)
    {
        if(!m_line[ix].selected())
            continue;
        m_line[ix].clear_np();

        int ivert=m_line[ix].GetVertice(0);
        int ivert1=m_line[ix].GetVertice(1);



        for(int iy=0; iy < lsize; iy++)
        {
            int v1,v2;

            v1=m_line[iy].GetVertice(0);
            v2=m_line[iy].GetVertice(1);

            if(iy!=ix && (v1==ivert || v2==ivert  || v1==ivert1  || v2==ivert1))
            {


                if(v1==ivert || v2==ivert)
                    m_line[ix].addprev(iy);

                if(v1==ivert1 || v2==ivert1)
                    m_line[ix].addnext(iy);


           }

        }
    }
    if (m_poly4.size()==0)
        return;
    int psize=m_poly4.size();

    for(int ix=0; ix < psize ;ix++)
    {
        if(!m_poly4[ix].selected())
            continue;
        m_poly4[ix].clearlist();

        int v1,v2,v3,v4;

        v1=m_poly4[ix].Get(0);
        v2=m_poly4[ix].Get(1);
        v3=m_poly4[ix].Get(2);
        v4=m_poly4[ix].Get(3);

        //v1-v3 sinistra
        for(int iy=0; iy < psize; iy++)
        {
            int pv1,pv2,pv3,pv4;

            pv1=m_poly4[iy].Get(0);
            pv2=m_poly4[iy].Get(1);
            pv3=m_poly4[iy].Get(2);
            pv4=m_poly4[iy].Get(3);



            if(ix!=iy)
            {
                //v1-v3 sinistra
                if(pv2==v1 && pv4==v3)
                    m_poly4[ix].addsin(iy);
                //v1-v2 down
                if(pv3==v1 && pv4==v2)
                    m_poly4[ix].adddown(iy);

                //v2-v4 des
                if(pv1==v2 && pv3==v4)
                    m_poly4[ix].adddes(iy);

                //v3-v4 up
                if(pv1==v3 && pv2==v4)
                    m_poly4[ix].addup(iy);



            }



        }







    }

}
void object3d::addvertexgroup(string name)
{
    if(local_vertex.empty())
        return;

    list<int> vlist;


    for(int ix=0; ix < local_vertex.size();ix++)
        if(local_vertex[ix].selected())
            vlist.push_back(ix);


    vertexgroup vg(name,m_vgroup.size(),vlist);

    vlist.clear();
    for(int ix=0; ix < m_line.size();ix++)
        if(m_line[ix].selected())
          vlist.push_back(ix);
    vg.setline(vlist);

    vlist.clear();
    for(int ix=0; ix < m_poly4.size();ix++)
        if(m_poly4[ix].selected())
          vlist.push_back(ix);
    vg.setpoly(vlist);

    m_vgroup.push_back(vg);

    if(m_vgroup.size()==1)
        m_ivgroup=0;
    else
        m_ivgroup=m_vgroup.size()-1;

}
void object3d::remvertexgroup(int i)
{
    if(i>=0 && i<m_vgroup.size())
    {
        m_vgroup.erase(m_vgroup.begin()+i);
    }
}
void object3d::unselectall()
{
    int nSize=local_vertex.size();
    for (int nIndex=0; nIndex < nSize ; nIndex++)
    {
            local_vertex[nIndex].SetSelected(false);
    }

    nSize=m_line.size();
    for (int nIndex=0; nIndex < nSize ; nIndex++)
    {
        m_line[nIndex].selected(false);
    }
    nSize=m_poly3.size();
    for (int nIndex=0; nIndex < nSize ; nIndex++)
    {
        m_poly3[nIndex].selected(false);
    }

    nSize=m_poly4.size();
    for (int nIndex=0; nIndex < nSize ; nIndex++)
    {
        m_poly4[nIndex].selected(false);
    }
}

void object3d::selectvertexgroup(int g)
{
    if(g>=0 && g<m_vgroup.size())
    {
        unselectall();
        if(g==0)
            g=m_ivgroup;
        list<int> l=m_vgroup[g].getlist();
        list<int>::iterator il;

        for(il=l.begin();il!=l.end();++il)
            local_vertex[(*il)].selected(true);

        l=m_vgroup[g].getlist_line();

        for(il=l.begin();il!=l.end();++il)
            m_line[(*il)].selected(true);

        l=m_vgroup[g].getlist_poly();

         for(il=l.begin();il!=l.end();++il)
            m_poly4[(*il)].selected(true);

    }
}
void object3d::vertexgroup_prev()
{
    if(m_ivgroup-1>=0)
        m_ivgroup--;

}

void object3d::vertexgroup_next()
{
    if(m_ivgroup+1<m_vgroup.size())
        m_ivgroup++;
}
string object3d::getgvname()
{
    return(m_vgroup[m_ivgroup].getname());
}
void object3d::vertexgroup_set()
{
    if(local_vertex.empty())
        return;

    list<int> vlist;


    for(int ix=0; ix < local_vertex.size();ix++)
        if(local_vertex[ix].selected())
            vlist.push_back(ix);

    m_vgroup[m_ivgroup].set(vlist);

    vlist.clear();
    for(int ix=0; ix < m_line.size();ix++)
        if(m_line[ix].selected())
          vlist.push_back(ix);

    m_vgroup[m_ivgroup].setline(vlist);

    vlist.clear();
    for(int ix=0; ix < m_poly4.size();ix++)
        if(m_poly4[ix].selected())
          vlist.push_back(ix);

    m_vgroup[m_ivgroup].setpoly(vlist);






}
void object3d::subdivideplane()
{

    for(int ix=0; ix < m_poly4.size(); ix++)
    {
        if(m_poly4[ix].selected())
        {
            vertex v;
            int vi[4];
            int vstart=local_vertex.size();

            for(int iv=0; iv<4;iv++)
                vi[iv]=m_poly4[ix].Get(iv);

            //vstart
            v=local_vertex[vi[0]];
            v+=local_vertex[vi[1]];

            v/=2.0F;
            local_vertex.push_back(v);

            //vstart+1
            v=local_vertex[vi[1]];
            v+=local_vertex[vi[3]];

            v/=2.0F;
            local_vertex.push_back(v);

            //vstart+2
            v=local_vertex[vi[2]];
            v+=local_vertex[vi[3]];

            v/=2.0F;
            local_vertex.push_back(v);

            //vstart+3
            v=local_vertex[vi[0]];
            v+=local_vertex[vi[2]];

            v/=2.0F;
            local_vertex.push_back(v);

            //vstart+4
            v=local_vertex[vi[0]];
            v+=local_vertex[vi[1]];
            v+=local_vertex[vi[2]];
            v+=local_vertex[vi[3]];

            v/=4.0F;

            local_vertex.push_back(v);

            AddPoligon(vi[0],vstart,vstart+3,vstart+4);
            AddPoligon(vstart,vi[1],vstart+4,vstart+1);
            AddPoligon(vstart+3,vstart+4,vi[2],vstart+2);
            AddPoligon(vstart+4,vstart+1,vstart+2,vi[3]);

            m_poly4.erase(m_poly4.begin()+ix);
            ix=0;

        }

    }

}

void object3d::subdivideline()
{
    for(int il=0; il <m_line.size();il++)
    {
        if(m_line[il].selected())
        {
            vertex appv;
            int v1,v2,vn;
            v1=m_line[il].get(0);
            v2=m_line[il].get(1);
            vn=local_vertex.size();

            appv=local_vertex[v1];

            appv+=local_vertex[v2];

            appv.SetX(appv.GetX()/2.0F);
            appv.SetY(appv.GetY()/2.0F);
            appv.SetZ(appv.GetZ()/2.0F);

            local_vertex.push_back(appv);

            line l1,l2;

            l1.SetLine(v1,vn);
            l2.SetLine(v2,vn);
            int pl1,pl2,pl3,pl4;
            for(int ip=0; ip<m_poly4.size();ip++)
            {
                pl1=m_poly4[ip].getline(0);
                pl2=m_poly4[ip].getline(1);
                pl3=m_poly4[ip].getline(2);
                pl4=m_poly4[ip].getline(3);

                if(pl1>il)
                    pl1--;
                if(pl2>il)
                    pl2--;
                if(pl3>il)
                    pl3--;
                if(pl4>il)
                    pl4--;

                m_poly4[ip].setline(pl1,pl2,pl3,pl4);



            }



            m_line.erase(m_line.begin()+il);

            m_line.push_back(l1);
            m_line.push_back(l2);



        }

    }
}
void object3d::addpolygonN(int npoly, int v)
{
    if(npoly>=0 && npoly<m_polyn.size() && v>=0 && v<local_vertex.size())
    {
        m_polyn[npoly].add(v);

    }
}
void object3d::addpolygonN(poligonN p)
{
    m_polyn.push_back(p);

}
poligonN * object3d::get(int i)
{
    if(i>=0 && i<m_polyn.size())
        return(&m_polyn[i]);
    else
        return NULL;
}
bool object3d::islinepoly4(int nl, int np)
{
    bool fl=false;
    //si assume che la linea sia contenuta ne poligono np

    int size=m_poly4.size();

    for(int ix=0; ix < size && !fl; ix++ )
    {
        if(ix!=np && !m_poly4[ix].m_berase)
        {
            fl=(m_poly4[ix].getline(0)==nl ||m_poly4[ix].getline(1)==nl ||m_poly4[ix].getline(2)==nl||m_poly4[ix].getline(3)==nl);

        }
    }
    return(!fl);


}
void object3d::remline(int nl)
{
    if (nl>=0 && nl<m_line.size())
    {
        m_line.erase(m_line.begin()+nl);
        assignline();
    }
}
void object3d::rempoly4(int np)
{
    int vi[4];
    int li[4];
    if(np<0 ||np >=m_poly4.size())
        return;
    for(int iv=0; iv<4;iv++)
    {
        vi[iv]=m_poly4[np].Get(iv);
        li[iv]=m_poly4[np].getline(iv);
        if(islinepoly4(li[iv],np))
            m_line[li[iv]].m_berase=true;

    }

    //

    if(m_poly4[np].gettriangle(0)!=-1)
        m_poly[m_poly4[np].gettriangle(0)].m_berase=true;
    if(m_poly4[np].gettriangle(1)!=-1)
        m_poly[m_poly4[np].gettriangle(1)].m_berase=true;



    //ricreare le linee eliminate mancanti

    m_poly4[np].m_berase=true;
    m_poly4[np].selected(false);


}
void object3d::makeline(int np)
{
    line appline[4];

    if(np<0 || np<m_poly4.size())
        return;

    int l[4],v[4],nl=0;

    for(int il=0; il < 4; il++)
    {

        l[il]=m_poly4[np].getline(il);
        v[il]=m_poly4[np].Get(il);
        if(l[il]==-1)
            nl++;

    }
    //
    //0---1
    //|   |
    //2---3
    //

    appline[0].SetLine(v[0],v[1]);
    appline[1].SetLine(v[2],v[3]);
    appline[2].SetLine(v[0],v[2]);
    appline[3].SetLine(v[1],v[3]);

    for(int il=0; il < 4; il++)
    {
        if(l[il]==-1)
        {

            l[il]=m_line.size();
            m_line.push_back(appline[il]);

        }

    }

    m_poly4[np].Set(l[0],l[1],l[2],l[3]);

}


void object3d::addlinetoremove(int il)
{
    _line_rem.push_back(il);
}

void object3d::remlinefromlist()
{
    list<int>::iterator il,il1;
    int ix=0;
    for(il=_line_rem.begin(); il!=_line_rem.end();++il,ix++)
    {
        int appi=(*il);
        m_line.erase(m_line.begin()+(*il));
        for(il1=il;il1!=_line_rem.end();++il1)
        {
            int appl=(*il1);
            if(appl>appi)
            {
                _line_rem.erase(il1);
                _line_rem.push_back(appl-1);
            }

        }
    }
    _line_rem.clear();
}
void object3d::purge()
{
    RemoveDoubleLines();
   /* for(int ix=0; ix < local_vertex.size(); ix++)
        if(local_vertex[ix].m_berase)
        {
            deleteeditvertex(ix);
        }
    */
}
void object3d::deleteeditvertex()
{
    for(int ix=0; ix < local_vertex.size(); ix++)
        if(local_vertex[ix].IsSelected())
        {
            deleteeditvertex(ix);
        }
}
void object3d::deleteeditvertex(int v)
{

    Q_ASSERT(v >= 0 && v <local_vertex.size());

    int ix=v;

    local_vertex.erase(local_vertex.begin()+v);
    for(int ip=0; ip <m_poly.size(); ip++)
    {
            if(m_poly[ip].lista_vertici[0]==ix ||m_poly[ip].lista_vertici[1]==ix || m_poly[ip].lista_vertici[2]==ix)
            {
                   m_poly.erase(m_poly.begin()+ip);
                    ip--;
            }
    }
    for(int ip=0; ip < m_poly4.size(); ip++)
    {
            if(m_poly4[ip].Present(ix))
            {
                   m_poly4.erase(m_poly4.begin()+ip);
                    ip--;
            }
    }
    for(int ip=0; ip < m_line.size(); ip++)
    {
            if(m_line[ip].GetVertice(0)==ix ||m_line[ip].GetVertice(1)==ix)
            {
                   m_line.erase(m_line.begin()+ip);
                    ip--;
            }

    }

    for(int ip=0; ip < m_poly.size(); ip++)
    {
            if(m_poly[ip].lista_vertici[0]>ix)
                    m_poly[ip].lista_vertici[0]-=1;
            if(m_poly[ip].lista_vertici[1]>ix)
                   m_poly[ip].lista_vertici[1]-=1;
            if(m_poly[ip].lista_vertici[2]>ix)
                    m_poly[ip].lista_vertici[2]-=1;

    }
    for(int ip=0; ip < m_poly4.size(); ip++)
    {
            int v[4];
            v[0]=m_poly4[ip].Get(0);
            v[1]=m_poly4[ip].Get(1);
            v[2]=m_poly4[ip].Get(2);
            v[3]=m_poly4[ip].Get(3);

            if(v[0]>ix)
                    v[0]-=1;
            if(v[1]>ix)
                    v[1]-=1;
            if(v[2]>ix)
                    v[2]-=1;
            if(v[3]>ix)
                    v[3]-=1;

            m_poly4[ip].Set(v[0],v[1],v[2],v[3]);

    }
    for(int ip=0; ip <m_line.size(); ip++)
    {
            int l1,l2;

            l1=m_line[ip].GetVertice(0);
            l2=m_line[ip].GetVertice(1);

            if(l1>ix)
                    l1--;
            if(l2>ix)
                    l2--;

            m_line[ip].SetLine(l1,l2);


    }
}
void object3d::makevbo()
{
    if(m_vbo==NULL)
        m_vbo=new objectVBO();
    else
        return;

    m_vbo->createbuffer(local_vertex);
    m_vbo->createnormalbuffer(local_vertex);
    m_vbo->creatematerialbuffer(local_vertex);
    //m_vbo->createindex(m_poly);
    m_vbo->createlinebuffer(m_line);
    m_vbo->createpoly3buffer(m_poly,m_poly3);
    m_vbo->initbuffer_onlyvertex();
    m_vbo->initbuffer_normals();
    m_vbo->initbuffer_wireframe();
    m_vbo->initbuffer_solid();
    m_vbo->initbuffer_material();

    local_vertex.clear();
    m_line.clear();
    m_poly.clear();
    m_poly3.clear();
    m_poly4.clear();
}
void object3d::DrawVBO(SCENE::ModeDraw md)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
//f (m_b2D)
    //	glDisable(GL_CULL_FACE);
    if ( m_angolo[0]>360) m_angolo[0]-=360;
    if ( m_angolo[1]>360)  m_angolo[1]-=360;
    if ( m_angolo[2]>360)  m_angolo[2]-=360;
    if(! inmove)
    //{
            glTranslatef( world_pos.GetX(), world_pos.GetY(), world_pos.GetZ());
    //}
    else
    //{
            glTranslatef( world_pos_app.GetX()+ world_pos.GetX(), world_pos_app.GetY()+ world_pos.GetY(), world_pos_app.GetZ()+ world_pos.GetZ());
    //}
    //isapp=!isapp;

    //glTranslatef(0.0,0.0,-5.0);
    glRotatef( m_angolo[0],1.0,0.0,0.0);
    glRotatef( m_angolo[1],0.0,1.0,0.0);
    glRotatef( m_angolo[2],0.0,0.0,1.0);
    glScalef( m_Scale[0], m_Scale[1], m_Scale[2]);
     if( m_bsmooth)
            glShadeModel(GL_SMOOTH);
    else
            glShadeModel(GL_FLAT);


    // Bind our buffers much like we would for texturing
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo->m_vboid);
    glBindBuffer(GL_NORMAL_ARRAY, m_vbo->m_nboid);

    // Set the state of what we are drawing (I don't think order matters here, but I like to do it in the same
    // order I set the pointers
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    // Resetup our pointers.  This doesn't reinitialise any data, only how we walk through it
    //glTexCoordPointer(2, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(12));
    glNormalPointer(GL_FLOAT,0, 0);
    //glColorPointer(4, GL_FLOAT, sizeof(VertexVBO), BUFFER_OFFSET(32));
    glVertexPointer(3, GL_FLOAT, 0,0);

    // Actually do our drawing, parameters are Primative (Triangles, Quads, Triangle Fans etc), Elements to
    // draw, Type of each element, Start Offset

    float val[]={0.5F,0.5F,0.5F,1.0F};
    float valsel[]={0.2F,0.2F,1.0F,1.0F};
    float val1[]={0.0F,0.0F,0.0F,1.0F};
    material mat,matsel;

    for(int ix=0; ix < 4; ix++)
    {
        mat.mat_ambient[ix]=val[ix];
        matsel.mat_ambient[ix]=valsel[ix];

        mat.mat_diffuse[ix]=val[ix];
        matsel.mat_diffuse[ix]=val[ix];

        mat.mat_specular[ix]=val[ix];
        matsel.mat_specular[ix]=val[ix];

        mat.mat_emission[ix]=val1[ix];
        matsel.mat_emission[ix]=val1[ix];

    }


    if(md==SCENE::wireframe)
    {
        glDisable(GL_LIGHTING);
        glColor4f(0.4F,0.4F,0.4F,1.0F);
        mat.Set();
        if(m_bselected)
            glEnable(GL_LIGHTING);

        glPointSize(2.0F);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_lboid);


        glDrawElements(GL_LINES, m_vbo->m_nlines*2, GL_UNSIGNED_INT, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_iboid);

        glColor4f(1.0F,1.0F,0.0F,1.0F);
        glDrawElements(GL_POINTS, m_vbo->m_ivertex, GL_UNSIGNED_INT, 0);

        glEnable(GL_LIGHTING);

    }
    if(md==SCENE::solid)
    {


        mat.Set();
        if(m_bselected)
            matsel.Set();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


        if(m_vbo->m_nindex==0 && m_vbo->m_nindex3==0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_lboid);


            glDrawElements(GL_LINES, m_vbo->m_nlines*2, GL_UNSIGNED_INT, 0);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_iboid);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_POINTS, m_vbo->m_ivertex, GL_UNSIGNED_INT, 0);

        }
        if(m_vbo->m_nindex>0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_TRIANGLES, m_vbo->m_nindex*3, GL_UNSIGNED_INT, 0);
        }


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        if(m_vbo->m_nindex3>0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid2);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_TRIANGLES, m_vbo->m_nindex3*3, GL_UNSIGNED_INT, 0);

        }



    }
    if(md==SCENE::color)
    {
        m_material_vector[0].Set();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


        if(m_vbo->m_nindex==0 && m_vbo->m_nindex3==0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_lboid);


            glDrawElements(GL_LINES, m_vbo->m_nlines*2, GL_UNSIGNED_INT, 0);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_iboid);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_POINTS, m_vbo->m_ivertex, GL_UNSIGNED_INT, 0);

        }
        if(m_vbo->m_nindex>0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_TRIANGLES, m_vbo->m_nindex*3, GL_UNSIGNED_INT, 0);
        }


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        if(m_vbo->m_nindex3>0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid2);

            glColor4f(1.0F,1.0F,0.0F,1.0F);
            glDrawElements(GL_TRIANGLES, m_vbo->m_nindex3*3, GL_UNSIGNED_INT, 0);

        }


    }


    // Disable our client state back to normal drawing
    //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_NORMAL_ARRAY, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    glPopMatrix();
}
void object3d::fetchvbo()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo->m_vboid);
    l3d_glfloat* ptr = (l3d_glfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
    glBindBuffer(GL_NORMAL_ARRAY, m_vbo->m_nboid);
    l3d_glfloat* nptr = (l3d_glfloat*)glMapBuffer(GL_NORMAL_ARRAY, GL_READ_ONLY);


    local_vertex.clear();
    // if the pointer is valid(mapped), update VBO
    if(ptr && nptr)
    {
        int ix=0;

        while(ix < m_vbo->m_ivertex*3)
        {

            pl3d_vertex_fast v= new l3d_vertex_fast;

            float x,y,z;
            float nx,ny,nz;


            x=*ptr++;
            y=*ptr++;
            z=*ptr++;


            nx=*nptr++;
            ny=*nptr++;
            nz=*nptr++;


            v->x=x;
            v->y=y;
            v->z=z;

            v->normals[0]=nx;
            v->normals[1]=ny;
            v->normals[2]=nz;


            v->prev=NULL;
            v->next=NULL;


            _vertex.add(v);

        }
        glUnmapBuffer(GL_ARRAY_BUFFER); // unmap it after use
        glUnmapBuffer(GL_NORMAL_ARRAY);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_NORMAL_ARRAY, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_lboid);
    l3d_glfloat* lptr = (l3d_glfloat*)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_READ_ONLY);


    m_line.clear();
    // if the pointer is valid(mapped), update VBO
    if(lptr)
    {
        while(lptr)
        {
            int l1,l2;
            l1=*lptr++;
            l2=*lptr++;

            pl3d_line_struct l= new l3d_line_struct;

            pl3d_vertex_fast pv=_vertex.find(l1);

            l->_v0=pv;

            pv=_vertex.find(l2);

            l->_v1=pv;

            l->v0=l1;
            l->v1=l2;

            l->prev=NULL;
            l->next=NULL;



            _edges.add(l);
        }
        glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER); // unmap it after use
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid);
    l3d_glfloat* fptr = (l3d_glfloat*)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_READ_ONLY);

    l3d_uint ix=0;

    while(ix++ < m_vbo->m_nindex*3)
    {
        l3d_uint v0,v1,v2;
        pl3d_vertex_fast vf;
        pl3d_face3_struct fs= new l3d_face3_struct;
        pl3d_line_struct lf;


        v0=*fptr++;
        v1=*fptr++;
        v2=*fptr++;

        fs->v0=v0;
        fs->v1=v1;
        fs->v2=v2;

        vf=_vertex.find(v0);
        fs->_pv0=vf;

        vf=_vertex.find(v1);
        fs->_pv1=vf;

        vf=_vertex.find(v2);
        fs->_pv2=vf;


        lf=_edges.find(v0,v1);
        fs->_l0=lf;

        lf=_edges.find(v0,v2);
        fs->_l1=lf;

        lf=_edges.find(v1,v2);
        fs->_l0=lf;

        _faces.add(fs);








    }


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo->m_sboid2);
    l3d_glfloat* fptr2 = (l3d_glfloat*)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_READ_ONLY);

    ix=0;

    while(ix++ < m_vbo->m_nindex3*3)
    {
        l3d_uint v0,v1,v2;
        pl3d_vertex_fast vf;
        pl3d_face3_struct fs= new l3d_face3_struct;
        pl3d_line_struct lf;


        v0=*fptr2++;
        v1=*fptr2++;
        v2=*fptr2++;

        fs->v0=v0;
        fs->v1=v1;
        fs->v2=v2;

        vf=_vertex.find(v0);
        fs->_pv0=vf;

        vf=_vertex.find(v1);
        fs->_pv1=vf;

        vf=_vertex.find(v2);
        fs->_pv2=vf;


        lf=_edges.find(v0,v1);
        fs->_l0=lf;

        lf=_edges.find(v0,v2);
        fs->_l1=lf;

        lf=_edges.find(v1,v2);
        fs->_l0=lf;

        _faces.add(fs);








    }


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);




}
void object3d::scalevbo()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo->m_vboid);
    l3d_glfloat * ptr = (l3d_glfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
    int ix=0;
    while(ix < m_vbo->m_ivertex*3)
    {

        ptr[ix]    *=  m_Scale[0];
        ptr[ix+1]  *=  m_Scale[1];
        ptr[ix+2]  *=  m_Scale[2];
        ix+=3;

    }
    glUnmapBuffer(GL_ARRAY_BUFFER); // unmap it after use

    m_Scale[0]=1.0F;
    m_Scale[1]=1.0F;
    m_Scale[2]=1.0F;



}

void object3d::make_fast()
{
    int vsize=local_vertex.size();
    for(int ix=0; ix <vsize; ix++)
    {
        //_vertex.add(local_vertex[ix]);

    }
    //local_vertex.clear();


}

