/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 08:07:03 2012
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equalizer
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *glF;
    QFrame *frame;
    QPushButton *dwnB;
    QCheckBox *glW;
    QLabel *label;
    QPushButton *clrB;
    QPushButton *upB;
    QLabel *label_2;
    QFrame *line;
    QPushButton *swB;
    QSlider *sl1;
    QSlider *sl7;
    QSlider *sl2;
    QSlider *sl5;
    QSlider *sl3;
    QSlider *sl0;
    QSlider *sl4;
    QSlider *sl8;
    QSlider *sl6;
    QCheckBox *enabledB;

    void setupUi(QWidget *Equalizer)
    {
        if (Equalizer->objectName().isEmpty())
            Equalizer->setObjectName(QString::fromUtf8("Equalizer"));
        Equalizer->resize(345, 295);
        Equalizer->setMinimumSize(QSize(345, 220));
        Equalizer->setMaximumSize(QSize(345, 295));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Equalizer->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Equalizer);
        verticalLayout->setSpacing(-1);
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        glF = new QFrame(Equalizer);
        glF->setObjectName(QString::fromUtf8("glF"));
        glF->setMaximumSize(QSize(333, 70));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        glF->setPalette(palette);
        glF->setFrameShape(QFrame::StyledPanel);
        glF->setFrameShadow(QFrame::Sunken);
        glF->setLineWidth(1);

        verticalLayout->addWidget(glF);

        frame = new QFrame(Equalizer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        dwnB = new QPushButton(frame);
        dwnB->setObjectName(QString::fromUtf8("dwnB"));
        dwnB->setGeometry(QRect(10, 150, 31, 28));
        glW = new QCheckBox(frame);
        glW->setObjectName(QString::fromUtf8("glW"));
        glW->setGeometry(QRect(90, 0, 121, 22));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(95, 30, 101, 18));
        clrB = new QPushButton(frame);
        clrB->setObjectName(QString::fromUtf8("clrB"));
        clrB->setGeometry(QRect(10, 95, 31, 28));
        upB = new QPushButton(frame);
        upB->setObjectName(QString::fromUtf8("upB"));
        upB->setGeometry(QRect(10, 40, 31, 28));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 30, 101, 20));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(60, 101, 265, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        swB = new QPushButton(frame);
        swB->setObjectName(QString::fromUtf8("swB"));
        swB->setGeometry(QRect(80, 175, 241, 22));
        swB->setCheckable(true);
        sl1 = new QSlider(frame);
        sl1->setObjectName(QString::fromUtf8("sl1"));
        sl1->setGeometry(QRect(90, 50, 25, 121));
        sl1->setCursor(QCursor(Qt::PointingHandCursor));
        sl1->setMaximum(200);
        sl1->setValue(100);
        sl1->setOrientation(Qt::Vertical);
        sl7 = new QSlider(frame);
        sl7->setObjectName(QString::fromUtf8("sl7"));
        sl7->setGeometry(QRect(270, 50, 25, 121));
        sl7->setCursor(QCursor(Qt::PointingHandCursor));
        sl7->setMaximum(200);
        sl7->setValue(100);
        sl7->setOrientation(Qt::Vertical);
        sl2 = new QSlider(frame);
        sl2->setObjectName(QString::fromUtf8("sl2"));
        sl2->setGeometry(QRect(120, 50, 25, 121));
        sl2->setCursor(QCursor(Qt::PointingHandCursor));
        sl2->setMaximum(200);
        sl2->setValue(100);
        sl2->setOrientation(Qt::Vertical);
        sl5 = new QSlider(frame);
        sl5->setObjectName(QString::fromUtf8("sl5"));
        sl5->setGeometry(QRect(210, 50, 25, 121));
        sl5->setCursor(QCursor(Qt::PointingHandCursor));
        sl5->setMaximum(200);
        sl5->setValue(100);
        sl5->setOrientation(Qt::Vertical);
        sl3 = new QSlider(frame);
        sl3->setObjectName(QString::fromUtf8("sl3"));
        sl3->setGeometry(QRect(150, 50, 25, 121));
        sl3->setCursor(QCursor(Qt::PointingHandCursor));
        sl3->setMaximum(200);
        sl3->setValue(100);
        sl3->setOrientation(Qt::Vertical);
        sl0 = new QSlider(frame);
        sl0->setObjectName(QString::fromUtf8("sl0"));
        sl0->setGeometry(QRect(50, 30, 25, 161));
        sl0->setCursor(QCursor(Qt::PointingHandCursor));
        sl0->setMinimum(10);
        sl0->setMaximum(190);
        sl0->setValue(100);
        sl0->setOrientation(Qt::Vertical);
        sl4 = new QSlider(frame);
        sl4->setObjectName(QString::fromUtf8("sl4"));
        sl4->setGeometry(QRect(180, 50, 25, 121));
        sl4->setCursor(QCursor(Qt::PointingHandCursor));
        sl4->setMaximum(200);
        sl4->setValue(100);
        sl4->setOrientation(Qt::Vertical);
        sl8 = new QSlider(frame);
        sl8->setObjectName(QString::fromUtf8("sl8"));
        sl8->setGeometry(QRect(300, 50, 25, 121));
        sl8->setCursor(QCursor(Qt::PointingHandCursor));
        sl8->setMaximum(200);
        sl8->setValue(100);
        sl8->setOrientation(Qt::Vertical);
        sl6 = new QSlider(frame);
        sl6->setObjectName(QString::fromUtf8("sl6"));
        sl6->setGeometry(QRect(240, 50, 25, 121));
        sl6->setCursor(QCursor(Qt::PointingHandCursor));
        sl6->setMaximum(200);
        sl6->setValue(100);
        sl6->setOrientation(Qt::Vertical);
        enabledB = new QCheckBox(frame);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setGeometry(QRect(5, 0, 51, 22));

        verticalLayout->addWidget(frame);

        QWidget::setTabOrder(enabledB, glW);
        QWidget::setTabOrder(glW, upB);
        QWidget::setTabOrder(upB, clrB);
        QWidget::setTabOrder(clrB, dwnB);
        QWidget::setTabOrder(dwnB, sl0);
        QWidget::setTabOrder(sl0, sl1);
        QWidget::setTabOrder(sl1, sl2);
        QWidget::setTabOrder(sl2, sl3);
        QWidget::setTabOrder(sl3, sl4);
        QWidget::setTabOrder(sl4, sl5);
        QWidget::setTabOrder(sl5, sl6);
        QWidget::setTabOrder(sl6, sl7);
        QWidget::setTabOrder(sl7, sl8);
        QWidget::setTabOrder(sl8, swB);

        retranslateUi(Equalizer);

        QMetaObject::connectSlotsByName(Equalizer);
    } // setupUi

    void retranslateUi(QWidget *Equalizer)
    {
        Equalizer->setWindowTitle(QApplication::translate("Equalizer", "QMP Equalizer", 0, QApplication::UnicodeUTF8));
        dwnB->setText(QApplication::translate("Equalizer", "->", 0, QApplication::UnicodeUTF8));
        glW->setText(QApplication::translate("Equalizer", "Poka\305\274 wykres", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Equalizer", "Low frequency", 0, QApplication::UnicodeUTF8));
        clrB->setText(QApplication::translate("Equalizer", "->", 0, QApplication::UnicodeUTF8));
        upB->setText(QApplication::translate("Equalizer", "->", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Equalizer", "High frequency", 0, QApplication::UnicodeUTF8));
        swB->setText(QApplication::translate("Equalizer", "Show in window", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Equalizer", "ON", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Equalizer: public Ui_Equalizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
