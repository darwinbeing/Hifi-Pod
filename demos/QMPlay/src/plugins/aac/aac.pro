TEMPLATE = lib

TARGET = qmp_plugin_aac
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

LIBS += -lfaad -lmp4ff

FORMS += formAac.ui formSetup.ui
HEADERS += formAac.h formSetup.h
SOURCES += qmp_aac_inputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
