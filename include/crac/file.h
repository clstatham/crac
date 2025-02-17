#ifndef INCLUDE_CRAC_FILE
#define INCLUDE_CRAC_FILE

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define crac_file_exists(path) (access(path, F_OK | R_OK) != -1)
#define crac_file_write(path, data, len) \
  do {                                   \
    FILE* file = fopen(path, "w");       \
    fwrite(data, 1, len, file);          \
    fclose(file);                        \
  } while (0)
#define crac_file_read(path, data, len) \
  do {                                  \
    FILE* file = fopen(path, "r");      \
    fread(data, 1, len, file);          \
    fclose(file);                       \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRAC_FILE */
