#include <stdlib.h>
#include <stdio.h>

int compare_int(const void* v1, const void* v2) {
  return (* (int *) v1) - (* (int*) v2);
}

void sort_int_array(int a[], int n) {
  qsort(a, n, sizeof(int), &compare_int );
}

int main(void) {
  int n;
  printf("How many numbers: ");
  scanf("%d", &n);

  int *a = malloc(n * sizeof(int));
  int val;
  printf("Enter values: ");
  for(int i = 0; i < n; i++) {
    scanf("%d", &val);
    a[i] = val;

  }
  sort_int_array(a,n);
  float m;
  if(n % 2 == 0) {
    m = (float)(a[n/2-1] + a[n/2])/2;
  }
  else {
    m = a[n/2];
  }
  printf("Median: %f\n", m);
  free(a);
  return 0;
}
