#ifndef SCENE_H
#define SCENE_H


#include <math.h>
#include <vector>
#include "sceneinclude.h"


#include "scene/elements/lightmodel.h"


#include "scene/elements/viewport.h"
#include "scene/elements/pipeline.h"
#include "scene/elements/settrackball.h"


#include "scene/project/project.h"

#include "scene/project/projectmanager.h"
#include "scene/elements/gridviewuv.h"
#include "scene/document.h"

#include "scene/animation/animationmanager_state.h"
#include "scene/animation/animationmanager.h"
#include "l3d_input_state.h"

#include "scene/view/l3d_view.h"

typedef struct _tagMouseSelect
{
        int x,y,x1,y1;
}mouse_select;
using namespace l3d::view;
class scene //: public object3d
{
private:
        int m_hint;
        SCENE::SceneType m_scene;
        SCENE::ModeDraw m_mode;
        SCENE::ModeDocument m_modedoc;
        SCENE::ModeEdit m_modeedit;
        SCENE::DocumentSelect m_docselect;
        SCENE::SelectTool m_selecttool;
        animationmanager_state * m_animationstate;
        //HDC _DC;
        mouse_select m_mousecord;

        //COpenGL opengl;

        gridviewuv * m_griduv;
        bool m_binsert;
        bool m_bisrotate;
        bool m_bismove;
        bool m_bligthselected;
        bool m_bisscale;
        bool m_bisupdown;

        pipeline* m_pipelinetop;

        //Ui::MainWindow *m_ui;


        //maincamera m_maincamera;
        settrackball m_track;
        //vector<object3d> m_object;
        //vector<object3d> m_ocopy;

        //vector<telecamera> m_telecamera;


        lightmodel m_light_model;
        //projectManager * _pmanager;

        document * m_maindocument;

        //move m_oMove;
        //moveedit m_oMoveEdit;
        //scaleedit m_toolscale;
        //rotateedit m_toolrotate;

        l3d_input_state _input;

        //bool m_bscale;
        //int m_scalexyz;
        float m_fscale[3];

        //bool m_brotate;
        float m_frotate[3];
        //int m_rotatexyz;

        //bool m_bmove;
        //vertex m_vmove;

        bool m_bplay;
        int m_iplay;
        int m_iframe;
        bool m_baltleft;

        bool m_btrackball;
        bool m_bmultiselect;
        bool m_btop;
        float m_ftop[2];
        //float m_movevertex[3];
        //float m_moveobj[3];
        //float m_bShift;
        bool m_bctrl;
        bool m_bupdown;
        float m_fortho;

        int numcubo,numpir,numsphere,numdisc,numplane,numcone;
        int m_ianiselect;
        int m_itelecamera;

        int m_view_width,m_view_heigth;

        void DrawPiano();
        void DoUserAction();
        void ApplyAnimationFrameActions(int,int,int );
        void ApplyAnimationFrame(int,int);
        int SelectTools(int,int,int,int);
        l3d_vertex_fast getpoint3d(l3d_uint x,l3d_uint y);
        void draw_multy_select_pointer(l3d_uint x,l3d_uint y);




        void initview();

        //CLightOption * pdlgLight; to-do
public:

        scene();
        scene(SCENE::SceneType );
        //virtual void Serialize(CArchive& ar);

        ~scene();
        l3d_view _main_view;

        //viewport m_view;
        //viewport m_mainviewport[4];
        void InitPipeline( );
        bool InitScene();
        //void setMainWindow(Ui::MainWindow*);
        void ResetScene(void);
        void DrawTelecamera();
        void SetScene(SCENE::SceneType);
        void setTool(SCENE::SelectTool);
        void setColorObject(color);

        //void CreatePovFile(CStdioFile *); to-do
        //prova vbo
        //insert* m_insert;

        void setdocument(document * doc);
        document * getdocument();

        void RemoveAll();

        //project function

        void AddProject(string name,PROJECT::ProjectType type);
        //void AddProjectObject(int ,object3d );

        //void AddObject(object3d );
        //void AddObject(object3d *);
        //void AddObjectMainScene(object3d );
        void AddObjectMaterial(l3d_material_struct);
        void AddMaterial(l3d_material_struct);
        void AddMaterialMainScene(l3d_material_struct);
        void AddObject(l3d_mesh_type _T ,float* objectpar);

        //void AddTelecamera(telecamera );
        void AddLigth(pl3d_light);
        void AddLight(LigthType);

