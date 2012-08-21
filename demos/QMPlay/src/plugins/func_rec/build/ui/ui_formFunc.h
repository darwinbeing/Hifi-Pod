/********************************************************************************
** Form generated from reading UI file 'formFunc.ui'
**
** Created: Tue Aug 21 19:58:37 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFUNC_H
#define UI_FORMFUNC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_1
{
public:
    QLineEdit *fnameE;
    QLabel *label;
    QPushButton *recB;
    QPushButton *stopB;
    QLabel *label_3;
    QSpinBox *rateB;
    QLabel *label_4;
    QSpinBox *bitsB;
    QLabel *label_5;
    QSpinBox *chnB;
    QLabel *txtL;
    QCheckBox *savB;
    QPushButton *pauseB;
    QCheckBox *sndB;

    void setupUi(QWidget *Form_1)
    {
        if (Form_1->objectName().isEmpty())
            Form_1->setObjectName(QString::fromUtf8("Form_1"));
        Form_1->resize(395, 230);
        Form_1->setMinimumSize(QSize(395, 230));
        Form_1->setMaximumSize(QSize(395, 230));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form_1->setWindowIcon(icon);
        fnameE = new QLineEdit(Form_1);
        fnameE->setObjectName(QString::fromUtf8("fnameE"));
        fnameE->setGeometry(QRect(10, 70, 381, 31));
        label = new QLabel(Form_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 151, 18));
        recB = new QPushButton(Form_1);
        recB->setObjectName(QString::fromUtf8("recB"));
        recB->setGeometry(QRect(10, 190, 181, 31));
        recB->setIconSize(QSize(24, 24));
        stopB = new QPushButton(Form_1);
        stopB->setObjectName(QString::fromUtf8("stopB"));
        stopB->setGeometry(QRect(290, 190, 101, 31));
        stopB->setIconSize(QSize(24, 24));
        label_3 = new QLabel(Form_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 91, 18));
        rateB = new QSpinBox(Form_1);
        rateB->setObjectName(QString::fromUtf8("rateB"));
        rateB->setGeometry(QRect(10, 150, 91, 31));
        rateB->setMinimum(4000);
        rateB->setMaximum(48000);
        label_4 = new QLabel(Form_1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 130, 81, 18));
        bitsB = new QSpinBox(Form_1);
        bitsB->setObjectName(QString::fromUtf8("bitsB"));
        bitsB->setGeometry(QRect(160, 150, 71, 31));
        bitsB->setMinimum(8);
        bitsB->setMaximum(32);
        label_5 = new QLabel(Form_1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 130, 101, 18));
        chnB = new QSpinBox(Form_1);
        chnB->setObjectName(QString::fromUtf8("chnB"));
        chnB->setGeometry(QRect(280, 150, 81, 31));
        chnB->setMinimum(1);
        chnB->setMaximum(2);
        txtL = new QLabel(Form_1);
        txtL->setObjectName(QString::fromUtf8("txtL"));
        txtL->setGeometry(QRect(10, 10, 371, 18));
        savB = new QCheckBox(Form_1);
        savB->setObjectName(QString::fromUtf8("savB"));
        savB->setGeometry(QRect(10, 30, 121, 22));
        pauseB = new QPushButton(Form_1);
        pauseB->setObjectName(QString::fromUtf8("pauseB"));
        pauseB->setGeometry(QRect(200, 190, 81, 31));
        pauseB->setIconSize(QSize(24, 24));
        sndB = new QCheckBox(Form_1);
        sndB->setObjectName(QString::fromUtf8("sndB"));
        sndB->setGeometry(QRect(10, 110, 151, 22));
        QWidget::setTabOrder(savB, fnameE);
        QWidget::setTabOrder(fnameE, sndB);
        QWidget::setTabOrder(sndB, rateB);
        QWidget::setTabOrder(rateB, bitsB);
        QWidget::setTabOrder(bitsB, chnB);
        QWidget::setTabOrder(chnB, recB);
        QWidget::setTabOrder(recB, pauseB);
        QWidget::setTabOrder(pauseB, stopB);

        retranslateUi(Form_1);

        QMetaObject::connectSlotsByName(Form_1);
    } // setupUi

    void retranslateUi(QWidget *Form_1)
    {
        Form_1->setWindowTitle(QApplication::translate("Form_1", "Nagrywanie", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_1", "Podaj nazw\304\231 pliku:", 0, QApplication::UnicodeUTF8));
        recB->setText(QApplication::translate("Form_1", "Nagrywaj", 0, QApplication::UnicodeUTF8));
        recB->setShortcut(QApplication::translate("Form_1", "X", 0, QApplication::UnicodeUTF8));
        stopB->setText(QApplication::translate("Form_1", "Stop", 0, QApplication::UnicodeUTF8));
        stopB->setShortcut(QApplication::translate("Form_1", "V", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form_1", "Samplerate:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form_1", "Ilo\305\233\304\207 bit\303\263w:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form_1", "Ilo\305\233\304\207 kana\305\202\303\263w:", 0, QApplication::UnicodeUTF8));
        txtL->setText(QApplication::translate("Form_1", "TextLabel", 0, QApplication::UnicodeUTF8));
        savB->setText(QApplication::translate("Form_1", "Zapis do pliku", 0, QApplication::UnicodeUTF8));
        pauseB->setText(QApplication::translate("Form_1", "Pauza", 0, QApplication::UnicodeUTF8));
        pauseB->setShortcut(QApplication::translate("Form_1", "C", 0, QApplication::UnicodeUTF8));
        sndB->setText(QApplication::translate("Form_1", "Odtwarzaj d\305\272wi\304\231k", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_1: public Ui_Form_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFUNC_H
