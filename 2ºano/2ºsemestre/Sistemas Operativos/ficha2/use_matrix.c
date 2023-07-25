#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main() {
  matrix* u1 = matrix_new_random(2, 2, 0, 9);
  matrix* u2 = matrix_new_random(2, 2, 0, 9);

  printf("u1 ---------------------------------\n");
  matrix_print(u1);
  printf("u2 ---------------------------------\n");
  matrix_print(u2);

  matrix* u3 = matrix_sub(u1, u2);
  printf("u3 ---------------------------------\n");
  matrix_print(u3);

  matrix* u4 = matrix_mul(u1, u2);
  printf("u4 ---------------------------------\n");
  matrix_print(u4);

  matrix* u5 = matrix_trans(u1);
  printf("u5 ---------------------------------\n");
  matrix_print(u5);

  return 0;
}
