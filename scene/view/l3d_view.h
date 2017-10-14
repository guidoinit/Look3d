#ifndef LED_VIEW_H
#define LED_VIEW_H
#include <QOpenGLFunctions>
#include "scene/elements/lightmodel.h"
#include "mesh/l3d_vertex.h"
#include "scene/sceneenum.h"
//tools
#include "scene/elements/moveedit.h"
#include "scene/elements/scaleedit.h"


#include "scene/maindocument/mainscenedocument.h"
#include "scene/document.h"
#include "scene/l3d_input_state.h"
#include "l3d_include.h"

using namespace l3d::vertex3f;
using namespace l3d::tool;
namespace l3d
{

    namespace view
    {
    //struttura che rappresenta la viewport
    typedef struct _l3d_viewport
    {
        l3d_uint x0,y0,x1,y1;//rappresenta e coordinate della viewport

        void set(l3d_uint _x0,l3d_uint _y0,l3d_uint _x1,l3d_uint _y1)
        {
            x0=_x0;
            y0=_y0;
            x1=_y1;
            y1=_y1;

        }

        void init()
        {
            glViewport(x0,y0,x1,y1);
        }


    }l3d_viewport;
    //struttura che rappresenta una telecamera
    typedef struct _l3d_telecamera
    {
        //due punti che rappresentano il punto di vidta ed il punto where
        l3d_vertex_fast _pointEye,_pointCenter,_pointUp;
        l3d_bool _freecamera;
        l3d_bool _normalcamera;
        l3d_double _alpha,_beta;//angoli per la telecamera
        void init()
        {
           // gluLookAt(_pointEye.x,_pointEye.y,_pointEye.z,_pointCenter.x,_pointCenter.y,_pointCenter.z,_pointUp.x,_pointUp.y,_pointUp.z);
            //gluLookAt(0.0F,20.0F,50.0F,0.0F,0.0F,0.0F,0.0F,1.0F,0.0F);
        }
        void setalpha(l3d_double _a)
        {
            _alpha=_a;
        }
        void setbeta(l3d_double _b)
        {
            _beta=_b;
        }

    }l3d_telecamera;
    //struttura che rapresenta la prospettia
    typedef struct _l3d_prospective
    {
        l3d_bool _ortho;
        l3d_bool _normal;

        l3d_double _left,_right,_top,_bottom,_znear,_zfar,_znear2,_zfar2,_fovy,_aspect;
        l3d_double _distance;


        void set(SCENE::SceneType _s)
        {
            ///_znear=1.0F;
            //_zfar=10000.0F;


            if(_ortho)
            {
//                glOrtho(_left,_right,_bottom,_top,_znear,_zfar);
                return;
            }
            if(_normal)
            {
                //gluPerspective(_fovy,_aspect,_znear2,_zfar2);
                return;
            }



            /*
            switch(_s)
            {
            case SCENE::sall:
                gluPerspective(_fovy,_aspect,_znear2,_zfar2);
                break;
            case SCENE::s3d:

                 gluPerspective(_fovy,_aspect,_znear2,_zfar2);
                break;
            case SCENE::stelecamera:

                 gluPerspective(_fovy,_aspect,_znear2,_zfar2);
                break;
            case SCENE::sright:
                glOrtho(_left,_right,_bottom,_top,_znear,_zfar);
                //glFrustum(-100.0F,100.0F,-100.0F,100.0F,-500.0F,10000.0F);
                break;
            case SCENE::stop:
                    //glOrtho(-(opengl.m_view_width/2),(opengl.m_view_width/2),-(opengl.m_view_height/2),(opengl.m_view_height/2),1.0F,1000.0F);
                  //  glOrtho((-forthox+m_fortho+m_ftop[0])*aspect,(forthox-m_fortho+m_ftop[0])*aspect,(-forthoy+m_fortho+m_ftop[1])*aspect,(forthoy-m_fortho+m_ftop[1])*aspect,1.0F+m_fortho,1000.0F+m_fortho);
                glOrtho(_left,_right,_bottom,_top,_znear,_zfar);
                //glFrustum(-100.0F,100.0F,-100.0F,100.0F,10.0F,10000.0F);

                break;
            case SCENE::sleft:
                //glFrustum(-100.0F,100.0F,-100.0F,100.0F,-500.0F,10000.0F);
                glOrtho(_left,_right,_bottom,_top,_znear,_zfar);
                    //glOrtho(-(opengl.m_view_width/2),(opengl.m_view_width/2),-(opengl.m_view_height/2),(opengl.m_view_height/2),1.0F,1000.0F);
                    //glOrtho((-forthox+m_fortho+m_ftop[0])*aspect,(forthox-m_fortho+m_ftop[0])*aspect,(-forthoy+m_fortho+m_ftop[1])*aspect,(forthoy-m_fortho+m_ftop[1])*aspect,1.0F+m_fortho,1000.0F+m_fortho);

                break;
            case SCENE::sbottom:
                glOrtho(_left,_right,_bottom,_top,_znear,_zfar);
                //glFrustum(-100.0F,100.0F,-100.0F,100.0F,-500.0F,10000.0F);
                break;


            }*/


        }


    }l3d_prospective;

