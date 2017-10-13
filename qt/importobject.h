#ifndef IMPORTOBJECT_H
#define IMPORTOBJECT_H

#include <QDialog>
#include <QModelIndex>
#include <string>

namespace Ui {
    class importobject;
}
enum TypeObjectImport
{
    md2_model=0,
    md2_player=1,
    m3ds_file=2,

    null_model

};

class importobject : public QDialog
{
    Q_OBJECT

public:
    explicit importobject(QWidget *parent = 0);
    ~importobject();

    void getobject(int *,std::string *);
private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pb_ok_clicked();

    void on_pb_exit_clicked();

private:
    Ui::importobject *ui;

    int _fsel;

    TypeObjectImport _to;
    std::string _filename;

};

#endif // IMPORTOBJECT_H
