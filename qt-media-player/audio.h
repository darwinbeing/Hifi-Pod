#pragma once
#include <QTimer>
#include "media.h"

#ifdef USE_FSRC
 #include <fsrc.h>
#endif

typedef struct _snd_pcm snd_pcm_t;
class AlsaOutput : public QObject, public AudioOutput {
    Q_OBJECT
public:
    AlsaOutput();
    ~AlsaOutput();
    void start( AudioFormat& format);
    void stop();
    void write( AudioFrame* frame );
    bool playback();
signals:
    void audioReady();
private:
    snd_pcm_t* pcm;
    int channels, frequency;
#ifdef USE_FSRC
    fsrc_converter* fsrc;
    fsrc_spec spec;
#endif
    QTimer wakeup;
    AudioFormat format;
    QList<AudioFrame*> buffer;
};

#ifdef USE_ALSA_CAPTURE
QStringList alsaDevices();
class AlsaSource : public QThread, public AudioSource {
    Q_OBJECT
public:
    AlsaSource();
    void start();
    void stop();
    void run();
public slots:
    void setDevice( QString );
private:
    QString device;
    snd_pcm_t* pcm;
    AudioFormat format;
    bool recording;
};
#endif
