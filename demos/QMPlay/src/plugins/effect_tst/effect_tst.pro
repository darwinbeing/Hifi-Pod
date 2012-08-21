TEMPLATE = lib

TARGET = qmp_plugin_effect_tst
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += qmp_effect_tst.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
