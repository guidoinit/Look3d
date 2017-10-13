#define GLEW_STATIC
#include <GL/glew.h>

#include <QColorDialog>

#include "program_info.h"



#include "scene/elements/littlematerial.h"




#include "scene/sceneenum.h"



#include "newobject.h"
#include "mainobject.h"

#include "importobject.h"
#include "newanimation.h"
#include "blend_dialog.h"
#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "scene/elements/l3d_light.h"

#include "scene/sceneenum.h"

#include "insertobject.h"
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;
using namespace l3d::light;

extern insertObject * Main_insert;

insertObject::insertObject(QObject *parent) :
    QObject(parent)
{
    m_dlgmaterial=NULL;
    m_loption=NULL;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);
    m_imaterial=0;
    _imaterial=l3d_null;
    _group=l3d_null;
    m_ilight=-1;
    m_ioldlight=-1;
    m_igroup_prev=-1;
    m_igroup=-1;

    m_dlgblend=NULL;

    _mesh_selected=l3d_null;

    Main_insert =this;
}
insertObject::~insertObject()
{
    delete m_dlgmaterial;
}

void insertObject::setscene(scene * oscene)
{
   // pscene=oscene;

}

void insertObject::connectobjects(Ui::MainWindow *ui)
{

    m_ui=ui;
    connect(ui->view3d,SIGNAL(clicked()),this,SLOT(on_view3d_clicked()));

    connect(ui->unselecteditall,SIGNAL(clicked()),this,SLOT(on_unselecteditall_clicked()));

    connect(ui->pbspin,SIGNAL(clicked()),this,SLOT(on_pbspin_clicked()));

    connect(ui->actionNullobject,SIGNAL(triggered()),this,SLOT(insertnull()));

    connect(ui->selectmouse,SIGNAL(clicked()),this,SLOT(on_slectmouse_clicked()));

    connect(ui->selectmulti,SIGNAL(clicked()),this,SLOT(on_selectmulti_clicked()));

    connect(ui->selectmove,SIGNAL(clicked()),this,SLOT(on_select_move()));

    connect(ui->selectscale,SIGNAL(clicked()),this,SLOT(on_select_scale()));

    connect(ui->selectrotate,SIGNAL(clicked()),this,SLOT(on_select_rotate()));

    connect(ui->pb_blending,SIGNAL(clicked()),this,SLOT(on_pb_blending_clicked()));

    connect(ui->pb_object_normals,SIGNAL(clicked()),this,SLOT(on_pb_object_normals_clicked()));

    connect(ui->selectvertex,SIGNAL(clicked()),this,SLOT(selecteditvertex()));

    connect(ui->pb_edit_all,SIGNAL(clicked()),this,SLOT(on_pb_edit_all_clicked()));

    connect(ui->pb_edit_delete,SIGNAL(clicked()),this,SLOT(on_pb_edit_delete_clicked()));

    connect(ui->pb_edit_invert,SIGNAL(clicked()),this,SLOT(on_pb_edit_invert_clicked()));

    connect(ui->selectvertex_2,SIGNAL(clicked()),this,SLOT(selecteditvertex()));

    connect(ui->viewtelecamera,SIGNAL(clicked()),this,SLOT(on_viewtelecamera_clicked()));

    connect(ui->selectedge,SIGNAL(clicked()),this,SLOT(selecteditedge()));

    connect(ui->selectedge_2,SIGNAL(clicked()),this,SLOT(selecteditedge()));

    connect(ui->pbspin_x,SIGNAL(clicked()),this,SLOT(on_pbspin_x_clicked()));

    connect(ui->pbspin_y,SIGNAL(clicked()),this,SLOT(on_pbspin_y_clicked()));

    connect(ui->pbspin_z,SIGNAL(clicked()),this,SLOT(on_pbspin_z_clicked()));

    connect(ui->view_setortho,SIGNAL(clicked()),this,SLOT(on_view_setortho_clicked()));





    connect(ui->pb_edit_invert_face,SIGNAL(clicked()),this,SLOT(on_pb_edit_invert_face_clicked()));

    connect(ui->selectface,SIGNAL(clicked()),this,SLOT(selecteditface()));

    connect(ui->selectface_2,SIGNAL(clicked()),this,SLOT(selecteditface()));

    connect(ui->actionspheredlg,SIGNAL(triggered()),this,SLOT(insertspheredlg()));

    connect(ui->actionInsertdisck,SIGNAL(triggered()),this,SLOT(insertdisckdlg()));

    connect(ui->actionInsert_line,SIGNAL(triggered()),this,SLOT(insertlinedlg()));

    connect(ui->actionInsert_circle,SIGNAL(triggered()),this,SLOT(insertcircledlg()));

    connect(ui->actionNew_cone,SIGNAL(triggered()),this,SLOT(insertconedlg()));

    connect(ui->actionNewcylinder,SIGNAL(triggered()),this,SLOT(inserttubesdlg()));

    connect(ui->actiontorusdlg,SIGNAL(triggered()),this,SLOT(inserttorusdlg()));

    connect(ui->actionAdd_telecamera,SIGNAL(triggered()),this,SLOT(on_actionAdd_telecamera_triggered()));

    connect(ui->actionSet_color,SIGNAL(triggered()),this,SLOT(setcolor()));

    connect(ui->actionObjectImport,SIGNAL(triggered()),this,SLOT(on_actionObjectImport_triggered()));

    connect(ui->actionInsertplane,SIGNAL(triggered()),this,SLOT(insertplanedlg()));

    connect(ui->actionInsertcube,SIGNAL(triggered()),this,SLOT(insertcubedlg()));

    connect(ui->selecteditdelete,SIGNAL(clicked()),this,SLOT(selecteditdelete()));

    connect(ui->selecteditduplicate,SIGNAL(clicked()),this,SLOT(selecteditduplicate()));

    connect(ui->selecteditinvert,SIGNAL(clicked()),this,SLOT(selecteditinvert()));

    connect(ui->pb_camera_up,SIGNAL(clicked()),this,SLOT(on_pb_camera_up_clicked()));

    connect(ui->cb_ambientdiffuse,SIGNAL(clicked(const bool)),this,SLOT(on_cb_ambientdiffuse_clicked(const bool)));

    connect(ui->pb_camera_down,SIGNAL(clicked()),this,SLOT(on_pb_camera_down_clicked()));

    connect(ui->pb_camera_left,SIGNAL(clicked()),this,SLOT(on_pb_camera_left_clicked()));

    connect(ui->pb_camera_right,SIGNAL(clicked()),this,SLOT(on_pb_camera_right_clicked()));

    connect(ui->actionLightSun,SIGNAL(triggered()),this,SLOT(addLight_sun()));

    connect(ui->actionLightSpot,SIGNAL(triggered()),this,SLOT(addLight_spot()));

    connect(ui->actionLightLamp,SIGNAL(triggered()),this,SLOT(addLight_lamp()));

    connect(ui->actionNullobject,SIGNAL(triggered()),this,SLOT(addnullobject()));

    //connect(ui->actionMaterial,SIGNAL(triggered()),this,SLOT(on_actionMaterial_triggered()));

    connect(ui->actionSet_material,SIGNAL(triggered()),this,SLOT(on_actionSet_material_triggered()));

    connect(ui->modepaint,SIGNAL(triggered()),this,SLOT(on_modepaint_clicked()));

    connect(ui->actionLightOptions,SIGNAL(triggered()),this,SLOT(on_actionLightOptions_triggered()));

    connect(ui->leName,SIGNAL(textChanged(const QString)),this,SLOT(on_leName_textChanged(const QString )));

    connect(ui->leName2,SIGNAL(textChanged(const QString)),this,SLOT(on_leName2_textChanged(const QString )));

    connect(ui->scalex,SIGNAL(valueChanged(double)),this,SLOT(on_scalex_valueChanged(double )));

    connect(ui->scaley,SIGNAL(valueChanged(double)),this,SLOT(on_scaley_valueChanged(double )));

    connect(ui->scalez,SIGNAL(valueChanged(double)),this,SLOT(on_scalez_valueChanged(double )));

    connect(ui->applyscale,SIGNAL(clicked()),this,SLOT(on_applyscale_clicked()));

    connect(ui->poswx,SIGNAL(valueChanged(double)),this,SLOT(on_poswx_valueChanged(double)));

    connect(ui->hsshininnis,SIGNAL(valueChanged(int)),this,SLOT(on_hsshininnis_valueChanged(int)));

    connect(ui->tb_move_world,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_world_toggled(bool )));

    connect(ui->tb_move_maincamera,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_maincamera_toggled(bool)));

    connect(ui->tb_move_freecamera,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_freecamera_toggled(bool )));

    connect(ui->tb_move_scenetelecamera,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_scenetelecamera_toggled(bool )));

    connect(ui->tb_move_maincamera_fix,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_maincamera_fix_toggled(bool )));



    connect(ui->tb_move_trackball,SIGNAL(toggled(bool)),this,SLOT(on_tb_move_trackball_toggled(bool )));



    connect(ui->poswy,SIGNAL(valueChanged(double)),this,SLOT(on_poswy_valueChanged(double)));

    connect(ui->poswz,SIGNAL(valueChanged(double)),this,SLOT(on_poswz_valueChanged(double)));

    connect(ui->pb_camera_x,SIGNAL(valueChanged(double)),this,SLOT(on_pb_camera_x_valueChanged(double)));

    connect(ui->pb_camera_y,SIGNAL(valueChanged(double)),this,SLOT(on_pb_camera_y_valueChanged(double)));

    connect(ui->pb_camera_z,SIGNAL(valueChanged(double)),this,SLOT(on_pb_camera_z_valueChanged(double)));

    connect(ui->rotatex,SIGNAL(valueChanged(double)),this,SLOT(on_rotatex_valueChanged(double )));

    connect(ui->rotatey,SIGNAL(valueChanged(double)),this,SLOT(on_rotatey_valueChanged(double )));

    connect(ui->rotatez,SIGNAL(valueChanged(double)),this,SLOT(on_rotatez_valueChanged(double )));

    connect(ui->poswx_group,SIGNAL(valueChanged(double)),this,SLOT(on_poswx_group_valueChanged(double)));

    connect(ui->poswy_group,SIGNAL(valueChanged(double)),this,SLOT(on_poswy_group_valueChanged(double)));

    connect(ui->poswz_group,SIGNAL(valueChanged(double)),this,SLOT(on_poswz_group_valueChanged(double)));

    connect(ui->rotatex_group,SIGNAL(valueChanged(double)),this,SLOT(on_rotatex_group_valueChanged(double )));

    connect(ui->rotatey_group,SIGNAL(valueChanged(double)),this,SLOT(on_rotatey_group_valueChanged(double )));

    connect(ui->rotatez_group,SIGNAL(valueChanged(double)),this,SLOT(on_rotatez_group_valueChanged(double )));

    connect(ui->scalex_group,SIGNAL(valueChanged(double)),this,SLOT(on_scalex_group_valueChanged(double )));

    connect(ui->scaley_group,SIGNAL(valueChanged(double)),this,SLOT(on_scaley_group_valueChanged(double )));

    connect(ui->scalez_group,SIGNAL(valueChanged(double)),this,SLOT(on_scalez_group_valueChanged(double )));

    connect(ui->applyrotate,SIGNAL(clicked()),this,SLOT(on_applyrotate_clicked()));

    connect(ui->pbFlat,SIGNAL(clicked()),this,SLOT(on_pbFlat_clicked()));

    connect(ui->pbFlat_2,SIGNAL(clicked()),this,SLOT(on_pbFlat_2_clicked()));

    connect(ui->pb_edit_extrude,SIGNAL(clicked()),this,SLOT(on_pb_edit_extrude_clicked()));


    //connect(ui->mainwidget,SIGNAL(clicked()),this,SLOT(on_opengl_clicked()));

    connect(ui->hsambientr,SIGNAL(valueChanged(int)),this,SLOT(on_hsambientr_valueChanged(int )));

    connect(ui->hsambientg,SIGNAL(valueChanged(int)),this,SLOT(on_hsambientg_valueChanged(int )));

    connect(ui->hsambientb,SIGNAL(valueChanged(int)),this,SLOT(on_hsambientb_valueChanged(int )));

    connect(ui->hsambienta,SIGNAL(valueChanged(int)),this,SLOT(on_hsambienta_valueChanged(int )));

    connect(ui->pb_addmaterial,SIGNAL(clicked()),this,SLOT(on_pb_addmaterial_clicked()));

    connect(ui->pb_prevmaterial,SIGNAL(clicked()),this,SLOT(on_pb_prevmaterial_clicked()));

    connect(ui->pb_nextmaterial,SIGNAL(clicked()),this,SLOT(on_pb_nextmaterial_clicked()));

    connect(ui->hsemittedr,SIGNAL(valueChanged(int)),this,SLOT(on_hsemittedr_valueChanged(int )));

    connect(ui->hsemittedg,SIGNAL(valueChanged(int)),this,SLOT(on_hsemittedg_valueChanged(int )));

    connect(ui->hsemittedb,SIGNAL(valueChanged(int)),this,SLOT(on_hsemittedb_valueChanged(int )));

    connect(ui->hsemitteda,SIGNAL(valueChanged(int)),this,SLOT(on_hsemitteda_valueChanged(int )));

    connect(ui->hsdiffuser,SIGNAL(valueChanged(int)),this,SLOT(on_hsdiffuser_valueChanged(int )));

    connect(ui->hsdiffuseg,SIGNAL(valueChanged(int)),this,SLOT(on_hsdiffuseg_valueChanged(int )));

    connect(ui->hsdiffuseb,SIGNAL(valueChanged(int)),this,SLOT(on_hsdiffuseb_valueChanged(int )));

    connect(ui->hsdiffusea,SIGNAL(valueChanged(int)),this,SLOT(on_hsdiffusea_valueChanged(int )));

    connect(ui->hsspecularr,SIGNAL(valueChanged(int)),this,SLOT(on_hsspecularr_valueChanged(int )));

    connect(ui->hsspecularg,SIGNAL(valueChanged(int)),this,SLOT(on_hsspecularg_valueChanged(int )));

    connect(ui->hsspecularb,SIGNAL(valueChanged(int)),this,SLOT(on_hsspecularb_valueChanged(int )));

    connect(ui->hsspeculara,SIGNAL(valueChanged(int)),this,SLOT(on_hsspeculara_valueChanged(int )));

    connect(ui->modepaint,SIGNAL(clicked()),this,SLOT(on_modepaint_clicked()));

    connect(ui->pb_setmaterial,SIGNAL(clicked()),this,SLOT(on_pb_setmaterial_clicked()));

    connect(ui->pb_preview_material,SIGNAL(clicked()),this,SLOT(on_pb_preview_material_clicked()));

    connect(ui->groupBox,SIGNAL(clicked()),this,SLOT(on_groupBox_clicked()));

    connect(ui->selecteditmerge,SIGNAL(clicked()),this,SLOT(on_selecteditmerge_clicked()));

    connect(ui->selecteditextrude,SIGNAL(clicked()),this,SLOT(on_selecteditextrude_clicked()));

    connect(ui->actionSave_mesh,SIGNAL(triggered()),this,SLOT(on_actionSave_mesh_triggered()));

    connect(ui->actionLoad_mesh,SIGNAL(triggered()),this,SLOT(on_actionLoad_mesh_triggered()));

    connect(ui->selectwave,SIGNAL(clicked()),this,SLOT(on_select_wave()));

    connect(ui->actionAdd_light,SIGNAL(triggered()),this,SLOT(on_actionAdd_light_triggered()));

    connect(ui->selecteditGroup,SIGNAL(clicked()),this,SLOT(on_selecteditGroup_clicked()));

    connect(ui->selecteditUnGroup,SIGNAL(clicked()),this,SLOT(on_selecteditUnGroup_clicked()));

    connect(ui->pb_group_first,SIGNAL(clicked()),this,SLOT(on_pb_group_first_clicked()));

    connect(ui->pb_group_last,SIGNAL(clicked()),this,SLOT(on_pb_group_last_clicked()));

    connect(ui->pb_group_next,SIGNAL(clicked()),this,SLOT(on_pb_group_next_clicked()));

    connect(ui->pb_group_prev,SIGNAL(clicked()),this,SLOT(on_pb_group_prev_clicked()));

    connect(ui->pb_insertprevius,SIGNAL(clicked()),this,SLOT(on_pb_insertprevius_clicked()));

    connect(ui->pb_insertnext,SIGNAL(clicked()),this,SLOT(on_pb_insertnext_clicked()));

    connect(ui->pb_insertobject,SIGNAL(clicked()),this,SLOT(on_pb_insertobject_clicked()));

    connect(ui->pb_edit_extrude_edge,SIGNAL(clicked()),this,SLOT(on_pb_edit_extrude_edge_clicked()));

    connect(ui->pb_edit_extrude_edge_individual,SIGNAL(clicked()),this,SLOT(on_pb_edit_extrude_edge_individual_clicked()));



    connect(ui->selecteditall,SIGNAL(clicked()),this,SLOT(on_selecteditall_clicked()));

    connect(ui->pb_smooth_group,SIGNAL(clicked()),this,SLOT(on_pb_smooth_group_clicked()));

    connect(ui->pb_light_lamp,SIGNAL(clicked()),this,SLOT(on_pb_light_lamp_clicked()));

    connect(ui->pb_light_sun,SIGNAL(clicked()),this,SLOT(on_pb_light_sun_clicked()));

    connect(ui->pb_light_spot,SIGNAL(clicked()),this,SLOT(on_pb_light_spot_clicked()));

    connect(ui->pb_light_directional,SIGNAL(clicked()),this,SLOT(on_pb_light_directional_clicked()));

    connect(ui->pb_light_onoff,SIGNAL(clicked()),this,SLOT(on_pb_light_onoff_clicked()));

    connect(ui->pb_camera_first,SIGNAL(clicked()),this,SLOT(on_pb_camera_first_clicked()));

    connect(ui->pb_camera_next,SIGNAL(clicked()),this,SLOT(on_pb_camera_next_clicked()));

    connect(ui->pb_camera_prev,SIGNAL(clicked()),this,SLOT(on_pb_camera_prev_clicked()));

    connect(ui->pb_camera_last,SIGNAL(clicked()),this,SLOT(on_pb_camera_last_clicked()));

    connect(ui->hs_ambientred_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_ambientred_light_valueChanged(int )));

    connect(ui->hs_ambientgreen_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_ambientgreen_light_valueChanged(int )));

    connect(ui->hs_ambientblue_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_ambientblue_light_valueChanged(int )));

    connect(ui->hs_ambientalpha_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_ambientalpha_light_valueChanged(int )));

    connect(ui->hs_diffusered_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_diffusered_light_valueChanged(int )));

    connect(ui->hs_diffusegreen_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_diffusegreen_light_valueChanged(int )));

    connect(ui->hs_diffuseblue_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_diffuseblue_light_valueChanged(int )));

    connect(ui->hs_diffusealpha_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_diffusealpha_light_valueChanged(int )));

    connect(ui->hs_specularred_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_specularred_light_valueChanged(int )));

    connect(ui->hs_speculargreen_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_speculargreen_light_valueChanged(int )));

    connect(ui->hs_specularblue_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_specularblue_light_valueChanged(int )));

    connect(ui->hs_specularalpha_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_specularalpha_light_valueChanged(int )));

    connect(ui->hs_exponent_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_exponent_light_valueChanged(int )));

    connect(ui->hs_degree_light,SIGNAL(valueChanged(int)),this,SLOT(on_hs_degree_light_valueChanged(int )));

    connect(ui->poswx_light,SIGNAL(valueChanged(double)),this,SLOT(on_poswx_light_valueChanged(double )));

    connect(ui->poswy_light,SIGNAL(valueChanged(double)),this,SLOT(on_poswy_light_valueChanged(double)));

    connect(ui->poswz_light,SIGNAL(valueChanged(double)),this,SLOT(on_poswz_light_valueChanged(double )));

    connect(ui->sb_distance_light,SIGNAL(valueChanged(int)),this,SLOT(on_sb_distance_light_valueChanged(int)));

    connect(ui->sb_anglea_light,SIGNAL(valueChanged(int)),this,SLOT(on_sb_anglea_light_valueChanged(int)));

    connect(ui->sb_angleb_light,SIGNAL(valueChanged(int)),this,SLOT(on_sb_angleb_light_valueChanged(int)));

    connect(ui->modetexture,SIGNAL(clicked()),this,SLOT(on_modetexture_clicked()));

    connect(ui->view_wireframe,SIGNAL(toggled(bool)),this,SLOT(on_view_wireframe_toggled(bool )));

    connect(ui->view_solid,SIGNAL(toggled(bool)),this,SLOT(on_view_solid_toggled(bool )));

    connect(ui->viewbox,SIGNAL(clicked()),this,SLOT(on_viewbox_clicked()));

    connect(ui->viewtree,SIGNAL(clicked()),this,SLOT(on_viewtree_clicked()));

    connect(ui->viewtop,SIGNAL(clicked()),this,SLOT(on_viewtop_clicked()));

    connect(ui->viewbottom,SIGNAL(clicked()),this,SLOT(on_viewbottom_clicked()));

    connect(ui->viewleft,SIGNAL(clicked()),this,SLOT(on_viewleft_clicked()));

    connect(ui->viewrigth,SIGNAL(clicked()),this,SLOT(on_viewrigth_clicked()));

    connect(ui->viewfront,SIGNAL(clicked()),this,SLOT(on_viewfront_clicked()));

    connect(ui->viewback,SIGNAL(clicked()),this,SLOT(on_viewback_clicked()));

    connect(ui->animationnew,SIGNAL(clicked()),this,SLOT(on_animationnew_clicked()));

    connect(ui->pb_addtexture,SIGNAL(clicked()),this,SLOT(on_pb_addtexture_clicked()));

    connect(ui->pb_addvertexgroup,SIGNAL(clicked()),this,SLOT(on_pb_addvertexgroup_clicked()));

    connect(ui->pb_vertexgroup_set,SIGNAL(clicked()),this,SLOT(on_pb_vertexgroup_set_clicked()));

    connect(ui->pb_vertexgroupprev,SIGNAL(clicked()),this,SLOT(on_pb_vertexgroupprev_clicked()));

    connect(ui->pb_vertexgroupnext,SIGNAL(clicked()),this,SLOT(on_pb_vertexgroupnext_clicked()));

    connect(ui->pb_vertexgroup_del,SIGNAL(clicked()),this,SLOT(on_pb_vertexgroup_del_clicked()));

    connect(ui->pb_vertexgroup_select,SIGNAL(clicked()),this,SLOT(on_pb_vertexgroup_select_clicked()));

    connect(ui->add_bezierline,SIGNAL(clicked()),this,SLOT(on_add_bezierline_clicked()));

    connect(ui->pb_blending_define,SIGNAL(clicked()),this,SLOT(on_pb_blending_define_clicked()));

    connect(ui->add_mesh_null,SIGNAL(clicked()),this,SLOT(on_add_mesh_null_clicked()));

    connect(ui->add_mesh_line,SIGNAL(clicked()),this,SLOT(on_add_mesh_line_clicked()));

    connect(ui->add_mesh_circle,SIGNAL(clicked()),this,SLOT(on_add_mesh_circle_clicked()));

    connect(ui->add_mesh_cube,SIGNAL(clicked()),this,SLOT(on_add_mesh_cube_clicked()));

    connect(ui->add_mesh_plane,SIGNAL(clicked()),this,SLOT(on_add_mesh_plane_clicked()));

    connect(ui->add_mesh_tube,SIGNAL(clicked()),this,SLOT(on_add_mesh_tube_clicked()));

    connect(ui->add_mesh_sphere,SIGNAL(clicked()),this,SLOT(on_add_mesh_sphere_clicked()));

    connect(ui->add_mesh_torus,SIGNAL(clicked()),this,SLOT(on_add_mesh_torus_clicked()));

    connect(ui->add_mesh_cone,SIGNAL(clicked()),this,SLOT(on_add_mesh_cone_clicked()));

    connect(ui->add_mesh_logo,SIGNAL(clicked()),this,SLOT(on_add_mesh_logo_clicked()));

    connect(ui->pb_edit_subdivide,SIGNAL(clicked()),this,SLOT(on_pb_edit_subdivide_clicked()));

    connect(ui->pb_edit_subdivide_all,SIGNAL(clicked()),this,SLOT(on_pb_edit_subdivide_all_clicked()));

    connect(ui->pb_delmaterial,SIGNAL(clicked()),this,SLOT(on_pb_delmaterial_clicked()));




}

