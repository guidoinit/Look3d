#ifndef NEWSPHERE_H
#define NEWSPHERE_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <QtOpenGL>
#include <QDialog>




class SphereGL;

namespace Ui {
    class newSphere;
}

class newSphere : public QDialog
{
    Q_OBJECT

public:
    explicit newSphere(QWidget *parent = 0);
    ~newSphere();
    int u,v;
    float radius;
    bool preview;

    //object3d* getsphereuv();
    void getuvr(int *, int *, float *);


private slots:
    void on_spinBoxU_valueChanged(int arg1);

    void on_spinBoxV_valueChanged(int arg1);

    void on_spinBoxRadius_valueChanged(int arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkBoxPreview_toggled(bool checked);

private:
    Ui::newSphere *ui;

    SphereGL * m_ogl;

    QTimer * m_timer;

    //object3d retobject;

public slots:
    void update();

};




class SphereGL : public QGLWidget
{
    Q_OBJECT
public:
    SphereGL(QWidget *parent = 0);
    ~SphereGL();
    //sphereuv * newsphere;

    bool preview;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:
    QTimer * m_timer;
public slots:
    void update();
};



#endif // NEWSPHERE_H
