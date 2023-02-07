#ifndef __RWS_ANDROID_LOG_H__
#define __RWS_ANDROID_LOG_H__

#include <stdio.h>
#include <stdbool.h>

#ifdef ANDROID
    #include <android/log.h>
    #define LOG_TAG "RWS_ANDROID"
    #define DEBUG
    #define ANDROID_PLATFORM
#endif
 
 
#ifdef ANDROID_PLATFORM
    #define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
    #define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
    #define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))
    #define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))


#else
    #define LOGD(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
    #define LOGI(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
    #define LOGW(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
    #define LOGE(fmt, ...) printf(fmt"\n", ##__VA_ARGS__)
#endif


#endif //__RWS_ANDROID_LOG_H__