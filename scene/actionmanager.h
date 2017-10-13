#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QObject>
#include <QVector>
#include <QAction>
#include <QMenu>


class ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = 0);
    void CreateActionToolBar();
    void CreateActionMainMenu();

    QMenu * getMainManu();

signals:

public slots:

private:
    //QList<QAction> p_actionsToolBar;
    //QList<QAction> p_actionsMainMenu;

};

#endif // ACTIONMANAGER_H
