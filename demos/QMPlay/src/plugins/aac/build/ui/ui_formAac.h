/********************************************************************************
** Form generated from reading UI file 'formAac.ui'
**
** Created: Tue Aug 21 08:13:06 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMAAC_H
#define UI_FORMAAC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAAC
{
public:
    QPushButton *closeButton;
    QLabel *label_4;
    QLabel *chnL;
    QLineEdit *pthE;
    QLabel *srateL;
    QPushButton *id3B;
    QLabel *id3L;
    QLabel *aBitRateL;
    QLabel *label;

    void setupUi(QWidget *FormAAC)
    {
        if (FormAAC->objectName().isEmpty())
            FormAAC->setObjectName(QString::fromUtf8("FormAAC"));
        FormAAC->resize(400, 220);
        FormAAC->setMinimumSize(QSize(400, 220));
        FormAAC->setMaximumSize(QSize(400, 220));
        closeButton = new QPushButton(FormAAC);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(310, 160, 81, 27));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        closeButton->setCheckable(true);
        label_4 = new QLabel(FormAAC);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 51, 18));
        chnL = new QLabel(FormAAC);
        chnL->setObjectName(QString::fromUtf8("chnL"));
        chnL->setGeometry(QRect(140, 130, 61, 18));
        pthE = new QLineEdit(FormAAC);
        pthE->setObjectName(QString::fromUtf8("pthE"));
        pthE->setGeometry(QRect(10, 190, 381, 25));
        pthE->setReadOnly(true);
        srateL = new QLabel(FormAAC);
        srateL->setObjectName(QString::fromUtf8("srateL"));
        srateL->setGeometry(QRect(140, 150, 61, 20));
        id3B = new QPushButton(FormAAC);
        id3B->setObjectName(QString::fromUtf8("id3B"));
        id3B->setGeometry(QRect(310, 130, 81, 28));
        id3B->setCursor(QCursor(Qt::PointingHandCursor));
        id3B->setCheckable(true);
        id3L = new QLabel(FormAAC);
        id3L->setObjectName(QString::fromUtf8("id3L"));
        id3L->setGeometry(QRect(10, 10, 381, 111));
        id3L->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        aBitRateL = new QLabel(FormAAC);
        aBitRateL->setObjectName(QString::fromUtf8("aBitRateL"));
        aBitRateL->setGeometry(QRect(70, 140, 51, 17));
        label = new QLabel(FormAAC);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 140, 61, 18));
        QWidget::setTabOrder(closeButton, id3B);
        QWidget::setTabOrder(id3B, pthE);

        retranslateUi(FormAAC);

        QMetaObject::connectSlotsByName(FormAAC);
    } // setupUi

    void retranslateUi(QWidget *FormAAC)
    {
        FormAAC->setWindowTitle(QApplication::translate("FormAAC", "AAC music information", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("FormAAC", "Close", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormAAC", "Path:", 0, QApplication::UnicodeUTF8));
        chnL->setText(QApplication::translate("FormAAC", "channels", 0, QApplication::UnicodeUTF8));
        srateL->setText(QApplication::translate("FormAAC", "rate", 0, QApplication::UnicodeUTF8));
        id3B->setText(QApplication::translate("FormAAC", "Edit ID3", 0, QApplication::UnicodeUTF8));
        id3L->setText(QString());
        aBitRateL->setText(QApplication::translate("FormAAC", "BR", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormAAC", "Bitrate:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormAAC: public Ui_FormAAC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMAAC_H
