#ifndef COMPLEX_FFT_H_
#define COMPLEX_FFT_H_
#include "bf_common.h"

void *bf_complex_fft_init(int size);
void bf_complex_fft(void *table, Flt32 *in, Complex *out);
void bf_complex_ifft(void *table, Complex *in, Flt32 *out);

#endif
