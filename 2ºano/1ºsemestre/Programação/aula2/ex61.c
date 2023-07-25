#include <stdio.h>

#define MAX_ELEMENTS 5

typedef struct {
  int elements[MAX_ELEMENTS];
  int size;
} stack;

void stack_print(const stack* s) {
  printf("[");
  for (int i = 0; i < s->size; i++) {
    printf(" %d", s->elements[i]);
  }
  printf(" ] (%d elements)\n", s->size);
}

int main(void) {
  stack s = {
    .elements = { 0, 1, 2},
    .size = 3
  };
  stack_print(&s);
  return 0;
}
