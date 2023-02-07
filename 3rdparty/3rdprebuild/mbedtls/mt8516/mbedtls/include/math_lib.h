/*
2.4 kbps MELP Proposed Federal Standard speech coder

Fixed-point C code, version 1.0

*/
/* 
   math_lib.h    Math include file.
                 (Log and Divide functions.)  

*/
#ifndef __math_lib_h_
#define __math_lib_h_

#include "../spl/typedefs.h"

/* External function definitions */
//WORD16 divider(WORD16 numer, WORD16 denom, WORD16 numer_shift, WORD16 denom_shift);
//WORD16 L_divider2 (WORD32 numer, WORD32 denom, WORD16 numer_shift, WORD16 denom_shift);
//WORD16 log10_fxp(WORD16 x, WORD16 Q);
//WORD16 L_log10_fxp(WORD32 x, WORD16 Q);
//WORD16 L_loge_fxp(WORD32 x, WORD16 Q);
//WORD16 pow10_fxp(WORD16 x, WORD16 Q);
//WORD16 sqrt_fxp (WORD16 x, WORD16 Q);
//WORD16 L_sqrt_fxp(WORD32 x, WORD16 Q);
//WORD16 L_pow_fxp(WORD32 x,WORD16 power,WORD16 Q_in,WORD16 Q_out);
//WORD16 LL_pow_fxp(WORD32 x,WORD16 power, WORD16 Q_in,WORD16 Q_power, WORD16 Q_out);
WORD16 sin_fxp(WORD16 x);
WORD16 cos_fxp(WORD16 x);
//WORD16 acos_fxp(WORD16 x);
//WORD64 iSqrt(WORD64 value);
//UWORD64 iCbrt(UWORD64 value); //lita: add for compute cube root in fix point version
//WORD16 log2_polyfit(long value);
//WORD32 L_mpy_ll(WORD32 L_var1, WORD32 L_var2);

#endif
