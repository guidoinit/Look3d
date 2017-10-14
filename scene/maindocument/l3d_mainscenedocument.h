#ifndef L3D_MAINSCENEDOCUMENT_H
#define L3D_MAINSCENEDOCUMENT_H
#include <QOpenGLFunctions>

#include <math.h>
#include <vector>


#include "mesh/vbo/objectvbo.h"
#include "scene/animation/frame.h"
#include "scene/animation/animate.h"

#include "scene/elements/l3d_light.h"


#include "scene/elements/moveedit.h"



#include "scene/animation/baseframe.h"
#include "scene/animation/locx.h"
#include "scene/animation/locy.h"
#include "scene/animation/locz.h"



#include "mesh/group.h"

#include "scene/animation/animationmanager.h"

#include "mesh/animation/join.h"
#include "mesh/animation/bone.h"
#include "scene/animation/mainbone.h"

#include "bezier/bezierbase.h"
#include "bezier/bezierline.h"



#include "l3d_include.h"
#include "mesh/l3d_id.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"


#include "scene/l3d_scene.h"


using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
namespace l3d
{
    class l3d_mainscenedocument
    {
    public:
        l3d_mainscenedocument();

        int getiGroupSelected();
        int getiLightSelected();
        group *getgroup(int index);
        int getSizeObjects();
        int getsizecamera();
        int getcameraselected();
        void nextcamera();
        void prevcamera();
        void firstcamera();
        void lastcamera();
        animationmanager *getmanageranimation();
        void drawtelecamera();
        telecamera *getpcamera(int value);
        int getFirstObject();
        int getObjectSelected();
        pl3d_light getlight();
        pl3d_light getlight(int);
        int getsizelight();
        int getsizematerials();
        l3d_vertex_fast gettoolpos();
        l3d_mesh getvectorobject();
        pl3d_mesh_struct getObject(int);
        void settype(SCENE::SceneType st);
        void setmodedraw(SCENE::ModeDraw md);
        void setmodedocument(SCENE::ModeDocument md);
        void addObject(l3d_mesh_struct);
        void addmesh(l3d_mesh_type,l3d_float *par);
        void makevbo(int io);
        void addBone();
        void addObjectSphere(l3d_mesh_struct);
        void draw();
        void drawvbo();
        void drawtexture();
        void drawedit();
        void draweditvertex();
        void draweditline();
        void draweditpoligon();
        void selectobject(int);
        void selectAll();
        void selectallobjects();
        void selectallgroups();
        void selecteditvertex(int,bool,bool);
        void selecteditline(int,bool,bool);
        void selecteditpoligon(int,bool,bool);
        void selecteditpoligonpaint(int,bool,bool);
        void scale(float[]);
        void move(l3d_vertex_fast );
        void applyscale();
        void rotate(float []);
        void applyrotate();
        void unselectobject();
        void unselectlights();
        void MoveObjectsVertex(l3d_vertex_fast);
        void MoveObjectVertex(int,l3d_vertex_fast);
        void MoveObjectVertexX(int,float);
        void MoveObjectVertexY(int,float);
        void MoveObjectVertexZ(int,float);
        void deletegroup();
        void deleteobjects();
        void deleteedit();
        void deleteeditvertex();
        void deleteeditvertex(int);
        void deleteeditvertex(int,int);
        void deleteeditedge();
        void deleteeditface();
        void deleteeditface(int);
        void duplicate();
        void duplicategroup();
        void duplicatevertex();
        void duplicateedge();
        void duplicateface();
        void subdivide();
        void subdivide_all();
        void copyobjects();
        void copyobjectsgroup(int,l3d_vertex_fast);
        void deselectobjectsgroup(int);
        void selectobjectsgroup(int);
        void pasteobjects();
        void invertselect();
        //void setcolor(color );
        void addCamera();
        void addbezierline();
        int geticamera();
        void addlight(LigthType);
        void addlight(LigthType,l3d_vertex_fast);
        void scalevertex(float[]);
        void applyscaleedit();
        void addmaterial(l3d_material_struct);
        void addmaterialandset(l3d_material_struct);
        void setObjectmaterial(int iobject);
        void setObjectsmaterial();
        void addnull();
        void addTorus();
        float getmax();
        void mergeObjectsSelected();
        l3d_material* getmaterials();

        //function for groups
        void drawBones();
        void drawBone(mainbone *);
        void drawGroup();
        void drawBezier();
        int drawGroupEdit();
        void addGroup(l3d_vertex_fast);
        void unGroup();
        void setSmoothGroup(int index);
        void savegroup(string filename, int index);
        void savegroup(std::ofstream *ar,int index);
        void loadgroup(string filename);
        void loadgroup(std::ifstream *ar);
        void savemesh(string filename,int _mtype,int index);
        void loadmesh(string filename);
        int getsizegroups();
        std::vector<int> getListObjectsSelected();
        std::vector<int> getListGroupsSelected();
        void setedit(SCENE::ModeEdit value);
        void SelectAllObjectsVertex();
        void UnselectAllObjectsVertex();
        void SelectAllObjectVertex(int index);
        void UnselectAllObjectVertex(int index);
        void SelectAllObjectsLines();
        void SelectAllObjectLines(int index);
        void UnselectAllObjectsLines();
        void UnselectAllObjectLines(int index);

        void extrude();
        void extrudevertex();
        void extrudeedge();
        void extrudeedgeind();


        void addvertexgroup(string);
        void remvertexgroup(int);
        void selectvertexgroup(int g);
    private:
        //maincamera m_maincamera; da inserire??

        l3d_scene mscene;

        l3d_mesh mesh;
        l3d_mesh m_object;

        l3d_mesh m_ocopy;

        vector<bezierline> m_bezierline;
        //da inserire materiali e texture
        l3d_material m_materials;
        vector<telecamera> m_telecamera;
        animationmanager m_animate;

        vector<mainbone> m_bones;

        //vector<objectnull> m_null;
        vector<group> m_groups;
        SCENE::SceneType m_type;
        SCENE::ModeDraw m_modedraw;
        SCENE::ModeDocument m_modedoc;
        SCENE::ModeEdit m_edit;
        int m_itelecamera;
        //updateinterface *m_update;
        void setlights();
    };

}


#endif // L3D_MAINSCENEDOCUMENT_H
