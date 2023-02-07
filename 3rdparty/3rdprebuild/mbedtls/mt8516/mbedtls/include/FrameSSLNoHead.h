#include "AFE_CODE.h"

#ifndef _FrameSSLNoHeadAPI_
#define _FrameSSLNoHeadAPI_


#define BUILDDLL

#ifdef BUILDDLL
#define FrameSSLNoHead_API //__declspec(dllexport)
#else
#define FrameSSLNoHead_API __declspec(dllimport)
#endif


typedef struct SSTParameters SSTPara;

FrameSSLNoHead_API SSTPara *FrameSSLNoHead_Init(int MicNum, float *MicPosMM, int SampleRateHz, int DelayPointNum, AFE_CODE *ReturnCode);

FrameSSLNoHead_API AFE_CODE FrameSSLNoHead_Process(SSTPara *st, short *MicIn, int PointNum, int *DOADegree);

FrameSSLNoHead_API AFE_CODE FrameSSLNoHead_Exit(SSTPara *st);

#endif