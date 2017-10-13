#ifndef NEWPACKAGE_H
#define NEWPACKAGE_H

#include <QDialog>

namespace Ui {
    class newpackage;
}

class newpackage : public QDialog
{
    Q_OBJECT

public:
    explicit newpackage(QWidget *parent = 0);
    ~newpackage();

private:
    Ui::newpackage *ui;
};

#endif // NEWPACKAGE_H
