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

#ifndef __UPLUS_EPP_DEF_H__
#define __UPLUS_EPP_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************/
/*debug, default: off*/
/*#define TEST_EPP_DATA_CONVERT
#define TEST_EPP_RAW_DATA*/

#define UPLUG_SDK_EPP_VERSION "1.0.0"
/******************************************************************/
/*E++ service access*/
#define MAX_EPP_ACCESS_NUM 1

#define uplug_syslog(fmt, ...) \
	uplus_sys_log("%u:"fmt"\n", uplus_os_current_time_get(), ##__VA_ARGS__);

/*resource def*/
/*queue size*/
#define QUEUE_SIZE_EPP_HIGH 5
#define QUEUE_SIZE_EPP_MIDDLE 30
#define QUEUE_SIZE_EPP_LOW 5
#define QUEUE_SIZE_EPP_MAIN 30
#define QUEUE_SIZE_EPP_ACCESS 40

/*task name*/
#define TASK_NAME_EPP "t_epp"
#define TASK_NAME_SERIAL "t_serial"

/*task stack*/
#define TASK_STACK_SIZE_EPP 2048
#define TASK_STACK_SIZE_SERIAL 1024

/*task priority*/
#define TASK_PRIORITY_EPP 2
#define TASK_PRIORITY_SERIAL 1

/*time def*/
#define TIME_MILLISECOND (1)
#define TIME_SECOND (1000 * (TIME_MILLISECOND))
#define TIME_MINUTE (60 * (TIME_SECOND))
#define TIME_HOUR (60 * (TIME_MINUTE))
#define TIME_DAY (24 * (TIME_HOUR))

#define TIME_EPP_WIFI_RPT (10 * (TIME_SECOND))
#define TIMES_EPP_WIFI_RPT_FAIL 3
#define TIME_EPP_WIFI_RPT_DELAY (2 * (TIME_SECOND))
#define TIME_EPP_KEEPALIVE (50 * (TIME_SECOND))
#define TIME_EPP_CHANGE_ENCRYPT (5 * (TIME_DAY)) /*对于E++2.0的设备，定期修改密钥（暂定是5天）*/
#define TIME_EPP_ALARM_RELEASE (13 * (TIME_SECOND)) /*E++1.x系列设备（除E++1.12）, 设备有13秒没有收到报警，认为设备停止报警，报给所有连接*/
#define TIME_EPP_ALARM_QUERY_1 (2 * (TIME_MINUTE)) /*E++2.0设备, 有报警且已经给串口发送停止报警后，模块2分钟向串口查询一次报警*/
#define TIME_EPP_ALARM_QUERY_2 (5 * (TIME_SECOND)) /*E++2.18设备, 有报警且已经给串口发送停止报警后，模块2分钟向串口查询一次报警*/
#define TIME_EPP_STATUS_QUERY_1 (5 * (TIME_SECOND)) /*E++1.x系列设备, 定时检查，5秒没收到02 6d 01或06 6d 01,则查一次状态*/
#define TIME_EPP_STATUS_QUERY_2 (2 * (TIME_MINUTE)) /*对于有汇报功能的设备（E++2.0；E++1.12），如果2分钟串口没有交互数据，模块查询一次状态*/
#define TIME_EPP_BIG_DATA_QUERY (1 * (TIME_MINUTE)) /*E++2.18设备, 由模块查询设备的大数据，对于主从的设备，模块默认60秒左右查询一次*/
#define TIME_EPP_MANAGEMENT_STATUS_QUERY (10 * (TIME_SECOND)) /*E++2.18设备, 管理信息帧定时查询,模块默认10秒左右查询一次*/
#define TIMES_EPP_STATUS_CHECK 3 /*对于有汇报功能的设备（E++2.0；E++1.12），如果连续3次（6分钟）没有串口交互认为串口故障*/
#define TIMES_EPP_STATUS_AC_CONFIG (3) /*空调中，3次检测到开机低风制冷30度，进入配置*/
#define TIME_EPP_CONFIG_PROTECT (30 * (TIME_MINUTE)) /*非出厂状态，空气净化器/空调，上电30分钟内，配置模式保护(只允许进一次配置模式)*/

#define TIME_SERIAL_TX (300 * (TIME_MILLISECOND))
#define TIME_SERIAL_WAIT (5 * (TIME_SECOND))

/*message queue*/
enum msg_queue
{
	QUEUE_EPP_HIGH,
	QUEUE_EPP_MIDDLE,
	QUEUE_EPP_LOW,
	QUEUE_EPP_MAIN,
	MAX_EPP_QUEUE_NUM
};

/*message type*/
enum msg_type
{
	MSG_CTL = 0,
	/*for epp internal*/
	MSG_EPP_REQ,
	MSG_EPP_RSP,
	MSG_EPP_RPT,

	MSG_REQ_FROM_ADAPTER, /*from adapter to E++*/

	MAX_MSG_TYPE_NUM
};

/*message sub type*/
enum msg_sub_type
{
	/*for epp internal, MSG_EPP_REQ*/
	MSG_SUB_EPP_REQ_FROM_APP = 0,
	MSG_SUB_EPP_REQ_FROM_PROTOCOL,
	MSG_SUB_EPP_REQ_FROM_PERIOD,
	MSG_SUB_EPP_REQ_FROM_LOCAL_ACK,

	/*control cmd def*/
	MSG_SUB_CTL_EPP_ERR, /*for CTL_EPP_BASE*/
	MSG_SUB_CTL_EXIT_CONFIG, /*for CTL_EPP_BASE*/
	MSG_SUB_CTL_ENTER_CONFIG, /*for CTL_EPP_BASE*/
	MSG_SUB_CTL_EPP_DEVICE_FAIL, /*for CTL_SERIAL_BASE*/

	CTL_CMD_TYPE_MASK = 0xFF,
	CTL_EPP_BASE = 0x200, /*for epp control*/
	CTL_SERIAL_BASE = 0x300, /*for epp serial control*/
};

/*message common header*/
typedef struct msg_common_header
{
	uplus_u8 type; /*MSG_XXX*/
	uplus_u8 data_is_alloc; /*data is dynamic alloc*/
	uplus_u16 sub_type;
	void * data;
} msg_common_header_t;

/*epp request message*/
typedef struct msg_epp_req
{
	uplus_u8 * session; /*session data*/
	uplus_u16 session_len; /*session len*/
	uplus_u8 * epp; /*epp data*/
	uplus_u16 data_len; /**epp len*/
    uplus_u16 timeout; /*timeout*/
    uplus_u8 retry; /*retry number*/
	uplus_u8 ack_cnt; /*resp cmd cnt*/
	uplus_u8 ack[2]; /*epp resp cmd list*/
} msg_epp_req_t;

/*epp response message*/
typedef struct msg_epp_rsp
{
	uplus_u8 * epp; /*epp data*/
	uplus_u16 data_len; /*all epp len*/
	uplus_u8 backup[2];
	uplus_u32 sn;
	msg_epp_req_t * req; /*response to who*/
} msg_epp_rsp_t;

/*epp report message*/
typedef struct msg_epp_rpt
{
	uplus_u8 * epp; /*epp data*/
	uplus_u16 data_len; /*all epp len*/
	uplus_u8 backup[2];
	uplus_u32 sn;
} msg_epp_rpt_t;

/*request message from app or response message to app*/
typedef struct msg_req_from_adapter
{
	uplus_u8 * session; /*session data*/
	uplus_u16 session_len; /*session len*/
	uplus_u8 * data; /*request/response data, epp_frame_header_t*/
	uplus_u16 data_len; /*request/response data len*/
	uplus_u8 device_protocol; /*DEVICE_PROTO_FAMILY_XXX*/
	uplus_u8 instance;
	uplus_u8 data_type; /*DATA_TYPE_XXX*/
} msg_req_from_adapter_t;

typedef void (*msg_handler_func)(msg_common_header_t *msg, void *para);

/*epp version, indicated by numeric*/
#define EPP_VERSION_MAJOR(mj_ver) ((mj_ver) << 8)
#define EPP_VERSION_MIDDLE(mid_ver) ((mid_ver) << 4)
#define EPP_VERSION_MINOR(mn_ver) (mn_ver)
#define GET_EPP_VERSION_MAJOR(epp_ver) ((epp_ver) & 0xFFFFFF00)
#define GET_EPP_VERSION_MIDDLE(epp_ver) ((epp_ver) & 0xF0)
#define GET_EPP_VERSION_MINOR(epp_ver) ((epp_ver) & 0xF)
#define BUILD_EPP_VERSION(mj_ver, mid_ver, mn_ver) (EPP_VERSION_MAJOR(mj_ver) + EPP_VERSION_MIDDLE(mid_ver) + EPP_VERSION_MINOR(mn_ver))
#define EPP_VERSION_1_00 (BUILD_EPP_VERSION(1, 0, 0))
#define EPP_VERSION_1_12 (BUILD_EPP_VERSION(1, 1, 2))
#define EPP_VERSION_1_20 (BUILD_EPP_VERSION(1, 2, 0))
#define EPP_VERSION_2_14 (BUILD_EPP_VERSION(2, 1, 4))
#define EPP_VERSION_2_15 (BUILD_EPP_VERSION(2, 1, 5))
#define EPP_VERSION_2_17 (BUILD_EPP_VERSION(2, 1, 7))
#define EPP_VERSION_2_18 (BUILD_EPP_VERSION(2, 1, 8))

enum device_state
{
	DEVICE_STATE_INIT = 0,
	DEVICE_STATE_VER,
	DEVICE_STATE_ENCRYPT,
	DEVICE_STATE_TYPEID,
	DEVICE_STATE_STATUS,
	DEVICE_STATE_ALARM,
	DEVICE_STATE_RUN, /*OK state*/
	DEVICE_STATE_ERROR
};

/*basic device info*/
typedef struct epp_device_info
{
	uplus_u32 epp_ver; /*EPP_VERSION_XXX*/
	uplus_u8 epp_ver_str[8];
	uplus_u8 type_id[32];
	uplus_u8 sw_ver[8];
	uplus_u8 hw_ver[8];
	uplus_u8 type; /*device type DEVICE_TYPE_XXX*/
	uplus_u8 state; /*DEVICE_STATE_XXX*/
    uplus_u8 ucCommunicationMode;//通讯方式0x00(交互模式), 0x01(主从模式)
    uplus_u8 aucSoftapDeviceName[8];//Softap配置模式时的设备名称
} epp_device_info_t;

#define EPP_FRAME_LEN  257//254 + 3

typedef struct epp_handshake_flags
{
    uplus_u8 flag_receive_verack;/*0 -- no ack   1 --receive right ack   2 -- ack cmd is 03*/
    uplus_u8 flag_receive_typeidack; /*0 -- no ack   1 --receive right ack   2 -- ack cmd is 03*/
}epp_handshake_flags_t;

struct uplug_epp;

/*epp device control block*/
typedef struct epp_device
{
	epp_device_info_t dev_info; /*device info*/

	uplus_u16 epp_down_sn;
	uplus_u8 encrypt; /*1-encrypt 0-not encrypt*/
	uplus_u8 stop_alarm; 
	uplus_u8 alarm[EPP_FRAME_LEN]; /*last rcved alarm*/
	uplus_u16 alarm_len; /*length of last rcved alarm*/
	uplus_u8 status[EPP_FRAME_LEN]; /*last rcved status*/
	uplus_u16 status_len; /*length of last rcved status*/

	uplus_u8 stage; /*解析E++报文上下文, STAGE_XXX*/
	uplus_u8 partial_frame_len; /*解析E++报文上下文*/
	uplus_u8 chksum; /*解析E++报文上下文*/
	uplus_u8 encryptflg; /*解析E++报文上下文*/

	uplus_u8 wifi_status; /*WIFI_STATUS_XXX, from state*/
	uplus_u8 wifi_rssi; /*copy from wifi.wifi_rssi*/

	/*encrypt para*/
	uplus_u8 epp_encrypt_key_len; /*length of epp encrypt key*/
	uplus_u8 epp_encrypt_key_index; /*index of epp encrypt key in key table*/

	/*times*/
	uplus_u8 times_wifi_rpt_fail; /*TIMES_EPP_WIFI_RPT_FAIL*/
	uplus_u8 times_ac_status_rpt_config; /*TIMES_EPP_STATUS_AC_CONFIG*/
	uplus_u32 times_epp_status_check; /*TIMES_EPP_STATUS_CHECK, must not use uplus_u8, may be exceed the max value*/

	/*timer*/
	uplus_time time_epp_wifi_rpt; /*EPP设备keep alive定时器, TIME_EPP_WIFI_RPT*/
	uplus_time time_last_recv; /*last time recv device data*/
    uplus_time time_last_ack_recv; /*last time recv uart ack, TIME_EPP_KEEPALIVE*/
	uplus_time time_last_alarm_recv; /*last time recv alarm data, 报警解除定时器，TIME_EPP_ALARM_RELEASE*/
	uplus_time time_last_status_recv; /*last time recv status data*/
	uplus_time time_epp_alarm_query; /*报警查询定时器, TIME_EPP_ALARM_QUERY*/
	uplus_time time_epp_status_query; /*状态查询定时器, TIME_EPP_STATUS_QUERY_X*/
    uplus_time time_epp_management_status_query; /*管理信息帧定时查询定时器, EPP_CMD_GET_MANAGEMET_STATE*/
    uplus_time time_epp_big_data_query; /*E++2.18设备, 由模块查询设备的大数据，对于主从的设备，模块默认60秒左右查询一次*/
	uplus_time time_epp_change_encrypt; /*修改EPP加密参数定时器， TIME_EPP_CHANGE_ENCRYPT*/
    uplus_time time_last_cfg_recv; /*last time recv into config or quit config, TIME_EPP_WIFI_RPT_DELAY*/

	/*如果模块配置过，上电后，进配置模式，只能进一次，要想再进入配置，要断电重启设备*/
	uplus_u8 enter_cfg_config;/*0 -- not in config mode    1 -- in config mode*/
	/**/
	uplus_u8 aip_status_rpt_enetr_config;/* 0 -- not enter config mode  1 -- enter config mode*/
	uplus_u8 aic_rcv_status_report; /**/
	uplus_u8 uart_status_flag; /*0 -- normal  1 -- abnormal */
    uplus_u8 epp_big_data_flag;
	struct epp_handshake_flags handshake_flags;  

	/*register to adapter*/
	adapter_control_info_t adapter_info;
	uplus_u8 adapter_registered;

	/*for support cmd F2/F4*/
	uplus_u8 is_in_cfg_mode;

	struct uplug_epp *uplug_epp;
} epp_device_t;

#define SERIAL_BUF_LEN 260

/*serail device control block*/
typedef struct serial_device
{
	void *epp_access_ctl; /*point to gv_uplug_common->epp_access*/

	/*for rx*/
	uplus_u8 rxbuf[SERIAL_BUF_LEN]; /*rx buf, may involve a few epp cmds or partial cmd*/
	uplus_u8 pktbuf[SERIAL_BUF_LEN]; /*packet buf, a whole epp cmd*/
	uplus_u16 offset; /*end of valid data in rx_buf*/
	uplus_u16 epp_up_sn;

	/*for tx*/
	msg_epp_req_t * req; /*epp request cmd*/
	uplus_u8 retry; /*current retry*/
	uplus_u8 err_cnt;
	uplus_u8 wait;
	uplus_time time_last_tx; /*发送间隔定时器, TIME_SERIAL_TX*/

	struct uplug_epp *uplug_epp;
} serial_device_t;

#define CONF_VALID_FLAG 0x12
/*config E++ data stucture*/
typedef struct conf_epp_data
{
	/*epp device 96 octets*/
	uplus_u16 rpt_time;
	uplus_u16 big_data_rpt_time;
	uplus_u8 encryption; /*1-encrypt 0-not encrypt, default 0*/
	/*device info*/
	uplus_u8 dev_info_valid; /*CONF_VALID_FLAG-indicate dev info config is valid*/
	uplus_u8 backup[2];
	uplus_u8 epp_ver_str[8];
	uplus_u8 type_id[32];
	uplus_u8 sw_ver[8];
	uplus_u8 hw_ver[8];
	uplus_u8 res_epp[32]; /*reserved*/
} conf_epp_data_t;

/*E++ common structure*/
typedef struct uplug_epp
{
	uplus_time time_init; /*TIME_EPP_CONFIG_PROTECT/TIME_SERIAL_WAIT*/

	conf_epp_data_t conf;

	/*epp device control block*/
	epp_device_t dev;

	/*serial device control block*/
	serial_device_t serial;
} uplug_epp_t;

/*epp access control block*/
typedef struct epp_access_control
{
	uplus_u8 used; /*1-used, 0-not used*/
	uplus_u8 valid; /*1-valid, 0-invalid*/
	uplus_u8 index; /*index, 0 based*/

	/*for msg*/
	uplus_id queue; /*queue*/
	uplus_u8 *last_buf; /*rx buf*/
	uplus_u16 res; /*reserved/not proessed bytes in last_buf*/
	uplus_u16 pos; /*current position in last_buf*/

	/*for serial & tcp client*/
	int fd[2]; /*for tcp client, only fd[0] is used; for serial, fd[0] for read, fd[1] for write*/
	void * fd_set_read; /*fd set*/

	epp_access_control_info_t info; /*registered info*/
} epp_access_control_t;

/*common data, eg, queue,mutex*/
typedef struct uplug_epp_common
{
	/*queue*/
	uplus_id queue[MAX_EPP_QUEUE_NUM];
	epp_access_control_t epp_access[MAX_EPP_ACCESS_NUM]; /*E++ acess*/

	/*config*/
	device_class_type_t device_class;
} uplug_epp_common_t;

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_EPP_DEF_H__*/

