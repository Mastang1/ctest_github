#ifndef  _DNNVAD_MANAGE_H
#define  _DNNVAD_MANAGE_H

#include "my_debug.h"

#define VAD_MODE_DNN			0
#define VAD_MODE_ENERGY			1
#define VAD_MODE_DNNENERGY		2
#define VAD_MODE_WEBRTC			3


#ifdef __cplusplus
//extern "C" {
#endif

#ifdef VAD_PARAMS_API
void*  dnn_vad_init(char* config_path);
#else
void*  dnn_vad_init(char* dnn_model, char* cmvn_model, short maxFrm, short minFrm, short segFrm, short lookAhead, short traceBack, int nMode);
#endif
void dnn_vad_reset(void* hVad);
void dnn_vad_del(void* hVad);
int dnn_vad_process(void* hVad, short* pWaveData, int nWaveLen,short** output1, int* outputLen1, short** output2, int* outputLen2);

#ifdef __cplusplus
//}
#endif

#endif
