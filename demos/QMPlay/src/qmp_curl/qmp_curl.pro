TEMPLATE = lib

TARGET = qmp_internet_support
DESTDIR = ../../qmplay/lib

DEPENDPATH += ../common ../common/struct
INCLUDEPATH += ../common ../common/struct

LIBS += -lcurl
windows:LIBS += -lws2_32

SOURCES += qmp_internet_support.cpp

OBJECTS_DIR = build/obj

CONFIG += release plugin
