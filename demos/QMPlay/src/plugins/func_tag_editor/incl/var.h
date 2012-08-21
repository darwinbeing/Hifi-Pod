#include <cstdio>
#include <cstring>

#include <QString>
#include <QMenu>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QSettings>
#include <QImageReader>

#include "struct.h"

#include "QLib.cpp"
Qmp *QLib = NULL;

QSettings *QMPset;

bool hOptions(0), hFuncWin(1);

const int langCount(4);
QStringList Texts;
QString langfile;
