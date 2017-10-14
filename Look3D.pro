#-------------------------------------------------
#
# Project created by QtCreator 2011-10-23T19:29:51
#
#-------------------------------------------------

QT       += core gui widgets opengl

TARGET = Look3D
TEMPLATE = app
#INCLUDEPATH += scene/lib/glew-1.9.0/include/
INCLUDEPATH += lua52/include/
#INCLUDEPATH += scene/lib/lib3ds-20080909/lib/
#LIBS += -Lscene/lib/lib3ds-20080909/lib/ -llib3ds.lib

SOURCES +=    mesh/vertex2f.cpp \
    mesh/variable.cpp \
    mesh/module.cpp \
    mesh/group.cpp \
    mesh/color.cpp \
    mesh/texture/vertexuv.cpp \
    mesh/texture/texture.cpp \
    mesh/texture/jpeg.cpp \
    qt/newproject.cpp \
    qt/newpackage.cpp \
    qt/mainwindow.cpp \
    qt/main.cpp \
    qt/loadpackage.cpp \
    qt/lightoptions.cpp \
    qt/insertobject.cpp \
    qt/importobject.cpp \
    qt/dialogmaterial.cpp \
    qt/aboutdialog.cpp \
    scene/sceneproperty.cpp \
    scene/document.cpp \
    scene/actionmanager.cpp \
    scene/animation/locz.cpp \
    scene/animation/locy.cpp \
    scene/animation/locx.cpp \
    scene/animation/keyframe.cpp \
    scene/animation/frame.cpp \
    scene/animation/baseframe.cpp \
    scene/elements/trackball.c \
    scene/elements/scaleedit.cpp \
    scene/elements/moveedit.cpp \
    scene/elements/lightmodel.cpp \
    scene/elements/gridviewuv.cpp \
    scene/exports/md2/Md2Player.cpp \
    scene/exports/md2/Md2Model.cpp \
    scene/project/projectmanager.cpp \
    scene/project/project.cpp \
    mesh/line.cpp \
    mesh/function.cpp \
    qt/opengl.cpp \
    scene/scene.cpp \
    scene/elements/littlematerial.cpp \
    mesh/animation/actionvertex.cpp \
    mesh/animation/vertexlist.cpp \
    mesh/animation/meshanimation.cpp \
    mesh/animation/meshframe.cpp \
    mesh/animation/meshkeyframe.cpp \
    mesh/animation/locx_vertex.cpp \
    mesh/animation/locy_vertex.cpp \
    mesh/animation/locz_vertex.cpp \
    mesh/animation/baseframe_vertex.cpp \
    mesh/animation/join.cpp \
    mesh/animation/bone.cpp \
    scene/animation/animationmanager.cpp \
    scene/animation/animatedcamera.cpp \
    scene/animation/animatedlight.cpp \
    scene/animation/animationmanager_state.cpp \
    mesh/texture/l3d_image.cpp \
    mesh/texture/l3d_imagebmp.cpp \
    mesh/texture/l3d_imagetga.cpp \
    mesh/texture/l3d_imagejpeg.cpp \
    qt/newanimation.cpp \
    scene/animation/mainjoin.cpp \
    scene/animation/mainbone.cpp \
    scene/animation/schinning.cpp \
    scene/animation/schinningvector.cpp \
    scene/animation/l3dvector.cpp \
    mesh/vertexgroup.cpp \
    scene/elements/settrackball.cpp \
    bezier/bezierbase.cpp \
    bezier/bezierline.cpp \
    math/vector2f.cpp \
    scene/imports/3ds/lib3dsimporter.cpp \
    scene/lib/lib3ds-20080909/src/lib3ds_viewport.c \
    scene/lib/lib3ds-20080909/src/lib3ds_vector.c \
    scene/lib/lib3ds-20080909/src/lib3ds_util.c \
    scene/lib/lib3ds-20080909/src/lib3ds_track.c \
    scene/lib/lib3ds-20080909/src/lib3ds_shadow.c \
    scene/lib/lib3ds-20080909/src/lib3ds_quat.c \
    scene/lib/lib3ds-20080909/src/lib3ds_node.c \
    scene/lib/lib3ds-20080909/src/lib3ds_mesh.c \
    scene/lib/lib3ds-20080909/src/lib3ds_matrix.c \
    scene/lib/lib3ds-20080909/src/lib3ds_math.c \
    scene/lib/lib3ds-20080909/src/lib3ds_material.c \
    scene/lib/lib3ds-20080909/src/lib3ds_light.c \
    scene/lib/lib3ds-20080909/src/lib3ds_io.c \
    scene/lib/lib3ds-20080909/src/lib3ds_file.c \
    scene/lib/lib3ds-20080909/src/lib3ds_chunktable.c \
    scene/lib/lib3ds-20080909/src/lib3ds_chunk.c \
    scene/lib/lib3ds-20080909/src/lib3ds_camera.c \
    scene/lib/lib3ds-20080909/src/lib3ds_background.c \
    scene/lib/lib3ds-20080909/src/lib3ds_atmosphere.c \
    scene/lib/glew-1.9.0/src/glew.c \
    mesh/vbo/bufferobject.cpp \
    mesh/l3d_vertex.cpp \
    mesh/l3d_line.cpp \
    mesh/l3d_face3.cpp \
    mesh/l3d_mesh.cpp \
    mesh/l3d_face4.cpp \
    mesh/vbo/l3d_bufferobject.cpp \
    mesh/vbo/l3d_vertexbufferobject.cpp \
    modifier/l3d_modifier_subdivide.cpp \
    scene/l3d_meshselect.cpp \
    scene/maindocument/l3d_mainscenedocument.cpp \
    mesh/l3d_material.cpp \
    mesh/l3d_vertex_group.cpp \
    modifier/l3d_modifier_extrude.cpp \
    modifier/l3d_modifier_wave.cpp \
    modifier/l3d_modifier_spin.cpp \
    l3d_blend.cpp \
    qt/blend_dialog.cpp \
    modifier/l3d_modifier_draw.cpp \
    scene/view/l3d_view.cpp \
    modifier/l3d_modifier_picking.cpp \
    tolua++package/l3d_mesh_lua.cpp \
    tolua++package/tolua_to.c \
    tolua++package/tolua_push.c \
    tolua++package/tolua_map.c \
    tolua++package/tolua_is.c \
    tolua++package/tolua_event.c \
    lua52/src/ltm.c \
    lua52/src/ltablib.c \
    lua52/src/ltable.c \
    lua52/src/lstrlib.c \
    lua52/src/lstring.c \
    lua52/src/lstate.c \
    lua52/src/lparser.c \
    lua52/src/loslib.c \
    lua52/src/lopcodes.c \
    lua52/src/lobject.c \
    lua52/src/loadlib.c \
    lua52/src/lmem.c \
    lua52/src/lmathlib.c \
    lua52/src/llex.c \
    lua52/src/liolib.c \
    lua52/src/linit.c \
    lua52/src/lgc.c \
    lua52/src/lfunc.c \
    lua52/src/ldump.c \
    lua52/src/ldo.c \
    lua52/src/ldebug.c \
    lua52/src/ldblib.c \
    lua52/src/lctype.c \
    lua52/src/lcorolib.c \
    lua52/src/lcode.c \
    lua52/src/lbitlib.c \
    lua52/src/lbaselib.c \
    lua52/src/lauxlib.c \
    lua52/src/lapi.c \
    lua52/src/lzio.c \
    lua52/src/lvm.c \
    lua52/src/lundump.c \
    lua52/src/luac.c \
    lua52/src/lua.c \
    modifier/l3d_modifier_save.cpp \
    mesh/istruction.cpp \
    modifier/l3d_modifier_uv.cpp \
    mesh/l3d_uv.cpp \
    scene/animation/animate.cpp \
    scene/elements/l3d_light.cpp \
    qt/newobject.cpp \
    mesh/action.cpp \
    scene/elements/telecamera.cpp \
    qt/fastinsert.cpp

