/********************************************************************************
** Form generated from reading UI file 'formStyle.ui'
**
** Created: Tue Aug 21 08:05:42 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSTYLE_H
#define UI_FORMSTYLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormS
{
public:
    QComboBox *styleCB;
    QPushButton *OKB;
    QLabel *label;
    QRadioButton *scB;
    QRadioButton *ccB;
    QGroupBox *groupBox;
    QComboBox *colorsB;
    QLabel *label_2;
    QPushButton *addB;
    QPushButton *delB;
    QLabel *label_3;
    QLineEdit *colorE;
    QFrame *line;
    QPushButton *applyColorsB;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *bC1_1;
    QLabel *label_14;
    QPushButton *bC1_2;
    QPushButton *bC1_3;
    QPushButton *bC1_4;
    QPushButton *bC1_5;
    QLabel *label_16;
    QPushButton *bC1_6;
    QPushButton *bC1_7;
    QFontComboBox *bF1;
    QSpinBox *bFSize1;
    QLabel *label_17;
    QPushButton *bC1_8;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *mainWindowSets;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QDoubleSpinBox *bP2_1;
    QLabel *label_10;
    QPushButton *bP2_2;
    QCheckBox *bHt2;
    QCheckBox *bSt2;
    QSpacerItem *verticalSpacer;
    QCheckBox *use2;
    QPushButton *chNameB;

    void setupUi(QWidget *FormS)
    {
        if (FormS->objectName().isEmpty())
            FormS->setObjectName(QString::fromUtf8("FormS"));
        FormS->resize(400, 465);
        FormS->setMinimumSize(QSize(400, 465));
        FormS->setMaximumSize(QSize(400, 465));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        FormS->setWindowIcon(icon);
        styleCB = new QComboBox(FormS);
        styleCB->setObjectName(QString::fromUtf8("styleCB"));
        styleCB->setGeometry(QRect(140, 10, 251, 23));
        OKB = new QPushButton(FormS);
        OKB->setObjectName(QString::fromUtf8("OKB"));
        OKB->setGeometry(QRect(10, 438, 381, 21));
        label = new QLabel(FormS);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 13, 121, 17));
        scB = new QRadioButton(FormS);
        scB->setObjectName(QString::fromUtf8("scB"));
        scB->setGeometry(QRect(10, 40, 201, 23));
        scB->setChecked(true);
        ccB = new QRadioButton(FormS);
        ccB->setObjectName(QString::fromUtf8("ccB"));
        ccB->setGeometry(QRect(210, 40, 181, 23));
        groupBox = new QGroupBox(FormS);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 381, 361));
        colorsB = new QComboBox(groupBox);
        colorsB->setObjectName(QString::fromUtf8("colorsB"));
        colorsB->setGeometry(QRect(80, 10, 111, 23));
        colorsB->setContextMenuPolicy(Qt::CustomContextMenu);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 13, 61, 17));
        addB = new QPushButton(groupBox);
        addB->setObjectName(QString::fromUtf8("addB"));
        addB->setGeometry(QRect(200, 11, 91, 21));
        delB = new QPushButton(groupBox);
        delB->setObjectName(QString::fromUtf8("delB"));
        delB->setGeometry(QRect(300, 11, 71, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 59, 17));
        colorE = new QLineEdit(groupBox);
        colorE->setObjectName(QString::fromUtf8("colorE"));
        colorE->setGeometry(QRect(80, 48, 111, 23));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 30, 361, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        applyColorsB = new QPushButton(groupBox);
        applyColorsB->setObjectName(QString::fromUtf8("applyColorsB"));
        applyColorsB->setGeometry(QRect(300, 50, 71, 21));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 80, 360, 270));
        tabWidget->setMinimumSize(QSize(360, 270));
        tabWidget->setMaximumSize(QSize(360, 270));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        bC1_1 = new QPushButton(tab);
        bC1_1->setObjectName(QString::fromUtf8("bC1_1"));
        bC1_1->setMinimumSize(QSize(60, 0));
        bC1_1->setMaximumSize(QSize(60, 16777215));
        bC1_1->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_1, 0, 2, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 5, 0, 1, 1);

        bC1_2 = new QPushButton(tab);
        bC1_2->setObjectName(QString::fromUtf8("bC1_2"));
        bC1_2->setMinimumSize(QSize(60, 0));
        bC1_2->setMaximumSize(QSize(60, 16777215));
        bC1_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_2, 1, 2, 1, 1);

        bC1_3 = new QPushButton(tab);
        bC1_3->setObjectName(QString::fromUtf8("bC1_3"));
        bC1_3->setMinimumSize(QSize(60, 0));
        bC1_3->setMaximumSize(QSize(60, 16777215));
        bC1_3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_3, 2, 2, 1, 1);

        bC1_4 = new QPushButton(tab);
        bC1_4->setObjectName(QString::fromUtf8("bC1_4"));
        bC1_4->setMinimumSize(QSize(60, 0));
        bC1_4->setMaximumSize(QSize(60, 16777215));
        bC1_4->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_4, 3, 2, 1, 1);

        bC1_5 = new QPushButton(tab);
        bC1_5->setObjectName(QString::fromUtf8("bC1_5"));
        bC1_5->setMinimumSize(QSize(60, 0));
        bC1_5->setMaximumSize(QSize(60, 16777215));
        bC1_5->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_5, 4, 2, 1, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 6, 0, 1, 1);

        bC1_6 = new QPushButton(tab);
        bC1_6->setObjectName(QString::fromUtf8("bC1_6"));
        bC1_6->setMinimumSize(QSize(60, 0));
        bC1_6->setMaximumSize(QSize(60, 16777215));
        bC1_6->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_6, 5, 2, 1, 1);

        bC1_7 = new QPushButton(tab);
        bC1_7->setObjectName(QString::fromUtf8("bC1_7"));
        bC1_7->setMinimumSize(QSize(60, 0));
        bC1_7->setMaximumSize(QSize(60, 16777215));
        bC1_7->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_7, 6, 2, 1, 1);

        bF1 = new QFontComboBox(tab);
        bF1->setObjectName(QString::fromUtf8("bF1"));

        gridLayout->addWidget(bF1, 8, 0, 1, 1);

        bFSize1 = new QSpinBox(tab);
        bFSize1->setObjectName(QString::fromUtf8("bFSize1"));
        bFSize1->setMinimum(6);
        bFSize1->setMaximum(14);
        bFSize1->setValue(10);

        gridLayout->addWidget(bFSize1, 8, 2, 1, 1);

        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 7, 0, 1, 1);

        bC1_8 = new QPushButton(tab);
        bC1_8->setObjectName(QString::fromUtf8("bC1_8"));
        bC1_8->setMinimumSize(QSize(60, 0));
        bC1_8->setMaximumSize(QSize(60, 16777215));
        bC1_8->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(bC1_8, 7, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mainWindowSets = new QWidget(tab_2);
        mainWindowSets->setObjectName(QString::fromUtf8("mainWindowSets"));
        gridLayout_3 = new QGridLayout(mainWindowSets);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(mainWindowSets);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        bP2_1 = new QDoubleSpinBox(mainWindowSets);
        bP2_1->setObjectName(QString::fromUtf8("bP2_1"));
        bP2_1->setMaximumSize(QSize(60, 16777215));
        bP2_1->setDecimals(1);
        bP2_1->setMaximum(1);
        bP2_1->setSingleStep(0.1);
        bP2_1->setValue(1);

        gridLayout_3->addWidget(bP2_1, 0, 1, 1, 1);

        label_10 = new QLabel(mainWindowSets);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        bP2_2 = new QPushButton(mainWindowSets);
        bP2_2->setObjectName(QString::fromUtf8("bP2_2"));
        bP2_2->setMaximumSize(QSize(60, 16777215));
        bP2_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(bP2_2, 1, 1, 1, 1);

        bHt2 = new QCheckBox(mainWindowSets);
        bHt2->setObjectName(QString::fromUtf8("bHt2"));
        bHt2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(bHt2, 2, 0, 1, 2);

        bSt2 = new QCheckBox(mainWindowSets);
        bSt2->setObjectName(QString::fromUtf8("bSt2"));
        bSt2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(bSt2, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 2);


        gridLayout_2->addWidget(mainWindowSets, 1, 0, 1, 2);

        use2 = new QCheckBox(tab_2);
        use2->setObjectName(QString::fromUtf8("use2"));
        use2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(use2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        chNameB = new QPushButton(groupBox);
        chNameB->setObjectName(QString::fromUtf8("chNameB"));
        chNameB->setGeometry(QRect(200, 50, 91, 21));
        QWidget::setTabOrder(styleCB, scB);
        QWidget::setTabOrder(scB, ccB);
        QWidget::setTabOrder(ccB, colorsB);
        QWidget::setTabOrder(colorsB, addB);
        QWidget::setTabOrder(addB, delB);
        QWidget::setTabOrder(delB, colorE);
        QWidget::setTabOrder(colorE, chNameB);
        QWidget::setTabOrder(chNameB, applyColorsB);
        QWidget::setTabOrder(applyColorsB, tabWidget);
        QWidget::setTabOrder(tabWidget, bC1_1);
        QWidget::setTabOrder(bC1_1, bC1_2);
        QWidget::setTabOrder(bC1_2, bC1_3);
        QWidget::setTabOrder(bC1_3, bC1_4);
        QWidget::setTabOrder(bC1_4, bC1_5);
        QWidget::setTabOrder(bC1_5, bC1_6);
        QWidget::setTabOrder(bC1_6, bC1_7);
        QWidget::setTabOrder(bC1_7, bC1_8);
        QWidget::setTabOrder(bC1_8, bFSize1);
        QWidget::setTabOrder(bFSize1, bF1);
        QWidget::setTabOrder(bF1, OKB);
        QWidget::setTabOrder(OKB, use2);
        QWidget::setTabOrder(use2, bP2_1);
        QWidget::setTabOrder(bP2_1, bP2_2);
        QWidget::setTabOrder(bP2_2, bHt2);
        QWidget::setTabOrder(bHt2, bSt2);

        retranslateUi(FormS);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormS);
    } // setupUi

    void retranslateUi(QWidget *FormS)
    {
        FormS->setWindowTitle(QApplication::translate("FormS", "Wybierz styl", 0, QApplication::UnicodeUTF8));
        OKB->setText(QApplication::translate("FormS", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormS", "Wybierz styl z QT:", 0, QApplication::UnicodeUTF8));
        scB->setText(QApplication::translate("FormS", "U\305\274yj kolor\303\263w systemowych", 0, QApplication::UnicodeUTF8));
        ccB->setText(QApplication::translate("FormS", "U\305\274yj w\305\202asnych kolor\303\263w", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("FormS", "Wybierz:", 0, QApplication::UnicodeUTF8));
        addB->setText(QApplication::translate("FormS", "Dodaj", 0, QApplication::UnicodeUTF8));
        delB->setText(QApplication::translate("FormS", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FormS", "Nazwa:", 0, QApplication::UnicodeUTF8));
        applyColorsB->setText(QApplication::translate("FormS", "Zastosuj", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormS", "Kolor przycisk\303\263w:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FormS", "Kolor okna:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FormS", "Kolor obramowania:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FormS", "Kolor pod\305\233wietlenia:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FormS", "Kolor p\303\263l tekstowych:", 0, QApplication::UnicodeUTF8));
        bC1_1->setText(QString());
        label_14->setText(QApplication::translate("FormS", "Kolor tekstu:", 0, QApplication::UnicodeUTF8));
        bC1_2->setText(QString());
        bC1_3->setText(QString());
        bC1_4->setText(QString());
        bC1_5->setText(QString());
        label_16->setText(QApplication::translate("FormS", "Kolor zaznaczonego:", 0, QApplication::UnicodeUTF8));
        bC1_6->setText(QString());
        bC1_7->setText(QString());
        label_17->setText(QApplication::translate("FormS", "Kolor przycisku suwaka", 0, QApplication::UnicodeUTF8));
        bC1_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormS", "Wszystkie okna", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FormS", "Przezroczysto\305\233\304\207:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FormS", "Tapeta okna:", 0, QApplication::UnicodeUTF8));
        bP2_2->setText(QString());
        bHt2->setText(QApplication::translate("FormS", "Przezroczyste pod\305\233wietlenie", 0, QApplication::UnicodeUTF8));
        bSt2->setText(QApplication::translate("FormS", "Przezroczyste obramowanie", 0, QApplication::UnicodeUTF8));
        use2->setText(QApplication::translate("FormS", "W\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormS", "Okno g\305\202\303\263wne", 0, QApplication::UnicodeUTF8));
        chNameB->setText(QApplication::translate("FormS", "Zmie\305\204 nazw\304\231", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormS: public Ui_FormS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSTYLE_H
