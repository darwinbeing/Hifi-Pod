/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 08:06:57 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETUP_H
#define UI_FORMSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QPushButton *ApplyB;
    QLabel *label;
    QLineEdit *fPthE;
    QPushButton *browseB;
    QCheckBox *rawB;
    QCheckBox *schB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(421, 144);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(10, 110, 401, 27));
        label = new QLabel(Form3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 18));
        fPthE = new QLineEdit(Form3);
        fPthE->setObjectName(QString::fromUtf8("fPthE"));
        fPthE->setGeometry(QRect(10, 30, 311, 29));
        browseB = new QPushButton(Form3);
        browseB->setObjectName(QString::fromUtf8("browseB"));
        browseB->setGeometry(QRect(330, 30, 81, 28));
        rawB = new QCheckBox(Form3);
        rawB->setObjectName(QString::fromUtf8("rawB"));
        rawB->setGeometry(QRect(10, 60, 291, 23));
        schB = new QCheckBox(Form3);
        schB->setObjectName(QString::fromUtf8("schB"));
        schB->setGeometry(QRect(10, 80, 291, 22));
        QWidget::setTabOrder(fPthE, rawB);
        QWidget::setTabOrder(rawB, browseB);
        QWidget::setTabOrder(browseB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form3", "Path to file export:", 0, QApplication::UnicodeUTF8));
        browseB->setText(QApplication::translate("Form3", "Browse", 0, QApplication::UnicodeUTF8));
        rawB->setText(QApplication::translate("Form3", "Export to RAW file (without header)", 0, QApplication::UnicodeUTF8));
        schB->setText(QApplication::translate("Form3", "Save 8bit unsigned char to signed char", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
