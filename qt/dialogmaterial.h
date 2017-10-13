#ifndef DIALOGMATERIAL_H
#define DIALOGMATERIAL_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <QDialog>

#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"
#include "mesh/l3d_material.h"

using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;


namespace Ui {
    class DialogMaterial;
}
class previewmaterial;

class DialogMaterial : public QDialog
{
    Q_OBJECT

public:
    pl3d_material_struct getmaterial();
    explicit DialogMaterial(QWidget *parent = 0);
    ~DialogMaterial();
    void starttimer();
    void stoptimer();
    void setmaterial(pl3d_material_struct );
private:
    previewmaterial * m_preview;
    Ui::DialogMaterial *ui;
    QTimer * m_timer;
    pl3d_material_struct m_material;

    void initdialog();
public slots:
    void update();
private slots:

    void on_buttonBox_accepted();
};

class previewmaterial : public QGLWidget
{
    Q_OBJECT
public:

    previewmaterial(QWidget *parent = 0);
    ~previewmaterial();
    //add insert class
    pl3d_material_struct m_material;
    bool preview;
    l3d_mesh_struct m_sphere;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    virtual void mousePressEvent ( QMouseEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual void mouseMoveEvent ( QMouseEvent * e );
private:
    QPoint pmouse;
    bool mpress;


public slots:
    void update();
};


#endif // DIALOGMATERIAL_H
