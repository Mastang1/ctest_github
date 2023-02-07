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

#ifndef __UPLUS_API_H__
#define __UPLUS_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/*led*/
#define LED_DEV_STATUS 0x20 /*base board status*/
#define LED_POWER_SAVE 0x10
#define LED_POWER_STATUS 0x8 /*power status*/

#define LED_STATUS_MASK 0x7
#define LED_STATUS_CONFIG 0x7
#define LED_STATUS_NO_WIFI 0x0
#define LED_STATUS_AP_FAIL 0x4
#define LED_STATUS_AP_OK 0x5
#define LED_STATUS_SVR_OK 0x6

/*mutex and queue op*/
#define API_NO_WAIT 0
#define API_WAIT 1

/*socket*/
#define AF_DOMAIN_INET 2
#define AF_DOMAIN_INET6 3

#define SOCK_TYPE_STREAM 1
#define SOCK_TYPE_DGRAM 2

#define IP_PROTO_IP 0
#define IP_PROTO_TCP 6
#define IP_PROTO_UDP 17

#define SO_LEVEL_SOCKET 0
#define SO_LEVEL_IP 1
#define SO_LEVEL_TCP 2
#define SO_LEVEL_UDP 3

#define SO_OPT_KEEPALIVE 1
#define SO_OPT_SNDTIMEO 2
#define SO_OPT_RCVTIMEO 3
#define SO_OPT_BROADCAST 4
#define SO_OPT_REUSEADDR 5 
#define SO_OPT_NONBLOCK 6
#define SO_OPT_SNDBUF 7
#define SO_OPT_RCVBUF 8

/*error*/
#define ERR_OTHERS 1
#define ERR_EAGAIN 2

/*config and image*/
#define ZONE_1 1
#define ZONE_2 2
#define ZONE_OTHER 0
#define OTA_IMAGE_OK 1
#define OTA_IMAGE_FAIL 0

/*net*/
#define DHCP_MODE_NONE 0
#define DHCP_MODE_CLIENT 1
#define DHCP_MODE_SERVER 2

/*wifi*/
#define WIFI_MODE_AP 1
#define WIFI_MODE_STA 2
#define WIFI_MODE_AP_STA 3

/*wifi encrypt*/
#define WIFI_ENCRYPT_AUTH_NONE 0x0
#define WIFI_ENCRYPT_AUTH_WPA_PSK 0x1
#define WIFI_ENCRYPT_AUTH_WPA2_PSK 0x2
#define WIFI_ENCRYPT_AUTH_MASK 0xFFFF

#define WIFI_ENCRYPT_CIPHER_NONE 0x00000
#define WIFI_ENCRYPT_CIPHER_TKIP 0x10000
#define WIFI_ENCRYPT_CIPHER_CCMP 0x20000
#define WIFI_ENCRYPT_CIPHER_WEP 0x40000
#define WIFI_ENCRYPT_CIPHER_MASK 0xFFFF0000

/*wifi network error*/
#define WIFI_NET_CFG_OK 0
#define WIFI_NET_CFG_ERR_GENERAL (-1)
#define WIFI_NET_CFG_ERR_NONE_NETWORK (-2)
#define WIFI_NET_CFG_ERR_CONNECT_FAIL (-3)
#define WIFI_NET_CFG_ERR_AUTH_FAIL (-4)

/*wifi status*/
#define WIFI_DOWN 0
#define WIFI_UP 1

/*wifi extend channel*/
#define WIFI_EXT_CHANNEL_ABOVE 1
#define WIFI_EXT_CHANNEL_BELOW 2
#define WIFI_EXT_CHANNEL_NONE 0

/*op*/
#define OP_SET 1
#define OP_GET 2
#define OP_START 1
#define OP_STOP 2
#define OP_ADD 1
#define OP_DELETE 2

#pragma pack(1)
struct ieee80211_frame
{
	uplus_u8 i_fc[2];
	uplus_u8 i_dur[2];
	uplus_u8 i_addr1[6];
	uplus_u8 i_addr2[6];
	uplus_u8 i_addr3[6];
	uplus_u8 i_seq[2];
};
#pragma pack()

typedef struct
{
    char ssid[32];
	uplus_u8 ap_mac[6];
    uplus_u8 ap_power; 
    uplus_u8 encryption;
    uplus_u16 channel; 
} ap_list_api_t;

