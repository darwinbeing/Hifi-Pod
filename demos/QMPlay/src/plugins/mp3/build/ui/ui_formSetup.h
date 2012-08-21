/********************************************************************************
** Form generated from reading UI file 'formSetup.ui'
**
** Created: Tue Aug 21 20:18:27 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form3
{
public:
    QGridLayout *gridLayout;
    QCheckBox *enabledB;
    QLineEdit *extsB;
    QCheckBox *notReadID3;
    QCheckBox *searchPartsB;
    QCheckBox *wait4DataB;
    QPushButton *ApplyB;

    void setupUi(QWidget *Form3)
    {
        if (Form3->objectName().isEmpty())
            Form3->setObjectName(QString::fromUtf8("Form3"));
        Form3->resize(259, 162);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Form3->setWindowIcon(icon);
        gridLayout = new QGridLayout(Form3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        enabledB = new QCheckBox(Form3);
        enabledB->setObjectName(QString::fromUtf8("enabledB"));
        enabledB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(enabledB, 0, 0, 1, 1);

        extsB = new QLineEdit(Form3);
        extsB->setObjectName(QString::fromUtf8("extsB"));

        gridLayout->addWidget(extsB, 1, 0, 1, 1);

        notReadID3 = new QCheckBox(Form3);
        notReadID3->setObjectName(QString::fromUtf8("notReadID3"));
        notReadID3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(notReadID3, 2, 0, 1, 1);

        searchPartsB = new QCheckBox(Form3);
        searchPartsB->setObjectName(QString::fromUtf8("searchPartsB"));
        searchPartsB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(searchPartsB, 3, 0, 1, 1);

        wait4DataB = new QCheckBox(Form3);
        wait4DataB->setObjectName(QString::fromUtf8("wait4DataB"));
        wait4DataB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(wait4DataB, 4, 0, 1, 1);

        ApplyB = new QPushButton(Form3);
        ApplyB->setObjectName(QString::fromUtf8("ApplyB"));
        ApplyB->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(ApplyB, 5, 0, 1, 1);

        QWidget::setTabOrder(enabledB, extsB);
        QWidget::setTabOrder(extsB, notReadID3);
        QWidget::setTabOrder(notReadID3, searchPartsB);
        QWidget::setTabOrder(searchPartsB, wait4DataB);
        QWidget::setTabOrder(wait4DataB, ApplyB);

        retranslateUi(Form3);

        QMetaObject::connectSlotsByName(Form3);
    } // setupUi

    void retranslateUi(QWidget *Form3)
    {
        Form3->setWindowTitle(QApplication::translate("Form3", "Ustawienia", 0, QApplication::UnicodeUTF8));
        enabledB->setText(QApplication::translate("Form3", "W\305\202\304\205cz wtyczk\304\231", 0, QApplication::UnicodeUTF8));
        notReadID3->setText(QApplication::translate("Form3", "Nie odczytuj ID3 dla wpis\303\263w playlisty", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        searchPartsB->setToolTip(QApplication::translate("Form3", "Kiedy plik MP3 nie jest kompletny i brakuje mu jaki\305\233 cz\304\231\305\233ci, to szuka dane a\305\274 do ko\305\204ca pliku", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        searchPartsB->setText(QApplication::translate("Form3", "Wyszukuj cz\304\231\305\233ci", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        wait4DataB->setToolTip(QApplication::translate("Form3", "Kiedy po\305\202\304\205czenie z serwerem zostanie zerwane lub si\304\231 zawiesi, QMPlay nie przerwie odtwarzania tylko b\304\231dzie czeka\305\202 na dane", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        wait4DataB->setText(QApplication::translate("Form3", "Czekaj na dane", 0, QApplication::UnicodeUTF8));
        ApplyB->setText(QApplication::translate("Form3", "Zastosuj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form3: public Ui_Form3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUP_H