void insertObject::insertnull()
{


    updateMainDock(m_sm,m_ui);
}

void insertObject::insertline()
{
    m_ui->mainwidget->pscene->AddObject(mesh_line,NULL);
    //objline mline;

    //mline.create(10,10.0F);

    ///mline.setName("line","10-10");

    //m_ui->mainwidget->pscene->AddObject(mline);

    updateMainDock(m_sm,m_ui);
}
void insertObject::insertlinedlg()
{
    newobject * nobject= new newobject(0);

    //objline mline;

    int *p,vp;
    float *s,vs,line[2];
    p=&vp;
    s=&vs;
    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getline(p,s);
        line[0]=vp;
        line[1]=vs;

        //mline.create(vp,vs);
        m_ui->mainwidget->pscene->AddObject(mesh_line,&line[0]);
        //m_ui->mainwidget->pscene->AddObject(mline);

    }

    delete nobject;

    updateMainDock(m_sm,m_ui);
}
void insertObject::insertcircledlg()
{
    newobject * nobject= new newobject(1);

   // circle c;

    int *p,vp;
    float *s,vs,par[2];
    p=&vp;
    s=&vs;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getcircle(p,s);
        //c.create(vp,vs);
        par[0]=vp;par[1]=vs;

        m_ui->mainwidget->pscene->AddObject(mesh_circle,&par[0]);

    }
    delete nobject;

    updateMainDock(m_sm,m_ui);
}

