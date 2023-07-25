#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int* data; // Elementos
  int capacity; // Capacidade do array
  int size; // Nº de elementos (posições ocupadas)
} ivector;

ivector* v_create(int initial_capacity) {
  ivector* v = malloc(sizeof(ivector));
  v -> data = malloc(initial_capacity * sizeof(int));
  v -> capacity = initial_capacity;
  v -> size = 0;
  return v;
}

int v_size(ivector* v) {
  return v -> size;
}

int* v_data(ivector* v) {
  return v -> data;
}

void v_destroy(ivector* v) {
  free(v->data);
  free(v);
}

void v_add(ivector* v, int x) {
  if(v->size >= v->capacity) {
    v = realloc(v,sizeof(int));
  }
  v->data[v->size+1] = x;
  v->capacity *= 2;
  v->size += 1;
}
