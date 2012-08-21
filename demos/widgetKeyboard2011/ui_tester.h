/********************************************************************************
** Form generated from reading UI file 'tester.ui'
**
** Created: Tue Aug 21 21:23:16 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTER_H
#define UI_TESTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tester
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Tester)
    {
        if (Tester->objectName().isEmpty())
            Tester->setObjectName(QString::fromUtf8("Tester"));
        Tester->resize(324, 296);
        gridLayout_2 = new QGridLayout(Tester);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(Tester);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(Tester);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(Tester);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);


        verticalLayout->addLayout(verticalLayout_2);

        lineEdit = new QLineEdit(Tester);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(Tester);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Tester);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Tester);

        QMetaObject::connectSlotsByName(Tester);
    } // setupUi

    void retranslateUi(QWidget *Tester)
    {
        Tester->setWindowTitle(QApplication::translate("Tester", "QLineEdit virtual keyboard Example", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Tester", "Open virtual keyboard!", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Tester", "Hide virtual keyboard!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tester: public Ui_Tester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTER_H
