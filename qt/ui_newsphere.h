/********************************************************************************
** Form generated from reading UI file 'newsphere.ui'
**
** Created: Wed Oct 19 14:35:19 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSPHERE_H
#define UI_NEWSPHERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newSphere
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBoxU;
    QSpinBox *spinBoxV;
    QSpinBox *spinBoxRadius;
    QCheckBox *checkBoxPreview;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayoutogl;

    void setupUi(QDialog *newSphere)
    {
        if (newSphere->objectName().isEmpty())
            newSphere->setObjectName(QString::fromUtf8("newSphere"));
        newSphere->resize(320, 240);
        buttonBox = new QDialogButtonBox(newSphere);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(newSphere);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 21, 17));
        label_2 = new QLabel(newSphere);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 21, 17));
        label_3 = new QLabel(newSphere);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 41, 17));
        spinBoxU = new QSpinBox(newSphere);
        spinBoxU->setObjectName(QString::fromUtf8("spinBoxU"));
        spinBoxU->setGeometry(QRect(70, 40, 43, 27));
        spinBoxU->setFrame(false);
        spinBoxU->setAccelerated(true);
        spinBoxU->setMaximum(1000);
        spinBoxU->setValue(32);
        spinBoxV = new QSpinBox(newSphere);
        spinBoxV->setObjectName(QString::fromUtf8("spinBoxV"));
        spinBoxV->setGeometry(QRect(70, 70, 43, 27));
        spinBoxV->setFrame(false);
        spinBoxV->setAccelerated(true);
        spinBoxV->setMaximum(1000);
        spinBoxV->setValue(32);
        spinBoxRadius = new QSpinBox(newSphere);
        spinBoxRadius->setObjectName(QString::fromUtf8("spinBoxRadius"));
        spinBoxRadius->setGeometry(QRect(70, 100, 43, 27));
        spinBoxRadius->setFrame(false);
        spinBoxRadius->setAccelerated(true);
        spinBoxRadius->setMaximum(200);
        spinBoxRadius->setSingleStep(2);
        spinBoxRadius->setValue(10);
        checkBoxPreview = new QCheckBox(newSphere);
        checkBoxPreview->setObjectName(QString::fromUtf8("checkBoxPreview"));
        checkBoxPreview->setGeometry(QRect(10, 150, 91, 22));
        verticalLayoutWidget = new QWidget(newSphere);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 40, 160, 121));
        vLayoutogl = new QVBoxLayout(verticalLayoutWidget);
        vLayoutogl->setObjectName(QString::fromUtf8("vLayoutogl"));
        vLayoutogl->setContentsMargins(0, 0, 0, 0);

        retranslateUi(newSphere);
        QObject::connect(buttonBox, SIGNAL(accepted()), newSphere, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newSphere, SLOT(reject()));

        QMetaObject::connectSlotsByName(newSphere);
    } // setupUi

    void retranslateUi(QDialog *newSphere)
    {
        newSphere->setWindowTitle(QApplication::translate("newSphere", "New UV sphere", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newSphere", "U", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("newSphere", "V", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("newSphere", "radius", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBoxU->setToolTip(QApplication::translate("newSphere", "insert U coordinate\n"
"", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBoxV->setToolTip(QApplication::translate("newSphere", "insert V coordiante", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBoxRadius->setToolTip(QApplication::translate("newSphere", "insert radius", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBoxPreview->setToolTip(QApplication::translate("newSphere", "sphere preview", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        checkBoxPreview->setText(QApplication::translate("newSphere", "preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newSphere: public Ui_newSphere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSPHERE_H
