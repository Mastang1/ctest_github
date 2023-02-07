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
* 2016-02-03 fanming create file
*******************************************************************************/

#ifndef __UPLUS_XXX_DEF_H__
#define __UPLUS_XXX_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************/
/*debug, controlled by make*/
/*#define DEBUG_VERSION*/

/*debug, default: off*/
#define TEST_XXX_TX
/******************************************************************/

#define uplug_syslog(fmt, ...) \
	uplus_sys_log("%u:"fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);

/*resource def*/
/*time def*/
#define TIME_MILLISECOND (1)
#define TIME_SECOND (1000 * (TIME_MILLISECOND))
#define TIME_MINUTE (60 * (TIME_SECOND))
#define TIME_HOUR (60 * (TIME_MINUTE))
#define TIME_DAY (24 * (TIME_HOUR))

#define TIME_WAIT_RESPONSE (10 * (TIME_SECOND))

/*task name*/
#define TASK_NAME_XXX "t_xxx"

/*task stack*/
#define TASK_STACK_SIZE_XXX 1024

/*task priority*/
#define TASK_PRIORITY_XXX 4

typedef struct xxx_control
{
	uplus_u8 sync_mode; /*tx request and wait response*/
	uplus_u8 rsp_rcvd; /*for sync mode*/
	uplus_u8 status_ok; /*status is ok*/

	uplus_u8 dev_mac[6];
	/*registered device info*/
	dev_info_t dev_info;
	uplus_u8 dev_protocol; /*any char, but diff for diffent device protocol, 'E' is reserved for E++*/
	uplus_u8 dev_instance; /*indicate different instance*/
	uplus_u8 dev_registered; /*the device is registered?*/

	uplus_u32 sn;
	/*TODO: add your vars*/
}xxx_control_t;

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_XXX_DEF_H__*/

