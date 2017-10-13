#include "newpackage.h"
#include "ui_newpackage.h"

newpackage::newpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newpackage)
{
    ui->setupUi(this);
}

newpackage::~newpackage()
{
    delete ui;
}
