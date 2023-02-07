#ifndef _TSSL_
#define _TSSL_

#ifdef __cplusplus
extern "C" {
#endif

#include "FrameSSLNoHead.h"

// ÖðÖ¡ÎÞÕÚµ²
int T_FrameSSLNoHead_Init_Azimuth(int channel_number, float *mic_pos, int SampleRate, int block);
int T_FrameSSLNoHead_Process_Azimuth(short *buffer, int len);
void T_FrameSSLNoHead_Exit_Azimuth();


// ÖðÖ¡ÓÐÕÚµ²
int T_FrameSSLNoHead_Init_Pitch(int channel_number, float *mic_pos, int SampleRate, int block);
int T_FrameSSLNoHead_Process_Pitch(short *buffer, int len);
void T_FrameSSLNoHead_Exit_Pitch();


// ¶ÎÎÞÕÚµ²
int T_SegSSLNoHead_Init_Azimuth(int channel_number, float *mic_pos, int SampleRate, short* isCircular);
//SSTPara *T_SegSSLNoHead_Init_Azimuth(int channel_number, float *mic_pos, int SAMPLE_RATE);
int T_SegSSLNoHead_Process_Azimuth(short *buffer, int len, int *doa_inst);
void T_SegSSLNoHead_Exit_Azimuth();


//int T_SegSSLNoHead_Init_Pitch(int channel_number, float *mic_pos, int SampleRate);
//int T_SegSSLNoHead_Process_Pitch(short *buffer, int len);
//void T_SegSSLNoHead_Exit_Pitch();




#ifdef __cplusplus
}
#endif

#endif
