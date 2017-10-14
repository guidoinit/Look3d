

#include "lightoptions.h"
#include "ui_lightoptions.h"

lightoptions::lightoptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lightoptions)
{
    ui->setupUi(this);
    m_light=NULL;
}

lightoptions::~lightoptions()
{
    delete ui;
}
void lightoptions::setlight(pl3d_light value)
{
    m_light=value;

}

void lightoptions::on_hsambientR_valueChanged(int value)
{
    m_light->ambient[0]=(float)value/100.0F;
}

void lightoptions::on_hsambientG_valueChanged(int value)
{
    m_light->ambient[1]=(float)value/100.0F;
}

void lightoptions::on_hsambientB_valueChanged(int value)
{
    m_light->ambient[2]=(float)value/100.0F;
}

void lightoptions::on_hsambientA_valueChanged(int value)
{
    m_light->ambient[3]=(float)value/100.0F;
}

void lightoptions::on_hsdiffuseR_valueChanged(int value)
{
    m_light->diffuse[0]=(float)value/100.0F;
}


void lightoptions::on_hsdiffuseG_valueChanged(int value)
{
    m_light->diffuse[1]=(float)value/100.0F;
}

void lightoptions::on_hsdiffuseB_valueChanged(int value)
{
    m_light->diffuse[2]=(float)value/100.0F;
}

void lightoptions::on_hsdiffuseA_valueChanged(int value)
{
    m_light->diffuse[3]=(float)value/100.0F;
}

void lightoptions::on_hsspecularR_valueChanged(int value)
{
    m_light->specular[0]=(float)value/100.0F;
}

void lightoptions::on_hsspecularG_valueChanged(int value)
{
    m_light->specular[1]=(float)value/100.0F;
}

void lightoptions::on_hsspecularB_valueChanged(int value)
{
    m_light->specular[2]=(float)value/100.0F;
}

void lightoptions::on_hsspecularA_valueChanged(int value)
{
    m_light->specular[3]=(float)value/100.0F;
}
