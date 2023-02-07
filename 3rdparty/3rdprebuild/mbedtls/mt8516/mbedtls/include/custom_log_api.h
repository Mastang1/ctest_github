#ifndef __COMMON_DEFINE_H__
#define __COMMON_DEFINE_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * custom log priority values, in increasing order of priority.
 */
typedef enum Custom_Log_Priority {
    /** For internal use only.  */
    CUSTOM_LOG_UNKNOWN = 0,
    /** The default priority, for internal use only.  */
    CUSTOM_LOG_DEFAULT, /* only for SetMinPriority() */
    /** Verbose logging. Should typically be disabled for a release apk. */
    CUSTOM_LOG_VERBOSE,
    /** Debug logging. Should typically be disabled for a release apk. */
    CUSTOM_LOG_DEBUG,
    /** Informational logging. Should typically be disabled for a release apk.*/
    CUSTOM_LOG_INFO,
    /** Warning logging. For use with recoverable failures. */
    CUSTOM_LOG_WARN,
    /** Error logging. For use with unrecoverable failures. */
    CUSTOM_LOG_ERROR,
    /** Fatal logging. For use when aborting. */
    CUSTOM_LOG_FATAL,
    /** For internal use only.  */
    CUSTOM_LOG_SILENT, /* only for SetMinPriority(); must be last */
} Custom_Log_Priority;

typedef int (*custom_log_fun)(const char *fromat, ...);

void custom_log_init(Custom_Log_Priority level, const char *module_name, custom_log_fun func);


#ifdef __cplusplus
};
#endif

#endif    // END __COMMON_DEFINE_H__
