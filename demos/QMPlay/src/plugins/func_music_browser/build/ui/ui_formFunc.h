/********************************************************************************
** Form generated from reading UI file 'formFunc.ui'
**
** Created: Tue Aug 21 19:58:23 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFUNC_H
#define UI_FORMFUNC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFunc
{
public:
    QGridLayout *gridLayout;
    QPushButton *playB;
    QLineEdit *titleE;
    QLabel *pagesL;
    QSpacerItem *horizontalSpacer;
    QPushButton *downloadB;
    QPushButton *dwnPB;
    QLabel *infoL;
    QPushButton *clrB;
    QPushButton *searchB;
    QPushButton *prevB;
    QPushButton *nextB;
    QTableWidget *titlesW;
    QSpinBox *currPageB;
    QWidget *dwnW;
    QGridLayout *gridLayout_2;
    QProgressBar *progressB;
    QPushButton *abortB;
    QLabel *dwnTitleL;
    QLabel *dwnInfoL;
    QListWidget *queueW;

    void setupUi(QWidget *FormFunc)
    {
        if (FormFunc->objectName().isEmpty())
            FormFunc->setObjectName(QString::fromUtf8("FormFunc"));
        FormFunc->resize(440, 367);
        gridLayout = new QGridLayout(FormFunc);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        playB = new QPushButton(FormFunc);
        playB->setObjectName(QString::fromUtf8("playB"));
        playB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(playB, 3, 10, 1, 2);

        titleE = new QLineEdit(FormFunc);
        titleE->setObjectName(QString::fromUtf8("titleE"));

        gridLayout->addWidget(titleE, 0, 0, 1, 13);

        pagesL = new QLabel(FormFunc);
        pagesL->setObjectName(QString::fromUtf8("pagesL"));

        gridLayout->addWidget(pagesL, 3, 4, 1, 3);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 9, 1, 1);

        downloadB = new QPushButton(FormFunc);
        downloadB->setObjectName(QString::fromUtf8("downloadB"));
        downloadB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(downloadB, 3, 13, 1, 1);

        dwnPB = new QPushButton(FormFunc);
        dwnPB->setObjectName(QString::fromUtf8("dwnPB"));
        dwnPB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(dwnPB, 2, 10, 1, 2);

        infoL = new QLabel(FormFunc);
        infoL->setObjectName(QString::fromUtf8("infoL"));

        gridLayout->addWidget(infoL, 2, 1, 1, 9);

        clrB = new QPushButton(FormFunc);
        clrB->setObjectName(QString::fromUtf8("clrB"));
        clrB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(clrB, 2, 13, 1, 1);

        searchB = new QPushButton(FormFunc);
        searchB->setObjectName(QString::fromUtf8("searchB"));
        searchB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(searchB, 0, 13, 1, 1);

        prevB = new QPushButton(FormFunc);
        prevB->setObjectName(QString::fromUtf8("prevB"));
        prevB->setMaximumSize(QSize(25, 16777215));
        prevB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(prevB, 3, 1, 1, 1);

        nextB = new QPushButton(FormFunc);
        nextB->setObjectName(QString::fromUtf8("nextB"));
        nextB->setMaximumSize(QSize(25, 16777215));
        nextB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(nextB, 3, 7, 1, 1);

        titlesW = new QTableWidget(FormFunc);
        if (titlesW->columnCount() < 4)
            titlesW->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        titlesW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        titlesW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        titlesW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        titlesW->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        titlesW->setObjectName(QString::fromUtf8("titlesW"));
        titlesW->setContextMenuPolicy(Qt::CustomContextMenu);
        titlesW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        titlesW->setEditTriggers(QAbstractItemView::NoEditTriggers);
        titlesW->setSelectionMode(QAbstractItemView::SingleSelection);
        titlesW->setSelectionBehavior(QAbstractItemView::SelectRows);
        titlesW->setIconSize(QSize(100, 100));
        titlesW->setShowGrid(false);
        titlesW->setCornerButtonEnabled(false);
        titlesW->horizontalHeader()->setVisible(true);
        titlesW->horizontalHeader()->setCascadingSectionResizes(true);
        titlesW->horizontalHeader()->setHighlightSections(false);
        titlesW->horizontalHeader()->setStretchLastSection(false);
        titlesW->verticalHeader()->setDefaultSectionSize(20);
        titlesW->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(titlesW, 1, 0, 1, 14);

        currPageB = new QSpinBox(FormFunc);
        currPageB->setObjectName(QString::fromUtf8("currPageB"));
        currPageB->setMaximum(999);

        gridLayout->addWidget(currPageB, 3, 2, 1, 1);

        dwnW = new QWidget(FormFunc);
        dwnW->setObjectName(QString::fromUtf8("dwnW"));
        gridLayout_2 = new QGridLayout(dwnW);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        progressB = new QProgressBar(dwnW);
        progressB->setObjectName(QString::fromUtf8("progressB"));
        progressB->setMaximumSize(QSize(16777215, 20));
        progressB->setValue(0);

        gridLayout_2->addWidget(progressB, 5, 0, 1, 2);

        abortB = new QPushButton(dwnW);
        abortB->setObjectName(QString::fromUtf8("abortB"));
        abortB->setMaximumSize(QSize(20, 20));
        abortB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(abortB, 5, 2, 1, 1);

        dwnTitleL = new QLabel(dwnW);
        dwnTitleL->setObjectName(QString::fromUtf8("dwnTitleL"));

        gridLayout_2->addWidget(dwnTitleL, 0, 0, 1, 3);

        dwnInfoL = new QLabel(dwnW);
        dwnInfoL->setObjectName(QString::fromUtf8("dwnInfoL"));

        gridLayout_2->addWidget(dwnInfoL, 2, 0, 1, 3);

        queueW = new QListWidget(dwnW);
        queueW->setObjectName(QString::fromUtf8("queueW"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(queueW->sizePolicy().hasHeightForWidth());
        queueW->setSizePolicy(sizePolicy);
        queueW->setMaximumSize(QSize(16777215, 75));
        queueW->setContextMenuPolicy(Qt::CustomContextMenu);
        queueW->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(queueW, 4, 0, 1, 3);


        gridLayout->addWidget(dwnW, 4, 0, 1, 14);

        QWidget::setTabOrder(titleE, searchB);
        QWidget::setTabOrder(searchB, titlesW);
        QWidget::setTabOrder(titlesW, prevB);
        QWidget::setTabOrder(prevB, currPageB);
        QWidget::setTabOrder(currPageB, nextB);
        QWidget::setTabOrder(nextB, dwnPB);
        QWidget::setTabOrder(dwnPB, playB);
        QWidget::setTabOrder(playB, clrB);
        QWidget::setTabOrder(clrB, downloadB);
        QWidget::setTabOrder(downloadB, queueW);
        QWidget::setTabOrder(queueW, abortB);

        retranslateUi(FormFunc);

        QMetaObject::connectSlotsByName(FormFunc);
    } // setupUi

    void retranslateUi(QWidget *FormFunc)
    {
        FormFunc->setWindowTitle(QApplication::translate("FormFunc", "Przegl\304\205darka muzyki", 0, QApplication::UnicodeUTF8));
        playB->setText(QApplication::translate("FormFunc", "Odtwarzaj w\n"
"QMPlay", 0, QApplication::UnicodeUTF8));
        downloadB->setText(QApplication::translate("FormFunc", "Pobierz na\n"
"dysk", 0, QApplication::UnicodeUTF8));
        dwnPB->setText(QApplication::translate("FormFunc", "\305\232cie\305\274ka\n"
"pobierania", 0, QApplication::UnicodeUTF8));
        infoL->setText(QString());
        clrB->setText(QApplication::translate("FormFunc", "Wyczy\305\233\304\207\n"
"wyniki", 0, QApplication::UnicodeUTF8));
        searchB->setText(QApplication::translate("FormFunc", "Szukaj", 0, QApplication::UnicodeUTF8));
        prevB->setText(QApplication::translate("FormFunc", "<", 0, QApplication::UnicodeUTF8));
        nextB->setText(QApplication::translate("FormFunc", ">", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = titlesW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormFunc", "Tytu\305\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = titlesW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormFunc", "D\305\202ugo\305\233\304\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = titlesW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FormFunc", "Rozmiar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = titlesW->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FormFunc", "U\305\274ytkownik", 0, QApplication::UnicodeUTF8));
        abortB->setText(QApplication::translate("FormFunc", "X", 0, QApplication::UnicodeUTF8));
        dwnTitleL->setText(QApplication::translate("FormFunc", "Pobieranie", 0, QApplication::UnicodeUTF8));
        dwnInfoL->setText(QApplication::translate("FormFunc", "Szybko\305\233\304\207:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormFunc: public Ui_FormFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFUNC_H
