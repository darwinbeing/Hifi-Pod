/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 19:58:11 2012
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QRadioButton *autoFactorB;
    QRadioButton *manualFactorB;
    QDoubleSpinBox *factorB;
    QCheckBox *hqB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(300, 147);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 141, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(10, 120, 281, 21));
        autoFactorB = new QRadioButton(Form3);
        autoFactorB->setObjectName(QString::fromUtf8("autoFactorB"));
        autoFactorB->setGeometry(QRect(20, 30, 251, 23));
        manualFactorB = new QRadioButton(Form3);
        manualFactorB->setObjectName(QString::fromUtf8("manualFactorB"));
        manualFactorB->setGeometry(QRect(20, 50, 251, 23));
        factorB = new QDoubleSpinBox(Form3);
        factorB->setObjectName(QString::fromUtf8("factorB"));
        factorB->setGeometry(QRect(30, 70, 71, 25));
        factorB->setDecimals(2);
        factorB->setMinimum(0.1);
        factorB->setMaximum(10);
        factorB->setSingleStep(0.01);
        factorB->setValue(1);
        hqB = new QCheckBox(Form3);
        hqB->setObjectName(QString::fromUtf8("hqB"));
        hqB->setGeometry(QRect(20, 100, 161, 21));
        hqB->setCursor(QCursor(Qt::PointingHandCursor));
        QWidget::setTabOrder(enabledB, autoFactorB);
        QWidget::setTabOrder(autoFactorB, manualFactorB);
        QWidget::setTabOrder(manualFactorB, factorB);
        QWidget::setTabOrder(factorB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        autoFactorB->setText(QApplication::translate("Form3", "Automatycznie dobierz wsp\303\263\305\202czynnik", 0, QApplication::UnicodeUTF8));
        manualFactorB->setText(QApplication::translate("Form3", "Wybierz wsp\303\263\305\202czynnik r\304\231cznie", 0, QApplication::UnicodeUTF8));
        hqB->setText(QApplication::translate("Form3", "Wysoka jako\305\233\304\207 (HQ)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
