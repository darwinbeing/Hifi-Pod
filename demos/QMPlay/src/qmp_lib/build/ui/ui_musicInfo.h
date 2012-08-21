/********************************************************************************
** Form generated from reading UI file 'musicInfo.ui'
**
** Created: Tue Aug 21 08:05:43 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICINFO_H
#define UI_MUSICINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_MusicInfo
{
public:
    QGridLayout *gridLayout;
    QLabel *pixmap;
    QFrame *line;
    QLabel *label;
    QLabel *plugName;
    QSpacerItem *verticalSpacer;
    QProgressBar *musP;

    void setupUi(QFrame *MusicInfo)
    {
        if (MusicInfo->objectName().isEmpty())
            MusicInfo->setObjectName(QString::fromUtf8("MusicInfo"));
        MusicInfo->resize(188, 116);
        MusicInfo->setFrameShape(QFrame::StyledPanel);
        MusicInfo->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(MusicInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pixmap = new QLabel(MusicInfo);
        pixmap->setObjectName(QString::fromUtf8("pixmap"));
        pixmap->setMinimumSize(QSize(68, 68));
        pixmap->setMaximumSize(QSize(68, 68));
        pixmap->setFrameShape(QFrame::StyledPanel);
        pixmap->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(pixmap, 0, 0, 1, 1);

        line = new QFrame(MusicInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 3, 1);

        label = new QLabel(MusicInfo);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        plugName = new QLabel(MusicInfo);
        plugName->setObjectName(QString::fromUtf8("plugName"));

        gridLayout->addWidget(plugName, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        musP = new QProgressBar(MusicInfo);
        musP->setObjectName(QString::fromUtf8("musP"));
        musP->setValue(0);

        gridLayout->addWidget(musP, 1, 2, 1, 1);


        retranslateUi(MusicInfo);

        QMetaObject::connectSlotsByName(MusicInfo);
    } // setupUi

    void retranslateUi(QFrame *MusicInfo)
    {
        MusicInfo->setWindowTitle(QApplication::translate("MusicInfo", "MusicInfo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MusicInfo", "t", 0, QApplication::UnicodeUTF8));
        plugName->setText(QApplication::translate("MusicInfo", "pN", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MusicInfo: public Ui_MusicInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICINFO_H
