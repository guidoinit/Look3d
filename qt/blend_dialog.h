#ifndef BLEND_DIALOG_H
#define BLEND_DIALOG_H

#include <QDialog>
#include "l3d_blend.h"

namespace Ui {
class blend_dialog;
}

class blend_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit blend_dialog(QWidget *parent = 0);
    ~blend_dialog();

    l3d::mesh::blendFunction _sfactor,_dfactor;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::blend_dialog *ui;
};

#endif // BLEND_DIALOG_H
