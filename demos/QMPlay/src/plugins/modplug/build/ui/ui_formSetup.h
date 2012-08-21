/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:17:56 2012
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QCheckBox *enabledB;
    QPushButton *ApplyB;
    QLineEdit *extsB;
    QGroupBox *groupBox;
    QRadioButton *hz44;
    QRadioButton *hz22;
    QRadioButton *hz11;
    QRadioButton *hz8;
    QGroupBox *groupBox_2;
    QRadioButton *r1B;
    QRadioButton *r2B;
    QRadioButton *r3B;
    QRadioButton *r4B;
    QGroupBox *groupBox_3;
    QSpinBox *surround2B;
    QSpinBox *surround1B;
    QCheckBox *surroundB;
    QGroupBox *groupBox_4;
    QSpinBox *reverb1B;
    QSpinBox *reverb2B;
    QCheckBox *reverbB;
    QGroupBox *groupBox_5;
    QSpinBox *bass1B;
    QSpinBox *bass2B;
    QCheckBox *bassB;
    QGroupBox *groupBox_6;
    QCheckBox *loopB;
    QCheckBox *bitsB;
    QCheckBox *stereoB;
    QCheckBox *osB;
    QCheckBox *nrB;
    QGroupBox *groupBox_7;
    QRadioButton *timeB;
    QRadioButton *patternB;
    QSlider *volS;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(425, 370);
        Form3->setMinimumSize(QSize(425, 370));
        Form3->setMaximumSize(QSize(425, 370));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(10, 10, 131, 22));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setGeometry(QRect(180, 310, 191, 31));
        extsB = new QLineEdit(Form3);
        extsB->setObjectName(QString::fromUtf8("extsB"));
        extsB->setGeometry(QRect(20, 30, 211, 23));
        groupBox = new QGroupBox(Form3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 111, 111));
        hz44 = new QRadioButton(groupBox);
        hz44->setObjectName(QString::fromUtf8("hz44"));
        hz44->setGeometry(QRect(10, 20, 91, 23));
        hz22 = new QRadioButton(groupBox);
        hz22->setObjectName(QString::fromUtf8("hz22"));
        hz22->setGeometry(QRect(10, 40, 91, 23));
        hz11 = new QRadioButton(groupBox);
        hz11->setObjectName(QString::fromUtf8("hz11"));
        hz11->setGeometry(QRect(10, 60, 91, 23));
        hz8 = new QRadioButton(groupBox);
        hz8->setObjectName(QString::fromUtf8("hz8"));
        hz8->setGeometry(QRect(10, 80, 91, 23));
        groupBox_2 = new QGroupBox(Form3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 60, 101, 111));
        r1B = new QRadioButton(groupBox_2);
        r1B->setObjectName(QString::fromUtf8("r1B"));
        r1B->setGeometry(QRect(10, 20, 81, 23));
        r2B = new QRadioButton(groupBox_2);
        r2B->setObjectName(QString::fromUtf8("r2B"));
        r2B->setGeometry(QRect(10, 40, 81, 23));
        r3B = new QRadioButton(groupBox_2);
        r3B->setObjectName(QString::fromUtf8("r3B"));
        r3B->setGeometry(QRect(10, 60, 81, 23));
        r4B = new QRadioButton(groupBox_2);
        r4B->setObjectName(QString::fromUtf8("r4B"));
        r4B->setGeometry(QRect(10, 80, 81, 23));
        groupBox_3 = new QGroupBox(Form3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 180, 121, 101));
        surround2B = new QSpinBox(groupBox_3);
        surround2B->setObjectName(QString::fromUtf8("surround2B"));
        surround2B->setGeometry(QRect(30, 70, 81, 23));
        surround2B->setMinimum(5);
        surround2B->setMaximum(40);
        surround2B->setValue(30);
        surround1B = new QSpinBox(groupBox_3);
        surround1B->setObjectName(QString::fromUtf8("surround1B"));
        surround1B->setGeometry(QRect(30, 40, 81, 23));
        surround1B->setMaximum(100);
        surround1B->setValue(50);
        surroundB = new QCheckBox(groupBox_3);
        surroundB->setObjectName(QString::fromUtf8("surroundB"));
        surroundB->setGeometry(QRect(10, 14, 51, 22));
        groupBox_4 = new QGroupBox(Form3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(140, 180, 121, 101));
        reverb1B = new QSpinBox(groupBox_4);
        reverb1B->setObjectName(QString::fromUtf8("reverb1B"));
        reverb1B->setGeometry(QRect(30, 40, 81, 23));
        reverb1B->setMaximum(100);
        reverb1B->setValue(50);
        reverb2B = new QSpinBox(groupBox_4);
        reverb2B->setObjectName(QString::fromUtf8("reverb2B"));
        reverb2B->setGeometry(QRect(30, 70, 81, 23));
        reverb2B->setMinimum(40);
        reverb2B->setMaximum(200);
        reverb2B->setValue(100);
        reverbB = new QCheckBox(groupBox_4);
        reverbB->setObjectName(QString::fromUtf8("reverbB"));
        reverbB->setGeometry(QRect(10, 14, 51, 22));
        groupBox_5 = new QGroupBox(Form3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 180, 111, 101));
        bass1B = new QSpinBox(groupBox_5);
        bass1B->setObjectName(QString::fromUtf8("bass1B"));
        bass1B->setGeometry(QRect(20, 40, 81, 23));
        bass1B->setMinimum(0);
        bass1B->setMaximum(100);
        bass1B->setValue(50);
        bass2B = new QSpinBox(groupBox_5);
        bass2B->setObjectName(QString::fromUtf8("bass2B"));
        bass2B->setGeometry(QRect(20, 70, 81, 23));
        bass2B->setMinimum(10);
        bass2B->setMaximum(100);
        bass2B->setValue(50);
        bassB = new QCheckBox(groupBox_5);
        bassB->setObjectName(QString::fromUtf8("bassB"));
        bassB->setGeometry(QRect(10, 14, 51, 20));
        groupBox_6 = new QGroupBox(Form3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(250, 30, 141, 141));
        loopB = new QCheckBox(groupBox_6);
        loopB->setObjectName(QString::fromUtf8("loopB"));
        loopB->setGeometry(QRect(10, 110, 71, 22));
        bitsB = new QCheckBox(groupBox_6);
        bitsB->setObjectName(QString::fromUtf8("bitsB"));
        bitsB->setGeometry(QRect(10, 90, 71, 22));
        stereoB = new QCheckBox(groupBox_6);
        stereoB->setObjectName(QString::fromUtf8("stereoB"));
        stereoB->setGeometry(QRect(10, 70, 71, 22));
        osB = new QCheckBox(groupBox_6);
        osB->setObjectName(QString::fromUtf8("osB"));
        osB->setGeometry(QRect(10, 20, 121, 22));
        nrB = new QCheckBox(groupBox_6);
        nrB->setObjectName(QString::fromUtf8("nrB"));
        nrB->setGeometry(QRect(10, 40, 121, 22));
        groupBox_7 = new QGroupBox(Form3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 290, 111, 71));
        timeB = new QRadioButton(groupBox_7);
        timeB->setObjectName(QString::fromUtf8("timeB"));
        timeB->setGeometry(QRect(10, 20, 81, 23));
        patternB = new QRadioButton(groupBox_7);
        patternB->setObjectName(QString::fromUtf8("patternB"));
        patternB->setGeometry(QRect(10, 40, 81, 23));
        volS = new QSlider(Form3);
        volS->setObjectName(QString::fromUtf8("volS"));
        volS->setGeometry(QRect(400, 40, 16, 321));
        volS->setMinimum(1);
        volS->setMaximum(255);
        volS->setValue(255);
        volS->setOrientation(Qt::Vertical);
        QWidget::setTabOrder(enabledB, extsB);
        QWidget::setTabOrder(extsB, volS);
        QWidget::setTabOrder(volS, hz44);
        QWidget::setTabOrder(hz44, hz22);
        QWidget::setTabOrder(hz22, hz11);
        QWidget::setTabOrder(hz11, hz8);
        QWidget::setTabOrder(hz8, r1B);
        QWidget::setTabOrder(r1B, r2B);
        QWidget::setTabOrder(r2B, r3B);
        QWidget::setTabOrder(r3B, r4B);
        QWidget::setTabOrder(r4B, osB);
        QWidget::setTabOrder(osB, nrB);
        QWidget::setTabOrder(nrB, stereoB);
        QWidget::setTabOrder(stereoB, bitsB);
        QWidget::setTabOrder(bitsB, loopB);
        QWidget::setTabOrder(loopB, bassB);
        QWidget::setTabOrder(bassB, bass1B);
        QWidget::setTabOrder(bass1B, bass2B);
        QWidget::setTabOrder(bass2B, reverbB);
        QWidget::setTabOrder(reverbB, reverb1B);
        QWidget::setTabOrder(reverb1B, reverb2B);
        QWidget::setTabOrder(reverb2B, surroundB);
        QWidget::setTabOrder(surroundB, surround1B);
        QWidget::setTabOrder(surround1B, surround2B);
        QWidget::setTabOrder(surround2B, timeB);
        QWidget::setTabOrder(timeB, patternB);
        QWidget::setTabOrder(patternB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        extsB->setToolTip(QApplication::translate("Form3", "Obs\305\202ugiwane rozszerzenia plik\303\263w", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("Form3", "Samplerate", 0, QApplication::UnicodeUTF8));
        hz44->setText(QApplication::translate("Form3", "44100Hz", 0, QApplication::UnicodeUTF8));
        hz22->setText(QApplication::translate("Form3", "22050Hz", 0, QApplication::UnicodeUTF8));
        hz11->setText(QApplication::translate("Form3", "11025Hz", 0, QApplication::UnicodeUTF8));
        hz8->setText(QApplication::translate("Form3", "8000Hz", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Form3", "Resampling", 0, QApplication::UnicodeUTF8));
        r1B->setText(QApplication::translate("Form3", "Nearest", 0, QApplication::UnicodeUTF8));
        r2B->setText(QApplication::translate("Form3", "Linear", 0, QApplication::UnicodeUTF8));
        r3B->setText(QApplication::translate("Form3", "Spline", 0, QApplication::UnicodeUTF8));
        r4B->setText(QApplication::translate("Form3", "Fir", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Form3", "Surround", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        surround2B->setToolTip(QApplication::translate("Form3", "Surround delays", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        surround1B->setToolTip(QApplication::translate("Form3", "Surround level", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        surroundB->setText(QApplication::translate("Form3", "On", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Form3", "Reverb", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reverb1B->setToolTip(QApplication::translate("Form3", "Reverb level", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        reverb2B->setToolTip(QApplication::translate("Form3", "Reverb delay", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        reverbB->setText(QApplication::translate("Form3", "On", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Form3", "Bass", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        bass1B->setToolTip(QApplication::translate("Form3", "XBass level", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        bass2B->setToolTip(QApplication::translate("Form3", "XBass cutoff in Hz", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bassB->setText(QApplication::translate("Form3", "On", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("Form3", "Inne opcje d\305\272wi\304\231ku", 0, QApplication::UnicodeUTF8));
        loopB->setText(QApplication::translate("Form3", "Loop", 0, QApplication::UnicodeUTF8));
        bitsB->setText(QApplication::translate("Form3", "16bit", 0, QApplication::UnicodeUTF8));
        stereoB->setText(QApplication::translate("Form3", "Stereo", 0, QApplication::UnicodeUTF8));
        osB->setText(QApplication::translate("Form3", "Oversampling", 0, QApplication::UnicodeUTF8));
        nrB->setText(QApplication::translate("Form3", "Noise reduction", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("Form3", "Ustaw suwak na:", 0, QApplication::UnicodeUTF8));
        timeB->setText(QApplication::translate("Form3", "Czas [s]", 0, QApplication::UnicodeUTF8));
        patternB->setText(QApplication::translate("Form3", "Pattern", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        volS->setToolTip(QApplication::translate("Form3", "G\305\202o\305\233no\305\233\304\207", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
