#ifndef __CUSTOM_LOG_H__
#define __CUSTOM_LOG_H__

#include "custom_log_api.h"

#ifdef __cplusplus
extern "C" {
#endif

int init_custom_log(int level, const char *module_name, custom_log_fun log_fun);

custom_log_fun get_log_fun();

const char* get_module_name();

int custom_log_print(int level, const char *fmt, ...);

int custom_log_print_out(const char *fmt, ...);

int custom_vlog_print(const char *fmt, va_list param);

#define TP_STR_HELPER(x) #x
#define TP_STR(x) TP_STR_HELPER(x)

#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#define LOG_PRINT(level, l_tag,  tag , fmt, ...) custom_log_print( level, "[%s][%c][%s %s][%s:line %s] %s : " fmt "\n", tag, l_tag, __DATE__, __TIME__, filename(__FILE__), TP_STR(__LINE__), __FUNCTION__,##__VA_ARGS__)

#define LOG_TAG get_module_name()
#define LOGD(fmt,...) LOG_PRINT(CUSTOM_LOG_DEBUG,  'D', LOG_TAG, fmt, ##__VA_ARGS__)
#define LOGI(fmt,...) LOG_PRINT(CUSTOM_LOG_INFO,   'I', LOG_TAG, fmt, ##__VA_ARGS__)
#define LOGE(fmt,...) LOG_PRINT(CUSTOM_LOG_ERROR,  'E', LOG_TAG, fmt, ##__VA_ARGS__)
#define LOGW(fmt,...) LOG_PRINT(CUSTOM_LOG_WARN,   'W', LOG_TAG, fmt, ##__VA_ARGS__)
#define LOGF(fmt,...) LOG_PRINT(CUSTOM_LOG_FATAL,  'F', LOG_TAG, fmt, ##__VA_ARGS__)


#ifdef __cplusplus
};
#endif

#endif // END __CUSTOM_LOG_H__
