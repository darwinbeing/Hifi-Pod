/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:30:19 2012
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
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QCheckBox *oknoB;
    QPushButton *ApplyB;
    QSpinBox *refB;
    QLabel *label;
    QCheckBox *isONB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(285, 120);
        Form3->setMinimumSize(QSize(285, 120));
        Form3->setMaximumSize(QSize(285, 120));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 20, 111, 22));
        enabledB->setCursor(QCursor(Qt::PointingHandCursor));
        oknoB = new QCheckBox(Form3);
        oknoB->setObjectName(QString::fromUtf8("oknoB"));
        oknoB->setGeometry(QRect(20, 40, 271, 22));
        oknoB->setCursor(QCursor(Qt::PointingHandCursor));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(20, 90, 261, 27));
        ApplyB->setCursor(QCursor(Qt::PointingHandCursor));
        refB = new QSpinBox(Form3);
        refB->setObjectName(QString::fromUtf8("refB"));
        refB->setGeometry(QRect(20, 60, 81, 25));
        refB->setMinimum(0);
        refB->setMaximum(100);
        label = new QLabel(Form3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 65, 31, 18));
        isONB = new QCheckBox(Form3);
        isONB->setObjectName(QString::fromUtf8("isONB"));
        isONB->setGeometry(QRect(0, 0, 81, 21));
        isONB->setCursor(QCursor(Qt::PointingHandCursor));
        QWidget::setTabOrder(enabledB, oknoB);
        QWidget::setTabOrder(oknoB, refB);
        QWidget::setTabOrder(refB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "Poka\305\274 okno", 0, QApplication::UnicodeUTF8));
        oknoB->setText(QApplication::translate("Form3", "Zezwalaj na pokazywanie w okienku", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        refB->setToolTip(QApplication::translate("Form3", "Szybko\305\233\304\207 od\305\233wie\305\274ania (w ms)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Form3", "ms", 0, QApplication::UnicodeUTF8));
        isONB->setText(QApplication::translate("Form3", "W\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
