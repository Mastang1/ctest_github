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

#ifndef __UPLUS_FUNC_H__
#define __UPLUS_FUNC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*uplus_client.c*/
#ifdef UPLUS_UWT_CLIENT
extern int uplug_client_delete(client_control_t * client_ctl, int index);
#endif
#ifdef UPLUS_FEATURE_MODULE_CLIENT
extern int uplug_client_start(client_control_t * client_ctl);
extern int uplug_client_stop(client_control_t * client_ctl);
extern void uplug_client_period(client_control_t * client_ctl);
extern int uplug_client_init(client_control_t * client_ctl, uplug_t *uplug);
#endif

/*uplus_conf.c*/
extern void uplug_conf_clr(conf_control_t *conf_ctl);
extern void uplug_conf_save(conf_control_t *conf_ctl);
extern void uplug_conf_read(conf_control_t *conf_ctl);
extern int uplug_conf_epp_set(void *conf, uplus_u16 conf_len);
extern int uplug_conf_epp_get(void *conf, uplus_u16 conf_len);
extern int uplug_conf_ap_set(uplug_t *uplug, const uplus_u8 ssid[32], const uplus_u8 passwd[64]);
#ifdef UPLUS_UWT_SECURITY
void uplug_conf_sec_data_set(uplug_t *uplug, void *conf, uplus_u16 conf_len);
void uplug_conf_sec_data_get(uplug_t *uplug, void **conf, uplus_u16 *conf_len);
#endif

/*uplus_discovery.c*/
#ifdef UPLUS_FEATURE_MODULE_DISCOVERY
extern int uplug_discovery_start(discovery_control_t *discovery_ctl);
extern int uplug_discovery_stop(discovery_control_t *discovery_ctl);
extern void uplug_discovery_set_offline_reason(discovery_control_t *discovery_ctl, uplus_u32 reason);
extern void uplug_discovery_period(discovery_control_t *discovery_ctl);
extern int uplug_discovery_init(discovery_control_t *discovery_ctl, uplug_t *uplug);
#endif

/*uplus_main.c*/
extern void uplug_aux_task(uplug_t *uplug);
extern void uplug_main_task(uplug_t *uplug);
extern int uplug_main_timer_is_timeout(uplus_time now, uplus_time timer, uplus_time timeout);
extern void uplug_main_led_control(uplug_t *uplug, uplus_u16 mask, uplus_u16 val);

/*uplus_msg.c*/
extern void uplug_msg_free(msg_common_header_t *msg);
extern int uplug_msg_copy(msg_common_header_t *dst_msg, msg_common_header_t *src_msg);
extern int uplug_msg_make(msg_common_header_t *msg, uplus_u8 type, uplus_u16 sub_type, int data_len);
extern int uplug_msg_send(msg_common_header_t *msg, int wait_op);
extern int uplug_msg_send_queue(msg_common_header_t *msg, uplus_u8 queue, int wait_op);
extern int uplug_msg_make_send(uplus_u8 type, uplus_u16 sub_type, int wait_op);
extern int uplug_msg_copy_send(msg_common_header_t *src_msg, int wait_op);
extern void uplug_msg_rcv_once(uplus_u8 queue, int wait_op, void (*msg_handler)(msg_common_header_t *msg, void *para), void *para);
extern void uplug_msg_rcv(uplus_u8 queue, int wait_op, void (*msg_handler)(msg_common_header_t *msg, void *para), void *para);

/*uplus_ota.c*/
#ifdef UPLUS_UWT_OTA
extern int uplug_ota_start(ota_control_t *ota_ctl, connection_header_t *conn);
extern int uplug_ota_continue(ota_control_t *ota_ctl, connection_header_t *conn);
extern int uplug_ota_stop(ota_control_t *ota_ctl, connection_header_t *conn, int reason);
extern void uplug_ota_resume(ota_control_t *ota_ctl, connection_header_t *conn);
#endif
#ifdef UPLUS_CAE_OTA
extern int uplug_ota_start_cae(ota_control_t *ota_ctl, uplus_u8 from_server, void *dev_handle, uplus_u8 * data);
extern void uplug_ota_continue_cae(ota_control_t *ota_ctl, uplus_u8 from_server, void *dev_handle, uplus_u8 * data);
extern int uplug_ota_stop_cae(ota_control_t *ota_ctl, uplus_u8 from_server, void *dev_handle, int reason);
extern void uplug_ota_resume_cae(ota_control_t *ota_ctl, uplus_u8 from_server, void *dev_handle);
extern int uplug_ota_register_cae(ota_control_t *ota_ctl, uplus_u8 from_server, void *dev_handle);
#endif
#ifdef UPLUS_FEATURE_MODULE_OTA
extern void uplug_ota_period(ota_control_t *ota_ctl);
extern int uplug_ota_init(ota_control_t *ota_ctl, uplug_t *uplug);
#endif

