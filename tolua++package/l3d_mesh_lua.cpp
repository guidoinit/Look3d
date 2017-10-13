/*
** Lua binding: l3d_mesh
*/
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"



#include "scene/sceneenum.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;

#include "l3d_include.h"

#include "tolua.h"
#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_l3d_mesh_open (lua_State* tolua_S);
LUALIB_API int luaopen_l3d_mesh (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_pl3d_mesh_struct (lua_State* tolua_S)
{
 pl3d_mesh_struct* self = (pl3d_mesh_struct*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_l3d_uint (lua_State* tolua_S)
{
 l3d_uint* self = (l3d_uint*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_l3d_bool (lua_State* tolua_S)
{
 l3d_bool* self = (l3d_bool*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"l3d_mesh");
 tolua_usertype(tolua_S,"l3d_float");
 tolua_usertype(tolua_S,"l3d_mesh_type");
 tolua_usertype(tolua_S,"l3d_vertexbufferobject");
 tolua_usertype(tolua_S,"SCENE::ModeDraw");
 tolua_usertype(tolua_S,"GLfloat");
 tolua_usertype(tolua_S,"pl3d_mesh_struct");
 tolua_usertype(tolua_S,"l3d_uint");
 tolua_usertype(tolua_S,"l3d_bool");
}

/* method: new of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  l3d_mesh* tolua_ret = (l3d_mesh*)  new l3d_mesh();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"l3d_mesh");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: size of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'",NULL);
#endif
 {
  l3d_uint tolua_ret =  self->size();
 {
#ifdef __cplusplus
 void* tolua_obj = new l3d_uint(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_l3d_uint),"l3d_uint");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(l3d_uint));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"l3d_uint");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}

/* method: init_material of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_init_material00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct tolua_var_1 = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init_material'",NULL);
#endif
 {
  self->init_material(tolua_var_1);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init_material'.",&tolua_err);
 return 0;
#endif
}

/* method: create_null of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_null00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_null'",NULL);
#endif
 {
  self->create_null();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_null'.",&tolua_err);
 return 0;
#endif
}

/* method: create_line of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_line00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_2 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_line'",NULL);
#endif
 {
  self->create_line(tolua_var_2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_line'.",&tolua_err);
 return 0;
#endif
}

/* method: create_circle of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_circle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_3 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_circle'",NULL);
#endif
 {
  self->create_circle(tolua_var_3);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_circle'.",&tolua_err);
 return 0;
#endif
}

/* method: create_disck of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_disck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_4 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_disck'",NULL);
#endif
 {
  self->create_disck(tolua_var_4);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_disck'.",&tolua_err);
 return 0;
#endif
}

/* method: create_plane of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_plane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_5 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_plane'",NULL);
#endif
 {
  self->create_plane(tolua_var_5);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_plane'.",&tolua_err);
 return 0;
#endif
}

/* method: create_cube of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_cube00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_6 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_cube'",NULL);
#endif
 {
  self->create_cube(tolua_var_6);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_cube'.",&tolua_err);
 return 0;
#endif
}

/* method: create_cone of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_cone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_7 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_cone'",NULL);
#endif
 {
  self->create_cone(tolua_var_7);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_cone'.",&tolua_err);
 return 0;
#endif
}

/* method: create_cone of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_cone01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_float* tolua_var_8 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
  pl3d_mesh_struct tolua_var_9 = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,3,0));
 {
  l3d_mesh::create_cone(tolua_var_8,tolua_var_9);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_create_cone00(tolua_S);
}

/* method: create_cylinder of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_cylinder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_10 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_cylinder'",NULL);
#endif
 {
  self->create_cylinder(tolua_var_10);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_cylinder'.",&tolua_err);
 return 0;
#endif
}

/* method: create_cylindern of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_cylindern00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_11 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_cylindern'",NULL);
#endif
 {
  self->create_cylindern(tolua_var_11);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_cylindern'.",&tolua_err);
 return 0;
#endif
}

/* method: create_sphereuv of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_sphereuv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_float* tolua_var_12 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
  pl3d_mesh_struct tolua_var_13 = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,3,0));
 {
  l3d_mesh::create_sphereuv(tolua_var_12,tolua_var_13);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_sphereuv'.",&tolua_err);
 return 0;
#endif
}

/* method: create_sphereuv of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_sphereuv01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_14 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_sphereuv'",NULL);
#endif
 {
  self->create_sphereuv(tolua_var_14);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_create_sphereuv00(tolua_S);
}

/* method: create_torus of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_torus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_15 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_torus'",NULL);
#endif
 {
  self->create_torus(tolua_var_15);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_torus'.",&tolua_err);
 return 0;
#endif
}

/* method: create_logo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_logo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_float* tolua_var_16 = ((l3d_float*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_logo'",NULL);
#endif
 {
  self->create_logo(tolua_var_16);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_logo'.",&tolua_err);
 return 0;
#endif
}

/* method: create_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_vbo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint _e = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_vbo'",NULL);
#endif
 {
  self->create_vbo(_e);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_vbo'.",&tolua_err);
 return 0;
#endif
}

/* method: delete_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_delete_vbo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint _e = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete_vbo'",NULL);
#endif
 {
  self->delete_vbo(_e);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete_vbo'.",&tolua_err);
 return 0;
#endif
}

/* method: delete_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_delete_vbo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct _e = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete_vbo'",NULL);
#endif
 {
  self->delete_vbo(_e);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_delete_vbo00(tolua_S);
}

/* method: create_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create_vbo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct _e = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_vbo'",NULL);
#endif
 {
  self->create_vbo(_e);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_create_vbo00(tolua_S);
}

/* method: matmult of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_matmult00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GLfloat",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"GLfloat",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  GLfloat M = *((GLfloat*)  tolua_tousertype(tolua_S,2,0));
  GLfloat v = *((GLfloat*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'matmult'",NULL);
#endif
 {
  //self->matmult(M,v);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'matmult'.",&tolua_err);
 return 0;
#endif
}

/* method: isfirst of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_isfirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isfirst'",NULL);
#endif
 {
  l3d_bool tolua_ret =  self->isfirst();
 {
#ifdef __cplusplus
 void* tolua_obj = new l3d_bool(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_l3d_bool),"l3d_bool");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(l3d_bool));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"l3d_bool");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isfirst'.",&tolua_err);
 return 0;
#endif
}

/* method: vertex_alone of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_vertex_alone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_17 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'vertex_alone'",NULL);
#endif
 {
  l3d_bool tolua_ret =  self->vertex_alone(tolua_var_17);
 {
#ifdef __cplusplus
 void* tolua_obj = new l3d_bool(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_l3d_bool),"l3d_bool");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(l3d_bool));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"l3d_bool");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'vertex_alone'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct _e = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  self->add(_e);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: del of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_del00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint _index = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del'",NULL);
#endif
 {
  self->del(_index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'del'.",&tolua_err);
 return 0;
#endif
}

/* method: del of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_del01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct _m = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del'",NULL);
#endif
 {
  self->del(_m);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_del00(tolua_S);
}

/* method: find of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_find00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint _index = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'find'",NULL);
#endif
 {
  pl3d_mesh_struct tolua_ret =  self->find(_index);
 {
#ifdef __cplusplus
 void* tolua_obj = new pl3d_mesh_struct(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_pl3d_mesh_struct),"pl3d_mesh_struct");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(pl3d_mesh_struct));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"pl3d_mesh_struct");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'find'.",&tolua_err);
 return 0;
#endif
}

/* method: find of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_find01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct _m = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'find'",NULL);
#endif
 {
  l3d_uint tolua_ret =  self->find(_m);
 {
#ifdef __cplusplus
 void* tolua_obj = new l3d_uint(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_l3d_uint),"l3d_uint");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(l3d_uint));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"l3d_uint");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_find00(tolua_S);
}

/* method: first of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_first00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'first'",NULL);
#endif
 {
  pl3d_mesh_struct tolua_ret =  self->first();
 {
#ifdef __cplusplus
 void* tolua_obj = new pl3d_mesh_struct(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_pl3d_mesh_struct),"pl3d_mesh_struct");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(pl3d_mesh_struct));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"pl3d_mesh_struct");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'first'.",&tolua_err);
 return 0;
#endif
}

/* method: clear of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
 {
  self->clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}

/* method: draw_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_draw_vbo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint tolua_var_18 = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_vbo'",NULL);
#endif
 {
  self->draw_vbo(tolua_var_18);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_vbo'.",&tolua_err);
 return 0;
#endif
}

/* method: draw_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_draw_vbo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_vertexbufferobject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_vertexbufferobject* tolua_var_19 = ((l3d_vertexbufferobject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_vbo'",NULL);
#endif
 {
  self->draw_vbo(tolua_var_19);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_draw_vbo00(tolua_S);
}

/* method: draw_vbo of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_draw_vbo02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"SCENE::ModeDraw",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct m = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
  SCENE::ModeDraw md = *((SCENE::ModeDraw*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_vbo'",NULL);
#endif
 {
  self->draw_vbo(m,md);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_draw_vbo01(tolua_S);
}

/* method: draw_edit of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_draw_edit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"pl3d_mesh_struct",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  pl3d_mesh_struct tolua_var_20 = *((pl3d_mesh_struct*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_edit'",NULL);
#endif
 {
  self->draw_edit(tolua_var_20);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw_edit'.",&tolua_err);
 return 0;
#endif
}

/* method: draw_edit of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_draw_edit01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_uint",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_uint tolua_var_21 = *((l3d_uint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw_edit'",NULL);
#endif
 {
  self->draw_edit(tolua_var_21);
 }
 }
 return 0;
tolua_lerror:
 return tolua_l3d_mesh_l3d_mesh_draw_edit00(tolua_S);
}

/* method: create of class  l3d_mesh */
static int tolua_l3d_mesh_l3d_mesh_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"l3d_mesh",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"l3d_mesh_type",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"l3d_float",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  l3d_mesh* self = (l3d_mesh*)  tolua_tousertype(tolua_S,1,0);
  l3d_mesh_type _typem = *((l3d_mesh_type*)  tolua_tousertype(tolua_S,2,0));
  l3d_float* tolua_var_22 = ((l3d_float*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create'",NULL);
#endif
 {
  self->create(_typem,tolua_var_22);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_l3d_mesh (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"l3d_mesh","l3d_mesh","",NULL);
 tolua_beginmodule(tolua_S,"l3d_mesh");
 tolua_function(tolua_S,"new",tolua_l3d_mesh_l3d_mesh_new00);
 tolua_function(tolua_S,"size",tolua_l3d_mesh_l3d_mesh_size00);
 tolua_function(tolua_S,"init_material",tolua_l3d_mesh_l3d_mesh_init_material00);
 tolua_function(tolua_S,"create_null",tolua_l3d_mesh_l3d_mesh_create_null00);
 tolua_function(tolua_S,"create_line",tolua_l3d_mesh_l3d_mesh_create_line00);
 tolua_function(tolua_S,"create_circle",tolua_l3d_mesh_l3d_mesh_create_circle00);
 tolua_function(tolua_S,"create_disck",tolua_l3d_mesh_l3d_mesh_create_disck00);
 tolua_function(tolua_S,"create_plane",tolua_l3d_mesh_l3d_mesh_create_plane00);
 tolua_function(tolua_S,"create_cube",tolua_l3d_mesh_l3d_mesh_create_cube00);
 tolua_function(tolua_S,"create_cone",tolua_l3d_mesh_l3d_mesh_create_cone00);
 tolua_function(tolua_S,"create_cone",tolua_l3d_mesh_l3d_mesh_create_cone01);
 tolua_function(tolua_S,"create_cylinder",tolua_l3d_mesh_l3d_mesh_create_cylinder00);
 tolua_function(tolua_S,"create_cylindern",tolua_l3d_mesh_l3d_mesh_create_cylindern00);
 tolua_function(tolua_S,"create_sphereuv",tolua_l3d_mesh_l3d_mesh_create_sphereuv00);
 tolua_function(tolua_S,"create_sphereuv",tolua_l3d_mesh_l3d_mesh_create_sphereuv01);
 tolua_function(tolua_S,"create_torus",tolua_l3d_mesh_l3d_mesh_create_torus00);
 tolua_function(tolua_S,"create_logo",tolua_l3d_mesh_l3d_mesh_create_logo00);
 tolua_function(tolua_S,"create_vbo",tolua_l3d_mesh_l3d_mesh_create_vbo00);
 tolua_function(tolua_S,"delete_vbo",tolua_l3d_mesh_l3d_mesh_delete_vbo00);
 tolua_function(tolua_S,"delete_vbo",tolua_l3d_mesh_l3d_mesh_delete_vbo01);
 tolua_function(tolua_S,"create_vbo",tolua_l3d_mesh_l3d_mesh_create_vbo01);
 tolua_function(tolua_S,"matmult",tolua_l3d_mesh_l3d_mesh_matmult00);
 tolua_function(tolua_S,"isfirst",tolua_l3d_mesh_l3d_mesh_isfirst00);
 tolua_function(tolua_S,"vertex_alone",tolua_l3d_mesh_l3d_mesh_vertex_alone00);
 tolua_function(tolua_S,"add",tolua_l3d_mesh_l3d_mesh_add00);
 tolua_function(tolua_S,"del",tolua_l3d_mesh_l3d_mesh_del00);
 tolua_function(tolua_S,"del",tolua_l3d_mesh_l3d_mesh_del01);
 tolua_function(tolua_S,"find",tolua_l3d_mesh_l3d_mesh_find00);
 tolua_function(tolua_S,"find",tolua_l3d_mesh_l3d_mesh_find01);
 tolua_function(tolua_S,"first",tolua_l3d_mesh_l3d_mesh_first00);
 tolua_function(tolua_S,"clear",tolua_l3d_mesh_l3d_mesh_clear00);
 tolua_function(tolua_S,"draw_vbo",tolua_l3d_mesh_l3d_mesh_draw_vbo00);
 tolua_function(tolua_S,"draw_vbo",tolua_l3d_mesh_l3d_mesh_draw_vbo01);
 tolua_function(tolua_S,"draw_vbo",tolua_l3d_mesh_l3d_mesh_draw_vbo02);
 tolua_function(tolua_S,"draw_edit",tolua_l3d_mesh_l3d_mesh_draw_edit00);
 tolua_function(tolua_S,"draw_edit",tolua_l3d_mesh_l3d_mesh_draw_edit01);
 tolua_function(tolua_S,"create",tolua_l3d_mesh_l3d_mesh_create00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_l3d_mesh_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_l3d_mesh);
 lua_pushstring(tolua_S, "l3d_mesh");
 lua_call(tolua_S, 1, 0);
 return 1;
}
