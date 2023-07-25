#include <stdio.h>

int main(void) {
  // Read values
  int a, b;
  printf("Enter values: ");
  scanf("%d %d", &a, &b);

  // Calculate min, max, and sum
  int min, max, sum;
 
  if(a >= b) {
    max = a;
    min = b;
  }
  else {
    max = b;
    min = a;
  }
  sum = a + b;
  printf("min: %d, max: %d, sum: %d\n", min, max, sum);
  return 0;
}
