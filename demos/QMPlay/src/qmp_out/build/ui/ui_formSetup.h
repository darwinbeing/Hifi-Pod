/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 08:06:46 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QGridLayout *gridLayout;
    QPushButton *ApplyB;
    QTabWidget *tabWidget;
    QWidget *tab;
    QSlider *sR;
    QCheckBox *bB;
    QCheckBox *playSB;
    QCheckBox *playSExB;
    QCheckBox *visEffB;
    QCheckBox *titleEB;
    QRadioButton *chChnB;
    QCheckBox *savEffB;
    QCheckBox *zChnB;
    QLabel *label_3;
    QSlider *pSL;
    QRadioButton *chChn2B;
    QLabel *label_4;
    QRadioButton *chChnNotB;
    QLabel *label_2;
    QCheckBox *volB;
    QSlider *sL;
    QCheckBox *bEffB;
    QLabel *label;
    QCheckBox *silenceB;
    QWidget *tab_2;
    QCheckBox *userBitsB;
    QGroupBox *bitsB;
    QRadioButton *bits8B;
    QRadioButton *bits16B;
    QRadioButton *bits24B;
    QRadioButton *bits32B;
    QCheckBox *userRateB;
    QCheckBox *userChnB;
    QSpinBox *rateB;
    QSpinBox *chnB;
    QLabel *label_5;
    QLabel *bsL;
    QCheckBox *buffQB;
    QLabel *mbsL;
    QLabel *label_8;
    QCheckBox *titleHB;
    QCheckBox *titleB;
    QLabel *label_6;
    QSpinBox *soundBB;
    QSpinBox *QBufB;
    QLabel *label_7;
    QLabel *label_9;
    QCheckBox *buffQIfNeadedB;
    QLabel *label_10;
    QLabel *bufQL;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(540, 330);
        Form3->setMinimumSize(QSize(540, 330));
        Form3->setMaximumSize(QSize(540, 330));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form3);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setMaximumSize(QSize(16777215, 22));

        gridLayout->addWidget(ApplyB, 1, 0, 1, 1);

        tabWidget = new QTabWidget(Form3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sR = new QSlider(tab);
        sR->setObjectName(QString::fromUtf8("sR"));
        sR->setGeometry(QRect(490, 10, 25, 91));
        sR->setCursor(QCursor(Qt::PointingHandCursor));
        sR->setFocusPolicy(Qt::WheelFocus);
        sR->setMaximum(100);
        sR->setValue(100);
        sR->setOrientation(Qt::Vertical);
        bB = new QCheckBox(tab);
        bB->setObjectName(QString::fromUtf8("bB"));
        bB->setGeometry(QRect(360, 60, 91, 51));
        bB->setCursor(QCursor(Qt::PointingHandCursor));
        playSB = new QCheckBox(tab);
        playSB->setObjectName(QString::fromUtf8("playSB"));
        playSB->setGeometry(QRect(10, 70, 141, 22));
        playSB->setCursor(QCursor(Qt::PointingHandCursor));
        playSExB = new QCheckBox(tab);
        playSExB->setObjectName(QString::fromUtf8("playSExB"));
        playSExB->setGeometry(QRect(20, 90, 321, 22));
        playSExB->setCursor(QCursor(Qt::PointingHandCursor));
        visEffB = new QCheckBox(tab);
        visEffB->setObjectName(QString::fromUtf8("visEffB"));
        visEffB->setGeometry(QRect(10, 50, 331, 22));
        visEffB->setCursor(QCursor(Qt::PointingHandCursor));
        titleEB = new QCheckBox(tab);
        titleEB->setObjectName(QString::fromUtf8("titleEB"));
        titleEB->setGeometry(QRect(10, 230, 461, 22));
        titleEB->setCursor(QCursor(Qt::PointingHandCursor));
        chChnB = new QRadioButton(tab);
        chChnB->setObjectName(QString::fromUtf8("chChnB"));
        chChnB->setGeometry(QRect(10, 130, 161, 25));
        chChnB->setCursor(QCursor(Qt::PointingHandCursor));
        savEffB = new QCheckBox(tab);
        savEffB->setObjectName(QString::fromUtf8("savEffB"));
        savEffB->setGeometry(QRect(10, 30, 371, 22));
        savEffB->setCursor(QCursor(Qt::PointingHandCursor));
        zChnB = new QCheckBox(tab);
        zChnB->setObjectName(QString::fromUtf8("zChnB"));
        zChnB->setGeometry(QRect(10, 190, 211, 22));
        zChnB->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 164, 131, 20));
        pSL = new QSlider(tab);
        pSL->setObjectName(QString::fromUtf8("pSL"));
        pSL->setGeometry(QRect(290, 122, 31, 102));
        pSL->setCursor(QCursor(Qt::PointingHandCursor));
        pSL->setMaximum(2);
        pSL->setValue(1);
        pSL->setOrientation(Qt::Vertical);
        pSL->setTickPosition(QSlider::TicksBelow);
        chChn2B = new QRadioButton(tab);
        chChn2B->setObjectName(QString::fromUtf8("chChn2B"));
        chChn2B->setGeometry(QRect(10, 150, 161, 25));
        chChn2B->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 119, 191, 21));
        chChnNotB = new QRadioButton(tab);
        chChnNotB->setObjectName(QString::fromUtf8("chChnNotB"));
        chChnNotB->setGeometry(QRect(10, 110, 111, 25));
        chChnNotB->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 210, 131, 20));
        volB = new QCheckBox(tab);
        volB->setObjectName(QString::fromUtf8("volB"));
        volB->setGeometry(QRect(10, 10, 291, 22));
        volB->setCursor(QCursor(Qt::PointingHandCursor));
        sL = new QSlider(tab);
        sL->setObjectName(QString::fromUtf8("sL"));
        sL->setGeometry(QRect(460, 10, 25, 91));
        sL->setCursor(QCursor(Qt::PointingHandCursor));
        sL->setFocusPolicy(Qt::WheelFocus);
        sL->setMaximum(100);
        sL->setValue(100);
        sL->setOrientation(Qt::Vertical);
        bEffB = new QCheckBox(tab);
        bEffB->setObjectName(QString::fromUtf8("bEffB"));
        bEffB->setGeometry(QRect(10, 170, 241, 21));
        bEffB->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 20, 61, 41));
        silenceB = new QCheckBox(tab);
        silenceB->setObjectName(QString::fromUtf8("silenceB"));
        silenceB->setGeometry(QRect(10, 210, 251, 22));
        silenceB->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        userBitsB = new QCheckBox(tab_2);
        userBitsB->setObjectName(QString::fromUtf8("userBitsB"));
        userBitsB->setGeometry(QRect(10, 130, 221, 22));
        userBitsB->setCursor(QCursor(Qt::PointingHandCursor));
        bitsB = new QGroupBox(tab_2);
        bitsB->setObjectName(QString::fromUtf8("bitsB"));
        bitsB->setGeometry(QRect(20, 160, 131, 71));
        bits8B = new QRadioButton(bitsB);
        bits8B->setObjectName(QString::fromUtf8("bits8B"));
        bits8B->setGeometry(QRect(10, 20, 51, 23));
        bits8B->setCursor(QCursor(Qt::PointingHandCursor));
        bits16B = new QRadioButton(bitsB);
        bits16B->setObjectName(QString::fromUtf8("bits16B"));
        bits16B->setGeometry(QRect(70, 20, 51, 23));
        bits16B->setCursor(QCursor(Qt::PointingHandCursor));
        bits16B->setChecked(true);
        bits24B = new QRadioButton(bitsB);
        bits24B->setObjectName(QString::fromUtf8("bits24B"));
        bits24B->setGeometry(QRect(10, 40, 51, 23));
        bits24B->setCursor(QCursor(Qt::PointingHandCursor));
        bits32B = new QRadioButton(bitsB);
        bits32B->setObjectName(QString::fromUtf8("bits32B"));
        bits32B->setGeometry(QRect(70, 40, 51, 23));
        bits32B->setCursor(QCursor(Qt::PointingHandCursor));
        userRateB = new QCheckBox(tab_2);
        userRateB->setObjectName(QString::fromUtf8("userRateB"));
        userRateB->setGeometry(QRect(10, 10, 261, 22));
        userRateB->setCursor(QCursor(Qt::PointingHandCursor));
        userChnB = new QCheckBox(tab_2);
        userChnB->setObjectName(QString::fromUtf8("userChnB"));
        userChnB->setGeometry(QRect(10, 70, 171, 22));
        userChnB->setCursor(QCursor(Qt::PointingHandCursor));
        rateB = new QSpinBox(tab_2);
        rateB->setObjectName(QString::fromUtf8("rateB"));
        rateB->setGeometry(QRect(20, 40, 81, 23));
        rateB->setMinimum(4000);
        rateB->setMaximum(384000);
        rateB->setValue(44100);
        chnB = new QSpinBox(tab_2);
        chnB->setObjectName(QString::fromUtf8("chnB"));
        chnB->setGeometry(QRect(20, 100, 81, 23));
        chnB->setMinimum(1);
        chnB->setMaximum(2);
        chnB->setValue(2);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 10, 171, 17));
        bsL = new QLabel(tab_2);
        bsL->setObjectName(QString::fromUtf8("bsL"));
        bsL->setGeometry(QRect(450, 10, 61, 17));
        buffQB = new QCheckBox(tab_2);
        buffQB->setObjectName(QString::fromUtf8("buffQB"));
        buffQB->setGeometry(QRect(270, 70, 201, 22));
        buffQB->setCursor(QCursor(Qt::PointingHandCursor));
        mbsL = new QLabel(tab_2);
        mbsL->setObjectName(QString::fromUtf8("mbsL"));
        mbsL->setGeometry(QRect(450, 30, 61, 17));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 30, 171, 17));
        titleHB = new QCheckBox(tab_2);
        titleHB->setObjectName(QString::fromUtf8("titleHB"));
        titleHB->setGeometry(QRect(200, 190, 311, 22));
        titleHB->setCursor(QCursor(Qt::PointingHandCursor));
        titleB = new QCheckBox(tab_2);
        titleB->setObjectName(QString::fromUtf8("titleB"));
        titleB->setGeometry(QRect(190, 170, 311, 22));
        titleB->setCursor(QCursor(Qt::PointingHandCursor));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 145, 171, 20));
        soundBB = new QSpinBox(tab_2);
        soundBB->setObjectName(QString::fromUtf8("soundBB"));
        soundBB->setGeometry(QRect(440, 141, 41, 23));
        soundBB->setMinimum(1);
        soundBB->setMaximum(8);
        soundBB->setValue(4);
        QBufB = new QSpinBox(tab_2);
        QBufB->setObjectName(QString::fromUtf8("QBufB"));
        QBufB->setGeometry(QRect(300, 110, 41, 23));
        QBufB->setMinimum(2);
        QBufB->setMaximum(64);
        QBufB->setValue(4);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(485, 145, 16, 20));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(350, 115, 121, 18));
        buffQIfNeadedB = new QCheckBox(tab_2);
        buffQIfNeadedB->setObjectName(QString::fromUtf8("buffQIfNeadedB"));
        buffQIfNeadedB->setGeometry(QRect(300, 90, 211, 22));
        buffQIfNeadedB->setCursor(QCursor(Qt::PointingHandCursor));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(270, 50, 171, 18));
        bufQL = new QLabel(tab_2);
        bufQL->setObjectName(QString::fromUtf8("bufQL"));
        bufQL->setGeometry(QRect(450, 50, 62, 18));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(tabWidget, volB);
        QWidget::setTabOrder(volB, savEffB);
        QWidget::setTabOrder(savEffB, visEffB);
        QWidget::setTabOrder(visEffB, playSB);
        QWidget::setTabOrder(playSB, playSExB);
        QWidget::setTabOrder(playSExB, chChnNotB);
        QWidget::setTabOrder(chChnNotB, chChnB);
        QWidget::setTabOrder(chChnB, chChn2B);
        QWidget::setTabOrder(chChn2B, bEffB);
        QWidget::setTabOrder(bEffB, zChnB);
        QWidget::setTabOrder(zChnB, silenceB);
        QWidget::setTabOrder(silenceB, titleEB);
        QWidget::setTabOrder(titleEB, pSL);
        QWidget::setTabOrder(pSL, bB);
        QWidget::setTabOrder(bB, sL);
        QWidget::setTabOrder(sL, sR);
        QWidget::setTabOrder(sR, ApplyB);
        QWidget::setTabOrder(ApplyB, userRateB);
        QWidget::setTabOrder(userRateB, rateB);
        QWidget::setTabOrder(rateB, userChnB);
        QWidget::setTabOrder(userChnB, chnB);
        QWidget::setTabOrder(chnB, userBitsB);
        QWidget::setTabOrder(userBitsB, bits8B);
        QWidget::setTabOrder(bits8B, bits16B);
        QWidget::setTabOrder(bits16B, bits24B);
        QWidget::setTabOrder(bits24B, bits32B);
        QWidget::setTabOrder(bits32B, buffQB);
        QWidget::setTabOrder(buffQB, buffQIfNeadedB);
        QWidget::setTabOrder(buffQIfNeadedB, QBufB);
        QWidget::setTabOrder(QBufB, soundBB);
        QWidget::setTabOrder(soundBB, titleB);
        QWidget::setTabOrder(titleB, titleHB);

        retranslateUi(Form3);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        bB->setText(QApplication::translate("Form3", "Przesuwaj\n"
"razem", 0, QApplication::UnicodeUTF8));
        playSB->setText(QApplication::translate("Form3", "Odtwarzaj d\305\272wi\304\231k", 0, QApplication::UnicodeUTF8));
        playSExB->setText(QApplication::translate("Form3", "Odtwarzaj d\305\272wi\304\231k podczas eksportu do pliku", 0, QApplication::UnicodeUTF8));
        visEffB->setText(QApplication::translate("Form3", "U\305\274ywaj efekt\303\263w d\305\272wi\304\231kowych do wizualizacji", 0, QApplication::UnicodeUTF8));
        titleEB->setText(QApplication::translate("Form3", "Posy\305\202aj do QMPExport tytu\305\202 utworu zamiast nazwy pliku piosenki", 0, QApplication::UnicodeUTF8));
        chChnB->setText(QApplication::translate("Form3", "Zmiksuj do mono", 0, QApplication::UnicodeUTF8));
        savEffB->setText(QApplication::translate("Form3", "Zapisuj efekty d\305\272wi\304\231kowe podczas eksportu do pliku", 0, QApplication::UnicodeUTF8));
        zChnB->setText(QApplication::translate("Form3", "Zamie\305\204 lewy i prawy kana\305\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form3", "Priorytet wy\305\274szy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pSL->setToolTip(QApplication::translate("Form3", "Priorytet w\304\205tku odtwarzaj\304\205cego i nagrywaj\304\205cego", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chChn2B->setText(QApplication::translate("Form3", "Zmiksuj do stereo", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form3", "Priorytet czasu rzeczywistego", 0, QApplication::UnicodeUTF8));
        chChnNotB->setText(QApplication::translate("Form3", "Nie miksuj", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form3", "Priorytet wysoki", 0, QApplication::UnicodeUTF8));
        volB->setText(QApplication::translate("Form3", "U\305\274ywaj g\305\202o\305\233no\305\233ci z QMPout w programie", 0, QApplication::UnicodeUTF8));
        bEffB->setText(QApplication::translate("Form3", "Ustaw g\305\202o\305\233no\305\233\304\207 przed efektami", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form3", "G\305\202o\305\233no\305\233\304\207\n"
"QMPout:", 0, QApplication::UnicodeUTF8));
        silenceB->setText(QApplication::translate("Form3", "Wyciszaj podczas zatrzymywania", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form3", "1", 0, QApplication::UnicodeUTF8));
        userBitsB->setText(QApplication::translate("Form3", "Wymu\305\233 ilo\305\233\304\207 bit\303\263w na pr\303\263bk\304\231:", 0, QApplication::UnicodeUTF8));
        bitsB->setTitle(QApplication::translate("Form3", "Format: Integer", 0, QApplication::UnicodeUTF8));
        bits8B->setText(QApplication::translate("Form3", "8", 0, QApplication::UnicodeUTF8));
        bits16B->setText(QApplication::translate("Form3", "16", 0, QApplication::UnicodeUTF8));
        bits24B->setText(QApplication::translate("Form3", "24", 0, QApplication::UnicodeUTF8));
        bits32B->setText(QApplication::translate("Form3", "32", 0, QApplication::UnicodeUTF8));
        userRateB->setText(QApplication::translate("Form3", "Wymu\305\233 cz\304\231stotliwo\305\233\304\207 pr\303\263bkowania:", 0, QApplication::UnicodeUTF8));
        userChnB->setText(QApplication::translate("Form3", "Wymu\305\233 ilo\305\233\304\207 kana\305\202\303\263w:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form3", "Rozmiar bufora d\305\272wi\304\231ku:", 0, QApplication::UnicodeUTF8));
        bsL->setText(QApplication::translate("Form3", "000000", 0, QApplication::UnicodeUTF8));
        buffQB->setText(QApplication::translate("Form3", "W\305\202\304\205cz dodatkowy bufor", 0, QApplication::UnicodeUTF8));
        mbsL->setText(QApplication::translate("Form3", "000000", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form3", "Rozmiar  bufora w QMP:", 0, QApplication::UnicodeUTF8));
        titleHB->setText(QApplication::translate("Form3", "Pokazuj tylko kiedy g\305\202\303\263wne okno jest ukryte", 0, QApplication::UnicodeUTF8));
        titleB->setText(QApplication::translate("Form3", "Pokazuj powiadomienie o zmianie tytu\305\202u", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form3", "Powieksz bufor d\305\272wi\304\231ku", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form3", "x", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Form3", "x bufor d\305\272wi\304\231ku", 0, QApplication::UnicodeUTF8));
        buffQIfNeadedB->setText(QApplication::translate("Form3", "U\305\274yj tylko kiedy wymagany", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form3", "Dodatkowy bufor QMP:", 0, QApplication::UnicodeUTF8));
        bufQL->setText(QApplication::translate("Form3", "nie", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Form3", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
