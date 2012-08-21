/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:29:53 2012
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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QGridLayout *gridLayout;
    QCheckBox *enabledB;
    QPushButton *addB;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *monoB;
    QRadioButton *stereoB;
    QRadioButton *fourB;
    QRadioButton *sixB;
    QRadioButton *eightB;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *hzB;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *hzB_2;
    QLabel *label_3;
    QLabel *label_6;
    QSpinBox *hzB_3;
    QLabel *label_5;
    QLabel *label_8;
    QSpinBox *hzB_4;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_9;
    QSpinBox *hzB_5;
    QLabel *label_12;
    QSpinBox *hzB_6;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_15;
    QSpinBox *hzB_7;
    QSpinBox *hzB_8;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *ApplyB;
    QSpinBox *srateB;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(341, 294);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(enabledB, 0, 0, 1, 1);

        addB = new QPushButton(Form3);
        addB->setObjectName(QString::fromUtf8("addB"));

        gridLayout->addWidget(addB, 1, 0, 1, 3);

        groupBox = new QGroupBox(Form3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        monoB = new QRadioButton(groupBox);
        monoB->setObjectName(QString::fromUtf8("monoB"));
        monoB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(monoB, 0, 0, 1, 1);

        stereoB = new QRadioButton(groupBox);
        stereoB->setObjectName(QString::fromUtf8("stereoB"));
        stereoB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(stereoB, 1, 0, 1, 1);

        fourB = new QRadioButton(groupBox);
        fourB->setObjectName(QString::fromUtf8("fourB"));
        fourB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(fourB, 2, 0, 1, 1);

        sixB = new QRadioButton(groupBox);
        sixB->setObjectName(QString::fromUtf8("sixB"));
        sixB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(sixB, 3, 0, 1, 1);

        eightB = new QRadioButton(groupBox);
        eightB->setObjectName(QString::fromUtf8("eightB"));
        eightB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(eightB, 4, 0, 1, 1);


        gridLayout->addWidget(groupBox, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(Form3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        hzB = new QSpinBox(groupBox_2);
        hzB->setObjectName(QString::fromUtf8("hzB"));
        hzB->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB->setMaximum(96000);

        gridLayout_2->addWidget(hzB, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        hzB_2 = new QSpinBox(groupBox_2);
        hzB_2->setObjectName(QString::fromUtf8("hzB_2"));
        hzB_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB_2->setMaximum(96000);

        gridLayout_2->addWidget(hzB_2, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        hzB_3 = new QSpinBox(groupBox_2);
        hzB_3->setObjectName(QString::fromUtf8("hzB_3"));
        hzB_3->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB_3->setMaximum(96000);

        gridLayout_2->addWidget(hzB_3, 5, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 5, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 6, 0, 1, 1);

        hzB_4 = new QSpinBox(groupBox_2);
        hzB_4->setObjectName(QString::fromUtf8("hzB_4"));
        hzB_4->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB_4->setMaximum(96000);

        gridLayout_2->addWidget(hzB_4, 7, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 7, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 1, 3, 1, 1);

        hzB_5 = new QSpinBox(groupBox_2);
        hzB_5->setObjectName(QString::fromUtf8("hzB_5"));
        hzB_5->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB_5->setMaximum(96000);

        gridLayout_2->addWidget(hzB_5, 1, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 2, 2, 1, 1);

        hzB_6 = new QSpinBox(groupBox_2);
        hzB_6->setObjectName(QString::fromUtf8("hzB_6"));
        hzB_6->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        hzB_6->setMaximum(96000);

        gridLayout_2->addWidget(hzB_6, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 3, 3, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 4, 2, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 6, 2, 1, 1);

        hzB_7 = new QSpinBox(groupBox_2);
        hzB_7->setObjectName(QString::fromUtf8("hzB_7"));
        hzB_7->setMaximum(96000);

        gridLayout_2->addWidget(hzB_7, 5, 2, 1, 1);

        hzB_8 = new QSpinBox(groupBox_2);
        hzB_8->setObjectName(QString::fromUtf8("hzB_8"));
        hzB_8->setMaximum(96000);

        gridLayout_2->addWidget(hzB_8, 7, 2, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 5, 3, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 7, 3, 1, 1);


        gridLayout->addWidget(groupBox_2, 3, 1, 2, 2);

        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(ApplyB, 4, 0, 1, 1);

        srateB = new QSpinBox(Form3);
        srateB->setObjectName(QString::fromUtf8("srateB"));
        srateB->setMinimum(4000);
        srateB->setMaximum(192000);
        srateB->setValue(44100);

        gridLayout->addWidget(srateB, 2, 1, 1, 1);

        label_13 = new QLabel(Form3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        QWidget::setTabOrder(enabledB, addB);
        QWidget::setTabOrder(addB, srateB);
        QWidget::setTabOrder(srateB, monoB);
        QWidget::setTabOrder(monoB, stereoB);
        QWidget::setTabOrder(stereoB, fourB);
        QWidget::setTabOrder(fourB, sixB);
        QWidget::setTabOrder(sixB, eightB);
        QWidget::setTabOrder(eightB, hzB);
        QWidget::setTabOrder(hzB, hzB_2);
        QWidget::setTabOrder(hzB_2, hzB_3);
        QWidget::setTabOrder(hzB_3, hzB_4);
        QWidget::setTabOrder(hzB_4, hzB_5);
        QWidget::setTabOrder(hzB_5, hzB_6);
        QWidget::setTabOrder(hzB_6, hzB_7);
        QWidget::setTabOrder(hzB_7, hzB_8);
        QWidget::setTabOrder(hzB_8, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        addB->setText(QApplication::translate("Form3", "Dodaj generator ton\303\263w do playlisty", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form3", "Ilo\305\233\304\207 kana\305\202\303\263w:", 0, QApplication::UnicodeUTF8));
        monoB->setText(QApplication::translate("Form3", "Mono", 0, QApplication::UnicodeUTF8));
        stereoB->setText(QApplication::translate("Form3", "Stereo", 0, QApplication::UnicodeUTF8));
        fourB->setText(QApplication::translate("Form3", "4 kana\305\202y", 0, QApplication::UnicodeUTF8));
        sixB->setText(QApplication::translate("Form3", "6 kana\305\202\303\263w", 0, QApplication::UnicodeUTF8));
        eightB->setText(QApplication::translate("Form3", "8 kana\305\202\303\263w", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Form3", "Ton o cz\304\231stotliwo\305\233ci:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form3", "Kana\305\202 1:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form3", "Kana\305\202 2:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form3", "Kana\305\202 3:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form3", "Kana\305\202 4:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form3", "Kana\305\202 5:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Form3", "Kana\305\202 6:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Form3", "Kana\305\202 7:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Form3", "Kana\305\202 8:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Form3", "Hz", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Form3", "Cz\304\231stotliwo\305\233\304\207 pr\303\263bkowania", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
