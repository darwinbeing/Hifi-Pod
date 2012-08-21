/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:28:03 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETUP_H
#define UI_FORMSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QLineEdit *extsB;
    QGroupBox *groupBox;
    QRadioButton *u8B;
    QRadioButton *s8B;
    QRadioButton *i16B;
    QRadioButton *i24B;
    QRadioButton *i32B;
    QRadioButton *f32B;
    QGroupBox *groupBox_2;
    QSpinBox *srateB;
    QGroupBox *groupBox_4;
    QRadioButton *beB;
    QRadioButton *leB;
    QGroupBox *groupBox_5;
    QSpinBox *chnB;
    QGroupBox *groupBox_6;
    QSpinBox *skipB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(436, 278);
        Form3->setMinimumSize(QSize(436, 278));
        Form3->setMaximumSize(QSize(436, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 131, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(210, 250, 221, 25));
        extsB = new QLineEdit(Form3);
        extsB->setObjectName(QString::fromUtf8("extsB"));
        extsB->setGeometry(QRect(20, 40, 411, 25));
        groupBox = new QGroupBox(Form3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 181, 201));
        u8B = new QRadioButton(groupBox);
        u8B->setObjectName(QString::fromUtf8("u8B"));
        u8B->setGeometry(QRect(10, 20, 161, 25));
        s8B = new QRadioButton(groupBox);
        s8B->setObjectName(QString::fromUtf8("s8B"));
        s8B->setGeometry(QRect(10, 50, 161, 25));
        i16B = new QRadioButton(groupBox);
        i16B->setObjectName(QString::fromUtf8("i16B"));
        i16B->setGeometry(QRect(10, 80, 161, 25));
        i24B = new QRadioButton(groupBox);
        i24B->setObjectName(QString::fromUtf8("i24B"));
        i24B->setGeometry(QRect(10, 110, 161, 25));
        i32B = new QRadioButton(groupBox);
        i32B->setObjectName(QString::fromUtf8("i32B"));
        i32B->setGeometry(QRect(10, 140, 161, 25));
        f32B = new QRadioButton(groupBox);
        f32B->setObjectName(QString::fromUtf8("f32B"));
        f32B->setGeometry(QRect(10, 170, 161, 25));
        groupBox_2 = new QGroupBox(Form3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 160, 111, 71));
        srateB = new QSpinBox(groupBox_2);
        srateB->setObjectName(QString::fromUtf8("srateB"));
        srateB->setGeometry(QRect(10, 30, 91, 25));
        srateB->setMinimum(4000);
        srateB->setMaximum(384000);
        srateB->setValue(4000);
        groupBox_4 = new QGroupBox(Form3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(200, 70, 141, 91));
        beB = new QRadioButton(groupBox_4);
        beB->setObjectName(QString::fromUtf8("beB"));
        beB->setGeometry(QRect(10, 30, 121, 25));
        leB = new QRadioButton(groupBox_4);
        leB->setObjectName(QString::fromUtf8("leB"));
        leB->setGeometry(QRect(10, 60, 121, 25));
        groupBox_5 = new QGroupBox(Form3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(340, 70, 81, 51));
        chnB = new QSpinBox(groupBox_5);
        chnB->setObjectName(QString::fromUtf8("chnB"));
        chnB->setGeometry(QRect(10, 20, 61, 25));
        chnB->setMinimum(1);
        chnB->setMaximum(16);
        groupBox_6 = new QGroupBox(Form3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(330, 170, 101, 51));
        skipB = new QSpinBox(groupBox_6);
        skipB->setObjectName(QString::fromUtf8("skipB"));
        skipB->setGeometry(QRect(10, 20, 81, 25));
        skipB->setMinimum(0);
        skipB->setMaximum(65536);
        QWidget::setTabOrder(enabledB, extsB);
        QWidget::setTabOrder(extsB, u8B);
        QWidget::setTabOrder(u8B, s8B);
        QWidget::setTabOrder(s8B, i16B);
        QWidget::setTabOrder(i16B, i24B);
        QWidget::setTabOrder(i24B, i32B);
        QWidget::setTabOrder(i32B, f32B);
        QWidget::setTabOrder(f32B, beB);
        QWidget::setTabOrder(beB, leB);
        QWidget::setTabOrder(leB, chnB);
        QWidget::setTabOrder(chnB, srateB);
        QWidget::setTabOrder(srateB, skipB);
        QWidget::setTabOrder(skipB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form3", "Ilo\305\233c bit\303\263w na pr\303\263bk\304\231", 0, QApplication::UnicodeUTF8));
        u8B->setText(QApplication::translate("Form3", "8bit unsigned char", 0, QApplication::UnicodeUTF8));
        s8B->setText(QApplication::translate("Form3", "8bit signed char", 0, QApplication::UnicodeUTF8));
        i16B->setText(QApplication::translate("Form3", "16bit integer", 0, QApplication::UnicodeUTF8));
        i24B->setText(QApplication::translate("Form3", "24bit integer", 0, QApplication::UnicodeUTF8));
        i32B->setText(QApplication::translate("Form3", "32bit integer", 0, QApplication::UnicodeUTF8));
        f32B->setText(QApplication::translate("Form3", "32bit float", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Form3", "Pr\303\263bkowanie", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Form3", "Format odczytu", 0, QApplication::UnicodeUTF8));
        beB->setText(QApplication::translate("Form3", "Big endian", 0, QApplication::UnicodeUTF8));
        leB->setText(QApplication::translate("Form3", "Little endian", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Form3", "Kana\305\202y", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("Form3", "Pomi\305\204 bajty", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
