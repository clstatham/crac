#ifndef CRAC_ASSERT_H_INCLUDED
#define CRAC_ASSERT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#if defined(NDEBUG) || defined(RELEASE)
#define crac_assert(cond, msg)
#else
#define crac_assert(cond, msg)                                                 \
  do {                                                                         \
    if (!(cond)) {                                                             \
      crac_panic(msg);                                                         \
    }                                                                          \
  } while (0)
#endif
#define crac_static_assert(cond)                                               \
  (1 ? (void)0 : (void)sizeof(char[1 - 2 * !(cond)]))

#ifdef __cplusplus
}
#endif

#endif // CRAC_ASSERT_H_INCLUDED