void insertObject::insertcircle()
{
   /* circle c;

    c.create();

    c.setName("circle","32-10");

    m_ui->mainwidget->pscene->AddObject(c);
*/
    m_ui->mainwidget->pscene->AddObject(mesh_circle,NULL);
    updateMainDock(m_sm,m_ui);

}
void insertObject::insertdisck()
{
    m_ui->mainwidget->pscene->AddObject(mesh_disck,NULL);
    updateMainDock(m_sm,m_ui);


}
void insertObject::insertdisckdlg()
{
    //disck*d= new disck();

    //d->setName("disck","");

    newobject * nobject= new newobject(2);



    int *p,vp;
    float *s,vs,par[2];
    p=&vp;
    s=&vs;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getdisck(p,s);
        //d->create(vs,vp);
        par[0]=vp;
        par[1]=vs;

        m_ui->mainwidget->pscene->AddObject(mesh_disck ,&par[0]);

    }
    delete (nobject);
    //delete(d);

    updateMainDock(m_sm,m_ui);

}
void insertObject::insertplane()
{
    //to-do
    m_ui->mainwidget->pscene->AddObject(mesh_plane,NULL);
    updateMainDock(m_sm,m_ui);
}

void insertObject::insertplanedlg()
{
    //to-do da fare il dialogo
    //plane p;

    newobject * nobject= new newobject(3);



    int *s,vs;
    float *r,vr,par[3];
    int *f,vf;
    s=&vs;
    r=&vr;
    f=&vf;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getplane(s,r,f);
        par[0]=vs;par[1]=vr;par[2]=vf;
        //p.create_function(vs,vr,vf);
        //p.setName("plane","");
        m_ui->mainwidget->pscene->AddObject(mesh_plane,&par[0]);

    }
    delete nobject;

    updateMainDock(m_sm,m_ui);

}
void insertObject::insertcube()
{
    m_ui->mainwidget->pscene->AddObject(mesh_cube,NULL);
    updateMainDock(m_sm,m_ui);

}
void insertObject::insertcubedlg()
{
    //cube c;

    newobject * nobject= new newobject(4);



    int *s,vs;
    float *r,vr;
    int *f,vf;
    float *par,fpar[3];
    s=&vs;
    r=&vr;
    f=&vf;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getcube(s,r);
        fpar[0]=vs;//(float)*s;
        fpar[1]=vr;//(float)*r;
        fpar[2]=vf;
        par=&fpar[0];
        //c.create(vs,vr);//_function(vs,vr,vf);

        m_ui->mainwidget->pscene->AddObject(mesh_cube,par);

    }
    delete nobject;

    updateMainDock(m_sm,m_ui);
}
void insertObject::insertconedlg()
{

    newobject * nobject= new newobject(6);

    float *ph,h,par[2];
    int *ps,s;

    ph=&h;
    ps=&s;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getcone(ph,ps);
        par[0]=h;par[1]=s;
        m_ui->mainwidget->pscene->AddObject(mesh_cone,&par[0]);
    }
    delete nobject;

    updateMainDock(m_sm,m_ui);

}
void insertObject::inserttubesdlg()
{

    newobject * nobject= new newobject(7);

    float *ph,h,par[2];
    int *ps,s,*pss,ss;

    ph=&h;
    ps=&s;
    pss=&ss;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->gettube(ph,ps,pss);
        par[0]=h;par[1]=s;par[2]=ss;
        m_ui->mainwidget->pscene->AddObject(mesh_tube_n,&par[0]);
    }
    delete nobject;

    updateMainDock(m_sm,m_ui);
}
void insertObject::inserttorusdlg()
{

    newobject * nobject= new newobject(8);

    float *pminr,*pmaxr,minr,maxr,par[4];
    int *pmins,*pmaxs,mins,maxs;

    pminr=&minr;
    pmaxr=&maxr;
    pmins=&mins;
    pmaxs=&maxs;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->gettorus(pmaxr,pminr,pmaxs,pmins);
        par[0]=maxr;par[1]=minr;par[2]=maxs; par[3]=mins;

        m_ui->mainwidget->pscene->AddObject(mesh_torus,&par[0]);
    }
    delete nobject;

    updateMainDock(m_sm,m_ui);
}


void insertObject::insertspheredlg()
{
    //sphereuv s;
    newobject * nobject= new newobject(5);



    int *u,vu;
    int *v,vv;
    float *r,vr,par[3];
    u=&vu;
    v=&vv;
    r=&vr;

    if(nobject->exec()==QDialog::Accepted)
    {
        nobject->getsphere(u,v,r);
        par[0]=vu;par[1]=vv;par[2]=vr;
        //s.create(vu,vv,vr);//_function(vs,vr,vf);
        //s.setMaterialVertex(0);
        m_ui->mainwidget->pscene->AddObject(mesh_sphereuv,&par[0]);

    }
    delete nobject;

    updateMainDock(m_sm,m_ui);

}

void insertObject::insertsphere()
{
    m_ui->mainwidget->pscene->AddObject(mesh_sphereuv,NULL);
    updateMainDock(m_sm,m_ui);

}

void insertObject::setdata(QStandardItemModel* sm,Ui::MainWindow *ui)
{
    m_ui=ui;
    m_sm=sm;
}
void insertObject::updateMainTelecamera()
{
    QStandardItemModel * mymodel=( QStandardItemModel *)m_ui->treeViewMain->model();
    QStandardItem *rootNode = mymodel->invisibleRootItem();

    //defining a couple of items

    QStandardItem *sceneitem = rootNode->child(0);

    QStandardItem *cameraitem = sceneitem->child(5);

    cameraitem->removeRows(0,cameraitem->rowCount());
    cameraitem->setEditable(false);

    //int io=0, size=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getsizecamera();
   // for(io=0; io < size; io++)
    {


        //telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(io);

        //QString name=QString("camera%1").arg(io);

        //QStandardItem *cameralabel = new QStandardItem(name);
       // QVariant *odata= new QVariant(QVariant::Int,&io);



        //cameralabel->setData(*odata);


        //cameralabel->setEditable(false);

        //cameraitem->appendRow(cameralabel);
    }


    //sceneitem->appendRow(cameraitem);


}

void insertObject::updateMainObjects()
{
    QStandardItemModel * mymodel=( QStandardItemModel *)m_ui->treeViewMain->model();
    QStandardItem *rootNode = mymodel->invisibleRootItem();

    //defining a couple of items

    QStandardItem *sceneitem = rootNode->child(0);

    QStandardItem *objectitem = sceneitem->child(0);

    objectitem->removeRows(0,objectitem->rowCount());
    objectitem->setEditable(false);



    int io=0, size=m_ui->mainwidget->pscene->GetSizeObjectMainScene();
    for(io=0; io < size; io++)
    {
    // da riscrivere
    /*
        object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(io);

        if(obj->getGroup()==-1)
        {
            QString name=QString("object%1(").arg(io);
            QString nameo=obj->getname().c_str();
            nameo.append("-");
            nameo.append(obj->getsubname().c_str());
            nameo.append(")");
            name.append(nameo);

            //name.fromStdString(getdocument()->getmainscenedoc()->getObject(io)->name);

            QStandardItem *objectlabel = new QStandardItem(name);
            QVariant *odata= new QVariant(QVariant::Int,&io);



            objectlabel->setData(*odata);


            objectlabel->setEditable(false);

            objectitem->appendRow(objectlabel);
        }
        */

    }
    // sceneitem->appendRow(objectitem);
}
void insertObject::updateMainLights()
{
    QStandardItemModel * mymodel=( QStandardItemModel *)m_ui->treeViewMain->model();
    QStandardItem *rootNode = mymodel->invisibleRootItem();

    //defining a couple of items

    QStandardItem *sceneitem = rootNode->child(0);

    QStandardItem *lightitem = sceneitem->child(2);

    lightitem->setEditable(false);

    lightitem->removeRows(0,lightitem->rowCount());


    //for(int io=0; io < m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getsizelight(); io++ )
    {
        //QString name=QString("light%1(").arg(io);

        //pl3d_light objl=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getlight(io);

       /* QString nameo="";
        switch(objl->type)
        {
            case l_lamp:
                nameo="lamp";
            break;
            case l_sun:
                nameo="sun";
            break;
            case l_spot:
                nameo="spot";
            break;
            case l_directional:
                nameo="directional";
            break;

        }



        nameo.append(")");
        name.append(nameo);


        QStandardItem *ligthlabel = new QStandardItem(name);
        QVariant *odata= new QVariant(QVariant::Int,&io);



        ligthlabel->setData(*odata);
        ligthlabel->setEditable(false);
        lightitem->appendRow(ligthlabel);
*/
    }

   // sceneitem->appendRow(lightitem);
}
void insertObject::updateMainGroups()
{
    QStandardItemModel * mymodel=( QStandardItemModel *)m_ui->treeViewMain->model();
    QStandardItem *rootNode = mymodel->invisibleRootItem();

    //defining a couple of items

    QStandardItem *sceneitem = rootNode->child(0);

    QStandardItem *groupitem = sceneitem->child(1);

    groupitem->setEditable(false);

    groupitem->removeRows(0,groupitem->rowCount());

    /*int gsize=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getsizegroups();
    for(int io=0; io < gsize; io++ )
    {
        std::vector<int> olist=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getgroup(io)->getList();
        std::vector<int>::iterator it;
        QString name=QString("group%1(").arg(io);



        QString nameo=QString("%1").arg(olist.size());

        nameo.append(")");

        name.append(nameo);


        QStandardItem *grouplabel = new QStandardItem(name);
        QVariant *odata= new QVariant(QVariant::Int,&io);

        for(it=olist.begin();it!=olist.end(); ++it)
        {
            pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject((*it));
            QString nameobjg;//=QString("object(%1)").arg(obj->getname().c_str());
            QStandardItem * ogroup= new QStandardItem(nameobjg);
            QVariant *obdata= new QVariant(QVariant::Int,&(*it));

            ogroup->setData(*obdata);
            ogroup->setEditable(false);

            grouplabel->appendRow(ogroup);


        }



        grouplabel->setData(*odata);
        grouplabel->setEditable(false);
        groupitem->appendRow(grouplabel);*/

    //}

   // sceneitem->appendRow(groupitem);

    updateMainObjects();
}

