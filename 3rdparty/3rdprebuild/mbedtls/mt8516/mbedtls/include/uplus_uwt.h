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

#ifndef __UPLUS_UWT_H__
#define __UPLUS_UWT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*supported uwt command*/
#define UWT_CMD_TRANSMIT_DOWN			10004
#define UWT_CMD_TRANSMIT_UP				10005

#define UWT_CMD_BUSINESS_TO_WIFI		10006
#define UWT_CMD_WIFI_TO_BUSINESS		10007

#define UWT_CMD_CAE_TRANSMIT_DOWN		10010
#define UWT_CMD_CAE_TRANSMIT_UP			10011

#define UWT_CMD_LOGIN_DEV				10014

#define UWT_CMD_KEEP_ALIVE_TO_SERVER    10015
#define UWT_CMD_KEEP_ALIVE_FROM_SERVER  10016

#define UWT_CMD_WIFI_TO_COMMSERVER		10019
#define UWT_CMD_COMMSERVER_TO_WIFI		10020
#define	UWT_CMD_WIFI_TO_DATASERVER		10021

#define UWT_SUB_CMD_REPORT_VERSION			20001
#define UWT_SUB_CMD_REPORT_VERSION_ACK		20001

#define UWT_SUB_CMD_UPGRADE					20002
#define UWT_SUB_CMD_UPGRADE_ACK				20003

#define UWT_SUB_CMD_CHANGE_DOMAIN			20004
#define UWT_SUB_CMD_CHANGE_DOMAIN_ACK		20005

#define UWT_SUB_CMD_WIFI_BASE_INFO			20012
#define UWT_SUB_CMD_WIFI_BASE_INFO_ACK		20013

#define UWT_SUB_CMD_DEVICE_EVENT_NOTIFY		20016
#define UWT_SUB_CMD_WIFI_INFO_REPORT		20017

#define UWT_SUB_CMD_UPGRADE_START			20018
#define UWT_SUB_CMD_UPGRADE_START_ACK		20019
#define UWT_SUB_CMD_UPGRADE_SEGMENT_REQ		20020
#define UWT_SUB_CMD_UPGRADE_SEGMENT_DATA	20021
#define UWT_SUB_CMD_UPGRADE_COMPLETE		20022

#define UWT_CMD_REG_CLIENT				24003
#define UWT_CMD_REG_CLIENT_ACK			24004
#define UWT_CMD_GEN_SESSION				24041  
#define UWT_CMD_GEN_SESSION_ACK			24042 
#define UWT_CMD_DEL_SESSION				24043 
#define UWT_CMD_DEL_SESSION_ACK			24044 
#define UWT_CMD_KEEPALIVE				24050
#define UWT_CMD_KEEPALIVE_ACK			24051

#define UWT_CMD_GET_PARAMETER		26001
#define UWT_CMD_GET_PARAMETER_ACK	26002
#define UWT_CMD_SET_PARAMETER		26003
#define UWT_CMD_SET_PARAMETER_ACK	26004

#define UWT_CMD_SMARTCONFIG_ACK			26008
#define UWT_CMD_GET_SMARTCONFIG_ERRNO   26009
#define UWT_CMD_GET_SMARTCONFIG_ERRNO_ACK   26010

#define UWT_CMD_SET_GMS_DOMAIN			26013
#define UWT_CMD_SET_GMS_DOMAIN_ACK		26014

#define UWT_CMD_TRANSMIT_DOWN_DATA		26108 
#define	UWT_CMD_TRANSMIT_DOWN_DATA_ACK	26109
#define UWT_CMD_TRANSMIT_UP_DATA		26110
#define UWT_CMD_TRANSMIT_UP_DATA_ACK	26111

#define	UWT_CMD_DEVICE_ONLINE			26701
#define UWT_CMD_DEVICE_OFFLINE			26702

#define UWT_CMD_UDISCOVERY_HEARTBEAT        26901
#define UWT_CMD_UDISCOVERY_HEARTBEAT_ACK    26901

#define UWT_CMD_MGR_SMARTLINK           30001
#define UWT_CMD_MGR_SMARTLINK_ACK       30002

#define UWT_CMD_MGR_WIFI            30003
#define UWT_CMD_MGR_WIFI_ACK        30004

/*max uwt cmd length*/
#define UWT_BODY_MAX_LEN		4096

/*def in command*/
#define UWT_ERROR_OK			0
#define UWT_ERROR_OTHER			0xFFFFFFFF
#define UWT_ERROR_TRANSMIT		200
#define CAE_ERROR_OTHER			20001

