#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>
#include "scene/elements/lightmodel.h"
#include "l3d_view.h"

using namespace l3d::view;

l3d_view::l3d_view()
{
    _selected=false;
    _telecamera._freecamera=false;
    _telecamera._normalcamera=true;
    _telecamera._alpha=_telecamera._beta=0.0F;
    _distance=_distance2=_distance3=0.0F;
    _movetype=SCENE::move_world;
    _world_pos.set(0.0F,0.0F,0.0F);
    setScene(SCENE::s3d);
}
l3d_view::l3d_view(l3d_uint _x0,l3d_uint _y0,l3d_uint _x1,l3d_uint _y1)
{
    _selected=false;
    _telecamera._freecamera=false;
    _telecamera._normalcamera=true;
    _telecamera._alpha=_telecamera._beta=0.0F;
    _viewport.set(_x0,_y0,_x1,_y1);
    _distance=_distance2=_distance3=0.0F;
    _movetype=SCENE::move_world;
    _world_pos.set(0.0F,0.0F,0.0F);
    setScene(SCENE::s3d);
}
void l3d_view::Prospective()
{
    switch(_scene)
    {
    case SCENE::sall://to-do
        _prospective.set(_scene);

        break;
    case SCENE::s3d:
        _prospective_3d.set(_scene);

        break;
    case SCENE::sleft:
        _prospective_left.set(_scene);

        break;
    case SCENE::sright:
        _prospective_right.set(_scene);

        break;
    case SCENE::stop:
        _prospective_top.set(_scene);

        break;
    case SCENE::sbottom:
        _prospective_bottom.set(_scene);


        break;
    case SCENE::sfront:
        _prospective_front.set(_scene);

        break;
    case SCENE::sback:
        _prospective_back.set(_scene);

        break;

    }
}

void l3d_view::Camera()
{

    switch(_scene)
    {
    case SCENE::sall://to-do

        _telecamera.init();
        break;
    case SCENE::s3d:

        _tel_3d.init();
        break;
    case SCENE::sleft:

        _tel_left.init();
        break;
    case SCENE::sright:

        _tel_right.init();
        break;
    case SCENE::stop:

        _tel_top.init();
        break;
    case SCENE::sbottom:

        _tel_bottom.init();

        break;
    case SCENE::sfront:
        _tel_front.init();
        break;
    case SCENE::sback:
        _tel_back.init();
        break;

    }
}

void l3d_view::setCamera(l3d_vertex_fast _eye,l3d_vertex_fast _center,l3d_vertex_fast _up)
{
    _telecamera._pointEye=_eye;
    _telecamera._pointCenter=_center;
    _telecamera._pointUp=_up;

}
void l3d_view::setCameraFree(l3d_bool val)
{
    _telecamera._freecamera=val;
}
void l3d_view::setCameraAlphaBeta(l3d_double _a,l3d_double _b)
{
    _telecamera.setalpha(_a);
    _telecamera.setbeta(_b);
}
void l3d_view::setPicking(l3d_uint x, l3d_uint y)
{
    _picking.set(x,y);

}