/*uplus_packet_rx.c*/
#ifdef UPLUS_FEATURE_MODULE_PKT
extern buf_list_t * uplug_pkt_tx_malloc(uplus_u16 offset_len, uplus_u16 dst_len, uplus_u16 data_len);
extern int uplug_pkt_read(pkt_connection_t *pkt_conn, uplus_u8 *buf, uplus_u32 len);
extern int uplug_pkt_write_direct(pkt_connection_t *pkt_conn, buf_list_t *buff);
extern int uplug_pkt_write(pkt_connection_t *pkt_conn, buf_list_t *buff);
extern void uplug_pkt_rx_tx(pkt_control_t *pkt_ctl);
extern void uplug_pkt_period(pkt_control_t *pkt_ctl);
extern int uplug_pkt_set_conn(pkt_control_t *pkt_ctl, pkt_connection_t *pkt_conn);
extern int uplug_pkt_reset_conn(pkt_control_t *pkt_ctl, pkt_connection_t *pkt_conn);
extern int uplug_pkt_init(pkt_control_t *pkt_ctl, uplug_t *uplug);
#ifdef UPLUS_UWT_SECURITY
extern uss_int uplug_pkt_sec_low_read(uss_void *io, uss_byte *buf, uss_uint n, USS_IO_ERROR *error);
extern uss_int uplug_pkt_sec_low_write(uss_void *io, const uss_byte *buf, uss_uint n, USS_IO_ERROR *error);
extern uss_bool uplug_pkt_sec_get_using_nonblock(uss_void *io);
#endif
#endif

/*uplus_scan.c*/
#ifdef UPLUS_FEATURE_MODULE_SCAN
extern void uplug_scan_task(scan_control_t *scan_ctl);
extern int uplug_scan_start(scan_control_t *scan_ctl, int is_period);
extern int uplug_scan_stop(scan_control_t *scan_ctl, int break_scan);
extern void uplug_scan_finish(scan_control_t *scan_ctl, int result, int force_exit);
extern void uplug_scan_period(scan_control_t *scan_ctl);
extern int uplug_scan_init(scan_control_t *scan_ctl, uplug_t *uplug);
#endif

/*uplus_security.c*/
#ifdef UPLUS_FEATURE_MODULE_SECURITY
#ifdef UPLUS_FEATURE_MODULE_PKT
extern int uplug_sec_conn_filter(pkt_connection_t *pkt_conn, struct uplus_sockaddr *from, uplus_u32 from_len);
extern int uplug_sec_cmd_filter(connection_header_t *conn);
#endif
extern int uplug_sec_protocol_data_filter(uplus_u8 protocol);
extern int uplug_sec_init(sec_control_t *sec_ctl, uplug_t * uplug);
#endif

/*uplus_server.c*/
#ifdef UPLUS_UWT_SERVER
extern void uplug_server_task(svr_task_para_t *svr_para);
extern int uplug_server_delete(svr_control_t *svr_ctl, int index);
extern int uplug_server_start_task(svr_control_t *svr_ctl, uplus_u32 index);
extern int uplug_server_stop_task(svr_control_t *svr_ctl, uplus_u32 index);
extern void uplug_server_connect_finish(svr_control_t *svr_ctl, int result, msg_server_connect_result_t * para, int force_exit);
extern void uplug_server_set_disconnect_reason(svr_control_t *svr_ctl, uplus_u32 reason);
#endif
#ifdef UPLUS_CAE_SERVER
extern void uplug_server_set_disconnect_reason_cae(svr_control_t *svr_ctl, uplus_u32 reason);
#endif

