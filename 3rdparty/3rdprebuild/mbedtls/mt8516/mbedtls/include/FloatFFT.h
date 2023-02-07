#pragma once

#include "KRFFT.H"


namespace haier {

	class CFloatFFT
	{
	public:
		CFloatFFT(int nSize);
		~CFloatFFT(void);

		bool SetSize(int nSize);
		void Execute(float *real, float *img, bool bInv = false);
	protected:
		int	m_nSize;
		HAIER_KRFFT<float> * m_pRFFT;
	};

}

