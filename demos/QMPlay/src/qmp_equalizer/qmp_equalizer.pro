TEMPLATE = lib

DESTDIR = ../../qmplay/lib

DEPENDPATH += incl forms ../common ../common/struct
INCLUDEPATH += incl forms ../common ../common/struct

DEPENDPATH += forms incl ../common/kiss_fft
INCLUDEPATH += forms incl ../common/kiss_fft

QMAKE_CFLAGS_RELEASE = -O3 -ffast-math -fomit-frame-pointer -dA

FORMS += formSetup.ui
HEADERS += formSetup.h
SOURCES += kiss_fft.c qmp_equalizer.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
