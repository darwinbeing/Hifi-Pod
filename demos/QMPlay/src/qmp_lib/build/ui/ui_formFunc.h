/********************************************************************************
** Form generated from reading UI file 'formFunc.ui'
**
** Created: Tue Aug 21 08:05:42 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FFunc
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *null;
    QPushButton *closeB;

    void setupUi(QWidget *FFunc)
    {
        if (FFunc->objectName().isEmpty())
            FFunc->setObjectName(QString::fromUtf8("FFunc"));
        FFunc->resize(600, 400);
        FFunc->setMinimumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FFunc->setWindowIcon(icon);
        gridLayout = new QGridLayout(FFunc);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(FFunc);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        null = new QWidget();
        null->setObjectName(QString::fromUtf8("null"));
        tabWidget->addTab(null, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

        closeB = new QPushButton(FFunc);
        closeB->setObjectName(QString::fromUtf8("closeB"));
        closeB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(closeB, 1, 0, 1, 2);


        retranslateUi(FFunc);

        QMetaObject::connectSlotsByName(FFunc);
    } // setupUi

    void retranslateUi(QWidget *FFunc)
    {
        FFunc->setWindowTitle(QApplication::translate("FFunc", "Funkcje", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(null), QApplication::translate("FFunc", "null", 0, QApplication::UnicodeUTF8));
        closeB->setText(QApplication::translate("FFunc", "Zamknij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FFunc: public Ui_FFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFUNC_H