void l3d_view::setProspectiveOrtho(l3d_bool _o,l3d_double _left,l3d_double _right,l3d_double _bottom,l3d_double _top,l3d_double _znear,l3d_double _zfar)
{
    _prospective._ortho=_o;
    _prospective._left=_left;
    _prospective._right=_right;
    _prospective._bottom=_bottom;
    _prospective._top=_top;
    _prospective._znear=_znear;
    _prospective._zfar=_zfar;

    _prospective_3d._ortho=_o;
    _prospective_3d._left=_left;
    _prospective_3d._right=_right;
    _prospective_3d._bottom=_bottom;
    _prospective_3d._top=_top;
    _prospective_3d._znear=_znear;
    _prospective_3d._zfar=_zfar;

    _prospective_top._ortho=true;
    _prospective_top._left=_left;
    _prospective_top._right=_right;
    _prospective_top._bottom=_bottom;
    _prospective_top._top=_top;
    _prospective_top._znear=_znear;
    _prospective_top._zfar=_zfar;

    _prospective_bottom._ortho=true;
    _prospective_bottom._left=_left;
    _prospective_bottom._right=_right;
    _prospective_bottom._bottom=_bottom;
    _prospective_bottom._top=_top;
    _prospective_bottom._znear=_znear;
    _prospective_bottom._zfar=_zfar;

    _prospective_left._ortho=true;
    _prospective_left._left=_left;
    _prospective_left._right=_right;
    _prospective_left._bottom=_bottom;
    _prospective_left._top=_top;
    _prospective_left._znear=_znear;
    _prospective_left._zfar=_zfar;


    _prospective_right._ortho=true;
    _prospective_right._left=_left;
    _prospective_right._right=_right;
    _prospective_right._bottom=_bottom;
    _prospective_right._top=_top;
    _prospective_right._znear=_znear;
    _prospective_right._zfar=_zfar;

    _prospective_front._ortho=true;
    _prospective_front._left=_left;
    _prospective_front._right=_right;
    _prospective_front._bottom=_bottom;
    _prospective_front._top=_top;
    _prospective_front._znear=_znear;
    _prospective_front._zfar=_zfar;

    _prospective_back._ortho=true;
    _prospective_back._left=_left;
    _prospective_back._right=_right;
    _prospective_back._bottom=_bottom;
    _prospective_back._top=_top;
    _prospective_back._znear=_znear;
    _prospective_back._zfar=_zfar;

}
void l3d_view::setProspectiveNormal(l3d_bool _n,l3d_double _fovy,l3d_double _aspect,l3d_double _znear,l3d_double _zfar)
{
    _prospective._normal=_n;
    _prospective._fovy=_fovy;
    _prospective._aspect=_aspect;
    _prospective._znear2=_znear;
    _prospective._zfar2=_zfar;

    _prospective_top._normal=_n;
    _prospective_top._fovy=_fovy;
    _prospective_top._aspect=_aspect;
    _prospective_top._znear2=_znear;
    _prospective_top._zfar2=_zfar;

    _prospective_bottom._normal=_n;
    _prospective_bottom._fovy=_fovy;
    _prospective_bottom._aspect=_aspect;
    _prospective_bottom._znear2=_znear;
    _prospective_bottom._zfar2=_zfar;

    _prospective_left._normal=_n;
    _prospective_left._fovy=_fovy;
    _prospective_left._aspect=_aspect;
    _prospective_left._znear2=_znear;
    _prospective_left._zfar2=_zfar;

    _prospective_right._normal=_n;
    _prospective_right._fovy=_fovy;
    _prospective_right._aspect=_aspect;
    _prospective_right._znear2=_znear;
    _prospective_right._zfar2=_zfar;

    _prospective_front._normal=_n;
    _prospective_front._fovy=_fovy;
    _prospective_front._aspect=_aspect;
    _prospective_front._znear2=_znear;
    _prospective_front._zfar2=_zfar;

    _prospective_back._normal=_n;
    _prospective_back._fovy=_fovy;
    _prospective_back._aspect=_aspect;
    _prospective_back._znear2=_znear;
    _prospective_back._zfar2=_zfar;

    _prospective_3d._normal=_n;
    _prospective_3d._fovy=_fovy;
    _prospective_3d._aspect=_aspect;
    _prospective_3d._znear2=_znear;
    _prospective_3d._zfar2=_zfar;

}
void l3d_view::setMoviment(l3d_double _val, int _type)
{
    //_type: 1)x  2)y  3)z

    l3d_double x,y,z,_camx,_camy,_camz;

    _camx=_camy=_camz=0.0F;

    switch(_input->_mouse_move)
    {
        case mouse_xzy:
            x=_distance;
            y=_distance2;
            z=_distance3;

        break;
        case mouse_xyz:
            x=_distance;
            y=_distance3;
            z=_distance2;

        break;
    }

    switch(_type)
    {
    case 1://x
        _camx+=_val;
        x+=_val;
        break;
    case 2://y
        _camy+=_val;
        y+=_val;
        break;
    case 3://z
        _camz+=_val;
        z+=_val;
        break;
    }

    switch(_input->_mouse_move)
    {
        case mouse_xzy:
            _distance=x;
            _distance2=y;
            _distance3=z;

        break;
        case mouse_xyz:
            _distance=x;
            _distance3=y;
            _distance2=z;

        break;
    }
    switch(_movetype)
    {
    case SCENE::move_world:
        _world_pos.set(x,y,z);

        break;
    case SCENE::move_camera:
        switch(_scene)
        {
        case SCENE::sall://to-do
            //_prospective._distance=_val;

            break;
        case SCENE::s3d:
            _tel_3d._pointEye.x+=_camx;
            _tel_3d._pointEye.y+=_camy;
            _tel_3d._pointEye.z+=_camz;

            _tel_3d._pointCenter.x+=_camx;
            _tel_3d._pointCenter.y+=_camy;
            _tel_3d._pointCenter.z+=_camz;

            break;
        case SCENE::sleft:
            _tel_left._pointEye.x+=_camx;
            _tel_left._pointEye.y+=_camy;
            _tel_left._pointEye.z+=_camz;

            _tel_left._pointCenter.x+=_camx;
            _tel_left._pointCenter.y+=_camy;
            _tel_left._pointCenter.z+=_camz;


            break;
        case SCENE::sright:
            _tel_right._pointEye.x+=_camx;
            _tel_right._pointEye.y+=_camy;
            _tel_right._pointEye.z+=_camz;

            _tel_right._pointCenter.x+=_camx;
            _tel_right._pointCenter.y+=_camy;
            _tel_right._pointCenter.z+=_camz;


            break;
        case SCENE::stop:
            _tel_top._pointEye.x+=_camx;
            _tel_top._pointEye.y+=_camy;
            _tel_top._pointEye.z+=_camz;

            _tel_top._pointCenter.x+=_camx;
            _tel_top._pointCenter.y+=_camy;
            _tel_top._pointCenter.z+=_camz;

            break;
        case SCENE::sbottom:
            _tel_bottom._pointEye.x+=_camx;
            _tel_bottom._pointEye.y+=_camy;
            _tel_bottom._pointEye.z+=_camz;

            _tel_bottom._pointCenter.x+=_camx;
            _tel_bottom._pointCenter.y+=_camy;
            _tel_bottom._pointCenter.z+=_camz;



            break;
        case SCENE::sfront:
            _tel_front._pointEye.x+=_camx;
            _tel_front._pointEye.y+=_camy;
            _tel_front._pointEye.z+=_camz;

            _tel_front._pointCenter.x+=_camx;
            _tel_front._pointCenter.y+=_camy;
            _tel_front._pointCenter.z+=_camz;



            break;
        case SCENE::sback:
            _tel_back._pointEye.x+=_camx;
            _tel_back._pointEye.y+=_camy;
            _tel_back._pointEye.z+=_camz;

            _tel_back._pointCenter.x+=_camx;
            _tel_back._pointCenter.y+=_camy;
            _tel_back._pointCenter.z+=_camz;



            break;

        }


        break;
    case SCENE::move_camera_center:
        switch(_scene)
        {
        case SCENE::sall://to-do
            //_prospective._distance=_val;

            break;
        case SCENE::s3d:
            _tel_3d._pointEye.x+=_camx;
            _tel_3d._pointEye.y+=_camy;
            _tel_3d._pointEye.z+=_camz;

            _tel_3d._pointCenter.x=0.0F;
            _tel_3d._pointCenter.y=0.0F;
            _tel_3d._pointCenter.z=0.0F;

            break;
        case SCENE::sleft:
            _tel_left._pointEye.x+=_camx;
            _tel_left._pointEye.y+=_camy;
            _tel_left._pointEye.z+=_camz;


            break;
        case SCENE::sright:
            _tel_right._pointEye.x+=_camx;
            _tel_right._pointEye.y+=_camy;
            _tel_right._pointEye.z+=_camz;


            break;
        case SCENE::stop:
            _tel_top._pointEye.x+=_camx;
            _tel_top._pointEye.y+=_camy;
            _tel_top._pointEye.z+=_camz;

            break;
        case SCENE::sbottom:
            _tel_bottom._pointEye.x+=_camx;
            _tel_bottom._pointEye.y+=_camy;
            _tel_bottom._pointEye.z+=_camz;



            break;
        case SCENE::sfront:
            _tel_front._pointEye.x+=_camx;
            _tel_front._pointEye.y+=_camy;
            _tel_front._pointEye.z+=_camz;





            break;
        case SCENE::sback:
            _tel_back._pointEye.x+=_camx;
            _tel_back._pointEye.y+=_camy;
            _tel_back._pointEye.z+=_camz;



            break;


        }


        break;
    }
}

