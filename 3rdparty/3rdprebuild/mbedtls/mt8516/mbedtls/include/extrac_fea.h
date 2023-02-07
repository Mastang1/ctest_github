#ifndef _EXTRACT_FEA_H_
#define _EXTRACT_FEA_H_
#include "kiss_fftr.h"


#define USE_HAIER_KISS_FFT


namespace haier{


typedef int fixed32;
typedef float float32;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;




#define DEFAULT_RADIX 12
#define FLOAT2FIX_ANY(x,radix) \
    (((x)<0.0) ? \
    ((fixed32)((x)*(float32)(1<<(radix)) - 0.5)) \
    : ((fixed32)((x)*(float32)(1<<(radix)) + 0.5)))
#define FLOAT2FIX(x) FLOAT2FIX_ANY(x,DEFAULT_RADIX)
/** Convert fixed point to floating point. */
#define FIX2FLOAT_ANY(x,radix) ((float)(x)/(1<<(radix)))
#define FIX2FLOAT(x) FIX2FLOAT_ANY(x,DEFAULT_RADIX)

//#define TEST_VAD

#ifdef  TEST_VAD
#define CEP_DIM         29    //feature dimention for VAD is 29
#else
#define CEP_DIM         26    //feature dimention for wakeup is 26
#endif

#define VEC_DIM			CEP_DIM
#define VEC_FEAT_DIM    (VEC_DIM*3)
#define MAX_SPEECH		10	// frame
#define FRAME_SIZE      400

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif



typedef struct {
	int		wklo;
	int     wkhi;
	int     klo;
	int     khi;
	int     nChans;
	int     nfftN;

	float*	loWt;			/* array[1..fftN/2] of loChan weighting */
	short*	loChan;			/* array[1..fftN/2] of loChan index */
	float*	loWtH;			/* array[1..fftN/2] of loChan weighting */
	short*	loChanH;		/* array[1..fftN/2] of loChan index */
}FilterBank;

class ExtractFea {
	float m_pNewFeat[MAX_SPEECH*VEC_FEAT_DIM];
	int m_nSftLen;
	int m_nFrmLen;
	//int iniflag;
	int	m_nFrame;
	float *FrameBuf;
	int   pFrameBuf[480];
	float *m_pHamWin;
	HAIER_kiss_fftr_cfg    kiss_fftr_state;
	FilterBank FBank;
	float  m_mean_u[VEC_FEAT_DIM];
	float  m_mean_val[VEC_FEAT_DIM];
	float MEL(int k, float fres);
	void  Dither(float* waveform, int Len, float dither_value, float* outwav);
	void  PreEmph(float* pBuf, int Len);
	inline	float RandUniform() {  // random between 0 and 1.
		return (float)((rand() + 1.0) / (RAND_MAX + 2.0));
	}
	inline float RandGauss() {
		return (float)(sqrt(-2 * log(RandUniform()))
			* cos(2 * 3.14159265358979*RandUniform()));
	}
public:
	ExtractFea(char* pCMVN,int nSftLen=160, int nFrmLen=400, int FFTLen=512);
	~ExtractFea();
	int    ComputeBaseFea(short *pBuf, int iSamples, float* pFea);
	int    ComputeBaseFea2(short *pBuf, int iSamples, float* pFea);
	void   zero_mean_frame(int *vec, int len, int* output);
	int    ComputeDelta(float* pFea, int frm, int offset);
	int    ComputeFeatureAll(short *pBuf, int iSamples);
	void   OnLineCms_Cal(short* wav, int vecSize, float* pFea);
	void   ResetMeanVar(int vecSize);
	float* ComputeFea(short* pWaveData, int iSamples, int* outSamples);
};

}

#endif