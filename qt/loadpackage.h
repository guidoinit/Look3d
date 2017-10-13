#ifndef LOADPACKAGE_H
#define LOADPACKAGE_H

#include <QDialog>

namespace Ui {
    class loadpackage;
}

class loadpackage : public QDialog
{
    Q_OBJECT

public:
    explicit loadpackage(QWidget *parent = 0);
    ~loadpackage();

private:
    Ui::loadpackage *ui;
};

#endif // LOADPACKAGE_H
