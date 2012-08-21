TEMPLATE = app
SOURCES += QMPlay.cpp

win32:TARGET=QMPlay
else:TARGET=qmplay
DESTDIR = ../../qmplay

mac:QMAKE_INFO_PLIST = MacOS/QMPlay.plist

windows:RC_FILE = Windows/icon.rc
windows:DEFINES -= UNICODE

OBJECTS_DIR = build/obj

CONFIG += release
