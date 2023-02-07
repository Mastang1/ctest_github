#ifndef __HAIER_WAKE_H__
#define __HAIER_WAKE_H__

#include "HaierWakeErr.h"

//#define DEBUG

#ifndef ANDROID_LOG
#define LOGD(...) printf(__VA_ARGS__)
#else
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "libHAIERspeechforcommand", __VA_ARGS__)
#endif

//wakeup info
#define WRD_NUM 10

//audio info
#define AUDIO_HEAD 44
#define SAMPLERATE 16000
#define FRAME_SHIFT 10
#define FRAME_SIZE 25
#define SEC2SAMPLE(x) \
	((SAMPLERATE) * (x) / 1000)


//feature info
#define FEAT_DIM 20
#define DELTA 0
#define LEFT_FRAME_SHIFT 5
#define RIGHT_FRAME_SHIFT 10

//decode info
#define decode_radix 15

//common configure
#define MAX_STR_LEN 1000

typedef long long HAIER_WAKEUP_HANDLE;

typedef struct{
	char cfgFile[MAX_STR_LEN];
	char dnnFile[MAX_STR_LEN];
	char cmvnFile[MAX_STR_LEN];
	int char_number;
	int gram[WRD_NUM];
	int smoothFrm[WRD_NUM];
	int slide_len;
	int cmvn_flag;
	float threshold;
} WAKEUP_INSTRUCT;

HAIER_WAKEUP_ERROR_CODE haier_wakeup_init(HAIER_WAKEUP_HANDLE* handle, WAKEUP_INSTRUCT* pInStruct);
void haier_wakeup_release(HAIER_WAKEUP_HANDLE handle);
void haier_wakeup_reset(HAIER_WAKEUP_HANDLE handle);
HAIER_WAKEUP_ERROR_CODE haier_wakeup_process(HAIER_WAKEUP_HANDLE handle, short *input, int inputLen, int* confidence);
HAIER_WAKEUP_ERROR_CODE haier_wakeup_judge(HAIER_WAKEUP_ERROR_CODE curr);

#endif//__HAIER_WAKE_H__

