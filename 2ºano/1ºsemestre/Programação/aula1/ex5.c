#include <stdio.h>

//5.1
int mdc(int a, int b) {
  int temp;
  while(temp != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

//5.2
int mdcrec(int a, int b) {
  if(b == 0) return a;
  else if(a < b) mdcrec(b,a);
  return mdcrec(b, a % b);
}

int main(void) {
  int a, b;
  printf("Enter values: ");
  scanf("%d %d", &a, &b);
  printf("mdc(%d,%d): %d\n", a, b, mdc(a, b));
  printf("mdcrec(%d,%d): %d\n", a, b, mdcrec(a, b));
  return 0;
}
