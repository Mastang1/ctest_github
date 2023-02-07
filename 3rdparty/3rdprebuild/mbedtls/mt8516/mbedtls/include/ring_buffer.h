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
 * Specifies the interface for the AEC generic buffer.
 */

#ifndef TW_MODULES_AUDIO_PROCESSING_UTILITY_RING_BUFFER_H_
#define TW_MODULES_AUDIO_PROCESSING_UTILITY_RING_BUFFER_H_

#include "../spl/typedefs.h"
#include "aec_core.h"


// Determines buffer datatype
typedef short bufdata_t;

// Unless otherwise specified, functions return 0 on success and -1 on error
WORD32 TwApm_CreateBuffer(void **bufInst, WORD32 size);
WORD32 TwApm_InitBuffer(void *bufInst);
WORD32 TwApm_FreeBuffer(void *bufInst);

// Returns number of samples read
WORD32 TwApm_ReadBuffer(void *bufInst, bufdata_t *data, WORD32 size);

// Returns number of samples written
WORD32 TwApm_WriteBuffer(void *bufInst, const bufdata_t *data, WORD32 size);

// Returns number of samples flushed
#ifdef DE_BUF
WORD32 TwApm_FlushBuffer(void *bufInst, WORD32 size);
#endif

// Returns number of samples stuffed
WORD32 TwApm_StuffBuffer(void *bufInst, WORD32 size);

// Returns number of samples in buffer
WORD32 TwApm_get_buffer_size(const void *bufInst);

#endif // TW_MODULES_AUDIO_PROCESSING_UTILITY_RING_BUFFER_H_