#ifdef UPLUS_FEATURE_MODULE_SERVER
extern void uplug_server_modify(svr_control_t *svr_ctl, msg_modify_server_t * para);
extern int uplug_server_start(svr_control_t *svr_ctl);
extern int uplug_server_stop(svr_control_t *svr_ctl);
extern void uplug_server_period(svr_control_t *svr_ctl);
extern void uplug_server_info_log(svr_control_t * svr_ctl);
extern int uplug_server_init(svr_control_t * svr_ctl, uplug_t *uplug);
#endif

/*uplus_state_transit.c*/
extern int uplug_state_protocol_ctrl(protocol_control_info_t * protocol_ctl_info, int ctrl_type, void * val);
extern int uplug_state_exit(state_control_t *st_ctl);
extern void uplug_state_do_event(state_control_t *st_ctl, uplus_u8 event, void *data);
extern void uplug_state_period(state_control_t *st_ctl);
extern void uplug_state_set_wait_flag(state_control_t *st_ctl, uplus_u8 wait_event_bit);
extern int uplug_state_is_set_wait_flag(state_control_t *st_ctl, uplus_u8 wait_event_bit);
extern int uplug_state_is_work_state(uplus_u8 state);
extern uplus_u8 uplug_state_current_state_get(state_control_t *st_ctl);
extern int uplug_state_init(state_control_t *st_ctl, uplug_t * uplug);
extern int uplug_state_event_epp_device_status(int is_ok);
extern int uplug_state_event_unbind(void);
#ifdef UPLUS_FEATURE_MODULE_SERVER
extern int uplug_state_modify_server_msg_send(uplus_u8 svr_type, char *svr_domain, uplus_u16 svr_port);
#endif

/*uplus_uwt.c*/
#if (defined UPLUS_UWT_CLIENT || defined UPLUS_UWT_SERVER)
extern int uplug_uwt_cmd_analysis(uplus_u32 cmd, uplus_u8 *uwt_head_type, uplus_u16 *len /*head len or body len*/);
extern void uplug_uwt_cmd_head_analysis(pkt_rx_data_t *p_rx_data, uplus_u8 is_stream);
extern void uplug_uwt_rx(connection_header_t *conn);
extern void uplug_uwt_new_conn(connection_header_t *conn);
#endif
#ifdef UPLUS_FEATURE_MODULE_UWT
extern int uplug_uwt_handle(msg_common_header_t *msg, uplug_t * uplug);
#endif
#ifdef UPLUS_UWT_SERVER
extern int uplug_uwt_cmd_ver_rpt_to_master(svr_control_t *svr_ctl, connection_svr_t *svr_conn);
extern int uplug_uwt_cmd_ver_rpt_to_svr(svr_control_t *svr_ctl, connection_svr_t *svr_conn);
extern int uplug_uwt_cmd_uart_err_to_svr(svr_control_t *svr_ctl, connection_svr_t *svr_conn);
extern int uplug_uwt_cmd_unbind_to_svr(svr_control_t *svr_ctl, connection_svr_t *svr_conn);
extern int uplug_uwt_cmd_alive_to_svr(svr_control_t *svr_ctl, connection_svr_t *svr_conn);
#ifdef UPLUS_FEATURE_MODULE_SCAN
extern int uplug_uwt_cmd_wifi_info_rpt_to_svr(scan_control_t *scan_ctl, connection_svr_t *svr_conn);
#endif
#endif

/*uplus_wifi.c*/
extern void uplug_wifi_task(wifi_control_t * wifi_ctl);
extern int uplug_wifi_start(wifi_control_t * wifi_ctl);
extern int uplug_wifi_stop(wifi_control_t * wifi_ctl);
extern int uplug_wifi_shutdown(wifi_control_t * wifi_ctl);
extern void uplug_wifi_finish(wifi_control_t * wifi_ctl, int result, int force_exit);
extern void uplug_wifi_period(wifi_control_t * wifi_ctl);
extern void uplug_wifi_info_log(wifi_control_t * wifi_ctl);
extern int uplug_wifi_init(wifi_control_t * wifi_ctl, uplug_t * uplug);

