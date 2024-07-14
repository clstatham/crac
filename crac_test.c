#include "include/crac/common.h"
#include "include/crac/hash.h"
#include "include/crac/log.h"
#include "include/crac/math.h"
#include "include/crac/mem.h"
#include "include/crac/string.h"
#include "include/crac/vec.h"

crac_vec_decl(intvec, i32);

int main() {
  crac_println("Hello, %s!", "world");
  crac_log_level(CRAC_LOG_LEVEL_INFO, "Info, world!");
  crac_log_level(CRAC_LOG_LEVEL_WARN, "Warning, %s!", "world");
  crac_log_level(CRAC_LOG_LEVEL_ERROR, "Error, world!");

  crac_set_seed(1234);

  crac_println("Random number: %d", crac_rand());
  crac_println("Random float: %f", crac_randf());

  ccharptr a = "Hello, world!";
  ccharptr b = "Goodbye, world!";
  crac_println("String 1 length: %d", crac_strlen(a));
  crac_println("String 2 length: %d", crac_strlen(b));
  crac_println("String compare: %d", crac_strcmp(a, b));
  if (crac_streq(a, b)) {
    crac_println("Strings are equal");
  } else {
    crac_println("Strings are not equal");
  }

  crac_static_assert(1 == 1);
  // crac_static_assert(1 == 0);  // uncomment to see the error

  u32* ptr = crac_new(u32, 5);
  crac_println("*ptr = %d", *ptr);
  crac_free(ptr);

  u64 value = 1234567890;
  crac_println("value = %llu", value);
  u64 hash = crac_hash_int(value);
  crac_println("hash = %llu", hash);
  hash = crac_hash_bytes((const u8*)&value, sizeof(value));
  crac_println("hash = %llu", hash);

  crac_vec3_t vec3_a = {1.0f, 2.0f, 3.0f};
  crac_println("vec3_a = (%f, %f, %f)", vec3_a.x, vec3_a.y, vec3_a.z);
  crac_vec3_t vec3_b = {4.0f, 5.0f, 6.0f};
  crac_println("vec3_b = (%f, %f, %f)", vec3_b.x, vec3_b.y, vec3_b.z);
  crac_vec3_t vec3_c = crac_vec3_add(vec3_a, vec3_b);
  crac_println("vec3_c = vec3_a + vec3_b = (%f, %f, %f)", vec3_c.x, vec3_c.y,
               vec3_c.z);
  vec3_c = crac_vec3_sub(vec3_a, vec3_b);
  crac_println("vec3_c = vec3_a - vec3_b = (%f, %f, %f)", vec3_c.x, vec3_c.y,
               vec3_c.z);
  f64 dot = crac_vec3_dot(vec3_a, vec3_b);
  crac_println("vec3_a . vec3_b = %f", dot);

  crac_println("vec3_a length = %f", crac_vec3_length(vec3_a));
  crac_vec3_t vec3_d = crac_vec3_normalize(vec3_a);
  crac_println("vec3_d = vec3_a normalized = (%f, %f, %f)", vec3_d.x, vec3_d.y,
               vec3_d.z);

  crac_mat4_t mat4_a = crac_mat4_identity();
  crac_mat4_print(mat4_a);
  crac_println("");
  crac_mat4_t mat4_b = crac_mat4_translate(crac_vec3(1.0f, 2.0f, 3.0f));
  crac_mat4_print(mat4_b);
  crac_println("");

  crac_mat4_t mat4_c = crac_mat4_mul(mat4_a, mat4_b);
  crac_mat4_print(mat4_c);
  crac_println("");

  crac_mat4_t mat4_d = crac_mat4_rotate_x(crac_deg2rad(32.0f));
  crac_mat4_print(mat4_d);
  crac_println("");

  mat4_c = crac_mat4_mul(mat4_c, mat4_d);
  crac_mat4_print(mat4_c);
  crac_println("");

  mat4_c = crac_mat4_inverse(mat4_c);
  crac_mat4_print(mat4_c);
  crac_println("");

  intvec* vec = intvec_new();
  intvec_push(vec, 1);
  intvec_push(vec, 2);
  intvec_push(vec, 3);

  for (int i = 0; i < vec->len; i++) {
    crac_println("vec[%d] = %d", i, *intvec_get(vec, i));
  }

  i32 last = intvec_pop(vec);
  crac_println("Popped: %d", last);
  last = intvec_pop(vec);
  crac_println("Popped: %d", last);
  last = intvec_pop(vec);
  crac_println("Popped: %d", last);

  intvec_free(vec);

  crac_println("Success!");
  return 0;
}
