#ifndef CRAC_HASH_H_INCLUDED
#define CRAC_HASH_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "assert.h"
#include "common.h"

#define CRAC_HASH_PRIME 1099511628211UL
#define CRAC_HASH_OFFSET 14695981039346656037UL

u64 crac_hash_int(u64 data);
u64 crac_hash_str(ccharptr str);
u64 crac_hash_bytes(const u8* data, usize len);
#define crac_hash(data) crac_hash_bytes((const u8*)&data, sizeof(data))

CRAC_INLINE u64 crac_hash_int(u64 data) {
  u64 hash = CRAC_HASH_OFFSET;
  hash ^= data;
  hash *= CRAC_HASH_PRIME;
  return hash;
}

CRAC_INLINE u64 crac_hash_str(ccharptr str) {
  crac_assert(str, "hash_str: str is NULL");
  u64 hash = CRAC_HASH_OFFSET;
  while (*str) {
    hash ^= *str++;
    hash *= CRAC_HASH_PRIME;
  }
  return hash;
}

CRAC_INLINE u64 crac_hash_bytes(const u8* data, usize len) {
  crac_assert(data, "hash_bytes: data is NULL");
  u64 hash = CRAC_HASH_OFFSET;
  for (usize i = 0; i < len; i++) {
    hash ^= data[i];
    hash *= CRAC_HASH_PRIME;
  }
  return hash;
}

#ifdef __cplusplus
}
#endif

#endif  // CRAC_HASH_H_INCLUDED
