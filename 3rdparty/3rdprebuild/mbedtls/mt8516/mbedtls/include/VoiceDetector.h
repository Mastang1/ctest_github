#ifndef _VOICE_DETECTOR_H_
#define _VOICE_DETECTOR_H_

#include "NNVadIntf.h"
//#include "ByteBuffer.h"

#include "my_debug.h"


namespace haier {

//#define ALGORITHDM_DELAY  5
#ifdef VAD_PARAMS
#define FRAME_SHIFT         160
#define HISTORY_FRM_MAX		80
#define SIL_HISTORY_FRM     60////70
#define SPEECH_HISTORY_FRM  30//35//25//35  //30
#define MIN_VOICE_RATIO		0.6f//(0.75f) //0.58f  //0.65f
#define MIN_SILENCE_RATIO	0.72//0.70f//0.6f//(0.75f)//(0.79f)//  


#else  //default params
#define FRAME_SHIFT         160
#define HISTORY_FRM_MAX		80
#define SIL_HISTORY_FRM     60//60  //70
#define SPEECH_HISTORY_FRM  35//25//35  //30
#define MIN_VOICE_RATIO		0.65f
#define MIN_SILENCE_RATIO	0.79f//(0.79f)//(0.79f)//(0.79f)  

#endif





typedef void	*NNV_HANDLE;

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

	class VoiceDetector {
	public:
#ifdef VAD_PARAMS_API		
		VoiceDetector(char* config_path);
#else
		VoiceDetector(char* dnn_model, char* cmvn_model, short maxFrm, short minFrm, short segFrm, short lookAhead, short traceBack, int nMode = 0);
#endif
		~VoiceDetector(void);

		void Reset();
		void Restart();
		void init_energy();

		//int InputWave(const short *pWaveData, int nSampleNum, bool bIsEnd);
		//int InputFloatWave(const float *pWaveData, int nSampleNum, bool bIsEnd);
		int InternalInputWave(short *pWaveData,
			int nSampleNum,
			short** output1,
			int *outputLen1,
			short** output2,
			int *outputLen2);

	private:
		NNV_HANDLE m_hVad;

		//int m_nPreFrameNum;
		int m_nMinVocFrameNum;
		float m_fMinVoiceRatio;
		int m_nMinSilFrameNum;
		float m_fMinSilRatio;
		int m_nCurProbFrameNum;
		int ret;
		float m_probs[2];
		float m_probe[2];
		short e_prob[1];

		//Jia201203: added for patch-1.
		int patch_state;
		int sp_frame;
		//patch-1 code end.

		//int a;

		//zouying add
		float m_sil_history[HISTORY_FRM_MAX];
		float m_speech_history[HISTORY_FRM_MAX];
		char  m_bprob_history[HISTORY_FRM_MAX];
		int   m_nSilIdx;
		int   audio_minlen;
		int   m_nMode;
		int   ewindow;
		float vad_threshold;

		int m_nVocStartFrame;//cmd start frame
		int m_nVocStopFrame; //cmd end   frame
		
		int m_nLastStop;
		int m_nVocStartOffset;//the frame where we have vad=1
		int m_nVoiceFrameThreshold;
		int m_nSilFrameThreshold;
		//int m_nSilenceHeadFrame;//silence frame at the beginning  add by wjing 2018.5.22
		//int m_nWriteFileTime;   //write file times to remove padding data at the file tail, add by wjing 2018.5.22

		float g_fSilProb;     //accumulated probability of sil
		float g_fVocProb;     //accumulated probability of voice
		int   g_nVoiceFrames; //number of frames of voice
		int   g_nSilFrames;   //number of frames of silence

		short *g_pBuf;         //address of ring buffer
		int    g_CMDidx;       //current number of frames of command in segment 
		int    totalcmdFrm;    //toal frm of a command
		short  *pEnd;          //end pos of ring buffer
		short  *pRt;           //current pos in ring buffer
		int    _buffSampleLen; //ring buffer len in sample
		int    g_frm;          //total frame arrived in 

        //---------energy----------------
		int frameCnt;
		float energy_mean_reg;
		float energy_sum;
		float energy_threshold;
		float energy_mean;
		float energy_mean_peak;
		float energy_mean_peak_second;
		float energy_noise;

		float ns_energy;
		float* energy_buffer;
		//---------------------------------

		short  _g_maxFrm;
		short  _g_minFrm;
		short  _g_sgeFrm;
		short  _g_sgetmp;
	#ifdef VAD_PARAMS_API
		short  _g_minsegFrm;
	#endif
		short  _lookaHeadNo;
		short  _g_traceBack;
		

		//float* energy_buffer;

	
		////end//////


		void JudgeVoiceBegin();
		void JudgeVoiceBegin4patch_1();
		void JudgeVoiceEnd();
		//void OffsetWaveFrame(int nFrame);
	};

}

#endif // _VOICE_DETECTOR_H_
