#ifndef INSERTOBJECT_H
#define INSERTOBJECT_H
#include <QOpenGLFunctions>
#include <QObject>
#include <QStandardItemModel>
#include "ui_mainwindow.h"

#include "newobject.h"
#include "insertcircle.h"
#include "dialogmaterial.h"
#include "blend_dialog.h"
#include "lightoptions.h"
#include "mesh/group.h"

#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;


class insertObject : public QObject
{
    Q_OBJECT
public:
    explicit insertObject(QObject *parent = 0);

    ~insertObject();
    void setscene(scene *);

    void connectobjects(Ui::MainWindow *ui);
    void initMainDock(QStandardItemModel*,Ui::MainWindow *ui);
    void updateMainDock(QStandardItemModel*,Ui::MainWindow *ui);
    void updateMainObjects( );
    void updateMainGroups( );
    void updateMainLights( );
    void updateMainMaterials( );
    void updateMainTelecamera();

    void viewMaterials();
    void loadObject(int);
    void loadGroup(int ng);
    void loadlight(int);
    void loadcamera(int icamera);
    float get_spindegree();
    float get_spinsteps();
    void setdata(QStandardItemModel*,Ui::MainWindow *ui);
private:
    pl3d_mesh_struct _mesh_selected;
    pl3d_material_struct _imaterial;
    group * _group;

    QStandardItemModel* m_sm;
    Ui::MainWindow *m_ui;

    DialogMaterial * m_dlgmaterial;
    lightoptions * m_loption;
    blend_dialog * m_dlgblend;


    int m_imaterial;
    int m_iobject;
    int m_igroup;
    int m_igroup_prev;
    int m_iobjectgroup;
    int m_iobjectgroup_first;
    int m_iobjectgroup_last;
    int m_ilight;
    int m_ioldlight;



    void getgroup();
    void loadmaterial();
    void loadmaterialvalue();


    void loadlightvalue();

    void updategroupobject(int index);

    void reset_view();

signals:

public slots:

    void update();
    void insertnull();
    void insertline();
    void insertlinedlg();
    void insertcircle();
    void insertcircledlg();
    void insertplane();
    void insertplanedlg();
    void insertcube();
    void insertcubedlg();
    void insertdisck();
    void insertdisckdlg();
    void insertsphere();
    void insertspheredlg();
    void insertconedlg();
    void inserttubesdlg();
    void inserttorusdlg();

    void addLight();
    void addLight_sun();
    void addLight_spot();
    void addLight_lamp();

    void addnullobject();


private slots:
    void on_actionActinsertcircle_triggered();
    void on_actionInsert_circle_triggered();
    void on_actionNewcircle_triggered();
    void on_actionInsert_line_triggered();
    void on_actionInsert_line_triggered(bool checked);
    void on_view3d_clicked();
    void on_slectmouse_clicked();
    void on_select_move();
    void on_select_scale();
    void on_select_rotate();
    void selecteditvertex();
    void selecteditedge();
    void selecteditface();
    void selecteditdelete();
    void selecteditduplicate();
    void selecteditinvert();
    void on_selectmulti_clicked();
    void setcolor();
    void on_actionActionNewTorus_triggered();
    void on_select_wave();
    void on_actionSet_material_triggered();
    void on_modepaint_clicked();
    void on_modeedit_clicked();

    void on_actionLightOptions_triggered();
    void on_applyscale_clicked();
    void on_scalex_valueChanged(double arg1);
    void on_scaley_valueChanged(double arg1);
    void on_scalez_valueChanged(double arg1);
    void on_poswx_valueChanged(double arg1);
    void on_poswy_valueChanged(double arg1);
    void on_poswz_valueChanged(double arg1);
    void on_rotatex_valueChanged(double arg1);
    void on_rotatey_valueChanged(double arg1);
    void on_rotatez_valueChanged(double arg1);
    void on_leName_textChanged(const QString &arg1);
    void on_leName2_textChanged(const QString &arg1);
    void on_applyrotate_clicked();
    void on_pbFlat_clicked();
    void on_pbFlat_2_clicked();
    void on_mainwidget_clicked();
    void on_hsambientr_valueChanged(int value);
    void on_hsambientg_valueChanged(int value);
    void on_hsambientb_valueChanged(int value);
    void on_hsambienta_valueChanged(int value);
    void on_pb_addmaterial_clicked();
    void on_pb_prevmaterial_clicked();
    void on_pb_nextmaterial_clicked();
    void on_hsdiffuser_valueChanged(int value);
    void on_hsdiffuseg_valueChanged(int value);
    void on_hsdiffuseb_valueChanged(int value);
    void on_hsdiffusea_valueChanged(int value);
    void on_pb_setmaterial_clicked();
    void on_hsemittedr_valueChanged(int value);
    void on_hsemittedg_valueChanged(int value);
    void on_hsemittedb_valueChanged(int value);
    void on_hsemitteda_valueChanged(int value);

