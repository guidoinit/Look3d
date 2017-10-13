#ifndef INSERTCIRLCE_H
#define INSERTCIRLCE_H

#define GLEW_STATIC
#include <GL/glew.h>




#include <QtOpenGL>
#include <QDialog>

class circleGL;

namespace Ui {
    class insertcircle;
}

class insertcircle : public QDialog
{
    Q_OBJECT

public:
    explicit insertcircle(QWidget *parent = 0);
    ~insertcircle();

    void getcircle(int *, float*);
private:
    circleGL *m_gl;
    QTimer *m_timer;
private slots:
    void on_checkBoxPreview_clicked();

    void on_spinBoxRadius_valueChanged(int arg1);

    void on_spinBoxV_valueChanged(int arg1);
public slots:
     void update();
private:
    Ui::insertcircle *ui;
};
class circleGL : public QGLWidget
{
    Q_OBJECT
public:
    circleGL(QWidget *parent = 0);
    ~circleGL();
    //circle * m_circle;
    float m_r;
    int m_p;
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
#endif // INSERTCIRLCE_H
