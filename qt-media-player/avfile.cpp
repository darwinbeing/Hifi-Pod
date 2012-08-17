#include "avfile.h"
extern "C" {
#include <stdint.h>
typedef uint64_t UINT64_C;
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

#ifdef USE_FTP
#include <QFile>
int qt_open(URLContext *h, const char *url, int ) {
    QFile* file = new QFile(url);
    h->priv_data = (void*) file;
    return file->open( QIODevice::ReadOnly ) ? 0 : -1;
}
int qt_read(URLContext *h, unsigned char *buf, int size) {
    QFile* file = (QFile*)h->priv_data;
    return file->read( (char*)buf, size );
}
int qt_write(URLContext *, unsigned char *, int ) { return 0; }
int64_t qt_seek(URLContext *h, int64_t pos, int whence) {
    QFile* file = (QFile*)h->priv_data;
    if( whence == AVSEEK_SIZE ) return file->size();
    return file->seek( pos ) ? 0 : -1;
}
int qt_close(URLContext *h) {
    QFile* file = (QFile*)h->priv_data;
    file->close();
    delete file;
    return 0;
}

extern "C" {
//FTP is implemented through Qt FileEngine system
URLProtocol ftp_protocol = {
    "ftp",
    &qt_open,
    &qt_read,
    &qt_write,
    &qt_seek,
    &qt_close,
    0,0,0,0
};
}
#endif

struct StaticThis {
    StaticThis() {
        av_register_all();
        av_log_set_level(AV_LOG_WARNING);
#ifdef USE_FTP
        av_register_protocol(&ftp_protocol);
#endif
    }
};
static StaticThis staticThis;

AVFile::AVFile() : file(0), audioStream(0), videoStream(0), audio(0), video(0) {}
void AVFile::open( QString path ) {
    if(file) close();
    audioPTS=0;
    if(avformat_open_input(&file, path.toUtf8(),0,0)) { file=0; return; }
    av_find_stream_info(file);
    for( uint i=0; i<file->nb_streams; i++ ) {
        if( !audioOutput.empty() && file->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO ) {
            audioStream = file->streams[i];
            audio = audioStream->codec;
            audio->sample_fmt = AV_SAMPLE_FMT_FLT;
            AVCodec* codec = avcodec_find_decoder(audio->codec_id);
            if( codec && avcodec_open( audio, codec ) >= 0 ) {
                audioFormat.frequency = audio->sample_rate;
                audioFormat.channels = audio->channels;
                Q_ASSERT_X( audioFormat.frequency, "AVFile::open", path.toAscii() );
                Q_ASSERT_X( audio->sample_fmt == AV_SAMPLE_FMT_S16, "AVFile::open", path.toAscii() );
            }
        }
        if( !videoOutput.empty() && file->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
            videoStream = file->streams[i];
            video = videoStream->codec;
            AVCodec* codec = avcodec_find_decoder(video->codec_id);
            if( codec && avcodec_open( video, codec ) >= 0 ) {
                videoFormat.width = video->width;
                videoFormat.height = video->height;
            }
        }
    }
}

void AVFile::start() {
    if(!file) return;
    if( hasAudio() ) foreach(AudioOutput* output, audioOutput) output->start( audioFormat );
    if( hasVideo() ) foreach(VideoOutput* output, videoOutput) output->start( videoFormat );
    startTime=0; playing=true;
    update();
}
void AVFile::stop() {
    playing=false;
    frames.clear();
    if( hasAudio() ) foreach(AudioOutput* output, audioOutput) output->stop();
    if( hasVideo() ) foreach(VideoOutput* output, videoOutput) output->stop();
}
void AVFile::seek( int time ) {
    if( av_seek_frame(file,-1,time*1000,0) < 0 )
        avformat_seek_file(file,0,0,time*file->file_size/duration(),file->file_size,AVSEEK_FLAG_BYTE);
}
void AVFile::close() {
    if(playing) stop();
    if( hasAudio() ) { avcodec_close(audio); audio=0; }
    if( hasVideo() ) { avcodec_close(video); video=0; }
    if(file) { av_close_input_file(file); file=0; }
}

int64_t AVFile::duration() { return file->duration/1000; }
#ifndef USE_TAGLIB
QString AVFile::metadata( QString key ) {
    if( !file ) return "";
    AVMetadataTag* tag = av_metadata_get( file->metadata, key.toAscii(), 0, 0 );
    if( !tag ) return "";
    return QString( tag->value );
}
#endif

void AVFile::update() {
    if(!playing) return;
    for(;;) {
        bool needAudio=false,needVideo=false;
        if(hasAudio()) foreach(AudioOutput* output, audioOutput) if( output->playback() ) needAudio=true;
        if( hasVideo() ) {
            if( frames.isEmpty() ) needVideo=true;
            else if( getTime() >= frames.first() ) {
                frames.takeFirst();
                if(hasVideo()) foreach(VideoOutput* output, videoOutput) if( output->display() ) needVideo=true;
            }
        }
        if( !needAudio && !needVideo ) break;

        AVPacket packet; int err;
        if( (err=av_read_frame(file, &packet)) < 0 ) { stop(); emit finished(); return; }
        if( file->streams[packet.stream_index]==audioStream ) {
            if( audioOutput.empty() ) continue;
            AVPacket pkt=packet;
            while( pkt.size > 0 ) {
                AudioFrame* frame = new AudioFrame( AVCODEC_MAX_AUDIO_FRAME_SIZE );
                int size = avcodec_decode_audio3( audio, frame->data, &frame->size, &pkt );
                if( size <= 0 ) { frame->free(); break; }
                pkt.size -= size;
                pkt.data += size;
                if( frame->size ) {
                    if(pkt.dts>=0) audioPTS = pkt.dts*av_q2d(audioStream->time_base)*1000;
                    else audioPTS=pkt.pos*duration()/file->file_size;
                    foreach(AudioOutput* output, audioOutput) output->write( frame->copy() );
                }
                frame->free();
            }
        }
        else if( file->streams[packet.stream_index]==videoStream ) {
            if( videoOutput.empty() ) continue;
            AVFrame* avFrame = avcodec_alloc_frame();
            int completeFrame=0;
            avcodec_decode_video2(video, avFrame, &completeFrame, &packet );
            if(completeFrame) {
                videoPTS = packet.dts*av_q2d(videoStream->time_base)*1000;
                if(!startTime) startTime=getTime()-videoPTS;
                VideoFrame* frame = new VideoFrame( avFrame->data, avFrame->linesize, avFrame );
                foreach(VideoOutput* output, videoOutput) output->write( frame->copy() );
                frame->free();
                frames << startTime+videoPTS;
                QTimer::singleShot(qMax((int64_t)0,startTime+videoPTS-getTime()),this,SLOT(update())); //schedule display
            }
        }
        av_free_packet(&packet);
    }
    emit positionChanged();
}
