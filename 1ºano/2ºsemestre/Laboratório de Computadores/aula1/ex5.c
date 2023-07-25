#include <stdio.h>

void range(int vec[], unsigned size, int inicio, int incr) {
  int i;
  printf("{ ");
  for(i=0; i < size-1; i++) {
   printf("%d, ",vec[i]=inicio+i*incr);
  }
   printf("%d ",vec[i]=inicio+i*incr);
  printf("}\n");
}

int main() {
  int a[5];
  range(a,5,3,2);
  return 0;
}
