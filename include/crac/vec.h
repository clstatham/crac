#ifndef CRAC_VEC_H_INCLUDED
#define CRAC_VEC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "assert.h"
#include "common.h"

#define crac_vec_decl(vec_type, item_type)                                     \
  typedef struct {                                                             \
    item_type *data;                                                           \
    usize len;                                                                 \
    usize cap;                                                                 \
  } vec_type;                                                                  \
  _crac_vec_new_impl(vec_type, item_type);                                     \
  _crac_vec_free_impl(vec_type, item_type);                                    \
  _crac_vec_push_impl(vec_type, item_type);                                    \
  _crac_vec_pop_impl(vec_type, item_type);                                     \
  _crac_vec_get_impl(vec_type, item_type);                                     \
  _crac_vec_clear_impl(vec_type, item_type);

#define _crac_vec_new_impl(vec_type, item_type)                                \
  CRAC_INLINE vec_type *vec_type##_new() {                                     \
    vec_type *vec = crac_alloc(vec_type);                                      \
    vec->data = NULL;                                                          \
    vec->len = 0;                                                              \
    vec->cap = 0;                                                              \
    return vec;                                                                \
  }

#define _crac_vec_free_impl(vec_type, item_type)                               \
  CRAC_INLINE void vec_type##_free(vec_type *vec) {                            \
    crac_assert(vec, "vec is NULL");                                           \
    crac_free(vec->data);                                                      \
    crac_free(vec);                                                            \
  }

#define _crac_vec_push_impl(vec_type, item_type)                               \
  CRAC_INLINE void vec_type##_push(vec_type *vec, item_type item) {            \
    crac_assert(vec, "vec is NULL");                                           \
    if (vec->len == vec->cap) {                                                \
      vec->cap = vec->cap == 0 ? 1 : vec->cap * 2;                             \
      vec->data =                                                              \
          (item_type *)crac_realloc(vec->data, vec->cap * sizeof(item_type));  \
    }                                                                          \
    vec->data[vec->len++] = item;                                              \
  }

#define _crac_vec_pop_impl(vec_type, item_type)                                \
  CRAC_INLINE item_type vec_type##_pop(vec_type *vec) {                        \
    crac_assert(vec, "vec is NULL");                                           \
    crac_assert(vec->len > 0, "vec is empty");                                 \
    return vec->data[--vec->len];                                              \
  }

#define _crac_vec_get_impl(vec_type, item_type)                                \
  CRAC_INLINE item_type *vec_type##_get(vec_type *vec, usize index) {          \
    crac_assert(vec, "vec is NULL");                                           \
    crac_assert(index < vec->len, "index out of bounds");                      \
    return &vec->data[index];                                                  \
  }

#define _crac_vec_clear_impl(vec_type, item_type)                              \
  CRAC_INLINE void vec_type##_clear(vec_type *vec) {                           \
    crac_assert(vec, "vec is NULL");                                           \
    vec->len = 0;                                                              \
  }

#ifdef __cplusplus
}
#endif

#endif // CRAC_VEC_H_INCLUDED
