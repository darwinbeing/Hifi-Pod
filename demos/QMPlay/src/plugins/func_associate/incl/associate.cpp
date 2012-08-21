#include <shlwapi.h>

#include <QSysInfo>
#include <QByteArray>

QByteArray doAssociate( char **extsAdd, int extsAddCount, char **extsDel, int extsDelCount, const char *qmpExecPath, bool onRun )
{
	HKEY qmplay_hkey = ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) ? HKEY_CLASSES_ROOT : HKEY_CURRENT_USER;

	const char FileExts[] = { "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\" };

	#define REGISTRY_PATH ( QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based ) ? "" : "Software\\Classes\\"
	#define Create_registry_path( a ) QByteArray( REGISTRY_PATH ) + a

	{
		HKEY TSTREG;
		bool n = false, c = false, d = false;
		SHDeleteKey( qmplay_hkey, Create_registry_path( "REG_ACCESS_TEST_QMPlay" ) );
		n = RegCreateKey( qmplay_hkey, Create_registry_path( "REG_ACCESS_TEST_QMPlay" ), &TSTREG );
		c = RegCloseKey( TSTREG );
		d = SHDeleteKey( qmplay_hkey, Create_registry_path( "REG_ACCESS_TEST_QMPlay" ) );
		if ( n || d || c )
			return "Nie udało się uzyskac pełnego dostępu do rejestru!\nPrawdopodobnie nie masz uprawnień...";
	}

	HKEY hreg;
	char *qmpPthToReg, *tmp;
	QByteArray result;

	int addDrive = 0, addCatalog = 0;
	for ( int i = 0 ; i < extsAddCount ; i++ )
	{
		if ( !strcmp( extsAdd[i], "._Catalog" ) )
			addCatalog = 1;
		if ( !strcmp( extsAdd[i], "._Drive" ) )
			addDrive = 1;
	}
	for ( int i = 0 ; i < extsDelCount ; i++ )
	{
		if ( !strcmp( extsDel[i], "._Catalog" ) )
			addCatalog = -1;
		if ( !strcmp( extsDel[i], "._Drive" ) )
			addDrive = -1;
	}
	const char *QMPShellExt = { "Play in QMPlay" };
	if ( addCatalog == 1 )
	{
		SHDeleteKey( qmplay_hkey, Create_registry_path( "Directory\\shell\\QMPlay" ) );
		RegCreateKey( qmplay_hkey, Create_registry_path( "Directory\\shell\\QMPlay" ), &hreg );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )QMPShellExt, strlen( QMPShellExt ) );
		RegCloseKey( hreg );
		RegCreateKey( qmplay_hkey, Create_registry_path( "Directory\\shell\\QMPlay\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+7+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );
		result += "Dodano rozszerzenie menu kontekstowego katalogów\n";
	}
	else if ( addCatalog == -1 )
	{
		SHDeleteKey( qmplay_hkey, Create_registry_path( "Directory\\shell\\QMPlay" ) );
		result += "Usunięto rozszerzenie menu kontekstowego katalogów\n";
	}
	if ( addDrive == 1 )
	{
		SHDeleteKey( qmplay_hkey, Create_registry_path( "Drive\\shell\\QMPlay" ) );
		RegCreateKey( qmplay_hkey, Create_registry_path( "Drive\\shell\\QMPlay" ), &hreg );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )QMPShellExt, strlen( QMPShellExt ) );
		RegCloseKey( hreg );
		RegCreateKey( qmplay_hkey, Create_registry_path( "Drive\\shell\\QMPlay\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+5+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" %1" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );
		result += "Dodano rozszerzenie menu kontekstowego napędów\n";
	}
	else if ( addDrive == -1 )
	{
		SHDeleteKey( qmplay_hkey, Create_registry_path( "Drive\\shell\\QMPlay" ) );
		result += "Usunięto rozszerzenie menu kontekstowego napędów\n";
	}
/**/
	SHDeleteKey(qmplay_hkey,Create_registry_path( "QMPlay" ) );
	if ( extsAddCount > 0 )
	{
		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlay\\DefaultIcon" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+2+1 ];
		strcpy( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, ",1" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlay\\Shell\\Open\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+7+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlay\\Shell\\Enqueue in QMPlay\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+10+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" -a \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlay\\Shell\\Enqueue in QMPlay and play\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+11+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" -al \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		result += "Stworzono wpis \"QMPlay\" w rejestrze\n";
	}
	else
		result += "Usunięto wpis \"QMPlay\" w rejestrze\n";
/**/
	SHDeleteKey( qmplay_hkey, Create_registry_path( "QMPlayPlayList" ) );
	if ( extsAddCount > 0 )
	{
		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlayPlayList\\DefaultIcon" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+2+1 ];
		strcpy( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, ",2" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlayPlayList\\Shell\\Open\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+7+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlayPlayList\\Shell\\Enqueue in QMPlay\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+10+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" -a \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		RegCreateKey( qmplay_hkey, Create_registry_path( "QMPlayPlayList\\Shell\\Enqueue in QMPlay and play\\command" ), &hreg );
		qmpPthToReg = new char[ strlen(qmpExecPath)+11+1 ];
		strcpy( qmpPthToReg, "\"" );
		strcat( qmpPthToReg, qmpExecPath );
		strcat( qmpPthToReg, "\" -al \"%1\"" );
		RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )qmpPthToReg, strlen( qmpPthToReg ) );
		delete[] qmpPthToReg;
		RegCloseKey( hreg );

		result += "Stworzono wpis \"QMPlayPlayList\" w rejestrze\n";
	}
	else
		result += "Usunięto wpis \"QMPlayPlayList\" w rejestrze\n";
/**/
	int WOD = 0;
	if ( addCatalog == -1 )
		WOD++;
	if ( addDrive == -1 )
		WOD++;
	if ( extsDelCount > WOD )
		result += "\nUsunięto rozszerzenia:\n";
	for ( int i = 0 ; i < extsDelCount ; i++ )
	{
		if ( !strcmp( extsDel[i], "._Catalog" ) || !strcmp( extsDel[i], "._Drive" ) )
			continue;

		tmp = new char[ strlen( FileExts ) + strlen( extsDel[i] ) + 1 ];
		strcpy( tmp, FileExts );
		strcat( tmp, extsDel[i] );
		SHDeleteKey( qmplay_hkey, tmp );
		delete[] tmp;
		tmp = new char[ strlen( extsDel[i] ) + strlen( REGISTRY_PATH ) + 1 ];
		strcpy( tmp, REGISTRY_PATH );
		strcat( tmp, extsDel[i] );
		SHDeleteKey( qmplay_hkey, tmp );
		delete[] tmp;

		if ( i > 0 )
			result += " ; ";
		result += extsDel[i];
	}
	if ( extsDelCount > 0 )
		result += "\n";

	WOD = 0;
	if ( addCatalog == 1 )
		WOD++;
	if ( addDrive == 1 )
		WOD++;
	if ( extsAddCount > WOD )
		result += "\nDodano rozszerzenia:\n";
	for ( int i = 0 ; i < extsAddCount ; i++ )
	{
		if ( !strcmp( extsAdd[i], "._Catalog" ) || !strcmp( extsAdd[i], "._Drive" ) )
			continue;

		tmp = new char[ strlen( extsAdd[i] ) + strlen( REGISTRY_PATH ) + 1 ];
		strcpy( tmp, REGISTRY_PATH );
		strcat( tmp, extsAdd[i] );
		SHDeleteKey( qmplay_hkey, tmp );
		delete[] tmp;
		tmp = new char[ strlen( FileExts ) + strlen(extsAdd[i] ) + 1 ];
		strcpy( tmp, FileExts );
		strcat( tmp, extsAdd[i] );
		SHDeleteKey( qmplay_hkey, tmp );
		delete[] tmp;
		tmp = new char[ strlen( extsAdd[i] ) + strlen( REGISTRY_PATH ) + 1 ];
		strcpy( tmp, REGISTRY_PATH );
		strcat( tmp, extsAdd[i] );
		RegCreateKey( qmplay_hkey, tmp, &hreg );
		delete[] tmp;
		if ( !strcmp( extsAdd[i], ".qplst" ) || !strcmp( extsAdd[i], ".m3u" ) || !strcmp( extsAdd[i], ".pls" ) )
			RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )"QMPlayPlayList", 14 );
		else
			RegSetValueEx( hreg, "", 0, REG_SZ, ( BYTE * )"QMPlay", 6 );
		RegCloseKey( hreg );

		if ( i > 0 )
			result += " ; ";
		result += extsAdd[i];
	}

	if ( !onRun )
		return result;
	else
		return QByteArray();
}