void l3d_view::set_prospective_distance(l3d_double _val)
{


    setMoviment(_val,1);



    return;
    switch(_scene)
    {
    case SCENE::sall://to-do
        _prospective._distance=_val;

        break;
    case SCENE::s3d:
        _prospective_3d._distance=_val;

        break;
    case SCENE::sleft:
        _prospective_left._distance=_val;

        break;
    case SCENE::sright:
        _prospective_right._distance=_val;

        break;
    case SCENE::stop:
        _prospective_top._distance=_val;

        break;
    case SCENE::sbottom:
        _prospective_bottom._distance=_val;


        break;

    }

}

l3d_double l3d_view::get_prospective_distance()
{


    return _distance;


    switch(_scene)
    {
    case SCENE::sall://to-do
        return _prospective._distance;

        break;
    case SCENE::s3d:
        return _prospective_3d._distance;

        break;
    case SCENE::sleft:
        return _prospective_left._distance;

        break;
    case SCENE::sright:
        return _prospective_right._distance;

        break;
    case SCENE::stop:
        return _prospective_top._distance;

        break;
    case SCENE::sbottom:
        return _prospective_bottom._distance;


        break;

    }

}
void l3d_view::set_prospective_distance2(l3d_double _val)
{


    setMoviment(_val,2);


    return;
    switch(_scene)
    {
    case SCENE::sall://to-do
        _prospective._distance=_val;

        break;
    case SCENE::s3d:
        _prospective_3d._distance=_val;

        break;
    case SCENE::sleft:
        _prospective_left._distance=_val;

        break;
    case SCENE::sright:
        _prospective_right._distance=_val;

        break;
    case SCENE::stop:
        _prospective_top._distance=_val;

        break;
    case SCENE::sbottom:
        _prospective_bottom._distance=_val;


        break;

    }

}

