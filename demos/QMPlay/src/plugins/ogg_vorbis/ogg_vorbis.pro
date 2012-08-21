TEMPLATE = lib

TARGET = qmp_plugin_ogg
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

RESOURCES += plug_icon.qrc

LIBS += -lvorbisfile -lvorbis -logg

FORMS += formOgg.ui formSetup.ui
HEADERS += formOgg.h formSetup.h
SOURCES += qmp_vorbis_inputplugin.cpp forms.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc

CONFIG += release plugin
