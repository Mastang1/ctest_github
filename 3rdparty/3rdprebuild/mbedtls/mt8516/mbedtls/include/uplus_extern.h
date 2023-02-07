/*******************************************************************************
* Copyright (c) 2015-2016 Haier uHome uBic. All Rights Reserved. 
* No part of this publication may be reproduced, transmitted, transcribed, 
* stored in a retrieval system, or translated into any language in any form 
* or by any means without the written permission of Haier uHome uBic, 
* or its suppliers or affiliate companies. To obtain this permission, 
* write to the attentionof the Haier uHome uBic legal department.
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

#ifndef __UPLUS_EXTERN_H__
#define __UPLUS_EXTERN_H__

#include "uplus_type.h"
#include "uplus_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*device protoco*/
#define DEVICE_PROTO_FAMILY_EPP ('E')

/*protocol family*/
#define PROTO_FAMILY_UNKNOWN (0)
#define PROTO_FAMILY_UPLUS ('U')
#define PROTO_FAMILY_UPLUS_UWT PROTO_FAMILY_UPLUS
#define PROTO_FAMILY_UPLUS_CAE PROTO_FAMILY_UPLUS
#define PROTO_FAMILY_XXX ('X')

/*****************************************************************************/
/*for device protocol adapter*/
enum data_type
{
	DATA_TYPE_EPP = 0x1,
	DATA_TYPE_JSON = 0x2,
	DATA_TYPE_RAW = 0x4, /*not supported*/
	DATA_TYPE_EPP_RAW = 0x8
};

/*req info*/
typedef struct req_session
{
	uplus_u8 protocol; /*PROTO_FAMILY_XXX*/
	uplus_u8 backup[3];
	uplus_u32 session; 
	uplus_u32 sn;
	uplus_time stamp; /*stamp when the session is created, used to verify session*/
} req_session_t;

enum std_dev_op_method
{
	/*the following defs for standard device, DATA_TYPE_JSON*/
	OP_DATA_FLAT = 0x10,
	OP_DATA_STRPAIR = 0x20,

	/*up & down*/
	OP_METHOD_DATA = OP_DATA_FLAT,
	OP_METHOD_SERVICE,

	/*down*/
	OP_METHOD_READ = OP_DATA_STRPAIR,
	OP_METHOD_WRITE,
	OP_METHOD_OP,
	/*up*/
	OP_METHOD_RSP_READ,
	OP_METHOD_RSP_WRITE,
	OP_METHOD_RSP_OP,
	OP_METHOD_RPT_STATUS,
	OP_METHOD_RPT_ALARM,
};

enum ext_dev_epp_raw_data
{
	EPP_RAW_DATA_NULL = 0, /*must be 0*/

	EPP_RAW_DATA_CTRL, /*read/write*/
	EPP_RAW_DATA_GROUP, /*op*/
	EPP_RAW_DATA_ALARM_GET,
	EPP_RAW_DATA_ALARM_STOP,

	EPP_RAW_DATA_STATUS,
	EPP_RAW_DATA_ALARM,
	EPP_RAW_DATA_BIGDATA,
	EPP_RAW_DATA_ACK_OK,
	EPP_RAW_DATA_ACK_NG
};

struct data_info;
typedef void (* data_free)(struct data_info * data);

/*data info*/
typedef struct data_info
{
	uplus_u8 data_type; /*DATA_TYPE_XXX*/
	data_free free; /*free data*/
	union
	{
		struct std_dev_data
		{
			uplus_u8 * data; /*must be global pointer, uplus_u8 * OP_METHOD_DATA/OP_METHOD_SERVICE, others cae_strpair_list_t**/
			uplus_u16 data_len; /*for OP_DATA_FLAT*/
			uplus_u8 op_method; /*OP_METHOD_XXX*/
			uplus_u8 *op_para; /*must be global pointer, only for OP_METHOD_OP/OP_METHOD_DATA/OP_METHOD_SERVICE, string*/
		}std;
		struct ext_dev_data
		{
			uplus_u8 * data; /*must be global pointer*/
			uplus_u16 data_len;
			uplus_u8 epp_raw_data_type; /*only for DATA_TYPE_EPP_RAW, EPP_RAW_DATA_XXX*/
		}ext;
	}data;
} data_info_t;

