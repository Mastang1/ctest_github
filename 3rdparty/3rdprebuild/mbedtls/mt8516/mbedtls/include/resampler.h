/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_RESAMPLER_H_
#define TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_RESAMPLER_H_

#include "../spl/typedefs.h"
#include "aec_core.h"

#ifdef DE_SKEW
enum { kResamplingDelay = 1 };

// Unless otherwise specified, functions return 0 on success and -1 on error
int TwAec_CreateResampler(void **resampInst);
int TwAec_InitResampler(void *resampInst, int deviceSampleRateHz);
int TwAec_FreeResampler(void *resampInst);
#endif

// Estimates skew from raw measurement.
#ifdef DE_SKEW
#ifdef COMPAR_FIX_FLOAT
int TwAec_GetSkew(void *resampInst, int rawSkew, WORD32 *skewEst);
#else
int TwAec_GetSkew(void *resampInst, int rawSkew, float *skewEst);
#endif
#endif

// Resamples input using linear interpolation.
// Returns size of resampled array.
#ifdef DE_BUF
#ifdef COMPAR_FIX_FLOAT
int TwAec_ResampleLinear(void *resampInst,
                             const short *inspeech,
                             int size,
                             WORD32 skew,
                             short *outspeech);
#else
int TwAec_ResampleLinear(void *resampInst,
                             const short *inspeech,
                             int size,
                             float skew,
                             short *outspeech);
#endif
#endif

#endif // TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_RESAMPLER_H_
