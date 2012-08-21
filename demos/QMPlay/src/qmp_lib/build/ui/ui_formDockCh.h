/********************************************************************************
** Form generated from reading UI file 'formDockCh.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDOCKCH_H
#define UI_FORMDOCKCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui__FormDock
{
public:
    QGridLayout *gridLayout;
    QPushButton *okB;
    QListWidget *dockList;

    void setupUi(QWidget *_FormDock)
    {
        if (_FormDock->objectName().isEmpty())
            _FormDock->setObjectName(QString::fromUtf8("_FormDock"));
        _FormDock->resize(450, 400);
        gridLayout = new QGridLayout(_FormDock);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        okB = new QPushButton(_FormDock);
        okB->setObjectName(QString::fromUtf8("okB"));

        gridLayout->addWidget(okB, 1, 0, 1, 1);

        dockList = new QListWidget(_FormDock);
        dockList->setObjectName(QString::fromUtf8("dockList"));
        dockList->setIconSize(QSize(96, 96));
        dockList->setSpacing(2);

        gridLayout->addWidget(dockList, 0, 0, 1, 1);

        QWidget::setTabOrder(dockList, okB);

        retranslateUi(_FormDock);

        QMetaObject::connectSlotsByName(_FormDock);
    } // setupUi

    void retranslateUi(QWidget *_FormDock)
    {
        _FormDock->setWindowTitle(QApplication::translate("_FormDock", "Zadokuj", 0, QApplication::UnicodeUTF8));
        okB->setText(QApplication::translate("_FormDock", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class _FormDock: public Ui__FormDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDOCKCH_H
