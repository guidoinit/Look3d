#include <QMessageBox>
#include "newanimation.h"
#include "ui_newanimation.h"

NewAnimation::NewAnimation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAnimation)
{
    ui->setupUi(this);
}

NewAnimation::~NewAnimation()
{
    delete ui;
}

void NewAnimation::on_buttonBox_accepted()
{
    QMessageBox mb;
    mb.setWindowTitle(QString("Look3D=> Error..."));
    mb.setText(QString("Insert a valid name ...   "));
    mb.setDefaultButton(QMessageBox::Ok);
    if(ui->lineEdit->text()=="<noname>")
        mb.exec();
    else
        _name=ui->lineEdit->text().toStdString();
    _type=ui->cb_type->currentIndex();


}