/*data structure for data exchange between service and adapter*/
typedef struct service_data_info
{
	uplus_u8 device_protocol;
	uplus_u8 instance;

	uplus_u8 is_rsp; /*is a response data, for service to adapter*/
	uplus_u8 dummy;
	uplus_u32 rsp_result;
	data_info_t data;
	req_session_t req;
} service_data_info_t;

/*dev type*/
#define DEVICE_TYPE_RFR 1 /*refrigerator*/
#define DEVICE_TYPE_SAC 2 /*split air conditioner*/
#define DEVICE_TYPE_AC 3 /*air conditioner*/
#define DEVICE_TYPE_PWM 4 /*pulsator washing machine*/
#define DEVICE_TYPE_WM 5 /*washing machine*/
#define DEVICE_TYPE_EWH 6 /*electric water heater*/
#define DEVICE_TYPE_MWO 7 /*micro-wave oven*/
#define DEVICE_TYPE_CELL 8 /*cellarette*/
#define DEVICE_TYPE_RH 9 /*range hood*/
#define DEVICE_TYPE_DW 10 /*dish washer*/
#define DEVICE_TYPE_DTC 11 /*disinfecting tableware cabinet*/
#define DEVICE_TYPE_BAC 13 /*business air conditioner*/
#define DEVICE_TYPE_TV 14 /*television*/
#define DEVICE_TYPE_ETM 15 /*entertainment equipment*/
#define DEVICE_TYPE_LIGHT 16 /*light*/
#define DEVICE_TYPE_SECU 17 /*security precaution*/
#define DEVICE_TYPE_VM 18 /*video monitor*/
#define DEVICE_TYPE_SEN 19 /*sensor*/
#define DEVICE_TYPE_SH 20 /*smart home*/
#define DEVICE_TYPE_HC 21 /*health care*/
#define DEVICE_TYPE_IC 22 /*ice box*/
#define DEVICE_TYPE_MED 23 /*medical cabinet*/
#define DEVICE_TYPE_GWH 24 /*gas water heater*/
#define DEVICE_TYPE_BWH 25 /*boiler water heater*/
#define DEVICE_TYPE_SO 26 /*steam box*/
#define DEVICE_TYPE_CM 27 /*coffee machine*/
#define DEVICE_TYPE_WD 28 /*water dispenser*/
#define DEVICE_TYPE_CU 29 /*cooking utensils*/
#define DEVICE_TYPE_OV 30 /*oven*/
#define DEVICE_TYPE_SWH 31 /*solar water heater*/
#define DEVICE_TYPE_HWH 32 /*heat pump water heater*/
#define DEVICE_TYPE_AIC 33 /*air cleaner*/
#define DEVICE_TYPE_WP 34 /*water purifier*/
#define DEVICE_TYPE_KT 35 /*kettle*/
#define DEVICE_TYPE_ACB 51 /*air cube*/
#define DEVICE_TYPE_RU 225 /*router*/
#define DEVICE_TYPE_CT 241 /*control terminal*/

/*device info*/
typedef struct {
	uplus_u32 type; /*device type DEVICE_TYPE_XXX*/
	char dev_id[32]; /*unique device id*/
	char proto_ver[16]; /*protocol ver*/
	char sw_ver[16]; /*device sw version*/
	char hw_ver[16]; /*device hw version*/
} dev_info_t;

struct adapter_control_info;
typedef int (* data_convert)(struct adapter_control_info *adapter_ctl_info, 
	data_info_t * src_data, data_info_t * dst_data);
typedef int (* data_tx)(struct adapter_control_info *adapter_ctl_info, service_data_info_t *service_data_info);

enum device_protocol_ctrl_cmd
{
	/*0 based*/
	DEVICE_PROTOCOL_CTRL_CONFIG_STATUS = 0, /*val : uplus_u8 **/
	MAX_DEVICE_PROTOCOL_CTRL_NUM
};
typedef int (*device_protocol_ctrl_func)(struct adapter_control_info *adapter_ctl_info, int ctrl_type, void *val);

#define MAX_ACCESS_PROTOCOL_NUMBER 4

