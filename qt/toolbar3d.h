#ifndef TOOLBAR3D_H
#define TOOLBAR3D_H

//#include"mainwindow.h"
#include <QToolBar>
#include <QDockWidget>

class ToolBar3D : public QToolBar
{
   // Q_OBJECT
public:
    ToolBar3D();
    ~ToolBar3D();
    //ToolBar3D(MainWindow*);
    void CreateAction();
    void setDock(QDockWidget *);
private:
    //MainWindow * pmain;

    QDockWidget *doc1;

    QAction *newAct;
    QAction *objectAct;
    QAction *saveAct;
    QAction *saveasAct;
    QAction *exportAct;
    QAction *exportAsAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *boldAct;
    QAction *italicAct;
    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *justifyAct;
    QAction *centerAct;
    QAction *setLineSpacingAct;
    QAction *setParagraphSpacingAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
public slots:
    void home();
    void object();
};

#endif // TOOLBAR3D_H
