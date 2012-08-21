#!/bin/bash

sudo=sudo
if [ `whoami` == "root" ]; then
	sudo=""
fi

function uninstall_qmplay
{
	echo
	echo "Removing .qplst, .j2b and .umx mimetype"
	$sudo xdg-mime uninstall qplst-qplst.xml
	$sudo xdg-mime uninstall j2b-j2b.xml
	$sudo xdg-mime uninstall umx-umx.xml
	echo "Removing QMPlay directory: /opt/qmplay"
	$sudo rm -rf /opt/qmplay
	echo "Removing symlinks"
	$sudo rm -f /usr/bin/qmplay
	$sudo rm -f /usr/share/pixmaps/QMPlay.png
	$sudo rm -f /usr/share/applications/QMPlay.desktop
	$sudo rm -f /usr/share/applications/QMPlay_enqueue.desktop
	echo
}

function close
{
	if [ ! -z $noqmplayinstallexit ]; then
		echo "Press enter to exit..."
		read
	fi
	exit
}

cd "$(dirname "$0")"

if [ -z $noqmplayinstallexit ]; then
	if [ ! -z "`xterm -help 2> /dev/null`" ] && [ ! -z $DISPLAY ] ; then
		noqmplayinstallexit=true xterm -e "./$(basename "$0")" &
		exit
	fi
	if [ ! -z $KDE_FULL_SESSION ]; then
		noqmplayinstallexit=true konsole -e "./$(basename "$0")" &
		exit
	fi
fi

printf "QMPlay instalator for Linux. Press "
if [ -z $noqmplayinstallexit ]; then
	printf "Ctrl+C to break, "
fi
printf "Enter to continue...\n"
read

if [ $PWD == "/opt/qmplay/install" ]; then
	printf "Would you like to uninstall old QMPlay? [Y/n]"
	read wybor
	if [ -e $wybor ] || [ $wybor != "n" ]; then
		uninstall_qmplay
	fi
	close
fi

installDir="$(basename "$PWD")"
cd ..
qmplayDir="$(basename "$PWD")"
cd ..
if [ $installDir != "install" ] || [ $qmplayDir != "qmplay" ]; then
	echo "Error, installation script must be in qmplay/install directory!"
	echo
	close
fi

if [ -d "/opt/qmplay" ]; then
	echo "QMPlay is already installed in /opt. Before update you must uninstall old version."
	printf "Would you like to uninstall QMPlay? [Y/n]"
	read wybor
	if [ ! -e $wybor ] && [ $wybor == "n" ]; then
		close
	fi
	uninstall_qmplay
fi

if [ ! -e "/opt" ]; then
	echo "Creating: /opt"
	$sudo mkdir /opt
fi

echo "Copying QMPlay directory into /opt/qmplay"
$sudo cp -R qmplay /opt
cd /opt/qmplay/install
if [ $PWD != "/opt/qmplay/install" ]; then
	echo "Error, can't find /opt/qmplay/install directory!"
	close
fi

$sudo chmod 777 ../colors
$sudo chmod +t ../colors

echo "Creating symlink to QMPlay executable script ( /usr/bin/qmplay )"
$sudo ln -s /opt/qmplay/install/qmplay /usr/bin/qmplay
echo "Creating symlink to QMPlay icon ( /usr/share/pixmaps/QMPlay.png )"
$sudo ln -s /opt/qmplay/install/QMPlay.png /usr/share/pixmaps/QMPlay.png
echo "Creating symlink to QMPlay shortcut ( /usr/share/applications/QMPlay.desktop )"
$sudo ln -s /opt/qmplay/install/QMPlay.desktop /usr/share/applications/QMPlay.desktop
echo "Creating symlink to QMPlay shortcut ( /usr/share/applications/QMPlay_enqueue.desktop )"
$sudo ln -s /opt/qmplay/install/QMPlay_enqueue.desktop /usr/share/applications/QMPlay_enqueue.desktop
echo "Creating .qplst, .j2b and .umx mimetype"
$sudo xdg-mime install qplst-qplst.xml
$sudo xdg-mime install j2b-j2b.xml
$sudo xdg-mime install umx-umx.xml

echo "Installation complete!"
echo

close