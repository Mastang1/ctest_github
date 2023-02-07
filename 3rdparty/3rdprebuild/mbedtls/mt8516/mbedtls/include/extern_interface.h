#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
	int bf_aec_ns_init(void** pStruct, float mic_distance_ms, int control_flag);
	int bf_aec_ns_process(void* pBFStruct, short* pInBuf, short* pOutBuf);
	void bf_aec_ns_destroy(void* pStruct);
#ifdef __cplusplus
}
#endif

#endif