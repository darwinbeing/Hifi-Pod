#ifndef libExt_H
#define libExt_H

#ifdef Q_WS_MAC
		const QString libExt = ".dylib";
#endif
#ifdef Q_WS_WIN
		const QString libExt = ".dll";
#endif
#ifdef Q_WS_X11
		const QString libExt = ".so";
#endif

#endif
