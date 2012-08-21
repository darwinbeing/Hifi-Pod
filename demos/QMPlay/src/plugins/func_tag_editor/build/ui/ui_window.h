/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Tue Aug 21 19:58:43 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout_3;
    QLineEdit *fileE;
    QPushButton *browseB;
    QPushButton *oocFB;
    QWidget *widget;
    QPushButton *updateB;
    QGroupBox *tagGroupBox;
    QLineEdit *titleE;
    QLineEdit *artistE;
    QLineEdit *albumE;
    QTextEdit *commentE;
    QSpinBox *yearB;
    QSpinBox *trackB;
    QLineEdit *genreE;
    QPushButton *clrB;
    QGroupBox *pictureGroupBox;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(400, 275);
        Window->setMinimumSize(QSize(400, 275));
        Window->setMaximumSize(QSize(400, 275));
        gridLayout_3 = new QGridLayout(Window);
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        gridLayout_3->setVerticalSpacing(0);
        fileE = new QLineEdit(Window);
        fileE->setObjectName(QString::fromUtf8("fileE"));

        gridLayout_3->addWidget(fileE, 0, 0, 1, 1);

        browseB = new QPushButton(Window);
        browseB->setObjectName(QString::fromUtf8("browseB"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(browseB->sizePolicy().hasHeightForWidth());
        browseB->setSizePolicy(sizePolicy);
        browseB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(browseB, 0, 2, 1, 1);

        oocFB = new QPushButton(Window);
        oocFB->setObjectName(QString::fromUtf8("oocFB"));
        oocFB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(oocFB, 0, 1, 1, 1);

        widget = new QWidget(Window);
        widget->setObjectName(QString::fromUtf8("widget"));
        updateB = new QPushButton(widget);
        updateB->setObjectName(QString::fromUtf8("updateB"));
        updateB->setGeometry(QRect(240, 220, 151, 21));
        updateB->setCursor(QCursor(Qt::PointingHandCursor));
        tagGroupBox = new QGroupBox(widget);
        tagGroupBox->setObjectName(QString::fromUtf8("tagGroupBox"));
        tagGroupBox->setGeometry(QRect(10, 5, 231, 241));
        tagGroupBox->setCheckable(true);
        tagGroupBox->setChecked(false);
        titleE = new QLineEdit(tagGroupBox);
        titleE->setObjectName(QString::fromUtf8("titleE"));
        titleE->setGeometry(QRect(10, 20, 211, 24));
        artistE = new QLineEdit(tagGroupBox);
        artistE->setObjectName(QString::fromUtf8("artistE"));
        artistE->setGeometry(QRect(10, 50, 211, 24));
        albumE = new QLineEdit(tagGroupBox);
        albumE->setObjectName(QString::fromUtf8("albumE"));
        albumE->setGeometry(QRect(10, 80, 211, 24));
        commentE = new QTextEdit(tagGroupBox);
        commentE->setObjectName(QString::fromUtf8("commentE"));
        commentE->setGeometry(QRect(10, 110, 211, 61));
        commentE->setTabChangesFocus(true);
        commentE->setAcceptRichText(false);
        commentE->setTextInteractionFlags(Qt::TextEditorInteraction);
        yearB = new QSpinBox(tagGroupBox);
        yearB->setObjectName(QString::fromUtf8("yearB"));
        yearB->setGeometry(QRect(10, 210, 101, 23));
        yearB->setMaximum(9999);
        yearB->setValue(0);
        trackB = new QSpinBox(tagGroupBox);
        trackB->setObjectName(QString::fromUtf8("trackB"));
        trackB->setGeometry(QRect(120, 210, 101, 23));
        trackB->setMaximum(255);
        trackB->setValue(0);
        genreE = new QLineEdit(tagGroupBox);
        genreE->setObjectName(QString::fromUtf8("genreE"));
        genreE->setGeometry(QRect(10, 180, 211, 24));
        clrB = new QPushButton(widget);
        clrB->setObjectName(QString::fromUtf8("clrB"));
        clrB->setGeometry(QRect(270, 190, 91, 21));
        clrB->setCursor(QCursor(Qt::PointingHandCursor));
        pictureGroupBox = new QGroupBox(widget);
        pictureGroupBox->setObjectName(QString::fromUtf8("pictureGroupBox"));
        pictureGroupBox->setGeometry(QRect(250, 5, 130, 150));
        pictureGroupBox->setCheckable(true);
        pictureGroupBox->setChecked(false);

        gridLayout_3->addWidget(widget, 1, 0, 1, 3);

        QWidget::setTabOrder(fileE, browseB);
        QWidget::setTabOrder(browseB, oocFB);
        QWidget::setTabOrder(oocFB, tagGroupBox);
        QWidget::setTabOrder(tagGroupBox, titleE);
        QWidget::setTabOrder(titleE, artistE);
        QWidget::setTabOrder(artistE, albumE);
        QWidget::setTabOrder(albumE, commentE);
        QWidget::setTabOrder(commentE, genreE);
        QWidget::setTabOrder(genreE, yearB);
        QWidget::setTabOrder(yearB, trackB);
        QWidget::setTabOrder(trackB, pictureGroupBox);
        QWidget::setTabOrder(pictureGroupBox, updateB);
        QWidget::setTabOrder(updateB, clrB);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Tag editor", 0, QApplication::UnicodeUTF8));
        browseB->setText(QApplication::translate("Window", "Przegl\304\205daj", 0, QApplication::UnicodeUTF8));
        oocFB->setText(QApplication::translate("Window", "Plik", 0, QApplication::UnicodeUTF8));
        updateB->setText(QApplication::translate("Window", "Uaktualnij", 0, QApplication::UnicodeUTF8));
        tagGroupBox->setTitle(QApplication::translate("Window", "Enabled", 0, QApplication::UnicodeUTF8));
        clrB->setText(QApplication::translate("Window", "Wyczy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        pictureGroupBox->setTitle(QApplication::translate("Window", "Picture", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
