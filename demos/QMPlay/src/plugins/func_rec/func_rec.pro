TEMPLATE = lib

TARGET = qmp_plugin_func_rec
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formFunc.ui
HEADERS += formFunc.h
SOURCES += qmp_func_rec.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
