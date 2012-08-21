/********************************************************************************
** Form generated from reading UI file 'formMp3.ui'
**
** Created: Tue Aug 21 20:18:27 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMP3_H
#define UI_FORMMP3_H

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

class Ui_FormMP3
{
public:
    QLabel *aBitRateL;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_4;
    QLabel *chnL;
    QLineEdit *pthE;
    QLabel *srateL;
    QPushButton *id3B;
    QLabel *id3L;
    QLabel *imgL;

    void setupUi(QWidget *FormMP3)
    {
        if (FormMP3->objectName().isEmpty())
            FormMP3->setObjectName(QString::fromUtf8("FormMP3"));
        FormMP3->resize(400, 220);
        FormMP3->setMinimumSize(QSize(400, 220));
        FormMP3->setMaximumSize(QSize(400, 220));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormMP3->setWindowIcon(icon);
        aBitRateL = new QLabel(FormMP3);
        aBitRateL->setObjectName(QString::fromUtf8("aBitRateL"));
        aBitRateL->setGeometry(QRect(70, 140, 52, 18));
        closeButton = new QPushButton(FormMP3);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(310, 160, 81, 27));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        closeButton->setCheckable(true);
        label = new QLabel(FormMP3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 140, 61, 18));
        label_4 = new QLabel(FormMP3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 51, 18));
        chnL = new QLabel(FormMP3);
        chnL->setObjectName(QString::fromUtf8("chnL"));
        chnL->setGeometry(QRect(140, 130, 61, 18));
        pthE = new QLineEdit(FormMP3);
        pthE->setObjectName(QString::fromUtf8("pthE"));
        pthE->setGeometry(QRect(10, 190, 381, 25));
        pthE->setReadOnly(true);
        srateL = new QLabel(FormMP3);
        srateL->setObjectName(QString::fromUtf8("srateL"));
        srateL->setGeometry(QRect(140, 150, 61, 20));
        id3B = new QPushButton(FormMP3);
        id3B->setObjectName(QString::fromUtf8("id3B"));
        id3B->setGeometry(QRect(310, 130, 81, 28));
        id3B->setCursor(QCursor(Qt::PointingHandCursor));
        id3B->setCheckable(true);
        id3L = new QLabel(FormMP3);
        id3L->setObjectName(QString::fromUtf8("id3L"));
        id3L->setGeometry(QRect(10, 10, 381, 111));
        id3L->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        imgL = new QLabel(FormMP3);
        imgL->setObjectName(QString::fromUtf8("imgL"));
        imgL->setGeometry(QRect(230, 130, 50, 50));
        imgL->setMinimumSize(QSize(50, 50));
        imgL->setMaximumSize(QSize(50, 50));
        imgL->setFrameShape(QFrame::StyledPanel);
        imgL->setFrameShadow(QFrame::Raised);
        QWidget::setTabOrder(closeButton, id3B);
        QWidget::setTabOrder(id3B, pthE);

        retranslateUi(FormMP3);

        QMetaObject::connectSlotsByName(FormMP3);
    } // setupUi

    void retranslateUi(QWidget *FormMP3)
    {
        FormMP3->setWindowTitle(QApplication::translate("FormMP3", "MP3 music information", 0, QApplication::UnicodeUTF8));
        aBitRateL->setText(QApplication::translate("FormMP3", "BR", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("FormMP3", "Close", 0, QApplication::UnicodeUTF8));
        closeButton->setShortcut(QApplication::translate("FormMP3", "Esc", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormMP3", "Bitrate:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormMP3", "Path:", 0, QApplication::UnicodeUTF8));
        chnL->setText(QApplication::translate("FormMP3", "channels", 0, QApplication::UnicodeUTF8));
        srateL->setText(QApplication::translate("FormMP3", "rate", 0, QApplication::UnicodeUTF8));
        id3B->setText(QApplication::translate("FormMP3", "Edit ID3", 0, QApplication::UnicodeUTF8));
        id3L->setText(QString());
        imgL->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormMP3: public Ui_FormMP3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMP3_H