/*os api*/
extern int uplus_os_task_create(char * name, uplus_u32 stack_size, uplus_u8 priority, task_func func, void *para, uplus_id *id);
extern int uplus_os_task_delete(uplus_id id);
extern int uplus_os_task_sleep(uplus_u32 delay);
extern int uplus_os_mutex_create(uplus_id *id);
extern int uplus_os_mutex_take(uplus_id id, int wait_op);
extern int uplus_os_mutex_give(uplus_id id);
extern int uplus_os_mutex_delete(uplus_id id);
extern int uplus_os_queue_create(uplus_id *id, uplus_u32 msg_size, uplus_u32 queue_size);
extern int uplus_os_queue_send(uplus_id id, void * msg, uplus_u32 msg_size, int wait_op);
extern int uplus_os_queue_receive(uplus_id id, void * msg, uplus_u32 *msg_size, int wait_op);
extern int uplus_os_queue_delete(uplus_id id);
extern uplus_time uplus_os_current_time_get(void);
extern uplus_time uplus_os_diff_time_cal(uplus_time new_time, uplus_time old_time);

/*tool api*/
#if 0
extern void *uplus_tool_debug_malloc(uplus_u32 num_bytes, char *file, int line);
extern void uplus_tool_debug_free(void *ptr, char *file, int line);
#define uplus_tool_malloc(num_bytes) uplus_tool_debug_malloc(num_bytes, __FILE__, __LINE__)
#define uplus_tool_free(ptr) uplus_tool_debug_free(ptr, __FILE__, __LINE__)
#else
extern void *uplus_tool_malloc(uplus_u32 num_bytes);
extern void uplus_tool_free(void *ptr);
#endif
extern void *uplus_tool_memcpy(void *dest, const void *src, int n);
extern void *uplus_tool_memset(void *s, int ch, int n);
extern int uplus_tool_memcmp(const void *buf1, const void *buf2, int count);
extern int uplus_tool_strncmp(const char *s1 , const char *s2 , int n);
extern char * uplus_tool_strncpy(char * dst0 , const char * src0 , int count);
extern int uplus_tool_strlen(char *s);
extern int uplus_tool_snprintf(char* str, int size, const char* fmt, ...);

extern uplus_u32 uplus_tool_rand(void);
extern void uplus_tool_srand(uplus_u32 seed);
extern int uplus_tool_md5_init(uplus_id *ctx);
extern void uplus_tool_md5_update(uplus_id ctx, uplus_u8 *buf, int len);
extern void uplus_tool_md5_finish(uplus_id ctx, uplus_u8 output[16]);

/*system api*/
extern int uplus_sys_led_control(uplus_u16 led_status_ind);
extern int uplus_sys_watchdog_start(uplus_u32 timeout);
extern void uplus_sys_watchdog_feed(void);
extern int uplus_sys_serial_open(int *fd);
extern int uplus_sys_serial_close(int fd);
extern int uplus_sys_serial_read(int fd, uplus_u8 *buf, uplus_u32 len);
extern int uplus_sys_serial_write(int fd, uplus_u8 *buf, uplus_u32 len);
extern void uplus_sys_system_reset(void);
extern char *uplus_sys_sdk_ver_get(void);
extern int uplus_sys_config_read(uplus_u8 config_zone, uplus_u8 *conf, uplus_u32 len);
extern int uplus_sys_config_write(uplus_u8 config_zone, uplus_u8 *conf, uplus_u32 len);
extern int uplus_sys_run_image_get(uplus_u8 *image_zone);
extern int uplus_sys_image_start(uplus_u8 image_zone);
extern int uplus_sys_image_read(uplus_u8 image_zone, uplus_u32 offset, uplus_u8 *buf, uplus_u32 len);
extern int uplus_sys_image_write(uplus_u8 image_zone, uplus_u32 offset, uplus_u8 *buf, uplus_u32 len);
extern int uplus_sys_image_finish(uplus_u8 image_zone, int result);
extern int uplus_sys_image_switch(uplus_u8 image_zone);
extern int uplus_sys_debug_printf(const char *fmt, ...);
extern int uplus_sys_log(const char *fmt, ...);
extern int uplus_sys_init(void);
extern void uplus_sys_period(void);