void insertObject::updateMainMaterials()
{
    QStandardItemModel * mymodel=( QStandardItemModel *)m_ui->treeViewMain->model();
    QStandardItem *rootNode = mymodel->invisibleRootItem();



    QStandardItem *sceneitem = rootNode->child(0);


    QStandardItem *materialitem = sceneitem->child(3);

    materialitem->setEditable(false);

    materialitem->removeRows(0,materialitem->rowCount());


    /*for(int io=0; io < m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getsizematerials(); io++ )
    {
        QString name=QString("material%1(").arg(io);


        QString nameo="";

        nameo.append(")");
        name.append(nameo);


        QStandardItem *materiallabel = new QStandardItem(name);
        QVariant *odata= new QVariant(QVariant::Int,&io);



        materiallabel->setData(*odata);
        materiallabel->setEditable(false);
        materialitem->appendRow(materiallabel);

    }

    sceneitem->appendRow(materialitem);*/
}
void insertObject::initMainDock(QStandardItemModel* maintreemodel,Ui::MainWindow *ui)
{
    maintreemodel->setObjectName(tr("Main scene"));

    maintreemodel->clear();

    QStandardItem *rootNode = maintreemodel->invisibleRootItem();

    QStandardItem *sceneitem = new QStandardItem("Main scene");
    sceneitem->removeRows(0,sceneitem->rowCount());

    sceneitem->setEditable(false);
    //sceneitem->

    QStandardItem *objectitem = new QStandardItem("Objects");

    objectitem->setEditable(false);

    sceneitem->appendRow(objectitem);

    QStandardItem *groupitem = new QStandardItem("Groups");

    groupitem->setEditable(false);

    sceneitem->appendRow(groupitem);

    QStandardItem *lightitem = new QStandardItem("Lights");

    lightitem->setEditable(false);

    sceneitem->appendRow(lightitem);

    QStandardItem *materialitem = new QStandardItem("Materials");

    materialitem->setEditable(false);

    sceneitem->appendRow(materialitem);

    QStandardItem *textureitem = new QStandardItem("Textures");

    textureitem->setEditable(false);

    sceneitem->appendRow(textureitem);

    QStandardItem*cameraitem = new QStandardItem("Telecamera");

    cameraitem->setEditable(false);

    sceneitem->appendRow(cameraitem);


    QStandardItem *animationitem = new QStandardItem("Animations");


    animationitem->setEditable(false);

    QStandardItem *animationitemobject = new QStandardItem("Objects");

    animationitemobject->setEditable(false);

    //to-do

    QStandardItem *animationitemscene = new QStandardItem("Scene");

    animationitemscene->setEditable(false);
    /*to-do
    for(int io=0; io < mp_opengl->m_ui->mainwidget->pscene->GetSizeAnimation(); io++ )
    {
        QString name=QString("anim(%d)").arg(io);;

        QStandardItem *animlabel = new QStandardItem(name);

        animationitemscene->appendRow(animlabel);

    }*/

    animationitem->appendRow(animationitemscene);

    animationitem->appendRow(animationitemobject);

    sceneitem->appendRow(animationitem);

    rootNode->appendRow(sceneitem);


    ui->treeViewMain->setModel(maintreemodel);

}

void insertObject::updateMainDock(QStandardItemModel* maintreemodel,Ui::MainWindow *ui)
{




    updateMainObjects();
    updateMainGroups();
    updateMainLights();
    updateMainMaterials();
    updateMainTelecamera();
    //QStandardItem * objectitem=sceneitem->child(0);


    //sceneitem->setEditable(false);


    //load objects

    //updateMainObjects(sceneitem);

    //updateMainLights(sceneitem);




    //sceneitem->appendRow(ligthitem);



    //QStandardItem *cameraitem = new QStandardItem("Camera");
    /*to-do
    for(int io=0; io < mp_opengl->m_ui->mainwidget->pscene->GetSizeTelecamera(); io++ )
    {
        QString name=QString("camera(%d)").arg(io);;

        QStandardItem *cameralabel = new QStandardItem(name);

        cameraitem->appendRow(cameralabel);

    }
    */
    /*cameraitem->setEditable(false);

    sceneitem->appendRow(cameraitem);


    QStandardItem *materialitem = new QStandardItem("Material");

    materialitem->setEditable(false);
    //to-do
    /*for(int io=0; io < mp_opengl->m_ui->mainwidget->pscene->m_telecamera.size(); io++ )
    {
        QString name;
        name.append("camera(%d)",io);
        QStandardItem *cameralabel = new QStandardItem(name);

        cameraitem->appendRow(cameralabel);

    }

    sceneitem->appendRow(materialitem);

    QStandardItem *textureitem = new QStandardItem("Textures");

    textureitem->setEditable(false);

    sceneitem->appendRow(textureitem);

    QStandardItem *animationitem = new QStandardItem("Animations");


    animationitem->setEditable(false);

    QStandardItem *animationitemobject = new QStandardItem("Objects");

    animationitemobject->setEditable(false);

    //to-do

    QStandardItem *animationitemscene = new QStandardItem("Scene");

    animationitemscene->setEditable(false);
    /*to-do
    for(int io=0; io < mp_opengl->m_ui->mainwidget->pscene->GetSizeAnimation(); io++ )
    {
        QString name=QString("anim(%d)").arg(io);;

        QStandardItem *animlabel = new QStandardItem(name);

        animationitemscene->appendRow(animlabel);

    }


    animationitem->appendRow(animationitemscene);

    animationitem->appendRow(animationitemobject);

    sceneitem->appendRow(animationitem);

    rootNode->appendRow(sceneitem);

    //maintreemodel->setVerticalHeaderLabels(tr("Main scene"));

    ui->treeViewMain->setModel(maintreemodel);*/
}

void insertObject::on_actionActinsertcircle_triggered()
{

    //insertcircle *mycircle= new insertcircle();

}

void insertObject::on_actionInsert_circle_triggered()
{
   // insertcircle *icircle;
    qDebug() << "insert circle";
}

void insertObject::on_actionNewcircle_triggered()
{
    qDebug() << "insert circle";
}

void insertObject::on_actionInsert_line_triggered()
{

}

void insertObject::on_actionInsert_line_triggered(bool checked)
{

}



void insertObject::on_view3d_clicked()
{
    reset_view();


    m_ui->view3d->setChecked(true);


    m_ui->mainwidget->pscene->SetScene(SCENE::s3d);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::s3d))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);

}

void insertObject::on_slectmouse_clicked()
{
    m_ui->selectmove->setChecked(false);
    m_ui->selectscale->setChecked(false);
    m_ui->selectrotate->setChecked(false);


    m_ui->selectmouse->setChecked(true);

    m_ui->mainwidget->pscene->setTool(SCENE::st_normal);

}
void insertObject::on_selectmulti_clicked()
{
    m_ui->selectmouse->setChecked(false);
    m_ui->selectscale->setChecked(false);
    m_ui->selectrotate->setChecked(false);
    m_ui->selectmove->setChecked(false);

    m_ui->selectmulti->setChecked(true);

    m_ui->mainwidget->pscene->setTool(SCENE::st_multiselect);
}

void insertObject::on_select_move()
{

    m_ui->selectscale->setChecked(false);
    m_ui->selectrotate->setChecked(false);


    m_ui->selectmove->setChecked(true);

    m_ui->mainwidget->pscene->setTool(SCENE::st_move);

}
void insertObject::on_select_scale()
{



    m_ui->selectrotate->setChecked(false);
    m_ui->selectmove->setChecked(false);

    m_ui->selectscale->setChecked(true);

    m_ui->mainwidget->pscene->setTool(SCENE::st_scale);

}
void insertObject::on_select_rotate()
{

    m_ui->selectmove->setChecked(false);
    m_ui->selectscale->setChecked(false);

    m_ui->selectrotate->setChecked(true);


    m_ui->mainwidget->pscene->setTool(SCENE::st_rotate);

}


void insertObject::selecteditvertex()
{
    m_ui->selectedge->setChecked(false);
    m_ui->selectface->setChecked(false);

    m_ui->selectedge_2->setChecked(false);
    m_ui->selectface_2->setChecked(false);

    m_ui->selectvertex->setChecked(true);
    m_ui->selectvertex_2->setChecked(true);

    m_ui->mainwidget->pscene->SetEditMode(SCENE::vertex);

}
void insertObject::selecteditedge()
{
    m_ui->selectvertex->setChecked(false);
    m_ui->selectface->setChecked(false);

    m_ui->selectvertex_2->setChecked(false);
    m_ui->selectface_2->setChecked(false);

    m_ui->selectedge->setChecked(true);
    m_ui->selectedge_2->setChecked(true);

    m_ui->mainwidget->pscene->SetEditMode(SCENE::line);

}
void insertObject::selecteditface()
{
    m_ui->selectedge->setChecked(false);
    m_ui->selectvertex->setChecked(false);
    m_ui->selectedge_2->setChecked(false);
    m_ui->selectvertex_2->setChecked(false);

    m_ui->selectface->setChecked(true);
    m_ui->selectface_2->setChecked(true);

    m_ui->mainwidget->pscene->SetEditMode(SCENE::polygon);

}
void insertObject::selecteditdelete()
{
    m_ui->mainwidget->pscene->Delete();

    updateMainDock(m_sm,m_ui);
}
void insertObject::selecteditduplicate()
{
    m_ui->mainwidget->pscene->Duplicate();

    updateMainDock(m_sm,m_ui);

}
void insertObject::selecteditinvert()
{
    m_ui->mainwidget->pscene->InvertObjectSelect();
}
void insertObject::setcolor()
{
    //imposta il colore alla mesh selezionata
    QColorDialog cdialog;
    QColor retcolor;
    color ncol;
    if(cdialog.exec()==QDialog::Accepted)
    {
        retcolor=cdialog.selectedColor();
        qreal a,r,g,b,*pa,*pr,*pg,*pb;
        pa=&a;
        pr=&r;
        pg=&g;
        pb=&b;

        retcolor.getRgbF(pr,pg,pb,pa);

        ncol.set(r,g,b,a);

        m_ui->mainwidget->pscene->setColorObject(ncol);

    }

}
void insertObject::addLight()
{
    //m_ui->mainwidget->pscene->AddLight();
}
void insertObject::addLight_sun()
{
    m_ui->mainwidget->pscene->AddLight(l_sun);


    updateMainLights();

}
void insertObject::addLight_spot()
{
    m_ui->mainwidget->pscene->AddLight(l_spot);


    updateMainLights();
}
void insertObject::addLight_lamp()
{
    m_ui->mainwidget->pscene->AddLight(l_lamp);


    updateMainLights();
}
void insertObject::addnullobject()
{
    m_ui->mainwidget->pscene->addNull();
}

void insertObject::on_actionActionNewTorus_triggered()
{
    m_ui->mainwidget->pscene->AddTorus();
}


void insertObject::on_actionSet_material_triggered()
{
    if(m_dlgmaterial==NULL)
    {
        m_dlgmaterial= new DialogMaterial();
        m_dlgmaterial->starttimer();
    }



    if(m_dlgmaterial->exec()==QDialog::Accepted)
    {
        pl3d_material_struct mat=m_dlgmaterial->getmaterial();
        m_ui->mainwidget->pscene->AddObjectMaterial(*mat);

    }

    m_dlgmaterial->stoptimer();

    delete (m_dlgmaterial);

    m_dlgmaterial=NULL;

}

void insertObject::on_modepaint_clicked()
{
    m_ui->modeedit->setChecked(false);
    m_ui->modeanimation->setChecked(false);
    m_ui->modeconsolle->setChecked(false);
    m_ui->modepaint->setChecked(true);
    m_ui->modetexture->setChecked(false);
    m_ui->mode3d->setChecked(false);

    m_ui->mainwidget->pscene->SetMode(SCENE::paint);
}

void insertObject::on_modeedit_clicked()
{

}
void insertObject::viewMaterials()
{
    //QWidget *m_layout=m_ui->swElements->widget(4);

    //1. prelevare la lista dei materiali della scena principale
    //l3d_material * material_list=m_ui->mainwidget->pscene->GetMainSceneMaterials();
    //2. inserirla nel layout con un ciclo
    //m_ui->formLayoutMaterials->;
    //for(int ix=0; ix < material_list->size();ix++)
    {
    //    QHBoxLayout *newlayout= new QHBoxLayout();
    //    littlematerial * lm= new littlematerial();
    //    newlayout->addWidget(lm);
        //m_ui->formLayoutMaterials->addRow(tr("Material"),newlayout);

    }





}

