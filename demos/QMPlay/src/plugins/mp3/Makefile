#############################################################################
# Makefile for building: libqmp_plugin_mp3.so
# Generated by qmake (2.01a) (Qt 4.6.2) on: Tue Aug 21 20:18:27 2012
# Project:  mp3.pro
# Template: lib
# Command: /usr/bin/qmake -unix -o Makefile mp3.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_PLUGIN -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Iincl -Iforms -I../../common -I../../common/struct -Ibuild/moc -Ibuild/ui
LINK          = g++
LFLAGS        = -Wl,-O1 -shared
LIBS          = $(SUBLIBS)  -L/usr/lib -lmpg123 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/obj/

####### Files

SOURCES       = qmp_mp3_inputplugin.cpp build/moc/moc_formMp3.cpp \
		build/moc/moc_formSetup.cpp
OBJECTS       = build/obj/qmp_mp3_inputplugin.o \
		build/obj/moc_formMp3.o \
		build/obj/moc_formSetup.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		mp3.pro
QMAKE_TARGET  = qmp_plugin_mp3
DESTDIR       = ../../../qmplay/plugins/
TARGET        = libqmp_plugin_mp3.so
TARGETD       = libqmp_plugin_mp3.so

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile  ../../../qmplay/plugins/$(TARGET)

../../../qmplay/plugins/$(TARGET): build/ui/ui_formMp3.h build/ui/ui_formSetup.h $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@$(CHK_DIR_EXISTS) ../../../qmplay/plugins/ || $(MKDIR) ../../../qmplay/plugins/ 
	-$(DEL_FILE) $(TARGET)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-$(MOVE) $(TARGET) ../../../qmplay/plugins/



Makefile: mp3.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile mp3.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile mp3.pro

dist: 
	@$(CHK_DIR_EXISTS) build/obj/qmp_plugin_mp31.0.0 || $(MKDIR) build/obj/qmp_plugin_mp31.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/obj/qmp_plugin_mp31.0.0/ && $(COPY_FILE) --parents forms/formMp3.h forms/formSetup.h build/obj/qmp_plugin_mp31.0.0/ && $(COPY_FILE) --parents qmp_mp3_inputplugin.cpp build/obj/qmp_plugin_mp31.0.0/ && $(COPY_FILE) --parents forms/formMp3.ui forms/formSetup.ui build/obj/qmp_plugin_mp31.0.0/ && (cd `dirname build/obj/qmp_plugin_mp31.0.0` && $(TAR) qmp_plugin_mp31.0.0.tar qmp_plugin_mp31.0.0 && $(COMPRESS) qmp_plugin_mp31.0.0.tar) && $(MOVE) `dirname build/obj/qmp_plugin_mp31.0.0`/qmp_plugin_mp31.0.0.tar.gz . && $(DEL_FILE) -r build/obj/qmp_plugin_mp31.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc/moc_formMp3.cpp build/moc/moc_formSetup.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc/moc_formMp3.cpp build/moc/moc_formSetup.cpp
build/moc/moc_formMp3.cpp: build/ui/ui_formMp3.h \
		forms/formMp3.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) forms/formMp3.h -o build/moc/moc_formMp3.cpp

build/moc/moc_formSetup.cpp: build/ui/ui_formSetup.h \
		forms/formSetup.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) forms/formSetup.h -o build/moc/moc_formSetup.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui/ui_formMp3.h build/ui/ui_formSetup.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui/ui_formMp3.h build/ui/ui_formSetup.h
build/ui/ui_formMp3.h: forms/formMp3.ui
	/usr/bin/uic-qt4 forms/formMp3.ui -o build/ui/ui_formMp3.h

build/ui/ui_formSetup.h: forms/formSetup.ui
	/usr/bin/uic-qt4 forms/formSetup.ui -o build/ui/ui_formSetup.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/obj/qmp_mp3_inputplugin.o: qmp_mp3_inputplugin.cpp incl/var.h \
		../../common/Functions.cpp \
		../../common/struct/QLib.cpp \
		../../common/struct/QOut.cpp \
		../../common/ID3.cpp \
		../../common/QMPlay_tag_editor.cpp \
		../../common/struct/QMPlay_tag_editor.h \
		../../common/QMPInternet_Load.cpp \
		../../common/libExt.h \
		forms/formMp3.h \
		build/ui/ui_formMp3.h \
		forms/formSetup.h \
		build/ui/ui_formSetup.h \
		incl/mp3_pl.h \
		incl/save.h \
		incl/save.cpp \
		../../common/struct/InputPlugin.cpp \
		../../common/struct/PluginInfo.h \
		../../common/internet_stream_info.cpp \
		incl/mp3_pl.cpp \
		forms/forms.cpp \
		forms/formMp3.cpp \
		forms/formSetup.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/qmp_mp3_inputplugin.o qmp_mp3_inputplugin.cpp

build/obj/moc_formMp3.o: build/moc/moc_formMp3.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_formMp3.o build/moc/moc_formMp3.cpp

build/obj/moc_formSetup.o: build/moc/moc_formSetup.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_formSetup.o build/moc/moc_formSetup.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

