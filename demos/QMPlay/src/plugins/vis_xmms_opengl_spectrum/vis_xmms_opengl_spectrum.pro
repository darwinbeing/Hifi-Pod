TEMPLATE = lib

TARGET = qmp_plugin_vis_xos
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct ../../common/kiss_fft
INCLUDEPATH += incl forms ../../common ../../common/struct ../../common/kiss_fft

QT += opengl

QMAKE_CFLAGS_RELEASE = -O3 -ffast-math -fomit-frame-pointer -dA

FORMS += formSetup.ui
HEADERS += FormVis.h formSetup.h
SOURCES += kiss_fft.c qmp_vis_xos.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
