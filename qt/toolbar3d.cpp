#define GLEW_STATIC
#include <GL/glew.h>

#include <QtGui>
#include <QToolBar>
#include "toolbar3d.h"
#include "mainwindow.h"



class QIcon;
class QAction;

/*
ToolBar3D::ToolBar3D(MainWindow * mw)
{
    pmain=mw;
    ToolBar3D();

}
*/
ToolBar3D::ToolBar3D()
{
    QSize size;

    //imposta la dimensione dell'icona
    size.setHeight(32);
    size.setWidth(32);

    setIconSize(size);


    //imposta in orizzontale la toolbar

    setOrientation(Qt::Horizontal);


    //imposta il movimento della toolbar

    setMovable(true);

    setFloatable(true);

    Qt::ToolButtonStyle bstyle=Qt::ToolButtonIconOnly;//visualizza solo le icone


    setToolButtonStyle(bstyle);

    setAllowedAreas(Qt::AllToolBarAreas);

    CreateAction();


}

ToolBar3D::~ToolBar3D()
{

}


void ToolBar3D::setDock(QDockWidget * pdoc)
{
    doc1=pdoc;
}
void ToolBar3D::home()
{
    doc1->setFocus();
}
void ToolBar3D::object()
{
    doc1->setFocus();
}
void ToolBar3D::CreateAction()
{

    QIcon icon1("./images/home.png");
    QIcon icon2("./images/object.png");
    QIcon icon3("./images/open.png");
    QIcon icon4("./images/open.png");
    QIcon icon5("./images/open.png");
    QIcon icon6("./images/open.png");

    newAct = new QAction(icon1,tr("Home"), this);
    newAct->setShortcuts(QKeySequence::Delete);
    newAct->setStatusTip(tr("Main tools"));


    objectAct = new QAction(icon2,tr("Object"), this);
    objectAct->setShortcuts(QKeySequence::Delete);
    objectAct->setStatusTip(tr("Object tools"));




    addAction(newAct);
    connect(newAct, SIGNAL(triggered()), this, SLOT(home()));

    addAction(objectAct);
    connect(objectAct, SIGNAL(triggered()), this, SLOT(object()));

    /*
    QAction *openAct;
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
    */
    //icon.addFile(tr(""));

    //addAction(icon,tr("Home"));



    //addAction(icon2,tr("Object"));
    addAction(icon3,tr("Mode"));
    addAction(icon4,tr("Tools"));
    addAction(icon5,tr("Dialogs"));
    addAction(icon6,tr("Help"));

   //

    /*openAct = new QAction(tr("&Open project..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing project"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save project.."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the project to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    /*
       QAction *saveasAct;
       QAction *exportAct;
       QAction *exportAsAct;
    */
    /*
    saveasAct = new QAction(tr("&Save project as.."), this);
    saveasAct->setShortcuts(QKeySequence::Save);
    saveasAct->setStatusTip(tr("Save the project to disk as..."));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveas()));

    exportAct= new QAction(tr("&Export.."), this);
    exportAct->setShortcut(QKeySequence::Save);
    exportAct->setStatusTip("Export project as...");
    connect(exportAct, SIGNAL(triggered()), this, SLOT(exportas()));

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the project"));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

    boldAct = new QAction(tr("&Bold"), this);
    boldAct->setCheckable(true);
    boldAct->setShortcut(QKeySequence::Bold);
    boldAct->setStatusTip(tr("Make the text bold"));
    connect(boldAct, SIGNAL(triggered()), this, SLOT(bold()));

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    italicAct = new QAction(tr("&Italic"), this);
    italicAct->setCheckable(true);
    italicAct->setShortcut(QKeySequence::Italic);
    italicAct->setStatusTip(tr("Make the text italic"));
    connect(italicAct, SIGNAL(triggered()), this, SLOT(italic()));

    QFont italicFont = italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);

    setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
    setLineSpacingAct->setStatusTip(tr("Change the gap between the lines of a "
                                       "paragraph"));
    connect(setLineSpacingAct, SIGNAL(triggered()), this, SLOT(setLineSpacing()));

    setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
    setLineSpacingAct->setStatusTip(tr("Change the gap between paragraphs"));
    connect(setParagraphSpacingAct, SIGNAL(triggered()),
            this, SLOT(setParagraphSpacing()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));
    */
}
