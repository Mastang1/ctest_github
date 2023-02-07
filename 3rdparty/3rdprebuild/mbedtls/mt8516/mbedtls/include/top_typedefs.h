// This file contains platform-specific typedefs and defines.

#ifndef BF_TYPEDEFS_H_
#define BF_TYPEDEFS_H_

#ifndef __ANDROID__
typedef signed char         int8_t;
typedef short               int16_t;
typedef int                 int32_t;
typedef long			    int64_t;

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long    uint64_t;

#endif

typedef double              Flt32;
typedef double              Flt64;

#ifndef NULL 
	#if defined(__cplusplus)
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif

#endif  // BF_TYPEDEFS_H_
