/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_AEC_RDFT_H_
#define TW_MODULES_AUDIO_PROCESSING_AEC_MAIN_SOURCE_AEC_RDFT_H_

#include "../spl/typedefs.h"
//#include "dbgprint.h"


#ifdef _MSC_VER /* visual c++ */
//# define ALIGN16_BEG __declspec(align(16))
# define ALIGN16_BEG 
# define ALIGN16_END

#define __FUNCTION__	"vc6 version"

#elif __CC_ARM
# define ALIGN16_BEG 
# define ALIGN16_END

#else /* gcc or icc */
# define ALIGN16_BEG
//# define ALIGN16_END __attribute__((aligned(16)))
# define ALIGN16_END
#endif


// constants shared by all paths (C, SSE2).
#ifdef COMPAR_FIX_FLOAT

extern WORD32 rdft_w[64];
// constants used by the C path.
extern WORD32 rdft_wk3ri_first[32];
extern WORD32 rdft_wk3ri_second[32];
// constants used by SSE2 but initialized in C path.
extern WORD32 rdft_wk1r[32];
extern WORD32 rdft_wk2r[32];
extern WORD32 rdft_wk3r[32];
extern WORD32 rdft_wk1i[32];
extern WORD32 rdft_wk2i[32];
extern WORD32 rdft_wk3i[32];

#else
extern float rdft_w[64];
// constants used by the C path.
extern float rdft_wk3ri_first[32];
extern float rdft_wk3ri_second[32];
// constants used by SSE2 but initialized in C path.
extern float rdft_wk1r[32];
extern float rdft_wk2r[32];
extern float rdft_wk3r[32];
extern float rdft_wk1i[32];
extern float rdft_wk2i[32];
extern float rdft_wk3i[32];
#endif


// code path selection function pointers
#ifdef COMPAR_FIX_FLOAT
typedef WORD32 (*rft_sub_128_t)(WORD32 *a, WORD32 );
#else
typedef void (*rft_sub_128_t)(float *a);
#endif

extern rft_sub_128_t rftfsub_128;
extern rft_sub_128_t rftbsub_128;
extern rft_sub_128_t cft1st_128;

// entry points
void aec_rdft_init(void);
void aec_rdft_init_sse2(void);

#ifdef COMPAR_FIX_FLOAT
//WORD32 aec_rdft_forward_128(WORD32 *a);
WORD32 aec_rdft_forward_128(WORD32 *a, WORD32 in_Qvalue);
WORD32 aec_rdft_inverse_128(WORD32 *a, WORD32 in_Qvalue);
#else
void aec_rdft_forward_128(float *a);
void aec_rdft_inverse_128(float *a);
#endif

#endif
