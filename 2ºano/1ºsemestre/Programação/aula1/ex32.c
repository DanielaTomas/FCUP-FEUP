#include <stdio.h>
#include <limits.h>

int main(void) {
  int n;
  printf("How many numbers? ");
  scanf("%d", &n);

  int min = INT_MAX;
  int max = INT_MIN;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int v;
    printf("Enter value: ");
    scanf("%d", &v);
    if(v > max) {
      max = v;
    }
    else if(v < min){
      min = v;
    }
    sum += v;
  }
  printf("min: %d, max=%d, sum=%d\n", min, max, sum);
  return 0;
}
