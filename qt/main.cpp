

#include <QApplication>
#include "mainwindow.h"





insertObject * Main_insert;



int main(int argc, char *argv[])
{


    QApplication a(argc, argv);


  //  a.setGlobalMouseTracking(true);
    MainWindow w;
    w.show();

    return a.exec();
}
