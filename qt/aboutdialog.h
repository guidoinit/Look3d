#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QGLWidget>
#include <QDialog>


class AboutGL;
class AboutGameGL;


namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;


    AboutGL * gl_about;
    AboutGameGL * gl_aboutgame;
};

class AboutGL : public QGLWidget
{
    Q_OBJECT
public:
    AboutGL(QWidget *parent = 0);
    ~AboutGL();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
};


class AboutGameGL : public QGLWidget
{
    Q_OBJECT
public:
    AboutGameGL(QWidget *parent = 0);
    ~AboutGameGL();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
};


#endif // ABOUTDIALOG_H
