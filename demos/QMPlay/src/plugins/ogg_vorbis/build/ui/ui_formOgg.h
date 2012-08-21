/********************************************************************************
** Form generated from reading UI file 'formOgg.ui'
**
** Created: Tue Aug 21 20:18:35 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMOGG_H
#define UI_FORMOGG_H

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

class Ui_FormOGG
{
public:
    QLabel *bitRateL;
    QLabel *aBitRateL;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *txtL;
    QLabel *label_4;
    QLabel *chnL;
    QLineEdit *pthE;
    QLabel *srateL;
    QPushButton *tagB;

    void setupUi(QWidget *FormOGG)
    {
        if (FormOGG->objectName().isEmpty())
            FormOGG->setObjectName(QString::fromUtf8("FormOGG"));
        FormOGG->resize(400, 200);
        FormOGG->setMinimumSize(QSize(400, 200));
        FormOGG->setMaximumSize(QSize(400, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormOGG->setWindowIcon(icon);
        bitRateL = new QLabel(FormOGG);
        bitRateL->setObjectName(QString::fromUtf8("bitRateL"));
        bitRateL->setGeometry(QRect(80, 130, 57, 17));
        aBitRateL = new QLabel(FormOGG);
        aBitRateL->setObjectName(QString::fromUtf8("aBitRateL"));
        aBitRateL->setGeometry(QRect(80, 110, 57, 17));
        closeButton = new QPushButton(FormOGG);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(310, 140, 81, 27));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(FormOGG);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 61, 31));
        txtL = new QLabel(FormOGG);
        txtL->setObjectName(QString::fromUtf8("txtL"));
        txtL->setGeometry(QRect(10, 10, 381, 101));
        txtL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4 = new QLabel(FormOGG);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 150, 51, 18));
        chnL = new QLabel(FormOGG);
        chnL->setObjectName(QString::fromUtf8("chnL"));
        chnL->setGeometry(QRect(170, 110, 81, 18));
        pthE = new QLineEdit(FormOGG);
        pthE->setObjectName(QString::fromUtf8("pthE"));
        pthE->setGeometry(QRect(10, 170, 381, 25));
        pthE->setReadOnly(true);
        srateL = new QLabel(FormOGG);
        srateL->setObjectName(QString::fromUtf8("srateL"));
        srateL->setGeometry(QRect(170, 130, 71, 20));
        tagB = new QPushButton(FormOGG);
        tagB->setObjectName(QString::fromUtf8("tagB"));
        tagB->setGeometry(QRect(310, 110, 81, 28));
        tagB->setCursor(QCursor(Qt::PointingHandCursor));
        tagB->setCheckable(true);
        QWidget::setTabOrder(pthE, tagB);
        QWidget::setTabOrder(tagB, closeButton);

        retranslateUi(FormOGG);

        QMetaObject::connectSlotsByName(FormOGG);
    } // setupUi

    void retranslateUi(QWidget *FormOGG)
    {
        FormOGG->setWindowTitle(QApplication::translate("FormOGG", "OGG music information", 0, QApplication::UnicodeUTF8));
        bitRateL->setText(QApplication::translate("FormOGG", "BR", 0, QApplication::UnicodeUTF8));
        aBitRateL->setText(QApplication::translate("FormOGG", "BR", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("FormOGG", "Close", 0, QApplication::UnicodeUTF8));
        closeButton->setShortcut(QApplication::translate("FormOGG", "Esc", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormOGG", "Bitrate:", 0, QApplication::UnicodeUTF8));
        txtL->setText(QApplication::translate("FormOGG", "txt", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormOGG", "Path:", 0, QApplication::UnicodeUTF8));
        chnL->setText(QApplication::translate("FormOGG", "mono/stereo", 0, QApplication::UnicodeUTF8));
        srateL->setText(QApplication::translate("FormOGG", "rate", 0, QApplication::UnicodeUTF8));
        tagB->setText(QApplication::translate("FormOGG", "Edit tag", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormOGG: public Ui_FormOGG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMOGG_H
