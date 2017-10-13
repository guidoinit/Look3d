#include "loadpackage.h"
#include "ui_loadpackage.h"

loadpackage::loadpackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadpackage)
{
    ui->setupUi(this);
}

loadpackage::~loadpackage()
{
    delete ui;
}