/*adpater protocol info*/
typedef struct adapter_control_info
{
	uplus_u8 device_protocol; /*any char, but diff for diffent device protocol, 'E' is reserved for E++*/
	uplus_u8 instance; /*indicate different instance*/
	uplus_u8 data_type; /*DATA_TYPE_XXX*/

	uplus_u8 protocol_number; /*must not be zero*/
	uplus_u8 protocol[MAX_ACCESS_PROTOCOL_NUMBER]; /*see protocol_control_info_t.protocol*/
	uplus_u8 protocol_data_type[MAX_ACCESS_PROTOCOL_NUMBER]; /*DATA_TYPE_XXX*/

	void *ctl_para; /*can be passed to func*/
	dev_info_t *dev_info; /*must be valid*/

	/*func*/
	data_convert convert; /*convert data format, src_data is consumed*/
	data_tx tx; /*tx to service, service_data_info.data is consumed*/
	device_protocol_ctrl_func ctrl;
} adapter_control_info_t;

/*adapter*/
extern int uplus_adapter_tx_data_from_service_to_adapter(service_data_info_t *service_data_info);
extern int uplus_adapter_register(adapter_control_info_t *adapter_ctl_info);
extern int uplus_adapter_set_default_dev(dev_info_t *default_dev_info);
/*set default dev name*/
extern int uplus_adapter_set_default_dev_name(const uplus_u8 default_dev_name[8], uplus_u8 is_clr);

/*****************************************************************************/

/*****************************************************************************/
/*for protocol*/
/*data structure for data from protocol to adapter*/
typedef struct protocol_data_info
{
	uplus_u8 protocol; /*see protocol_control_info_t.protocol*/
	uplus_u8 device_protocol; /*see adapter_control_info_t.device_protocol*/
	uplus_u8 instance;

	req_session_t req; /*req info*/
	data_info_t data; /*data*/
} protocol_data_info_t;

struct protocol_control_info;
typedef int (*protocol_data_func)(struct protocol_control_info * protocol_ctl_info, protocol_data_info_t *protocol_data_info);

enum protocol_ctrl_cmd
{
	/*0 based*/
	PROTOCOL_CTRL_DEV = 0, /*val : adapter_control_info_t **/
	PROTOCOL_CTRL_WORK_STATUS, /*set work status, 1-enter work, 0-exit work, val : uplus_u8 **/
	MAX_PROTOCOL_CTRL_NUM
};
typedef int (*protocol_ctrl_func)(struct protocol_control_info * protocol_ctl_info, int ctrl_type, void *val);

/*protocol info*/
typedef struct protocol_control_info
{
	uplus_u8 protocol; /*any char, but diff for diffent protocol, 'U' is reserved for U+*/

	void *ctl_para; /*can be passed to func*/

	protocol_data_func response_rx; /*protocol_data_info.data is consumed*/
	protocol_data_func report_rx; /*protocol_data_info.data is consumed*/
	protocol_ctrl_func ctrl;
} protocol_control_info_t;

/*protocol*/
extern int uplus_protocol_register(protocol_control_info_t *protocol_ctl_info);
extern int uplus_protocol_tx_data_from_protocol_to_adapter(protocol_data_info_t *protocol_data_info);
extern void uplus_protocol_rcv(uplus_u8 protocol);
extern void uplus_protocol_ctrl_check(uplus_u8 protocol);
/*****************************************************************************/

/*****************************************************************************/
/*for E++ access*/
enum epp_access_method
{
	EPP_ACCESS_METHOD_SERIAL = 0, /*using serial fd + select*/
	EPP_ACCESS_METHOD_MSG, /*using queue + polling*/
	EPP_ACCESS_METHOD_TCP_CLIENT, /*using tcp client + select*/
	EPP_ACCESS_METHOD_MAX
};

typedef int (*epp_tx)(void *ctl_para, uplus_u8 *buf, uplus_u32 len);

typedef enum device_class_type
{
	DEVICE_CLASS_GENERAL = 0,
	DEVICE_CLASS_AC
} device_class_type_t;

/*E++ access info*/
typedef struct epp_access_control_info
{
	uplus_u8 instance;
	uplus_u8 access_method; /*EPP_ACCESS_METHOD_XXX*/

	char dev_name[32]; /*for tcp client, this is server address*/
	uplus_u32 info; /*for tcp client, this is server port*/

	void *ctl_para;
	epp_tx tx; /*for msg*/
} epp_access_control_info_t;

/*E++*/
extern int uplus_epp_init(device_class_type_t device_class);

