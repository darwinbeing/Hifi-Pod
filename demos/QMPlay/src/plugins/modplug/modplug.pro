TEMPLATE = lib

TARGET = qmp_plugin_mp
DESTDIR = ../../../qmplay/plugins

DEPENDPATH += incl forms ../../common ../../common/struct
INCLUDEPATH += incl forms ../../common ../../common/struct

FORMS += formSetup.ui formMod.ui formMod2.ui
HEADERS += formSetup.h formMod.h formMod2.h
SOURCES += qmp_modplug_inputplugin.cpp

win32: DEFINES -= UNICODE

#libmodplug
DEPENDPATH += libmodplug
INCLUDEPATH += libmodplug
SOURCES += fastmix.cpp load_ams.cpp load_dsm.cpp load_j2b.cpp load_mod.cpp load_okt.cpp load_s3m.cpp load_umx.cpp modplug.cpp snd_flt.cpp load_669.cpp load_dbm.cpp load_far.cpp load_mdl.cpp load_mt2.cpp load_psm.cpp load_stm.cpp load_xm.cpp snd_dsp.cpp snd_fx.cpp load_amf.cpp load_dmf.cpp load_it.cpp load_med.cpp load_mtm.cpp load_ptm.cpp load_ult.cpp mmcmp.cpp sndfile.cpp sndmix.cpp

UI_DIR = build/ui
MOC_DIR = build/moc
OBJECTS_DIR = build/obj

CONFIG += release plugin
