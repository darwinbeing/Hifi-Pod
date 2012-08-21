TEMPLATE = lib

TARGET = qmp_plugin_mm
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

LIBS += -lmikmod

FORMS += formMMSlider.ui formMod.ui formSplIns.ui formSetup.ui
HEADERS += formMMSlider.h formMod.h formSplIns.h formSetup.h
SOURCES += qmp_mikmod_inputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
