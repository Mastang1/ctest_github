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

#ifndef __UPLUS_EPP_H__
#define __UPLUS_EPP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*epp command*/
#define EPP_CMD_CTRL               0x01
#define EPP_CMD_STATUS             0x02
#define EPP_CMD_INVALID_CMD        0x03
#define EPP_CMD_ALARM              0x04
#define EPP_CMD_ACK                0x05
#define EPP_CMD_REPORT             0x06
#define EPP_CMD_STOP_ALARM         0x09

#define EPP_CMD_GROUP_EXE          0x60
#define EPP_CMD_DEV_VER            0x61
#define EPP_CMD_DEV_VER_ACK        0x62
#define EPP_CMD_GET_ENCRYPT_KEY    0x63
#define EPP_CMD_SET_ENCRYPT_KEY    0x64
#define EPP_CMD_GROUP_ADDR         0x65

#define EPP_CMD_GET_TYPEID         0x70
#define EPP_CMD_GET_TYPEID_ACK     0x71

#define EPP_CMD_GET_ALARM          0x73
#define EPP_CMD_GET_ALARM_ACK      0x74

#define EPP_CMD_SET_RPT_TIME       0x7c
#define EPP_CMD_SET_RPT_TIME_ACK   0x7d

#define EPP_CMD_SPLIT_DOWN         0x8A
#define EPP_CMD_SPLIT_UP           0x8B

#define EPP_CMD_DEV_DATA_DOWN      0x8c
#define EPP_CMD_DEV_DATA_UP        0x8d

#define EPP_CMD_GET_INFO           0xA0
#define EPP_CMD_GET_INFO_ACK   	   0xA1
#define EPP_CMD_MOD_SSID	       0xA2

#define EPP_CMD_GET_WIFI_STATUS    0xf0
#define EPP_CMD_GET_WIFI_STATUS_ACK 0xf1

#define EPP_CMD_SET_INTO_CONFIG    0xF2
#define EPP_CMD_SET_INTO_CONFIG_ACK 0xF3

#define EPP_CMD_EXIT_CONFIG        0xF4
#define EPP_CMD_EXIT_CONFIG_ACK    0xF5
#define EPP_CMD_RPT_WIFI_STATUS    0xF7
#define EPP_CMD_RESET_CONFIG       0xF8
#define EPP_CMD_ENTER_PRODUCT_TEST 0xF9

#define EPP_CMD_SET_BIGDATA_RPT_TIME      0xFA
#define EPP_CMD_SET_BIGDATA_RPT_TIME_ACK  0xFB

#define EPP_CMD_GET_MANAGEMET_STATE      0xFC
#define EPP_CMD_GET_MANAGEMET_STATE_ACK  0xFD
/*
#define EPP_POS_LEN        2
#define EPP_POS_KEYFLG     3
#define EPP_POS_TYPE       9

#define EPP_POS_VER        10
#define EPP_POS_SUBCMD     11
#define EPP_POS_TOTALCNT   12
#define EPP_POS_NOWCNT     14
#define EPP_POS_DATA       16
*/

#define EPP_SIZE_EXTRA 3 /*2 byte flag_seq + 1 byte len*/
#define EPP_MIN_FRAME_LEN 8 /*6 byte addr + 1 byte cmd + 1 byte checksum*/

#pragma pack(1)
typedef struct epp_frame_header
{
	uplus_u8 flag_sequence[2]; /*0xFF, 0xFF*/
	uplus_u8 epp_frame_len;
	uplus_u8 addr[6];
	uplus_u8 cmd;
} epp_frame_header_t;

typedef struct epp_frame_get_info_ack
{
	char hw_ver[8];
	char sw_ver[8];
	char platform[32];
	char mac[16];
	char server_domain[64];
	uplus_u32 server_port;
	char ssid[32];
	char password[64];
} epp_frame_get_info_ack_t;
#pragma pack()

/*request msg retry*/
#define EPP_DEFAULT_RETRY 3
#define EPP_DEFAULT_ACK_CNT 2

#define STAGE_INIT_TO_CHECK_FLAG_SEQ 0
#define STAGE_FLAG_SEQ_PARTIAL 1
#define STAGE_FLAG_SEQ_OK_TO_CHECK_LEN 2
#define STAGE_LEN_OK_TO_CHECK_ADDR 31
#define STAGE_ADDR_PARTIAL 32
#define STAGE_ADDR_ESCAPE 33
#define STAGE_ADDR_OK_TO_CHECK_DATA 3
#define STAGE_DATA_ESCAPE 4
#define STAGE_CHECKSUM_ESCAPE 5

#define EPP_MAX_TRANSMIT_PKG_BYTES 96
#define EPP_CMD_SPLIT_UP_TIMEOUT 2000

#define WIFI_STATUS_SVR_OK		0x00
#define WIFI_STATUS_DISCONNECT	0x01
#define WIFI_STATUS_AP_OK		0x02
#define WIFI_STATUS_INCONFIG	0x03

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_EPP_H__*/

