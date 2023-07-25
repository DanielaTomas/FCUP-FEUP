#include <stdio.h>

void convert(int d, int* ph, int* pm, int* ps) {
  *ph = d / 3600;
  *pm = (d % 3600)/60;
  *ps = ((d % 3600))%60;
}

int main(void) {
  int d, h, m, s;
  printf("Enter duration: ");
  scanf("%d", &d);
  convert(d, &h, &m, &s);
  printf("h: %d, m: %d, s: %d\n", h, m, s);
  return 0;
}
