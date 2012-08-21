TEMPLATE = lib

DESTDIR = ../../qmplay/lib

DEPENDPATH += incl forms ../common ../common/struct
INCLUDEPATH += incl forms ../common ../common/struct

windows:LIBS += -lshlwapi

mac:LIBS += -framework Carbon

RESOURCES += icons.qrc

HEADERS += form1.h formSetup.h formPlaylist.h formFunc.h formSL.h formStyle.h formLang.h formAbout.h formProp.h formCp.h formDownload.h formDockCh.h miniQMP.h musicInfo.h
FORMS += form1.ui formSetup.ui formPlaylist.ui formFunc.ui formSL.ui formStyle.ui formLang.ui formAbout.ui formProp.ui formCp.ui formDownload.ui formDockCh.ui miniQMP.ui musicInfo.ui
SOURCES += main.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc

CONFIG += release plugin
