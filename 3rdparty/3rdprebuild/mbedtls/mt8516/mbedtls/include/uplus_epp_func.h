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

#ifndef __UPLUS_EPP_FUNC_H__
#define __UPLUS_EPP_FUNC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*uplus_epp.c*/
extern int uplug_epp_tx_rsp_to_app(epp_device_t *epp_ctl, uplus_u8 *session, uplus_u16 session_len, epp_frame_header_t *epp, uplus_u16 data_len, uplus_u8 dummy);
extern int uplug_epp_tx_rpt_to_app(epp_device_t *epp_ctl, epp_frame_header_t *epp, uplus_u16 data_len);
extern int uplug_epp_tx_req(epp_device_t *epp_ctl, uplus_u16 sub_type, uplus_u8 *data, uplus_u16 data_len, uplus_u8 *session, uplus_u16 session_len);
extern void uplug_epp_task(epp_device_t *epp_ctl);
extern int uplug_epp_register_adapter(epp_device_t *epp_ctl);
extern int uplug_epp_init(epp_device_t *epp_ctl, uplug_epp_t * uplug_epp);

/*uplus_epp_crypto.c*/
extern int	uplug_epp_dev_handle_decrypt(epp_device_t *epp_ctl, uplus_u8 *srcbuf, int srclen, uplus_u8 *dstbuf, int *len_processed, int is_ctx);
extern int uplug_epp_dev_handle_encrypt(epp_device_t *epp_ctl, uplus_u8 *srcbuf, int srclen, uplus_u8 *dstbuf, uplus_u8 encryptflg);

/*uplus_epp_dev.c*/
extern int uplug_epp_dev_tx_local_cmd(epp_device_t *epp_ctl, uplus_u8 cmd, uplus_u16 sub_type);
extern void uplug_epp_dev_ack(epp_device_t *epp_ctl, uplus_u8 cmd);
extern int uplug_epp_dev_req_from_app_do_ctrl(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
extern int uplug_epp_dev_req_from_app_do_get_alarm(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
extern int uplug_epp_dev_req_from_app_do_stop_alarm(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
extern int uplug_epp_dev_req_from_app_do_set_rpt_time(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
extern int uplug_epp_dev_req_from_app_do_set_bigdata_rpt_time(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
#ifdef UPLUS_SUPPORT_EPP_INFRARED
extern int uplug_epp_dev_req_from_app_do_split_transparent_down(epp_device_t *epp_ctl, msg_req_from_adapter_t *req);
#endif
extern int uplug_epp_dev_rpt_from_serial_do_alarm(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_status_report(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_set_into_config(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_exit_config(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_reset_config(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_enter_product_test(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
extern int uplug_epp_dev_rpt_from_serial_do_mod_ssid(epp_device_t *epp_ctl, msg_epp_rpt_t *rpt);
#ifdef UPLUS_SUPPORT_EPP_INFRARED
extern int uplug_epp_dev_do_split_transparent_up(epp_device_t *epp_ctl, uplus_u8 *epp, epp_frame_header_t **new_epp);
#endif
extern int uplug_epp_dev_rsp_from_serial_do_ctrl(epp_device_t *epp_ctl, msg_epp_rsp_t *rsp);
extern int uplug_epp_dev_ac_is_in_config_mode(epp_device_t *epp_ctl);
extern int uplug_epp_dev_rsp_from_serial_do_get_alarm(epp_device_t *epp_ctl, msg_epp_rsp_t *rsp);
extern void uplug_epp_dev_rsp_from_serial_do_rpt_wifi_status(epp_device_t *epp_ctl, msg_epp_rsp_t *rsp);
extern int uplug_epp_dev_handle_managemet_state_rsp(epp_device_t *epp_ctl, msg_epp_rsp_t *rsp);
extern void uplug_epp_dev_rsp_from_serial_do_handshake(epp_device_t *epp_ctl, msg_epp_rsp_t *rsp);
extern void uplug_epp_dev_req_to_serial_fill_ack_info(msg_epp_req_t *req, uplus_u8 *epp, uplus_u8 retry);
extern void uplug_epp_dev_set_encrypt_key(epp_device_t *epp_ctl);
extern void uplug_epp_dev_init(epp_device_t *epp_ctl);
extern void uplug_epp_dev_uart_restart(epp_device_t *epp_ctl);
extern void uplug_epp_dev_set_temp_29(epp_device_t *epp_ctl);
extern void uplug_epp_dev_set_temp_30(epp_device_t *epp_ctl);

/*uplus_epp_period.c*/
extern void uplug_epp_period(epp_device_t *epp_ctl);

/*uplus_epp_msg.c*/
extern void uplug_epp_msg_free(msg_common_header_t *msg);
extern int uplug_epp_msg_make(msg_common_header_t *msg, uplus_u8 type, uplus_u16 sub_type, int data_len);
extern int uplug_epp_msg_send_queue(msg_common_header_t *msg, uplus_u8 queue, int wait_op);
extern int uplug_epp_msg_make_send_queue(uplus_u8 type, uplus_u16 sub_type, uplus_u8 queue, int wait_op);
extern void uplug_epp_msg_rcv_once(uplus_u8 queue, int wait_op, void (*msg_handler)(msg_common_header_t *msg, void *para), void *para);
extern void uplug_epp_msg_rcv(uplus_u8 queue, int wait_op, void (*msg_handler)(msg_common_header_t *msg, void *para), void *para);

/*uplus_serial.c*/
extern int uplug_serial_tx_rpt(serial_device_t *serial_ctl, epp_frame_header_t *epp_frame);
extern void uplug_serial_task(serial_device_t *serial_ctl);
extern int uplug_serial_init(serial_device_t *serial_ctl, uplug_epp_t * uplug_epp);

/*in uplugSDK*/
extern int uplug_conf_epp_set(void *conf, uplus_u16 conf_len);
extern int uplug_conf_epp_get(void *conf, uplus_u16 conf_len);
extern int uplug_main_timer_is_timeout(uplus_time now, uplus_time timer, uplus_time timeout);
extern int uplug_util_hex_to_str(uplus_u8 *str, const uplus_u8 *hex, int length);
extern int uplug_util_str_to_hex(uplus_u8 *hex, const uplus_u8 *str, int length, int upper);
extern int uplug_util_copy_data_info(data_info_t *old_data, data_info_t *new_data);
extern void uplug_util_free_data_info(data_info_t *data);
extern int uplug_state_event_epp_device_status(int is_ok);
extern int uplug_state_event_unbind(void);

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_EPP_FUNC_H__*/

