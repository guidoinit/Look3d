#ifndef FASTINSERT_H
#define FASTINSERT_H
#define GLEW_STATIC
#include <GL/glew.h>
#include <QtOpenGL>
#include <QDialog>




namespace Ui {
    class fastinsert;
}

class insertGL;

class fastinsert : public QDialog
{
    Q_OBJECT

public:
    explicit fastinsert(QWidget *parent = 0);
    ~fastinsert();
    void starttimer();
    void stoptimer();
    //object3d getobject();
private:
    Ui::fastinsert *ui;
    bool m_bwireframe;
    insertGL * m_insertgl;
    QTimer * m_timer;
public slots:
    void update();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_view_wireframe_clicked();
    void on_view_solid_clicked();
    void on_loadpackage_clicked();
    void on_pbAddObject_clicked();
};


class insertGL : public QGLWidget
{
    Q_OBJECT
public:
    //insert * m_insert;
    insertGL(QWidget *parent = 0);
    ~insertGL();
    //add insert class

    bool preview;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:


public slots:
    void update();
};
#endif // FASTINSERT_H
