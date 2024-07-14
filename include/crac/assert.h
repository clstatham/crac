#ifndef INCLUDE_CRAC_ASSERT
#define INCLUDE_CRAC_ASSERT

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#if defined(NDEBUG) || defined(RELEASE)
#define crac_assert(cond, msg)
#else
#define crac_assert(cond, msg)              \
  do {                                      \
    if (!(cond)) {                          \
      crac_panic("assertion failed: " msg); \
    }                                       \
  } while (0)
#endif

#define crac_static_assert(cond) \
  (1 ? (void)0 : (void)sizeof(char[1 - 2 * !(cond)]))

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRAC_ASSERT */
