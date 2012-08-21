TEMPLATE = lib

TARGET = qmp_plugin_cd
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

RESOURCES += plug_icon.qrc

LIBS += -lcddb -lcdio
win32:LIBS += -liconv -lregex -lwsock32 -lwinmm

FORMS += formSetup.ui formInfo.ui
HEADERS += formSetup.h formInfo.h
SOURCES += qmp_cd_inputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc

CONFIG += release plugin
