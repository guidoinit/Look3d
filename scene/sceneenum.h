#ifndef _SCENE_ENUM

#define _SCENE_ENUM

namespace SCENE
{

enum SceneType
{
	s3d=1,
	stop=2,
    sbottom=3,
    sleft=4,
    sright=5,
    sfront=6,
    sback=7,
    sall=8,
    stelecamera=9
};
enum SceneMove
{
    move_world =1,
    move_camera=2,
    move_camera_trackball=3,
    move_camera_scene=4,
    move_camera_free=5,
    move_camera_center=6,

    move_last=10000
};

enum DocumentSelect
{
    dsmainscene=0,
    dsproject=1,
    dspackage=2
};

enum ModeDocument
{
	normal=1,
	edit=2,
	animation=3,
	consolle=4,
	texture=5,
        container=6,
        paint=7,
    fastinsert=8
};
enum ModeEdit
{
	vertex=1,
	line=2,
	polygon=3

};
enum ModeDraw
{
	solid=1,
	wireframe=2,
	color=3,
    mtexture=4,
    box=5
};

enum ObjectType
{
    ot_null=1,
    ot_line=2,
    ot_triangle=3,
    ot_rectangle=4,
    ot_circle=5,
    ot_piramid=6,
    ot_cube=7,
    ot_sphereuv=8,
    ot_cone=9,
    ot_cylinder=10,
    ot_torus=11,
    ot_disck=12,
    ot_plane=13,
    ot_mascotte=14,
    ot_tube=15


};

enum SelectTool
{
    st_normal=1,
    st_multiselect=2,
    st_move=3,
    st_scale=4,
    st_rotate=5,
    st_allactions=6,
    st_extrude=7
};

}
#endif
