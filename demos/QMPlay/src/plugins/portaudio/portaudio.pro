TEMPLATE = lib

TARGET = qmp_plugin_pa
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

LIBS += -lportaudio
win32:LIBS += -lwinmm -lksguid

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_pa_outputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
