/*
要求：圆心必须在中间，不能在遮挡物的外面
*/



#include "AFE_CODE.h"

#ifndef _FrameSSLWithHeadAPI_
#define _FrameSSLWithHeadAPI_


#define BUILDDLL

#ifdef BUILDDLL
#define FrameSSLWithHead_API //__declspec(dllexport)
#else
#define FrameSSLWithHead_API __declspec(dllimport)
#endif


typedef struct SSTParameters SSTPara;

FrameSSLWithHead_API SSTPara *FrameSSLWithHead_Init(int MicNum, float *MicPosMM, int SampleRateHz, int DelayPointNum, AFE_CODE *ReturnCode);

FrameSSLWithHead_API AFE_CODE FrameSSLWithHead_Process(SSTPara *st, short *MicIn, int PointNum, int *DOADegree);

FrameSSLWithHead_API AFE_CODE FrameSSLWithHead_Exit(SSTPara *st);

#endif