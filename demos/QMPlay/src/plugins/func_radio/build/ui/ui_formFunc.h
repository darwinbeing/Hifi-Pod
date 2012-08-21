/********************************************************************************
** Form generated from reading UI file 'formFunc.ui'
**
** Created: Tue Aug 21 19:58:31 2012
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
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFunc
{
public:
    QGridLayout *gridLayout;
    QPushButton *createList;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progress;
    QLabel *infoL;
    QListWidget *lista;

    void setupUi(QWidget *FormFunc)
    {
        if (FormFunc->objectName().isEmpty())
            FormFunc->setObjectName(QString::fromUtf8("FormFunc"));
        FormFunc->resize(537, 375);
        gridLayout = new QGridLayout(FormFunc);
        gridLayout->setSpacing(-1);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        createList = new QPushButton(FormFunc);
        createList->setObjectName(QString::fromUtf8("createList"));

        gridLayout->addWidget(createList, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        progress = new QProgressBar(FormFunc);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setMaximum(0);
        progress->setValue(69090);

        gridLayout->addWidget(progress, 5, 0, 1, 2);

        infoL = new QLabel(FormFunc);
        infoL->setObjectName(QString::fromUtf8("infoL"));

        gridLayout->addWidget(infoL, 4, 0, 1, 2);

        lista = new QListWidget(FormFunc);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setIconSize(QSize(32, 32));
        lista->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        lista->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        lista->setMovement(QListView::Static);
        lista->setProperty("isWrapping", QVariant(true));
        lista->setResizeMode(QListView::Adjust);

        gridLayout->addWidget(lista, 1, 0, 1, 2);


        retranslateUi(FormFunc);

        QMetaObject::connectSlotsByName(FormFunc);
    } // setupUi

    void retranslateUi(QWidget *FormFunc)
    {
        FormFunc->setWindowTitle(QApplication::translate("FormFunc", "Radio", 0, QApplication::UnicodeUTF8));
        createList->setText(QApplication::translate("FormFunc", "Dodaj wszystkie do listy", 0, QApplication::UnicodeUTF8));
        infoL->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormFunc: public Ui_FormFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFUNC_H
