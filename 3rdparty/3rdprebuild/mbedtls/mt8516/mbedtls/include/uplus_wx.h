/*
 * airkiss_pub.h
 *
 *  Created on: 2016年5月26日
 *      Author: hudingxuan
 */

#ifndef __UPLUS_WX_H__
#define __UPLUS_WX_H__

#ifdef __cplusplus
extern "C" {
#endif

#define CONFIG_METHOD_AIRKISS ('A')

extern int uplus_airkiss_start(void);

extern int uplus_airkiss_stop(void);

extern int uplus_airkiss_result_get(uplus_u8 *ssid, uplus_u8 *passwd, uplus_u8 * ext_data, uplus_u8 *ext_data_len);

extern int uplus_airkiss_rcv(uplus_u8 * buf, int length);

extern int uplus_airkiss_ch_sw(void);

extern int uplus_airkiss_ack_build(wifi_config_ack_t *info, uplus_u8 **ack, uplus_u16 *ack_len, struct uplus_sockaddr *addr, int *addrlen);

#ifdef __cplusplus
}
#endif

#endif /* __UPLUS_WX_H__ */
