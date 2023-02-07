#ifndef BEAMFORMING_2CH_H_
#define BEAMFORMING_2CH_H_
#include "bf_common.h"

//void beamforming_2ch_init(int16_t fft_size,int16_t frame_len,Flt32 beanwidth);

//void beamforming_2ch_process(int16_t* in_L,int16_t* in_R,int16_t* out_L,int16_t* out_R);

int beamforming_2ch_init(void** bfPara, int16_t fft_size, int16_t frame_len, Flt32 beamwidth, Flt32 d_mic);

void beamforming_2ch_process(void* bfPara, int16_t* in_L, int16_t* in_R, int16_t* out_L, int16_t* out_R);

void beamforming_2ch_destroy(void* bfPara);

#endif
