TEMPLATE = lib

TARGET = qmp_plugin_playlists
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += ../../common ../../common/struct
INCLUDEPATH += ../../common ../../common/struct

SOURCES += playlists.cpp

MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
