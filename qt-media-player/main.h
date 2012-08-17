#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QSlider>
#include <QLabel>
#include <QTreeWidget>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>
#include <QSettings>
#include <QTimer>
#include <QTime>
#include <QDir>

#include "media.h"
#include "avfile.h"
#include "audio.h"

#ifdef USE_KDE
#include <KDE/KFileDialog>
#else
#ifdef USE_DIALOG
#include "dialog.h"
#else
#include <QFileDialog>
#endif
#endif
#ifdef USE_VIDEO
#include "video.h"
#endif
#ifdef USE_TAGLIB
#include <taglib/fileref.h>
#include <taglib/tag.h>
#endif
#ifdef USE_HOTKEY
#include "hotkey.h"
#endif
#ifdef USE_FTP
#include "ftp.h"
#endif
#ifdef USE_RUBBERBAND
#include "stretch.h"
#endif

class Player : public QMainWindow {
    Q_OBJECT
public:
    Player();
    ~Player();
public slots:
    void open();
    void loadMetadata();
    void fitWindow();
    void play(QTreeWidgetItem*);
    void next();
    void start();
    void stop();
    void positionChanged();
    void toggleOpen(bool);
    void togglePlay(bool);
#ifdef USE_VIDEO
    void toggleFullScreen();
#endif
#ifdef USE_MARK
    void toggleMark(bool);
#endif
#ifdef USE_RUBBERBAND
    void toggleSlow(bool);
#endif
private:
    void append(QString);
private:
    AVFile* file;
    AlsaOutput* audio;

    QToolBar toolBar;
    QAction* openAction;
    QAction* playAction;
    QSlider slider;
    QLabel elapsed;
    QLabel remaining;
    QTreeWidget playlist;
    QList<QTreeWidgetItem*> metadataQueue;
#ifdef USE_KDE
    KFileDialog* dialog;
#else
#ifdef USE_DIALOG
    FileDialog* dialog;
#else
    QFileDialog* dialog;
#endif
#endif
#ifdef USE_MARK
    QAction* markAction;
    int64_t markPosition;
#endif
#ifdef USE_VIDEO
    VideoWidget* video;
#endif
#ifdef USE_RUBBERBAND
    AudioStretcher* audioStretcher;
    VideoStretcher* videoStretcher;
#endif
};