l3d_double l3d_view::get_prospective_distance2()
{


    return _distance2;

    switch(_scene)
    {
    case SCENE::sall://to-do
        return _prospective._distance;

        break;
    case SCENE::s3d:
        return _prospective_3d._distance;

        break;
    case SCENE::sleft:
        return _prospective_left._distance;

        break;
    case SCENE::sright:
        return _prospective_right._distance;

        break;
    case SCENE::stop:
        return _prospective_top._distance;

        break;
    case SCENE::sbottom:
        return _prospective_bottom._distance;


        break;

    }

}

void l3d_view::set_prospective_distance3(l3d_double _val)
{


    setMoviment(_val,3);


    return;
    switch(_scene)
    {
    case SCENE::sall://to-do
        _prospective._distance=_val;

        break;
    case SCENE::s3d:
        _prospective_3d._distance=_val;

        break;
    case SCENE::sleft:
        _prospective_left._distance=_val;

        break;
    case SCENE::sright:
        _prospective_right._distance=_val;

        break;
    case SCENE::stop:
        _prospective_top._distance=_val;

        break;
    case SCENE::sbottom:
        _prospective_bottom._distance=_val;


        break;

    }

}

l3d_double l3d_view::get_prospective_distance3()
{

    return _distance3;

    switch(_scene)
    {
    case SCENE::sall://to-do
        return _prospective._distance;

        break;
    case SCENE::s3d:
        return _prospective_3d._distance;

        break;
    case SCENE::sleft:
        return _prospective_left._distance;

        break;
    case SCENE::sright:
        return _prospective_right._distance;

        break;
    case SCENE::stop:
        return _prospective_top._distance;

        break;
    case SCENE::sbottom:
        return _prospective_bottom._distance;


        break;

    }

}
void l3d_view::setViewport(l3d_uint x0, l3d_uint y0, l3d_uint x1, l3d_uint y1)
{
    _viewport.set(x0,y0,x1,y1);
    glViewport(x0,y0,x1,y1);

    _viewport4[0].set(0.0,x1/2.0,y1/2.0,x1/2.0);

    _viewport4[1].set(y1/2.0,x1/2.0,y1/2.0,x1/2.0);

    _viewport4[2].set(0.0,0.0,y1/2,x1/2);

    _viewport4[3].set(y1/2.0,0.0,y1/2,x1/2);
}
void l3d_view::setScene(SCENE::SceneType scene)
{
    static float _distance=250.0F;
    _scene=scene;
    //impostare la telecamera
    l3d_vertex_fast _eye,_center,_up;

    _center.set(0.0F,0.0F,0.0F);
     _up.set(0.0F,1.0F,0.0F);
     _tel_3d._pointUp=_up;
     _tel_left._pointUp=_up;
     _tel_right._pointUp=_up;

     _tel_3d._pointCenter=_center;
     _tel_top._pointCenter=_center;
     _tel_bottom._pointCenter=_center;
     _tel_left._pointCenter=_center;
     _tel_right._pointCenter=_center;
     _tel_front._pointCenter=_center;
     _tel_back._pointCenter=_center;

    switch(_scene)
    {
    case SCENE::sall://to-do
        break;
    case SCENE::s3d:
        _eye.set(0.0F,_distance,-_distance);
        _tel_3d._pointEye=_eye;
        break;
    case SCENE::sleft:
        _eye.set(_distance,0.0F,0.0F);
        _tel_left._pointEye=_eye;
        break;
    case SCENE::sright:
        _eye.set(-_distance,0.0F,0.0F);
        _tel_right._pointEye=_eye;
        break;
    case SCENE::stop:
        _eye.set(0.0F,_distance,0.0F);
        _up.set(0.0F,0.0F,1.0F);
        _tel_top._pointEye=_eye;
        _tel_top._pointUp=_up;
        break;
    case SCENE::sbottom:
        _eye.set(0.0F,-_distance,0.0F);
        _up.set(0.0F,0.0F,-1.0F);
        _tel_bottom._pointEye=_eye;
        _tel_bottom._pointUp=_up;
        break;
    case SCENE::sfront:
        _eye.set(0.0F,0.0F,_distance);
        _tel_front._pointEye=_eye;
        _tel_front._pointUp=_up;

        break;
    case SCENE::sback:
        _eye.set(0.0F,0.0F,-_distance);
        _tel_back._pointEye=_eye;
        _tel_back._pointUp=_up;

        break;

    }

    setCamera(_eye,_center,_up);
}
void l3d_view::setDrawFunction(void (*_draw)(void))
{
    _draw_function=_draw;
}

