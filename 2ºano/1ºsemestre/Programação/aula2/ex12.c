#include <stdio.h>

void invert(int n, int a[]) {
  for (int i = 0; i < n/2; i++) {
    int temp = a[i];
    a[i] = a[n-1-i];
    a[n-1-i] = temp;
  }
}

void print(int n, int a[]) {
  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", i, a[i]);
  }
}

int main(void) {
  int a[7] = { 0, 1, 2, 3, 4, 5, 6};
  print(7, a);
  invert(7, a);
  print(7, a);
  return 0;
}
