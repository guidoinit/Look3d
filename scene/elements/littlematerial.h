#ifndef LITTLEMATERIAL_H
#define LITTLEMATERIAL_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>



#include "../../mesh/l3d_material.h"


using namespace l3d::material;
class littlematerial : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit littlematerial(QWidget *parent = 0);

    pl3d_material_struct  m_material;
    bool preview;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:


public slots:
    void update();
signals:


};

#endif // LITTLEMATERIAL_H
