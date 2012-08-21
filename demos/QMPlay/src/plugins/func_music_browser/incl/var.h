#ifndef __VAR_H__
#define __VAR_H__

#include <QTextDocumentFragment>
#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <QMenu>
#include <QClipboard>
#include <QFileDialog>
#include <QUrl>

#include "QLib.cpp"
Qmp *QLib = NULL;

QTimer timRef;

QMenu mnuT, mnuQ;

QWidget *tmpWidget = NULL;

const int langCount(24+1);
QStringList Texts;

QString pth;

bool hOptions(0), hFuncWin(1), mustGetExts(0), as(0), notInFunc(0);
bool once  = false;

QSettings *QMPset;

QString QMPConf;

const int MAX_ILE = 3;

#include "QMPInternet_Load.cpp"

#endif