        void AddNewAnimation(string , int);
        void AddAnimation(animate);
        //void AddAnimationObject(animatedmesh,int);
        void AddAnimationKeyFrame(int findex);
        void AddAnimationKeyFrameLoc(int findex);
        void AddAnimationFrame(frame,int);
        void AddAnimationFrameAction(action,int,int);
        void AddAnimationFrameActionHide(int,int,bool);
        void AddAnimationFramesMove(int ,int , int , int , l3d_vertex_fast );
        void AddAnimationFramesRotate(int ,int , int , int , l3d_vertex_fast );
        void AddAnimationFramesScale(int, int, int, int, l3d_vertex_fast);
        void DeleteAnimationFrameAction(int , int , int );
        void DeleteAnimationFramesAction(int , int , int ,int);
        void DeleteEdit();
        void Delete();

        void AddMainCameraAngle(float []);
        void AddAnimationObjectNew(int *,int );

        void InitLigth();
        void Draw();
        void Drawtool(l3d_vertex_fast);
        void Drawtexture();
        void DrawSceneLigths();
        void DrawContainer();
        void DrawPointer();
        void DrawAnimation(int );
        void DrawEdit();
        void DrawEditVertex();
        void DrawEditLine();
        void DrawEditPoligon();
        void DrawEditAnimation();
        void DrawSelect(int,int,int,int);
        void DrawMultiSelect(int,int,int,int);
        void Pipeline();
        void SetDocument(SCENE::ModeDraw);
        void SetMode(SCENE::ModeDocument);
        void SetDcoumentSelect(SCENE::DocumentSelect );
        SCENE::ModeDocument GetMode();
        void SetEditMode(SCENE::ModeEdit);
        SCENE::ModeEdit GetEditMode();
        void setOrtho(l3d_bool _ortho);
        l3d_bool isOrtho(SCENE::SceneType _s);

        void SetAnimation(int);
        void SetRadius(float);
        void SetObjectMaterial(pl3d_material_struct mat);
        bool SetTelecamera(int);

        void SelectWave();
        void SelectAll();
        void SelectAllLines(int,int);
        void SelectObject(int);
        void SelectObjectMainScene(int);
        void SelectObjectDocument(int);
        void SelectObjectAnimation(int);
        void SelectObjectVertex(int);
        void SelectObjectLine(int);
        void SelectObjectPoligon(int);
        void SelectObjectPoligonPaint(int);

        pl3d_mesh_struct  getpobjectmainscene(int index);
        //object3d* GetpObject(int);
        pl3d_mesh_struct GetpObjectMainScene(int);
        //object3d GetObject(int);
        //animatedmesh* GetAnimationpObject(int,int);
        //animatedmesh GetAnimationObject(int,int);
        animate GetAnimation(int);
        animate *GetpAnimation(int);
        pl3d_light GetpLightSelected(int);

        void Group();
        void UnGroup( );
        void SetSmoothGroup(int index);
        void SetFlatGroup(int index);
        int GetSizeObject();
        int GetSizeObjectMainScene();
        int GetSizeLigth();
        int GetSizeTelecamera();
        int GetSizeAnimation();
        int GetSizeAnimationFrames(int);
        int GetSizeAnimationObjects(int);
        l3d_vertex_fast GetWPAnimationObject(int,int);
        int GetSizeAnimationFrameAction(int,int);
        l3d_material *  GetMainSceneMaterials();
        l3d_vertex_fast GetWPTelecamera(int);

        void SetInitialState();
        void SetScale(bool);
        void SetScaleValue(float []);
        void SetScaleAnimationObject(int,int,float[]);
        void SetMove(bool);
        void SetMoveValue(l3d_vertex_fast);
        void SetRotate(bool);
        void SetRotateValue(float []);
        void SetInMoveAnimationObject(int,int,bool);
        void SetAnimationObjectsHide();
        void SetAnimationObjectsUnHide();
        void SetWPAppAnimationObject(int,int,l3d_vertex_fast);
        void SetWPAnimationObject(int,int,l3d_vertex_fast);

        void SetInsert(bool);

        void MoveObjectVertexX(int, float);
        void MoveObjectVertexY(int, float);
        void MoveObjectVertexZ(int, float);
        void MoveObjectVertex(int , l3d_vertex_fast);
        void MoveObjectsVertex(l3d_vertex_fast);
        void Extrude(int value);
        void Extrudevertex(int value);
        void Extrudeedge(int value);
        void Extrudeedgeind(int value);

        void Scale(float []);
        void ScaleVertex(float []);
        void ScaleObject(float [],int);
        void ScaleAnimation(int,float []);

        void ApplyScale();
        void ApplyScaleEdit();
        void ApplyScaleObject(int);
        void ApplyScaleAnimationObject(int,int);

        void Move(l3d_vertex_fast);
        void MoveObject(l3d_vertex_fast,int);
        void MoveTelecamera(l3d_vertex_fast,int);
        void MoveAnimation(l3d_vertex_fast,int);

        void Rotate(float []);
        void RotateVertex(float []);
        void RotateAnimation(float [], int );
        void ApplyRotate();

        void InvertObjectSelect();

