/**
 * crac.h
 * Connor's Rusty Abstractions for C
 * A header-only library of useful functions and macros for C programming,
 * inspired by Rust.
 *
 * Author:
 * Connor Statham
 * github.com/clstatham
 * (and GitHub Copilot, lol)
 *
 * License:
 * MIT / Apache 2.0 (dual-licensed)
 */

#ifndef CRAC_H_INCLUDED
#define CRAC_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t usize;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef ptrdiff_t isize;
typedef float f32;
typedef double f64;
typedef const char *ccharptr;

#define CRAC_EXTERN extern

#if defined(__GNUC__) || defined(__clang__)
#define CRAC_INLINE inline __attribute__((unused))
#else
#define CRAC_INLINE inline
#endif

CRAC_INLINE void crac_print(ccharptr fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
}

CRAC_INLINE void crac_println(ccharptr fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}

static inline void crac_panic(const char *msg) {
  crac_println("panicked: %s", msg);
#if defined(NDEBUG) || defined(RELEASE)
  exit(1);
#else
  abort(); // abort and generate a core dump in debug mode
#endif
}

#define crac_defer(...) for (int _i = 1; _i; _i = 0, __VA_ARGS__)
#define crac_move(x) (void)(x)

#ifdef __cplusplus
}
#endif

#endif /* CRAC_H_INCLUDED */
