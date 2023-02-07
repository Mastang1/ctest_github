#ifndef COMMON_H_
#define COMMON_H_

#include "bf_typedefs.h"

#define FFT_SIZE	   1024
#define FRAME_LEN     (FFT_SIZE)
#define NUM_BINS      (FFT_SIZE/2+1)
#define STFT_SHIFT    (FRAME_LEN/2)
#define FS            (16000.0)
#define SOUND_SPEED   (340.0)
#define EPS  (2.220446049250313e-16)
#define PI	 (3.1415926535898)

#define ABS(x)  ( (x)>0?(x):-(x) )

#define SAFE_FREE(x)  if(x!=NULL) {free(x); x = NULL;}


#define J 40 //Filter tap length
#define M 2 //Number of input channels
#define MJ 80
#define win_length 512
#define fft_length 1024
#define win_by2_plus1 257
#define win_inc 307
#define Lgs 37
#define LG 289
#define PI 3.1415926535
//#define EPS 1e-60
#define SAMPLE_RATE 16000


#endif