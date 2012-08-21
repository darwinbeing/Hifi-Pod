/********************************************************************************
** Form generated from reading UI file 'formAbout.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMABOUT_H
#define UI_FORMABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormA
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_ver;
    QLabel *label_5;
    QLabel *kBL;
    QPushButton *cleanB;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *kBB;
    QPushButton *OKB;
    QPushButton *refB;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QTextEdit *logE;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QTextEdit *changeLogE;

    void setupUi(QWidget *FormA)
    {
        if (FormA->objectName().isEmpty())
            FormA->setObjectName(QString::fromUtf8("FormA"));
        FormA->resize(465, 374);
        FormA->setMinimumSize(QSize(390, 335));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormA->setWindowIcon(icon);
        gridLayout = new QGridLayout(FormA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FormA);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 6);

        label_6 = new QLabel(FormA);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_ver = new QLabel(FormA);
        label_ver->setObjectName(QString::fromUtf8("label_ver"));

        gridLayout->addWidget(label_ver, 1, 1, 1, 5);

        label_5 = new QLabel(FormA);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        kBL = new QLabel(FormA);
        kBL->setObjectName(QString::fromUtf8("kBL"));

        gridLayout->addWidget(kBL, 3, 1, 1, 5);

        cleanB = new QPushButton(FormA);
        cleanB->setObjectName(QString::fromUtf8("cleanB"));

        gridLayout->addWidget(cleanB, 6, 0, 1, 3);

        label_3 = new QLabel(FormA);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(175, 0));
        label_3->setMaximumSize(QSize(175, 16777215));

        gridLayout->addWidget(label_3, 5, 0, 1, 2);

        label_4 = new QLabel(FormA);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(68, 16777215));

        gridLayout->addWidget(label_4, 5, 5, 1, 1);

        kBB = new QSpinBox(FormA);
        kBB->setObjectName(QString::fromUtf8("kBB"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kBB->sizePolicy().hasHeightForWidth());
        kBB->setSizePolicy(sizePolicy);
        kBB->setMinimum(512);
        kBB->setMaximum(1024);

        gridLayout->addWidget(kBB, 5, 3, 1, 2);

        OKB = new QPushButton(FormA);
        OKB->setObjectName(QString::fromUtf8("OKB"));

        gridLayout->addWidget(OKB, 6, 5, 1, 1);

        refB = new QPushButton(FormA);
        refB->setObjectName(QString::fromUtf8("refB"));

        gridLayout->addWidget(refB, 6, 3, 1, 2);

        toolBox = new QToolBox(FormA);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 453, 184));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        logE = new QTextEdit(page);
        logE->setObjectName(QString::fromUtf8("logE"));
        logE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        logE->setUndoRedoEnabled(false);
        logE->setLineWrapMode(QTextEdit::WidgetWidth);
        logE->setReadOnly(true);

        gridLayout_2->addWidget(logE, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("QMPlay log"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 96, 83));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        changeLogE = new QTextEdit(page_2);
        changeLogE->setObjectName(QString::fromUtf8("changeLogE"));
        changeLogE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        changeLogE->setUndoRedoEnabled(false);
        changeLogE->setLineWrapMode(QTextEdit::WidgetWidth);
        changeLogE->setReadOnly(true);

        gridLayout_3->addWidget(changeLogE, 0, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("ChangeLog"));

        gridLayout->addWidget(toolBox, 4, 0, 1, 6);

        QWidget::setTabOrder(OKB, refB);
        QWidget::setTabOrder(refB, kBB);
        QWidget::setTabOrder(kBB, cleanB);
        QWidget::setTabOrder(cleanB, logE);
        QWidget::setTabOrder(logE, changeLogE);

        retranslateUi(FormA);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormA);
    } // setupUi

    void retranslateUi(QWidget *FormA)
    {
        FormA->setWindowTitle(QApplication::translate("FormA", "O QMPlay", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormA", "Autor: B\305\202a\305\274ej Szczygie\305\202 (zaps166)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FormA", "Wersja:", 0, QApplication::UnicodeUTF8));
        label_ver->setText(QApplication::translate("FormA", "v0.00.00", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FormA", "Rozmiar loga:", 0, QApplication::UnicodeUTF8));
        kBL->setText(QApplication::translate("FormA", "kB", 0, QApplication::UnicodeUTF8));
        cleanB->setText(QApplication::translate("FormA", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FormA", "Kasuj log kiedy osi\304\205gnie:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormA", "kB", 0, QApplication::UnicodeUTF8));
        OKB->setText(QApplication::translate("FormA", "OK", 0, QApplication::UnicodeUTF8));
        refB->setText(QApplication::translate("FormA", "Od\305\233wie\305\274", 0, QApplication::UnicodeUTF8));
        refB->setShortcut(QApplication::translate("FormA", "F5", 0, QApplication::UnicodeUTF8));
        logE->setHtml(QApplication::translate("FormA", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("FormA", "QMPlay log", 0, QApplication::UnicodeUTF8));
        changeLogE->setHtml(QApplication::translate("FormA", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("FormA", "ChangeLog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormA: public Ui_FormA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMABOUT_H
