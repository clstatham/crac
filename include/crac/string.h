#ifndef CRAC_STRING_H_INCLUDED
#define CRAC_STRING_H_INCLUDED

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

#endif  // CRAC_STRING_H_INCLUDED
