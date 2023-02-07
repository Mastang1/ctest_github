/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_INTERFACE_ECHO_CANCELLATION_H_
#define TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_INTERFACE_ECHO_CANCELLATION_H_

#include "../spl/typedefs.h"
#include "aec_core.h"

// Errors
#define AEC_UNSPECIFIED_ERROR           12000
#define AEC_UNSUPPORTED_FUNCTION_ERROR  12001
#define AEC_UNINITIALIZED_ERROR         12002
#define AEC_NULL_POINTER_ERROR          12003
#define AEC_BAD_PARAMETER_ERROR         12004

// Warnings
#define AEC_BAD_PARAMETER_WARNING       12050

enum {
    kAecNlpConservative = 0,
    kAecNlpModerate,
    kAecNlpAggressive
};

enum {
    kAecFalse = 0,
    kAecTrue
};

typedef struct {
    WORD16 nlpMode;        // default kAecNlpModerate
    WORD16 skewMode;       // default kAecFalse
    WORD16 metricsMode;    // default kAecFalse
    //float realSkew;
} AecConfig;

/*
typedef struct {
#ifdef COMPAR_FIX_FLOAT
    WORD32 instant;
    WORD32 average;
    WORD32 max;
    WORD32 min;
#else
    WORD16 instant;
    WORD16 average;
    WORD16 max;
    WORD16 min;
#endif
} AecLevel;

typedef struct {
    AecLevel rerl;
    AecLevel erl;
    AecLevel erle;
    AecLevel aNlp;
} AecMetrics;
*/
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Allocates the memory needed by the AEC. The memory needs to be initialized
 * separately using the TwAec_Init() function.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void **aecInst               Pointer to the AEC instance to be created
 *                              and initilized
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32 return          0: OK
 *                              -1: error
 */
//WORD32 TwAec_Create(void **aecInst);
//WORD32 TwAec_Create(void **aecInst, WORD32 sampFreq, WORD16 SelectMode);
WORD32 TwAec_Create(void **aecInst, WORD32 sampFreq);
/*
 * This function releases the memory allocated by TwAec_Create().
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void         *aecInst        Pointer to the AEC instance
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32  return         0: OK
 *                              -1: error
 */
WORD32 TwAec_Free(void *aecInst);

/*
 * Initializes an AEC instance.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 * WORD32  sampFreq      Sampling frequency of data
 * WORD32  scSampFreq    Soundcard sampling frequency
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32 return          0: OK
 *                              -1: error
 */
WORD32 TwAec_Init(void *aecInst,
                             WORD32 sampFreq,
                             WORD32 scSampFreq);

/*
 * Inserts an 80 or 160 sample block of data into the farend buffer.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 * WORD16  *farend       In buffer containing one frame of
 *                              farend signal for L band
 * WORD16  nrOfSamples   Number of samples in farend buffer
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32  return         0: OK
 *                              -1: error
 */
#ifdef DE_SKEW
WORD32 TwAec_BufferFarend(void *aecInst,
                                     const WORD16 *farend,
                                     WORD16 nrOfSamples);
#endif
/*
 * Runs the echo canceller on an 80 or 160 sample blocks of data.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void          *aecInst       Pointer to the AEC instance
 * WORD16 *nearend       In buffer containing one frame of
 *                              nearend+echo signal for L band
 * WORD16 *nearendH      In buffer containing one frame of
 *                              nearend+echo signal for H band
 * WORD16 nrOfSamples    Number of samples in nearend buffer
 * WORD16 msInSndCardBuf Delay estimate for sound card and
 *                              system buffers
 * WORD16 skew           Difference between number of samples played
 *                              and recorded at the soundcard (for clock skew
 *                              compensation)
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD16  *out          Out buffer, one frame of processed nearend
 *                              for L band
 * WORD16  *outH         Out buffer, one frame of processed nearend
 *                              for H band
 * WORD32  return         0: OK
 *                              -1: error
 */
WORD32 TwAec_Process(void *aecInst,
                                const WORD16 *nearend,
                                const WORD16 *nearendH,
                                WORD16 *out,
								WORD16 *prefilt_out,
                                WORD16 *outH,
                                WORD16 nrOfSamples,
#ifdef DE_BUF
#else
								const WORD16 *reference_in,
#endif
                                WORD16 msInSndCardBuf,
                                WORD32 skew,
								WORD16 selected_mode);

/*
 * This function enables the user to set certain parameters on-the-fly.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 * AecConfig      config        Config instance that contains all
 *                              properties to be set
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32  return         0: OK
 *                              -1: error
 */
WORD32 TwAec_set_config(void *aecInst, AecConfig config);

/*
 * Gets the on-the-fly paramters.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * AecConfig      *config       Pointer to the config instance that
 *                              all properties will be written to
 * WORD32  return         0: OK
 *                              -1: error
 */
WORD32 TwAec_get_config(void *aecInst, AecConfig *config);

/*
 * Gets the current echo status of the nearend signal.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD16  *status       0: Almost certainly nearend single-talk
 *                              1: Might not be neared single-talk
 * WORD32  return         0: OK
 *                              -1: error
 */
//WORD32 TwAec_get_echo_status(void *aecInst, WORD16 *status);

/*
 * Gets the current echo metrics for the session.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * AecMetrics     *metrics      Struct which will be filled out with the
 *                              current echo metrics.
 * WORD32  return         0: OK
 *                              -1: error
 */
//WORD32 TwAec_GetMetrics(void *aecInst, AecMetrics *metrics);

/*
 * Gets the last error code.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * void           *aecInst      Pointer to the AEC instance
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD32  return        11000-11100: error code
 */
//WORD32 TwAec_get_error_code(void *aecInst);

/*
 * Gets a version string.
 *
 * Inputs                       Description
 * -------------------------------------------------------------------
 * char           *versionStr   Pointer to a string array
 * WORD16  len           The maximum length of the string
 *
 * Outputs                      Description
 * -------------------------------------------------------------------
 * WORD8   *versionStr   Pointer to a string array
 * WORD32  return         0: OK
 *                              -1: error
 */
//WORD32 TwAec_get_version(WORD8 *versionStr, WORD16 len);

#ifdef __cplusplus
}
#endif
#endif  /* TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_INTERFACE_ECHO_CANCELLATION_H_ */