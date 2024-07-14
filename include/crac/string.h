#ifndef INCLUDE_CRAC_STRING
#define INCLUDE_CRAC_STRING

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#define crac_strlen(str) strlen(str)
#define crac_strcmp(str1, str2) strcmp(str1, str2)
#define crac_streq(str1, str2) (strcmp(str1, str2) == 0)

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRAC_STRING */
