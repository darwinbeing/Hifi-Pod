/********************************************************************************
** Form generated from reading UI file 'formCp.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCP_H
#define UI_FORMCP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormC
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *fL;
    QProgressBar *pB;
    QPushButton *brB;

    void setupUi(QWidget *FormC)
    {
        if (FormC->objectName().isEmpty())
            FormC->setObjectName(QString::fromUtf8("FormC"));
        FormC->resize(293, 105);
        FormC->setMinimumSize(QSize(245, 75));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormC->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FormC);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        fL = new QLabel(FormC);
        fL->setObjectName(QString::fromUtf8("fL"));

        verticalLayout->addWidget(fL);

        pB = new QProgressBar(FormC);
        pB->setObjectName(QString::fromUtf8("pB"));
        pB->setValue(0);

        verticalLayout->addWidget(pB);

        brB = new QPushButton(FormC);
        brB->setObjectName(QString::fromUtf8("brB"));

        verticalLayout->addWidget(brB);


        retranslateUi(FormC);

        QMetaObject::connectSlotsByName(FormC);
    } // setupUi

    void retranslateUi(QWidget *FormC)
    {
        FormC->setWindowTitle(QApplication::translate("FormC", "Kopiowanie", 0, QApplication::UnicodeUTF8));
        fL->setText(QApplication::translate("FormC", "File name", 0, QApplication::UnicodeUTF8));
        brB->setText(QApplication::translate("FormC", "Przerwij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormC: public Ui_FormC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCP_H