void l3d_view::PipeLine4()
{
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glClearColor(0.5f,0.5f,0.5f,0.0F);


    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    //_prospective.set(SCENE::s3d);
    glOrtho(-1.0F,1.0F,-1.0F,1.0F,-100.0F,100.0F);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glDrawBuffer(GL_BACK);

    glPushMatrix();
        //glDisable(GL_LIGHTING);
        //_viewport.init();

        glLineWidth(4.0F);
        glColor3f(1.0F,1.0F,1.0F);
        glBegin(GL_LINES);

            glVertex2f(0.0F,1.0F);
            glVertex2f(0.0F,-1.0F);

            glVertex2f(-1.0F,0.0F);
            glVertex2f(1.0F,0.0F);

        glEnd();
        glLineWidth(6.0F);
        glColor3f(0.2F,0.2F,0.2F);
        glBegin(GL_LINES);

            glVertex2f(0.0F,1.0F);
            glVertex2f(0.0F,-1.0F);

            glVertex2f(-1.0F,0.0F);
            glVertex2f(1.0F,0.0F);

        glEnd();

    glPopMatrix();

    //init view 1
    /*glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _prospective.set(SCENE::stop);

    //glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

    glPushMatrix();
        //m_mainviewport[0].set();
        _viewport4[0].init();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        _telecamera.init();
        //m_mainviewport[0].m_cam.SetPos();

        Draw();
    glPopMatrix();

    //init view 2

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _prospective.set(SCENE::sbottom);

    //glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

    glPushMatrix();

        //m_mainviewport[1].set();
        _viewport4[1].init();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        _telecamera.init();
        //m_mainviewport[1].m_cam.SetPos();

        Draw();

    glPopMatrix();

    //init view 3

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _prospective.set(SCENE::sleft);
    //glOrtho(-100.0F,100.0F,-100.0F,100.0F,-100.0F,10000.0F);

    glPushMatrix();
        //m_mainviewport[2].set();
        _viewport4[2].init();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        _telecamera.init();
        //m_mainviewport[2].m_cam.SetPos();

        Draw();
    glPopMatrix();


    //init view 4

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _prospective.set(SCENE::s3d);
    //gluPerspective(45.0f,1.5F,1.0F,10000.0F);

    glPushMatrix();

        //m_mainviewport[3].set();
        _viewport4[3].init();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        _telecamera.init();
        //m_maincamera.Draw();
        //m_mainviewport[0].set();

        Draw();*/

    glPopMatrix();

}

void l3d_view::PipeLine()
{
    if(_scene==SCENE::sall)
        PipeLine4();

    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glClearColor(0.5f,0.5f,0.5f,0.0F);

    glEnable(GL_LIGHTING);

    _lightmodel.set();


    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();


    Prospective();



    Camera();


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();
    //scene trasformation
    /*switch(_scene)
    {
    case SCENE::sall://to-do
        glTranslatef(0.0F,0.0F,0.0F);

        break;
    case SCENE::s3d:
        glTranslatef(_distance2,_distance,0.0F);

        break;
    case SCENE::sleft:
        glTranslatef(_distance,_distance2,0.0F);

        break;
    case SCENE::sright:
        glTranslatef(-_distance,_distance2,0.0F);

        break;
    case SCENE::stop:
        glTranslatef(_distance2,_distance,0.0F);

        break;
    case SCENE::sbottom:
        glTranslatef(_distance2,-_distance,0.0F);


        break;

    }*/



    glTranslatef(_world_pos.x,_world_pos.y,_world_pos.z);



    glRotatef(0.0F,1.0,0.0,0.0);

    glRotatef(0.0F,0.0,1.0,0.0);

    glRotatef(0.0F,0.0,0.0,1.0);

    Draw();
    drawTool(_maindocument->getmainscenedoc()->gettoolpos(),false);

    glPopMatrix();

}
void l3d_view::setTool(SCENE::SelectTool st)
{
    _selectedtool=st;
}

void l3d_view::setDocument(document* _doc)
{
    _maindocument=_doc;
    //_modedoc=_maindocument->getmainscenedoc()->getmodedocument();
}
void l3d_view::drawTool(l3d_vertex_fast _pos,l3d_bool _select)
{
    glDisable(GL_LIGHTING);
    //float fmax=-1.0F;
    switch(_selectedtool)
    {
        case SCENE::st_normal:

        break;
        case SCENE::st_move://move tool selected

             _movetools.setpos(_pos);
            if(_select)
                _movetools.DrawSelect();
            else
                _movetools.Draw(false);


        break;
        case SCENE::st_scale:
            _scaletools.setpos(_pos);
            if(_select)
                _scaletools.DrawSelect();
            else
                _scaletools.Draw(false);


        break;
        case SCENE::st_rotate:

            //m_toolrotate.SetWorldPos(appv.GetX(),appv.GetY(),appv.GetZ());
            //m_toolrotate.setmax(fmax);
            //m_toolrotate.Draw(true);

        break;

    }
    glEnable(GL_LIGHTING);
}

