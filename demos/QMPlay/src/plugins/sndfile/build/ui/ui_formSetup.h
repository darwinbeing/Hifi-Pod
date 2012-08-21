/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:28:08 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QLineEdit *extsB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(194, 110);
        Form3->setMinimumSize(QSize(194, 110));
        Form3->setMaximumSize(QSize(194, 110));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 131, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(20, 70, 161, 31));
        extsB = new QLineEdit(Form3);
        extsB->setObjectName(QString::fromUtf8("extsB"));
        extsB->setGeometry(QRect(20, 40, 161, 25));
        QWidget::setTabOrder(enabledB, extsB);
        QWidget::setTabOrder(extsB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
