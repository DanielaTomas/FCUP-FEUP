#include <stdio.h>
int power(int x, int n) {
  if(n == 0) return 1;
  int val = 1;
  for(int i = 0; i < n; i++)
   val *= x;
   
  return val;
}

int main(void) {
  for (int n = 0; n <= 10; n++) {
    printf("2^%d: %d\n", n, power(2,n));
    printf("3^%d: %d\n", n, power(3,n));
  }
  return 0;
}
