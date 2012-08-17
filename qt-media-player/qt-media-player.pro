## Edit this line to add/remove the features you need
CONFIG += dialog

## These lines will try to automatically add features if dependencies are met
unix:CONFIG += hotkey
#exists( /usr/include/KDE/KFileDialog ):CONFIG += kde
exists( /usr/include/taglib/tag.h ):CONFIG += taglib
#exists( /usr/include/rubberband/RubberBandStretcher.h ):CONFIG += stretch
exists( /usr/include/fsrc.h ):CONFIG += fsrc

## Mandatory features (depends on ffmpeg and alsa)

SOURCES += main.cpp avfile.cpp audio.cpp
HEADERS += main.h avfile.h audio.h
LIBS += -lavcodec -lavformat -lasound

## Choose your file dialog

kde {
# network transparent file dialog also allowing multiple files/folders selection (KDE dialog)
    DEFINES += USE_KDE
    LIBS += -lkio
} else:dialog {
# simple file dialog allowing multiple files/folders selection (own implementation)
    DEFINES += USE_DIALOG
    SOURCES += dialog.cpp
    HEADERS += dialog.h
} # else QFileDialog (doesn't allow multiple directories)

## Optionnal features

video {
# enable video playback (need GLSL capable GPU)
    QT += opengl
    DEFINES += USE_VIDEO
    SOURCES += video.cpp
    HEADERS += video.h
}

taglib {
# 4x faster tag parsing than libavformat (need TagLib)
    DEFINES += USE_TAGLIB
    LIBS += -ltag
}

hotkey {
# global hotkey support (X11 only supported)
    DEFINES += USE_HOTKEY
    SOURCES += hotkey.cpp
    HEADERS += hotkey.h
}

fsrc {
# high quality audio sample rate conversion
    DEFINES += USE_FSRC
    LIBS += -L. -lfsrc
}

ftp {
# play remote media directly from an FTP server
    QT += network
    DEFINES += USE_FTP
    SOURCES += ftp.cpp
    HEADERS += ftp.h
}

stretch {
# high quality time stretching (need RubberBand)
    DEFINES += USE_RUBBERBAND
    SOURCES += stretch.cpp
    HEADERS += stretch.h
    LIBS += -lrubberband
}

mark {
# mark the current position for replay (useful to study a video)
    DEFINES += USE_MARK
}

OBJECTS_DIR=build
MOC_DIR=build
DESTDIR=build

bin.path = /usr/bin
bin.files = build/qt-media-player
desktop.path = /usr/share/applications
desktop.files = qt-media-player.desktop
INSTALLS += bin desktop

touchscreen {
#install touchscreen stylesheet and an application shortcut to use it
    touchscreen.path = /usr/share/qt4/stylesheets
    touchscreen.files = touchscreen.qss
    INSTALLS += touchscreen
    desktop.files += qt-media-player-touch.desktop
}

OTHER_FILES = touchscreen.qss
