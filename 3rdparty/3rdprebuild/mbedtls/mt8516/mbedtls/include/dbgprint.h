
#ifndef DBGPRINT
#define DBGPRINT

#ifdef __cplusplus
extern "C" {
#endif

#include "typedefs.h"

//#define FIXED_COPARE


void tprintf(WORD8 *fmt, ...);
void printf_block(void* in, WORD32 len, WORD32 type);
void printf_block_LL(void* in, WORD32 len, WORD32 type);
void printf_block_float_LL(void* in, WORD32 len,  WORD32 type, WORD32 Q_value);
void printf_block_float(void* in, WORD32 len,  WORD32 type, WORD32 Q_value);


#ifdef __cplusplus
}
#endif

#endif

