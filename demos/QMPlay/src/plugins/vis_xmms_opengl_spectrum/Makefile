#############################################################################
# Makefile for building: libqmp_plugin_vis_xos.so
# Generated by qmake (2.01a) (Qt 4.6.2) on: Tue Aug 21 20:30:19 2012
# Project:  vis_xmms_opengl_spectrum.pro
# Template: lib
# Command: /usr/bin/qmake -unix -o Makefile vis_xmms_opengl_spectrum.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_PLUGIN -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O3 -ffast-math -fomit-frame-pointer -dA -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -Iincl -Iforms -I../../common -I../../common/struct -I../../common/kiss_fft -I/usr/X11R6/include -Ibuild/moc -Ibuild/ui
LINK          = g++
LFLAGS        = -Wl,-O1 -shared
LIBS          = $(SUBLIBS)  -L/usr/lib -L/usr/X11R6/lib -lQtOpenGL -lQtGui -lQtCore -lGLU -lGL -lpthread 
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

SOURCES       = ../../common/kiss_fft/kiss_fft.c \
		qmp_vis_xos.cpp build/moc/moc_FormVis.cpp \
		build/moc/moc_formSetup.cpp
OBJECTS       = build/obj/kiss_fft.o \
		build/obj/qmp_vis_xos.o \
		build/obj/moc_FormVis.o \
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
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		vis_xmms_opengl_spectrum.pro
QMAKE_TARGET  = qmp_plugin_vis_xos
DESTDIR       = ../../../qmplay/plugins/
TARGET        = libqmp_plugin_vis_xos.so
TARGETD       = libqmp_plugin_vis_xos.so

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

../../../qmplay/plugins/$(TARGET): build/ui/ui_formSetup.h $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@$(CHK_DIR_EXISTS) ../../../qmplay/plugins/ || $(MKDIR) ../../../qmplay/plugins/ 
	-$(DEL_FILE) $(TARGET)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-$(MOVE) $(TARGET) ../../../qmplay/plugins/



Makefile: vis_xmms_opengl_spectrum.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
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
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtOpenGL.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile vis_xmms_opengl_spectrum.pro
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
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtOpenGL.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile vis_xmms_opengl_spectrum.pro

dist: 
	@$(CHK_DIR_EXISTS) build/obj/qmp_plugin_vis_xos1.0.0 || $(MKDIR) build/obj/qmp_plugin_vis_xos1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/obj/qmp_plugin_vis_xos1.0.0/ && $(COPY_FILE) --parents forms/FormVis.h forms/formSetup.h build/obj/qmp_plugin_vis_xos1.0.0/ && $(COPY_FILE) --parents ../../common/kiss_fft/kiss_fft.c qmp_vis_xos.cpp build/obj/qmp_plugin_vis_xos1.0.0/ && $(COPY_FILE) --parents forms/formSetup.ui build/obj/qmp_plugin_vis_xos1.0.0/ && (cd `dirname build/obj/qmp_plugin_vis_xos1.0.0` && $(TAR) qmp_plugin_vis_xos1.0.0.tar qmp_plugin_vis_xos1.0.0 && $(COMPRESS) qmp_plugin_vis_xos1.0.0.tar) && $(MOVE) `dirname build/obj/qmp_plugin_vis_xos1.0.0`/qmp_plugin_vis_xos1.0.0.tar.gz . && $(DEL_FILE) -r build/obj/qmp_plugin_vis_xos1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc/moc_FormVis.cpp build/moc/moc_formSetup.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc/moc_FormVis.cpp build/moc/moc_formSetup.cpp
build/moc/moc_FormVis.cpp: forms/FormVis.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) forms/FormVis.h -o build/moc/moc_FormVis.cpp

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
compiler_uic_make_all: build/ui/ui_formSetup.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui/ui_formSetup.h
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

build/obj/kiss_fft.o: ../../common/kiss_fft/kiss_fft.c ../../common/kiss_fft/_kiss_fft_guts.h \
		../../common/kiss_fft/kiss_fft.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/obj/kiss_fft.o ../../common/kiss_fft/kiss_fft.c

build/obj/qmp_vis_xos.o: qmp_vis_xos.cpp incl/var.h \
		../../common/kiss_fft/kiss_fft.h \
		../../common/struct/QLib.cpp \
		forms/FormVis.h \
		forms/formSetup.h \
		build/ui/ui_formSetup.h \
		incl/vis.h \
		incl/save.h \
		incl/save.cpp \
		../../common/struct/VisPlugin.cpp \
		../../common/struct/PluginInfo.h \
		incl/xmms_vis.cpp \
		incl/vis.cpp \
		forms/forms.cpp \
		forms/FormVis.cpp \
		forms/formSetup.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/qmp_vis_xos.o qmp_vis_xos.cpp

build/obj/moc_FormVis.o: build/moc/moc_FormVis.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_FormVis.o build/moc/moc_FormVis.cpp

build/obj/moc_formSetup.o: build/moc/moc_formSetup.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_formSetup.o build/moc/moc_formSetup.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

