/********************************************************************************
** Form generated from reading UI file 'formPlaylist.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYLIST_H
#define UI_FORMPLAYLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form4
{
public:
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *actButton;
    QPushButton *odczytajB;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *toupButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *delButton;
    QPushButton *clrButton;
    QPushButton *zapiszB;
    QPushButton *todownButton;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *plistTime;
    QLabel *addingL;
    QCheckBox *listPlaylstBox;
    QLineEdit *searchBarE;
    QPushButton *searchModeB;
    QListWidget *listPlaylst;
    QPushButton *infoMB;

    void setupUi(QWidget *Form4)
    {
        if (Form4->objectName().isEmpty())
            Form4->setObjectName(QString::fromUtf8("Form4"));
        Form4->resize(420, 290);
        Form4->setMinimumSize(QSize(420, 290));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form4->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form4);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addButton = new QPushButton(Form4);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        actButton = new QPushButton(Form4);
        actButton->setObjectName(QString::fromUtf8("actButton"));

        gridLayout->addWidget(actButton, 0, 1, 1, 1);

        odczytajB = new QPushButton(Form4);
        odczytajB->setObjectName(QString::fromUtf8("odczytajB"));

        gridLayout->addWidget(odczytajB, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(74, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 2, 1);

        toupButton = new QPushButton(Form4);
        toupButton->setObjectName(QString::fromUtf8("toupButton"));
        toupButton->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(toupButton, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(74, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 2, 1);

        delButton = new QPushButton(Form4);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        gridLayout->addWidget(delButton, 1, 0, 1, 1);

        clrButton = new QPushButton(Form4);
        clrButton->setObjectName(QString::fromUtf8("clrButton"));

        gridLayout->addWidget(clrButton, 1, 1, 1, 1);

        zapiszB = new QPushButton(Form4);
        zapiszB->setObjectName(QString::fromUtf8("zapiszB"));

        gridLayout->addWidget(zapiszB, 1, 2, 1, 1);

        todownButton = new QPushButton(Form4);
        todownButton->setObjectName(QString::fromUtf8("todownButton"));
        todownButton->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(todownButton, 1, 4, 1, 1);

        frame = new QFrame(Form4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plistTime = new QLabel(widget);
        plistTime->setObjectName(QString::fromUtf8("plistTime"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        plistTime->setFont(font);

        gridLayout_2->addWidget(plistTime, 0, 0, 1, 1);

        addingL = new QLabel(widget);
        addingL->setObjectName(QString::fromUtf8("addingL"));

        gridLayout_2->addWidget(addingL, 1, 0, 1, 1);

        listPlaylstBox = new QCheckBox(widget);
        listPlaylstBox->setObjectName(QString::fromUtf8("listPlaylstBox"));
        listPlaylstBox->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(listPlaylstBox, 2, 0, 1, 1);

        searchBarE = new QLineEdit(widget);
        searchBarE->setObjectName(QString::fromUtf8("searchBarE"));

        gridLayout_2->addWidget(searchBarE, 2, 1, 1, 1);

        searchModeB = new QPushButton(widget);
        searchModeB->setObjectName(QString::fromUtf8("searchModeB"));
        searchModeB->setMaximumSize(QSize(25, 16777215));
        searchModeB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(searchModeB, 2, 2, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 2);

        listPlaylst = new QListWidget(frame);
        listPlaylst->setObjectName(QString::fromUtf8("listPlaylst"));
        listPlaylst->setMinimumSize(QSize(160, 0));
        listPlaylst->setMaximumSize(QSize(160, 16777215));
        listPlaylst->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_3->addWidget(listPlaylst, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 2, 0, 1, 7);

        infoMB = new QPushButton(Form4);
        infoMB->setObjectName(QString::fromUtf8("infoMB"));
        infoMB->setCursor(QCursor(Qt::PointingHandCursor));
        infoMB->setFocusPolicy(Qt::NoFocus);
        infoMB->setIconSize(QSize(48, 48));
        infoMB->setFlat(true);

        gridLayout->addWidget(infoMB, 0, 6, 2, 1);

        QWidget::setTabOrder(addButton, delButton);
        QWidget::setTabOrder(delButton, actButton);
        QWidget::setTabOrder(actButton, clrButton);
        QWidget::setTabOrder(clrButton, odczytajB);
        QWidget::setTabOrder(odczytajB, zapiszB);
        QWidget::setTabOrder(zapiszB, toupButton);
        QWidget::setTabOrder(toupButton, todownButton);
        QWidget::setTabOrder(todownButton, listPlaylst);
        QWidget::setTabOrder(listPlaylst, listPlaylstBox);

        retranslateUi(Form4);

        QMetaObject::connectSlotsByName(Form4);
    } // setupUi

    void retranslateUi(QWidget *Form4)
    {
        Form4->setWindowTitle(QApplication::translate("Form4", "Playlist", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Form4", "Dodaj", 0, QApplication::UnicodeUTF8));
        actButton->setText(QApplication::translate("Form4", "Akcja", 0, QApplication::UnicodeUTF8));
        odczytajB->setText(QApplication::translate("Form4", "Odczytaj", 0, QApplication::UnicodeUTF8));
        toupButton->setText(QApplication::translate("Form4", "\341\220\261", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("Form4", "Usu\305\204 wpisy", 0, QApplication::UnicodeUTF8));
        clrButton->setText(QApplication::translate("Form4", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        zapiszB->setText(QApplication::translate("Form4", "Zapisz", 0, QApplication::UnicodeUTF8));
        todownButton->setText(QApplication::translate("Form4", "\341\220\257", 0, QApplication::UnicodeUTF8));
        plistTime->setText(QApplication::translate("Form4", "00:00", 0, QApplication::UnicodeUTF8));
        addingL->setText(QApplication::translate("Form4", "0 / 0", 0, QApplication::UnicodeUTF8));
        listPlaylstBox->setText(QApplication::translate("Form4", "Pokazuj list\304\231 playlist", 0, QApplication::UnicodeUTF8));
        searchModeB->setText(QString());
        infoMB->setText(QApplication::translate("Form4", "Informacje\n"
"o muzyce", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form4: public Ui_Form4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYLIST_H