/*E++ access*/
extern int uplus_epp_access_register(epp_access_control_info_t *epp_access_ctl_info);
extern int uplus_epp_access_tx_data(uplus_u8 instance, uplus_u8 *buf, uplus_u32 len); /*for EPP_ACCESS_METHOD_MSG*/
/*****************************************************************************/

/*****************************************************************************/
/*for dynamic config para*/
/*config*/
typedef void (*op_conf_func)(uplus_u8 *conf);

extern int uplus_conf_set(uplus_u8 ext_block_index, uplus_u8 *conf, uplus_u16 conf_len);
extern int uplus_conf_get(uplus_u8 ext_block_index, uplus_u8 *conf, uplus_u16 conf_len);
extern int uplus_conf_clr_set(uplus_u8 ext_block_index, op_conf_func clr);
/*****************************************************************************/

/*****************************************************************************/
/*for info get*/
/*basic info*/
typedef struct module_base_info
{
	char hw_ver[16];
	char sw_ver[16];
	char platform[32];
	char mac[16];
	char server_domain[64];
	uplus_u16 server_port;
	char ip_addr[16];
} module_base_info_t;

/*wifi info*/
typedef struct module_wifi_info
{
	uplus_u8 ssid_valid;
	char ssid[32];
	char password[64];
} module_wifi_info_t;

/*status info*/
typedef struct module_status_info
{
	uplus_u16 led_control;
	uplus_u8 wifi_rssi;
	uplus_u8 cfg_mode; /*CONFIG_MODE_XXX*/
} module_status_info_t;

typedef enum module_info_type
{
	MODULE_INFO_TYPE_BASE, /*module_base_info_t*/
	MODULE_INFO_TYPE_WIFI, /*module_wifi_info_t*/
	MODULE_INFO_TYPE_STATUS /*module_status_info_t*/
} module_info_type_t;

extern const char *uplus_sdk_ver_get(void);
extern void uplus_sdk_info_get(module_info_type_t info_type, void *info);
/*****************************************************************************/

/*****************************************************************************/
/*for state event notify*/
/*event notify, clear user config*/
extern int uplus_state_event_clr_user_config(void);
/*event notify, enter product*/
extern int uplus_state_event_enter_product(void);
/*event notify, module reset*/
extern int uplus_state_event_module_reset(void);
/*****************************************************************************/

/*****************************************************************************/
/*for init*/
typedef struct config_para
{
	uplus_u8 vendor_id[16]; /*vendor id, "haier"*/

	uplus_u8 hw_ver[16]; /*硬件版本*/
	uplus_u8 sw_ver[16]; /*软件版本*/
	uplus_u8 platform[32]; /*平台*/

	uplus_u8 sdk_ver[16]; /*SDK version*/
	uplus_u8 sdk_platform[32]; /*SDK platform*/

	uplus_u8 max_client_num; /*max client can be accessed, 1~16*/
	uplus_u8 conf_extend_block_num; /*extend config block, 0~3*/
	uplus_u8 long_config_time; /*config time, 1-30 minutes or 0-10 minutes*/
	uplus_u8 long_led_time; /*led power save time, 1-1 hour or 0-5 minutes*/

	/*next for smartlink config*/
	uplus_u8 smartlink_to_softap; /*support smartlink state transit to softap state*/
	uplus_u8 smartlink_promisc_softap; /*support promisc + softap*/
	uplus_u8 smartlink_method_num; /*smartlink method*/
} config_para_t;

/*U+ common*/
extern int uplus_init(config_para_t * config);
/*protocol xxx*/
extern int uplus_xxx_init(void);
/*****************************************************************************/

/*****************************************************************************/
/*for wifi config*/
typedef enum config_mode
{
	CONFIG_MODE_NONE = 0, /*only used for none config*/
	CONFIG_MODE_SMARTLINK,
	CONFIG_MODE_SOFTAP,
	CONFIG_MODE_OTHERS
} config_mode_t;

#define SNIFFER_RCV_NG -1
#define SNIFFER_RCV_CHANNEL_LOCKED 0
#define SNIFFER_RCV_OK 1

/*result_analysis*/
#define EXT_DATA_TYPE_CHANNEL 0 /*uplus_u16*/
#define EXT_DATA_TYPE_ENCRYPT 1 /*uplus_u32, WIFI_ENCRYPT_XXX*/

