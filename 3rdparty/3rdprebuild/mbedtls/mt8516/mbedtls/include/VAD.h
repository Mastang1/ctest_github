/*
 * VAD.h
 *
 *  Created on: 2013-12-12
 *      Author: gaopeng
 */

#ifndef VAD_H_
#define VAD_H_

//#include <vector>

#include "felib/PLP.h"
#include "felib/feintf.h"
#include "amlib/dnn.h"
#include "felib/fftwrapper.h"
//#include "ByteBuffer.h"


//#define LOG_TAG "vad_jni"
//#include <android/log.h>
//#undef LOGD
//#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
//#undef LOGE
//#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#include "common.h"


namespace haier {

#define VAD_OUT_DIM		2
#define	VAD_DNN_LAYER	3


	class VAD {
	public:
		VAD(int sampleRate, int frameLenMs, char* dnn_model, char* cmvn_model);
		virtual ~VAD();
		void  ResetCurMaxFrame();
		void  Reset();
		void  Restart();
		bool  InputWave(const short *pWaveData, int frameNum, float* outprob);
		int   InputFloatWave(short *pWaveData, int frameNum, float *pOutFeature);
		void  UpdateProba(int flag, float* pEnergy, float* pOutFeature);
		
	    


	//protected:
		private:
		int m_nSampleRate;
		int m_nFrameLenMs;
		int m_nFrameSampleNum;

		//FE_HDR m_feHdr;
		HANDLE m_hFE;
		CDNN m_dnn;
		int m_nCurMaxFrame;

		//int i = 0;
		/*
		int frameCnt;
		float energy_mean_reg;
		float energy_sum ;
		float energy_threshold ;
		float energy_mean ;
		float energy_mean_peak ;
		float energy_mean_peak_second ;
		float energy_noise ;

		float ns_energy ;*/
		//float* energy_buffer;
	

		//int    e_prob = 0;
		//int m_nMode; /* 0 dnn, 1 DNN+energy */
		bool PrepareNNMode(char* dnn_model, char* cmvn_model);

	};

}

#endif /* VAD_H_ */
