#include "AFE_CODE.h"

#ifndef _SegSSLNoHeadAPI_
#define _SegSSLNoHeadAPI_


#define BUILDDLL

#ifdef BUILDDLL
#define SegSSLNoHead_API //__declspec(dllexport)
#else
#define SegSSLNoHead_API __declspec(dllimport)
#endif


typedef struct SSTParameters SSTPara;

SegSSLNoHead_API SSTPara *SegSSLNoHead_Init(int MicNum, float *MicPosMM, int SampleRateHz, AFE_CODE *ReturnCode, short *isCircular);

SegSSLNoHead_API AFE_CODE SegSSLNoHead_Process(SSTPara *st, short *MicIn, int PointNum, int *DOADegree, int *doa_inst);

SegSSLNoHead_API AFE_CODE SegSSLNoHead_Exit(SSTPara *st);

#endif
