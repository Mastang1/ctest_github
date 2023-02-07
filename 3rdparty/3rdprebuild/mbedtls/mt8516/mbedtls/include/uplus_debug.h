/******************************************************************************
*
* Copyright (c) 2015-2016 Haier uHome uBic. All Rights Reserved. 
* No part of this publication may be reproduced, transmitted, transcribed, 
* stored in a retrieval system, or translated into any language in any form 
* or by any means without the written permission of Haier uHome uBic, 
* or its suppliers or affiliate companies. To obtain this permission, 
* write to the attention of the Haier uHome uBic legal department.
*
* DESCRIPTION:
*
*******************************************************************************/

/******************************************************************************
*
* Modification history
* --------------------
*
* 2016-05-27 fanming create file
*******************************************************************************/

#ifndef __UPLUS_DEBUG_H__
#define __UPLUS_DEBUG_H__

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG_LEVEL_NONE  0
#define DEBUG_LEVEL_ERROR 0x1
#define DEBUG_LEVEL_WARN  0x2
#define DEBUG_LEVEL_INFO  0x4
#define DEBUG_LEVEL_DEBUG 0x8
#define DEBUG_LEVEL_BUF 0x10

#ifdef DEBUG_VERSION
extern uplus_u32 uplug_debug_level;
extern void uplus_util_debug_printf_info(uplus_u32 level, const char *info);
extern void uplug_util_print_buf(uplus_u8 *buf, int len);
extern void uplus_util_print_mem_alloc_fail(uplus_u32 level, const char *file, int line);
extern void uplus_util_print_module_init_fail(uplus_u32 level, const char *module);
extern void uplus_util_print_create_fail(uplus_u32 level, const char *info);
extern void uplus_util_print_common_fail(uplus_u32 level, const char *info);

#ifndef UPLUS_NO_DEBUG_PRINT
#define uplus_debug_printf_debug(fmt, ...)\
	do\
	{\
		if (DEBUG_LEVEL_DEBUG & uplug_debug_level)\
			uplus_sys_debug_printf("[%u]: "fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);\
	} while(0)
#else
#define uplus_debug_printf_debug(fmt, ...)
#endif

#define uplus_debug_printf_info(level, info) uplus_util_debug_printf_info(level, info)

#define uplus_debug_printf(level, fmt, ...) \
	do\
	{\
		if (level & uplug_debug_level)\
			uplus_sys_debug_printf("[%u]: "fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);\
	} while(0)
#define uplus_debug_printf_buf(level, buf, len, fmt, ...) \
	do\
	{\
		if ((level & uplug_debug_level) && (DEBUG_LEVEL_BUF & uplug_debug_level))\
		{\
			uplus_sys_debug_printf("[%u]: "fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);\
			uplug_util_print_buf((uplus_u8 *)buf, (int)len);\
		}\
	} while(0)
#define uplus_debug_print_mem_alloc_fail(level) uplus_util_print_mem_alloc_fail(level, __FILE__, __LINE__);
#define uplus_debug_print_module_init_fail(level, module) uplus_util_print_module_init_fail(level, module);
#define uplus_debug_print_create_fail(level, info) uplus_util_print_create_fail(level, info);
#define uplus_debug_print_common_fail(level, info) uplus_util_print_common_fail(level, info);
#else
#define uplus_debug_printf_debug(fmt, ...)
#define uplus_debug_printf_info(level, info)
#define uplus_debug_printf(level, fmt, ...)
#define uplus_debug_printf_buf(level, buf, len, fmt, ...)
#define uplus_debug_print_mem_alloc_fail(level)
#define uplus_debug_print_module_init_fail(level, module)
#define uplus_debug_print_create_fail(level, info)
#define uplus_debug_print_common_fail(level, info)
#endif

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_DEBUG_H__*/