typedef struct
{
	char *mac;
	char *ip_addr;
	char *ip_broadcast_addr;
	dev_info_t *dev_info;
	uplus_u8 * ext_data;
	uplus_u8 ext_data_len;
	uplus_u8 *ssid;
	uplus_u8 *passwd;
} wifi_config_ack_t;

typedef int (*wifi_config)(void);
typedef int (*wifi_config_result_get)(uplus_u8 *ssid, uplus_u8 *passwd, uplus_u8 * ext_data, uplus_u8 *ext_data_len);
typedef int (*wifi_config_result_analysis)(uplus_u8 * ext_data, uplus_u16 ext_data_type, void *out_val);
typedef int (*wifi_sniffer_rcv)(uplus_u8 * buf, int length);
typedef int (*wifi_sniffer_locked_channel_get)(uplus_u16 *cur_channel, uplus_u8 *ext_channel);
typedef int (*wifi_config_ack_build)(wifi_config_ack_t *info, uplus_u8 **ack, uplus_u16 *ack_len, struct uplus_sockaddr *addr, int *addrlen);

#define CONFIG_METHOD_ALL (0)
#define CONFIG_METHOD_UPLUS ('U')

typedef struct wifi_config_info
{
	uplus_u8 cfg_mode; /*CONFIG_MODE_XXX*/
	uplus_u8 method; /*any char, but diff for diffent protocol, 'U' is reserved for U+, CONFIG_METHOD_UPLUS*/
	uplus_u8 method_name[4]; /*method name, max 3 chars*/
	uplus_u32 channel_locked_time; /*max channel locked time, unit: second*/

	wifi_config start; /*start config, option*/
	wifi_config stop; /*stop config, option*/
	wifi_config_result_get result_get; /*get config result, mandatory*/
	wifi_config_result_analysis ext_analysis; /*analysis ext data, option*/
	wifi_config ch_sw; /*channel switched, only for CONFIG_MODE_SMARTLINK, option*/
	wifi_sniffer_rcv rcv; /*only for CONFIG_MODE_SMARTLINK, mandatory*/
	wifi_sniffer_locked_channel_get locked_ch_get; /*only for CONFIG_MODE_SMARTLINK, option*/
	wifi_config_ack_build ack_build; /*only for CONFIG_MODE_SMARTLINK, option*/
} wifi_config_info_t;

/*third config*/
extern int uplus_config_other_enter(uplus_u32 config_time);
/*exit third config*/
extern int uplus_config_other_exit(int is_ok, const uplus_u8 ssid[32], const uplus_u8 passwd[64]);

/*trigger enter smartlink config*/
extern int uplus_config_smartlink_enter(uplus_u8 method);
/*trigger enter softap config*/
extern int uplus_config_softap_enter(void);
/*trigger to enter smartlink to softap config state*/
extern int uplus_config_smartlink_softap_enter(uplus_u8 method);
/*trigger exit config*/
extern int uplus_config_exit(void);

/*config register*/
extern int uplus_config_smartlink_register(wifi_config_info_t *info);

/*notify the result*/
extern int uplus_config_notify(const uplus_u8 ssid[32], const uplus_u8 passwd[64]);

/*U+ smartlink config API*/
extern int uplus_smartlink_ch_sw(void);
extern int uplus_smartlink_rcv(uplus_u8 * buf, int length);
extern int uplus_smartlink_start(void);
extern int uplus_smartlink_stop(void);
extern int uplus_smartlink_result_get(uplus_u8 *ssid, uplus_u8 *passwd, uplus_u8 * ext_data, uplus_u8 *ext_data_len);
extern int uplus_smartlink_locked_ch_get(uplus_u16 *cur_channel, uplus_u8 *ext_channel);
extern int uplus_smartlink_ack_build(wifi_config_ack_t *info, uplus_u8 **ack, uplus_u16 *ack_len, struct uplus_sockaddr *addr, int *addrlen);

/*****************************************************************************/

/*****************************************************************************/
/*for ota config*/
typedef int (*ota_check)(void *para, uplus_u8 *buf, uplus_u32 len, uplus_u8 force_upgrade);
extern int uplus_ota_register_check(ota_check check, void *para, uplus_u32 offset, uplus_u32 len);
/*****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_EXTERN_H__*/