HEADERS  += mesh/vertex2f.h \
    mesh/variable.h \
    mesh/module.h \
    mesh/group.h \
    mesh/color.h \
    mesh/texture/vertexuv.h \
    mesh/texture/texture.h \
    mesh/texture/makeuv.h \
    mesh/texture/jpeg.h \
    qt/toolbar3d.h \
    qt/newproject.h \
    qt/newpackage.h \
    qt/newobject.h \
    qt/mainwindow.h \
    qt/loadpackage.h \
    qt/lightoptions.h \
    qt/insertobject.h \
    qt/importobject.h \
    qt/fastinsert.h \
    qt/dialogmaterial.h \
    qt/aboutdialog.h \
    scene/sceneproperty.h \
    scene/sceneinclude.h \
    scene/sceneenum.h \
    scene/function.h \
    scene/documentinclude.h \
    scene/document.h \
    scene/actionmanager.h \
    scene/action.h \
    scene/animation/locz.h \
    scene/animation/locy.h \
    scene/animation/locx.h \
    scene/animation/keyframe.h \
    scene/animation/frame.h \
    scene/animation/baseframe.h \
    scene/elements/viewport.h \
    scene/elements/trackball.h \
    scene/elements/scaleedit.h \
    scene/elements/pipeline.h \
    scene/elements/moveedit.h \
    scene/elements/maincamera.h \
    scene/elements/lightmodel.h \
    scene/elements/insert.h \
    scene/elements/gridviewuv.h \
    scene/exports/md2/Md2Player.h \
    scene/exports/md2/Md2Model.h \
    scene/exports/md2/Anorms.h \
    scene/maindocument/mainscenedocument.h \
    scene/project/projectmanager.h \
    scene/project/project.h \
    mesh/line.h \
    mesh/action.h \
    mesh/function.h \
    qt/opengl.h \
    scene/scene.h \
    scene/elements/sceneelements.h \
    scene/elements/littlematerial.h \
    qt/mainobject.h \
    mesh/animation/actionvertex.h \
    mesh/animation/vertexlist.h \
    mesh/animation/animatedmesh.h \
    mesh/animation/meshanimation.h \
    mesh/animation/meshframe.h \
    mesh/animation/meshkeyframe.h \
    mesh/animation/locx_vertex.h \
    mesh/animation/locy_vertex.h \
    mesh/animation/locz_vertex.h \
    mesh/animation/baseframe_vertex.h \
    mesh/animation/join.h \
    mesh/animation/bone.h \
    scene/animation/animationmanager.h \
    scene/animation/animatedcamera.h \
    scene/animation/animatedlight.h \
    scene/animation/animationmanager_state.h \
    mesh/texture/l3d_image.h \
    mesh/texture/l3d_imagebmp.h \
    mesh/texture/l3d_imagetga.h \
    mesh/texture/l3d_imagejpeg.h \
    qt/newanimation.h \
    scene/animation/mainjoin.h \
    scene/animation/mainbone.h \
    scene/animation/schinning.h \
    scene/animation/schinningvector.h \
    scene/animation/l3dvector.h \
    mesh/vertexgroup.h \
    scene/elements/settrackball.h \
    mesh/bezierbase.h \
    bezier/bezierbase.h \
    bezier/bezierline.h \
    math/vector2f.h \
    scene/imports/3ds/lib3dsimporter.h \
    scene/lib/lib3ds-20080909/src/lib3ds_impl.h \
    scene/lib/lib3ds-20080909/src/lib3ds.h \
    mesh/vbo/objectvbo.h \
    scene/lib/glew-1.9.0/include/GL/glew.h \
    mesh/vbo/bufferobject.h \
    l3d_include.h \
    mesh/l3d_vertex.h \
    mesh/l3d_line.h \
    mesh/l3d_face3.h \
    mesh/l3d_mesh.h \
    mesh/l3d_face4.h \
    mesh/vbo/l3d_bufferobject.h \
    mesh/vbo/l3d_vertexbufferobject.h \
    mesh/l3d_id.h \
    scene/l3d_scene.h \
    mesh/l3d_id_picking.h \
    modifier/l3d_modifier_subdivide.h \
    scene/l3d_meshselect.h \
    scene/maindocument/l3d_mainscenedocument.h \
    mesh/l3d_material.h \
    mesh/l3d_vertex_group.h \
    modifier/l3d_modifier_extrude.h \
    mesh/l3d_list.h \
    modifier/l3d_modifier_wave.h \
    modifier/l3d_modifier_spin.h \
    l3d_blend.h \
    qt/blend_dialog.h \
    modifier/l3d_modifier_draw.h \
    program_info.h \
    scene/view/l3d_view.h \
    modifier/l3d_modifier_picking.h \
    scene/l3d_input_state.h \
    tolua++package/tolua.h \
    lua52/include/lualib.h \
    lua52/include/luaconf.h \
    lua52/include/lua.hpp \
    lua52/include/lua.h \
    lua52/include/lauxlib.h \
    tolua++package/tolua_event.h \
    tolua++package/tolua.h \
    lua52/src/lua.hpp \
    lua52/src/lua.h \
    lua52/src/ltm.h \
    lua52/src/ltable.h \
    lua52/src/lstring.h \
    lua52/src/lstate.h \
    lua52/src/lparser.h \
    lua52/src/lopcodes.h \
    lua52/src/lobject.h \
    lua52/src/lmem.h \
    lua52/src/llimits.h \
    lua52/src/llex.h \
    lua52/src/lgc.h \
    lua52/src/lfunc.h \
    lua52/src/ldo.h \
    lua52/src/ldebug.h \
    lua52/src/lctype.h \
    lua52/src/lcode.h \
    lua52/src/lauxlib.h \
    lua52/src/lapi.h \
    lua52/src/lzio.h \
    lua52/src/lvm.h \
    lua52/src/lundump.h \
    lua52/src/lualib.h \
    lua52/src/luaconf.h \
    modifier/l3d_modifier_save.h \
    mesh/l3d_transform.h \
    modifier/l3d_modifier_uv.h \
    mesh/l3d_uv.h \
    scene/animation/animate.h \
    scene/elements/l3d_light.h \
    mesh/l3d_action.h \
    scene/animation/l3d_frame.h \
    scene/elements/telecamera.h
QT           += opengl

FORMS    +=  qt/newproject.ui \
    qt/newpackage.ui \
    qt/newobject.ui \
    qt/newcone.ui \
    qt/mainwindow.ui \
    qt/maindock.ui \
    qt/loadpackage.ui \
    qt/lightoptions.ui \
    qt/importobject.ui \
    qt/fastinsert.ui \
    qt/dialogmaterial.ui \
    qt/bootmmaindock.ui \
    qt/aboutdialog.ui \
    qt/newanimation.ui \
    qt/dialogapp.ui \
    qt/blend_dialog.ui

RESOURCES +=  resources/mainresource.qrc

OTHER_FILES += \
    scene/imports/3ds/license.txt \
    lua52/src/lua52.def \
    tolua++package/l3d_mesh.pkg \
    tolua++package/l3d_mesh_struct.pkg \
    tolua++package/l3d_mesh_struct.pkg










































































































































































































































