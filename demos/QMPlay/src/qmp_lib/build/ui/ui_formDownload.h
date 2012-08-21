/********************************************************************************
** Form generated from reading UI file 'formDownload.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDOWNLOAD_H
#define UI_FORMDOWNLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Download
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QProgressBar *dwnB;
    QLabel *label_2;
    QLabel *spdL;
    QLabel *label_4;
    QLabel *dwnL;
    QPushButton *instB;
    QPushButton *brB;

    void setupUi(QWidget *Form_Download)
    {
        if (Form_Download->objectName().isEmpty())
            Form_Download->setObjectName(QString::fromUtf8("Form_Download"));
        Form_Download->resize(245, 146);
        Form_Download->setMinimumSize(QSize(245, 146));
        Form_Download->setMaximumSize(QSize(245, 146));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form_Download->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form_Download);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Form_Download);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        dwnB = new QProgressBar(Form_Download);
        dwnB->setObjectName(QString::fromUtf8("dwnB"));
        dwnB->setValue(0);

        gridLayout->addWidget(dwnB, 1, 0, 1, 3);

        label_2 = new QLabel(Form_Download);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        spdL = new QLabel(Form_Download);
        spdL->setObjectName(QString::fromUtf8("spdL"));

        gridLayout->addWidget(spdL, 2, 1, 1, 2);

        label_4 = new QLabel(Form_Download);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dwnL = new QLabel(Form_Download);
        dwnL->setObjectName(QString::fromUtf8("dwnL"));

        gridLayout->addWidget(dwnL, 3, 1, 1, 2);

        instB = new QPushButton(Form_Download);
        instB->setObjectName(QString::fromUtf8("instB"));

        gridLayout->addWidget(instB, 4, 0, 1, 2);

        brB = new QPushButton(Form_Download);
        brB->setObjectName(QString::fromUtf8("brB"));

        gridLayout->addWidget(brB, 4, 2, 1, 1);


        retranslateUi(Form_Download);

        QMetaObject::connectSlotsByName(Form_Download);
    } // setupUi

    void retranslateUi(QWidget *Form_Download)
    {
        Form_Download->setWindowTitle(QApplication::translate("Form_Download", "Aktualizacja QMPlay", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_Download", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form_Download", "Szybko\305\233\304\207:", 0, QApplication::UnicodeUTF8));
        spdL->setText(QApplication::translate("Form_Download", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form_Download", "\305\232ci\304\205gni\304\231te:", 0, QApplication::UnicodeUTF8));
        dwnL->setText(QApplication::translate("Form_Download", "0", 0, QApplication::UnicodeUTF8));
        instB->setText(QApplication::translate("Form_Download", "Zainstaluj", 0, QApplication::UnicodeUTF8));
        brB->setText(QApplication::translate("Form_Download", "Przerwij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_Download: public Ui_Form_Download {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDOWNLOAD_H
