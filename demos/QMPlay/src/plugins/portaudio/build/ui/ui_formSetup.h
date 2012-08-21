/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:18:47 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QComboBox *devB;
    QLabel *label;
    QLabel *label_2;
    QComboBox *devNB;
    QPushButton *detectB;
    QPushButton *ApplyDB;
    QPushButton *defDevB;
    QCheckBox *zB;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *lB;
    QDoubleSpinBox *lNB;
    QCheckBox *autoSurroundB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(415, 350);
        Form3->setMinimumSize(QSize(415, 350));
        Form3->setMaximumSize(QSize(415, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(0, 0, 71, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(250, 320, 161, 27));
        devB = new QComboBox(Form3);
        devB->setObjectName(QString::fromUtf8("devB"));
        devB->setGeometry(QRect(10, 83, 401, 23));
        label = new QLabel(Form3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 63, 211, 18));
        label_2 = new QLabel(Form3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 113, 221, 18));
        devNB = new QComboBox(Form3);
        devNB->setObjectName(QString::fromUtf8("devNB"));
        devNB->setGeometry(QRect(10, 133, 401, 23));
        detectB = new QPushButton(Form3);
        detectB->setObjectName(QString::fromUtf8("detectB"));
        detectB->setGeometry(QRect(10, 30, 401, 27));
        ApplyDB = new QPushButton(Form3);
        ApplyDB->setObjectName(QString::fromUtf8("ApplyDB"));
        ApplyDB->setGeometry(QRect(10, 320, 231, 27));
        defDevB = new QPushButton(Form3);
        defDevB->setObjectName(QString::fromUtf8("defDevB"));
        defDevB->setGeometry(QRect(10, 160, 401, 27));
        zB = new QCheckBox(Form3);
        zB->setObjectName(QString::fromUtf8("zB"));
        zB->setGeometry(QRect(10, 250, 301, 22));
        label_3 = new QLabel(Form3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 190, 91, 18));
        label_4 = new QLabel(Form3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 190, 181, 18));
        lB = new QDoubleSpinBox(Form3);
        lB->setObjectName(QString::fromUtf8("lB"));
        lB->setGeometry(QRect(10, 210, 91, 31));
        lB->setDecimals(2);
        lB->setMinimum(0.01);
        lB->setMaximum(2);
        lB->setSingleStep(0.01);
        lB->setValue(0.1);
        lNB = new QDoubleSpinBox(Form3);
        lNB->setObjectName(QString::fromUtf8("lNB"));
        lNB->setGeometry(QRect(130, 210, 91, 31));
        lNB->setDecimals(2);
        lNB->setMinimum(0.01);
        lNB->setMaximum(2);
        lNB->setSingleStep(0.01);
        lNB->setValue(0.1);
        autoSurroundB = new QCheckBox(Form3);
        autoSurroundB->setObjectName(QString::fromUtf8("autoSurroundB"));
        autoSurroundB->setGeometry(QRect(10, 270, 391, 41));
        QWidget::setTabOrder(detectB, devB);
        QWidget::setTabOrder(devB, devNB);
        QWidget::setTabOrder(devNB, defDevB);
        QWidget::setTabOrder(defDevB, lB);
        QWidget::setTabOrder(lB, lNB);
        QWidget::setTabOrder(lNB, zB);
        QWidget::setTabOrder(zB, autoSurroundB);
        QWidget::setTabOrder(autoSurroundB, ApplyB);
        QWidget::setTabOrder(ApplyB, ApplyDB);
        QWidget::setTabOrder(ApplyDB, enabledB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form3", "Wybierz urz\304\205dzenie wyj\305\233ciowe:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form3", "Wybierz urz\304\205dzenie nagrywaj\304\205ce:", 0, QApplication::UnicodeUTF8));
        detectB->setText(QApplication::translate("Form3", "Wykyj urz\304\205dzenia", 0, QApplication::UnicodeUTF8));
        ApplyDB->setText(QApplication::translate("Form3", "Zastosuj wybrane urz\304\205dzenia", 0, QApplication::UnicodeUTF8));
        defDevB->setText(QApplication::translate("Form3", "Domy\305\233lne urz\304\205dzenia", 0, QApplication::UnicodeUTF8));
        zB->setText(QApplication::translate("Form3", "Zawsze u\305\274ywaj tych urz\304\205dze\305\204 je\305\274eli istniej\304\205", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form3", "Op\303\263\305\272nienie:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form3", "Op\303\263\305\272nienie dla nagrywania:", 0, QApplication::UnicodeUTF8));
        autoSurroundB->setText(QApplication::translate("Form3", "Automatycznie zmie\305\204 urz\304\205dzenie d\305\272wi\304\231kowe \"default\" na\n"
"\"surround\" podczas odtwarzania d\305\272wi\304\231ku wielokana\305\202owego", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