void insertObject::on_actionLightOptions_triggered()
{
   //pl3d_light lselect= m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getlight();

   /*if(lselect==NULL)
       return;

   if(m_loption==NULL)
       m_loption= new lightoptions();

   m_loption->setlight(lselect);
   if(m_loption->exec()==QDialog::Accepted)
   {

   }
   delete (m_loption);
   m_loption=NULL;*/
}
void insertObject::loadGroup(int ig)
{
    //_group=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getgroup(ig);


   /* if(_group)
    {
        m_igroup=ig;
        QString str,name("group"),no;

        str.setNum(ig);

        name.append(str);

        m_ui->labgroupname->setText(name);

        std::vector<int> olist=_group->getList();
        std::vector<int>::iterator io;
        int nobj=olist.size(),nvertex=0,npoly=0;


        no.setNum(nobj);
        m_ui->labgroupobjects->setText(no);

        for(io=olist.begin();io!=olist.end();++io)
        {
            pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject((*io));

            nvertex+=obj->_vertex.size();
            npoly+=obj->_faces.size();
            npoly+=obj->_quad.size();


        }

        str.setNum(nvertex);
        m_ui->labvertex_group->setText(str);

        str.setNum(npoly);
        m_ui->labpoly_group->setText(str);


        m_ui->poswx_group->setValue(_group->getPos().x);
        m_ui->poswy_group->setValue(_group->getPos().y);
        m_ui->poswz_group->setValue(_group->getPos().z);

        m_ui->rotatex_group->setValue(_group->_transformation._rotate.x);
        m_ui->rotatey_group->setValue(_group->_transformation._rotate.y);
        m_ui->rotatez_group->setValue(_group->_transformation._rotate.z);

        m_ui->scalex_group->setValue(_group->_transformation._scale.x);
        m_ui->scaley_group->setValue(_group->_transformation._scale.y);
        m_ui->scalez_group->setValue(_group->_transformation._scale.z);


        m_iobjectgroup=0;
        m_iobjectgroup_first=0;
        m_iobjectgroup_last=_group->getList().size()-1;

        io=olist.begin();
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject((*io));

        str=obj->_name;

        m_ui->le_group_object->setText(str);




    }
    m_igroup_prev=ig;*/

}
void insertObject::updategroupobject(int index)
{


    QString str;

    if(!_group)
        return;
    int nobj=_group->getList().at(index);

    //pl3d_mesh_struct obj2=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

    //str=obj2->_name;
    m_ui->le_group_object->setText(str);

    if(index<0 || index>=_group->getList().size())
        return;


    loadObject(nobj);





}
void insertObject::loadlightvalue()
{
    pl3d_light ilight=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    //prelevare la luce

    QPalette pal=m_ui->colorwidget_light1->palette();
    QColor col;
    col.setRedF(ilight->ambient[0]);
    col.setGreenF(ilight->ambient[1]);
    col.setBlueF(ilight->ambient[2]);
    col.setAlphaF(ilight->ambient[3]);
    pal.setColor(QPalette::Window,col);
    m_ui->colorwidget_light1->setAutoFillBackground(true);
    m_ui->colorwidget_light1->setPalette(pal);
    m_ui->colorwidget_light1->update();

    col.setRedF(ilight->diffuse[0]);
    col.setGreenF(ilight->diffuse[1]);
    col.setBlueF(ilight->diffuse[2]);
    col.setAlphaF(ilight->diffuse[3]);
    pal.setColor(QPalette::Window,col);
    m_ui->colorwidget_light2->setAutoFillBackground(true);
    m_ui->colorwidget_light2->setPalette(pal);
    m_ui->colorwidget_light2->update();

    col.setRedF(ilight->specular[0]);
    col.setGreenF(ilight->specular[1]);
    col.setBlueF(ilight->specular[2]);
    col.setAlphaF(ilight->specular[3]);
    pal.setColor(QPalette::Window,col);
    m_ui->colorwidget_light3->setAutoFillBackground(true);
    m_ui->colorwidget_light3->setPalette(pal);
    m_ui->colorwidget_light3->update();
}

void insertObject::loadlight(int il)
{

    m_ilight=il;

    //m_ui->swElements->setCurrentIndex(3);
    pl3d_light _light=m_ui->mainwidget->pscene->GetpLightSelected(il);
    _light->selected(true);

    //prelevare la luce
    m_ui->pb_light_lamp->setChecked(false);
    m_ui->pb_light_spot->setChecked(false);
    m_ui->pb_light_sun->setChecked(false);
    m_ui->pb_light_directional->setChecked(false);

    switch(_light->type)
    {
    case l_sun:
        m_ui->pb_light_sun->setChecked(true);
        break;
    case l_lamp:
        m_ui->pb_light_lamp->setChecked(true);
        break;
    case l_spot:
        m_ui->pb_light_spot->setChecked(true);
        break;
    case l_directional:
        m_ui->pb_light_directional->setChecked(true);
        break;
    }

    l3d_vertex_fast lpos=_light->m_pos;

    m_ui->poswx_light->setValue(lpos.x);
    m_ui->poswy_light->setValue(lpos.y);
    m_ui->poswz_light->setValue(lpos.z);

    m_ui->hs_ambientred_light->setValue(_light->ambient[0]*100);
    m_ui->hs_ambientgreen_light->setValue(_light->ambient[1]*100);
    m_ui->hs_ambientblue_light->setValue(_light->ambient[2]*100);
    m_ui->hs_ambientalpha_light->setValue(_light->ambient[3]*100);

    m_ui->hs_diffusered_light->setValue(_light->diffuse[0]*100);
    m_ui->hs_diffusegreen_light->setValue(_light->diffuse[1]*100);
    m_ui->hs_diffuseblue_light->setValue(_light->diffuse[2]*100);
    m_ui->hs_diffusealpha_light->setValue(_light->diffuse[3]*100);

    m_ui->hs_specularred_light->setValue(_light->specular[0]*100);
    m_ui->hs_speculargreen_light->setValue(_light->specular[1]*100);
    m_ui->hs_specularblue_light->setValue(_light->specular[2]*100);
    m_ui->hs_specularalpha_light->setValue(_light->specular[3]*100);

    m_ui->hs_exponent_light->setValue(_light->spot_exponent);

    m_ui->hs_degree_light->setValue(_light->spot_cutoff);

    m_ui->sb_distance_light->setValue(_light->spot_distance);

    m_ui->sb_anglea_light->setValue(_light->getanglea());
    m_ui->sb_angleb_light->setValue(_light->getangleb());

    m_ui->pb_light_onoff->toggle();


    loadlightvalue();







}
void insertObject::loadcamera(int icam)
{
    //m_ui->swElements->setCurrentIndex(4);

    /*telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(icam);

    QString str=QString("%1").arg(icam);
    m_ui->le_camera->setText(str);

    m_ui->pb_camera_x->setValue(tel->vpos.GetX());
    m_ui->pb_camera_y->setValue(tel->vpos.GetY());
    m_ui->pb_camera_z->setValue(tel->vpos.GetZ());

*/

}

void insertObject::loadObject(int io)
{
    //m_ui->swElements->setCurrentIndex(1);
    //_mesh_selected=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(io);

    QString name=QString::fromStdString(_mesh_selected->_name);
    QString desc=QString::fromStdString(_mesh_selected->_sub_name);
    int nvert=_mesh_selected->_vertex.size();
    int npoly=_mesh_selected->_quad.size()+_mesh_selected->_faces.size();
    int nline=_mesh_selected->_edges.size();
    QString numvert,numpoly,numline;
    numvert.setNum(nvert);
    numpoly.setNum(npoly);
    numline.setNum(nline);
    m_ui->leName->setText(name);
    m_ui->leName2->setText(desc);

    m_ui->labvertex->setText(numvert);
    m_ui->labpoly->setText(numpoly);
    m_ui->labline_val->setText(numline);
    l3d_vertex_fast wp,scale,rotate;

    if(_mesh_selected->_lgroup==l3d_null)
    {
        wp=_mesh_selected->_transformation._wp;
        scale=_mesh_selected->_transformation._scale;
        rotate=_mesh_selected->_transformation._rotate;
        m_ui->lb_groupn->setText(QString("group:none"));
    }
    else
    {
        wp=_mesh_selected->_transformation._wpgroup;
        scale=_mesh_selected->_transformation._scalegroup;
        rotate=_mesh_selected->_transformation._rotategroup;

        QString g("group:");
        l3d_string cgroup=new char[20];
        ::snprintf(cgroup,20,"%d",_mesh_selected->_id_group);

        g.append(cgroup);

        m_ui->lb_groupn->setText(g);
    }

    m_ui->poswx->setValue(wp.x);
    m_ui->poswy->setValue(wp.y);
    m_ui->poswz->setValue(wp.z);


    m_ui->scalex->setValue(scale.x);
    m_ui->scaley->setValue(scale.y);
    m_ui->scalez->setValue(scale.z);

    m_ui->rotatex->setValue(rotate.x);
    m_ui->rotatey->setValue(rotate.y);
    m_ui->rotatez->setValue(rotate.z);

    l3d_uint sg=_mesh_selected->_vertex_group.size();



    loadmaterial();



}
void insertObject::update()
{
    if(m_ui->mainwidget->pscene->GetMode()==SCENE::edit)
        return;

    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();
    int ngroup=m_ui->mainwidget->pscene->GetiGroupSelectedMainScene();
    int nlight=m_ui->mainwidget->pscene->GetiLightSelectedMainScene();
    int ncam=m_ui->mainwidget->pscene->GetiCameraSelectedMainScene();

    if(nobj!=m_iobject)
        m_imaterial=0;

    _group=l3d_null;
    if(nobj>=0)
        loadObject(nobj);
    if (ngroup>=0)
        loadGroup(ngroup);
    if(nlight>=0 )
        loadlight(nlight);
    if(ncam>=0 )
        loadcamera(ncam);

        //m_ui->swElements->setCurrentIndex(0);



    m_iobject=nobj;

}

void insertObject::on_applyscale_clicked()
{
    //to-do applicare la scala
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        obj->scale();

    }
}

void insertObject::on_scalex_valueChanged(double arg1)
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        obj->_transformation._scale.x=arg1;

    }


}

void insertObject::on_scaley_valueChanged(double arg1)
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        obj->_transformation._scale.y=arg1;

    }
}

void insertObject::on_scalez_valueChanged(double arg1)
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        obj->_transformation._scale.z=arg1;

    }
}

void insertObject::on_poswx_valueChanged(double arg1)
{


    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._wp.x=arg1;
        else
            _mesh_selected->_transformation._wpgroup.x=arg1;

    }

}

void insertObject::on_poswy_valueChanged(double arg1)
{
    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._wp.y=arg1;
        else
            _mesh_selected->_transformation._wpgroup.y=arg1;

    }

}

void insertObject::on_poswz_valueChanged(double arg1)
{
    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._wp.z=arg1;
        else
            _mesh_selected->_transformation._wpgroup.z=arg1;

    }

}

void insertObject::on_rotatex_valueChanged(double arg1)
{
    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._rotate.x=arg1;
        else
            _mesh_selected->_transformation._rotategroup.x=arg1;

    }
}

void insertObject::on_rotatey_valueChanged(double arg1)
{
    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._rotate.y=arg1;
        else
            _mesh_selected->_transformation._rotategroup.y=arg1;

    }
}

void insertObject::on_rotatez_valueChanged(double arg1)
{
    if(_mesh_selected)
    {

        if(_mesh_selected->_id_group==-1)
            _mesh_selected->_transformation._rotate.z=arg1;
        else
            _mesh_selected->_transformation._rotategroup.z=arg1;

    }
}

void insertObject::on_leName_textChanged(const QString &arg1)
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        //obj->_name =arg1.toStdString();
        //obj->_sub_name=m_ui->leName2->text().toStdString();

    }
}

void insertObject::on_leName2_textChanged(const QString &arg1)
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        //obj->_name=m_ui->leName->text().toStdString();
        //obj->_sub_name=arg1.toStdString();


    }
}