/*net api*/
extern int uplus_net_socket_create(int domain, int type, int protocol);
extern int uplus_net_socket_close(int fd);
extern int uplus_net_socket_bind(int sockfd, const struct uplus_sockaddr *addr, int addrlen);
extern int uplus_net_socket_listen(int sockfd, int backlog);
extern int uplus_net_socket_accept(int sockfd, struct uplus_sockaddr *addr, int *addrlen);
extern int uplus_net_socket_opt_set(int sockfd, int level, int optname, const void *optval, uplus_u32 optlen);
extern int uplus_net_socket_connect(int sockfd, const struct uplus_sockaddr *addr, int addrlen);
extern int uplus_net_socket_send(int sockfd, const void *buf, int len, int flags);
extern int uplus_net_socket_sendto(int sockfd, const void *buf, int len, int flags, const struct uplus_sockaddr *addr, int addrlen);
extern int uplus_net_socket_recv(int sockfd, void *buf, int len, int flags);
extern int uplus_net_socket_recvfrom(int sockfd, void *buf, int len, int flags, struct uplus_sockaddr *addr, int *addrlen);
extern uplus_u32 uplus_net_htonl(uplus_u32 hostlong);
extern uplus_u32 uplus_net_ntohl(uplus_u32 netlong);
extern uplus_u16 uplus_net_htons(uplus_u16 hostshort);
extern uplus_u16 uplus_net_ntohs(uplus_u16 netshort);
extern char *uplus_net_inet_ntoa(struct uplus_in_addr in);
extern uplus_u32 uplus_net_inet_addr(const char *cp);
extern int uplus_net_select(int nfds, void *readfds, void *writefds, void *exceptfds, struct uplus_timeval *timeout);
extern void uplus_net_fd_zero(void *set);
extern void uplus_net_fd_clr(int fd, void *set);
extern void uplus_net_fd_set(int fd, void *set);
extern int uplus_net_fd_isset(int fd, void *set);
extern uplus_u32 uplus_net_fd_size(void);
extern int uplus_net_ip_config(uplus_u8 op, char *local_ip_addr, char *net_mask, char *gateway_ip_addr);
extern int uplus_net_dns_config(uplus_u8 op, char *dns_server);
extern int uplus_net_dhcp_config(uplus_u8 op, uplus_u8 mode);
extern int uplus_net_dhcp_pool_set(uplus_u8 op, char *address_pool_start, char *address_pool_end);
extern int uplus_net_dns_request(const char *hostname, char *ip);
extern int uplus_net_ssl_client_open(uplus_id *id, uplus_u8 * rootCABuff, uplus_u32 rootCALen);
extern int uplus_net_ssl_client_bind(uplus_id id, int fd);
extern int uplus_net_ssl_client_close(uplus_id id);
extern int uplus_net_ssl_pending(uplus_id id);
extern int uplus_net_ssl_read(uplus_id id, uplus_u8 *buf, int len);
extern int uplus_net_ssl_write(uplus_id id, uplus_u8 *buf, int len);
extern int uplus_net_last_error_get(void);
extern int uplus_net_hostname_set(const char *hostname);

/*wifi api*/
extern int uplus_wifi_power_on(uplus_u8 wifi_mode);
extern int uplus_wifi_power_off(void);
extern int uplus_wifi_disconnect(void);
extern int uplus_wifi_country_set(char *country_code);
extern int uplus_wifi_sniffer_start(uplus_u8 rssi, void (* func)(uplus_u8 *buf, int length));
extern int uplus_wifi_sniffer_stop(void);
extern int uplus_wifi_channel_set(uplus_u16 channel);
extern int uplus_wifi_sniffer_channel_set(uplus_u16 channel, int ext_channel);
extern int uplus_wifi_scan_start(void);
extern int uplus_wifi_scan_stop(void);
extern int uplus_wifi_ap_list_get(uplus_u8 *ap_number, ap_list_api_t *list);
extern int uplus_wifi_ps_enable(void);
extern int uplus_wifi_ps_disable(void);
extern int uplus_wifi_status_get(uplus_u8 *status, uplus_u8 *wifi_strength);
extern void uplus_wifi_status_callback(uplus_u8 status);
extern int uplus_wifi_mac_get(uplus_u8 *mac);
extern int uplus_wifi_network_set(uplus_u8 wifi_mode, char *wifi_ssid, char *wifi_key, uplus_u16 channel, uplus_u32 encryption);
extern int uplus_wifi_network_get(uplus_u8 wifi_mode, char *wifi_ssid, uplus_u16 *channel, uplus_u32 *encryption);
extern void uplus_wifi_fast_reconnect_clr(void);

#ifdef __cplusplus
}
#endif

#endif /*__UPLUS_API_H__*/

