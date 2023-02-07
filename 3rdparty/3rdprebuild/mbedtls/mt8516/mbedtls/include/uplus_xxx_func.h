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
* 2015-02-03 fanming create file
*******************************************************************************/

#ifndef __UPLUS_XXX_FUNC_H__
#define __UPLUS_XXX_FUNC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*uplus_xxx.c*/
extern void uplug_xxx_period(void);
extern int uplug_xxx_send(uplus_u8 data_type, uplus_u8 *data, uplus_u16 data_len);
extern void uplug_xxx_task(xxx_control_t *ux);

/*in uplugSDK*/
extern int uplug_main_timer_is_timeout(uplus_time now, uplus_time timer, uplus_time timeout);
extern void uplug_util_free_data_info(data_info_t *data);

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_XXX_FUNC_H__*/