void insertObject::on_applyrotate_clicked()
{
    int nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();

    if(nobj>=0)
    {
        pl3d_mesh_struct obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

        //obj->ApplicaRotazione();

    }

}

void insertObject::on_pbFlat_clicked()
{
    if(_mesh_selected)
    {


        _mesh_selected->_display->smooth=true;
        //obj->SetSmooth(false);

    }
}

void insertObject::on_pbFlat_2_clicked()
{


    if(_mesh_selected)
    {


        _mesh_selected->_display->smooth=false;
        //obj->SetSmooth(false);

    }
}


void insertObject::on_mainwidget_clicked()
{

}

void insertObject::on_hsambientr_valueChanged(int value)
{


    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_ambient[0]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}



void insertObject::on_hsambientg_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_ambient[1]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsambientb_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_ambient[2]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsambienta_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_ambient[3]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_pb_addmaterial_clicked()
{




    if(_mesh_selected)
    {
        _mesh_selected->_material.addnew();
        //m_imaterial++;
    }


    loadmaterial();



}
void insertObject::loadmaterialvalue()
{
    if(_imaterial)
    {



        QPalette pal=m_ui->colorwidget->palette();
        QColor col;
        col.setRedF(_imaterial->mat_ambient[0]);
        col.setGreenF(_imaterial->mat_ambient[1]);
        col.setBlueF(_imaterial->mat_ambient[2]);
        col.setAlphaF(_imaterial->mat_ambient[3]);
        pal.setColor(QPalette::Window,col);
        m_ui->colorwidget->setAutoFillBackground(true);
        m_ui->colorwidget->setPalette(pal);
        m_ui->colorwidget->update();

        col.setRedF(_imaterial->mat_diffuse[0]);
        col.setGreenF(_imaterial->mat_diffuse[1]);
        col.setBlueF(_imaterial->mat_diffuse[2]);
        col.setAlphaF(_imaterial->mat_diffuse[3]);
         pal.setColor(QPalette::Window,col);
        m_ui->colorwidget1->setAutoFillBackground(true);
        m_ui->colorwidget1->setPalette(pal);
        m_ui->colorwidget1->update();

        col.setRedF(_imaterial->mat_emission[0]);
        col.setGreenF(_imaterial->mat_emission[1]);
        col.setBlueF(_imaterial->mat_emission[2]);
        col.setAlphaF(_imaterial->mat_emission[3]);
        pal.setColor(QPalette::Window,col);
        m_ui->colorwidget2->setAutoFillBackground(true);
        m_ui->colorwidget2->setPalette(pal);
        m_ui->colorwidget2->update();

        col.setRedF(_imaterial->mat_specular[0]);
        col.setGreenF(_imaterial->mat_specular[1]);
        col.setBlueF(_imaterial->mat_specular[2]);
        col.setAlphaF(_imaterial->mat_specular[3]);
        pal.setColor(QPalette::Window,col);
        m_ui->colorwidget3->setAutoFillBackground(true);
        m_ui->colorwidget3->setPalette(pal);
        m_ui->colorwidget3->update();

    }

}

void insertObject::loadmaterial()
{
    _imaterial=_mesh_selected->_material.get(m_imaterial);



    if(_imaterial)
    {
        loadmaterialvalue();





        //load material hsdiffusea


        m_ui->hsambientr->setValue(_imaterial->mat_ambient[0]*100.0F);
        m_ui->hsambientg->setValue(_imaterial->mat_ambient[1]*100.0F);
        m_ui->hsambientb->setValue(_imaterial->mat_ambient[2]*100.0F);
        m_ui->hsambienta->setValue(_imaterial->mat_ambient[3]*100.0F);

        m_ui->hsdiffuser->setValue(_imaterial->mat_diffuse[0]*100.0F);
        m_ui->hsdiffuseg->setValue(_imaterial->mat_diffuse[1]*100.0F);
        m_ui->hsdiffuseb->setValue(_imaterial->mat_diffuse[2]*100.0F);
        m_ui->hsdiffusea->setValue(_imaterial->mat_diffuse[3]*100.0F);

        m_ui->hsspecularr->setValue(_imaterial->mat_specular[0]*100.0F);
        m_ui->hsspecularg->setValue(_imaterial->mat_specular[1]*100.0F);
        m_ui->hsspecularb->setValue(_imaterial->mat_specular[2]*100.0F);
        m_ui->hsspeculara->setValue(_imaterial->mat_specular[3]*100.0F);

        m_ui->hsemittedr->setValue(_imaterial->mat_emission[0]*100.0F);
        m_ui->hsemittedg->setValue(_imaterial->mat_emission[1]*100.0F);
        m_ui->hsemittedb->setValue(_imaterial->mat_emission[2]*100.0F);
        m_ui->hsemitteda->setValue(_imaterial->mat_emission[3]*100.0F);

        m_ui->hsshininnis->setValue(_imaterial->mat_shininess[0]*100.0F);

        m_ui->cb_ambientdiffuse->setChecked(_imaterial->m_bambientanddiffuse);


        QString str;
        str.setNum(m_imaterial);
        m_ui->le_nummaterial->setText(str);


    }

}

void insertObject::on_pb_prevmaterial_clicked()
{
    if(m_imaterial-1<0)
        return;

    if(_mesh_selected->_material.get(m_imaterial-1)!=l3d_null)
    {
        _imaterial=_mesh_selected->_material.get(m_imaterial-1);

        m_imaterial--;

        loadmaterial();
    }
}

void insertObject::on_pb_nextmaterial_clicked()
{

    if(_mesh_selected->_material.get(m_imaterial+1)!=l3d_null)
    {
        _imaterial=_mesh_selected->_material.get(m_imaterial+1);
        m_imaterial++;

        loadmaterial();
    }



}

void insertObject::on_hsdiffuser_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_diffuse[0]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsdiffuseg_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_diffuse[1]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsdiffuseb_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_diffuse[2]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsdiffusea_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_diffuse[3]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_pb_setmaterial_clicked()
{

    if(_mesh_selected)
    {
        _mesh_selected->set_material_all(m_imaterial);
    }
}

void insertObject::on_hsemittedr_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_emission[0]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsemittedg_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_emission[1]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsemittedb_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_emission[2]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsemitteda_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_emission[3]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsspecularr_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_specular[0]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsspecularg_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_specular[1]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsspecularb_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_specular[2]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_hsspeculara_valueChanged(int value)
{
    if(_imaterial)
    {
       // object3d *obj=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);
       // material * appm=obj->getmaterial(m_imaterial);

        _imaterial->mat_specular[3]=(float)value/100.0F;
       // appm->mat_ambient[0]=(float)value/100.0F;

       loadmaterialvalue();

    }
}

void insertObject::on_pb_preview_material_clicked()
{



     if(m_dlgmaterial==NULL)
    {
        m_dlgmaterial= new DialogMaterial();
        m_dlgmaterial->setWindowTitle("Material preview");


        m_dlgmaterial->setmaterial(_imaterial);
        m_dlgmaterial->starttimer();
    }



    if(m_dlgmaterial->exec()==QDialog::Accepted)
        m_dlgmaterial->stoptimer();

    delete (m_dlgmaterial);

    m_dlgmaterial=NULL;


}



void insertObject::on_groupBox_clicked()
{

}

void insertObject::on_selecteditmerge_clicked()
{
    m_ui->mainwidget->pscene->MergeObjectsSelected();
    updateMainObjects();
}
void insertObject::on_selecteditextrude_clicked()
{
    m_ui->mainwidget->pscene->Extrude(1);
}

void insertObject::on_actionSave_mesh_triggered()
{
    string filename;
  //  vector<int> olist=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getListObjectsSelected();
  //  vector<int> glist=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getListGroupsSelected();

    vector<int>::iterator io;
    vector<int>::iterator ig;

    //for(io=olist.begin();io!=olist.end();++io)
    {
        filename=QFileDialog::getSaveFileName(0,
        tr("Save mesh"),"./",tr("Mesh Files (*.l3m)")).toStdString();

      //  m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->savemesh(filename,0//oggetto
                                        //                   ,(*io));

    }

    //for(ig=glist.begin();ig!=glist.end();++ig)
    {
        filename=QFileDialog::getSaveFileName(0,
        tr("Save mesh"),"./",tr("Mesh Files (*.l3m)")).toStdString();

       // m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->savemesh(filename,1//gruppo
        //                                                   ,(*ig));

    }













}

void insertObject::on_actionLoad_mesh_triggered()
{
    string filename;

    filename=QFileDialog::getOpenFileName(0,
    tr("Load mesh"),"./mesh",tr("Mesh Files (*.l3m)")).toStdString();

    //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->loadmesh(filename);

    updateMainObjects();
    updateMainGroups();
}

void insertObject::on_selecteditGroup_clicked()
{
    m_ui->mainwidget->pscene->Group();
    updateMainGroups();
}

void insertObject::on_selecteditUnGroup_clicked()
{
    m_ui->mainwidget->pscene->UnGroup();
    updateMainGroups();
}

void insertObject::on_actionSphere_triggered()
{

}

void insertObject::on_pb_group_first_clicked()
{
    m_iobjectgroup=m_iobjectgroup_first;
    updategroupobject(m_iobjectgroup_first);
}

void insertObject::on_pb_group_last_clicked()
{
    m_iobjectgroup=m_iobjectgroup_last;
    updategroupobject(m_iobjectgroup_last);
}

void insertObject::on_pb_group_prev_clicked()
{
    if(m_iobjectgroup-1 >= 0)
        m_iobjectgroup--;
    updategroupobject(m_iobjectgroup);
}

void insertObject::on_pb_group_next_clicked()
{
    if(m_iobjectgroup+1 <= m_iobjectgroup_last)
        m_iobjectgroup++;
    updategroupobject(m_iobjectgroup);
}

void insertObject::on_poswx_group_object_valueChanged(double arg1)
{

    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

       // pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._wpgroup.x=arg1;

    }
}

void insertObject::on_poswy_group_object_valueChanged(double arg1)
{
    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

        //pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._wpgroup.y=arg1;

    }
}

void insertObject::on_poswz_group_object_valueChanged(double arg1)

{

    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

       // pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._wpgroup.z=arg1;

    }
}

void insertObject::on_scalex_group_object_valueChanged(double arg1)
{


    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

        //pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._scalegroup.x=arg1;

    }

}

void insertObject::on_scaley_group_object_valueChanged(double arg1)
{

    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

        //pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._scalegroup.y=arg1;

    }
}

void insertObject::on_scalez_group_object_valueChanged(double arg1)
{

    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

        //pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._scalegroup.z=arg1;

    }
}

void insertObject::on_rotatex_group_object_valueChanged(double arg1)
{

    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

       // pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

       // obj->_transformation._rotategroup.x=arg1;

    }
}

void insertObject::on_rotatey_group_object_valueChanged(double arg1)
{
    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

        //pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

        //obj->_transformation._rotategroup.y=arg1;

    }

}

void insertObject::on_rotatez_group_object_valueChanged(double arg1)
{
    int index=m_ui->le_group_object->text().toInt();

    if(_group)
    {
        int nobj=_group->getList().at(index);

       // pl3d_mesh_struct obj=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj);

       // obj->_transformation._rotategroup.z=arg1;

    }

}
void insertObject::getgroup()
{
    //m_igroup=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getiGroupSelected();
}

void insertObject::on_selecteditall_clicked()
{
    m_ui->mainwidget->pscene->SelectAll();
}

void insertObject::on_pb_smooth_group_clicked()
{

    if(_group)
        m_ui->mainwidget->pscene->SetSmoothGroup(m_igroup);
}

void insertObject::on_poswx_group_valueChanged(double arg1)
{

    if(_group)
    {
        l3d_vertex_fast v= _group->getPos();

        v.x=arg1;

        _group->setPos(v);


    }


}

void insertObject::on_poswy_group_valueChanged(double arg1)
{
    if(_group)
    {
        l3d_vertex_fast v= _group->getPos();

        v.y=arg1;

        _group->setPos(v);


    }
}

void insertObject::on_poswz_group_valueChanged(double arg1)
{

    if(_group)
    {
        l3d_vertex_fast v= _group->getPos();

        v.z=arg1;

        _group->setPos(v);


    }
}

