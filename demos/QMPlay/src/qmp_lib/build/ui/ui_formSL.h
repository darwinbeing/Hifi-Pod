/********************************************************************************
** Form generated from reading UI file 'formSL.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSL_H
#define UI_FORMSL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSLR
{
public:
    QGridLayout *gridLayout;
    QPushButton *bR_1;
    QPushButton *bL_4;
    QSpacerItem *spacerItem;
    QPushButton *bR_5;
    QPushButton *bL_3;
    QPushButton *bL_1;
    QPushButton *bL_2;
    QPushButton *bR_4;
    QPushButton *bL_5;
    QPushButton *bR_2;
    QSpacerItem *spacerItem1;
    QPushButton *bR_3;

    void setupUi(QWidget *FormSLR)
    {
        if (FormSLR->objectName().isEmpty())
            FormSLR->setObjectName(QString::fromUtf8("FormSLR"));
        FormSLR->resize(163, 161);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormSLR->setWindowIcon(icon);
        gridLayout = new QGridLayout(FormSLR);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bR_1 = new QPushButton(FormSLR);
        bR_1->setObjectName(QString::fromUtf8("bR_1"));
        QPalette palette;
        QBrush brush(QColor(85, 255, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        QBrush brush1(QColor(244, 240, 235, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bR_1->setPalette(palette);
        bR_1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bR_1, 4, 2, 1, 1);

        bL_4 = new QPushButton(FormSLR);
        bL_4->setObjectName(QString::fromUtf8("bL_4"));
        QPalette palette1;
        QBrush brush2(QColor(255, 170, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bL_4->setPalette(palette1);
        bL_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bL_4, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 3, 5, 1);

        bR_5 = new QPushButton(FormSLR);
        bR_5->setObjectName(QString::fromUtf8("bR_5"));
        QPalette palette2;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bR_5->setPalette(palette2);
        bR_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bR_5, 0, 2, 1, 1);

        bL_3 = new QPushButton(FormSLR);
        bL_3->setObjectName(QString::fromUtf8("bL_3"));
        QPalette palette3;
        QBrush brush4(QColor(255, 170, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bL_3->setPalette(palette3);
        bL_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bL_3, 2, 1, 1, 1);

        bL_1 = new QPushButton(FormSLR);
        bL_1->setObjectName(QString::fromUtf8("bL_1"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bL_1->setPalette(palette4);
        bL_1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bL_1, 4, 1, 1, 1);

        bL_2 = new QPushButton(FormSLR);
        bL_2->setObjectName(QString::fromUtf8("bL_2"));
        QPalette palette5;
        QBrush brush5(QColor(85, 255, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bL_2->setPalette(palette5);
        bL_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bL_2, 3, 1, 1, 1);

        bR_4 = new QPushButton(FormSLR);
        bR_4->setObjectName(QString::fromUtf8("bR_4"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bR_4->setPalette(palette6);
        bR_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bR_4, 1, 2, 1, 1);

        bL_5 = new QPushButton(FormSLR);
        bL_5->setObjectName(QString::fromUtf8("bL_5"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bL_5->setPalette(palette7);
        bL_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bL_5, 0, 1, 1, 1);

        bR_2 = new QPushButton(FormSLR);
        bR_2->setObjectName(QString::fromUtf8("bR_2"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bR_2->setPalette(palette8);
        bR_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bR_2, 3, 2, 1, 1);

        spacerItem1 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 0, 0, 5, 1);

        bR_3 = new QPushButton(FormSLR);
        bR_3->setObjectName(QString::fromUtf8("bR_3"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        bR_3->setPalette(palette9);
        bR_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(bR_3, 2, 2, 1, 1);


        retranslateUi(FormSLR);

        QMetaObject::connectSlotsByName(FormSLR);
    } // setupUi

    void retranslateUi(QWidget *FormSLR)
    {
        FormSLR->setWindowTitle(QApplication::translate("FormSLR", "Slider L&R", 0, QApplication::UnicodeUTF8));
        bR_1->setText(QString());
        bL_4->setText(QString());
        bR_5->setText(QString());
        bL_3->setText(QString());
        bL_1->setText(QString());
        bL_2->setText(QString());
        bR_4->setText(QString());
        bL_5->setText(QString());
        bR_2->setText(QString());
        bR_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSLR: public Ui_FormSLR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSL_H
