TEMPLATE = lib

TARGET = qmp_plugin_ao
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

LIBS += -lao
win32:LIBS += -lwinmm

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_ao_outputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
