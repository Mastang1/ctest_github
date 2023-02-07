#ifndef _NDOT_CALCULATE_H_
#define _NDOT_CALCULATE_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "my_debug.h"
#include "split.h"
#include "AudioEnergy.h"


#ifdef AEC_INIT_INNER
#ifdef OUTPUT_AEC_FILES
float nDotFrontCalculate(short data[], int len,mic_board_type_e mic_board_type, float ratio,const char* aecOutName);
#else
float nDotFrontCalculate(short data[], int len,mic_board_type_e mic_board_type,float ratio);
#endif

#else
float nDotFrontCalculate(short data[], int len, mic_board_type_e mic_board_type, void* pStruct);
#endif



#ifdef __cplusplus
}
#endif

#endif