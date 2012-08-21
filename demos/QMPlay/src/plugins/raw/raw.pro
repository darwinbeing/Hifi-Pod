TEMPLATE = lib

TARGET = qmp_plugin_raw
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_raw_inputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
unix:OBJECTS_DIR = build/obj

CONFIG += release plugin
