TEMPLATE = lib

TARGET = qmp_plugin_mp3
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

LIBS += -lmpg123

FORMS += formMp3.ui formSetup.ui
HEADERS += formMp3.h formSetup.h
SOURCES += qmp_mp3_inputplugin.cpp forms.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
