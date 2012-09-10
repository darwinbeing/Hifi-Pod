#include "audio.h"
#include "alsa/asoundlib.h"

AlsaOutput::AlsaOutput() {
    snd_pcm_open(&pcm,"default",SND_PCM_STREAM_PLAYBACK,SND_PCM_NO_SOFTVOL);
    connect(&wakeup,SIGNAL(timeout()),SIGNAL(audioReady()));
}

AlsaOutput::~AlsaOutput() { snd_pcm_close(pcm); }

int gcd(int a, int b) {
    while( b != 0 ) {
       int t = b;
       b = a % b;
       a = t;
    }
    return a;
}

void AlsaOutput::start( AudioFormat& format) {
    this->format=format;
    channels=2;
#ifdef USE_FSRC
    frequency=48000;
    if(frequency != format.frequency) {
        fsrc_freq_ratio(format.frequency, frequency, &spec.fr);
        int divisor = gcd(format.frequency,frequency);
        spec.isize = format.frequency/divisor; spec.osize = frequency/divisor;
        spec.dp = fsrc_ripple_db(.001); // peak to peak passband ripple of 0.001 dB
        spec.ds = fsrc_gain_db(-100); // stopband attenuation of 100 dB
        spec.bw = .95; // preserve 95% of the bandwidth below the Nyquist rate
        spec.flags = FSRC_DOUBLE | FSRC_USE_FFT;
        fsrc_create(0, &fsrc, &spec, 2);
    } else fsrc = 0;
    snd_pcm_set_params(pcm,SND_PCM_FORMAT_S16_LE,SND_PCM_ACCESS_RW_INTERLEAVED,2,frequency,0,1000000);
#else
    frequency=format.frequency;
    snd_pcm_set_params(pcm,SND_PCM_FORMAT_S16_LE,SND_PCM_ACCESS_RW_INTERLEAVED,2,frequency,1,1000000);
#endif
    snd_pcm_uframes_t buffer_size,period_size;
    snd_pcm_get_params(pcm,&buffer_size,&period_size);
    wakeup.start( 1000 * buffer_size / channels / frequency / 2 );
}

void AlsaOutput::stop() {
    foreach(AudioFrame* frame,buffer) frame->free();
    buffer.clear();
#ifdef USE_FSRC
    if(fsrc) fsrc_destroy(fsrc);
#endif
    if( snd_pcm_state(pcm) == SND_PCM_STATE_RUNNING ) snd_pcm_drain(pcm);
}

void AlsaOutput::write( AudioFrame* frame ) { buffer << frame; }

bool AlsaOutput::playback() {
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
    if( snd_pcm_state(pcm) == SND_PCM_STATE_XRUN ) { snd_pcm_prepare(pcm); }
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
    while( buffer.size() > 1 && snd_pcm_avail_update(pcm) >= 160 ) {
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
        AudioFrame* frame = buffer.first();
#ifdef USE_FSRC
        if(fsrc) {
            fsrc_bufdesc idesc = { spec.isize, fsrc_alloc(spec.isize*channels*2), 0, fsrc_i16 };
            if( (size_t)frame->size > idesc.size*channels*2 ) {
                memcpy(idesc.data,frame->data,idesc.size*channels*2);
                frame->data += idesc.size*channels;
                frame->size -= idesc.size*channels*2;
            } else {
                memcpy(idesc.data,frame->data,frame->size);
                void* data = (int8_t*)idesc.data+frame->size;
                int remaining = idesc.size*channels*2-frame->size;
                frame->free();
                buffer.removeFirst();
                frame = buffer.first();
                memcpy(data,frame->data,remaining);
                frame->data += remaining/2;
                frame->size -= remaining;
            }
            fsrc_read(fsrc, &idesc);
            fsrc_free(idesc.data);
            if( fsrc_process(fsrc) == FSRC_S_OK ) {
                fsrc_bufdesc odesc = { spec.osize, fsrc_alloc(spec.osize*channels*2), 0, fsrc_i16 };
                fsrc_write(fsrc, &odesc);
                snd_pcm_writei(pcm,odesc.data,odesc.size);
                fsrc_free(odesc.data);
            }
        } else
#endif
        {
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
    printf("***frame_size: %d***\n", frame->size);
            snd_pcm_writei(pcm,frame->data,frame->size/2/channels);
            frame->free();
        }
    }
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
    if( snd_pcm_state(pcm) == SND_PCM_STATE_PREPARED && !buffer.isEmpty() ) snd_pcm_start(pcm);
    printf("***%s: %d***\n", __FUNCTION__, __LINE__);
    return buffer.size() <= 1;
}