void l3d_view::DrawPiano()
{

        int ix;
        float fx=0.0F,fz=0.0F;

        float width=200.0F;
        float densita;

        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);

        glDisable(GL_LIGHTING);
        glPushMatrix();

        glTranslatef(0.0F,0.0F,0.0F);


        glRotatef(0.0F,1.0,0.0,0.0);

        glRotatef(0.0F,0.0,1.0,0.0);

        glRotatef(0.0F,0.0,0.0,1.0);





        glLineWidth(1.0F);

        glBegin(GL_LINES);

        fx=0.0F;
        fz=0.0F;


        densita=width*10.0f;

        glColor4f(0.6F,0.6F,0.6F,1.0F);

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {

                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx+width,0.0F,fz-width);


                fz+=(densita/width);
        }
        fx=0.0F;
        fz=0.0F;

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {
                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx-width,0.0F,fz+width);

                fx+=(densita/width);
        }


        glColor3f(0.0F,1.0F,0.0F);

        glVertex3f(-width,0.0F,0.0F);
        glVertex3f(width,0.0F,0.0F);

        glColor3f(0.0F,0.0F,1.0F);


        glColor3f(1.0F,0.0F,0.0F);

        glVertex3f(0.0F ,0.0F ,-width);
        glVertex3f(0.0F ,0.0F , width);


        glEnd();
        glPopMatrix();

        glEnable(GL_LIGHTING);

}

void l3d_view::DrawPianoOrtho()
{

        int ix;
        float fx=0.0F,fz=0.0F;

        float width=300.0F;
        float densita;

        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);

        glDisable(GL_LIGHTING);
        glPushMatrix();

        glTranslatef(0.0F,0.0F,0.0F);
        if(_scene==SCENE::sleft || _scene==SCENE::sright )
        {
            glRotatef(0.0F,1.0,0.0,0.0);
            glRotatef(0.0F,0.0,1.0,0.0);
            glRotatef(90.0F,0.0,0.0,1.0);

        }
        else if ( _scene==SCENE::sfront|| _scene==SCENE::sback)
        {
            glRotatef(0.0F,1.0,0.0,0.0);
            glRotatef(0.0F,0.0,1.0,0.0);
            glRotatef(0.0F,0.0,0.0,1.0);

        }
        else
        {
            glRotatef(0.0F,1.0,0.0,0.0);
            glRotatef(0.0F,0.0,1.0,0.0);
            glRotatef(0.0F,0.0,0.0,1.0);
        }




        glLineWidth(1.0F);

        glBegin(GL_LINES);

        fx=0.0F;
        fz=0.0F;


        densita=width*5.0f;

        glColor4f(0.6F,0.6F,0.6F,1.0F);

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {

                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx+width,0.0F,fz-width);


                fz+=(densita/width);
        }
        fx=0.0F;
        fz=0.0F;

        for (ix=0; ix <= width*2 ; ix+=(densita/width))
        {
                glVertex3f(fx-width,0.0F,fz-width);
                glVertex3f(fx-width,0.0F,fz+width);

                fx+=(densita/width);
        }


        if(_scene==SCENE::sleft || _scene==SCENE::sright)
            glColor3f(0.0F,0.0F,1.0F);
        else
            glColor3f(0.0F,1.0F,0.0F);

        glVertex3f(-width,0.0F,0.0F);
        glVertex3f(width,0.0F,0.0F);

        glColor3f(0.0F,0.0F,1.0F);


        glColor3f(1.0F,0.0F,0.0F);

        glVertex3f(0.0F ,0.0F ,-width);
        glVertex3f(0.0F ,0.0F , width);


        glEnd();
        glPopMatrix();

        glEnable(GL_LIGHTING);

}
void l3d_view::Draw()
{

    if(isOrtho( _scene))
        DrawPianoOrtho();
    else
        DrawPiano();


    switch(_docselect)
    {
        case SCENE::dsmainscene:
            _maindocument->getmainscenedoc()->draw();
            //appv = _maindocument->getmainscenedoc()->gettoolpos();
            //fmax= m_maindocument->getmainscenedoc()->getmax();

        break;
    }

}
void l3d_view::setDocumentSelect(SCENE::DocumentSelect _dsel)
{
    _docselect=_dsel;
}


