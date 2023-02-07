//#ifndef COMMON_H_
//#define COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "./typedefs.h"

#define FFT_SIZE_WPE   512
#define STFT_SHIFT_WPE   (FFT_SIZE_WPE/2)
#define STFT_SHIFT_WPE_FRAME  (STFT_SHIFT_WPE+160)
#define FFT_SIZE	   1024
#define NUM_BINS      (FFT_SIZE/2+1)
#define STFT_SHIFT    (FFT_SIZE/2)
#define FS            (16000.0)
#define SOUND_SPEED   (340.0)
#define EPS  (2.220446049250313e-16)
#define PI	 (3.1415926535898)


#define ABS(x)  ( (x)>0?(x):-(x) )

#define SAFE_FREE(x)  if(x!=NULL) {free(x);}

//#endif