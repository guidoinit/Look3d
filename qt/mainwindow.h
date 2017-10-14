#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QOpenGLFunctions>

#include <QMainWindow>
#include "newsphere.h"
#include "aboutdialog.h"
#include "fastinsert.h"
#include "qt/opengl.h"
#include "scene/documentinclude.h"
#include "insertobject.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    document * getdocument();

private slots:
    void on_actionAbout_triggered();

    void on_actionSphere_2_triggered();

    void on_actionProject_triggered();

    void on_actionExit_triggered();

    void on_actionNew_project_triggered();

    void on_actionActionHome_triggered();

    void on_actionObjects_triggered();

    void on_actionspheredlg_triggered();

    void on_actionOpen_project_triggered();

    void on_actionSaveproject_triggered();

    void on_actionSaveprojectas_triggered();

    void on_actionExportproject_triggered();

    void on_actionTools_triggered();

    void on_viewnew_clicked();

    void viewfullscreen();

    void on_actionTfullscreen_triggered();

    void on_actionFast_insert_triggered();

    void on_actionPackage_triggered();

    void on_actionPackage_2_triggered();

    void on_view3d_clicked();

    void on_viewtop_clicked();

    void on_viewbottom_clicked();

    void on_viewsolid_clicked();

    void on_viewwireframe_clicked();

    void on_viewcolor_clicked();

    void on_viewtexture_clicked();

    void on_treeViewMain_clicked(const QModelIndex &index);

    void on_mode3d_clicked();

    void on_modeedit_clicked();

    void on_modeanimation_clicked();

    void on_tbinsertsphere_clicked();

private:
    Ui::MainWindow *ui;

    newSphere *md_newsphere;
    AboutDialog * md_about;

    void updateMainDock();

    insertObject *m_insertobject;

    bool createmaindocument();

    fastinsert * m_fastinsert;

    document * m_maindocument;

    int m_numobject;

    OpenGL * mp_opengl;
    QStandardItemModel * maintreemodel;

};

#endif // MAINWINDOW_H
