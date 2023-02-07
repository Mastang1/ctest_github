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

#ifndef __UPLUS_DEF_H__
#define __UPLUS_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif

#if (defined UPLUS_UWT_CLIENT || defined UPLUS_UWT_DISCOVERY || defined UPLUS_UWT_SERVER)
#define UPLUS_FEATURE_MODULE_PKT
#endif

/*service*/
#define MAX_ADAPTER_NUM 1
#ifndef MAX_PROTO_FAMILY_NUM
/*protocol family*/
#define MAX_PROTO_FAMILY_NUM 1 /*U+ and third party protocol*/
#endif

#define uplug_syslog(uplug, fmt, ...) \
	uplus_sys_log("%u: %s:"fmt"\n", uplus_os_current_time_get(), uplug->state.state_str_tbl[uplug->state.current_state], ##__VA_ARGS__);
#define uplug_syslog_info(fmt, ...) \
	uplus_sys_log("%u:"fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);

/*macro def*/
#define SDK_TYPE "e"

#define UDP_SEND_PORT					7083
#define UDP_RECV_PORT					7083
#define TCP_WORK_LISTEN_PORT			56800
#define TCP_SOFTAP_CONFIG_LISTEN_PORT	56797
#define UDP_SMARTCONFIG_LISTEN_PORT		7084

#define CAE_SW_TYPE "MqttWifi"
#define UDP_CAE_PORT 5683
#define CAE_DATE_TYPE_RAW "raw"
#define CAE_DATE_TYPE_EPP "epp"
#define CAE_DATE_TYPE_EPP_INFRARED "eInfrared"

#if 0
#define MASTER_SVR_DOMAIN		"103.8.220.166"
#define SLAVE_SVR_DOMAIN		"103.8.220.166"
#define SLAVE_SVR_PORT	        		56611
#else
#define MASTER_SVR_DOMAIN		"gw.haier.net"
#endif 
#define MASTER_SVR_PORT	        		56808

#define MASTER_SVR_DOMAIN_CAE "103.8.220.166"
#define MASTER_SVR_PORT_CAE 56810

#define MAX_SERVER_NUM 2 /*1 master server + 1 server*/
#define MAX_CLIENT_LISTEN_NUM 1
#define MAX_CLIENT_NUM 16
#define MAX_DISCOVERY_NUM 1

/*resource def*/
/*queue size*/
#define QUEUE_SIZE_UWT_CAE 20
#define QUEUE_SIZE_UPLUS_MAIN 20
#define QUEUE_SIZE_UPLUS_LOW 5
#define QUEUE_SIZE_UPLUS_AUX 5
#define QUEUE_SIZE_ADAPTER 30
#define QUEUE_SIZE_PROTOCOL 20

/*task name*/
#define TASK_NAME_UPLUS "t_uplus"
#define TASK_NAME_AUX "t_aux"
#define TASK_NAME_ADAPTER "t_ada"

/*task stack*/
#ifdef UPLUS_UWT_SECURITY
#define TASK_STACK_SIZE_UPLUS 1536
#else
#define TASK_STACK_SIZE_UPLUS 1024
#endif
#define TASK_STACK_SIZE_AUX 1024
#define TASK_STACK_SIZE_ADAPTER 1024

/*task priority*/
#define TASK_PRIORITY_UPLUS 3
#define TASK_PRIORITY_AUX 4
#define TASK_PRIORITY_ADAPTER 4

/*time def*/
#define TIME_MILLISECOND (1)
#define TIME_SECOND (1000 * (TIME_MILLISECOND))
#define TIME_MINUTE (60 * (TIME_SECOND))
#define TIME_HOUR (60 * (TIME_MINUTE))
#define TIME_DAY (24 * (TIME_HOUR))

#define TIME_WATCHDOG_RESET (1 * (TIME_MINUTE))

#ifdef UPLUS_UWT_CLIENT
#define TIME_CLIENT_TIMEOUT (63 * (TIME_SECOND))
#define TIME_CLIENT_SOCK_RXTX (1 * (TIME_SECOND))
#endif

#ifdef UPLUS_FEATURE_MODULE_SERVER
#define TIME_SVR_WIFI_INFO_RPT_0 (10 * (TIME_MINUTE))
#define TIME_SVR_WIFI_INFO_RPT_1 (12 * (TIME_HOUR))
#endif

#ifdef UPLUS_UWT_SERVER
#define TIME_SVR_KEEP_ALIVE (60 * (TIME_SECOND))
#define TIME_SVR_VER_RPT (10 * (TIME_SECOND))
#define TIME_SVR_TIMEOUT (3 * (TIME_MINUTE))
#define TIME_SVR_MASTER_RECONNECT (30 * (TIME_SECOND))
#define TIME_SVR_MASTER_TIMEOUT (10 * (TIME_SECOND))
#define TIME_SVR_RECONNECT (20 * (TIME_SECOND))
#define TIMES_SVR_RECONNECT (3 - 1) /*if connect failed, then retry 2 times*/
#define TIME_SVR_SOCK_RXTX (5 * (TIME_SECOND))

#ifdef UPLUS_UWT_SECURITY
#define TIME_SVR_SEC_HANDSHAKE (10 * (TIME_SECOND))
#endif
#endif

#ifdef UPLUS_CAE_SERVER
#define TIME_SVR_NET_QUALITY_INFO_RPT (10 * (TIME_MINUTE))
#define TIMES_SVR_MASTER_RECONNECT_CAE 1
#define TIMES_SVR_RECONNECT_CAE 3
#endif

#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
#define TIME_CONFIG_SMARTLINK_LONG (30 * (TIME_MINUTE))
#define TIME_CONFIG_SMARTLINK_SHORT (10 * (TIME_MINUTE))
#define TIME_CONFIG_SMARTLINK_TO_SOFTAP (1 * (TIME_MINUTE))
#define TIME_SWITCH_CHANNEL (110 * (TIME_MILLISECOND))
#endif

#ifdef UPLUS_FEATURE_MODULE_SCAN
#define TIME_SCAN_INTERVAL (10 * (TIME_SECOND))
#endif

#ifdef UPLUS_FEATURE_MODULE_OTA
#define TIME_OTA_SEQ_REQ_INTERVAL_FAST (30 * (TIME_SECOND))
#define TIME_OTA_SEQ_REQ_INTERVAL_SLOW (5 * (TIME_MINUTE))
#define TIME_OTA_SPLIT (3 * (TIME_MINUTE))
#define TIME_OTA_DELAY_RESET (1 * (TIME_SECOND))
#endif

#ifdef UPLUS_FEATURE_MODULE_SOFTAP
#define TIME_CONFIG_WIFI_LONG (30 * (TIME_MINUTE))
#define TIME_CONFIG_WIFI_SHORT (10 * (TIME_MINUTE))
#define TIME_SOFTAP_WAIT (1 * (TIME_SECOND))
#endif

#define TIME_SAVED_CMD (10 * (TIME_SECOND))

#define TIME_SOCK_TX (10 * (TIME_SECOND)) /*报文在发送队列中最大缓存时间*/
#define TIME_SOCK_TX_SERVER (30 * (TIME_SECOND)) /*报文在发送队列中最大缓存时间*/
#define TIME_TX_DELAY (500 * (TIME_MILLISECOND)) /*延迟发送时间*/

#ifdef UPLUS_FEATURE_MODULE_WIFI
#define TIMES_WIFI_CONNECT_FAIL (2)
#endif

#define TIME_RSSI_CHECK (10 * (TIME_SECOND))
#define TIME_WIFI_CONNECT_0 (60 * (TIME_SECOND)) /*从smartlink配置模式转入工作模式,WIFI连接超时时间*/
#define TIME_WIFI_CONNECT_1 (60 * (TIME_MINUTE)) /*产测模式WIFI连接超时时间*/
#if 0
#define TIME_WIFI_DOWN (30 * (TIME_SECOND))
#endif

#define TIME_CONN_INTERVAL_0 (3 * (TIME_SECOND)) /*快速重连间隔时间*/
#define TIME_CONN_INTERVAL_1 (60 * (TIME_SECOND)) /*慢速重连间隔时间*/
#define TIME_CONN_CHG_INTERVAL (1 * (TIME_MINUTE)) /*时间之内快速重连，时间之外慢速重连*/

#ifdef UPLUS_UWT_DISCOVERY
#define TIME_ONLINE_RPT (200 * (TIME_MILLISECOND))
#define TIMES_ONLINE_RPT 15
#endif

#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
#define TIME_SMARTLINK_ACK (150 * (TIME_MILLISECOND))
#define TIMES_SMARTLINK_ACK 20
#endif

#define TIME_LED_POWER_SAVE_LONG (1 * (TIME_HOUR))   /*空调默认上电后led灯打开1hour*/
#define TIME_LED_POWER_SAVE_SHORT (5 * (TIME_MINUTE))

#if (MAX_PROTO_FAMILY_NUM > 1)
#define TIME_CHECK_SHARE (30 * (TIME_SECOND))
#endif

#define TIME_SYS (10 * (TIME_SECOND))

#ifdef UPLUS_CAE_DISCOVERY
#define TIME_SD_REG_SVC (2)
#endif

#ifdef UPLUS_CAE_CLIENT
#define TIME_LOCAL_RPT_TIMEOUT (1)
#endif

/*message queue*/
enum msg_queue
{
	QUEUE_UPLUS_MAIN = 0,
	QUEUE_UWT_CAE,
	QUEUE_UPLUS_LOW, /*comm with other protocols*/
	QUEUE_UPLUS_AUX,
	QUEUE_ADAPTER,
	MAX_UPLUS_QUEUE_NUM,
	MAX_QUEUE_NUM = MAX_UPLUS_QUEUE_NUM + MAX_PROTO_FAMILY_NUM /*a queue assigned for each protocol family*/
};

/*message type*/
enum msg_type
{
	MSG_CTL = 0,

	/*for adapter*/
	/*for epp/others comm with uwt/others*/
	MSG_REQ_FROM_APP, /*from protocol to adapter*/ /*protocol_data_info_t*/
	MSG_RSP_TO_APP, /*from adapter to protocol*/ /*service_data_info_t*/
	MSG_RPT_TO_APP, /*from adapter to protocol*/ /*service_data_info_t*/
	MSG_FROM_SERVICE_TO_ADAPTER, /*from service to adapter*/ /*service_data_info_t*/

#ifdef UPLUS_FEATURE_MODULE_UWT
	/*for uwt*/
	MSG_UWT_RSP,
#endif

#ifdef UPLUS_FEATURE_MODULE_CAE
	/*for cae*/
	MSG_CAE,
#endif

	/*comm with third party protocol*/
	MSG_FROM_THIRD_PARTY_COMM, /*from other protocols to U+*/
	MSG_TO_THIRD_PARTY_COMM, /*from U+ to other protocols*/

	MAX_MSG_TYPE_NUM
};

/*event def*/
enum event_type
{
	EVENT_INIT = 0,/*0 based*/

	/*配置模式相关事件*/
	EVENT_SMARTLINK_OK,
	EVENT_ENTER_SMARTLINK_CONFIG,
	EVENT_SOFTAP_CONFIG_OK,
	EVENT_ENTER_SOFTAP_CONFIG,
	EVENT_CONFIG_TIMEOUT,
	EVENT_QUIT_CONFIG,
	EVENT_ENTER_THIRD_CONFIG,
	EVENT_EXIT_THIRD_CONFIG,

	EVENT_CLR_USER_CONFIG,
	EVENT_ENTER_PRODUCT,

	/*WIFI、AP相关事件*/
	EVENT_DISCONNET_AP,
	EVENT_MODI_AP_INFO,
	EVENT_AP_CONNECTED,
	EVENT_AP_CONNECT_ERR,
	EVENT_WIFI_DOWN,

	/*服务器相关事件*/
	EVENT_MODI_SERVER_DOMAIN,
	EVENT_SERVER_CONNECTED,
	EVENT_SERVER_CONNECT_FAIL,

	/*SCAN相关事件*/
	EVENT_SCAN_FINISH,
	EVENT_SCAN_BREAK,

	/*EPP协议相关事件*/
	EVENT_EPP_DEVICE_OK,
	EVENT_EPP_DEVICE_FAIL,

	MAX_EVENT_TYPE
};

enum msg_sub_type
{
	/*control cmd def*/
	MSG_SUB_CTL_MODULE_RESET = 0, /*for CTL_UPLUS_BASE*/
	MSG_SUB_CTL_MODULE_RESET_OTA, /*for CTL_UPLUS_BASE*/
	MSG_SUB_CTL_UNBIND, /*for CTL_UPLUS_BASE*/
	MAX_CTL_NUM,

	MSG_SUB_CTL_WIFI_CONNECT = 0, /*for CTL_AUX_BASE*/
	MSG_SUB_CTL_SERVER_CONNECT, /*for CTL_AUX_BASE*/
	MSG_SUB_CTL_SCAN, /*for CTL_AUX_BASE*/

#ifdef UPLUS_FEATURE_MODULE_CAE
	MSG_SUB_CAE_OTA_START = 0, /*for MSG_CAE*/
	MSG_SUB_CAE_OTA_CONTENT, /*for MSG_CAE*/
#endif

	CTL_CMD_TYPE_MASK = 0xFF,
	CTL_UPLUS_BASE = 0,
	CTL_EVENT_CMD_BASE = 0x100, /*event cmd = CTL_EVENT_CMD_BASE + EVENT_XXX*/
	CTL_AUX_BASE = 0x400,

	MAX_CTL_CMD_NUM = MAX_CTL_NUM + MAX_EVENT_TYPE
};

/*message common header*/
typedef struct msg_common_header
{
	uplus_u8 type; /*MSG_XXX*/
	uplus_u8 data_is_alloc; /*data is dynamic alloc*/
	uplus_u16 sub_type;
	void * data;
} msg_common_header_t;

#define UPLUS_CAE_SESSION 0x80000000
#define UPLUS_MAKE_SESSION(conn_type, index) (((conn_type) << 8) | (index))
#define UPLUS_GET_CONN_TYPE_FROM_SESSION(conn_type, session) (conn_type) = ((session) >> 8) & 0xFF
#define UPLUS_GET_INDEX_FROM_SESSION(index, session) (index) = (session) & 0xFF

#ifdef UPLUS_FEATURE_MODULE_UWT
/*uwt response message*/
typedef struct msg_uwt_rsp
{
	req_session_t session; /*dst of rsp*/
	uplus_u16 data_len; /*len of data*/
	uplus_u8 backup[2];
	uplus_u8 * data; /*uwt msg*/
} msg_uwt_rsp_t;
#endif

#ifdef UPLUS_FEATURE_MODULE_CAE
/*ota start info from CAE*/
typedef struct cae_ota_start
{
    cae_int8_t * upgrade_sn;
    cae_int32_t check_type;
    cae_int8_t * check_value;
    cae_int32_t total_len;
	cae_int8_t * url;
    cae_int32_t flag_force;
} cae_ota_start_t;

/*ota content info from CAE, for MSG_SUB_CAE_*/
typedef struct cae_ota_content
{
    cae_int8_t * upgrade_sn;
    cae_int32_t err_no;
    cae_int32_t offset;
	cae_int32_t len;
	cae_int32_t sum; 
	cae_uint8_t * data;
} cae_ota_content_t;

typedef struct msg_cae
{
	uplus_u8 from_server;
	uplus_u16 data_len; /*len of data*/
	void *dev_handle;
	uplus_u8 * data; /*cae_ota_start_t or cae_ota_content_t*/
} msg_cae_t;
#endif

/*need to be extented*/
typedef struct msg_uplus_third_protocol
{
	uplus_u8 * data; /*aj comm data*/
	uplus_u16 data_len; /**aj comm data len*/
	uplus_u8 protocol; /*PROTO_FAMILY_XXX, current not used*/
	uplus_u8 backup; 
} msg_uplus_third_protocol_t;

typedef void (*msg_handler_func)(msg_common_header_t *msg, void *para);

/*for EVENT_MODI_SERVER_DOMAIN*/
typedef struct msg_modify_server
{
	char svr_domain[64];
	uplus_u16 svr_port;
	uplus_u8 svr_type; /*SERVER_TYPE_XXX*/
} msg_modify_server_t;

/*for EVENT_SERVER_CONNECTED/EVENT_SERVER_CONNECT_FAIL*/
typedef struct msg_server_connect_result
{
	uplus_u32 index;
	uplus_id ssl_id;
	int fd;
} msg_server_connect_result_t;

/*for EVENT_MODI_AP_INFO*/
typedef struct msg_modify_ap
{
	uplus_u8 ssid[32];
	uplus_u8 key[64];
} msg_modify_ap_t;

/*for EVENT_ENTER_SMARTLINK_CONFIG*/
typedef struct msg_smartlink_cfg
{
	uplus_u8 method;
	uplus_u8 smartlink_to_softap;
} msg_smartlink_cfg_t;

/*state def*/
enum state_type
{
	STATE_INIT = 0,
#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
	STATE_SMARTLINK,
#endif
#ifdef UPLUS_FEATURE_MODULE_SOFTAP
	STATE_SOFTAP,
#endif
	STATE_WORK,
#ifdef UPLUS_FEATURE_MODULE_PRODUCT
	STATE_PRODUCT,
#endif
#ifdef UPLUS_FEATURE_MODULE_THIRD_CONFIG
	STATE_CONFIG,
#endif
	STATE_NO_WIFI,
	MAX_STATE_TYPE,
	STATE_KEEP = 0xFF
};

/*wait event bit*/
enum wait_event_bit_type
{
	WAIT_EVENT_BIT_AP_RESULT = 0,
	WAIT_EVENT_BIT_SCAN_RESULT,
	WAIT_EVENT_BIT_SERVER_RESULT = WAIT_EVENT_BIT_SCAN_RESULT/*相邻的前一个定义*/ + MAX_SERVER_NUM,
	MAX_WAIT_EVENT_BIT_TYPE,
	WAIT_EVENT_BIT_NONE = 0xFF
};

#define SET_WAIT_FLAG(wait_flag, wait_event_bit) (wait_flag[(wait_event_bit)/32] |= (1 << ((wait_event_bit) & 31)))
#define CLR_WAIT_FLAG(wait_flag, wait_event_bit) (wait_flag[(wait_event_bit)/32] &= ~(1 << ((wait_event_bit) & 31)))
#define IS_WAIT_FLAG_SET(wait_flag, wait_event_bit) (wait_flag[(wait_event_bit)/32] & (1 << ((wait_event_bit) & 31)))
#define IS_WAIT_FLAG_CLR(wait_flag) (wait_flag[0] == 0)

typedef uplus_u8 (*event_action_func)(void *, void *);
/**state transit control block*/
typedef struct state_control
{
	uplus_u8 current_state; /*current state STATE_XXX*/
	uplus_u8 new_state; /*new state STATE_XXX*/
	uplus_u8 last_state; /*last state STATE_XXX*/
	uplus_u8 state_chg_flag; /*indicate state is changed, 1/0*/
	uplus_u32 wait_flag[((MAX_WAIT_EVENT_BIT_TYPE) + 31)/32]; /*1-set, 0-clear*/
	uplus_u32 wait_exit_flag[((MAX_WAIT_EVENT_BIT_TYPE) + 31)/32]; /*1-set, 0-clear*/
	event_action_func event_action_tbl[MAX_EVENT_TYPE];
	char *event_str_tbl[MAX_EVENT_TYPE];
	char *state_str_tbl[MAX_STATE_TYPE];

	uplus_time enter_time; /*time entering current state*/

	struct uplug *uplug;
}state_control_t;

#ifdef UPLUS_FEATURE_MODULE_SCAN

#define MAX_SCAN_AP_NUM 20

typedef struct scan_control
{
	uplus_u8 exit_flag; 
	uplus_time time_scan; /*scan interval, TIME_SCAN_INTERVAL*/

	/*ap list*/
	uplus_u8 ap_num;
    ap_list_api_t *ap_list;

	struct uplug *uplug;
} scan_control_t;
#endif

#define SOFT_AP_CHANNEL 3

/*wifi control block*/
typedef struct wifi_control
{
	/*common info*/
	uplus_u8 dev_mac[6];
	char mac[16]; /*wifi mac, 字符串形式, 全大写*/
	uplus_u8 wifi_rssi; /*wifi received signal strength indication*/
	uplus_u8 exit_flag; 

#ifdef UPLUS_FEATURE_MODULE_WIFI
	uplus_u8 wifi_cfg_chg;
	uplus_u8 times_wifi_connect_fail;
	uplus_u8 wifi_mode; /*WIFI_MODE_XXX*/
	uplus_u8 dhcp_mode; /*DHCP_MODE_XXX*/
	uplus_u16 channel; /*last channel*/
	char wifi_ssid[32 + 1];
	char wifi_key[64 + 1];
	uplus_u32 encryption; /*WIFI_ENCRYPT_XXX*/
#endif

	/*network info*/
	char hostname[32 + 1];
	char ip_addr[16]; /*ip addr*/
	char ip_mask[16]; /*ip mask*/
	char ip_gw[16]; /*ip gw*/
	char ip_dns[16]; /*ip dns server*/
	char ip_broadcast_addr[16]; /*ip broadcast addr*/

#ifdef UPLUS_FEATURE_MODULE_WIFI
	/*ap connection error code*/
    uplus_u32 conn_ap_err;
#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
	uplus_u32 last_smartlink_ap_err;
#endif
#endif

	/*timer*/
	uplus_time time_wifi_connect; /*wifi连接超时定时器, TIME_WIFI_CONNECT_XXX*/
	uplus_time time_wifi_down; /*wifi掉线重启定时器, TIME_WIFI_DOWN*/
	uplus_time time_rssi_check; /*获取WIFI信号强度定时器, TIME_RSSI_CHECK*/

	struct uplug *uplug;
} wifi_control_t;

#ifdef UPLUS_FEATURE_MODULE_PKT

#define PKT_STATE_NEW 0
#define PKT_STATE_HEAD 1
#define PKT_STATE_BODY 2
#define PKT_STATE_PARTIAL 0x80

#define UWT_HEAD_TYPE_NONE 0
#define UWT_HEAD_TYPE_CAE 1
#define UWT_HEAD_TYPE_TCP 2
#define UWT_HEAD_TYPE_TCP_SUB_CMD 3

struct pkt_rx_data;
typedef void (*pkt_rx_data_free)(struct pkt_rx_data *p_rx_data);

/*packet rx data context*/
typedef struct pkt_rx_data
{
	uplus_u8 state; /*state of receive uwt data, PKT_STATE_XXX*/

	pkt_rx_data_free free; /*NULL, static buf, general for udp rx, listen*/

	uplus_u8 *head; /*uwt head*/
	uplus_u8 *body; /*uwt body*/
	uplus_u8 *buf; /*point to cmd, head, or body, used for reading from sock*/
	uplus_u16 rcv_len; /*rcv len*/
	uplus_u16 len; /*final, len of body*/
	uplus_u8 uwt_head_type; /*UWT_HEAD_TYPE_XXX*/

	uplus_u32 cmd; /*uwt cmd*/
	uplus_u32 sub_cmd; /*uwt sub cmd*/
} pkt_rx_data_t;

#define MAX_TX_PKT_BUF_SIZE 2048

/*packet buf list*/
typedef struct buf_list
{
	struct buf_list *next;

	uplus_u16 sent; /*bytes has been sent*/
	uplus_u16 offset_len; /*sizeof offset*/
	uplus_u16 dst_len; /*sizeof dst*/
	uplus_u16 data_len; /*sizeof data*/
	/*buf, dst + offset + data*/
} buf_list_t;

/*packet tx data context*/
typedef struct pkt_tx_data
{
	buf_list_t *head;
	buf_list_t *tail;
	uplus_u16 total_len;
	uplus_time time_last_tx; /*TIME_SOCK_TX/TIME_SOCK_TX_SERVER*/
} pkt_tx_data_t;

#define RX_MODE_TCP_BASE 0
#define RX_MODE_UWT_SPLIT (RX_MODE_TCP_BASE + 0) /*special for uwt tcp rx, each packet_tx_data for a conn*/
#ifdef UPLUS_UWT_SECURITY
#define RX_MODE_UWT_FRAME (RX_MODE_TCP_BASE + 1) /*special for uwt tcp rx, share one packet_tx_data*/
#endif

#define RX_MODE_UDP_BASE 0x10
#define RX_MODE_UWT_WHOLE (RX_MODE_UDP_BASE + 0) /*general for uwt udp rx, share one packet_tx_data*/
#define RX_MODE_WHOLE (RX_MODE_UDP_BASE + 1) /*not use packet rx, share one packet_tx_data*/

#define RX_MODE_OTHER_BASE 0x20
#define RX_MODE_SELF (RX_MODE_OTHER_BASE + 0) /*not use packet rx, use self rx*/

/*connection def*/
#define MAX_PKT_CONN_NUM (MAX_SERVER_NUM + MAX_CLIENT_NUM + MAX_CLIENT_LISTEN_NUM + MAX_DISCOVERY_NUM)
#define MAKE_DISCOVERY_RX_CONN_INDEX(ind) (MAX_SERVER_NUM + MAX_CLIENT_LISTEN_NUM + ind)
#define MAKE_CLIENT_RX_CONN_INDEX(ind) (MAX_SERVER_NUM + MAX_CLIENT_LISTEN_NUM + MAX_DISCOVERY_NUM + ind)
#define MAKE_SERVER_RX_CONN_INDEX(ind) (ind)
#define MAKE_LISTEN_RX_CONN_INDEX(ind) (MAX_SERVER_NUM + ind)
#define GET_DISCOVERY_INDEX_BY_RX_CONN(ind) (ind - (MAX_SERVER_NUM + MAX_CLIENT_LISTEN_NUM))
#define GET_CLIENT_INDEX_BY_RX_CONN(ind) (ind - (MAX_SERVER_NUM + MAX_CLIENT_LISTEN_NUM + MAX_DISCOVERY_NUM))
#define GET_SERVER_INDEX_BY_RX_CONN(ind) (ind)
#define GET_LISTEN_INDEX_BY_RX_CONN(ind) (ind - (MAX_SERVER_NUM))
#define PKT_CONN_IS_SERVER_CONN(ind) ((ind) < MAX_SERVER_NUM)

#define RX_CONN_TYPE_1_to_1 0 /*1 app conn map to 1 rx conn*/
#define RX_CONN_TYPE_1_to_n 1 /*n app conns map to 1 rx conn*/

#define PKT_ERROR_RX 0
#define PKT_ERROR_TX 1
#define PKT_ERROR_TX_TIMEOUT 2

#ifdef UPLUS_UWT_SECURITY
#define PKT_SEC_MODE_NONE 0 /*must be zero*/
#define PKT_SEC_MODE_CLIENT 1
#define PKT_SEC_MODE_SERVER 2

#define SEC_HANDSHAKE_NG 0
#define SEC_HANDSHAKE_OK 1
#define SEC_HANDSHAKE_NG_TO_OK 2
#define SEC_HANDSHAKE_OK_TO_NG 3
#endif

/*for packet rx/tx, select*/
typedef struct pkt_connection
{
	uplus_u8 index; /*MAX_PKT_CONN_NUM-1*/
	uplus_u8 conn_type; /*RX_CONN_TYPE_XXX*/
	uplus_u8 ssl_mode; /*1-ssl mode, 0-normal*/
	uplus_u8 rx_mode; /*RX_MODE_XXX*/
	uplus_u8 rx_enable; /*rx_enable*/
	uplus_u8 tx_enable; /*tx_enable*/
#ifdef UPLUS_UWT_SECURITY
	uplus_u8 sec_mode; /*PKT_SEC_MODE_XXX*/
	uplus_u8 sec_handshake; /*security handshake flag, SEC_HANDSHAKE_XXX*/
	void *uss_ctx;
#endif
	int fd;
	uplus_id ssl_id;/*ssl info*/
	uplus_time tx_delay_start; /*发送重传定时器，TIME_TX_DELAY*/

	void (*rx_handler)(struct pkt_connection *pkt_conn); /*rx handler*/
	void (*error)(struct pkt_connection *pkt_conn, int error); /*PKT_ERROR_XXX*/
	int (*lower_rx)(struct pkt_connection *pkt_conn);/*1-whole packet, 0-partial packet, -1-error*/
	pkt_rx_data_t *p_rx_data;
	pkt_tx_data_t tx_data;
	void *from;
	struct uplug *uplug;
} pkt_connection_t;

#define CONN_TYPE_SERVER 0
#define CONN_TYPE_CLIENT 1
#define CONN_TYPE_LISTEN 2
#define CONN_TYPE_DISCOVERY 3

/*common connection header, for all conn, including listen*/
typedef struct connection_header
{
	uplus_u8 valid; /*1-valid, 0-invalid*/ /*for client and server*/
	uplus_u8 conn_type; /*CONN_TYPE_XXX*/
	uplus_u8 index; /*0~MAX_XXX_NUM-1*/

	uplus_time time_last_recv; /*客户端超时定时器/接入网关超时定时器, TIME_CLIENT_TIMEOUT/TIME_SVR_TIMEOUT*/
	uplus_time stamp; /*stamp when this conn is created*/
	pkt_connection_t *pkt_conn;
} connection_header_t;

#define MAX_PKT_BUF_SIZE 1024

/*packet control block*/
typedef struct pkt_control
{
	uplus_u8 max_pkt_conn; /*less than MAX_PKT_CONN_NUM*/
	void * fd_set_read; /*fd set for read*/
	void * fd_set_write; /*fd set for write*/
	pkt_connection_t *conn_tbl[MAX_PKT_CONN_NUM]; /*all conn pointer*/
	pkt_rx_data_t rx_data; /*static buffer control block, transfer to other modules*/
	struct uplus_sockaddr_in from;
	uplus_u8 *buf; /*static buf*/
	struct uplug *uplug;
} pkt_control_t;
#endif

#ifdef UPLUS_UWT_SERVER
typedef struct svr_extra_info
{
	char session[32]; /*session code on this connection*/
} svr_extra_info_t;

/*server connection*/
typedef struct connection_svr
{
	connection_header_t header; /*must be the first member of the structure*/
	svr_extra_info_t extra;

	/*server info*/
    char domain[64]; /*server domain name*/
    char ip_addr[16]; /*server ip address*/
    uplus_u16 port; /*server port*/

	uplus_u8 exit_flag;

	union
	{
		struct
		{
			uplus_u8 wifi_info_to_svr; /*report wifi info to server*/
			/*times*/
			uplus_u8 times_svr_reconnect; /*TIMES_SVR_RECONNECT*/
			uplus_u8 times_svr_wifi_info_rpt; /*first TIME_SVR_WIFI_INFO_RPT_0, others TIME_SVR_WIFI_INFO_RPT_1*/

			/*timer*/
			uplus_time time_svr_wifi_info_rpt; /*上报wifi信息定时器, TIME_SVR_WIFI_INFO_RPT_XXX*/
			uplus_time time_svr_keep_alive; /*接入网关keep alive定时器, TIME_SVR_KEEP_ALIVE*/
			uplus_time time_svr_ver_rpt; /*上报设备信息定时器, TIME_SVR_VER_RPT*/
			uplus_time time_svr_reconnect; /*接入网关重连定时器, TIME_SVR_RECONNECT*/
		} access;

		struct
		{
			/*timer*/
			uplus_time time_svr_master_reconnect; /*主网关重连定时器, TIME_SVR_MASTER_RECONNECT*/
			uplus_time time_svr_master_timeout; /*主网关超时定时器, TIME_SVR_MASTER_TIMEOUT*/
		} master;
	} u;
#ifdef UPLUS_UWT_SECURITY
	uplus_time time_svr_sec_handshake; /*uss handshake timeout TIME_SVR_SEC_HANDSHAKE*/
#endif
} connection_svr_t;

#define MASTER_SERVER_INDEX (MAX_SERVER_NUM - 1) /*0 based*/
#endif

#define SERVER_TYPE_MASTER 1
#define SERVER_TYPE_ACCESS 2
#define SERVER_TYPE_MASTER_CAE 3
#define SERVER_TYPE_ACCESS_CAE 4
#define SERVER_TYPE_MASTER_RECONNECT 5

#ifdef UPLUS_FEATURE_MODULE_SERVER
/*server control block*/
typedef struct svr_control
{
	uplus_u8 started; /*has been started*/
#ifdef UPLUS_UWT_SERVER
	uplus_u8 mod_server_type;
	uplus_u8 dev_err_to_svr; /*report dev error to server*/

	connection_svr_t conn[MAX_SERVER_NUM]; /*主网关 + 接入网关*/
	pkt_connection_t pkt_conn[MAX_SERVER_NUM]; /*主网关 + 接入网关*/
	uplus_u8 * svr_ca;
	uplus_u32 svr_ca_len;
#endif

#ifdef UPLUS_CAE_SERVER
	uplus_u8 connect_ok;
	uplus_u8 connect_chg;
	uplus_u8 is_connecting;
	uplus_u8 dev_err_to_svr_cae; /*report dev error to server*/
	cae_cloud_devGW_handle_t devGW_handle;
	cae_cloud_dev_handle_t dev_handle;

	/*timer*/
	uplus_time time_svr_net_quality_rpt; /*net quality report TIME_SVR_NET_QUALITY_INFO_RPT*/
	uplus_time time_svr_wifi_info_rpt; /*上报wifi信息定时器, TIME_SVR_WIFI_INFO_RPT_XXX*/
	uplus_u8 times_svr_wifi_info_rpt; /*first TIME_SVR_WIFI_INFO_RPT_0, others TIME_SVR_WIFI_INFO_RPT_1*/
	uplus_u8 wifi_info_to_svr; /*report wifi info to server*/

	char domain[64]; /*server domain name*/
	uplus_u16 port; /*server port*/
#endif

	struct uplug *uplug;
} svr_control_t;

/*task para*/
typedef struct svr_task_para
{
	svr_control_t *svr_ctl;
	uplus_u32 index;
	msg_server_connect_result_t *result;
} svr_task_para_t;

#endif

#ifdef UPLUS_UWT_CLIENT
typedef struct client_extra_info
{
	char session[32]; /*session code on this connection*/
	struct uplus_sockaddr_in from;
	uplus_u32 from_len;
} client_extra_info_t;

/*local connection*/
typedef struct connection_client
{
	connection_header_t header; /*must be the first member of the structure*/
	client_extra_info_t extra;
} connection_client_t;
#endif

#ifdef UPLUS_FEATURE_MODULE_CLIENT
/*client control block*/
typedef struct client_control
{
	uplus_u8 started; /*has been started*/
#ifdef UPLUS_UWT_CLIENT
	uplus_u8 current_active; /*current active client*/
	uplus_u8 max_client; /*max client*/

	connection_header_t listen[MAX_CLIENT_LISTEN_NUM]; /*tcp listen*/
	pkt_connection_t *pkt_conn; /*client rx, max_client + MAX_CLIENT_LISTEN_NUM*/
	connection_client_t *conn; /*max_client*/
#endif

#ifdef UPLUS_CAE_CLIENT
	cae_locals_handle_t locals_handle;
	cae_locals_dev_handle_t dev_handle;
#endif

	struct uplug *uplug;
} client_control_t;
#endif

#ifdef UPLUS_UWT_DISCOVERY
typedef struct discovery_extra_info
{
	uplus_u32 dummy;
} discovery_extra_info_t;

/*local discovery*/
typedef struct connection_discovery
{
	connection_header_t header; /*must be the first member of the structure*/
	discovery_extra_info_t extra;
} connection_discovery_t;
#endif

#ifdef UPLUS_FEATURE_MODULE_DISCOVERY
/*discovery control block*/
typedef struct discovery_control
{
#ifdef UPLUS_UWT_DISCOVERY
	connection_discovery_t conn[MAX_DISCOVERY_NUM];
	pkt_connection_t pkt_conn[MAX_DISCOVERY_NUM];
#endif

	uplus_u8 started; /*has been started*/
	uplus_u32 reason; /*offline reason*/

#ifdef UPLUS_UWT_DISCOVERY
	/*times*/
	uplus_u8 times_online_rpt; /*TIMES_ONLINE_RPT*/
	/*timer*/
	uplus_time time_online_rpt; /*上线宣告定时器, TIME_ONLINE_RPT*/
#endif
#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
	/*times*/
	uplus_u8 times_smartlink_ack; /*TIMES_SMARTLINK_ACK*/
	/*timer*/
	uplus_time time_smartlink_ack; /*smarklink配置应答定时器, TIME_SMARTLINK_ACK*/
#endif

#ifdef UPLUS_CAE_DISCOVERY
	uplus_u8 init_ok;
	cae_sd_svc_handle_t svc_handle;
#endif

	struct uplug *uplug;
} discovery_control_t;
#endif

#ifdef UPLUS_FEATURE_MODULE_OTA
typedef struct ota_file_header
{
	uplus_u8 verion; /*文件头版本，当前0*/
	uplus_u8 backup1[3]; /*保留*/
	uplus_u8 hw_ver[16]; /*硬件版本*/
	uplus_u8 sw_ver[16]; /*软件版本*/
	uplus_u8 platform[32]; /*平台*/
	uplus_u8 make_time[64]; /*制作时间*/
	uplus_u8 backup2[380]; /*保留*/
} ota_file_header_t;

#define OTA_BUFFER_LEN_MAX 4096
#define OTA_BUFFER_LEN_MIN 1024
#define OTA_SEGMENT_LEN 1024

#define OTA_ACCEPT_NEW 0
#define OTA_REJECT_NEW 1
#define OTA_STOP_OLD 2
#define OTA_RESTART_OLD_ACK 3
#define OTA_RESTART_OLD 4
#define OTA_KEEP_OLD 5

#define OTA_STOP_REASON_OTA_FINISH 0
#define OTA_STOP_REASON_CONN_BREAK -1
#define OTA_STOP_REASON_PREEMPTION -2
#define OTA_STOP_REASON_RESTART_ACK -3
#define OTA_STOP_REASON_RESTART -4
#define OTA_STOP_REASON_TIMEOUT -5
#endif

#ifdef UPLUS_UWT_OTA
#define OTA_RX_MODE_NORMAL 0
#define OTA_RX_MODE_OTA 1

#define OTA_MODE_CONT 0
#define OTA_MODE_RESUME_BREAK 1

typedef struct ota_reject_conn_list
{
	struct ota_reject_conn_list *next;

	connection_header_t *conn;
	/*dirty data*/
	uplus_u8 *buffer;
	uplus_u32 buffer_need_rcvd;

	msg_common_header_t msg; /*for ack, 收到OTA升级命令后，先构造ACK消息，待接收完成后，直接发送*/
	void (*rx_handler)(struct pkt_connection *pkt_conn); /*rx handler*/
	int (*lower_rx)(struct pkt_connection *pkt_conn);/*1-whole packet, 0-partial packet, -1-error*/
} ota_reject_conn_list_t;
#endif

#ifdef UPLUS_FEATURE_MODULE_OTA
/*ota control block*/
typedef struct ota_control
{
	uplus_u8 image_zone; /*ota zone to be written*/

	uplus_u8 is_upgrading; /*upgrading?*/

	/*ota file info*/
	uplus_u8 force_upgrade;
	uplus_u32 total_len; /*ota file len*/
	uplus_u8 md5_digest_str[32];
	uplus_u32 check_sum;

	/*buffer info*/
	uplus_u8 *buffer; /*max 4K, min 1024 bytes, if memory is large enough, use max*/
	uplus_u16 buffer_size;
	uplus_u32 buffer_need_rcvd; /*需要接收的数据长度*/
	uplus_u32 total_rcvd; /*rcv ota data len*/
	uplus_u32 buffer_offset;
	uplus_u32 flash_offset;

	uplus_u32 last_error;

	/*timer*/
	uplus_time time_seg_req; /*重传seq request的时间间隔，TIME_OTA_SEQ_REQ_INTERVAL*/
	uplus_time time_ota; /*OTA开始升级时间*/
	uplus_time time_ota_delay_reset; /*TIME_OTA_DELAY_RESET*/

#ifdef UPLUS_UWT_OTA
	connection_header_t *current_conn; /*current conn doing ota op*/
	ota_reject_conn_list_t *reject; /*reject conn list, used to recv dirty data*/

	uplus_u8 ota_conn_type; /*CONN_TYPE_XXX*/
	uplus_u8 mode; /*持续接收 or 断点续传, OTA_MODE_XXX*/
	uplus_u8 re_rpt_to_svr; /*在远程OTA升级过程中，若被本地OTA升级程序打断，当本地OTA失败时，向远程服务器重新上报版本号*/
	uplus_u8 rcv_dirty_data;

	/*ota file info*/
	uplus_u32 upgrade_sn; /*network order*/

	msg_common_header_t msg; /*for ack, 收到OTA升级命令后，先构造ACK消息，待接收完成后，直接发送. 
		notice: should not be sent, only copy & send msg; only valid when current_conn is valid*/

	/*buffer info*/
	uplus_u32 dirty_data_need_rcvd; /*需要接收的脏数据长度*/

	/*ota rx*/
	uplus_u8 ota_rx_mode; /*OTA_RX_MODE_XXX*/
	void (*rx_handler)(struct pkt_connection *pkt_conn); /*rx handler*/
	int (*lower_rx)(struct pkt_connection *pkt_conn);/*1-whole packet, 0-partial packet, -1-error*/
#endif

#ifdef UPLUS_CAE_OTA
	/*ota file info*/
	cae_int8_t * upgrade_sn_str;
	cae_int8_t * url;
	uplus_u8 from_server;
	void *dev_handle;
#endif

	ota_check header_check;
	ota_check tail_check; /*must be set*/
	void *check_para;
	uplus_u32 check_offset;
	uplus_u32 check_len;

	struct uplug *uplug;
} ota_control_t;
#endif

/*E++ packet header*/
#pragma pack(1)
typedef struct epp_frame_header
{
	uplus_u8 flag_sequence[2]; /*0xFF, 0xFF*/
	uplus_u8 epp_frame_len;
	uplus_u8 addr[6];
	uplus_u8 cmd;
} epp_frame_header_t;
#pragma pack()

/*used E++ cmd*/
#define EPP_CMD_CTRL               0x01
#define EPP_CMD_STATUS             0x02
#define EPP_CMD_INVALID_CMD        0x03
#define EPP_CMD_ALARM              0x04
#define EPP_CMD_ACK                0x05
#define EPP_CMD_REPORT             0x06
#define EPP_CMD_STOP_ALARM         0x09
#define EPP_CMD_GROUP_EXE          0x60
#define EPP_CMD_GET_ALARM          0x73
#define EPP_CMD_GET_ALARM_ACK      0x74
#define EPP_CMD_SPLIT_DOWN         0x8A
#define EPP_CMD_SPLIT_UP           0x8B
#define EPP_SIZE_EXTRA 3 /*2 byte flag_seq + 1 byte len*/


#ifdef UPLUS_FEATURE_MODULE_SECURITY
typedef struct sec_control
{
	struct uplug *uplug;
} sec_control_t;
#endif

#define CONF_VER_0 0

#define CONF_VALID_FLAG 0x12

#define CONFIG_BLOCK_SIZE 1024
#define CONFIG_BLOCK_NUMBER 4

#define MAX_CONFIG_DATA_LEN (CONFIG_BLOCK_SIZE * CONFIG_BLOCK_NUMBER)
#define CONF_FLAG_EXTEND_BLOCK_MASK 0x3 /*number of extended block*/

/*config data stucture, less than 1k*/
typedef struct conf_data
{
	uplus_u8 digest[16]; /*digest, not include digest field*/
	uplus_u8 ver; /*ver, current ver 0*/
	uplus_u8 flags; /*CONF_FLAG_XXX*/
	uplus_u16 len; /*sizeof conf_data_t, may be diff for diff ver*/

	/*common 512 octets*/
	char user[64];
	char passWord[64];
	char nickName[64];
	char roomName[64];

	char svr_domain[64]; /*master server*/
	uplus_u16 svr_port; /*master server port*/
	uplus_u8 led_enable; /*1-enable 0-disable, default 0*/
	uplus_u8 last_offline_reason;
	uplus_u16 last_offline_strength;
	uplus_u8 svr_valid; /*CONF_VALID_FLAG-indicate svr config is valid*/ 

	uplus_u8 svr_valid_cae; /*CONF_VALID_FLAG-indicate svr config is valid*/
	char svr_domain_cae[64]; /*master server*/
	uplus_u16 svr_port_cae; /*master server port*/
	uplus_u16 last_offline_strength_cae;
	uplus_u8 last_offline_reason_cae;

	uplus_u8 default_dev_name_valid; /*CONF_VALID_FLAG-indicate default_dev_name is valid*/
	uplus_u8 default_dev_name[8];
	uplus_u8 res_common[106]; /*reserved*/

	/*wifi 128 octets*/
	char ssid[32];
	char key[64];
	uplus_u8 ssid_valid; /*CONF_VALID_FLAG-indicate ssid config is valid*/
	uplus_u8 res_wifi[27]; /*reserved*/
	uplus_u32 encryption; /*WIFI_ENCRYPT_XXX*/

	/*epp device 96 octets*/
	uplus_u8 epp_conf[96];

	/*network 96 octets*/
	char ip_addr[16]; /*ip addr when dhcp is disabled*/
	char ip_mask[16]; /*ip mask when dhcp is disabled*/
	char ip_gw[16]; /*ip gw when dhcp is disabled*/
	char ip_dns[16]; /*ip dns server when dhcp is disabled*/
	uplus_u8 dhcp_enable; /*1-enable 0-disable, default 1*/
	uplus_u8 res_net[31]; /*reserved*/
} conf_data_t;

#define CONFIG_CHG_ZONE_1 1
#define CONFIG_CHG_ZONE_2 2
#define CONFIG_CHG_ZONE_BOTH (CONFIG_CHG_ZONE_1 | CONFIG_CHG_ZONE_2)

typedef void (* uplug_conf_data_convert_func)(conf_data_t *);

/*config data control block*/
typedef struct conf_control
{
	uplus_u8 chg_zone; /*indicate zones that neeed be synced*/
	uplus_u8 first_wr_zone; /*存储配置时，先写哪个区域*/
	uplus_u8 ext_block_number; /*extended block number supported*/

	/*total MAX_CONFIG_DATA_LEN*/
	conf_data_t data;
	uplus_u8 res[CONFIG_BLOCK_SIZE - sizeof(conf_data_t)]; /*now the res zone can be used, total size 172 bytes*/
	uplus_u8 extend[CONFIG_BLOCK_NUMBER - 1][CONFIG_BLOCK_SIZE];
	op_conf_func clr[CONFIG_BLOCK_NUMBER - 1];
} conf_control_t;

#ifdef UPLUS_FEATURE_MODULE_SMARTLINK

#define WIFI_EXT_CHANNEL_INVALID 0xFF

typedef struct smartlink_control
{
	uplus_u8 started; /*has been started*/
	uplus_u8 smartlink_ok; /*indicate smartlink is ok*/

	/*current channel*/
	uplus_time time_channel_start;
	uplus_time time_lock_channel_start;
	uplus_u16 cur_channel; /*current sniffer channel*/
	uplus_u16 max_channel; /*max supportted channel*/
	uplus_u8 channel_changed; /*indiacate channnel is switched*/
	uplus_u8 channel_locked; /*channel is locked?*/
	uplus_u8 method_index; /*current using method index, valid when channel is locked*/
	uplus_u8 ext_channel; /*for 11n 40M*/
	uplus_u8 method_forced; /*method to be used*/

	/*result*/
	uplus_u8 ext_data[32];
	uplus_u8 ext_data_len;
	uplus_u8 ssid[32 + 1];
	uplus_u8 passwd[64 + 1];
	uplus_u8 result_method_index; /*which method is used to get the result*/

	struct uplug *uplug;
} smartlink_control_t;
#endif

/*发生严重错误，尝试恢复的最大次数，超出后，系统复位*/
#define MAX_RETRY_NUM_SEVERY_ERROR 10

typedef struct uplug
{
	uplus_u8 reset_flag;

	/*third party*/
	uplus_u8 notify_third_party;

	/*timer*/
	uplus_time time_init; /*LED省电定时器/空调允许配置定时器, TIME_LED_POWER_SAVE*/
	uplus_time time_sys; /*for lower system or some info, TIME_SYS*/
	uplus_time time_second;

	/*registered device info*/
	dev_info_t dev_info;
	uplus_u8 dev_protocol; /*any char, but diff for diffent device protocol, 'E' is reserved for E++*/
	uplus_u8 dev_instance; /*indicate different instance*/
	uplus_u8 protocol_data_type;
	uplus_u8 dev_registered; /*the device is registered?*/

	/*config data*/
	conf_control_t conf;

	/*wifi control block*/
	wifi_control_t wifi;

	/*state control block*/
	state_control_t state;

#ifdef UPLUS_FEATURE_MODULE_PKT
	/*packet block*/
	pkt_control_t pkt;
#endif

#ifdef UPLUS_FEATURE_MODULE_SOFTAP
	uplus_time time_softap_wait; /*等待客户端收到应答延迟，TIME_SOFTAP_WAIT*/
	/*make ssid for softap*/
	/*uplus_u8 dev_type_name[16];*/ /*epp dev class + mac*/
#endif

#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
	/*smartlink info*/
	uplus_u8 smartconfiged_flg; /*enter work mode from smartlink mode*/
	uplus_u8 smartlink_to_softap; /*to softap*/
	msg_smartlink_cfg_t saved_smlk_para;
	smartlink_control_t smlk;
#endif

#ifdef UPLUS_FEATURE_MODULE_THIRD_CONFIG
	uplus_u32 config_time;
#endif

#ifdef UPLUS_FEATURE_MODULE_WIFI_CONFIG
	/*timer*/
	uplus_time time_config; /*配置超时定时器, TIME_CONFIG_XXX*/
	uplus_time time_saved_cmd; /*保存命令超时定时器，TIME_SAVED_CMD*/
	uplus_u16 saved_config_cmd; /*在没有获取到底板设备信息之前保存的进入配置的命令*/
	uplus_u8 cfg_mode; /*CONFIG_MODE_XXX*/
#endif

	/*led control*/
	uplus_u16 led_control;

#ifdef UPLUS_FEATURE_MODULE_SCAN
	scan_control_t scan;
#endif

#ifdef UPLUS_FEATURE_MODULE_SERVER
	/*server connection block*/
	svr_control_t svr;
#endif

#ifdef UPLUS_FEATURE_MODULE_DISCOVERY
	/*local discovery block*/
	discovery_control_t discovery;
#endif

#ifdef UPLUS_FEATURE_MODULE_CLIENT
	/*local connection block*/
	client_control_t client;
#endif

#ifdef UPLUS_FEATURE_MODULE_OTA
	/*ota control block*/
	ota_control_t ota;
#endif

#ifdef UPLUS_FEATURE_MODULE_SECURITY
	/*security control block*/
	sec_control_t security;
#endif
} uplug_t;

enum 
{
	/*comm with third party protocol*/
	NOTIFY_ENTER_WORK = 0,
	NOTIFY_EXIT_WORK,
};

typedef struct share_data_with_third_party
{
	uplus_u8 work_mode; /*1-work, 0-others*/
} share_data_with_third_party_t;

/*adpater control block*/
typedef struct adapter_control
{
	uplus_u8 used; /*1-used, 0-not used*/
	uplus_u8 valid; /*1-valid, 0-invalid*/
	uplus_u8 index; /*index, 0 based*/

	adapter_control_info_t info; /*registered info*/
	dev_info_t dev_info; /*registered dev info*/
} adapter_control_t;

/*third party protocol control block*/
typedef struct protocol_control
{
	uplus_u8 used; /*1-used, 0-not used*/
	uplus_u8 valid; /*1-valid, 0-invalid*/
	uplus_u8 index; /*index, 0 based*/

	uplus_u8 changed[MAX_PROTOCOL_CTRL_NUM];
	protocol_control_info_t info; /*registered info*/
} protocol_control_t;

/*wifi config control block*/
typedef struct wifi_config_control
{
	uplus_u8 used; /*1-used, 0-not used*/
	uplus_u8 valid; /*1-valid, 0-invalid*/
	uplus_u8 index; /*index, 0 based*/

	wifi_config_info_t info; /*registered info*/
} wifi_config_control_t;

/*common data, eg, queue,mutex*/
typedef struct uplug_common
{
	/*queue*/
	uplus_id queue[MAX_QUEUE_NUM];

	adapter_control_t adapter[MAX_ADAPTER_NUM]; /*device adapter*/
	protocol_control_t protocol[MAX_PROTO_FAMILY_NUM]; /*interconnection protocol*/
#ifdef UPLUS_FEATURE_MODULE_SMARTLINK
	wifi_config_control_t *wifi_config_smartlink;
#endif
	dev_info_t default_dev_info;
	uplus_u8 default_dev_info_cfged;

	/*mutex*/
	uplus_id mutex_u_internal; /*for u+ internal*/
#if (MAX_PROTO_FAMILY_NUM > 1)
	uplus_id mutex_u_external; /*for u+ and alljoyn or others*/
#endif

	/*timer*/
	uplus_time time_check_share; /*第三方协议共享数据查询定时器, TIME_CHECK_SHARE, for U+*/
	share_data_with_third_party_t share_data;

	/*config*/
	config_para_t config;
} uplug_common_t;

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_DEF_H__*/

