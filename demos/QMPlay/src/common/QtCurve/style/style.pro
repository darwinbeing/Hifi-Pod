TEMPLATE = lib

TARGET = qtcurve
DESTDIR = ../../../../qmplay/styles

DEPENDPATH += . ../common
INCLUDEPATH += . ../common

DEFINES += QTC_QT_ONLY

HEADERS += qtcurve.h
SOURCES += qtcurve.cpp

CONFIG += release plugin

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc
