#ifndef NEWOBJECT_H
#define NEWOBJECT_H
#include <QOpenGLFunctions>
#include <QDialog>


#include "mesh/l3d_mesh.h"

using namespace l3d::mesh;


class objectGL;

namespace Ui {
    class newobject;
}

class newobject : public QDialog
{
    Q_OBJECT

public:
    explicit newobject(int page,QWidget *parent = 0);
    ~newobject();
    void getline(int*,float*);
    void getcircle(int*,float*);
    void getdisck(int*,float*);
    void getplane(int*,float*,int*);
    void getcube(int*,float*);
    void getsphere(int*,int*,float*);
    void getcone(float* height,int* segments);
    void gettube(float *height,int* segments, int * sidesegments);
    void gettuben(float *height,float *radius,int* segments, int * sidesegments);
    void gettorus(float* maxr,float*minr,int*maxs,int*mins);
    l3d_mesh_struct getobject();
    objectGL *m_gl;
private:
    Ui::newobject *ui;
    int m_page;
    l3d_mesh_struct nobj;
    QTimer *m_timer;
public slots:
    void update();
private slots:

    void on_pbpreview_clicked();
    void on_insertline_2_clicked();
    void on_tbinsertcircle_clicked();
    void on_tbinsertdisck_clicked();
    void on_tbinsertplane_clicked();
    void on_tbinsertcube_clicked();

};

class objectGL : public QGLWidget
{
    Q_OBJECT
public:
    objectGL(QWidget *parent = 0);
    ~objectGL();
    //objline* m_oline;
    //circle *m_circle;
    //disck *m_disck;
    //plane *m_plane;
    //cube *m_cube;
    //sphereuv *m_sphere;
    //cone * m_cone;
    //torus * m_torus;
    //tubes * m_tube;
    //sphereuv * newsphere;

    bool preview;
    int m_page;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:
    QTimer * m_timer;
public slots:
    void update();
};


#endif // NEWOBJECT_H
