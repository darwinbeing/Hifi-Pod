/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:30:12 2012
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
    QCheckBox *sngTB;
    QSpinBox *msB;
    QCheckBox *lpB;
    QCheckBox *sB;
    QSpinBox *refB;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *pB;
    QCheckBox *kB;
    QCheckBox *kolor2B;
    QCheckBox *autoFillBackgroundB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(410, 180);
        Form3->setMinimumSize(QSize(410, 180));
        Form3->setMaximumSize(QSize(410, 180));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(0, 0, 71, 22));
        enabledB->setCursor(QCursor(Qt::PointingHandCursor));
        oknoB = new QCheckBox(Form3);
        oknoB->setObjectName(QString::fromUtf8("oknoB"));
        oknoB->setGeometry(QRect(10, 20, 271, 22));
        oknoB->setCursor(QCursor(Qt::PointingHandCursor));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(280, 150, 121, 25));
        ApplyB->setCursor(QCursor(Qt::PointingHandCursor));
        sngTB = new QCheckBox(Form3);
        sngTB->setObjectName(QString::fromUtf8("sngTB"));
        sngTB->setGeometry(QRect(10, 40, 171, 22));
        sngTB->setCursor(QCursor(Qt::PointingHandCursor));
        msB = new QSpinBox(Form3);
        msB->setObjectName(QString::fromUtf8("msB"));
        msB->setGeometry(QRect(280, 80, 91, 25));
        msB->setMinimum(1);
        msB->setMaximum(2000);
        lpB = new QCheckBox(Form3);
        lpB->setObjectName(QString::fromUtf8("lpB"));
        lpB->setGeometry(QRect(10, 80, 151, 22));
        lpB->setCursor(QCursor(Qt::PointingHandCursor));
        sB = new QCheckBox(Form3);
        sB->setObjectName(QString::fromUtf8("sB"));
        sB->setGeometry(QRect(10, 60, 171, 22));
        sB->setCursor(QCursor(Qt::PointingHandCursor));
        refB = new QSpinBox(Form3);
        refB->setObjectName(QString::fromUtf8("refB"));
        refB->setGeometry(QRect(280, 30, 91, 25));
        refB->setMinimum(5);
        refB->setMaximum(999);
        label_2 = new QLabel(Form3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 38, 20, 20));
        label_3 = new QLabel(Form3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 88, 31, 20));
        pB = new QCheckBox(Form3);
        pB->setObjectName(QString::fromUtf8("pB"));
        pB->setGeometry(QRect(30, 100, 111, 22));
        pB->setCursor(QCursor(Qt::PointingHandCursor));
        kB = new QCheckBox(Form3);
        kB->setObjectName(QString::fromUtf8("kB"));
        kB->setGeometry(QRect(30, 120, 111, 22));
        kB->setCursor(QCursor(Qt::PointingHandCursor));
        kolor2B = new QCheckBox(Form3);
        kolor2B->setObjectName(QString::fromUtf8("kolor2B"));
        kolor2B->setGeometry(QRect(30, 140, 181, 22));
        kolor2B->setCursor(QCursor(Qt::PointingHandCursor));
        autoFillBackgroundB = new QCheckBox(Form3);
        autoFillBackgroundB->setObjectName(QString::fromUtf8("autoFillBackgroundB"));
        autoFillBackgroundB->setGeometry(QRect(10, 160, 211, 19));
        autoFillBackgroundB->setCursor(QCursor(Qt::PointingHandCursor));
        QWidget::setTabOrder(enabledB, oknoB);
        QWidget::setTabOrder(oknoB, sngTB);
        QWidget::setTabOrder(sngTB, sB);
        QWidget::setTabOrder(sB, lpB);
        QWidget::setTabOrder(lpB, pB);
        QWidget::setTabOrder(pB, kB);
        QWidget::setTabOrder(kB, kolor2B);
        QWidget::setTabOrder(kolor2B, autoFillBackgroundB);
        QWidget::setTabOrder(autoFillBackgroundB, refB);
        QWidget::setTabOrder(refB, msB);
        QWidget::setTabOrder(msB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        oknoB->setText(QApplication::translate("Form3", "Zezwalaj na pokazywanie w okienku", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        sngTB->setText(QApplication::translate("Form3", "Odczytuj tekst piosenki", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        msB->setToolTip(QApplication::translate("Form3", "Ilo\305\233\304\207 pokazywanych pr\303\263bek w ci\304\205gu okre\305\233lonego czasu (ms)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lpB->setText(QApplication::translate("Form3", "Poka\305\274 lewy i prawy", 0, QApplication::UnicodeUTF8));
        sB->setText(QApplication::translate("Form3", "Poka\305\274 pr\303\263bki d\305\272wi\304\231ku", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        refB->setToolTip(QApplication::translate("Form3", "Szybko\305\233\304\207 od\305\233wie\305\274ania (ms)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Form3", "ms", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form3", "ms", 0, QApplication::UnicodeUTF8));
        pB->setText(QApplication::translate("Form3", "Poka\305\274 paski", 0, QApplication::UnicodeUTF8));
        kB->setText(QApplication::translate("Form3", "Poka\305\274 kreski", 0, QApplication::UnicodeUTF8));
        kolor2B->setText(QApplication::translate("Form3", "Poka\305\274 w wielu kolorach", 0, QApplication::UnicodeUTF8));
        autoFillBackgroundB->setText(QApplication::translate("Form3", "Automatycznie wype\305\202niaj t\305\202o", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
