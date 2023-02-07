/*******************************************************************************
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

/*******************************************************************************
* Modification history
* --------------------
*
* 2016-01-19 fanming create file
*******************************************************************************/

#ifndef __API_SYS_COMMON_H__
#define __API_SYS_COMMON_H__

#include "uplus_extern.h"

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <netdb.h>
#include <sys/time.h>
#include <fcntl.h>      /*文件控制定义*/
#include <termios.h>    /*PPSIX 终端控制定义*/
#include <malloc.h>

#include "mbedtls/config.h"
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#endif
#include "mbedtls/net.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ANDROID
/*#define MEM_DEBUG*/
#endif

typedef struct sys_conf_info
{
	char raw_file[32];
	char ota_file1[32];
	char ota_file2[32];

	char if_name[32];
	char serial_name[32];
	char config_file1[32];
	char config_file2[32];
} sys_conf_info_t;

typedef struct sys_info
{
	sys_conf_info_t conf;
	FILE *ota_file;
	unsigned long age_number;
	int net_err;
	struct timeval start_time;

#ifdef MEM_DEBUG
	uplus_id mutex;
	uplus_u32 total_used_mem;
	uplus_u32 total_mem_block;
#endif
} sys_info_t;

typedef struct ota_valid
{
	unsigned char magic_numer[4]; /*NVRM*/
	unsigned long age_number;
} ota_valid_t;

extern sys_info_t *my_sys;
extern int uplus_local_if_ioctl(u_long request, caddr_t buffer);

#ifdef __cplusplus
}
#endif

#endif

