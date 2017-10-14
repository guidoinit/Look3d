#ifndef LIGHTOPTIONS_H
#define LIGHTOPTIONS_H
#include <QOpenGLFunctions>

#include <QDialog>
#include "scene/elements/l3d_light.h"

using namespace l3d::light;

namespace Ui {
    class lightoptions;
}

class lightoptions : public QDialog
{
    Q_OBJECT

public:
    explicit lightoptions(QWidget *parent = 0);
    ~lightoptions();
    void setlight(pl3d_light);

private slots:
    void on_hsambientR_valueChanged(int value);

    void on_hsambientG_valueChanged(int value);

    void on_hsambientB_valueChanged(int value);

    void on_hsambientA_valueChanged(int value);

    void on_hsdiffuseR_valueChanged(int value);

    void on_hsdiffuseG_valueChanged(int value);

    void on_hsdiffuseB_valueChanged(int value);

    void on_hsdiffuseA_valueChanged(int value);

    void on_hsspecularR_valueChanged(int value);

    void on_hsspecularG_valueChanged(int value);

    void on_hsspecularB_valueChanged(int value);

    void on_hsspecularA_valueChanged(int value);

private:
    Ui::lightoptions *ui;

    pl3d_light m_light;

};

#endif // LIGHTOPTIONS_H
