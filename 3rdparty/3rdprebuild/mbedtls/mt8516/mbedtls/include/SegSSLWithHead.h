/*
要求：圆心必须在中间，不能在遮挡物的外面
*/



#include "AFE_CODE.h"

#ifndef _SegSSLWithHeadAPI_
#define _SegSSLWithHeadAPI_


#define BUILDDLL

#ifdef BUILDDLL
#define SegSSLWithHead_API //__declspec(dllexport)
#else
#define SegSSLWithHead_API __declspec(dllimport)
#endif


typedef struct SSTParameters SSTPara;

SegSSLWithHead_API SSTPara *SegSSLWithHead_Init(int MicNum, float *MicPosMM, int SampleRateHz, AFE_CODE *ReturnCode);

SegSSLWithHead_API AFE_CODE SegSSLWithHead_Process(SSTPara *st, short *MicIn, int PointNum, int *DOADegree);

SegSSLWithHead_API AFE_CODE SegSSLWithHead_Exit(SSTPara *st);

#endif