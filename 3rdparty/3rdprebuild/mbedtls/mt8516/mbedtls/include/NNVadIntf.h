/************************************************************************/
/** \file NNVadIntf.h
 * \n
 * \n
 * Written by @Author, @Date\n
 * \n
 * 
 * Copyright ZTSpeech 2014
 * www.ztspeech.com
 * 
 */
/************************************************************************/

#ifndef __NNVAD_INTF_H__
#define __NNVAD_INTF_H__

#include "my_debug.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifndef STC_SOURCE_COMPILE
#ifndef STC_DYNAMIC_LOAD
//#pragma comment(lib, "NNVad.lib")
#endif
#endif




#define VAD_SAMPLE_RATE (16000)
/* VAD work mode */
#define VAD_MODE_DNN		    0
//#define VAD_MODE_DNNENERGY		1
/************************************************************************/
typedef void	*VD_HANDLE;

#ifdef VAD_PARAMS_API
VD_HANDLE  HAIER_VD_NewVad(char* config_path);
#else
VD_HANDLE  HAIER_VD_NewVad(char* dnn_model, 
	                 char* cmvn_model,
					 short maxFrm, 
					 short minFrm, 
					 short segFrm, 
					 short lookAhead, 
					 short traceBack, 
					 int nMode);
#endif

int  HAIER_VD_ResetVad(VD_HANDLE hVad);

int  HAIER_VD_DelVad(VD_HANDLE hVad);

int  HAIER_VD_InputWave(VD_HANDLE hVad, 
	              short *pWaveData, 
	              int nSampleNum, 
	              short **output1,
	              int *outputLen1,
	              short **output2,
	              int *outputLen2);





#ifdef __cplusplus
};
#endif

#endif
