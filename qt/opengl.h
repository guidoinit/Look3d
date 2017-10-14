#ifndef OPENGL_H
#define OPENGL_H



#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "scene/sceneinclude.h"

class OpenGL :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGL(QWidget *parent = 0);
    ~OpenGL();
    void start_timer();
    void stop_timer();
    scene * pscene;
public slots:

    void buttonclicked();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    virtual void mousePressEvent ( QMouseEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual void WheelEvent(QWheelEvent *event);
    virtual void keyPressEvent ( QKeyEvent * event);
    virtual void keyReleaseEvent ( QKeyEvent * event ) ;
    virtual void mouseMoveEvent ( QMouseEvent * e );
    void timerEvent(QTimerEvent *event);

protected slots:

private:
    int ntimer;
    int m_width;
    int m_heigth;
};

#endif // OPENGL_H
