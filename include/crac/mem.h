#ifndef CRAC_MEM_H_INCLUDED
#define CRAC_MEM_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#define crac_malloc(size) malloc(size)
#define crac_calloc(count, size) calloc(count, size)
#define crac_realloc(ptr, size) realloc(ptr, size)
#define crac_alloc(type) ((type*)malloc(sizeof(type)))
#define crac_new(type, ...) \
  ((type*)memcpy(malloc(sizeof(type)), &(type){__VA_ARGS__}, sizeof(type)))
#define crac_free(ptr) \
  do {                 \
    free(ptr);         \
    ptr = NULL;        \
  } while (0)
#define crac_memcpy(dest, src, len) memcpy(dest, src, len)
#define crac_memset(ptr, value, len) memset(ptr, value, len)
#define crac_memzero(ptr, len) memset(ptr, 0, len)
#define crac_memzero_struct(ptr) memset(ptr, 0, sizeof(*ptr))
#define crac_memeq(ptr1, ptr2, len) (memcmp(ptr1, ptr2, len) == 0)

#ifdef __cplusplus
}
#endif

#endif  // CRAC_MEM_H_INCLUDED
