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
* 2016-02-22 fanming create file
*******************************************************************************/

#ifndef __UPLUS_CONFIG_FILE_H__
#define __UPLUS_CONFIG_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

/*uplus module def, may be set to on/off, default: on*/
/*
#define UPLUS_FEATURE_MODULE_LED
#define UPLUS_FEATURE_MODULE_DISCOVERY
#define UPLUS_FEATURE_MODULE_CLIENT
#define UPLUS_FEATURE_MODULE_SERVER
#define UPLUS_FEATURE_MODULE_OTA
#define UPLUS_FEATURE_MODULE_SECURITY
#define UPLUS_FEATURE_MODULE_UWT
#define UPLUS_FEATURE_MODULE_WIFI

#ifdef UPLUS_FEATURE_MODULE_WIFI
#define UPLUS_FEATURE_MODULE_SCAN
#define UPLUS_FEATURE_MODULE_PRODUCT
#define UPLUS_FEATURE_MODULE_SOFTAP
#define UPLUS_FEATURE_MODULE_SMARTLINK
#define UPLUS_FEATURE_MODULE_THIRD_CONFIG
#if (defined UPLUS_FEATURE_MODULE_SOFTAP || defined UPLUS_FEATURE_MODULE_SMARTLINK || defined UPLUS_FEATURE_MODULE_THIRD_CONFIG)
#define UPLUS_FEATURE_MODULE_WIFI_CONFIG
#endif
#endif
*/

/*set by makefile
#define UPLUS_NOT_SUPPORT_DATA_CONVERT
#define UPLUS_NOT_SUPPORT_OTA_CONT
#define UPLUS_NOT_SUPPORT_THIRD_CONFIG
#define MAX_PROTO_FAMILY_NUM 2
#define UPLUS_SUPPORT_EPP_INFRARED
#define UPLUS_ONLY_SUPPORT_EPP_ACCESS_SERIAL

#define DEBUG_VERSION
#define UPLUS_NO_DEBUG_PRINT
*/

#ifndef UPLUGSDK_VERSION
#error "UPLUGSDK_VERSION not defined"
#endif

#ifndef UPLUGSDK_REVISION
#error "UPLUGSDK_REVISION not defined"
#endif

#ifndef UPLUGSDK_MODULE
#error "UPLUGSDK_MODULE not defined"
#endif

#ifdef UPLUGSDK_FUNCTION_ALL
	#define UPLUS_FEATURE_MODULE_LED
	#define UPLUS_FEATURE_MODULE_DISCOVERY
	#define UPLUS_FEATURE_MODULE_CLIENT
	#define UPLUS_FEATURE_MODULE_SERVER
	#define UPLUS_FEATURE_MODULE_OTA
	#define UPLUS_FEATURE_MODULE_SECURITY
#ifdef UPLUGSDK_SUPPORT_UWT
	#define UPLUS_FEATURE_MODULE_UWT
#endif
#ifdef UPLUGSDK_SUPPORT_CAE
	#define UPLUS_FEATURE_MODULE_CAE
#endif
	#define UPLUS_FEATURE_MODULE_WIFI
	#define UPLUS_FEATURE_MODULE_SCAN
	#define UPLUS_FEATURE_MODULE_PRODUCT
	#define UPLUS_FEATURE_MODULE_SOFTAP
	#define UPLUS_FEATURE_MODULE_SMARTLINK
#ifndef UPLUS_NOT_SUPPORT_THIRD_CONFIG
	#define UPLUS_FEATURE_MODULE_THIRD_CONFIG
#endif
	#define UPLUS_FEATURE_MODULE_WIFI_CONFIG
#endif

#ifdef UPLUGSDK_FUNCTION_NO_CFG
	#define UPLUS_FEATURE_MODULE_LED
	#define UPLUS_FEATURE_MODULE_DISCOVERY
	#define UPLUS_FEATURE_MODULE_CLIENT
	#define UPLUS_FEATURE_MODULE_SERVER
	#define UPLUS_FEATURE_MODULE_OTA
	#define UPLUS_FEATURE_MODULE_SECURITY
#ifdef UPLUGSDK_SUPPORT_UWT
	#define UPLUS_FEATURE_MODULE_UWT
#endif
#ifdef UPLUGSDK_SUPPORT_CAE
	#define UPLUS_FEATURE_MODULE_CAE
#endif
	#define UPLUS_FEATURE_MODULE_WIFI
	#define UPLUS_FEATURE_MODULE_SCAN
	#define UPLUS_FEATURE_MODULE_PRODUCT
#endif

#ifdef UPLUGSDK_FUNCTION_NO_WIFI
	#define UPLUS_FEATURE_MODULE_LED
	#define UPLUS_FEATURE_MODULE_DISCOVERY
	#define UPLUS_FEATURE_MODULE_CLIENT
	#define UPLUS_FEATURE_MODULE_SERVER
	#define UPLUS_FEATURE_MODULE_OTA
	#define UPLUS_FEATURE_MODULE_SECURITY
#ifdef UPLUGSDK_SUPPORT_UWT
	#define UPLUS_FEATURE_MODULE_UWT
#endif
#ifdef UPLUGSDK_SUPPORT_CAE
	#define UPLUS_FEATURE_MODULE_CAE
#endif
#endif

#ifdef UPLUS_FEATURE_MODULE_DISCOVERY
#ifdef UPLUS_FEATURE_MODULE_UWT
#define UPLUS_UWT_DISCOVERY
#endif
#ifdef UPLUS_FEATURE_MODULE_CAE
#define UPLUS_CAE_DISCOVERY
#endif
#endif

#ifdef UPLUS_FEATURE_MODULE_CLIENT
#ifdef UPLUS_FEATURE_MODULE_UWT
#define UPLUS_UWT_CLIENT
#endif
#ifdef UPLUS_FEATURE_MODULE_CAE
#define UPLUS_CAE_CLIENT
#endif
#endif

#ifdef UPLUS_FEATURE_MODULE_SERVER
#ifdef UPLUS_FEATURE_MODULE_UWT
#define UPLUS_UWT_SERVER
#endif
#ifdef UPLUS_FEATURE_MODULE_CAE
#define UPLUS_CAE_SERVER
#endif
#endif

#ifdef UPLUS_FEATURE_MODULE_OTA
#if (defined UPLUS_UWT_CLIENT || defined UPLUS_UWT_SERVER)
#define UPLUS_UWT_OTA
#endif
#if (defined UPLUS_CAE_CLIENT || defined UPLUS_CAE_SERVER)
#define UPLUS_CAE_OTA
#endif
#endif

#ifdef UPLUS_FEATURE_MODULE_SOFTAP
#ifdef UPLUS_FEATURE_MODULE_CAE
#define UPLUS_CAE_SOFTAP
#endif
#endif

#ifdef UPLUGSDK_SUPPORT_USS
#ifdef UPLUS_FEATURE_MODULE_SECURITY
#ifdef UPLUS_FEATURE_MODULE_UWT
#define UPLUS_UWT_SECURITY
#endif
#endif
#endif

#define UPLUG_SDK_VERSION UPLUGSDK_VERSION"."UPLUGSDK_MODULE"."UPLUGSDK_REVISION

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_CONFIG_FILE_H__*/

