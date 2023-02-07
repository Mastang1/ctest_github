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
* 2015-08-21 fanming create file
*******************************************************************************/

#ifndef __UPLUS_TYPE_H__
#define __UPLUS_TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char uplus_u8;
typedef unsigned short uplus_u16;
typedef unsigned int uplus_u32;
typedef char uplus_s8;
typedef short uplus_s16;
typedef int uplus_s32;
typedef uplus_u32 uplus_time;
typedef void (*task_func)(void *para);
typedef void * uplus_id;

/** For compatibility with BSD code */
struct uplus_in_addr
{
	uplus_u32 s_addr; /*network order*/
};

struct uplus_sockaddr_in
{
	uplus_u16 sin_family;
	uplus_u16 sin_port; /*network order*/
	struct uplus_in_addr sin_addr; /*network order*/
	char sin_zero[8];
};

struct uplus_sockaddr
{
	uplus_u16 sa_family;
	char sa_data[14];
};

struct uplus_timeval
{
	uplus_u32 tv_sec; /* seconds */
	uplus_u32 tv_usec; /* microseconds */
};

#ifndef NULL
#define NULL ((void*) 0)
#endif

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_TYPE_H__*/

