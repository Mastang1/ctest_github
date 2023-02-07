/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

/*
 * Specifies the interface for the AEC core.
 */

#ifndef TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_AEC_CORE_H_
#define TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_AEC_CORE_H_

#include "../spl/typedefs.h"
//#include "dbgprint.h"



// must define only one of "Short_Order" or "Long_Order" or "V0902"
//#define Short_Order                // select relatively low-complexity algorithm  V0705
//#define Long_Order               // select relatively high-complexity algorithm   V0727
//#define V0902                      // algorithm tuned for lenovo data V0902
//#define DE_BUF                     // 去除不使用的buf准备
//#define DE_SKEW                    // 去除不适用的skew估计
//#define DE_XFW                     // 去除xfwBuf存储


//#define G167 // for running G167 tests
//#define UNCONSTR // time-unconstrained filter
//#define AEC_DEBUG // for recording files

//#define POSTFILTER
#define PREPOSTFILTER_OUT_FLG

//#define SPL_FFT    // 使用SPL定点FFT
//#define	REMAIN_QVALUE	10

#define FRAME_LEN 80
//#define FRAME_LEN 160
#define PART_LEN 64 // Length of partition
#define PART_LEN1 (PART_LEN + 1) // Unique fft coefficients
#define PART_LEN2 (PART_LEN * 2) // Length of partition * 2

/*
#ifdef Short_Order
#define NR_PART 12 // Number of partitions
#else
#ifdef Long_Order
#define NR_PART 32 // Number of partitions
#else
#ifdef V0902
#define NR_PART 32 // Number of partitions
#endif
#endif
#endif

#define FILT_LEN (PART_LEN * NR_PART) // Filter length
#define FILT_LEN2 (FILT_LEN * 2) // Double filter length
#define FAR_BUF_LEN (FILT_LEN2 * 2)
#define PREF_BAND_SIZE 24
*/

#define BLOCKL_MAX FRAME_LEN

//add by wc
#define PreFilterOut
#define ToSimplify 
#define DataFilling

#define ERRTHRESH_QVALUE	40	
#define EF_QVALUE			30
#define WF_QVALUE			20


typedef WORD32 complex_t[2];
typedef WORD64 complex_tlong[2];


// For performance reasons, some arrays of complex numbers are replaced by twice
// as long arrays of float, all the real parts followed by all the imaginary
// ones (complex_t[SIZE] -> float[2][SIZE]). This allows SIMD optimizations and
// is better than two arrays (one for the real parts and one for the imaginary
// parts) as this other way would require two pointers instead of one and cause
// extra register spilling. This also allows the offsets to be calculated at
// compile time.