    typedef struct _l3d_picking
    {
        l3d_uint oldx,oldy;
        l3d_uint newx,newy;

        void set(l3d_uint _x,l3d_uint _y)
        {
            oldx=newx;
            oldy=newy;
            newx=_x;
            newy=_y;
        }

    }l3d_picking;
        class l3d_view
        {
        private:
            l3d_prospective _prospective;
            l3d_prospective _prospective_top,_prospective_bottom,_prospective_left,_prospective_right,_prospective_front,_prospective_back,_prospective_3d;
            l3d_viewport _viewport;
            l3d_viewport _viewport4[4];
            l3d_telecamera _telecamera;
            l3d_telecamera _tel_top,_tel_bottom,_tel_left,_tel_right,_tel_front,_tel_back,_tel_3d;
            l3d_picking _picking;
            l3d_bool _selected;
            SCENE::SceneType _scene;
            SCENE::DocumentSelect _docselect;
            SCENE::ModeDocument _modedoc;
            SCENE::SelectTool _selectedtool;
            SCENE::SceneMove _movetype;
            document * _maindocument;
            lightmodel _lightmodel;
            l3d_double _distance;
            l3d_double _distance2;
            l3d_double _distance3;

            pl3d_input_state _input;
            l3d_vertex_fast _world_pos;//da sostituire con posizione delle classe world quando è fatta

            moveedit _movetools;
            scaleedit _scaletools;
            //rotateedit m_toolrotate;

            void Draw();

            void setMoviment(l3d_double _val,int _type);


        public:
            l3d_view();
            l3d_view(l3d_uint _x0,l3d_uint _y0,l3d_uint _x1,l3d_uint _y1);
            void (*_draw_function)(void);
            void setScene(SCENE::SceneType scene);
            void setViewport(l3d_uint x0,l3d_uint y0,l3d_uint x1,l3d_uint y1);
            void setCamera(l3d_vertex_fast _eye,l3d_vertex_fast _center,l3d_vertex_fast _up);
            void setCameraAlphaBeta(l3d_double _a,l3d_double _b);
            void setCameraFree(l3d_bool val);
            void Camera();
            void Prospective();
            void setPicking(l3d_uint x,l3d_uint y);
            void setProspectiveOrtho(l3d_bool _o,l3d_double _left,l3d_double _right,l3d_double _bottom,l3d_double _top,l3d_double _znear,l3d_double _zfar);
            void setProspectiveNormal(l3d_bool _n,l3d_double _fovy,l3d_double _aspect,l3d_double _znear,l3d_double _zfar);
            //void Prospective();
            void setDrawFunction(void (*_draw)(void));
            void setDocument(document* _doc);
            void setDocumentSelect(SCENE::DocumentSelect _dsel);
            void DrawPiano();
            void DrawPianoOrtho();
            void PipeLine();
            void PipeLine4();
            void drawTool(l3d_vertex_fast _pos,l3d_bool _select);
            void setTool(SCENE::SelectTool st);
            void setInput(pl3d_input_state);
            void setOrtho(l3d_bool _ortho);
            l3d_bool isOrtho(SCENE::SceneType _s);

            l3d_double get_prospective_distance();
            void set_prospective_distance(l3d_double _val);
            l3d_double get_prospective_distance2();
            void set_prospective_distance2(l3d_double _val);
            l3d_double get_prospective_distance3();
            void set_prospective_distance3(l3d_double _val);
            //funzioni per il picking
            l3d_uint drawSelect(l3d_uint _sx,l3d_uint _sy,l3d_uint _rx,l3d_uint _ry);

            void setMove(SCENE::SceneMove _move);

            int SelectTools(int x,int y, int x1, int y1);
        };
    }
}

#endif // LED_VIEW_H
