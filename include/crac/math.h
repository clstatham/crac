#ifndef INCLUDE_CRAC_MATH
#define INCLUDE_CRAC_MATH

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "common.h"

#define CRAC_RAND_MAX RAND_MAX
#define CRAC_MAX_VEC_CAPACITY LLONG_MAX
#define CRAC_MAX_MAP_CAPACITY LLONG_MAX

#define crac_min(a, b) ((a) < (b) ? (a) : (b))
#define crac_max(a, b) ((a) > (b) ? (a) : (b))
#define crac_clamp(x, min, max) (crac_max(min, crac_min(x, max)))
#define crac_abs(x) ((x) < 0 ? -(x) : (x))
#define crac_sqr(x) ((x) * (x))
#define crac_cube(x) ((x) * (x) * (x))
#define crac_lerp(a, b, t) ((a) + ((b) - (a)) * (t))
#define crac_rotl(x, n) (((x) << (n)) | ((x) >> (sizeof(x) * CHAR_BIT - (n))))
#define crac_rotr(x, n) (((x) >> (n)) | ((x) << (sizeof(x) * CHAR_BIT - (n)))
#define CRAC_PI 3.14159265358979323846
#define CRAC_TAU (2.0 * CRAC_PI)
#define CRAC_DEG_TO_RAD (CRAC_PI / 180.0)
#define CRAC_RAD_TO_DEG (180.0 / CRAC_PI)
#define crac_deg2rad(deg) ((deg) * CRAC_DEG_TO_RAD)
#define crac_rad2deg(rad) ((rad) * CRAC_RAD_TO_DEG)
#define CRAC_EPSILON 0.00001

CRAC_INLINE void crac_set_seed(u64 seed) {
  srand(seed);
}

CRAC_INLINE u64 crac_rand() {
  return rand();
}

CRAC_INLINE u64 crac_rand_range(u64 min, u64 max) {
  return min + crac_rand() % (max - min + 1);
}

CRAC_INLINE f64 crac_randf() {
  return (f64)crac_rand() / (f64)CRAC_RAND_MAX;
}

CRAC_INLINE f64 crac_randf_range(f64 min, f64 max) {
  return min + crac_randf() * (max - min);
}

typedef struct {
  f64 x;
  f64 y;
} crac_vec2_t;

typedef struct {
  f64 x;
  f64 y;
  f64 z;
} crac_vec3_t;

typedef struct {
  f64 x;
  f64 y;
  f64 z;
  f64 w;
} crac_vec4_t;

typedef struct {
  f64 x;
  f64 y;
  f64 z;
  f64 w;
} crac_quat_t;

typedef struct {
  f64 m[16];
} crac_mat4_t;

/* vec2 */
CRAC_INLINE crac_vec2_t crac_vec2(f64 x, f64 y) {
  return (crac_vec2_t){x, y};
}

CRAC_INLINE crac_vec2_t crac_vec2_add(crac_vec2_t a, crac_vec2_t b) {
  return (crac_vec2_t){a.x + b.x, a.y + b.y};
}

CRAC_INLINE crac_vec2_t crac_vec2_sub(crac_vec2_t a, crac_vec2_t b) {
  return (crac_vec2_t){a.x - b.x, a.y - b.y};
}

CRAC_INLINE crac_vec2_t crac_vec2_mul(crac_vec2_t a, f64 s) {
  return (crac_vec2_t){a.x * s, a.y * s};
}

CRAC_INLINE crac_vec2_t crac_vec2_div(crac_vec2_t a, f64 s) {
  return (crac_vec2_t){a.x / s, a.y / s};
}

CRAC_INLINE f64 crac_vec2_dot(crac_vec2_t a, crac_vec2_t b) {
  return a.x * b.x + a.y * b.y;
}

CRAC_INLINE f64 crac_vec2_length(crac_vec2_t a) {
  return sqrt(a.x * a.x + a.y * a.y);
}

CRAC_INLINE crac_vec2_t crac_vec2_normalize(crac_vec2_t a) {
  f64 len = crac_vec2_length(a);
  return (crac_vec2_t){a.x / len, a.y / len};
}

CRAC_INLINE crac_vec2_t crac_vec2_lerp(crac_vec2_t a, crac_vec2_t b, f64 t) {
  return (crac_vec2_t){a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t};
}

CRAC_INLINE void crac_vec2_print(crac_vec2_t a) {
  crac_print("vec2(%f, %f)", a.x, a.y);
}

/* vec3 */

