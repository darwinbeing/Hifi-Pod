TEMPLATE = lib

TARGET = qmp_plugin_func_radio
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formFunc.ui
HEADERS += formFunc.h
SOURCES += qmp_func_radio.cpp

RESOURCES += plug_icon.qrc

RCC_DIR = build/rcc
UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
