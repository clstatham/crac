#ifndef CRAC_LOG_H_INCLUDED
#define CRAC_LOG_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdio.h>
#include "common.h"


typedef enum {
  CRAC_LOG_LEVEL_TRACE,
  CRAC_LOG_LEVEL_DEBUG,
  CRAC_LOG_LEVEL_INFO,
  CRAC_LOG_LEVEL_WARN,
  CRAC_LOG_LEVEL_ERROR
} crac_log_level_t;

CRAC_INLINE void crac_log_level(crac_log_level_t level, ccharptr fmt, ...) {
  va_list args;
  va_start(args, fmt);
  switch (level) {
    case CRAC_LOG_LEVEL_TRACE:
      printf("[TRACE] ");
      break;
    case CRAC_LOG_LEVEL_DEBUG:
      printf("[DEBUG] ");
      break;
    case CRAC_LOG_LEVEL_INFO:
      printf("[INFO]  ");
      break;
    case CRAC_LOG_LEVEL_WARN:
      printf("[WARN]  ");
      break;
    case CRAC_LOG_LEVEL_ERROR:
      printf("[ERROR] ");
      break;
    default:
      break;
  }
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}

#define crac_log_trace(msg) crac_log_level(CRAC_LOG_LEVEL_TRACE, msg)
#define crac_log_debug(msg) crac_log_level(CRAC_LOG_LEVEL_DEBUG, msg)
#define crac_log_info(msg) crac_log_level(CRAC_LOG_LEVEL_INFO, msg)
#define crac_log_warn(msg) crac_log_level(CRAC_LOG_LEVEL_WARN, msg)
#define crac_log_error(msg) crac_log_level(CRAC_LOG_LEVEL_ERROR, msg)

#ifdef __cplusplus
}
#endif

#endif  // CRAC_LOG_H_INCLUDED
