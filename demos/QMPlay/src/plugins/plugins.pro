TEMPLATE = subdirs

SUBDIRS = aac cdda effect_resample effect_tst func_music_browser func_radio func_rec func_tag_editor modplug mp3 ogg_vorbis playlists portaudio raw sndfile snd_generator vis_fft vis_tst vis_xmms_opengl_spectrum
windows:SUBDIRS += func_associate

#if you don't have PulseAudio remove below line
unix:!mac:SUBDIRS += pulseaudio

#optional Plugins, uncomment below line if you want compile it
#SUBDIRS += openal ao mikmod
