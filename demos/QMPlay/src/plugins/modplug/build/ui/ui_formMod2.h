/********************************************************************************
** Form generated from reading UI file 'formMod2.ui'
**
** Created: Tue Aug 21 20:17:56 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMOD2_H
#define UI_FORMMOD2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMS
{
public:
    QGridLayout *gridLayout;
    QListWidget *patW;

    void setupUi(QWidget *FormMS)
    {
        if (FormMS->objectName().isEmpty())
            FormMS->setObjectName(QString::fromUtf8("FormMS"));
        FormMS->resize(331, 128);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormMS->setWindowIcon(icon);
        FormMS->setAutoFillBackground(true);
        gridLayout = new QGridLayout(FormMS);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        patW = new QListWidget(FormMS);
        patW->setObjectName(QString::fromUtf8("patW"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        patW->setFont(font);
        patW->setFocusPolicy(Qt::ClickFocus);
        patW->setContextMenuPolicy(Qt::NoContextMenu);
        patW->setFrameShape(QFrame::NoFrame);
        patW->setFrameShadow(QFrame::Plain);
        patW->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        patW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        patW->setProperty("showDropIndicator", QVariant(false));

        gridLayout->addWidget(patW, 0, 0, 1, 1);


        retranslateUi(FormMS);

        QMetaObject::connectSlotsByName(FormMS);
    } // setupUi

    void retranslateUi(QWidget *FormMS)
    {
        FormMS->setWindowTitle(QApplication::translate("FormMS", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormMS: public Ui_FormMS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMOD2_H