void insertObject::on_scalex_group_valueChanged(double arg1)
{
    if(_group)
    {


        _group->_transformation._scale.x=arg1;


    }
}

void insertObject::on_scaley_group_valueChanged(double arg1)
{
    if(_group)
    {


        _group->_transformation._scale.y=arg1;


    }
}

void insertObject::on_scalez_group_valueChanged(double arg1)
{
    if(_group)
    {


        _group->_transformation._scale.z=arg1;


    }
}

void insertObject::on_rotatex_group_valueChanged(double arg1)
{
    if(_group)
    {

        _group->_transformation._rotate.x=arg1;




    }
}

void insertObject::on_rotatey_group_valueChanged(double arg1)
{
    if(_group)
    {

        _group->_transformation._rotate.y=arg1;




    }

}

void insertObject::on_rotatez_group_valueChanged(double arg1)
{

    if(_group)
    {

        _group->_transformation._rotate.z=arg1;




    }
}

void insertObject::on_pb_light_sun_toggled(bool checked)
{


}

void insertObject::on_pb_light_lamp_toggled(bool checked)
{


}

void insertObject::on_pb_light_spot_toggled(bool checked)
{


}

void insertObject::on_pb_light_directional_toggled(bool checked)
{



}

void insertObject::on_pb_light_onoff_toggled(bool checked)
{


}

void insertObject::on_hs_ambientred_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->ambient[0]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_ambientgreen_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->ambient[1]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_ambientblue_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->ambient[2]=(float)value/100.0F;

    loadlightvalue();
}
void insertObject::on_hs_ambientalpha_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->ambient[3]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_diffusered_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->diffuse[0]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_diffusegreen_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->diffuse[1]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_diffuseblue_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->diffuse[2]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_diffusealpha_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->diffuse[3]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_specularred_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->specular[0]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_speculargreen_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->specular[1]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_specularblue_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->specular[2]=(float)value/100.0F;

    loadlightvalue();
}

void insertObject::on_hs_specularalpha_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->specular[3]=(float)value/100.0F;

    loadlightvalue();

}

void insertObject::on_hs_exponent_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->spot_exponent=(float)value;

}



void insertObject::on_hs_degree_light_valueChanged(int value)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->setcutoff(value);
}

void insertObject::on_poswx_light_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l3d_vertex_fast v=l->m_pos;
    v.x=arg1;

    l->move(v);
}

void insertObject::on_poswy_light_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l3d_vertex_fast v=l->m_pos;
    v.y=arg1;
    l->move(v);
}

void insertObject::on_poswz_light_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l3d_vertex_fast v=l->m_pos;
    v.z=arg1;
    l->move(v);
}

void insertObject::on_poswx_group_3_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->spotdir[0]=arg1;
}

void insertObject::on_poswy_group_3_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->spotdir[1]=arg1;
}

void insertObject::on_poswz_group_3_valueChanged(double arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if(l==NULL)
        return;
    l->spotdir[2]=arg1;
}

void insertObject::on_pb_light_sun_clicked()
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);


    if (l==NULL)
        return;
    l->settype(l_sun);

    m_ui->pb_light_lamp->setChecked(false);
    m_ui->pb_light_spot->setChecked(false);
    m_ui->pb_light_directional->setChecked(false);
}

void insertObject::on_pb_light_lamp_clicked()
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;
    l->settype(l_lamp);

    m_ui->pb_light_sun->setChecked(false);
    m_ui->pb_light_spot->setChecked(false);
    m_ui->pb_light_directional->setChecked(false);
}

void insertObject::on_pb_light_spot_clicked()
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;

    l->settype(l_spot);

    m_ui->pb_light_lamp->setChecked(false);
    m_ui->pb_light_sun->setChecked(false);
    m_ui->pb_light_directional->setChecked(false);
}

void insertObject::on_pb_light_directional_clicked()
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;
    l->settype(l_directional);

    m_ui->pb_light_lamp->setChecked(false);
    m_ui->pb_light_spot->setChecked(false);
    m_ui->pb_light_sun->setChecked(false);
}

void insertObject::on_sb_distance_light_valueChanged(int arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);

    if (l==NULL)
        return;

    l->setdistance( m_ui->sb_distance_light->value());

}

void insertObject::on_sb_anglea_light_valueChanged(int arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;

    l->setanglea(arg1);

}

void insertObject::on_sb_angleb_light_valueChanged(int arg1)
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;

    l->setangleb(arg1);

}

void insertObject::on_pb_light_onoff_clicked()
{
    pl3d_light l=m_ui->mainwidget->pscene->GetpLightSelected(m_ilight);
    if (l==NULL)
        return;

    l->onoff(true);
    m_ui->pb_light_onoff->toggle();
}

void insertObject::on_pb_object_normals_clicked()
{

    if(_mesh_selected)
    {
        _mesh_selected->faces_normals();
        //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj)->CalcNormal();
    }
}

void insertObject::on_actionAdd_light_triggered()
{
    m_ui->mainwidget->pscene->AddLight(l_lamp);


    updateMainLights();
}

void insertObject::on_actionAdd_telecamera_triggered()
{
    //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->addCamera();


    updateMainTelecamera();
}

void insertObject::on_viewtelecamera_clicked()
{
    reset_view();

    m_ui->viewtelecamera->setChecked(true);

    m_ui->mainwidget->pscene->SetScene(SCENE::stelecamera);
}

void insertObject::on_pb_camera_up_clicked()
{
    int ntel=m_ui->mainwidget->pscene->GetiCameraSelectedMainScene();

    if(ntel>=0)
    {
        //telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

        //tel->up();
    }
}

void insertObject::on_pb_camera_down_clicked()
{
    int ntel=m_ui->mainwidget->pscene->GetiCameraSelectedMainScene();
    if(ntel>=0)
    {
        //telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

        //tel->down();

    }
}

void insertObject::on_pb_camera_left_clicked()
{
    int ntel=m_ui->mainwidget->pscene->GetiCameraSelectedMainScene();
    if(ntel>=0)
    {
        //telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

        //tel->left();

    }
}

void insertObject::on_pb_camera_right_clicked()
{
    int ntel=m_ui->mainwidget->pscene->GetiCameraSelectedMainScene();
    if(ntel>=0)
    {
        //telecamera *tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

        //tel->right();
    }

}

void insertObject::on_pb_camera_first_clicked()
{

    //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->firstcamera();

    //int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

    //if(ntel==-1)
     //   return;

    //loadcamera(ntel);
}

void insertObject::on_pb_camera_prev_clicked()
{

   // m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->prevcamera();

   // int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

   // if(ntel==-1)
   //     return;

   // loadcamera(ntel);

}

void insertObject::on_pb_camera_next_clicked()
{

   // m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->nextcamera();

   // int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

   // if(ntel==-1)
   //     return;

   // loadcamera(ntel);

}

void insertObject::on_pb_camera_last_clicked()
{

   // m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->lastcamera();

   // int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

   // if(ntel==-1)
   //     return;

   // loadcamera(ntel);
}

void insertObject::on_pb_camera_x_valueChanged(double arg1)
{
    //int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();
    //if(ntel==-1)
    //    return;

   // telecamera * tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

    //tel->vpos.SetX(arg1);

}

void insertObject::on_pb_camera_y_valueChanged(double arg1)
{
   // int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

  //  if(ntel==-1)
  //      return;

  //  telecamera * tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

    //tel->vpos.SetY(arg1);
}

void insertObject::on_pb_camera_z_valueChanged(double arg1)
{
    //int ntel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->geticamera();

    //if(ntel==-1)
        return;

   // telecamera * tel=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getpcamera(ntel);

    //tel->vpos.SetZ(arg1);
}

void insertObject::on_actionspheredlg_triggered()
{

}

void insertObject::on_pb_edit_extrude_clicked()
{
    int ex=-1;
    if(m_ui->rb_extrude_x->isChecked())
        ex=0;
    if(m_ui->rb_extrude_y->isChecked())
        ex=1;
    if(m_ui->rb_extrude_z->isChecked())
        ex=2;
    if(m_ui->rb_extrude_normal->isChecked())
        ex=3;

    m_ui->mainwidget->pscene->Extrudevertex(ex);

}

void insertObject::on_pb_edit_invert_face_clicked()
{

    if(_mesh_selected)
    {
        _mesh_selected->invert_quad();
        //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj)->invertface();
    }

}

void insertObject::on_selectvertex_2_clicked()
{

}

void insertObject::on_selectvertex_clicked()
{

}

void insertObject::on_pb_edit_all_clicked()
{
    m_ui->mainwidget->pscene->OnKeyDown(65,0,0);

}

void insertObject::on_pb_edit_delete_clicked()
{
    m_ui->mainwidget->pscene->DeleteEdit();
}

void insertObject::on_pb_edit_invert_clicked()
{
    m_ui->mainwidget->pscene->InvertObjectSelect();
}

void insertObject::on_modetexture_clicked()
{
    //to-do insert code for texture mode

    m_ui->modeedit->setChecked(false);
    m_ui->modeanimation->setChecked(false);
    m_ui->modeconsolle->setChecked(false);
    m_ui->modepaint->setChecked(false);
    m_ui->modetexture->setChecked(true);
    m_ui->mode3d->setChecked(false);

    //m_ui->swElements->setCurrentIndex(5);

    m_ui->mainwidget->pscene->SetMode(SCENE::texture);
}

void insertObject::on_mode3d_clicked()
{

}

void insertObject::on_viewsolid_clicked()
{

}

void insertObject::on_pb_insertprevius_clicked()
{
    //m_ui->mainwidget->pscene->m_insert->prev();
}

void insertObject::on_pb_insertnext_clicked()
{
    //m_ui->mainwidget->pscene->m_insert->next();
}

void insertObject::on_pb_insertobject_clicked()
{

}

void insertObject::on_view_wireframe_toggled(bool checked)
{
    if (checked)
    {
        m_ui->view_wireframe->setChecked(false);
        //m_ui->mainwidget->pscene->m_insert->iswireframe=true;
    }


}

void insertObject::on_view_solid_toggled(bool checked)
{
    if (checked)
    {
        m_ui->view_solid->setChecked(false);
        //m_ui->mainwidget->pscene->m_insert->iswireframe=false;
    }
}
void insertObject::reset_view()
{
    m_ui->view3d->setChecked(false);
    m_ui->viewtop->setChecked(false);
    m_ui->viewbottom->setChecked(false);
    m_ui->viewleft->setChecked(false);
    m_ui->viewrigth->setChecked(false);
    m_ui->viewfront->setChecked(false);
    m_ui->viewback->setChecked(false);
    m_ui->viewtree->setChecked(false);
    m_ui->viewtelecamera->setChecked(false);

}

void insertObject::on_viewtree_clicked()
{
    reset_view();
    m_ui->viewtree->setChecked(true);

    m_ui->mainwidget->pscene->SetScene(SCENE::sall);

}

void insertObject::on_viewtop_clicked()
{
    reset_view();
    m_ui->viewtop->setChecked(true);

    m_ui->mainwidget->pscene->SetScene(SCENE::stop);
    if(m_ui->mainwidget->pscene->isOrtho(SCENE::stop))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_viewbottom_clicked()
{
    reset_view();
    m_ui->viewbottom->setChecked(true);
    m_ui->mainwidget->pscene->SetScene(SCENE::sbottom);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::sbottom))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_viewleft_clicked()
{
    reset_view();
    m_ui->viewleft->setChecked(true);
    m_ui->mainwidget->pscene->SetScene(SCENE::sleft);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::sleft))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_viewrigth_clicked()
{
    reset_view();
    m_ui->viewrigth->setChecked(true);
    m_ui->mainwidget->pscene->SetScene(SCENE::sright);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::sright))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_actionObjectImport_triggered()
{
    importobject imo;

    imo.exec();

    int fsel;
    std::string filename;

    imo.getobject(&fsel,&filename);

    if(fsel==-1)
        return;

    TypeObjectImport to=(TypeObjectImport)fsel;
    switch(to)
    {
        case md2_model:
            m_ui->mainwidget->pscene->ImportModel_md2(filename);

        break;
        case md2_player:
            m_ui->mainwidget->pscene->ImportPlayer_md2(filename);
        break;
    case m3ds_file:
        m_ui->mainwidget->pscene->Import3ds_file(filename);
        break;
    }




}