        void SelectAllObjects();
        void SelectAllObjectLines(int);
        void SelectAllObjectsLines();
        void SelectAllObjectsAnimation(int);
        void UnselectAll();
        void UnselectAllObjects();
        void UnselectAllObjectsLines();
        void UnselectAllObjectLines(int);
        void UnselectAllObjectsAnimation(int);
        void SelectAllObjectsVertex();
        void UnselectAllObjectsVertex();
        void SelectAllObjectVertex(int index);
        void UnselectAllObjectVertex(int index);
        void UnselectAllObjectsQuads();
        void UnselectAllObjectsQuads(int index);

        void SelectAllAnimationObjects(int);
        void UnselectAllAnimationObjects(int);

        void MergeObjectsSelected();
        void CopyObjectsSelected();
        void PasteObjects();
        void Duplicate();
        void DuplicateObjects();

        void DeleteAnimationFrames(int );
        void DeleteAnimationFrame(int,int );
        void DeleteAnimation(int);
        void DeleteObjectsSelected();
        void DeleteObjectLinesSelected();
        void DeleteObjectLineSelected(int);
        void DeleteObjectsPolygonSelected();
        void DeleteObjectPolygonSelected(int oindex);
        void DeleteObjectsVertexSelected();
        void DeleteObjectVertexSelected(int index);
        void DeleteObjectVertex(int,int);
        void MergeObjectVertexSelected();
        void DuplicateObjectsSelected();

        void ClearAnimationFrame(int , int );
        void ClearAnimationFrameMove(int , int );
        void ClearAnimationFrameRotate(int , int );
        void ClearAnimationFrameScale(int , int );



        void PopObjectVertex(int);
        void PushObjectVertex(int);
        void SetViewportSize(int width, int heigth);
        void TrackBall(int,int,int,int);
        void SetTrackBall(int,int);
        void SetTrackBall(bool);

        bool IsSelectedAnimationObject(int,int);
        bool IsPresentAnimationFrame(int,int);

        void OnLButtonDown(unsigned int flags,int pointx,int pointy);
        void OnLButtonUp(unsigned int flags,int pointx,int pointy);
        void OnMouseWheel(unsigned int flags,short zDelta,int pointx, int pointy);
        void OnKeyDown(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags) ;
        void OnKeyUp(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags) ;
        void OnMouseMove(unsigned int nFlags, int pointx,int pointy);
        /*
        void OnMouseMoveMFC(UINT ,CPoint);
        void OnMouseWheelMFC(UINT nFlags, short zDelta, CPoint pt);
        void OnLButtonDownMFC(UINT nFlags, CPoint point);
        void OnLButtonUpMFC(UINT nFlags, CPoint point);
        void OnMButtonDownMFC(UINT nFlags, CPoint point) ;
        void OnMButtonUpMFC(UINT nFlags, CPoint point) ;
        void OnKeyDownMFC(UINT nChar, UINT nRepCnt, UINT nFlags) ;
        void OnKeyUpMFC(UINT nChar, UINT nRepCnt, UINT nFlags) ;
        void OnSizeMFC(UINT nType, int cx, int cy) ;
        */
        void Play(int);
        void PlayAnimation(int);
        void ViewAnimationFrame(int ,int );
        void InitAnimation(int);
        void FastAddiction();
        void Scalex(void);
        void Scaley(void);
        void Scalez(void);
        void ScaleAll(void);
        void Rotatex(void);
        void Rotatey(void);
        void Rotatez(void);
        void RotateAll(void);
        void EnableDisableLigth(bool enable);
        void OnLigthOptions(void);
        void ScaleEditObject(float []);
        void ScaleEditVertex(int,int,l3d_vertex_fast);
        void ScaleEditVertexAll(int,l3d_vertex_fast);
        void ScaleEditObjectVertexX(int,int,float);
        void ScaleEditObjectVertexY(int,int,float);
        void ScaleEditObjectVertexZ(int,int,float);
        bool SaveObject(int,string);
        string GetPath(void);
        void SaveObjectSelected(int nobject);
        int GetiObjectSelected(void);
        int GetiObjectSelectedMainScene(void);
        int GetiGroupSelectedMainScene(void);
        int GetiLightSelectedMainScene(void);
        int GetiCameraSelectedMainScene(void);
        void AddObjectFromFile(string);
        void AddObjectFromFilePath(string);
        bool isActions();
        void addNull();
        void AddTorus();



        void ImportModel_md2(std::string filename);
        void ImportPlayer_md2(std::string filename);
        void Import3ds_file(std::string filename);

        void addvertexgroup(string name);

        void remvertexgroup(int i);

        void vertexgroup_prev();
        void vertexgroup_next();
        void vertexgroup_set();
        string vertexgroup_name();


        void Spin();
        void Spin(l3d_uint);

        void subdivide();
        void subdivide_all();


};


#endif // SCENE_H
