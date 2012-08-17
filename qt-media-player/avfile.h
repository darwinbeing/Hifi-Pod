#pragma once
#include <QObject>
#include <QTimer>
#include <QAbstractEventDispatcher>
#include "media.h"
class AVFormatContext;
class AVStream;
class AVCodecContext;

/// Decodes audio/video files using libavcodec/libavformat.
class AVFile : public QObject, public AudioSource, public VideoSource {
    Q_OBJECT
public:
    AVFile();
    void open( QString path );
    void close();

    inline bool isOpen() { return file!=0; }
    inline bool hasAudio() { return audio!=0; }
    inline bool hasVideo() { return video!=0; }
    inline void clearOutputs() { audioOutput.clear(); videoOutput.clear(); }

    int64_t position() { return audioPTS; }
    int64_t duration();
#ifndef USE_TAGLIB
    QString metadata( QString key );
#endif
public slots:
    void start();
    void stop();
    void seek( int ts );
signals:
    void positionChanged();
    void finished();
private slots:
    void update();
private:
    AVFormatContext* file;
    AVStream* audioStream;
    AVStream* videoStream;
    AVCodecContext* audio;
    AVCodecContext* video;

    VideoFormat videoFormat;
    AudioFormat audioFormat;

    bool playing;
    int64_t startTime,audioPTS,videoPTS;
    QList<int64_t> frames;
};
