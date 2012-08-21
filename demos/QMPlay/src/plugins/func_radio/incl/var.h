#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <QMenu>
#include <QClipboard>
#include <QUrl>

#include "QLib.cpp"
Qmp *QLib = NULL;

QWidget *tmpWidget = NULL;

const int langCount(3+1);
QStringList Texts;

bool hOptions(0), hFuncWin(1);
bool once = false;
bool onceShow = false;

QSettings *QMPset;

QString QMPConf;

const int MAX_ILE = 3;

#include "QMPInternet_Load.cpp"

#endif