#define UWT_EVENT_UART_ERR		101
#define UWT_EVENT_UNBIND		201

#define UWT_NETTYPE_NO			0
#define UWT_NETTYPE_WIFI		1
#define UWT_NETTYPE_2G			2
#define UWT_NETTYPE_3G			3
#define UWT_NETTYPE_4G			4

enum offline_reason_e
{
	OFFLINE_RELOAD = 1,
	OFFLINE_ENTER_CONFIG,
	OFFLINE_WATCHDOG,
	OFFLINE_UPGRAD_UPLUG,
	OFFLINE_UPGRAD_BASE_BOARD,
	OFFLINE_UART_ERR,
	OFFLINE_MODI_AP_INFO
};

enum svr_connect_err_e
{
	CONSVR_OTHER_ERR = 0,/*【0】其他*/
	CONSVR_FISTCONNECT,/*【1】设备启动后第一次连接*/
	CONSVR_TRANS_ERR,/*【2】与服务器通信失败*/
	CONSVR_AP_ERR,/*【3】与接入点AP连接断开*/
	CONSVR_RD_ERR,/*【4】收到无效数据主动断开连接*/
	CONSVR_NO_TRANS_ERR,/*【5】超时未收到数据主动断开连接*/
	CONSVR_MODE_CHG/*【6】模式切换主动断开连接*/
};

enum ap_connect_err_e
{
	CONAP_OK =0,
	CONAP_OTHER_ERR = 60001,
	CONAP_PASSWORD_ERR,
	CONAP_NONE_NETWORK_ERR,
	CONAP_NOSIGNAL_ERR,
	CONAP_DHCP_ERR,
	CONAP_TIMEOUT_ERR
};

#define OTA_OK								0
#define OTA_ERROR_OTHER						99
#define OTA_ERROR_CONTENT_VALIDATION		106
#define OTA_ERROR_INCOMPLETE_CONTENT		110
#define OTA_ERROR_ILLEGAL_CONTENT			107
/*#define OTA_ERROR_DEVICE_MODULE_UPGRADING	113*/
#define OTA_ERROR_UPGRADE_ABORT				116

#define MAX_AP_REPORT 10
#define MAX_AP_REPORT_TO_APP 20

/*msg def, shoule be one byte alignment*/
#pragma pack(1)
/*UWT_CMD_LOGIN_DEV*/
typedef struct uwt_login_dev
{
	uplus_u32 cmd;
	char passwd[64];
} uwt_login_dev_t;
typedef struct uwt_login_ack
{
	uplus_u32 cmd;
	uplus_u32 result;
	char session[32];
} uwt_login_ack_t;

/*structure with cae header*/
typedef struct uwt_cae_head
{
	uplus_u32 cmd;
	uplus_u16 ctrl;
	uplus_u16 check;
	uplus_u32 sn;
	uplus_u32 len;
} uwt_cae_head_t;

/*UWT_CMD_REG_CLIENT*/
typedef struct uwt_cae_reg_client
{
	/*uwt_cae_head_t head;*/
	char mac[16];
	char user[64];
	char passwd[64];
	char platform[32];
} uwt_cae_reg_client_t;

/*UWT_CMD_REG_CLIENT_ACK*/
typedef struct uwt_cae_reg_client_ack
{
	uwt_cae_head_t head;
	uplus_u32 error;
	char mac[16];
	char ip[32];
	char nickName[64];
	uplus_u32 isRemote;
	uplus_u32 isOnline;
} uwt_cae_reg_client_ack_t;

/*UWT_CMD_GEN_SESSION*/
typedef struct uwt_cae_get_session
{
	/*uwt_cae_head_t head;*/
	char mac[16];
} uwt_cae_get_session_t;

/*UWT_CMD_GEN_SESSION_ACK*/
typedef struct uwt_cae_get_session_ack
{
	uwt_cae_head_t head;
	uplus_u32 error;
	char session[32];
} uwt_cae_get_session_ack_t;

/*UWT_CMD_DEL_SESSION*/
typedef struct uwt_cae_del_session
{
	/*uwt_cae_head_t head;*/
	char session[32];
	char del_session[32];
} uwt_cae_del_session_t;

/*UWT_CMD_DEL_SESSION_ACK*/
typedef struct uwt_cae_del_session_ack
{
	uwt_cae_head_t head;
	char session[32];
	uplus_u32 error;
} uwt_cae_del_session_ack_t;

