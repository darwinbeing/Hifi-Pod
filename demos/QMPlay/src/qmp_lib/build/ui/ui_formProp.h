/********************************************************************************
** Form generated from reading UI file 'formProp.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROP_H
#define UI_FORMPROP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormP
{
public:
    QTextEdit *textEdit;
    QLabel *titleL;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *adresE;
    QPushButton *OKB;
    QLabel *label_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QRadioButton *fileB;
    QRadioButton *adresB;
    QComboBox *pluginsB;
    QRadioButton *pluginB;
    QPushButton *applyTB;
    QPushButton *applyB;
    QLineEdit *typeE;
    QLabel *label_3;
    QLabel *nrL;
    QLabel *label_6;
    QLabel *fSizeL;

    void setupUi(QWidget *FormP)
    {
        if (FormP->objectName().isEmpty())
            FormP->setObjectName(QString::fromUtf8("FormP"));
        FormP->resize(431, 429);
        FormP->setMinimumSize(QSize(431, 429));
        FormP->setMaximumSize(QSize(431, 429));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormP->setWindowIcon(icon);
        textEdit = new QTextEdit(FormP);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(9, 256, 413, 128));
        textEdit->setReadOnly(true);
        titleL = new QLabel(FormP);
        titleL->setObjectName(QString::fromUtf8("titleL"));
        titleL->setGeometry(QRect(64, 9, 358, 18));
        titleL->setMinimumSize(QSize(358, 18));
        titleL->setMaximumSize(QSize(358, 18));
        label = new QLabel(FormP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 57, 81, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(FormP);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 226, 104, 23));
        label_2->setFont(font);
        adresE = new QLineEdit(FormP);
        adresE->setObjectName(QString::fromUtf8("adresE"));
        adresE->setGeometry(QRect(119, 226, 303, 23));
        OKB = new QPushButton(FormP);
        OKB->setObjectName(QString::fromUtf8("OKB"));
        OKB->setGeometry(QRect(347, 393, 75, 27));
        label_4 = new QLabel(FormP);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(9, 9, 49, 18));
        label_4->setFont(font);
        groupBox = new QGroupBox(FormP);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 89, 413, 126));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        fileB = new QRadioButton(groupBox);
        fileB->setObjectName(QString::fromUtf8("fileB"));
        fileB->setChecked(true);

        gridLayout->addWidget(fileB, 0, 0, 1, 1);

        adresB = new QRadioButton(groupBox);
        adresB->setObjectName(QString::fromUtf8("adresB"));

        gridLayout->addWidget(adresB, 3, 0, 1, 1);

        pluginsB = new QComboBox(groupBox);
        pluginsB->setObjectName(QString::fromUtf8("pluginsB"));

        gridLayout->addWidget(pluginsB, 1, 1, 1, 1);

        pluginB = new QRadioButton(groupBox);
        pluginB->setObjectName(QString::fromUtf8("pluginB"));

        gridLayout->addWidget(pluginB, 1, 0, 1, 1);

        applyTB = new QPushButton(groupBox);
        applyTB->setObjectName(QString::fromUtf8("applyTB"));

        gridLayout->addWidget(applyTB, 3, 1, 1, 1);

        applyB = new QPushButton(FormP);
        applyB->setObjectName(QString::fromUtf8("applyB"));
        applyB->setGeometry(QRect(9, 393, 328, 27));
        typeE = new QLineEdit(FormP);
        typeE->setObjectName(QString::fromUtf8("typeE"));
        typeE->setGeometry(QRect(101, 57, 321, 23));
        typeE->setReadOnly(true);
        label_3 = new QLabel(FormP);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(9, 32, 49, 18));
        label_3->setFont(font);
        nrL = new QLabel(FormP);
        nrL->setObjectName(QString::fromUtf8("nrL"));
        nrL->setGeometry(QRect(64, 32, 49, 18));
        label_6 = new QLabel(FormP);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 32, 111, 18));
        label_6->setFont(font);
        fSizeL = new QLabel(FormP);
        fSizeL->setObjectName(QString::fromUtf8("fSizeL"));
        fSizeL->setGeometry(QRect(280, 32, 141, 18));
        QWidget::setTabOrder(typeE, fileB);
        QWidget::setTabOrder(fileB, pluginB);
        QWidget::setTabOrder(pluginB, adresB);
        QWidget::setTabOrder(adresB, pluginsB);
        QWidget::setTabOrder(pluginsB, applyTB);
        QWidget::setTabOrder(applyTB, adresE);
        QWidget::setTabOrder(adresE, textEdit);
        QWidget::setTabOrder(textEdit, applyB);
        QWidget::setTabOrder(applyB, OKB);

        retranslateUi(FormP);

        QMetaObject::connectSlotsByName(FormP);
    } // setupUi

    void retranslateUi(QWidget *FormP)
    {
        FormP->setWindowTitle(QApplication::translate("FormP", "W\305\202a\305\233ciwo\305\233ci", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("FormP", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Rodzaje typ\303\263w:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\"<span style=\" font-weight:600;\">file</span>\" - podana jest \305\233cie\305\274ka do zwyk\305\202ego pliku</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\"<span style=\" font-weight:600;\">plugin:param.x</span>\" - odtwarzane specjalnie przez plugin ( param to parametr przes\305\202any do wtyczki, a x to nazwa wtyczki ). Mo\305\274e s\305\202u\305\274y\304\207 do generowania jaki\305\233 d\305\272wi\304\231k\303\263w przez plugin lub odczyt np. audio CD.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\"<span style=\" font-weight:600;\">internet:x</span>\" - strumie\305\204 otwierany z internetu ( x to nazwa wtyczki ). Obs\305\202ugiwany protok\303\263\305\202 i format strumienia zale\305\274y od wtyczki.</p></body></html>", 0, QApplication::UnicodeUTF8));
        titleL->setText(QApplication::translate("FormP", "Title flom QMP playlist", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormP", "Typ pliku:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FormP", "Wpisz adres:", 0, QApplication::UnicodeUTF8));
        OKB->setText(QApplication::translate("FormP", "Zamknij", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormP", "Tytu\305\202:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FormP", "Wybierz typ pliku", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FormP", "Wtyczka:", 0, QApplication::UnicodeUTF8));
        fileB->setText(QApplication::translate("FormP", "Plik", 0, QApplication::UnicodeUTF8));
        adresB->setText(QApplication::translate("FormP", "Adres internetowy", 0, QApplication::UnicodeUTF8));
        pluginB->setText(QApplication::translate("FormP", "Wtyczka", 0, QApplication::UnicodeUTF8));
        applyTB->setText(QApplication::translate("FormP", "Zastosuj", 0, QApplication::UnicodeUTF8));
        applyB->setText(QApplication::translate("FormP", "Zastosuj", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FormP", "Numer:", 0, QApplication::UnicodeUTF8));
        nrL->setText(QApplication::translate("FormP", "Number", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FormP", "Rozmiar pliku:", 0, QApplication::UnicodeUTF8));
        fSizeL->setText(QApplication::translate("FormP", "0MB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormP: public Ui_FormP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROP_H
