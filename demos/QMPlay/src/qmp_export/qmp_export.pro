TEMPLATE = lib

DESTDIR = ../../qmplay/lib

DEPENDPATH += incl forms ../common ../common/struct
INCLUDEPATH += incl forms ../common ../common/struct

DEPENDPATH += incl forms
INCLUDEPATH += incl forms

FORMS += formSetup.ui
HEADERS += formSetup.h save.h
SOURCES += qmp_wav_outputplugin.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
