#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHARS 10000
int decimal(char str[]) {
  int x = atoi(str);
return x;
}
int main() {
  char str[MAXCHARS];
  scanf("%s", str);
  printf("%d\n", decimal(str));
  return 0;
}
