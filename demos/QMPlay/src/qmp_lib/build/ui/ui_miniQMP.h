/********************************************************************************
** Form generated from reading UI file 'miniQMP.ui'
**
** Created: Tue Aug 21 08:05:43 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIQMP_H
#define UI_MINIQMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_miniQMP
{
public:
    QGridLayout *gridLayout_2;
    QSlider *volS;
    QWidget *mPS;
    QLabel *timeL;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QLabel *okienko;
    QFrame *titleB;
    QGridLayout *gridLayout;
    QLabel *titleL;
    QPushButton *closeB;
    QPushButton *plistB;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *playB;
    QPushButton *stopB;
    QPushButton *prevB;
    QPushButton *nextB;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pauseB;

    void setupUi(QFrame *miniQMP)
    {
        if (miniQMP->objectName().isEmpty())
            miniQMP->setObjectName(QString::fromUtf8("miniQMP"));
        miniQMP->resize(253, 98);
        miniQMP->setMouseTracking(true);
        miniQMP->setFrameShape(QFrame::StyledPanel);
        miniQMP->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(miniQMP);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        volS = new QSlider(miniQMP);
        volS->setObjectName(QString::fromUtf8("volS"));
        volS->setCursor(QCursor(Qt::PointingHandCursor));
        volS->setMaximum(100);
        volS->setValue(100);
        volS->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(volS, 2, 4, 3, 1);

        mPS = new QWidget(miniQMP);
        mPS->setObjectName(QString::fromUtf8("mPS"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mPS->sizePolicy().hasHeightForWidth());
        mPS->setSizePolicy(sizePolicy);
        mPS->setMinimumSize(QSize(144, 20));

        gridLayout_2->addWidget(mPS, 3, 1, 1, 3);

        timeL = new QLabel(miniQMP);
        timeL->setObjectName(QString::fromUtf8("timeL"));
        sizePolicy.setHeightForWidth(timeL->sizePolicy().hasHeightForWidth());
        timeL->setSizePolicy(sizePolicy);
        timeL->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(timeL, 4, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 0, 1, 5);

        widget_2 = new QWidget(miniQMP);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        okienko = new QLabel(widget_2);
        okienko->setObjectName(QString::fromUtf8("okienko"));
        okienko->setMinimumSize(QSize(68, 68));
        okienko->setMaximumSize(QSize(68, 68));
        okienko->setFrameShape(QFrame::StyledPanel);
        okienko->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(okienko, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 2, 0, 3, 1);

        titleB = new QFrame(miniQMP);
        titleB->setObjectName(QString::fromUtf8("titleB"));
        titleB->setFrameShape(QFrame::StyledPanel);
        titleB->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(titleB);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        titleL = new QLabel(titleB);
        titleL->setObjectName(QString::fromUtf8("titleL"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titleL->sizePolicy().hasHeightForWidth());
        titleL->setSizePolicy(sizePolicy2);
        titleL->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout->addWidget(titleL, 0, 0, 1, 1);

        closeB = new QPushButton(titleB);
        closeB->setObjectName(QString::fromUtf8("closeB"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(closeB->sizePolicy().hasHeightForWidth());
        closeB->setSizePolicy(sizePolicy3);
        closeB->setMinimumSize(QSize(18, 18));
        closeB->setMaximumSize(QSize(18, 18));
        closeB->setCursor(QCursor(Qt::PointingHandCursor));
        closeB->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(closeB, 0, 2, 1, 1);

        plistB = new QPushButton(titleB);
        plistB->setObjectName(QString::fromUtf8("plistB"));
        sizePolicy3.setHeightForWidth(plistB->sizePolicy().hasHeightForWidth());
        plistB->setSizePolicy(sizePolicy3);
        plistB->setMinimumSize(QSize(18, 18));
        plistB->setMaximumSize(QSize(18, 18));
        plistB->setCursor(QCursor(Qt::PointingHandCursor));
        plistB->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(plistB, 0, 1, 1, 1);


        gridLayout_2->addWidget(titleB, 0, 0, 1, 5);

        widget = new QWidget(miniQMP);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        playB = new QPushButton(widget);
        playB->setObjectName(QString::fromUtf8("playB"));
        playB->setMinimumSize(QSize(24, 24));
        playB->setMaximumSize(QSize(24, 24));
        playB->setCursor(QCursor(Qt::PointingHandCursor));
        playB->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(playB, 1, 1, 1, 1);

        stopB = new QPushButton(widget);
        stopB->setObjectName(QString::fromUtf8("stopB"));
        stopB->setMinimumSize(QSize(24, 24));
        stopB->setMaximumSize(QSize(24, 24));
        stopB->setCursor(QCursor(Qt::PointingHandCursor));
        stopB->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(stopB, 1, 3, 1, 1);

        prevB = new QPushButton(widget);
        prevB->setObjectName(QString::fromUtf8("prevB"));
        prevB->setMinimumSize(QSize(24, 24));
        prevB->setMaximumSize(QSize(24, 24));
        prevB->setCursor(QCursor(Qt::PointingHandCursor));
        prevB->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(prevB, 1, 4, 1, 1);

        nextB = new QPushButton(widget);
        nextB->setObjectName(QString::fromUtf8("nextB"));
        nextB->setMinimumSize(QSize(24, 24));
        nextB->setMaximumSize(QSize(24, 24));
        nextB->setCursor(QCursor(Qt::PointingHandCursor));
        nextB->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(nextB, 1, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 6, 1, 1);

        pauseB = new QPushButton(widget);
        pauseB->setObjectName(QString::fromUtf8("pauseB"));
        pauseB->setMinimumSize(QSize(24, 24));
        pauseB->setMaximumSize(QSize(24, 24));
        pauseB->setCursor(QCursor(Qt::PointingHandCursor));
        pauseB->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(pauseB, 1, 2, 1, 1);


        gridLayout_2->addWidget(widget, 2, 1, 1, 3);

        QWidget::setTabOrder(playB, pauseB);
        QWidget::setTabOrder(pauseB, stopB);
        QWidget::setTabOrder(stopB, prevB);
        QWidget::setTabOrder(prevB, nextB);
        QWidget::setTabOrder(nextB, volS);
        QWidget::setTabOrder(volS, closeB);

        retranslateUi(miniQMP);

        QMetaObject::connectSlotsByName(miniQMP);
    } // setupUi

    void retranslateUi(QFrame *miniQMP)
    {
        miniQMP->setWindowTitle(QApplication::translate("miniQMP", "miniQMP", 0, QApplication::UnicodeUTF8));
        timeL->setText(QApplication::translate("miniQMP", "00 : 00 : 00", 0, QApplication::UnicodeUTF8));
        titleL->setText(QApplication::translate("miniQMP", "title", 0, QApplication::UnicodeUTF8));
        closeB->setText(QApplication::translate("miniQMP", "X", 0, QApplication::UnicodeUTF8));
        plistB->setText(QApplication::translate("miniQMP", "P", 0, QApplication::UnicodeUTF8));
        playB->setText(QString());
        stopB->setText(QString());
        prevB->setText(QString());
        nextB->setText(QString());
        pauseB->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class miniQMP: public Ui_miniQMP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIQMP_H
