#include "var.h"

BOOL qmp_IsThere()
{
	return 1;
}

MDRIVER drv_qmp =
{
	NULL,
	(char*)"QMPlay",
	(char*)"QMPlay output driver",
	0, 255,
#if (LIBMIKMOD_VERSION > 0x30106)
	(char*)"QMPlay",
	NULL,
#endif
#if (LIBMIKMOD_VERSION >= 0x30200)
	NULL,
#endif
	qmp_IsThere,
	VC_SampleLoad,
	VC_SampleUnload,
	VC_SampleSpace,
	VC_SampleLength,
	VC_Init,
	VC_Exit,
	NULL,
	VC_SetNumVoices,
	VC_PlayStart,
	VC_PlayStop,
	NULL,
	NULL,
	VC_VoiceSetVolume,
	VC_VoiceGetVolume,
	VC_VoiceSetFrequency,
	VC_VoiceGetFrequency,
	VC_VoiceSetPanning,
	VC_VoiceGetPanning,
	VC_VoicePlay,
	VC_VoiceStop,
	VC_VoiceStopped,
	VC_VoiceGetPosition,
	VC_VoiceRealVolume
};
