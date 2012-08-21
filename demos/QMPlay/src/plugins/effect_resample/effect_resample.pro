TEMPLATE = lib

TARGET = qmp_plugin_effect_resample
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct libresample/include
INCLUDEPATH += incl forms ../../common ../../common/struct libresample/include

FORMS += formSetup.ui
HEADERS += formSetup.h libresample.h
SOURCES += qmp_effect_resample.cpp libresample/src/filterkit.c libresample/src/resample.c libresample/src/resamplesubs.c

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
