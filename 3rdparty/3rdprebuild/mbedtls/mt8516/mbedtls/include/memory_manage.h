#ifndef _QWAKEUP_MEMORY_H_
#define _QWAKEUP_MEMORY_H_

#include <stdlib.h>
#include <string.h>


//#define MEM_DEBUG

#ifdef MEM_DEBUG
#ifdef __cplusplus
extern "C" int g_total_byte;
#else
extern int g_total_byte;
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


 void* MemCalloc(int cnt, int size);

 void* MemMalloc(int size);

#ifdef WIN32
int gettimeofday(struct timeval *tp, void *tzp);
#else
unsigned long GetTickCount();
#endif

#ifdef __cplusplus
}
#endif

#endif
