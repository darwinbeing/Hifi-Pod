#include "stretch.h"

void AudioStretcher::start( AudioFormat& format ) {
    if( format.channels != audio.channels || format.frequency != audio.frequency ) {
        if(rubberband) delete rubberband;
        for( int c=0; c<audio.channels; c++ ) free(buffer[c]);
        audio=format;
        rubberband = new RubberBand::RubberBandStretcher(audio.frequency, audio.channels, RubberBand::RubberBandStretcher::OptionProcessRealTime, timeRatio, pitchScale );
        rubberband->setMaxProcessSize( audio.frequency );
        for( int c=0; c<audio.channels; c++ ) buffer[c] = (float*)malloc( audio.frequency*sizeof(float) );
    }
    foreach( AudioOutput* output, audioOutput ) output->start( audio );
}
void AudioStretcher::stop() { foreach( AudioOutput* output, audioOutput ) output->stop(); }
void AudioStretcher::setTimeRatio( double timeRatio ) { this->timeRatio=timeRatio; if(rubberband) rubberband->setTimeRatio(timeRatio); }
void AudioStretcher::setPitchScale( double pitchScale ) { this->pitchScale=pitchScale; if(rubberband) rubberband->setPitchScale(pitchScale); }

void AudioStretcher::write( AudioFrame* frame ) {
    int readFrames = frame->size / (audio.channels*2);
    //convert s16 to float
    for( int i=0; i < readFrames; i++ )
        for( int c=0; c<audio.channels; c++ )
            buffer[c][i] = frame->data[i*audio.channels+c] / 32768.f;
    rubberband->process( buffer, readFrames, false );

    if( !audioOutput.empty() ) {
        int actualFrames = rubberband->retrieve( buffer, audio.frequency );
        AudioFrame* frame = new AudioFrame( actualFrames * (2*audio.channels) );
        //convert float to s16
        for( int i=0; i<actualFrames; i++ )
            for( int c=0; c<audio.channels; c++ )
                frame->data[i*audio.channels+c] = buffer[c][i] * 32768.f;
        foreach( AudioOutput* output, audioOutput ) output->write( frame->copy() );
        frame->free();
    }
    frame->free();
}
bool AudioStretcher::playback() {
    bool needData=false;
    foreach( AudioOutput* output, audioOutput ) if( output->playback() ) needData=true;
    return needData;
}

void VideoStretcher::start( VideoFormat& format ) {
    this->format=format; ref=-1;
    foreach( VideoOutput* output, videoOutput ) output->start( format );
}
void VideoStretcher::stop() { foreach( VideoOutput* output, videoOutput ) output->stop(); }
void VideoStretcher::setTimeRatio( double timeRatio ) { this->timeRatio=timeRatio; ref=lastFrame; }
void VideoStretcher::write( VideoFrame* frame ) {
    /*if( ref < 0 ) ref=frame->time;
    lastFrame = frame->time = ref + (frame->time-ref)*timeRatio;*/
    foreach( VideoOutput* output, videoOutput ) output->write( frame );
}
bool VideoStretcher::display() {
    bool needData=false;
    foreach( VideoOutput* output, videoOutput ) if( output->display() ) needData=true;
    return needData;
}