void insertObject::on_animationnew_clicked()
{
    NewAnimation na;

    if(na.exec()==QDialog::Accepted &&( na._type==0 || na._type==1 ))
    {


        if(na._type==0)
        {

            animate newani(na._name);

            m_ui->mainwidget->pscene->AddAnimation(newani);

        }
        if(na._type==1)
        {

            //to-do add object animated

        }
    }


}

void insertObject::on_pb_edit_extrude_edge_clicked()
{
    int ex=-1;
    if(m_ui->rb_extrude_x->isChecked())
        ex=0;
    if(m_ui->rb_extrude_y->isChecked())
        ex=1;
    if(m_ui->rb_extrude_z->isChecked())
        ex=2;
    if(m_ui->rb_extrude_normal->isChecked())
        ex=3;

    m_ui->mainwidget->pscene->Extrudeedge(ex);

}

void insertObject::on_pb_edit_extrude_edge_individual_clicked()
{
    int ex=-1;
    if(m_ui->rb_extrude_x->isChecked())
        ex=0;
    if(m_ui->rb_extrude_y->isChecked())
        ex=1;
    if(m_ui->rb_extrude_z->isChecked())
        ex=2;
    if(m_ui->rb_extrude_normal->isChecked())
        ex=3;

    m_ui->mainwidget->pscene->Extrudeedgeind(ex);
}

void insertObject::on_pb_addtexture_clicked()
{

}

void insertObject::on_pb_addvertexgroup_clicked()
{
    QString appstr=m_ui->le_vertexgroup_name->text();
    string nameg=m_ui->le_vertexgroup_name->text().toStdString();

    if(appstr.count()==0 || !appstr.compare("<noname>"))
    {
        QMessageBox qm;

        qm.setWindowTitle(QString("Look3d"));
        qm.setDefaultButton(QMessageBox::Ok);
        qm.setText(QString("insert a valid name for the vertex group"));

        qm.exec();
        return;
    }

    if(_mesh_selected)
    {
        _mesh_selected->addvertexgroup( nameg);
        string n=_mesh_selected->_vertex_group.get_sname();
        QString sn;
        sn.append(n.c_str());
        m_ui->le_vertexgroup_view->setText(sn);

    }


}

void insertObject::on_pb_vertexgroup_set_clicked()
{
    if(_mesh_selected)
        _mesh_selected->set_group();

}

void insertObject::on_pb_vertexgroupprev_clicked()
{
    if(_mesh_selected)
    {
        if(_mesh_selected->_vertex_group.size()==0)
            return;
        _mesh_selected->_vertex_group.prev_group();
        string n=_mesh_selected->_vertex_group.get_sname();
        QString sn;
        sn.append(n.c_str());
        m_ui->le_vertexgroup_view->setText(sn);

    }




}

void insertObject::on_pb_vertexgroupnext_clicked()
{

    if(_mesh_selected)
    {
        if(_mesh_selected->_vertex_group.size()==0)
            return;
        _mesh_selected->_vertex_group.next_group();
        string n=_mesh_selected->_vertex_group.get_sname();
        QString sn;
        sn.append(n.c_str());
        m_ui->le_vertexgroup_view->setText(sn);

    }


}

void insertObject::on_pb_vertexgroup_del_clicked()
{
    if(_mesh_selected)
        _mesh_selected->del_group();

}

void insertObject::on_pb_vertexgroup_select_clicked()
{
    if(_mesh_selected)
        _mesh_selected->select_group();

}

void insertObject::on_add_bezierline_clicked()
{
    //m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->addbezierline();
}

void insertObject::on_add_mesh_null_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_null,NULL);

    //aggiungere gli oggetti nulli inseriti nella combobox dello spin cbPoint

    m_ui->cbPoint->clear();

    m_ui->cbPoint->addItem(QString("center(0,0, 0)"));

    //pl3d_mesh_struct _mesh=m_ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(0);
    l3d_uint inull=0;

   /* while(_mesh)
    {
        QString snull;
        if(_mesh->_display->isnull)

        {
            char n;
            ::snprintf(&n,1,"%d",inull);
            inull++;
            snull=QString("null");
            snull+=n;
            m_ui->cbPoint->addItem(snull);

        }




        _mesh=_mesh->next;
    }

*/




}

void insertObject::on_add_mesh_line_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_line,NULL);
}

void insertObject::on_add_mesh_circle_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_circle,NULL);
}

void insertObject::on_add_mesh_plane_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_plane,NULL);

}

void insertObject::on_add_mesh_cube_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_cube,NULL);

}

void insertObject::on_add_mesh_sphere_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_sphereuv,NULL);

}

void insertObject::on_add_mesh_cylinder_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_tube,NULL);
}

void insertObject::on_add_mesh_tube_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_tube,NULL);

}

void insertObject::on_add_mesh_torus_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_torus,NULL);

}

void insertObject::on_actionNullobject_triggered()
{


}

void insertObject::on_add_mesh_cone_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_cone,NULL);
}

void insertObject::on_add_mesh_logo_clicked()
{
    m_ui->mainwidget->pscene->AddObject(mesh_logo,NULL);
}

void insertObject::on_pb_edit_subdivide_clicked()
{
    m_ui->mainwidget->pscene->subdivide();
}

void insertObject::on_pb_edit_subdivide_all_clicked()
{
    m_ui->mainwidget->pscene->subdivide_all();
}

void insertObject::on_poswx_group_valueChanged(const QString &arg1)
{

}

void insertObject::on_actionInsertcube_triggered()
{

}

void insertObject::on_actiontorusdlg_triggered()
{

}

void insertObject::on_actionFast_insert_triggered()
{

}
void insertObject::on_select_wave()
{
    m_ui->mainwidget->pscene->SelectWave();
}



void insertObject::on_unselecteditall_clicked()
{
    m_ui->mainwidget->pscene->UnselectAll();
}
float insertObject::get_spindegree()
{
    return(m_ui->ledegree_spin->text().toFloat());
}

float insertObject::get_spinsteps()
{
    return(m_ui->ledegreestep_spin->text().toFloat());
}

void insertObject::on_pbspin_clicked()
{
    //to-do make the spin
    m_ui->mainwidget->pscene->Spin();
}

void insertObject::on_pbspin_x_clicked()
{
    m_ui->mainwidget->pscene->Spin(0);
}

void insertObject::on_pbspin_y_clicked()
{
    m_ui->mainwidget->pscene->Spin(1);
}

void insertObject::on_pbspin_z_clicked()
{
    m_ui->mainwidget->pscene->Spin(2);
}

void insertObject::on_pb_blending_clicked()
{
    l3d_uint nobj=m_ui->mainwidget->pscene->GetiObjectSelectedMainScene();
    pl3d_mesh_struct mesh=l3d_null;
    if(nobj!=-1)
        mesh=m_ui->mainwidget->pscene->GetpObjectMainScene(nobj);

    if(mesh!=l3d_null)
        if(mesh->blend())
            mesh->blend(false);
        else
            mesh->blend(true);

}

void insertObject::on_cb_ambientdiffuse_clicked(bool checked)
{
    if(_imaterial)
    {

        _imaterial->m_bambientanddiffuse=checked;

    }
}

void insertObject::on_pb_blending_define_clicked()
{
    if(!m_dlgblend)
        m_dlgblend= new blend_dialog();

    if(m_dlgblend->exec()==QDialog::Accepted)
    {
        if(_mesh_selected)
            _mesh_selected->_display->blend.set_factor(m_dlgblend->_sfactor,m_dlgblend->_dfactor);

    }

    delete(m_dlgblend);
    m_dlgblend=NULL;
}

void insertObject::on_hsshininnis_valueChanged(int value)
{
    if(_imaterial)
    {
        _imaterial->mat_shininess[0]=value;
    }
}

void insertObject::on_pb_delmaterial_clicked()
{
    if(_mesh_selected && m_imaterial>0 )
    {
        if(_mesh_selected->_material.get(m_imaterial)!=l3d_null)
        {
            if(_mesh_selected->_material.size()==1)
                return;


            _mesh_selected->_material.del(m_imaterial);
            if(m_imaterial==_mesh_selected->_material.size())
                m_imaterial--;

            if(m_imaterial==0 || m_imaterial==_mesh_selected->_material.size())
                _mesh_selected->_material.set(m_imaterial);

            loadmaterial();

        }

    }
}

void insertObject::on_pb_flat_group_clicked()
{
    if(_group)
        m_ui->mainwidget->pscene->SetFlatGroup(m_igroup);

}

void insertObject::on_selectmove_clicked()
{

}

void insertObject::on_selectmove_toggled(bool checked)
{

}

void insertObject::on_view_setortho_clicked()
{
    if(m_ui->view_setortho->isChecked())
    {
        m_ui->mainwidget->pscene->setOrtho(true);
        m_ui->view_setortho->setChecked(true);
    }
    else
    {
        m_ui->mainwidget->pscene->setOrtho(false);
        m_ui->view_setortho->setChecked(false);
    }


}

void insertObject::on_tb_move_world_toggled(bool checked)
{
    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_world);
        m_ui->tb_move_trackball->setChecked(false);
        m_ui->tb_move_scenetelecamera->setChecked(false);
        m_ui->tb_move_maincamera->setChecked(false);
        m_ui->tb_move_freecamera->setChecked(false);

    }
}

void insertObject::on_tb_move_maincamera_toggled(bool checked)
{

    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_camera);
        m_ui->tb_move_trackball->setChecked(false);
        m_ui->tb_move_scenetelecamera->setChecked(false);
        m_ui->tb_move_world->setChecked(false);
        m_ui->tb_move_freecamera->setChecked(false);
    }
}

void insertObject::on_tb_move_freecamera_toggled(bool checked)
{
    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_camera_free);
        m_ui->tb_move_trackball->setChecked(false);
        m_ui->tb_move_scenetelecamera->setChecked(false);
        m_ui->tb_move_world->setChecked(false);
        m_ui->tb_move_maincamera->setChecked(false);
    }
}

void insertObject::on_tb_move_trackball_toggled(bool checked)
{
    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_camera_trackball);
        m_ui->tb_move_maincamera->setChecked(false);
        m_ui->tb_move_scenetelecamera->setChecked(false);
        m_ui->tb_move_world->setChecked(false);
        m_ui->tb_move_freecamera->setChecked(false);
    }
}



void insertObject::on_tb_move_scenetelecamera_toggled(bool checked)
{
    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_camera_scene);
        m_ui->tb_move_trackball->setChecked(false);
        m_ui->tb_move_maincamera->setChecked(false);
        m_ui->tb_move_world->setChecked(false);
        m_ui->tb_move_freecamera->setChecked(false);
    }
}

void insertObject::on_tb_move_maincamera_fix_toggled(bool checked)
{
    if(checked)
    {
        m_ui->mainwidget->pscene->_main_view.setMove(SCENE::move_camera_center);
        m_ui->tb_move_trackball->setChecked(false);
        m_ui->tb_move_maincamera->setChecked(false);
        m_ui->tb_move_world->setChecked(false);
        m_ui->tb_move_freecamera->setChecked(false);
    }
}



void insertObject::on_viewfront_clicked()
{
    reset_view();
    m_ui->viewfront->setChecked(true);
    m_ui->mainwidget->pscene->SetScene(SCENE::sfront);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::sfront))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_viewback_clicked()
{
    reset_view();
    m_ui->viewback->setChecked(true);
    m_ui->mainwidget->pscene->SetScene(SCENE::sback);

    if(m_ui->mainwidget->pscene->isOrtho(SCENE::sback))
    {
        m_ui->view_setortho->setChecked(true);
    }else
        m_ui->view_setortho->setChecked(false);
}

void insertObject::on_viewbox_clicked()
{
    m_ui->viewsolid->setChecked(false);
    m_ui->viewbox->setChecked(true);
    m_ui->viewwireframe->setChecked(false);
    m_ui->viewcolor->setChecked(false);
    m_ui->viewtexture->setChecked(false);

    m_ui->mainwidget->pscene->SetDocument(SCENE::box);
}
