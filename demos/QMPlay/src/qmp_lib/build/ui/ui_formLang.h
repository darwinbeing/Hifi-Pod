/********************************************************************************
** Form generated from reading UI file 'formLang.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLANG_H
#define UI_FORMLANG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormL
{
public:
    QGridLayout *gridLayout;
    QComboBox *langCB;
    QPushButton *OKB;

    void setupUi(QWidget *FormL)
    {
        if (FormL->objectName().isEmpty())
            FormL->setObjectName(QString::fromUtf8("FormL"));
        FormL->resize(245, 77);
        FormL->setMinimumSize(QSize(245, 75));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormL->setWindowIcon(icon);
        gridLayout = new QGridLayout(FormL);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        langCB = new QComboBox(FormL);
        langCB->setObjectName(QString::fromUtf8("langCB"));

        gridLayout->addWidget(langCB, 0, 0, 1, 1);

        OKB = new QPushButton(FormL);
        OKB->setObjectName(QString::fromUtf8("OKB"));

        gridLayout->addWidget(OKB, 1, 0, 1, 1);


        retranslateUi(FormL);

        QMetaObject::connectSlotsByName(FormL);
    } // setupUi

    void retranslateUi(QWidget *FormL)
    {
        FormL->setWindowTitle(QApplication::translate("FormL", "Wybierz j\304\231zyk", 0, QApplication::UnicodeUTF8));
        OKB->setText(QApplication::translate("FormL", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormL: public Ui_FormL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLANG_H
