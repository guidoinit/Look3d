#ifndef NEWANIMATION_H
#define NEWANIMATION_H

#include <QDialog>

namespace Ui {
    class NewAnimation;
}

class NewAnimation : public QDialog
{
    Q_OBJECT

public:
    explicit NewAnimation(QWidget *parent = 0);
    ~NewAnimation();

    std::string _name;
    int _type;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewAnimation *ui;

};

#endif // NEWANIMATION_H
