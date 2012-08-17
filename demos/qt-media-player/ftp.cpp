#include "ftp.h"

/** TODO:
      - use QNetworkAccessManager
      - QNAM authentification dialog
      - QNAM disk cache (file,folder)
      - streaming
**/

FtpEngine::FtpEngine(const QString& path) : url( path ) {
    connect(&ftp,SIGNAL(listInfo(QUrlInfo)),this,SLOT(listInfo(QUrlInfo)));
    ftp.connectToHost(url.host(),url.port(21));
    ftp.login( url.userName(), url.password() );
    QString parent = url.path().section('/',0,-2);
    ftp.cd("/"+parent);
    ftp.list();

    /*QString tmpDir = "/var/cache/qt/"+url.host()+"/"+parent;
    QDir::mkpath(tmpDir);
    QString tmpFile = "/var/cache/qt/"+url.host()+"/"+url.path();
    file = QFile( tmpFile );*/
}

QAbstractFileEngine::FileFlags FtpEngine::fileFlags( FileFlags ) const {
    while( !info.isValid() ) QCoreApplication::processEvents(QEventLoop::WaitForMoreEvents);
    FileFlags flags;
    if( info.isDir() ) flags |= DirectoryType;
    if( info.isFile() ) flags |= FileType;
    return flags;
}
qint64 FtpEngine::size() const {
    return info.size();
}

void FtpEngine::listInfo( const QUrlInfo& i ) {
    QString current = url.path().section('/',-1);
    if( i.name() == current ) info=i;
}

bool FtpEngine::open( QIODevice::OpenMode mode ) {
    if( mode & QIODevice::ReadOnly || mode & QIODevice::ReadWrite ) {
        file.setBuffer( &buffer );
        file.open(QBuffer::ReadOnly);
        target.setBuffer( &buffer );
        target.open(QBuffer::WriteOnly);
        ftp.get(url.path(),&target);
        return true;
    }
    qWarning()<<"FtpEngine::open unsupported"<<mode;
    return false;
}
qint64 FtpEngine::pos() const { return file.pos(); }
bool FtpEngine::seek(qint64 pos) { return file.seek(pos); }
qint64 FtpEngine::read( char* data, qint64 maxlen ) {
    while( (ftp.hasPendingCommands() || ftp.currentCommand() == QFtp::Get) && file.bytesAvailable() == 0 )
        QCoreApplication::processEvents(QEventLoop::WaitForMoreEvents);
    return file.read(data,maxlen);
}
bool FtpEngine::close() { ftp.close(); return true; }
