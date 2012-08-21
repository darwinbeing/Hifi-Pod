/********************************************************************************
** Form generated from reading UI file 'formInfo.ui'
**
** Created: Tue Aug 21 19:54:53 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMINFO_H
#define UI_FORMINFO_H

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

class Ui_FormINFO
{
public:
    QPushButton *closeButton;
    QLineEdit *cdtitleE;
    QLineEdit *cdartistE;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *chnL;
    QLineEdit *artistE;
    QLineEdit *titleE;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *cdgenereE;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *cdyearE;
    QLabel *label;
    QLabel *tL;
    QLabel *label_8;
    QLabel *cdL;

    void setupUi(QWidget *FormINFO)
    {
        if (FormINFO->objectName().isEmpty())
            FormINFO->setObjectName(QString::fromUtf8("FormINFO"));
        FormINFO->resize(260, 360);
        FormINFO->setMinimumSize(QSize(260, 360));
        FormINFO->setMaximumSize(QSize(260, 360));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormINFO->setWindowIcon(icon);
        closeButton = new QPushButton(FormINFO);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(170, 330, 81, 27));
        cdtitleE = new QLineEdit(FormINFO);
        cdtitleE->setObjectName(QString::fromUtf8("cdtitleE"));
        cdtitleE->setGeometry(QRect(10, 30, 241, 25));
        cdtitleE->setReadOnly(true);
        cdartistE = new QLineEdit(FormINFO);
        cdartistE->setObjectName(QString::fromUtf8("cdartistE"));
        cdartistE->setGeometry(QRect(10, 80, 241, 25));
        cdartistE->setReadOnly(true);
        label_2 = new QLabel(FormINFO);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 71, 18));
        label_3 = new QLabel(FormINFO);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 71, 18));
        chnL = new QLabel(FormINFO);
        chnL->setObjectName(QString::fromUtf8("chnL"));
        chnL->setGeometry(QRect(10, 340, 141, 18));
        artistE = new QLineEdit(FormINFO);
        artistE->setObjectName(QString::fromUtf8("artistE"));
        artistE->setGeometry(QRect(20, 250, 231, 25));
        artistE->setReadOnly(true);
        titleE = new QLineEdit(FormINFO);
        titleE->setObjectName(QString::fromUtf8("titleE"));
        titleE->setGeometry(QRect(20, 300, 231, 25));
        titleE->setReadOnly(true);
        label_4 = new QLabel(FormINFO);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 51, 18));
        label_5 = new QLabel(FormINFO);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 51, 18));
        cdgenereE = new QLineEdit(FormINFO);
        cdgenereE->setObjectName(QString::fromUtf8("cdgenereE"));
        cdgenereE->setGeometry(QRect(10, 130, 241, 25));
        cdgenereE->setReadOnly(true);
        label_6 = new QLabel(FormINFO);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 91, 18));
        label_7 = new QLabel(FormINFO);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 160, 91, 18));
        cdyearE = new QLineEdit(FormINFO);
        cdyearE->setObjectName(QString::fromUtf8("cdyearE"));
        cdyearE->setGeometry(QRect(10, 180, 241, 25));
        cdyearE->setReadOnly(true);
        label = new QLabel(FormINFO);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 51, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        tL = new QLabel(FormINFO);
        tL->setObjectName(QString::fromUtf8("tL"));
        tL->setGeometry(QRect(60, 210, 31, 17));
        label_8 = new QLabel(FormINFO);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 210, 31, 17));
        label_8->setFont(font);
        cdL = new QLabel(FormINFO);
        cdL->setObjectName(QString::fromUtf8("cdL"));
        cdL->setGeometry(QRect(120, 210, 131, 17));
        QWidget::setTabOrder(closeButton, cdtitleE);
        QWidget::setTabOrder(cdtitleE, cdartistE);
        QWidget::setTabOrder(cdartistE, cdgenereE);
        QWidget::setTabOrder(cdgenereE, cdyearE);
        QWidget::setTabOrder(cdyearE, artistE);
        QWidget::setTabOrder(artistE, titleE);

        retranslateUi(FormINFO);

        QMetaObject::connectSlotsByName(FormINFO);
    } // setupUi

    void retranslateUi(QWidget *FormINFO)
    {
        FormINFO->setWindowTitle(QApplication::translate("FormINFO", "CDAudio", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("FormINFO", "Close", 0, QApplication::UnicodeUTF8));
        closeButton->setShortcut(QApplication::translate("FormINFO", "Esc", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FormINFO", "CD title:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FormINFO", "CD artist:", 0, QApplication::UnicodeUTF8));
        chnL->setText(QApplication::translate("FormINFO", "mono/stereo", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormINFO", "Artist:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FormINFO", "Title:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FormINFO", "CD genere:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FormINFO", "CD year:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormINFO", "Track:", 0, QApplication::UnicodeUTF8));
        tL->setText(QApplication::translate("FormINFO", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FormINFO", "CD:", 0, QApplication::UnicodeUTF8));
        cdL->setText(QApplication::translate("FormINFO", "/dev/null", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormINFO: public Ui_FormINFO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMINFO_H
