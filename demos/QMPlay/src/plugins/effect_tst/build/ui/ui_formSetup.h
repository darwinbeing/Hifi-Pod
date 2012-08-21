/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 19:58:18 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QCheckBox *echoB;
    QCheckBox *voiceB;
    QCheckBox *skipB;
    QCheckBox *szybkoB;
    QGroupBox *groupBox;
    QSlider *e1s;
    QSlider *e2s;
    QSlider *e3s;
    QCheckBox *surroundB;
    QGroupBox *groupBox_2;
    QSlider *p1s;
    QSlider *p2s;
    QGroupBox *groupBox_3;
    QRadioButton *mniejB;
    QRadioButton *wiecejB;
    QGroupBox *groupBox_4;
    QRadioButton *i0;
    QRadioButton *i1;
    QRadioButton *i2;
    QRadioButton *i3;
    QCheckBox *wolnoB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(557, 175);
        Form3->setMinimumSize(QSize(557, 175));
        Form3->setMaximumSize(QSize(557, 175));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 131, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(10, 146, 121, 21));
        echoB = new QCheckBox(Form3);
        echoB->setObjectName(QString::fromUtf8("echoB"));
        echoB->setGeometry(QRect(20, 40, 61, 22));
        voiceB = new QCheckBox(Form3);
        voiceB->setObjectName(QString::fromUtf8("voiceB"));
        voiceB->setGeometry(QRect(20, 60, 131, 22));
        skipB = new QCheckBox(Form3);
        skipB->setObjectName(QString::fromUtf8("skipB"));
        skipB->setGeometry(QRect(20, 120, 131, 22));
        szybkoB = new QCheckBox(Form3);
        szybkoB->setObjectName(QString::fromUtf8("szybkoB"));
        szybkoB->setGeometry(QRect(20, 80, 91, 22));
        groupBox = new QGroupBox(Form3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(150, 0, 131, 171));
        e1s = new QSlider(groupBox);
        e1s->setObjectName(QString::fromUtf8("e1s"));
        e1s->setGeometry(QRect(10, 20, 31, 91));
        e1s->setMinimum(1);
        e1s->setMaximum(1000);
        e1s->setOrientation(Qt::Vertical);
        e1s->setTickPosition(QSlider::TicksBelow);
        e1s->setTickInterval(100);
        e2s = new QSlider(groupBox);
        e2s->setObjectName(QString::fromUtf8("e2s"));
        e2s->setGeometry(QRect(50, 20, 31, 91));
        e2s->setMinimum(1);
        e2s->setMaximum(100);
        e2s->setOrientation(Qt::Vertical);
        e2s->setTickPosition(QSlider::TicksBelow);
        e2s->setTickInterval(10);
        e3s = new QSlider(groupBox);
        e3s->setObjectName(QString::fromUtf8("e3s"));
        e3s->setGeometry(QRect(90, 20, 31, 91));
        e3s->setMinimum(1);
        e3s->setMaximum(100);
        e3s->setOrientation(Qt::Vertical);
        e3s->setTickPosition(QSlider::TicksBelow);
        e3s->setTickInterval(10);
        surroundB = new QCheckBox(groupBox);
        surroundB->setObjectName(QString::fromUtf8("surroundB"));
        surroundB->setGeometry(QRect(20, 130, 91, 22));
        groupBox_2 = new QGroupBox(Form3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 0, 111, 91));
        p1s = new QSlider(groupBox_2);
        p1s->setObjectName(QString::fromUtf8("p1s"));
        p1s->setGeometry(QRect(20, 20, 31, 61));
        p1s->setMinimum(2);
        p1s->setOrientation(Qt::Vertical);
        p1s->setTickPosition(QSlider::TicksBelow);
        p1s->setTickInterval(10);
        p2s = new QSlider(groupBox_2);
        p2s->setObjectName(QString::fromUtf8("p2s"));
        p2s->setGeometry(QRect(60, 20, 31, 61));
        p2s->setMinimum(2);
        p2s->setOrientation(Qt::Vertical);
        p2s->setTickPosition(QSlider::TicksBelow);
        p2s->setTickInterval(10);
        groupBox_3 = new QGroupBox(Form3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 90, 111, 81));
        mniejB = new QRadioButton(groupBox_3);
        mniejB->setObjectName(QString::fromUtf8("mniejB"));
        mniejB->setGeometry(QRect(10, 25, 81, 23));
        wiecejB = new QRadioButton(groupBox_3);
        wiecejB->setObjectName(QString::fromUtf8("wiecejB"));
        wiecejB->setGeometry(QRect(10, 45, 81, 23));
        groupBox_4 = new QGroupBox(Form3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(410, 0, 141, 171));
        i0 = new QRadioButton(groupBox_4);
        i0->setObjectName(QString::fromUtf8("i0"));
        i0->setGeometry(QRect(10, 30, 121, 23));
        i1 = new QRadioButton(groupBox_4);
        i1->setObjectName(QString::fromUtf8("i1"));
        i1->setGeometry(QRect(10, 60, 121, 23));
        i2 = new QRadioButton(groupBox_4);
        i2->setObjectName(QString::fromUtf8("i2"));
        i2->setGeometry(QRect(10, 90, 121, 23));
        i3 = new QRadioButton(groupBox_4);
        i3->setObjectName(QString::fromUtf8("i3"));
        i3->setGeometry(QRect(10, 120, 121, 23));
        wolnoB = new QCheckBox(Form3);
        wolnoB->setObjectName(QString::fromUtf8("wolnoB"));
        wolnoB->setGeometry(QRect(20, 100, 81, 22));
        QWidget::setTabOrder(enabledB, echoB);
        QWidget::setTabOrder(echoB, voiceB);
        QWidget::setTabOrder(voiceB, szybkoB);
        QWidget::setTabOrder(szybkoB, wolnoB);
        QWidget::setTabOrder(wolnoB, skipB);
        QWidget::setTabOrder(skipB, e1s);
        QWidget::setTabOrder(e1s, e2s);
        QWidget::setTabOrder(e2s, e3s);
        QWidget::setTabOrder(e3s, surroundB);
        QWidget::setTabOrder(surroundB, p1s);
        QWidget::setTabOrder(p1s, p2s);
        QWidget::setTabOrder(p2s, mniejB);
        QWidget::setTabOrder(mniejB, wiecejB);
        QWidget::setTabOrder(wiecejB, i0);
        QWidget::setTabOrder(i0, i1);
        QWidget::setTabOrder(i1, i2);
        QWidget::setTabOrder(i2, i3);
        QWidget::setTabOrder(i3, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        echoB->setText(QApplication::translate("Form3", "Echo", 0, QApplication::UnicodeUTF8));
        voiceB->setText(QApplication::translate("Form3", "Usuwanie g\305\202osu", 0, QApplication::UnicodeUTF8));
        skipB->setText(QApplication::translate("Form3", "Przeskakiwanie", 0, QApplication::UnicodeUTF8));
        szybkoB->setText(QApplication::translate("Form3", "Szybciej", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form3", "Echo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        e1s->setToolTip(QApplication::translate("Form3", "Op\303\263\305\272nienie", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        e2s->setToolTip(QApplication::translate("Form3", "Powtarzanie", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        e3s->setToolTip(QApplication::translate("Form3", "G\305\202o\305\233no\305\233\304\207 echa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        surroundB->setText(QApplication::translate("Form3", "Surround", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Form3", "Skipping", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        p1s->setToolTip(QApplication::translate("Form3", "Odtwarzanie", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        p2s->setToolTip(QApplication::translate("Form3", "Pomijanie", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("Form3", "Usuwanie g\305\202osu", 0, QApplication::UnicodeUTF8));
        mniejB->setText(QApplication::translate("Form3", "Mniej", 0, QApplication::UnicodeUTF8));
        wiecejB->setText(QApplication::translate("Form3", "Wi\304\231cej", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Form3", "Odwracanie pr\303\263bek", 0, QApplication::UnicodeUTF8));
        i0->setText(QApplication::translate("Form3", "Nie odwracaj", 0, QApplication::UnicodeUTF8));
        i1->setText(QApplication::translate("Form3", "Odwr\303\263\304\207 lewy", 0, QApplication::UnicodeUTF8));
        i2->setText(QApplication::translate("Form3", "Odwr\303\263\304\207 prawy", 0, QApplication::UnicodeUTF8));
        i3->setText(QApplication::translate("Form3", "Odwr\303\263\304\207 oba", 0, QApplication::UnicodeUTF8));
        wolnoB->setText(QApplication::translate("Form3", "Wolniej", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
