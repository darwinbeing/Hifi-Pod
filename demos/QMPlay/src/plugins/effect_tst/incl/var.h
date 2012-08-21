#ifndef __VAR_H__
#define __VAR_H__

#include <QString>
#include <QDir>
#include <QSettings>
#include <QMessageBox>

bool Enabled, effVoice, effEcho, effSkip, effSzybko, voice, echoSurround, hOptions(1), effWolno, canChEchoVal(0);
char effInvert;
QString QMPConf;
QSettings *QMPset;
int echo_delay, echo_feedback, echo_volume, p1s, p2s;

#endif
