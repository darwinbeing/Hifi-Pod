/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 08:05:42 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabQMP;
    QGridLayout *gridLayout_1;
    QPushButton *toUpB;
    QLabel *label;
    QListWidget *pluginList;
    QPushButton *applyButton;
    QPushButton *toDownB;
    QTabWidget *tabWidget_2;
    QWidget *tab_1;
    QPushButton *setStyleB;
    QPushButton *abPB;
    QPushButton *opcjePB;
    QCheckBox *naf1Box;
    QPushButton *loadPlugButton;
    QPushButton *delSetsButton;
    QFrame *naf1Frame;
    QRadioButton *zVpluginaB;
    QRadioButton *zIpluginaB;
    QRadioButton *defB;
    QPushButton *langB;
    QCheckBox *pbRBox;
    QCheckBox *pbLBox;
    QPushButton *updB;
    QPushButton *dockB;
    QCheckBox *fileFilterB;
    QCheckBox *chImgsB;
    QCheckBox *eoplB;
    QWidget *tab_2;
    QCheckBox *bladinfoB;
    QCheckBox *PlaynxtBox;
    QCheckBox *NxterrBox;
    QCheckBox *savplistBox;
    QCheckBox *savposBox;
    QCheckBox *closeExportOnNxtB;
    QCheckBox *pmppB;
    QSpinBox *procBox;
    QLabel *label_f;
    QSpinBox *secBox;
    QLabel *label_o;
    QLabel *label_10;
    QCheckBox *uPLeLB;
    QCheckBox *uPLeB;
    QCheckBox *fileStructB;
    QRadioButton *procB;
    QRadioButton *sekB;
    QCheckBox *unknownTypeB;
    QWidget *tab_4;
    QLineEdit *proxyE;
    QCheckBox *proxyB;
    QLabel *label_2;
    QSpinBox *maxSpdDwnB;
    QSpinBox *maxSpdUplB;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *buffSizeB;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *autoUpdatesB;
    QLineEdit *svrAddressE;
    QPushButton *svrAddressRestoreB;
    QSpacerItem *spacer;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTabWidget *libsT;
    QWidget *tab_8;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QListWidget *pluginsL;
    QTabWidget *inputT;
    QWidget *tab_6;
    QTabWidget *outputT;
    QWidget *tab_11;
    QTabWidget *effectT;
    QWidget *tab_10;
    QTabWidget *visT;
    QWidget *tab_7;
    QTabWidget *funcT;
    QWidget *tab_9;
    QSpacerItem *spacer_2;
    QPushButton *QMPButton;
    QPushButton *prevButton;
    QPushButton *nxtButton;
    QSpacerItem *spacer_3;
    QPushButton *OKButton;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(600, 475);
        Form3->setMinimumSize(QSize(600, 475));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form3);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Form3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabQMP = new QWidget();
        tabQMP->setObjectName(QString::fromUtf8("tabQMP"));
        gridLayout_1 = new QGridLayout(tabQMP);
        gridLayout_1->setContentsMargins(5, 5, 5, 5);
        gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
        toUpB = new QPushButton(tabQMP);
        toUpB->setObjectName(QString::fromUtf8("toUpB"));
        toUpB->setMinimumSize(QSize(77, 20));
        toUpB->setMaximumSize(QSize(77, 20));

        gridLayout_1->addWidget(toUpB, 1, 2, 1, 1);

        label = new QLabel(tabQMP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(61, 17));
        label->setMaximumSize(QSize(61, 17));

        gridLayout_1->addWidget(label, 1, 0, 1, 1);

        pluginList = new QListWidget(tabQMP);
        pluginList->setObjectName(QString::fromUtf8("pluginList"));
        pluginList->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_1->addWidget(pluginList, 2, 0, 1, 4);

        applyButton = new QPushButton(tabQMP);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setMaximumSize(QSize(16777215, 22));
        applyButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_1->addWidget(applyButton, 3, 0, 1, 4);

        toDownB = new QPushButton(tabQMP);
        toDownB->setObjectName(QString::fromUtf8("toDownB"));
        toDownB->setMinimumSize(QSize(77, 20));
        toDownB->setMaximumSize(QSize(77, 20));

        gridLayout_1->addWidget(toDownB, 1, 3, 1, 1);

        tabWidget_2 = new QTabWidget(tabQMP);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(520, 227));
        tabWidget_2->setMaximumSize(QSize(16777215, 227));
        tabWidget_2->setUsesScrollButtons(false);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        setStyleB = new QPushButton(tab_1);
        setStyleB->setObjectName(QString::fromUtf8("setStyleB"));
        setStyleB->setGeometry(QRect(430, 130, 121, 27));
        abPB = new QPushButton(tab_1);
        abPB->setObjectName(QString::fromUtf8("abPB"));
        abPB->setGeometry(QRect(430, 40, 121, 27));
        opcjePB = new QPushButton(tab_1);
        opcjePB->setObjectName(QString::fromUtf8("opcjePB"));
        opcjePB->setGeometry(QRect(430, 70, 121, 27));
        naf1Box = new QCheckBox(tab_1);
        naf1Box->setObjectName(QString::fromUtf8("naf1Box"));
        naf1Box->setGeometry(QRect(10, 10, 151, 22));
        naf1Box->setCursor(QCursor(Qt::PointingHandCursor));
        loadPlugButton = new QPushButton(tab_1);
        loadPlugButton->setObjectName(QString::fromUtf8("loadPlugButton"));
        loadPlugButton->setGeometry(QRect(430, 10, 121, 27));
        delSetsButton = new QPushButton(tab_1);
        delSetsButton->setObjectName(QString::fromUtf8("delSetsButton"));
        delSetsButton->setGeometry(QRect(290, 130, 131, 41));
        naf1Frame = new QFrame(tab_1);
        naf1Frame->setObjectName(QString::fromUtf8("naf1Frame"));
        naf1Frame->setGeometry(QRect(20, 30, 181, 61));
        naf1Frame->setFrameShape(QFrame::NoFrame);
        naf1Frame->setFrameShadow(QFrame::Plain);
        zVpluginaB = new QRadioButton(naf1Frame);
        zVpluginaB->setObjectName(QString::fromUtf8("zVpluginaB"));
        zVpluginaB->setGeometry(QRect(10, 0, 161, 23));
        zVpluginaB->setCursor(QCursor(Qt::PointingHandCursor));
        zIpluginaB = new QRadioButton(naf1Frame);
        zIpluginaB->setObjectName(QString::fromUtf8("zIpluginaB"));
        zIpluginaB->setGeometry(QRect(10, 20, 161, 23));
        zIpluginaB->setCursor(QCursor(Qt::PointingHandCursor));
        defB = new QRadioButton(naf1Frame);
        defB->setObjectName(QString::fromUtf8("defB"));
        defB->setGeometry(QRect(10, 40, 161, 23));
        defB->setCursor(QCursor(Qt::PointingHandCursor));
        langB = new QPushButton(tab_1);
        langB->setObjectName(QString::fromUtf8("langB"));
        langB->setGeometry(QRect(430, 160, 121, 27));
        pbRBox = new QCheckBox(tab_1);
        pbRBox->setObjectName(QString::fromUtf8("pbRBox"));
        pbRBox->setGeometry(QRect(10, 110, 231, 22));
        pbRBox->setCursor(QCursor(Qt::PointingHandCursor));
        pbLBox = new QCheckBox(tab_1);
        pbLBox->setObjectName(QString::fromUtf8("pbLBox"));
        pbLBox->setGeometry(QRect(10, 90, 231, 22));
        pbLBox->setCursor(QCursor(Qt::PointingHandCursor));
        updB = new QPushButton(tab_1);
        updB->setObjectName(QString::fromUtf8("updB"));
        updB->setGeometry(QRect(290, 55, 131, 41));
        dockB = new QPushButton(tab_1);
        dockB->setObjectName(QString::fromUtf8("dockB"));
        dockB->setGeometry(QRect(290, 10, 131, 28));
        fileFilterB = new QCheckBox(tab_1);
        fileFilterB->setObjectName(QString::fromUtf8("fileFilterB"));
        fileFilterB->setGeometry(QRect(10, 130, 251, 23));
        fileFilterB->setCursor(QCursor(Qt::PointingHandCursor));
        chImgsB = new QCheckBox(tab_1);
        chImgsB->setObjectName(QString::fromUtf8("chImgsB"));
        chImgsB->setGeometry(QRect(10, 150, 271, 23));
        chImgsB->setCursor(QCursor(Qt::PointingHandCursor));
        eoplB = new QCheckBox(tab_1);
        eoplB->setObjectName(QString::fromUtf8("eoplB"));
        eoplB->setGeometry(QRect(10, 170, 301, 22));
        eoplB->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget_2->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        bladinfoB = new QCheckBox(tab_2);
        bladinfoB->setObjectName(QString::fromUtf8("bladinfoB"));
        bladinfoB->setGeometry(QRect(10, 60, 251, 21));
        bladinfoB->setCursor(QCursor(Qt::PointingHandCursor));
        PlaynxtBox = new QCheckBox(tab_2);
        PlaynxtBox->setObjectName(QString::fromUtf8("PlaynxtBox"));
        PlaynxtBox->setGeometry(QRect(10, 100, 371, 21));
        PlaynxtBox->setCursor(QCursor(Qt::PointingHandCursor));
        NxterrBox = new QCheckBox(tab_2);
        NxterrBox->setObjectName(QString::fromUtf8("NxterrBox"));
        NxterrBox->setGeometry(QRect(10, 80, 341, 22));
        NxterrBox->setCursor(QCursor(Qt::PointingHandCursor));
        savplistBox = new QCheckBox(tab_2);
        savplistBox->setObjectName(QString::fromUtf8("savplistBox"));
        savplistBox->setGeometry(QRect(10, 120, 161, 22));
        savplistBox->setCursor(QCursor(Qt::PointingHandCursor));
        savposBox = new QCheckBox(tab_2);
        savposBox->setObjectName(QString::fromUtf8("savposBox"));
        savposBox->setGeometry(QRect(10, 40, 211, 22));
        savposBox->setCursor(QCursor(Qt::PointingHandCursor));
        closeExportOnNxtB = new QCheckBox(tab_2);
        closeExportOnNxtB->setObjectName(QString::fromUtf8("closeExportOnNxtB"));
        closeExportOnNxtB->setGeometry(QRect(10, 20, 391, 22));
        closeExportOnNxtB->setCursor(QCursor(Qt::PointingHandCursor));
        pmppB = new QCheckBox(tab_2);
        pmppB->setObjectName(QString::fromUtf8("pmppB"));
        pmppB->setGeometry(QRect(10, 0, 281, 21));
        pmppB->setCursor(QCursor(Qt::PointingHandCursor));
        procBox = new QSpinBox(tab_2);
        procBox->setObjectName(QString::fromUtf8("procBox"));
        procBox->setGeometry(QRect(460, 115, 51, 25));
        procBox->setMinimum(1);
        procBox->setMaximum(60);
        procBox->setValue(10);
        label_f = new QLabel(tab_2);
        label_f->setObjectName(QString::fromUtf8("label_f"));
        label_f->setGeometry(QRect(320, 50, 131, 18));
        secBox = new QSpinBox(tab_2);
        secBox->setObjectName(QString::fromUtf8("secBox"));
        secBox->setGeometry(QRect(460, 45, 51, 25));
        secBox->setMinimum(2);
        secBox->setMaximum(99);
        secBox->setValue(10);
        label_o = new QLabel(tab_2);
        label_o->setObjectName(QString::fromUtf8("label_o"));
        label_o->setGeometry(QRect(320, 120, 131, 20));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(520, 50, 21, 18));
        uPLeLB = new QCheckBox(tab_2);
        uPLeLB->setObjectName(QString::fromUtf8("uPLeLB"));
        uPLeLB->setGeometry(QRect(10, 140, 341, 22));
        uPLeLB->setCursor(QCursor(Qt::PointingHandCursor));
        uPLeB = new QCheckBox(tab_2);
        uPLeB->setObjectName(QString::fromUtf8("uPLeB"));
        uPLeB->setGeometry(QRect(10, 160, 471, 22));
        uPLeB->setCursor(QCursor(Qt::PointingHandCursor));
        fileStructB = new QCheckBox(tab_2);
        fileStructB->setObjectName(QString::fromUtf8("fileStructB"));
        fileStructB->setGeometry(QRect(10, 180, 381, 22));
        fileStructB->setCursor(QCursor(Qt::PointingHandCursor));
        procB = new QRadioButton(tab_2);
        procB->setObjectName(QString::fromUtf8("procB"));
        procB->setGeometry(QRect(520, 106, 41, 23));
        procB->setCursor(QCursor(Qt::PointingHandCursor));
        sekB = new QRadioButton(tab_2);
        sekB->setObjectName(QString::fromUtf8("sekB"));
        sekB->setGeometry(QRect(520, 126, 41, 23));
        sekB->setCursor(QCursor(Qt::PointingHandCursor));
        unknownTypeB = new QCheckBox(tab_2);
        unknownTypeB->setObjectName(QString::fromUtf8("unknownTypeB"));
        unknownTypeB->setGeometry(QRect(390, 180, 181, 21));
        unknownTypeB->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget_2->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        proxyE = new QLineEdit(tab_4);
        proxyE->setObjectName(QString::fromUtf8("proxyE"));
        proxyE->setGeometry(QRect(110, 10, 451, 23));
        proxyB = new QCheckBox(tab_4);
        proxyB->setObjectName(QString::fromUtf8("proxyB"));
        proxyB->setGeometry(QRect(10, 10, 101, 22));
        proxyB->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 371, 17));
        maxSpdDwnB = new QSpinBox(tab_4);
        maxSpdDwnB->setObjectName(QString::fromUtf8("maxSpdDwnB"));
        maxSpdDwnB->setGeometry(QRect(20, 60, 71, 23));
        maxSpdDwnB->setMaximum(16384);
        maxSpdUplB = new QSpinBox(tab_4);
        maxSpdUplB->setObjectName(QString::fromUtf8("maxSpdUplB"));
        maxSpdUplB->setGeometry(QRect(20, 110, 71, 23));
        maxSpdUplB->setMaximum(16384);
        maxSpdUplB->setValue(0);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 371, 17));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 65, 41, 17));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 115, 41, 17));
        buffSizeB = new QSpinBox(tab_4);
        buffSizeB->setObjectName(QString::fromUtf8("buffSizeB"));
        buffSizeB->setGeometry(QRect(20, 160, 71, 23));
        buffSizeB->setMinimum(256);
        buffSizeB->setMaximum(65536);
        buffSizeB->setSingleStep(256);
        buffSizeB->setValue(8192);
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 165, 20, 20));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 140, 251, 18));
        autoUpdatesB = new QCheckBox(tab_4);
        autoUpdatesB->setObjectName(QString::fromUtf8("autoUpdatesB"));
        autoUpdatesB->setGeometry(QRect(280, 130, 281, 20));
        autoUpdatesB->setCursor(QCursor(Qt::PointingHandCursor));
        svrAddressE = new QLineEdit(tab_4);
        svrAddressE->setObjectName(QString::fromUtf8("svrAddressE"));
        svrAddressE->setGeometry(QRect(280, 160, 191, 24));
        svrAddressRestoreB = new QPushButton(tab_4);
        svrAddressRestoreB->setObjectName(QString::fromUtf8("svrAddressRestoreB"));
        svrAddressRestoreB->setGeometry(QRect(479, 160, 81, 27));
        tabWidget_2->addTab(tab_4, QString());

        gridLayout_1->addWidget(tabWidget_2, 0, 0, 1, 4);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_1->addItem(spacer, 1, 1, 1, 1);

        tabWidget->addTab(tabQMP, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        libsT = new QTabWidget(tab);
        libsT->setObjectName(QString::fromUtf8("libsT"));
        libsT->setUsesScrollButtons(true);
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        libsT->addTab(tab_8, QString());

        gridLayout_3->addWidget(libsT, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pluginsL = new QListWidget(tab_3);
        new QListWidgetItem(pluginsL);
        new QListWidgetItem(pluginsL);
        new QListWidgetItem(pluginsL);
        new QListWidgetItem(pluginsL);
        new QListWidgetItem(pluginsL);
        pluginsL->setObjectName(QString::fromUtf8("pluginsL"));
        pluginsL->setMaximumSize(QSize(160, 16777215));

        gridLayout_4->addWidget(pluginsL, 0, 0, 1, 1);

        inputT = new QTabWidget(tab_3);
        inputT->setObjectName(QString::fromUtf8("inputT"));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        inputT->addTab(tab_6, QString());

        gridLayout_4->addWidget(inputT, 0, 1, 1, 1);

        outputT = new QTabWidget(tab_3);
        outputT->setObjectName(QString::fromUtf8("outputT"));
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        outputT->addTab(tab_11, QString());

        gridLayout_4->addWidget(outputT, 0, 2, 1, 1);

        effectT = new QTabWidget(tab_3);
        effectT->setObjectName(QString::fromUtf8("effectT"));
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        effectT->addTab(tab_10, QString());

        gridLayout_4->addWidget(effectT, 0, 3, 1, 1);

        visT = new QTabWidget(tab_3);
        visT->setObjectName(QString::fromUtf8("visT"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        visT->addTab(tab_7, QString());

        gridLayout_4->addWidget(visT, 0, 4, 1, 1);

        funcT = new QTabWidget(tab_3);
        funcT->setObjectName(QString::fromUtf8("funcT"));
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        funcT->addTab(tab_9, QString());

        gridLayout_4->addWidget(funcT, 0, 5, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 6);

        spacer_2 = new QSpacerItem(241, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacer_2, 1, 0, 1, 1);

        QMPButton = new QPushButton(Form3);
        QMPButton->setObjectName(QString::fromUtf8("QMPButton"));
        QMPButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(QMPButton, 1, 1, 1, 1);

        prevButton = new QPushButton(Form3);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(prevButton, 1, 2, 1, 1);

        nxtButton = new QPushButton(Form3);
        nxtButton->setObjectName(QString::fromUtf8("nxtButton"));
        nxtButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(nxtButton, 1, 3, 1, 1);

        spacer_3 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacer_3, 1, 4, 1, 1);

        OKButton = new QPushButton(Form3);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));
        OKButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(OKButton, 1, 5, 1, 1);

        QWidget::setTabOrder(naf1Box, zVpluginaB);
        QWidget::setTabOrder(zVpluginaB, zIpluginaB);
        QWidget::setTabOrder(zIpluginaB, defB);
        QWidget::setTabOrder(defB, pbLBox);
        QWidget::setTabOrder(pbLBox, pbRBox);
        QWidget::setTabOrder(pbRBox, fileFilterB);
        QWidget::setTabOrder(fileFilterB, chImgsB);
        QWidget::setTabOrder(chImgsB, eoplB);
        QWidget::setTabOrder(eoplB, dockB);
        QWidget::setTabOrder(dockB, updB);
        QWidget::setTabOrder(updB, delSetsButton);
        QWidget::setTabOrder(delSetsButton, loadPlugButton);
        QWidget::setTabOrder(loadPlugButton, abPB);
        QWidget::setTabOrder(abPB, opcjePB);
        QWidget::setTabOrder(opcjePB, setStyleB);
        QWidget::setTabOrder(setStyleB, langB);
        QWidget::setTabOrder(langB, pluginList);
        QWidget::setTabOrder(pluginList, toUpB);
        QWidget::setTabOrder(toUpB, toDownB);
        QWidget::setTabOrder(toDownB, applyButton);
        QWidget::setTabOrder(applyButton, QMPButton);
        QWidget::setTabOrder(QMPButton, prevButton);
        QWidget::setTabOrder(prevButton, nxtButton);
        QWidget::setTabOrder(nxtButton, OKButton);
        QWidget::setTabOrder(OKButton, tabWidget_2);
        QWidget::setTabOrder(tabWidget_2, pmppB);
        QWidget::setTabOrder(pmppB, closeExportOnNxtB);
        QWidget::setTabOrder(closeExportOnNxtB, savposBox);
        QWidget::setTabOrder(savposBox, bladinfoB);
        QWidget::setTabOrder(bladinfoB, NxterrBox);
        QWidget::setTabOrder(NxterrBox, PlaynxtBox);
        QWidget::setTabOrder(PlaynxtBox, savplistBox);
        QWidget::setTabOrder(savplistBox, uPLeLB);
        QWidget::setTabOrder(uPLeLB, uPLeB);
        QWidget::setTabOrder(uPLeB, fileStructB);
        QWidget::setTabOrder(fileStructB, unknownTypeB);
        QWidget::setTabOrder(unknownTypeB, secBox);
        QWidget::setTabOrder(secBox, procBox);
        QWidget::setTabOrder(procBox, procB);
        QWidget::setTabOrder(procB, sekB);
        QWidget::setTabOrder(sekB, maxSpdDwnB);
        QWidget::setTabOrder(maxSpdDwnB, maxSpdUplB);
        QWidget::setTabOrder(maxSpdUplB, buffSizeB);
        QWidget::setTabOrder(buffSizeB, autoUpdatesB);
        QWidget::setTabOrder(autoUpdatesB, svrAddressE);
        QWidget::setTabOrder(svrAddressE, svrAddressRestoreB);
        QWidget::setTabOrder(svrAddressRestoreB, libsT);
        QWidget::setTabOrder(libsT, pluginsL);
        QWidget::setTabOrder(pluginsL, inputT);
        QWidget::setTabOrder(inputT, outputT);
        QWidget::setTabOrder(outputT, effectT);
        QWidget::setTabOrder(effectT, visT);
        QWidget::setTabOrder(visT, funcT);
        QWidget::setTabOrder(funcT, tabWidget);
        QWidget::setTabOrder(tabWidget, proxyB);
        QWidget::setTabOrder(proxyB, proxyE);

        retranslateUi(Form3);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        libsT->setCurrentIndex(0);
        inputT->setCurrentIndex(0);
        outputT->setCurrentIndex(0);
        effectT->setCurrentIndex(0);
        visT->setCurrentIndex(0);
        funcT->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        toUpB->setText(QApplication::translate("Form3", "\341\220\261", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form3", "Pluginy:", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
        toDownB->setText(QApplication::translate("Form3", "\341\220\257", 0, QApplication::UnicodeUTF8));
        setStyleB->setText(QApplication::translate("Form3", "Ustaw styl", 0, QApplication::UnicodeUTF8));
        abPB->setText(QApplication::translate("Form3", "O wtyczce", 0, QApplication::UnicodeUTF8));
        opcjePB->setText(QApplication::translate("Form3", "Opcje wtyczki", 0, QApplication::UnicodeUTF8));
        naf1Box->setText(QApplication::translate("Form3", "Pokaz Vizualizacje", 0, QApplication::UnicodeUTF8));
        loadPlugButton->setText(QApplication::translate("Form3", "Prze\305\202aduj wtyczki", 0, QApplication::UnicodeUTF8));
        delSetsButton->setText(QApplication::translate("Form3", "Usu\305\204 ustawienia\n"
"programu", 0, QApplication::UnicodeUTF8));
        zVpluginaB->setText(QApplication::translate("Form3", "Z Vis. plugina", 0, QApplication::UnicodeUTF8));
        zIpluginaB->setText(QApplication::translate("Form3", "Z Input plugina", 0, QApplication::UnicodeUTF8));
        defB->setText(QApplication::translate("Form3", "Z QMP", 0, QApplication::UnicodeUTF8));
        langB->setText(QApplication::translate("Form3", "Wybierz j\304\231zyk", 0, QApplication::UnicodeUTF8));
        pbRBox->setText(QApplication::translate("Form3", "Poka\305\274 g\305\202o\305\233no\305\233\304\207 kana\305\202u prawego", 0, QApplication::UnicodeUTF8));
        pbLBox->setText(QApplication::translate("Form3", "Poka\305\274 g\305\202o\305\233no\305\233\304\207 kana\305\202u lewego", 0, QApplication::UnicodeUTF8));
        updB->setText(QApplication::translate("Form3", "Sprawd\305\272\n"
"aktualizacje", 0, QApplication::UnicodeUTF8));
        dockB->setText(QApplication::translate("Form3", "Zadokuj", 0, QApplication::UnicodeUTF8));
        fileFilterB->setText(QApplication::translate("Form3", "Dodawaj tylko znane typy plik\303\263w", 0, QApplication::UnicodeUTF8));
        chImgsB->setText(QApplication::translate("Form3", "Pokazuj obrazek w okienku playlisty", 0, QApplication::UnicodeUTF8));
        eoplB->setText(QApplication::translate("Form3", "Dodawaj nowe wpisy na ko\305\204cu playlisty", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_1), QApplication::translate("Form3", "Strona 1", 0, QApplication::UnicodeUTF8));
        bladinfoB->setText(QApplication::translate("Form3", "Nie informuj o b\305\202\304\231dzie na starcie", 0, QApplication::UnicodeUTF8));
        PlaynxtBox->setText(QApplication::translate("Form3", "Zacznij odtwarza\304\207 po naci\305\233ni\304\231ciu przycisku \"Next\"", 0, QApplication::UnicodeUTF8));
        NxterrBox->setText(QApplication::translate("Form3", "Odtwarzaj nast\304\231pny plik po wyst\304\205pieniu b\305\202\304\231du", 0, QApplication::UnicodeUTF8));
        savplistBox->setText(QApplication::translate("Form3", "Zapisuj playlist\304\231", 0, QApplication::UnicodeUTF8));
        savposBox->setText(QApplication::translate("Form3", "Zapisuj pozycj\304\231 muzyki", 0, QApplication::UnicodeUTF8));
        closeExportOnNxtB->setText(QApplication::translate("Form3", "Zako\305\204cz eksport do pliku przy prze\305\202\304\205czaniu muzyki", 0, QApplication::UnicodeUTF8));
        pmppB->setText(QApplication::translate("Form3", "Podgl\304\205d muzyki podczas przewijania", 0, QApplication::UnicodeUTF8));
        label_f->setText(QApplication::translate("Form3", "Odtwarzaj pierwsze:", 0, QApplication::UnicodeUTF8));
        label_o->setText(QApplication::translate("Form3", "Przewijaj muzyk\304\231 o:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form3", "s", 0, QApplication::UnicodeUTF8));
        uPLeLB->setText(QApplication::translate("Form3", "\305\201aduj czas i tytu\305\202 playlisty *.m3u i *.pls z pliku", 0, QApplication::UnicodeUTF8));
        uPLeB->setText(QApplication::translate("Form3", "Uaktualniaj informacje o muzyce podczas rozpocz\304\231cia odtwarzania", 0, QApplication::UnicodeUTF8));
        fileStructB->setText(QApplication::translate("Form3", "Rozpoznawaj pliki po strukturze a nie po rozszerzeniu", 0, QApplication::UnicodeUTF8));
        procB->setText(QApplication::translate("Form3", "%", 0, QApplication::UnicodeUTF8));
        sekB->setText(QApplication::translate("Form3", "s", 0, QApplication::UnicodeUTF8));
        unknownTypeB->setText(QApplication::translate("Form3", "Je\305\274eli nieznany typ", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("Form3", "Strona 2", 0, QApplication::UnicodeUTF8));
        proxyB->setText(QApplication::translate("Form3", "U\305\274yj proxy", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form3", "Maksymalna szybko\305\233\304\207 pobierania (0 - bez ogranicze\305\204):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form3", "Maksymalna szybko\305\233\304\207 wysy\305\202ania (0 - bez ogranicze\305\204):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form3", "kB/s", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form3", "kB/s", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form3", "B", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form3", "Rozmiar bufora (domy\305\233lnie 8192 B)", 0, QApplication::UnicodeUTF8));
        autoUpdatesB->setText(QApplication::translate("Form3", "Automatycznie sprawdzaj aktualizacje", 0, QApplication::UnicodeUTF8));
        svrAddressRestoreB->setText(QApplication::translate("Form3", "Przywr\303\263\304\207", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Form3", "Strona 3 -> ustawienia dost\304\231pu do Internetu", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabQMP), QApplication::translate("Form3", "Ustawienia QMP", 0, QApplication::UnicodeUTF8));
        libsT->setTabText(libsT->indexOf(tab_8), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form3", "G\305\202\303\263wne biblioteki", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = pluginsL->isSortingEnabled();
        pluginsL->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = pluginsL->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Form3", "Input plugin", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = pluginsL->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Form3", "Output plugin", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = pluginsL->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Form3", "Effect plugin", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = pluginsL->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Form3", "Visualisation plugin", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = pluginsL->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Form3", "Function plugin", 0, QApplication::UnicodeUTF8));
        pluginsL->setSortingEnabled(__sortingEnabled);

        inputT->setTabText(inputT->indexOf(tab_6), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        outputT->setTabText(outputT->indexOf(tab_11), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        effectT->setTabText(effectT->indexOf(tab_10), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        visT->setTabText(visT->indexOf(tab_7), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        funcT->setTabText(funcT->indexOf(tab_9), QApplication::translate("Form3", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form3", "Wtyczki", 0, QApplication::UnicodeUTF8));
        QMPButton->setText(QApplication::translate("Form3", "Opcje QMP", 0, QApplication::UnicodeUTF8));
        prevButton->setText(QApplication::translate("Form3", "<", 0, QApplication::UnicodeUTF8));
        nxtButton->setText(QApplication::translate("Form3", ">", 0, QApplication::UnicodeUTF8));
        OKButton->setText(QApplication::translate("Form3", "Zamknij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
