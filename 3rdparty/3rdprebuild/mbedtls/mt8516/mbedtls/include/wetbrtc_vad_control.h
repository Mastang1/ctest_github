#ifndef _WEBRTC_VAD_CONTROL_H_
#define _WEBRTC_VAD_CONTROL_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "webrtc_vad.h"

#define  HIGH_SCORE_THREAD  0

class  WebrtcVADControl {
private:
	void						*hvad;

	short						*pOut;//save cmd data
	short                       *pEnd;
	short                       *pRt;
	int                          _buffSampleLen;
	int							cmdFrm;//number of frames in short
	int                         totalcmdFrm;//accumulated frames
	int							preRet;//last vad result
	int                         _fs;
	int                         _frmShift;
	short                       _g_maxFrm;
	short                       _g_minFrm;
	short                       _g_sgeFrm;
	short                       _g_sgetmp;
	short                       _lookaHeadNo;
	short                       _g_traceBack;
	//short                       _high_score;
	int                          g_frm;
public:	
	WebrtcVADControl(short maxFrm, short minFrm, short segFrm, short lookAhead,short traceBack,int fs = 16000);
	~WebrtcVADControl();
	int  init_vad(short min_energy, short individual_10ms_agc, short total_10ms_agc);
	int  reset_vad();
	int  get_voice(short* input, int SampleLen, short **output1, int *outputLen1, short **output2, int *outputLen2);
};

#endif