/*uplus_util.c*/
extern int uplug_util_to_lower(uplus_u8 *dst, const uplus_u8 *src, int length);
extern int uplug_util_to_upper(uplus_u8 *dst, const uplus_u8 *src, int length);
extern int uplug_util_hex_to_str(uplus_u8 *str, const uplus_u8 *hex, int length);
extern int uplug_util_str_to_hex(uplus_u8 *hex, const uplus_u8 *str, int length, int upper);
extern int uplug_util_md5_string(uplus_u8 *buf, int len, uplus_u8 *output);
extern int uplug_util_copy_data_info(data_info_t *old_data, data_info_t *new_data);
extern void uplug_util_free_data_info(data_info_t *data);
extern void uplug_util_add_epp_escape(uplus_u8 *src_buf, uplus_u16 src_len, uplus_u8 *dst_buf, uplus_u16 *dst_len);
extern void uplug_util_del_epp_escape(uplus_u8 *src_buf, uplus_u16 src_len, uplus_u8 *dst_buf, uplus_u16 *dst_len);
extern int uplug_util_net_udp_socket_create(uplus_u16 udp_port);
extern int uplug_util_net_tcp_server_connect(char *ip_addr, uplus_u16 tcp_port);

/*uplus_protocol_adapter.c*/
extern void uplug_adapter_task(void *para);
extern int uplug_adapter_init(uplug_t * uplug);
extern void uplug_adpater_ctrl(uplug_t *uplug, int ctrl_type, void *val);
extern int uplug_protocol_notify_third_party(uplug_t *uplug, uplus_u16 sub_type);

/*uplus_config.c*/
int uplug_config_ap_info_notify(uplus_u16 sub_type, const uplus_u8 ssid[32], const uplus_u8 passwd[64]);
#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
extern int uplug_config_smartlink_start(smartlink_control_t *smlk_ctl, uplus_u8 method);
extern int uplug_config_smartlink_stop(smartlink_control_t *smlk_ctl);
extern void uplug_config_smartlink_period(smartlink_control_t *smlk_ctl);
extern int uplug_config_smartlink_init(smartlink_control_t *smlk_ctl, uplug_t *uplug);
#endif
#ifdef UPLUS_CAE_SOFTAP
extern int uplug_config_softap_start_cae(uplug_t *uplug);
extern int uplug_config_softap_stop_cae(uplug_t *uplug);
#endif

/*uplus_cae.c*/
#ifdef UPLUS_FEATURE_MODULE_CAE
extern int uplug_cae_handle(msg_common_header_t *msg, uplug_t * uplug);
extern int uplug_cae_ext_op_handler(uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server,
	const cae_int8_t * data_type, const cae_uint8_t * data, const cae_int32_t data_length);
extern int uplug_cae_attr_read_handler(	uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server, const cae_int8_t * name);
extern int uplug_cae_attr_write_handler(uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server, 
	const cae_int8_t * name, const cae_int8_t * value);
extern int uplug_cae_attr_op_handler(uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server, 
	const cae_int8_t * op, const cae_strpair_list_t * op_param);
extern int uplug_cae_down_data_handler(uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server, 
	const cae_int8_t * data_type, const cae_uint8_t* data, const cae_int32_t data_length);
extern int uplug_cae_down_service_handler(uplug_t * uplug, cae_request_handle_t request, uplus_u8 from_server, 
	const cae_int8_t * data_type, const cae_uint8_t* data, const cae_int32_t data_length);
#endif
#ifdef UPLUS_CAE_SERVER
extern int uplug_cae_uart_err_to_svr(svr_control_t *svr_ctl);
extern int uplug_cae_offline_reason_to_svr(svr_control_t *svr_ctl);
extern int uplug_cae_net_quality_to_svr(svr_control_t *svr_ctl);
extern int uplug_cae_epp_big_data_to_svr(svr_control_t *svr_ctl, uplus_u8 *data, uplus_u16 data_len);
#ifdef UPLUS_FEATURE_MODULE_SCAN
extern int uplug_cae_wifi_info_rpt_to_svr(scan_control_t *scan_ctl);
#endif
extern void uplug_cae_new_conn(uplug_t *uplug);
#endif

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_FUNC_H__*/

