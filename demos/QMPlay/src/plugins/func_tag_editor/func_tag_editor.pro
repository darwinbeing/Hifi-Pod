TEMPLATE = lib
DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

TARGET = qmp_plugin_func_tag_editor
DESTDIR = ../../../qmplay/plugins

unix: INCLUDEPATH += /usr/include/taglib
win32: INCLUDEPATH += c:/mingw/include/taglib

LIBS += -ltag
win32: LIBS += -lz

RESOURCES += plug_icon.qrc

HEADERS += window.h
FORMS += window.ui
SOURCES += qmplay_func.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc

CONFIG += release plugin
