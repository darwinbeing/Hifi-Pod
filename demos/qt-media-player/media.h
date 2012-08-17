#pragma once
#include <stdint.h>
#include <QVector>

#include <time.h>
inline int64_t getTime() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC,&t);
    return t.tv_sec*1000+t.tv_nsec/1000000;
}

struct AudioFrame {
    AudioFrame( int size ) : data((int16_t*)malloc(size)), size(size), pointer(data), refCount(1) {}
    AudioFrame* copy() { refCount.ref(); return this; }
    void free() { if(!refCount.deref()) { ::free(pointer); delete this; } }
    int16_t* data;
    int size;
private:
    void* pointer;
    QAtomicInt refCount;
};

struct VideoFrame {
    VideoFrame( uint8_t** data, int* linesize, void* pointer ) :
            data(data), linesize(linesize), pointer(pointer), refCount(1) {}
    VideoFrame* copy() { refCount.ref(); return this; }
    void free() { if(!refCount.deref()) { ::free(pointer); delete this; } }
    uint8_t** data;
    int* linesize;
private:
    void* pointer;
    QAtomicInt refCount;
};

/*struct Subtitle {
    Subtitle( int time, QString text ) : text(text), time(time) {}
    QString text;
    int64_t time;
};*/

struct AudioFormat {
    AudioFormat() : frequency(0), channels(0) {}
    int frequency;
    int channels;
};

struct VideoFormat {
    VideoFormat() : width(0), height(0) {}
    int width;
    int height;
};

struct AudioOutput {
    virtual void start( AudioFormat& format ) = 0;
    virtual void stop() = 0;
    virtual void write( AudioFrame* frame ) = 0;
    virtual bool playback() = 0;
};

struct VideoOutput {
    virtual void start( VideoFormat& format ) = 0;
    virtual void stop() = 0;
    virtual void write( VideoFrame* frame ) = 0;
    virtual bool display() = 0;
};

/*struct SubtitleOutput {
    virtual void write( Subtitle frame ) = 0;
    virtual bool display() = 0;
};*/

class AudioSource {
public:
    inline void addAudioOutput( AudioOutput* output ) { audioOutput<<output; }
protected:
    QVector<AudioOutput*> audioOutput;
};

class VideoSource {
public:
    inline void addVideoOutput( VideoOutput* output ) { videoOutput<<output; }
protected:
    QVector<VideoOutput*> videoOutput;
};

/*class SubtitleSource {
public:
    inline void addSubtitleOutput( SubtitleOutput* output ) { subtitleOutput<<output; }
protected:
    QVector<SubtitleOutput*> subtitleOutput;
};*/
