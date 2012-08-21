TEMPLATE = lib

TARGET = qmp_plugin_snd_generator
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_snd_generator_inputplugin.cpp forms.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
