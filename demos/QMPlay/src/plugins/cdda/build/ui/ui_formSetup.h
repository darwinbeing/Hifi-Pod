/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 19:54:53 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QSpinBox *speedB;
    QLabel *label;
    QPushButton *trackB;
    QLineEdit *driveE;
    QComboBox *driveB;
    QPushButton *ejectB;
    QPushButton *closeTB;
    QCheckBox *canCloseTB;
    QCheckBox *useCDDBB;
    QFrame *frame;
    QRadioButton *qmpCacheB;
    QRadioButton *defCacheB;
    QGroupBox *groupBox;
    QRadioButton *useFDBB;
    QLineEdit *userDatabaseServerB;
    QRadioButton *useUserDatabaseB;
    QCheckBox *useCddbpB;
    QCheckBox *clrB;
    QCheckBox *readCDTXTB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(450, 390);
        Form3->setMinimumSize(QSize(450, 390));
        Form3->setMaximumSize(QSize(450, 390));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 131, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(10, 360, 431, 25));
        speedB = new QSpinBox(Form3);
        speedB->setObjectName(QString::fromUtf8("speedB"));
        speedB->setGeometry(QRect(20, 95, 61, 23));
        speedB->setMinimum(1);
        speedB->setMaximum(52);
        speedB->setValue(1);
        label = new QLabel(Form3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 100, 21, 17));
        trackB = new QPushButton(Form3);
        trackB->setObjectName(QString::fromUtf8("trackB"));
        trackB->setGeometry(QRect(280, 35, 111, 51));
        driveE = new QLineEdit(Form3);
        driveE->setObjectName(QString::fromUtf8("driveE"));
        driveE->setGeometry(QRect(20, 65, 131, 21));
        driveB = new QComboBox(Form3);
        driveB->setObjectName(QString::fromUtf8("driveB"));
        driveB->setGeometry(QRect(20, 35, 131, 23));
        ejectB = new QPushButton(Form3);
        ejectB->setObjectName(QString::fromUtf8("ejectB"));
        ejectB->setGeometry(QRect(160, 35, 111, 21));
        closeTB = new QPushButton(Form3);
        closeTB->setObjectName(QString::fromUtf8("closeTB"));
        closeTB->setGeometry(QRect(160, 65, 111, 21));
        canCloseTB = new QCheckBox(Form3);
        canCloseTB->setObjectName(QString::fromUtf8("canCloseTB"));
        canCloseTB->setGeometry(QRect(20, 145, 251, 22));
        useCDDBB = new QCheckBox(Form3);
        useCDDBB->setObjectName(QString::fromUtf8("useCDDBB"));
        useCDDBB->setGeometry(QRect(20, 170, 131, 22));
        frame = new QFrame(Form3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 195, 411, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        qmpCacheB = new QRadioButton(frame);
        qmpCacheB->setObjectName(QString::fromUtf8("qmpCacheB"));
        qmpCacheB->setGeometry(QRect(10, 50, 211, 31));
        defCacheB = new QRadioButton(frame);
        defCacheB->setObjectName(QString::fromUtf8("defCacheB"));
        defCacheB->setGeometry(QRect(10, 10, 211, 31));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(230, 10, 171, 141));
        useFDBB = new QRadioButton(groupBox);
        useFDBB->setObjectName(QString::fromUtf8("useFDBB"));
        useFDBB->setGeometry(QRect(10, 20, 141, 23));
        userDatabaseServerB = new QLineEdit(groupBox);
        userDatabaseServerB->setObjectName(QString::fromUtf8("userDatabaseServerB"));
        userDatabaseServerB->setGeometry(QRect(20, 100, 141, 23));
        useUserDatabaseB = new QRadioButton(groupBox);
        useUserDatabaseB->setObjectName(QString::fromUtf8("useUserDatabaseB"));
        useUserDatabaseB->setGeometry(QRect(10, 50, 141, 23));
        useCddbpB = new QCheckBox(groupBox);
        useCddbpB->setObjectName(QString::fromUtf8("useCddbpB"));
        useCddbpB->setGeometry(QRect(20, 75, 111, 22));
        clrB = new QCheckBox(Form3);
        clrB->setObjectName(QString::fromUtf8("clrB"));
        clrB->setGeometry(QRect(20, 120, 291, 22));
        readCDTXTB = new QCheckBox(Form3);
        readCDTXTB->setObjectName(QString::fromUtf8("readCDTXTB"));
        readCDTXTB->setGeometry(QRect(120, 95, 161, 22));
        QWidget::setTabOrder(enabledB, driveB);
        QWidget::setTabOrder(driveB, driveE);
        QWidget::setTabOrder(driveE, speedB);
        QWidget::setTabOrder(speedB, clrB);
        QWidget::setTabOrder(clrB, canCloseTB);
        QWidget::setTabOrder(canCloseTB, useCDDBB);
        QWidget::setTabOrder(useCDDBB, readCDTXTB);
        QWidget::setTabOrder(readCDTXTB, defCacheB);
        QWidget::setTabOrder(defCacheB, qmpCacheB);
        QWidget::setTabOrder(qmpCacheB, useFDBB);
        QWidget::setTabOrder(useFDBB, useUserDatabaseB);
        QWidget::setTabOrder(useUserDatabaseB, useCddbpB);
        QWidget::setTabOrder(useCddbpB, userDatabaseServerB);
        QWidget::setTabOrder(userDatabaseServerB, ejectB);
        QWidget::setTabOrder(ejectB, closeTB);
        QWidget::setTabOrder(closeTB, trackB);
        QWidget::setTabOrder(trackB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        speedB->setToolTip(QApplication::translate("Form3", "Szybko\305\233\304\207 odczytu p\305\202yty", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Form3", "x", 0, QApplication::UnicodeUTF8));
        trackB->setText(QApplication::translate("Form3", "Dodaj \305\233cie\305\274ki z\n"
"p\305\202yty do listy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        driveE->setToolTip(QApplication::translate("Form3", "\305\232cie\305\274ka do nap\304\231du CD albo obrazu p\305\202yty", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        driveB->setToolTip(QApplication::translate("Form3", "Tutaj wybierasz sw\303\263j nap\304\231d CD", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ejectB->setText(QApplication::translate("Form3", "Wysu\305\204 tack\304\231", 0, QApplication::UnicodeUTF8));
        closeTB->setText(QApplication::translate("Form3", "Wsu\305\204 tack\304\231", 0, QApplication::UnicodeUTF8));
        canCloseTB->setText(QApplication::translate("Form3", "Wsuwaj tack\304\231 CD podczas odczytu", 0, QApplication::UnicodeUTF8));
        useCDDBB->setText(QApplication::translate("Form3", "U\305\274ywaj CDDB", 0, QApplication::UnicodeUTF8));
        qmpCacheB->setText(QApplication::translate("Form3", "Umie\305\233\304\207 pami\304\231\304\207 podr\304\231czn\304\205\n"
"CDDB w katalogu z QMPlay", 0, QApplication::UnicodeUTF8));
        defCacheB->setText(QApplication::translate("Form3", "U\305\274yj domy\305\233lnej lokalizacji dla\n"
"pami\304\231ci podr\304\231cznej CDDB", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form3", "Baza danych CDDB", 0, QApplication::UnicodeUTF8));
        useFDBB->setText(QApplication::translate("Form3", "U\305\274yj freedb.org", 0, QApplication::UnicodeUTF8));
        useUserDatabaseB->setText(QApplication::translate("Form3", "U\305\274yj w\305\202asnej", 0, QApplication::UnicodeUTF8));
        useCddbpB->setText(QApplication::translate("Form3", "U\305\274yj Cddbp", 0, QApplication::UnicodeUTF8));
        clrB->setText(QApplication::translate("Form3", "Czy\305\233\304\207 list\304\231 podczas dodawania AudioCD", 0, QApplication::UnicodeUTF8));
        readCDTXTB->setText(QApplication::translate("Form3", "Odczytuj CD-TEXT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
