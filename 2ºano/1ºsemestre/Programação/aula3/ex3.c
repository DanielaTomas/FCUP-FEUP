#include <stdlib.h>
#include <stdio.h>

int compare_int(const void* v1, const void* v2) {
  return (* (int *) v1) - (* (int*) v2);
}

void sort_int_array(int a[], int n) {
  qsort(a, n, sizeof(int), &compare_int );
}

int main(void) {
  int *a = malloc(sizeof(int));
  printf("Enter values: ");
  int cap = 4;
  int cont = 0;

  scanf("%d", &a[cont]);

  while(a[cont] != 0) {
    cont++;
    cap *= 2;
    a = realloc(a,cap * sizeof(int));
    scanf("%d", &a[cont]);
  }
  sort_int_array(a,cont);

  float m;
  if(cont % 2 == 0) {
    m = (float)(a[cont/2-1] + a[cont/2])/2;
  }
  else {
    m = a[cont/2];
  }
  printf("Median: %f\n", m);
  free(a);
  return 0;
}
