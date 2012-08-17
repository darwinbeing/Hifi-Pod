#pragma once

#include <QIODevice>
#include <rubberband/RubberBandStretcher.h>
#include "media.h"

/// Stretch audio samples using librubberband
class AudioStretcher : public AudioSource, public AudioOutput {
public:
    AudioStretcher() : rubberband(0), timeRatio(1), pitchScale(1) {}
    void start( AudioFormat& format );
    void stop();
    void write( AudioFrame* frame );
    bool playback();
    void setTimeRatio( double timeRatio );
    void setPitchScale( double pitchScale );
private:
    RubberBand::RubberBandStretcher* rubberband;
    AudioFormat audio;
    float* buffer[8];
    float timeRatio;
    float pitchScale;
};

/// Change video refresh rate
class VideoStretcher : public VideoSource, public VideoOutput {
public:
    VideoStretcher() : timeRatio(1) {}
    void start( VideoFormat& format );
    void stop();
    void write( VideoFrame* frame );
    bool display();
    void setTimeRatio( double timeRatio );
private:
    VideoFormat format;
    int64_t ref;
    int64_t lastFrame;
    float timeRatio;
};
