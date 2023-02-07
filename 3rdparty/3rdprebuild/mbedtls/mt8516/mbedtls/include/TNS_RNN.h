//#pragma once


#include "rnnoise.h"
#include "stb_fft.h"


struct RnnDenoiseParameters_;
typedef struct RnnDenoiseParameters_ RnnDenoiseParameters;

RnnDenoiseParameters *RnnDenoise_Init(uint32_t channels, uint32_t sampleRate, uint32_t targetFrameSize, uint32_t targetSampleRate);

void RnnDenoise_Process(RnnDenoiseParameters* tns_st, float *data_in, float *data_out, float* vad_prob);

void RnnDenoise_Exit(RnnDenoiseParameters* tns_st);