#include "newproject.h"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    ui->setupUi(this);
}

NewProject::~NewProject()
{
    delete ui;
}
