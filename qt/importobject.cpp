#include "importobject.h"
#include "ui_importobject.h"
#include <QFileDialog>
#include <QMessageBox>
importobject::importobject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importobject)
{
    ui->setupUi(this);
    _fsel=-1;
    _filename="";
}

importobject::~importobject()
{
    delete ui;
}

void importobject::on_listWidget_clicked(const QModelIndex &index)
{
    int fsel=(int)index.row();

    switch(fsel)
    {
        case 0:

        break;
    }

    _fsel=fsel;
}

void importobject::on_pushButton_clicked()
{
    _to=(TypeObjectImport)_fsel;

    if(_fsel ==-1)
    {
        //
    }
    else
    {
          //
        switch(_to)
        {
        case md2_model://md2 files


            _filename=QFileDialog::getOpenFileName(0,
            tr("Load md2 model"),"",tr("Md2 model files (*.md2)")).toStdString();
            break;
        case md2_player:
            _filename=QFileDialog::getExistingDirectory(0,
            tr("Load md2 player"),"",QFileDialog::ShowDirsOnly).toStdString();

            break;
        case m3ds_file:
            _filename=QFileDialog::getOpenFileName(0,
            tr("Load 3ds file"),"",tr("3DS files (*.3ds)")).toStdString();
            break;
        }
    }

}

void importobject::on_pb_ok_clicked()
{
    if(_fsel==-1 || _filename.empty())
    {
        //to-do
        QMessageBox msg;
        msg.setText(QString("Look3D: Error..."));
        msg.setInformativeText("You are not selected an object...");
        msg.setWindowModified(Qt::ApplicationModal);
        msg.setStandardButtons(QMessageBox::Ok );
        //msg.set(,QString("You are not selected the model and the file.."),QIcon(),1,1,1)

        msg.exec();


    }
    _to=(TypeObjectImport)_fsel;

    hide();
}

void importobject::on_pb_exit_clicked()
{
    hide();
}

void importobject::getobject(int * _i,std::string * str)
{
    *_i=_fsel;
    *str=_filename;
}
