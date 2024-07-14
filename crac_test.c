#include "include/crac/common.h"
#include "include/crac/vec.h"

crac_vec_decl(intvec, i32);

int main() {
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
