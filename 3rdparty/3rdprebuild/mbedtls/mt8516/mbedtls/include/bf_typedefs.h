// This file contains platform-specific typedefs and defines.

#ifndef TW_TYPEDEFS_H_
#define TW_TYPEDEFS_H_

typedef signed char         int8_t;
typedef short               int16_t;
typedef int                 int32_t;
//typedef long			    int64_t;
//typedef __int64             int64_t;

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
//typedef unsigned long    uint64_t;
//typedef unsigned __int64    uint64_t;

typedef double              Flt32;
typedef double              Flt64;

#ifndef NULL 
	#if defined(__cplusplus)
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif

#endif  // TW_TYPEDEFS_H_
