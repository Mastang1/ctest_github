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
* 2015-08-21 fanming create file
*******************************************************************************/

#ifndef __UPLUS_H__
#define __UPLUS_H__

#include <uplus_extern.h>
#include <uplus_config_file.h>

#ifdef UPLUS_FEATURE_MODULE_CAE
#ifdef UPLUS_CAE_SERVER
#include <cae_cloud_dev.h>
#endif
#ifdef UPLUS_CAE_CLIENT
#include <cae_local_server.h>
#endif
#ifdef UPLUS_CAE_DISCOVERY
#include <cae_sd_provider.h>
#endif
#ifdef UPLUS_CAE_SMARTLINK
#include <cae_dev_smartlink_cfg.h>
#endif
#ifdef UPLUS_CAE_SOFTAP
#include <cae_dev_softap_cfg.h>
#endif
#include <cae_version.h>
#include <tool/cJSON.h>
/*#define CAE11*/
#endif

#ifdef UPLUS_UWT_SECURITY
#include <uss_common.h>
#include <uss_local_o2o_common.h>
#include <uss_local_o2o_server.h>
#include <uss_cloud_common.h>
#include <uss_cloud_device.h>
#endif

#include <uplus_def.h>
#include <uplus_uwt.h>
#include <uplus_func.h>
#include <uplus_debug.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uplug_t *gv_uplug;
extern uplug_common_t *gv_uplug_common;

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_H__*/

