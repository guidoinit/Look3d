#include <QObject>
#include <QAction>
#include <QMenu>
#include <QVector>
#include "actionmanager.h"

ActionManager::ActionManager(QObject *parent) :
    QObject(parent)
{
}

void ActionManager::CreateActionToolBar()
{

    //p_actionsToolBar.clear();

    QAction *myaction=new QAction(QIcon(":/images/open.png"), tr("&New..."), this);

    myaction->setShortcuts(QKeySequence::New);

    myaction->setStatusTip(tr("New project..."));

    //_actions.append(*myaction);


    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

}
void ActionManager::CreateActionMainMenu()
{

   // p_actionsMainMenu.clear();

    QAction *myaction=new QAction(QIcon(":/images/open.png"), tr("&New..."), this);

    myaction->setShortcuts(QKeySequence::New);

    myaction->setStatusTip(tr("New project..."));

    //p_actionsMainMenu.append(*myaction);

    //_actions.append(*myaction);


    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

}

QMenu * ActionManager::getMainManu()
{

    //QMenu * mainmenu= new QMenu(QString("MainMenu"));


   // QAction appa=_actions.at(0);

    //mainmenu->addAction(appa);



    //to-do aggiungere le latre voci del menu




   // return mainmenu;




}
