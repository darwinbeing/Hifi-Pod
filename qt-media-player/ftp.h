#pragma once

#include <QCoreApplication>
#include <QAbstractFileEngineHandler>
#include <QFtp>
#include <QUrl>
#include <QBuffer>

class FtpEngine : public QObject, public QAbstractFileEngine {
    Q_OBJECT
public:
    FtpEngine(const QString&);
    FileFlags fileFlags( FileFlags type = FileInfoAll ) const;
    qint64 size() const;
    bool open( QIODevice::OpenMode mode );
    qint64 pos() const;
    bool seek(qint64 pos);
    qint64 read( char* data, qint64 maxlen );
    bool close();
private slots:
    void listInfo( const QUrlInfo& );
private:
    QFtp ftp;
    QUrl url;
    QUrlInfo info;
    QByteArray buffer;
    QBuffer file;
    QBuffer target;
};

class FtpEngineHandler : public QAbstractFileEngineHandler {
public:
    QAbstractFileEngine *create(const QString& url) const { return url.startsWith("ftp://") ? new FtpEngine(url) : 0; }
};
