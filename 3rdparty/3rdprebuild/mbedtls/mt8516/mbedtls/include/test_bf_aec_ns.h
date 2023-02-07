#ifndef BF_AEC_NS_H_
#define BF_AEC_NS_H_

#include "common.h"
#include "../top/my_debug.h"
//#include "tvqe_java.h"


#ifdef __cplusplus
extern "C" {
#endif
	typedef enum{
		HAIER_BF_AEC_NS_OK = 0,
		HAIER_BF_AEC_NS_MALLOC_ERR = 1,
		HAIER_BF_AEC_NS_CHANNEL_ERR = 2,
		HAIER_BF_AEC_NS_BEAMFORMING_INIT_ERR = 3,
		HAIER_BF_AEC_NS_AEC_INIT_ERR = 4,
		HAIER_BF_AEC_NS_NS_INIT_ERR = 5,
		HAIER_BF_AEC_NS_AGC_INIT_ERR = 6,
		HAIER_BF_AEC_NS_WPE_INIT_ERR = 7,
		HAIER_BF_AEC_NS_OPEN_FILE_ERR = 8,
	}HAIER_BF_AEC_NS_ERR_CODE; 

	int bf_aec_ns_init(void** pStruct, float mic_distance_ms, int control_flag, int chan);
//#ifdef OUTPUT_2CHAN
	int bf_aec_ns_process(void* pStruct, short* pInBuf, short* pOutBuf, short* pOutBufR);
//#else
//	int bf_aec_ns_process(void* pStruct, short* pInBuf, short* pOutBuf);
//#endif
	void bf_aec_ns_destroy(void* pStruct);

#ifdef __cplusplus
}
#endif

#endif