    void on_hsspecularr_valueChanged(int value);
    void on_hsspecularg_valueChanged(int value);
    void on_hsspecularb_valueChanged(int value);
    void on_hsspeculara_valueChanged(int value);
    void on_pb_preview_material_clicked();


    void on_groupBox_clicked();
    void on_selecteditmerge_clicked();
    void on_selecteditextrude_clicked();
    void on_actionSave_mesh_triggered();
    void on_actionLoad_mesh_triggered();
    void on_selecteditGroup_clicked();
    void on_selecteditUnGroup_clicked();
    void on_actionSphere_triggered();
    void on_pb_group_first_clicked();
    void on_pb_group_last_clicked();
    void on_pb_group_prev_clicked();
    void on_pb_group_next_clicked();
    void on_poswx_group_object_valueChanged(double arg1);
    void on_poswy_group_object_valueChanged(double arg1);
    void on_poswz_group_object_valueChanged(double arg1);
    void on_scalex_group_object_valueChanged(double arg1);
    void on_scaley_group_object_valueChanged(double arg1);
    void on_scalez_group_object_valueChanged(double arg1);
    void on_rotatex_group_object_valueChanged(double arg1);
    void on_rotatey_group_object_valueChanged(double arg1);
    void on_rotatez_group_object_valueChanged(double arg1);
    void on_selecteditall_clicked();
    void on_pb_smooth_group_clicked();
    void on_poswx_group_valueChanged(double arg1);
    void on_poswy_group_valueChanged(double arg1);
    void on_poswz_group_valueChanged(double arg1);
    void on_scalex_group_valueChanged(double arg1);
    void on_scaley_group_valueChanged(double arg1);
    void on_scalez_group_valueChanged(double arg1);
    void on_rotatex_group_valueChanged(double arg1);
    void on_rotatey_group_valueChanged(double arg1);
    void on_rotatez_group_valueChanged(double arg1);
    void on_pb_light_sun_toggled(bool checked);
    void on_pb_light_lamp_toggled(bool checked);
    void on_pb_light_spot_toggled(bool checked);
    void on_pb_light_directional_toggled(bool checked);
    void on_pb_light_onoff_toggled(bool checked);
    void on_hs_ambientred_light_valueChanged(int value);
    void on_hs_ambientgreen_light_valueChanged(int value);
    void on_hs_ambientblue_light_valueChanged(int value);
    void on_hs_diffusered_light_valueChanged(int value);
    void on_hs_diffusegreen_light_valueChanged(int value);
    void on_hs_diffuseblue_light_valueChanged(int value);
    void on_hs_diffusealpha_light_valueChanged(int value);
    void on_hs_specularred_light_valueChanged(int value);
    void on_hs_speculargreen_light_valueChanged(int value);
    void on_hs_specularblue_light_valueChanged(int value);
    void on_hs_specularalpha_light_valueChanged(int value);
    void on_hs_exponent_light_valueChanged(int value);
    void on_hs_ambientalpha_light_valueChanged(int value);
    void on_hs_degree_light_valueChanged(int value);
    void on_poswx_light_valueChanged(double arg1);
    void on_poswy_light_valueChanged(double arg1);
    void on_poswz_light_valueChanged(double arg1);
    void on_poswx_group_3_valueChanged(double arg1);
    void on_poswy_group_3_valueChanged(double arg1);
    void on_poswz_group_3_valueChanged(double arg1);
    void on_pb_light_sun_clicked();
    void on_pb_light_lamp_clicked();
    void on_pb_light_spot_clicked();
    void on_pb_light_directional_clicked();
    void on_sb_distance_light_valueChanged(int arg1);
    void on_sb_anglea_light_valueChanged(int arg1);
    void on_sb_angleb_light_valueChanged(int arg1);
    void on_pb_light_onoff_clicked();
    void on_pb_object_normals_clicked();
    void on_actionAdd_light_triggered();
    void on_actionAdd_telecamera_triggered();
    void on_viewtelecamera_clicked();
    void on_pb_camera_up_clicked();
    void on_pb_camera_down_clicked();
    void on_pb_camera_left_clicked();
    void on_pb_camera_right_clicked();
    void on_pb_camera_first_clicked();
    void on_pb_camera_prev_clicked();
    void on_pb_camera_next_clicked();
    void on_pb_camera_last_clicked();
    void on_pb_camera_x_valueChanged(double arg1);
    void on_pb_camera_y_valueChanged(double arg1);
    void on_pb_camera_z_valueChanged(double arg1);
    void on_actionspheredlg_triggered();
    void on_pb_edit_extrude_clicked();
    void on_pb_edit_invert_face_clicked();
    void on_selectvertex_2_clicked();
    void on_selectvertex_clicked();
    void on_pb_edit_all_clicked();
    void on_pb_edit_delete_clicked();
    void on_pb_edit_invert_clicked();
    void on_modetexture_clicked();
    void on_mode3d_clicked();
    void on_viewsolid_clicked();
    void on_pb_insertprevius_clicked();
    void on_pb_insertnext_clicked();
    void on_pb_insertobject_clicked();
    void on_view_wireframe_toggled(bool checked);
    void on_view_solid_toggled(bool checked);
    void on_viewtree_clicked();
    void on_viewtop_clicked();
    void on_viewbottom_clicked();
    void on_viewleft_clicked();
    void on_viewrigth_clicked();
    void on_actionObjectImport_triggered();
    void on_animationnew_clicked();
    void on_pb_edit_extrude_edge_clicked();
    void on_pb_edit_extrude_edge_individual_clicked();
    void on_pb_addtexture_clicked();
    void on_pb_addvertexgroup_clicked();
    void on_pb_vertexgroup_set_clicked();
    void on_pb_vertexgroupprev_clicked();
    void on_pb_vertexgroupnext_clicked();
    void on_pb_vertexgroup_del_clicked();
    void on_pb_vertexgroup_select_clicked();
    void on_add_bezierline_clicked();
    void on_add_mesh_null_clicked();
    void on_add_mesh_line_clicked();
    void on_add_mesh_circle_clicked();
    void on_add_mesh_plane_clicked();
    void on_add_mesh_cube_clicked();
    void on_add_mesh_sphere_clicked();
    void on_add_mesh_cylinder_clicked();
    void on_add_mesh_tube_clicked();
    void on_add_mesh_torus_clicked();
    void on_actionNullobject_triggered();
    void on_add_mesh_cone_clicked();
    void on_add_mesh_logo_clicked();
    void on_pb_edit_subdivide_clicked();
    void on_pb_edit_subdivide_all_clicked();
    void on_poswx_group_valueChanged(const QString &arg1);
    void on_actionInsertcube_triggered();
    void on_actiontorusdlg_triggered();
    void on_actionFast_insert_triggered();
    void on_unselecteditall_clicked();
    void on_pbspin_clicked();
    void on_pbspin_x_clicked();
    void on_pbspin_y_clicked();
    void on_pbspin_z_clicked();
    void on_pb_blending_clicked();
    void on_cb_ambientdiffuse_clicked(bool checked);
    void on_pb_blending_define_clicked();
    void on_hsshininnis_valueChanged(int value);
    void on_pb_delmaterial_clicked();
    void on_pb_flat_group_clicked();
    void on_selectmove_clicked();
    void on_selectmove_toggled(bool checked);
    void on_view_setortho_clicked();
    void on_tb_move_world_toggled(bool checked);
    void on_tb_move_maincamera_toggled(bool checked);
    void on_tb_move_freecamera_toggled(bool checked);
    void on_tb_move_trackball_toggled(bool checked);
    void on_tb_move_scenetelecamera_toggled(bool checked);
    void on_tb_move_maincamera_fix_toggled(bool checked);
    void on_viewfront_clicked();
    void on_viewback_clicked();
    void on_viewbox_clicked();
};

#endif // INSERTOBJECT_H