/*UWT_CMD_KEEPALIVE*/
typedef struct uwt_cae_alive
{
	/*uwt_cae_head_t head;*/
	char session[32];
	char mac[16];
} uwt_cae_alive_t;

/*UWT_CMD_KEEPALIVE_ACK*/
typedef struct uwt_cae_alive_ack
{
	uwt_cae_head_t head;
	char session[32];
	char mac[16];
	uplus_u32 link_status;
} uwt_cae_alive_ack_t;

/*UWT_CMD_GET_PARAMETER*/
typedef struct uwt_cae_get_uwt_parameter_t
{
	uwt_cae_head_t head;
} uwt_cae_get_uwt_parameter_t;

typedef struct ap_info
{
	char ssid[32];
	uplus_u16 encryptionType;
	uplus_u16 strength;
} ap_info_t;

typedef struct config_r_head
{
	uplus_u32 errornum;
	char typeID[32];
	uplus_u32 mode;
	char mac[16];
	char ip[16];
	char e_protocol_ver[16];
	uplus_u32 ap_num;
	char nickName[64];
	char roomName[64];
	char passWord[64];
} config_r_head_t;

/*UWT_CMD_GET_PARAMETER_ACK*/
typedef struct uwt_cae_get_uwt_parameter_ack
{
	uwt_cae_head_t head;
	config_r_head_t info;
	/*ap_info_t*/
} uwt_cae_get_uwt_parameter_ack_t;

typedef struct set_uwt_parameter_info
{
	char roomName[64];
	char typeID[32];
	char nickName[64];
	char user[64];
	char passWord[64];
	char ap_sid[32];
	char ap_pass[64];
	uplus_u32 useDhcp;
	char ip[32];
	char gate[32];
	char mask[32];
	char dns[32];
	char server_domain[64];
	uplus_u32 server_port;
	char server_domain_bak[64];
	uplus_u32 server_port_bak;
} set_uwt_parameter_info_t;

/*UWT_CMD_SET_PARAMETER*/
typedef struct uwt_cae_set_uwt_parameter
{
	/*uwt_cae_head_t head;*/
	set_uwt_parameter_info_t info;
} uwt_cae_set_uwt_parameter_t;

/*UWT_CMD_SET_PARAMETER_ACK*/
typedef struct uwt_cae_set_uwt_parameter_ack
{
	uwt_cae_head_t head;
	uplus_u32 error;
} uwt_cae_set_uwt_parameter_ack_t;

typedef struct mgr_sl_info_t
{
	uplus_u32 restore;
	uplus_u32 reset;
	char log_ip[32];
	uplus_u32 log_port;
	uplus_u32 log_enable;
	uplus_u32 log_time_span;
	uplus_u32 led_enable;
	uplus_u32 enter_cfg;
	char common_svr_domain[64];
	uplus_u32 common_svr_port;
	char svr_domain[64];
	uplus_u32 svr_port;
} mgr_sl_info_t;

/*UWT_CMD_MGR_SMARTLINK*/
typedef struct uwt_cae_mgt_smartlink
{
	/*uwt_cae_head_t head;*/
	char session[32];
	char mac[16];
	mgr_sl_info_t info;
} uwt_cae_mgt_smartlink_t;

/*UWT_CMD_MGR_SMARTLINK_ACK*/
typedef struct uwt_cae_mgt_smartlink_ack
{
	uwt_cae_head_t head;
	char session[32];
	uplus_u32 error;
	mgr_sl_info_t info;
} uwt_cae_mgt_smartlink_ack_t;

/*UWT_CMD_MGR_WIFI*/
typedef struct uwt_cae_mgr_wifi
{
	/*uwt_cae_head_t head;*/
	char session[32];
	uplus_u8 disable_wifi;
	uplus_u8 para[63];
} uwt_cae_mgr_wifi_t;

/*UWT_CMD_MGR_WIFI_ACK*/
typedef struct uwt_cae_mgr_wifi_ack
{
	uwt_cae_head_t head;
	char session[32];
	uplus_u32 error;
	uplus_u8 disable_wifi;
	uplus_u8 para[63];
} uwt_cae_mgr_wifi_ack_t;

/*UWT_CMD_UDISCOVERY_HEARTBEAT*/
typedef struct uwt_cae_udp_search
{
	/*uwt_cae_head_t cae_head;*/
	char mac[16];
	char version[8];
	char platform[32];
} uwt_cae_udp_search_t;

