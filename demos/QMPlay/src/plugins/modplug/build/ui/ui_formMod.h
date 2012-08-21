/********************************************************************************
** Form generated from reading UI file 'formMod.ui'
**
** Created: Tue Aug 21 20:17:56 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMOD_H
#define UI_FORMMOD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QFrame *frame_2;
    QGridLayout *gridLayout1;
    QLabel *titleLabel;
    QLabel *modformatLabel;
    QFrame *okno;
    QFrame *frame;
    QPushButton *closeButton;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *sampleLabel;
    QLabel *patternLabel;
    QLabel *rowLabel;
    QLabel *chanLabel;
    QLabel *instrLabel;
    QLabel *label;
    QLabel *label_3;
    QLabel *spdLabel;
    QLabel *bpmLabel;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName(QString::fromUtf8("Form2"));
        Form2->resize(320, 280);
        Form2->setMinimumSize(QSize(320, 280));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../.designer/backup"), QSize(), QIcon::Normal, QIcon::Off);
        Form2->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form2);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(10, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 2, 1, 1);

        frame_2 = new QFrame(Form2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(16, 40));
        frame_2->setMaximumSize(QSize(16777215, 40));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        gridLayout1 = new QGridLayout(frame_2);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(1, 1, 1, 1);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        titleLabel = new QLabel(frame_2);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        gridLayout1->addWidget(titleLabel, 0, 0, 1, 1);

        modformatLabel = new QLabel(frame_2);
        modformatLabel->setObjectName(QString::fromUtf8("modformatLabel"));

        gridLayout1->addWidget(modformatLabel, 1, 0, 1, 1);


        gridLayout->addWidget(frame_2, 0, 0, 1, 3);

        okno = new QFrame(Form2);
        okno->setObjectName(QString::fromUtf8("okno"));

        gridLayout->addWidget(okno, 2, 0, 1, 3);

        frame = new QFrame(Form2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(300, 115));
        frame->setMaximumSize(QSize(420, 115));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(220, 80, 61, 27));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(9, 30, 130, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(9, 9, 130, 16));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(9, 72, 130, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 93, 130, 16));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(9, 51, 141, 17));
        sampleLabel = new QLabel(frame);
        sampleLabel->setObjectName(QString::fromUtf8("sampleLabel"));
        sampleLabel->setGeometry(QRect(150, 30, 76, 16));
        patternLabel = new QLabel(frame);
        patternLabel->setObjectName(QString::fromUtf8("patternLabel"));
        patternLabel->setGeometry(QRect(150, 10, 76, 16));
        rowLabel = new QLabel(frame);
        rowLabel->setObjectName(QString::fromUtf8("rowLabel"));
        rowLabel->setGeometry(QRect(150, 90, 76, 16));
        chanLabel = new QLabel(frame);
        chanLabel->setObjectName(QString::fromUtf8("chanLabel"));
        chanLabel->setGeometry(QRect(150, 70, 76, 16));
        instrLabel = new QLabel(frame);
        instrLabel->setObjectName(QString::fromUtf8("instrLabel"));
        instrLabel->setGeometry(QRect(150, 50, 76, 16));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 10, 51, 26));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 30, 51, 26));
        spdLabel = new QLabel(frame);
        spdLabel->setObjectName(QString::fromUtf8("spdLabel"));
        spdLabel->setGeometry(QRect(270, 10, 61, 26));
        bpmLabel = new QLabel(frame);
        bpmLabel->setObjectName(QString::fromUtf8("bpmLabel"));
        bpmLabel->setGeometry(QRect(270, 34, 61, 21));

        gridLayout->addWidget(frame, 1, 0, 1, 2);


        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QApplication::translate("Form2", "Module music information", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("Form2", "Brak odtwarzanej muzyki", 0, QApplication::UnicodeUTF8));
        modformatLabel->setText(QApplication::translate("Form2", "Format MOD", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Form2", "Zamknij", 0, QApplication::UnicodeUTF8));
        closeButton->setShortcut(QApplication::translate("Form2", "Esc", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form2", "Liczba sampli:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form2", "Pattern:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form2", "Liczba kana\305\202\303\263w:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form2", "Rows in pattern:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form2", "Liczba instrument\303\263w:", 0, QApplication::UnicodeUTF8));
        sampleLabel->setText(QApplication::translate("Form2", "0", 0, QApplication::UnicodeUTF8));
        patternLabel->setText(QApplication::translate("Form2", "0 / 0", 0, QApplication::UnicodeUTF8));
        rowLabel->setText(QApplication::translate("Form2", "0 / 0", 0, QApplication::UnicodeUTF8));
        chanLabel->setText(QApplication::translate("Form2", "0 / 0", 0, QApplication::UnicodeUTF8));
        instrLabel->setText(QApplication::translate("Form2", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form2", "Speed:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form2", "Tempo:", 0, QApplication::UnicodeUTF8));
        spdLabel->setText(QApplication::translate("Form2", "0", 0, QApplication::UnicodeUTF8));
        bpmLabel->setText(QApplication::translate("Form2", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMOD_H
