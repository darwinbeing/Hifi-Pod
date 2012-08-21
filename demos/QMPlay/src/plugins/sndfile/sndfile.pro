TEMPLATE = lib

TARGET = qmp_plugin_sndfile
DESTDIR = ../../../qmplay/plugins

LIBS += -lsndfile -lFLAC
win32:LIBS += -lws2_32

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui formSndfile.ui
HEADERS += formSetup.h formSndfile.h
SOURCES += qmp_sndfile_inputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
