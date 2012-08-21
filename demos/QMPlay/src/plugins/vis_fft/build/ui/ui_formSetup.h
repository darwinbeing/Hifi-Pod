/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:29:59 2012
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
    QSpinBox *fftsizeB;
    QCheckBox *paskiB;
    QCheckBox *linieB;
    QSpinBox *scaleB;
    QSpinBox *pB;
    QCheckBox *fullScopeB;
    QSpinBox *refB;
    QSpinBox *lpaskiB;
    QLabel *label;
    QCheckBox *kreskiB;
    QCheckBox *isONB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(280, 250);
        Form3->setMinimumSize(QSize(280, 250));
        Form3->setMaximumSize(QSize(280, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 20, 111, 22));
        enabledB->setCursor(QCursor(Qt::PointingHandCursor));
        oknoB = new QCheckBox(Form3);
        oknoB->setObjectName(QString::fromUtf8("oknoB"));
        oknoB->setGeometry(QRect(20, 40, 261, 22));
        oknoB->setCursor(QCursor(Qt::PointingHandCursor));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(14, 220, 261, 27));
        ApplyB->setCursor(QCursor(Qt::PointingHandCursor));
        fftsizeB = new QSpinBox(Form3);
        fftsizeB->setObjectName(QString::fromUtf8("fftsizeB"));
        fftsizeB->setGeometry(QRect(90, 70, 81, 31));
        fftsizeB->setMinimum(1);
        fftsizeB->setMaximum(1024);
        paskiB = new QCheckBox(Form3);
        paskiB->setObjectName(QString::fromUtf8("paskiB"));
        paskiB->setGeometry(QRect(20, 60, 71, 22));
        paskiB->setCursor(QCursor(Qt::PointingHandCursor));
        linieB = new QCheckBox(Form3);
        linieB->setObjectName(QString::fromUtf8("linieB"));
        linieB->setGeometry(QRect(20, 80, 71, 22));
        linieB->setCursor(QCursor(Qt::PointingHandCursor));
        scaleB = new QSpinBox(Form3);
        scaleB->setObjectName(QString::fromUtf8("scaleB"));
        scaleB->setGeometry(QRect(180, 70, 81, 31));
        scaleB->setMinimum(1);
        scaleB->setMaximum(100);
        pB = new QSpinBox(Form3);
        pB->setObjectName(QString::fromUtf8("pB"));
        pB->setGeometry(QRect(90, 180, 81, 31));
        pB->setMaximum(500);
        fullScopeB = new QCheckBox(Form3);
        fullScopeB->setObjectName(QString::fromUtf8("fullScopeB"));
        fullScopeB->setGeometry(QRect(20, 120, 111, 22));
        fullScopeB->setCursor(QCursor(Qt::PointingHandCursor));
        refB = new QSpinBox(Form3);
        refB->setObjectName(QString::fromUtf8("refB"));
        refB->setGeometry(QRect(90, 140, 81, 31));
        refB->setMinimum(5);
        refB->setMaximum(999);
        lpaskiB = new QSpinBox(Form3);
        lpaskiB->setObjectName(QString::fromUtf8("lpaskiB"));
        lpaskiB->setGeometry(QRect(180, 180, 81, 31));
        lpaskiB->setMinimum(4);
        lpaskiB->setMaximum(1024);
        label = new QLabel(Form3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 150, 31, 18));
        kreskiB = new QCheckBox(Form3);
        kreskiB->setObjectName(QString::fromUtf8("kreskiB"));
        kreskiB->setGeometry(QRect(20, 100, 71, 22));
        kreskiB->setCursor(QCursor(Qt::PointingHandCursor));
        isONB = new QCheckBox(Form3);
        isONB->setObjectName(QString::fromUtf8("isONB"));
        isONB->setGeometry(QRect(0, 0, 71, 22));
        isONB->setCursor(QCursor(Qt::PointingHandCursor));
        QWidget::setTabOrder(enabledB, oknoB);
        QWidget::setTabOrder(oknoB, paskiB);
        QWidget::setTabOrder(paskiB, linieB);
        QWidget::setTabOrder(linieB, kreskiB);
        QWidget::setTabOrder(kreskiB, fullScopeB);
        QWidget::setTabOrder(fullScopeB, fftsizeB);
        QWidget::setTabOrder(fftsizeB, scaleB);
        QWidget::setTabOrder(scaleB, refB);
        QWidget::setTabOrder(refB, pB);
        QWidget::setTabOrder(pB, lpaskiB);
        QWidget::setTabOrder(lpaskiB, ApplyB);

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
        fftsizeB->setToolTip(QApplication::translate("Form3", "Wielko\305\233\304\207 tablicy dla FFT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        paskiB->setText(QApplication::translate("Form3", "Paski", 0, QApplication::UnicodeUTF8));
        linieB->setText(QApplication::translate("Form3", "Linie", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scaleB->setToolTip(QApplication::translate("Form3", "Skala", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pB->setToolTip(QApplication::translate("Form3", "Przesuni\304\231cie FFT dla pask\303\263w", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fullScopeB->setText(QApplication::translate("Form3", "Pe\305\202ne widmo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        refB->setToolTip(QApplication::translate("Form3", "Szybko\305\233\304\207 od\305\233wie\305\274ania (w ms)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        lpaskiB->setToolTip(QApplication::translate("Form3", "Ilo\305\233\304\207 pask\303\263w", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Form3", "ms", 0, QApplication::UnicodeUTF8));
        kreskiB->setText(QApplication::translate("Form3", "Kreski", 0, QApplication::UnicodeUTF8));
        isONB->setText(QApplication::translate("Form3", "W\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
