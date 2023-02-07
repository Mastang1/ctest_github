#ifndef _FFTWRAPPER_H_
#define _FFTWRAPPER_H_

#define USE_HAIER_KISS_FFT




#ifdef USE_HAIER_KISS_FFT
#include "../kissFFT/kiss_fftr.h"
#else
#include "fftw3.h"
#include "lockwrapper.h"
#endif



namespace haier{

typedef unsigned int UINT;


class FFTWrapper  
{
public:
	// Add by Gao Peng, 2006.2.24
	// !!!!! Must call this Init method at a one-time global init place
	// sample code:
	// ...
	// FFTWrapper::Init();
	//...
	// DO NOT call this method on each FFTWrapper instance

	FFTWrapper(UINT nSize);
	virtual ~FFTWrapper();

	//bool SetSize(UINT nSize);

	void Execute(float *real, float *img, bool bInv = false);
	//void Execute(short *real, short *img, bool bInv = false);

protected:

#ifdef USE_HAIER_KISS_FFT
	HAIER_kiss_fftr_cfg    kiss_fftr_state;
	//HAIER_kiss_fft_scalar *rin;
	//HAIER_kiss_fft_cpx    *cout;
#else
	UINT	m_nSize;
	static cs_lock_t m_lock;
	fftwf_complex	*m_in, *m_out;
	fftwf_plan	m_plan, m_inv;
#endif

};

}

#endif