CRAC_INLINE crac_vec3_t crac_vec3(f64 x, f64 y, f64 z) {
  return (crac_vec3_t){x, y, z};
}

CRAC_INLINE crac_vec3_t crac_vec3_add(crac_vec3_t a, crac_vec3_t b) {
  return (crac_vec3_t){a.x + b.x, a.y + b.y, a.z + b.z};
}

CRAC_INLINE crac_vec3_t crac_vec3_sub(crac_vec3_t a, crac_vec3_t b) {
  return (crac_vec3_t){a.x - b.x, a.y - b.y, a.z - b.z};
}

CRAC_INLINE crac_vec3_t crac_vec3_mul(crac_vec3_t a, f64 s) {
  return (crac_vec3_t){a.x * s, a.y * s, a.z * s};
}

CRAC_INLINE crac_vec3_t crac_vec3_div(crac_vec3_t a, f64 s) {
  return (crac_vec3_t){a.x / s, a.y / s, a.z / s};
}

CRAC_INLINE f64 crac_vec3_dot(crac_vec3_t a, crac_vec3_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

CRAC_INLINE crac_vec3_t crac_vec3_cross(crac_vec3_t a, crac_vec3_t b) {
  return (crac_vec3_t){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x};
}

CRAC_INLINE f64 crac_vec3_length(crac_vec3_t a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

CRAC_INLINE crac_vec3_t crac_vec3_normalize(crac_vec3_t a) {
  f64 len = crac_vec3_length(a);
  return (crac_vec3_t){a.x / len, a.y / len, a.z / len};
}

CRAC_INLINE crac_vec3_t crac_vec3_lerp(crac_vec3_t a, crac_vec3_t b, f64 t) {
  return (crac_vec3_t){a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t,
                       a.z + (b.z - a.z) * t};
}

CRAC_INLINE void crac_vec3_print(crac_vec3_t a) {
  crac_print("vec3(%f, %f, %f)", a.x, a.y, a.z);
}

/* vec4 */

CRAC_INLINE crac_vec4_t crac_vec4(f64 x, f64 y, f64 z, f64 w) {
  return (crac_vec4_t){x, y, z, w};
}

CRAC_INLINE crac_vec4_t crac_vec4_add(crac_vec4_t a, crac_vec4_t b) {
  return (crac_vec4_t){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

CRAC_INLINE crac_vec4_t crac_vec4_sub(crac_vec4_t a, crac_vec4_t b) {
  return (crac_vec4_t){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

CRAC_INLINE crac_vec4_t crac_vec4_mul(crac_vec4_t a, f64 s) {
  return (crac_vec4_t){a.x * s, a.y * s, a.z * s, a.w * s};
}

CRAC_INLINE crac_vec4_t crac_vec4_div(crac_vec4_t a, f64 s) {
  return (crac_vec4_t){a.x / s, a.y / s, a.z / s, a.w / s};
}

CRAC_INLINE f64 crac_vec4_dot(crac_vec4_t a, crac_vec4_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

CRAC_INLINE f64 crac_vec4_length(crac_vec4_t a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

CRAC_INLINE crac_vec4_t crac_vec4_normalize(crac_vec4_t a) {
  f64 len = crac_vec4_length(a);
  return (crac_vec4_t){a.x / len, a.y / len, a.z / len, a.w / len};
}

CRAC_INLINE crac_vec4_t crac_vec4_lerp(crac_vec4_t a, crac_vec4_t b, f64 t) {
  return (crac_vec4_t){a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t,
                       a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t};
}

CRAC_INLINE void crac_vec4_print(crac_vec4_t a) {
  crac_print("vec4(%f, %f, %f, %f)", a.x, a.y, a.z, a.w);
}

/* mat4 */

CRAC_INLINE crac_mat4_t crac_mat4_identity() {
  return (crac_mat4_t){1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_mul(crac_mat4_t a, crac_mat4_t b) {
  crac_mat4_t r;
  // clang-format off
    r.m[0] = a.m[0] * b.m[0] + a.m[1] * b.m[4] + a.m[2] * b.m[8] + a.m[3] * b.m[12];
    r.m[1] = a.m[0] * b.m[1] + a.m[1] * b.m[5] + a.m[2] * b.m[9] + a.m[3] * b.m[13];
    r.m[2] = a.m[0] * b.m[2] + a.m[1] * b.m[6] + a.m[2] * b.m[10] + a.m[3] * b.m[14];
    r.m[3] = a.m[0] * b.m[3] + a.m[1] * b.m[7] + a.m[2] * b.m[11] + a.m[3] * b.m[15];
    r.m[4] = a.m[4] * b.m[0] + a.m[5] * b.m[4] + a.m[6] * b.m[8] + a.m[7] * b.m[12];
    r.m[5] = a.m[4] * b.m[1] + a.m[5] * b.m[5] + a.m[6] * b.m[9] + a.m[7] * b.m[13];
    r.m[6] = a.m[4] * b.m[2] + a.m[5] * b.m[6] + a.m[6] * b.m[10] + a.m[7] * b.m[14];
    r.m[7] = a.m[4] * b.m[3] + a.m[5] * b.m[7] + a.m[6] * b.m[11] + a.m[7] * b.m[15];
    r.m[8] = a.m[8] * b.m[0] + a.m[9] * b.m[4] + a.m[10] * b.m[8] + a.m[11] * b.m[12];
    r.m[9] = a.m[8] * b.m[1] + a.m[9] * b.m[5] + a.m[10] * b.m[9] + a.m[11] * b.m[13];
    r.m[10] = a.m[8] * b.m[2] + a.m[9] * b.m[6] + a.m[10] * b.m[10] + a.m[11] * b.m[14];
    r.m[11] = a.m[8] * b.m[3] + a.m[9] * b.m[7] + a.m[10] * b.m[11] + a.m[11] * b.m[15];
    r.m[12] = a.m[12] * b.m[0] + a.m[13] * b.m[4] + a.m[14] * b.m[8] + a.m[15] * b.m[12];
    r.m[13] = a.m[12] * b.m[1] + a.m[13] * b.m[5] + a.m[14] * b.m[9] + a.m[15] * b.m[13];
    r.m[14] = a.m[12] * b.m[2] + a.m[13] * b.m[6] + a.m[14] * b.m[10] + a.m[15] * b.m[14];
    r.m[15] = a.m[12] * b.m[3] + a.m[13] * b.m[7] + a.m[14] * b.m[11] + a.m[15] * b.m[15];
  // clang-format on
  return r;
}

CRAC_INLINE crac_vec4_t crac_mat4_mul_vec4(crac_mat4_t m, crac_vec4_t v) {
  return (crac_vec4_t){
      m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z + m.m[3] * v.w,
      m.m[4] * v.x + m.m[5] * v.y + m.m[6] * v.z + m.m[7] * v.w,
      m.m[8] * v.x + m.m[9] * v.y + m.m[10] * v.z + m.m[11] * v.w,
      m.m[12] * v.x + m.m[13] * v.y + m.m[14] * v.z + m.m[15] * v.w};
}

CRAC_INLINE crac_mat4_t crac_mat4_translate(crac_vec3_t v) {
  return (crac_mat4_t){1, 0, 0, v.x, 0, 1, 0, v.y, 0, 0, 1, v.z, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_scale(crac_vec3_t v) {
  return (crac_mat4_t){v.x, 0, 0, 0, 0, v.y, 0, 0, 0, 0, v.z, 0, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_rotate_x(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  return (crac_mat4_t){1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_rotate_y(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  return (crac_mat4_t){c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_rotate_z(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  return (crac_mat4_t){c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
}

CRAC_INLINE crac_mat4_t crac_mat4_perspective(float fov,
                                              float aspect,
                                              float near,
                                              float far) {
  float f = 1.0f / tanf(fov * 0.5f);
  float nf = 1.0f / (near - far);
  // clang-format off
    return (crac_mat4_t){
        f / aspect, 0, 0, 0,
        0, f, 0, 0,
        0, 0, (far + near) * nf, 2 * far * near * nf,
        0, 0, -1, 0
    };
  // clang-format on
}

CRAC_INLINE crac_mat4_t crac_mat4_ortho(float left,
                                        float right,
                                        float bottom,
                                        float top,
                                        float near,
                                        float far) {
  float lr = 1.0f / (left - right);
  float bt = 1.0f / (bottom - top);
  float nf = 1.0f / (near - far);
  // clang-format off
    return (crac_mat4_t){-2 * lr, 0,       0,      (left + right) * lr,
                        0,       -2 * bt, 0,      (top + bottom) * bt,
                        0,       0,       2 * nf, (far + near) * nf,
                        0,       0,       0,      1};
  // clang-format on
}

CRAC_INLINE crac_mat4_t crac_mat4_look_at(crac_vec3_t eye,
                                          crac_vec3_t center,
                                          crac_vec3_t up) {
  crac_vec3_t f = crac_vec3_normalize(crac_vec3_sub(center, eye));
  crac_vec3_t r = crac_vec3_normalize(crac_vec3_cross(f, up));
  crac_vec3_t u = crac_vec3_cross(r, f);
  return (crac_mat4_t){r.x,  r.y,  r.z,  -crac_vec3_dot(r, eye),
                       u.x,  u.y,  u.z,  -crac_vec3_dot(u, eye),
                       -f.x, -f.y, -f.z, crac_vec3_dot(f, eye),
                       0,    0,    0,    1};
}

CRAC_INLINE crac_mat4_t crac_mat4_transpose(crac_mat4_t m) {
  return (crac_mat4_t){m.m[0], m.m[4],  m.m[8],  m.m[12], m.m[1],  m.m[5],
                       m.m[9], m.m[13], m.m[2],  m.m[6],  m.m[10], m.m[14],
                       m.m[3], m.m[7],  m.m[11], m.m[15]};
}

CRAC_INLINE crac_mat4_t crac_mat4_inverse(crac_mat4_t m) {
  float a0 = m.m[0] * m.m[5] - m.m[1] * m.m[4];
  float a1 = m.m[0] * m.m[6] - m.m[2] * m.m[4];
  float a2 = m.m[0] * m.m[7] - m.m[3] * m.m[4];
  float a3 = m.m[1] * m.m[6] - m.m[2] * m.m[5];
  float a4 = m.m[1] * m.m[7] - m.m[3] * m.m[5];
  float a5 = m.m[2] * m.m[7] - m.m[3] * m.m[6];
  float b0 = m.m[8] * m.m[13] - m.m[9] * m.m[12];
  float b1 = m.m[8] * m.m[14] - m.m[10] * m.m[12];
  float b2 = m.m[8] * m.m[15] - m.m[11] * m.m[12];
  float b3 = m.m[9] * m.m[14] - m.m[10] * m.m[13];
  float b4 = m.m[9] * m.m[15] - m.m[11] * m.m[13];
  float b5 = m.m[10] * m.m[15] - m.m[11] * m.m[14];
  float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
  if (det == 0) {
    crac_panic("Matrix is not invertible");
  }
  float inv_det = 1.0f / det;
  // clang-format off
    return (crac_mat4_t){(m.m[5] * b5 - m.m[6] * b4 + m.m[7] * b3) * inv_det,
                        (-m.m[1] * b5 + m.m[2] * b4 - m.m[3] * b3) * inv_det,
                        (m.m[13] * a5 - m.m[14] * a4 + m.m[15] * a3) * inv_det,
                        (-m.m[9] * a5 + m.m[10] * a4 - m.m[11] * a3) * inv_det,
                        (-m.m[4] * b5 + m.m[6] * b2 - m.m[7] * b1) * inv_det,
                        (m.m[0] * b5 - m.m[2] * b2 + m.m[3] * b1) * inv_det,
                        (-m.m[12] * a5 + m.m[14] * a2 - m.m[15] * a1) * inv_det,
                        (m.m[8] * a5 - m.m[10] * a2 + m.m[11] * a1) * inv_det,
                        (m.m[4] * b4 - m.m[5] * b2 + m.m[7] * b0) * inv_det,
                        (-m.m[0] * b4 + m.m[1] * b2 - m.m[3] * b0) * inv_det,
                        (m.m[12] * a4 - m.m[13] * a2 + m.m[15] * a0) * inv_det,
                        (-m.m[8] * a4 + m.m[9] * a2 - m.m[11] * a0) * inv_det,
                        (-m.m[4] * b3 + m.m[5] * b1 - m.m[6] * b0) * inv_det,
                        (m.m[0] * b3 - m.m[1] * b1 + m.m[2] * b0) * inv_det,
                        (-m.m[12] * a3 + m.m[13] * a1 - m.m[14] * a0) * inv_det,
                        (m.m[8] * a3 - m.m[9] * a1 + m.m[10] * a0) * inv_det};
  // clang-format on
}

CRAC_INLINE void crac_mat4_print(crac_mat4_t m) {
  printf("[ %f %f %f %f ]\n", m.m[0], m.m[4], m.m[8], m.m[12]);
  printf("[ %f %f %f %f ]\n", m.m[1], m.m[5], m.m[9], m.m[13]);
  printf("[ %f %f %f %f ]\n", m.m[2], m.m[6], m.m[10], m.m[14]);
  printf("[ %f %f %f %f ]\n", m.m[3], m.m[7], m.m[11], m.m[15]);
}

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRAC_MATH */