/*UWT_CMD_UDISCOVERY_HEARTBEAT_ACK*/
typedef struct uwt_cae_udp_search_ack
{
	uwt_cae_head_t cae_head;
	char mac[16];
	char version[8];
	char platform[32];
} uwt_cae_udp_search_ack_t;

/*UWT_CMD_DEVICE_ONLINE*/
typedef struct uwt_cae_udp_dev_online
{
	uwt_cae_head_t cae_head;
	char mac[16];
	char typeID[32];
	char nickName[64];
	char roomName[64];
	char ssid[32];
	char ip[16];
	char cfg_ver[8];
	char epp_ver[8];
	char sw_ver[8];
	char hw_ver[8];
	char platform[32];
} uwt_cae_udp_dev_online_t;

/*UWT_CMD_DEVICE_OFFLINE*/
typedef struct uwt_cae_udp_dev_offline
{
	uwt_cae_head_t cae_head;
	char mac[16];
	uplus_u32 reason;
} uwt_cae_udp_dev_offline_t;

/*UWT_CMD_SMARTCONFIG_ACK*/
typedef struct uwt_cae_udp_smartlink_ack
{
	uwt_cae_head_t cae_head;
	char mac[16];
	char ip[16];
	char typeID[32];
	char epp_ver[8];
	char ssid[32];
	char password[64];
	uplus_u16 configSeedID;
} uwt_cae_udp_smartlink_ack_t;

/*
UWT_CMD_TRANSMIT_DOWN_DATA
UWT_CMD_TRANSMIT_UP_DATA
*/
typedef struct
{
	uwt_cae_head_t head;
	char session[32];
	char mac[16];
	/*e++ data*/
}uwt_transmit_down_data_t, uwt_transmit_up_data_t;

/*
UWT_CMD_TRANSMIT_DOWN_DATA_ACK
UWT_CMD_TRANSMIT_UP_DATA_ACK
*/
typedef struct
{
	uwt_cae_head_t head;
	char session[32];
	uplus_u32 errno;
}uwt_transmit_down_data_ack_t, uwt_transmit_up_data_ack_t;

/*UWT_CMD_GET_SMARTCONFIG_ERRNO_ACK*/
typedef struct uwt_cae_smartconfig_errno_ack
{
	uwt_cae_head_t head;
	char hw_version[8];
	uplus_u32 errno;
} uwt_cae_smartconfig_errno_ack_t;

#define UWT_TYPE_MASTER_DOMAIN	0x1
#define UWT_TYPE_SVR_DOMAIN		0x2

/*UWT_CMD_SET_GMS_DOMAIN*/
typedef struct uwt_cae_set_gms_domain
{
	/*uwt_cae_head_t head;*/
	uplus_u32 type;
	char domain[64];
	uplus_u32 port;
} uwt_cae_set_gms_domain_t;

/*UWT_CMD_SET_GMS_DOMAIN_ACK*/
typedef struct uwt_cae_set_gms_domain_ack
{
	uwt_cae_head_t head;
} uwt_cae_set_gms_domain_ack_t;

/*structure with tcp header*/
typedef struct uwt_tcp_head
{
	uplus_u32 cmd;
	uplus_u32 error_num;
	char session[32];
	char mac[32];
	uplus_u32 sn;
	uplus_u32 len;
} uwt_tcp_head_t;

/*UWT_CMD_KEEP_ALIVE_TO_SERVER*/
typedef struct uwt_alive_to_svr
{
	uwt_tcp_head_t head;
	uplus_u32 duration;
	uplus_u16 strength;
	uplus_u16 network_type;
} uwt_alive_to_svr_t;

/*UWT_CMD_KEEP_ALIVE_FROM_SERVER*/
typedef struct uwt_alive_from_svr
{
	uwt_tcp_head_t head;
} uwt_alive_from_svr_t;

/*
UWT_CMD_WIFI_TO_COMMSERVER
UWT_CMD_COMMSERVER_TO_WIFI
*/
typedef struct
{
	uwt_tcp_head_t head;
	uplus_u32 sub_cmd;
} uwt_wifi_to_comm_svr_t, uwt_comm_svr_to_wifi_t;

/*UWT_SUB_CMD_WIFI_BASE_INFO*/
typedef struct rpt_ver_master
{
	char modual_ver[8];
	char devfile_ver[8];
	char e_protocol_ver[8];
	char hw_ver[8];
	char platform[32];
	char basebd_sw_ver[8];
	char basebd_hw_ver[8];
	uplus_u8 basebd_upgrade;
	uplus_u32 ciper_suite;
} rpt_ver_master_t;

