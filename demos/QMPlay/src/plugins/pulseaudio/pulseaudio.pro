TEMPLATE = lib

TARGET = qmp_plugin_Pulseaudio
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_pulseaudio_outputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
