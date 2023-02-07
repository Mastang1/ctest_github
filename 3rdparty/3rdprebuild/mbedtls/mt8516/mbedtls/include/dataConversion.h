#ifndef __DATA_CONVERSION_H__
#define __DATA_CONVERSION_H__

#ifdef __cplusplus 
extern "C"
{ 
#endif

int data_24bits2int(char *b, int *i, int numsamples);

int data_int224bits(int *i, char *b, int numsamples);
int data_24bits2float(char *b, float *f, int numsamples);

#ifdef __cplusplus 
}
#endif

#endif