/*UWT_SUB_CMD_WIFI_BASE_INFO_ACK*/
typedef struct master_baseinfo_ack
{
    char domain[64];
    uplus_u32 port;
    char dev_type_name[32];
    char app_bundle_id[32];
    uplus_u32 cfg_file_flg;
} master_baseinfo_ack_t;

/*UWT_CMD_WIFI_TO_DATASERVER*/
typedef struct
{
	uwt_tcp_head_t head;
} uwt_wifi_to_data_svr_t;

/*
UWT_CMD_TRANSMIT_DOWN
UWT_CMD_TRANSMIT_UP
*/
typedef struct
{
	uwt_tcp_head_t head;
	/*e++ data*/
}uwt_transmit_down_t, uwt_transmit_up_t;

/*
UWT_CMD_CAE_TRANSMIT_DOWN
UWT_CMD_CAE_TRANSMIT_UP
*/
typedef struct
{
	uwt_tcp_head_t head;
	/*cae data*/
} uwt_cae_transmit_down_t, uwt_cae_transmit_up_t;

/*
UWT_CMD_BUSINESS_TO_WIFI
UWT_CMD_WIFI_TO_BUSINESS
*/
typedef struct
{
	uwt_tcp_head_t head;
	uplus_u32 sub_cmd;
} uwt_business_to_wifi_t, uwt_wifi_to_business_t;

/*
UWT_SUB_CMD_REPORT_VERSION_ACK
UWT_SUB_CMD_UPGRADE_ACK
UWT_SUB_CMD_CHANGE_DOMAIN_ACK
UWT_SUB_CMD_UPGRADE_START_ACK
*/

/*UWT_SUB_CMD_REPORT_VERSION*/
typedef struct uwt_rpt_ver_svr
{
	char modual_ver[8];
	char devfile_ver[8];
	char e_protocol_ver[8];
	char hw_ver[8];
	char platform[32];
	char basebd_sw_ver[8];
	char basebd_hw_ver[8];
	uplus_u8 basebd_upgrade;
	uplus_u8 offline_cause;
	uplus_u16 strength;
} uwt_rpt_ver_svr_t;

/*UWT_SUB_CMD_UPGRADE*/
typedef struct uwt_update
{
    char file_path[252];
    uplus_u32 ota_tag;
    uplus_u8 file_md5[64];
    uplus_u32 file_len;
} uwt_update_t;

/*UWT_SUB_CMD_CHANGE_DOMAIN*/
typedef struct uwt_change_domain
{
    char domain[64];
	uplus_u32 port;
} uwt_change_domain_t;

/*UWT_SUB_CMD_UPGRADE_START*/
typedef struct uwt_update_start
{
	uplus_u32 upgrade_sn;
	uplus_u32 upgrade_flag;
	uplus_u32 total_len;
	char file_md5[32];
} uwt_update_start_t;

/*UWT_SUB_CMD_UPGRADE_SEGMENT_REQ*/
typedef struct uwt_update_segment_req
{
	uplus_u32 upgrade_sn;
	uplus_u32 segment_offset;
	uplus_u32 segment_len;
} uwt_update_segment_req_t;

/*UWT_SUB_CMD_UPGRADE_SEGMENT_DATA*/
typedef struct uwt_update_segment_data
{
	uplus_u32 upgrade_sn;
	uplus_u32 segment_offset;
	uplus_u32 segment_len;
	uplus_u32 segment_chk_sum;
	/*data*/
} uwt_update_segment_data_t;

/*UWT_SUB_CMD_UPGRADE_COMPLETE*/
typedef struct uwt_update_complete
{
	uplus_u32 upgrade_sn;
} uwt_update_complete_t;

/*UWT_SUB_CMD_DEVICE_EVENT_NOTIFY*/
typedef struct rpt_event
{
	uplus_u32 event;
	char reserved[16];
} rpt_event_t;

typedef struct wifi_info
{
	char ssid[32];
	char ap_mac[8];
	uplus_u16 strength;
	uplus_u16 flag;
} wifi_info_t;

/*UWT_SUB_CMD_WIFI_INFO_REPORT*/
typedef struct rpt_wifi_info
{
	uplus_u32 ap_num;
	/*wifi_info_t*/
}rpt_wifi_info_t;

#pragma pack()

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_UWT_H__*/