// Metrics
enum {offsetLevel = -100};
/*
typedef struct
{
	WORD64 sfrsum;
	WORD64 framelevel;
    WORD64 frsum;
	WORD64 minlevel;
    WORD64 averagelevel;
    
    WORD32 sfrcounter;

    WORD32 frcounter;

} power_level_t;

typedef struct
{
	WORD32 instant;
    WORD32 average;
    WORD32 min;
    WORD32 max;
    WORD32 sum;
    WORD32 hisum;
    WORD32 himean;
    WORD32 counter;
    WORD32 hicounter;
} stats_t;
*/
typedef struct
{
    WORD32 farBufWritePos, farBufReadPos;

    WORD32 knownDelay;
//    WORD32 inSamples, outSamples;
    WORD32 delayEstCtr;

    void *farFrBuf, *nearFrBuf, *outFrBuf, *prefilt_outFrBuf;

    void *nearFrBufH;
    void *outFrBufH;

	WORD16 xBuf[PART_LEN2];
	WORD16 dBuf[PART_LEN2];  // nearend	
//	WORD16 dBufH[PART_LEN2]; // nearend
	WORD32 yBuf[PART_LEN2];  // wuchao       //ebuf ybuf可否用WORD16???

	WORD32 xPow[PART_LEN1];
	WORD32 dPow[PART_LEN1];
	WORD32 dMinPow[PART_LEN1];
    WORD32 dInitMinPow[PART_LEN1];
	WORD32 *noisePow;

//	WORD32 mu;  ////Q15
//	WORD32 errThresh;  ////Q40
	//WORD32 targetSupp,minOverDrive; //targetSupp --Q11
//	WORD32 Corr_Th;

	WORD32 mu; ////Q15
	WORD32 errThresh;////Q40
	WORD32 mu_vr, mu_comm;               //Q15;
	WORD32 errThresh_vr, errThresh_comm; //Q40;

	WORD32 eBuf[PART_LEN2]; // error

	////////////// Changed by wc////////////////////////

	//WORD32 xfBuf[2][NR_PART * PART_LEN1]; // farend fft buffer
    //WORD32 wfBuf[2][NR_PART * PART_LEN1]; // filter fft
	//WORD32 xfBuf_Qvalue[NR_PART];

	complex_t *xfBuf,*wfBuf;  
	WORD32 *xfBuf_Qvalue;
	////////////// Changed by wc/////////////////////////

#ifdef OPTIMIZED_32BIT
	WORD32 sx[PART_LEN1], sd[PART_LEN1], se[PART_LEN1]; // far, near and error psd
#else
	//WORD64 sx[PART_LEN1], sd[PART_LEN1], se[PART_LEN1]; // far, near and error psd
#endif
    WORD32 hNs[PART_LEN1];
    //WORD32 hNlFbMin, hNlFbLocalMin;
    //WORD32 hNlXdAvgMin;
	//WORD32 overDrive, overDriveSm;
    
    WORD32 outBuf[PART_LEN];
	WORD32 prefilter_outBuf[PART_LEN];
	//WORD32 cn_scale_Hband;   //scale for comfort noise in H band
#ifdef OPTIMIZED_32BIT
    complex_t sde[PART_LEN1]; // cross-psd of nearend and error
    complex_t sxd[PART_LEN1]; // cross-psd of farend and nearend
//#ifdef V0902
	complex_t sxe[PART_LEN1]; // cross-psd of farend and error
//#endif
#else
    //complex_tlong sde[PART_LEN1]; // cross-psd of nearend and error
    //complex_tlong sxd[PART_LEN1]; // cross-psd of farend and nearend
#endif

#ifdef DE_XFW
 //   complex_t xfwBuf[NR_PART * PART_LEN1]; // farend windowed fft buffer
	complex_t *xfwBuf;
#endif
	//WORD32 xfwBuf_Qvalue[NR_PART];

	///////////add by wc//////////////
	WORD16 COM_mode,ASR_mode,Last_mode;
	WORD16 NR_PART;
	WORD16 FAR_BUF_LEN;
	WORD32 *efwBuf_R;
	WORD32 *efwBuf_I;
	WORD32 *efw_Qvalue_buf;
	
	WORD16 *hNlBuf1;
	WORD16 *hNlBuf2;
	WORD16 state;
	WORD32 NoiseEstEn;
	WORD16 InitBlock;
	WORD32 sy[PART_LEN1];
	WORD16 N_Delay;
	WORD16 sy_Qvalue,NoiseEstEn_Qvalue;
	WORD32 local_min, local_tmp;
	WORD16 local_count;
	WORD16 local_min_Qvalue, local_tmp_Qvalue;	
	WORD16 block_for_init, Min_search,local_frame, echo_prob;
	/////////////////////

    //WORD32 hNlNewMin, hNlMinCtr;

    WORD32 delayIdx;

    //WORD16 stNearState;
	WORD16 echoState;
    WORD16 divergeState;

    WORD32 xfBufBlockPos;
	WORD32 efBufInputPos,efBufOutputPos;

#ifdef DE_BUF
    //WORD16 farBuf[FILT_LEN2 * 2];
	*farBuf;
#endif
    WORD16 mult; // sampling frequency multiple
    WORD32 sampFreq;
    UWORD32 seed;

    WORD32 noiseEstCtr;

    //power_level_t farlevel;
    //power_level_t nearlevel;
    //power_level_t linoutlevel;
    //power_level_t nlpoutlevel;

    WORD32 metricsMode;
    //WORD32 stateCounter;
    //stats_t erl;
    //stats_t erle;
    //stats_t aNlp;
    //stats_t rerl;

    // Quantities to control H band scaling for SWB input
    //WORD32 freq_avg_ic;         //initial bin for averaging nlp gain
    //WORD32 flag_Hband_cn;      //for comfort noise

	WORD32 xpow_Qvalue, dPow_Qvalue ,dMinPow_Qvalue ,dInitMinPow_Qvalue, noisePow_Qvalue ;
	WORD32 sx_Qvalue, sd_Qvalue, se_Qvalue, sde_Qvalue, sxd_Qvalue;
//#ifdef V0902
	WORD32 sxe_Qvalue;
//#endif
	WORD16 hNl[PART_LEN1];
	WORD32 hNl_alpha;
#ifdef SPL_FFT
	WORD16 realImag[PART_LEN2*2];
	WORD32 stages;
#endif
    
} aec_t;

typedef void (*TwAec_FilterFar_t)(aec_t *aec, WORD32 yf[2][PART_LEN1],WORD32 xf_Qvalue, WORD32 wf_Qvalue, WORD32 yf_outQvalue);
typedef WORD32 (*TwAec_FilterAdaptation_t) (aec_t *aec, WORD32 *fft, WORD32 fft_Qvalue, WORD32 ef[2][PART_LEN1]);
typedef WORD32 (*TwAec_OverdriveAndSuppress_t) (aec_t *aec, WORD16 hNl[PART_LEN1], const WORD32 hNlFb, WORD32 efw[2][PART_LEN1]);

extern TwAec_FilterFar_t TwAec_FilterFar;
typedef void (*TwAec_ScaleErrorSignal_t)(aec_t *aec, WORD32 ef[2][PART_LEN1], WORD32 ef_Qvalue);
extern TwAec_ScaleErrorSignal_t TwAec_ScaleErrorSignal;

extern TwAec_FilterAdaptation_t TwAec_FilterAdaptation;

extern TwAec_OverdriveAndSuppress_t TwAec_OverdriveAndSuppress;

WORD32 TwAec_CreateAec(aec_t **aec , WORD32 sampFreq);
//WORD32 TwAec_CreateAec(aec_t **aec , WORD32 sampFreq, WORD16 mode);
WORD32 TwAec_FreeAec(aec_t *aec);
WORD32 TwAec_InitAec(aec_t *aec, WORD32 sampFreq);
//void TwAec_InitAec_SSE2(void);

//void TwAec_InitMetrics(aec_t *aec);
void TwAec_ProcessFrame(aec_t *aec, const WORD16 *farend,
                       const WORD16 *nearend, const WORD16 *nearendH,
                       WORD16 *out, WORD16 *prefilt_out, WORD16 *outH,
                       WORD32 knownDelay, WORD16 selected_mode);

#endif // TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_AEC_CORE_H_

