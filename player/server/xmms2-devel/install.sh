#!/bin/sh

XMMS2_BIN_FILES="xmms2 xmms2d xmms2-et xmms2-find-avahi xmms2-launcher xmms2-mdns-avahi xmms2-mlib-updater"
XMMS2_STARTUP_SCRIPTS="xmms2-et-launcher.sh    xmms2-mdns-launcher.sh  xmms2-mlib-updater.sh"

TMP_BUILD_BIN=build/bin
TMP_BUILD_LIB=build/lib
TMP_BUILD_SCRIPTS=build/scripts
TOP_DIR=`pwd`

echo $TOP_DIR

mkdir -p $TMP_BUILD_BIN
mkdir -p $TMP_BUILD_LIB
mkdir -p $TMP_BUILD_SCRIPTS


for file in $XMMS2_BIN_FILES ; do
    echo $file
    cp -rf `find . -name $file` $TMP_BUILD_BIN
done

for file in $XMMS2_STARTUP_SCRIPTS ; do
    echo $file
    cp -rf `find . -name $file` $TMP_BUILD_SCRIPTS

done

scp $TMP_BUILD_BIN/* root@192.168.2.101:/usr/bin
scp $TMP_BUILD_SCRIPTS/* root@192.168.2.101:/usr/share/xmms2/scripts/startup.d
