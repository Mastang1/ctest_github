#ifndef __DEBUG_LOG_H__
#define __DEBUG_LOG_H__

#ifdef __cplusplus 
extern "C"
{ 
#endif

//make for Android
//#define ANDROID_VERSION

#ifdef ANDROID_VERSION

#include <android/log.h>

#define TAG "soundconnectSDK"
#define DEBUG_DEBUG(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define DEBUG_INFO(fmt, args...) __android_log_print(ANDROID_LOG_INFO, TAG, fmt, ##args)
#define DEBUG_ERROR(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)
#define DEBUG_WARNING(fmt, args...) __android_log_print(ANDROID_LOG_WARN, TAG, fmt, ##args)

//macro for closing all DEBUG information
#define DEBUG_ALLCLOSE

//macro for LOG* ,use macro or function
#define DEBUG_MACRO 
#else
//macro for closing all DEBUG information
//#define DEBUG_ALLCLOSE

//macro for LOG* ,use macro or function
#define DEBUG_MACRO 

#endif

//macro for no LOGD
#define VERSION_RELEASE




#ifdef  DEBUG_ALLCLOSE
#ifdef ANDROID_VERSION
#else

#define DEBUG_ERROR(fmt, args...)  
#define DEBUG_DEBUG(fmt, args...) 
#define DEBUG_WARNING(fmt, args...) 
#define DEBUG_INFO(fmt, args...) 
#endif

#else

#ifdef RaspberryPI_VERSION
#define DEBUG_ERROR(fmt, args...)  printf(fmt,  ##args)
#define DEBUG_DEBUG(fmt, args...)  printf(fmt,  ##args)
#define DEBUG_WARNING(fmt, args...)  printf(fmt,  ##args)
#define DEBUG_INFO(fmt, args...)  printf(fmt,  ##args)
#else
#define DEBUG_ERROR(fmt, args...)  printf("\033[47;31m[error]\033[0m "fmt"\n",  ##args)
#define DEBUG_DEBUG(fmt, args...)  printf("\033[47;30m[debug]\033[0m "fmt"\n",  ##args)
#define DEBUG_WARNING(fmt, args...)  printf("\033[47;33m[warnning]\033[0m "fmt"\n",  ##args)
#define DEBUG_INFO(fmt, args...)  printf("\033[47;32m[info]\033[0m "fmt"\n",  ##args)
#endif

#endif


#ifdef DEBUG_MACRO
#define LOGE(fmt, args...) DEBUG_ERROR(fmt, ##args)
#define LOGD(fmt, args...) DEBUG_DEBUG(fmt, ##args)
#define LOGW(fmt, args...) DEBUG_WARNING(fmt, ##args)
#define LOGI(fmt, args...) DEBUG_INFO(fmt, ##args)
#else

void LOGE(const char * tag, ... );
void LOGW(const char * tag, ... );
void LOGI(const char * tag, ... );

#ifdef VERSION_RELEASE
#define LOGD(fmt, args...)
#else
void LOGD(const char * tag, ... );
#endif

#endif


/*
#define DEBUG_ERROR(fmt, args...)  printf("\033[47;31m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno)
#define DEBUG_DEBUG(fmt, args...)  printf("\033[47;30m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno)
#define DEBUG_WARNING(fmt, args...)  printf("\033[47;33m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno)
#define DEBUG_INFO(fmt, args...)  printf("\033[47;32m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno)
*/

#ifdef __cplusplus 
}
#endif

#endif


