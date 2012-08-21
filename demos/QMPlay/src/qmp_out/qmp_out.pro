TEMPLATE = lib

DESTDIR = ../../qmplay/lib

DEPENDPATH += incl forms ../common ../common/struct
INCLUDEPATH += incl forms ../common ../common/struct

QMAKE_CXXFLAGS += -fsigned-char

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += main.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