l3d_uint l3d_view::drawSelect(l3d_uint _sx, l3d_uint _sy, l3d_uint _rx, l3d_uint _ry)
{
    int st=SelectTools(_sx,_sy,_rx,_ry);

    if(st==20000 || st==20001 || st==20002|| st==20003)
        return -1;

    GLuint *buffer=(GLuint*) ::malloc(sizeof(GLuint)*10000);

    GLint viewport[4];
    glSelectBuffer(10000,buffer );
    glRenderMode(GL_SELECT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix ();

    {
        glGetIntegerv( GL_VIEWPORT , viewport );
        gluPickMatrix(_sx,viewport[3]-_sy,5,5,viewport);
        Prospective();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        Camera();

        glInitNames();
        glPushName(~0);

        //scene trasformation
        /*switch(_scene)
        {
        case SCENE::sall://to-do
            glTranslatef(0.0F,0.0F,0.0F);

            break;
        case SCENE::s3d:
            glTranslatef(_distance2,_distance,0.0F);

            break;
        case SCENE::sleft:
            glTranslatef(_distance,_distance2,0.0F);

            break;
        case SCENE::sright:
            glTranslatef(-_distance,_distance2,0.0F);

            break;
        case SCENE::stop:
            glTranslatef(_distance2,_distance,0.0F);

            break;
        case SCENE::sbottom:
            glTranslatef(_distance2,-_distance,0.0F);


            break;

        }*/

        glTranslatef(_world_pos.x,_world_pos.y,_world_pos.z);

        glRotatef(0.0F,1.0,0.0,0.0);

        glRotatef(0.0F,0.0,1.0,0.0);

        glRotatef(0.0F,0.0,0.0,1.0);

        /*switch(_maindocument->getmainscenedoc()->getmodedocument())
        {
        case SCENE::normal:
            switch(_docselect)
                {
                    case SCENE::dsmainscene:
                        _maindocument->getmainscenedoc()->drawedit();
                        //appv=_maindocument->getmainscenedoc()->gettoolpos();
                    break;
                }

                break;
        case SCENE::animation:
            //DrawEditAnimation();

                break;
        case SCENE::paint:/*
                switch(modeedit)
                {

                case SCENE::vertex:
                  //DrawEditVertex();
                    switch(_docselect)
                    {
                        case SCENE::dsmainscene:
                            _maindocument->getmainscenedoc()->draweditvertex();
                        break;
                    }


                        break;

                case SCENE::line:
                  //DrawEditLine();
                    switch(_docselect)
                    {
                        case SCENE::dsmainscene:
                            _maindocument->getmainscenedoc()->draweditline();
                        break;
                    }

                        break;

                case SCENE::polygon:
                    //DrawEditPoligon();
                    switch(_docselect)
                    {
                        case SCENE::dsmainscene:
                            _maindocument->getmainscenedoc()->draweditpoligon();
                        break;
                    }




                        break;
                }*/
/*
                break;
        case SCENE::edit:
            switch(_maindocument->getmainscenedoc()->geteditmode())
            {

            case SCENE::vertex:
              //DrawEditVertex();
                switch(_docselect)
                {
                    case SCENE::dsmainscene:
                        _maindocument->getmainscenedoc()->draweditvertex();
                    break;
                }


                    break;

            case SCENE::line:
              //DrawEditLine();
                switch(_docselect)
                {
                    case SCENE::dsmainscene:
                        _maindocument->getmainscenedoc()->draweditline();
                    break;
                }

                    break;

            case SCENE::polygon:
                //DrawEditPoligon();
                switch(_docselect)
                {
                    case SCENE::dsmainscene:
                        _maindocument->getmainscenedoc()->draweditpoligon();
                    break;
                }




                    break;
            }

            break;




        }*/


    }glPopMatrix();

    int m_hint=glRenderMode(GL_RENDER);

    int ns=0;
    if (m_hint)
    {
            int n=0;double minz=buffer[1];

            for(int i=1 ; i <m_hint ; i++)
            {
                if ( buffer[1+i*4] < minz )
                {
                    n=i;
                    minz=buffer[1+i*4];
                }
            }

            ns=buffer[3+n*4];


    }

    else

    {

            if(_modedoc==SCENE::normal)
                 _maindocument->getmainscenedoc()->unselectobject();
            //Main_insert->update();



    }
    free(buffer);

    //Main_insert->update();

    return(ns);

}
void l3d_view::setInput(pl3d_input_state _i)
{
    _input=_i;
}
void l3d_view::setOrtho(l3d_bool _ortho)
{
    switch(_scene)
    {
    case SCENE::sall://to-do
        _prospective._ortho=_ortho;

        break;
    case SCENE::s3d:
        _prospective_3d._ortho=_ortho;

        break;
    case SCENE::sleft:
        _prospective_left._ortho=_ortho;

        break;
    case SCENE::sright:
        _prospective_right._ortho=_ortho;

        break;
    case SCENE::stop:
        _prospective_top._ortho=_ortho;

        break;
    case SCENE::sbottom:
        _prospective_bottom._ortho=_ortho;


        break;
    case SCENE::sfront:
        _prospective_front._ortho=_ortho;


        break;
    case SCENE::sback:
        _prospective_back._ortho=_ortho;


        break;

    }
}
l3d_bool l3d_view::isOrtho(SCENE::SceneType _s)
{
    switch(_s)
    {
    case SCENE::sall://to-do
        return(_prospective._ortho);

        break;
    case SCENE::s3d:
        return(_prospective_3d._ortho);

        break;
    case SCENE::sleft:
        return(_prospective_left._ortho);

        break;
    case SCENE::sright:
        return(_prospective_right._ortho);

        break;
    case SCENE::stop:
        return(_prospective_top._ortho);

        break;
    case SCENE::sbottom:
        return(_prospective_bottom._ortho);


        break;
    case SCENE::sfront:
        return(_prospective_front._ortho);


        break;
    case SCENE::sback:
        return(_prospective_back._ortho);


        break;

    }
}
void l3d_view::setMove(SCENE::SceneMove _move)
{
    _movetype=_move;
}
int l3d_view::SelectTools(int _sx,int _sy, int _rx, int _ry)
{
    l3d_vertex_fast pos=_maindocument->getmainscenedoc()->gettoolpos();

    GLuint *buffer=(GLuint*) ::malloc(sizeof(GLuint)*10000);

    GLint viewport[4];
    glSelectBuffer(10000,buffer );
    glRenderMode(GL_SELECT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix ();

    {
        glGetIntegerv( GL_VIEWPORT , viewport );
        gluPickMatrix(_sx,viewport[3]-_sy,5,5,viewport);
        Prospective();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        Camera();

        glInitNames();
        glPushName(~0);

        //world transformaton
        glTranslatef(_world_pos.x,_world_pos.y,_world_pos.z);

        glRotatef(0.0F,1.0,0.0,0.0);

        glRotatef(0.0F,0.0,1.0,0.0);

        glRotatef(0.0F,0.0,0.0,1.0);

        switch(_selectedtool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected

                     if(_input->isnot_movevertex())
                        drawTool(pos,true);


                break;

               case SCENE::st_scale://move tool selected

                    //if(!m_movevertex[0] && !m_movevertex[1] && !m_movevertex[2])

                    drawTool(pos,true);

                break;

                case SCENE::st_rotate://move tool selected

                    //if(!m_movevertex[0] && !m_movevertex[1] && !m_movevertex[2])
                     drawTool(pos,true);

                 break;
            }
    }

    glPopMatrix();

    unsigned int m_hint=glRenderMode(GL_RENDER);

    int ns=-1;
    qDebug() << "hint select:" << m_hint;

    if (m_hint)
    {
        int n=0;double minz=buffer[1];

        for(int i=1 ; i <m_hint ; i++)
        {
            if ( buffer[1+i*4] < minz )
            {
                n=i;
                minz=buffer[1+i*4];
            }
        }

        ns=buffer[3+n*4];

    }
    else
    {
        free(buffer);
        return (-1);

    }

    if (ns==20000 || ns==20001 || ns==20002 || ns==20003)
    {
        //_modedoc=_maindocument->getmainscenedoc()->getmodedocument();
        switch(_modedoc)
        {
        case SCENE::normal:

            switch(_selectedtool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected


                   _input->move(true,ns-20000);

                   //m_moveobj[ns-20000]=true;

               break;

               case SCENE::st_scale://move tool selected

                   _input->scale(true,ns-20000);
                   //m_bscale=true;
                   //m_scalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://move tool selected

                    _input->rotate(true,ns-20000+1);
                    //m_brotate=true;
                    //m_rotatexyz=ns-20000+1;

                break;
            }
            break;
        case SCENE::edit:
            switch(_selectedtool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected

                    _input->move_vertex(true,ns-20000);
                   //m_bmove=true;

                   //m_movevertex[ns-20000]=true;

               break;

               case SCENE::st_scale://scale tool selected

                    _input->scale_vertex(true,ns-20000);
                   //m_bscale=true;
                   //m_scalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://rotate tool selected

                    _input->rotate_vertex(true,ns-20000+1);
                    //m_brotate=true;
                    //m_rotatexyz=ns-20000+1;

                break;
            }
            break;

        case SCENE::animation:
            switch(_selectedtool)
            {

               case SCENE::st_normal:


                break;

               case SCENE::st_move://move tool selected


                   //m_animationstate->m_bismove=true;

                   //m_animationstate->m_moveobj[ns-20000]=true;

               break;

               case SCENE::st_scale://scale tool selected

                   //m_animationstate->m_bisscale=true;
                   //m_animationstate->m_iscalexyz=ns-20000+1;

                break;
                case SCENE::st_rotate://rotate tool selected

                    //m_animationstate->m_bisrotate=true;
                    //m_animationstate->m_irotatexyz=ns-20000+1;

                break;
            }
            break;
        }
    }
    free(buffer);

    return(ns);

}
