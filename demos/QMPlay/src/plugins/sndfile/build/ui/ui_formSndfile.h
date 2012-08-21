/********************************************************************************
** Form generated from reading UI file 'formSndfile.ui'
**
** Created: Tue Aug 21 20:28:08 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSNDFILE_H
#define UI_FORMSNDFILE_H

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

class Ui_FormSNDFILE
{
public:
    QPushButton *closeButton;
    QLabel *txtL;
    QLabel *label_4;
    QLabel *chnL;
    QLineEdit *pthE;
    QLabel *srateL;
    QPushButton *tagB;
    QLabel *formatL;
    QLabel *imgL;

    void setupUi(QWidget *FormSNDFILE)
    {
        if (FormSNDFILE->objectName().isEmpty())
            FormSNDFILE->setObjectName(QString::fromUtf8("FormSNDFILE"));
        FormSNDFILE->resize(400, 200);
        FormSNDFILE->setMinimumSize(QSize(400, 200));
        FormSNDFILE->setMaximumSize(QSize(400, 200));
        closeButton = new QPushButton(FormSNDFILE);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(310, 140, 81, 27));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        txtL = new QLabel(FormSNDFILE);
        txtL->setObjectName(QString::fromUtf8("txtL"));
        txtL->setGeometry(QRect(10, 10, 381, 101));
        txtL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4 = new QLabel(FormSNDFILE);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 150, 51, 18));
        chnL = new QLabel(FormSNDFILE);
        chnL->setObjectName(QString::fromUtf8("chnL"));
        chnL->setGeometry(QRect(120, 110, 81, 18));
        pthE = new QLineEdit(FormSNDFILE);
        pthE->setObjectName(QString::fromUtf8("pthE"));
        pthE->setGeometry(QRect(10, 170, 381, 25));
        pthE->setReadOnly(true);
        srateL = new QLabel(FormSNDFILE);
        srateL->setObjectName(QString::fromUtf8("srateL"));
        srateL->setGeometry(QRect(120, 130, 71, 20));
        tagB = new QPushButton(FormSNDFILE);
        tagB->setObjectName(QString::fromUtf8("tagB"));
        tagB->setGeometry(QRect(310, 110, 81, 28));
        tagB->setCursor(QCursor(Qt::PointingHandCursor));
        tagB->setCheckable(true);
        formatL = new QLabel(FormSNDFILE);
        formatL->setObjectName(QString::fromUtf8("formatL"));
        formatL->setGeometry(QRect(10, 110, 71, 20));
        imgL = new QLabel(FormSNDFILE);
        imgL->setObjectName(QString::fromUtf8("imgL"));
        imgL->setGeometry(QRect(230, 110, 50, 50));
        imgL->setMinimumSize(QSize(50, 50));
        imgL->setMaximumSize(QSize(50, 50));
        imgL->setFrameShape(QFrame::StyledPanel);
        imgL->setFrameShadow(QFrame::Raised);
        QWidget::setTabOrder(pthE, tagB);
        QWidget::setTabOrder(tagB, closeButton);

        retranslateUi(FormSNDFILE);

        QMetaObject::connectSlotsByName(FormSNDFILE);
    } // setupUi

    void retranslateUi(QWidget *FormSNDFILE)
    {
        FormSNDFILE->setWindowTitle(QApplication::translate("FormSNDFILE", "Sndfile information", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("FormSNDFILE", "Close", 0, QApplication::UnicodeUTF8));
        closeButton->setShortcut(QApplication::translate("FormSNDFILE", "Esc", 0, QApplication::UnicodeUTF8));
        txtL->setText(QApplication::translate("FormSNDFILE", "txt", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormSNDFILE", "Path:", 0, QApplication::UnicodeUTF8));
        chnL->setText(QApplication::translate("FormSNDFILE", "channels", 0, QApplication::UnicodeUTF8));
        srateL->setText(QApplication::translate("FormSNDFILE", "rate", 0, QApplication::UnicodeUTF8));
        tagB->setText(QApplication::translate("FormSNDFILE", "Edit tag", 0, QApplication::UnicodeUTF8));
        formatL->setText(QApplication::translate("FormSNDFILE", "format", 0, QApplication::UnicodeUTF8));
        imgL->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSNDFILE: public Ui_FormSNDFILE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSNDFILE_H
