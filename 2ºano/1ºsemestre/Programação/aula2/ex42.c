#include <stdio.h>
#include <stdlib.h>

int main(int argc,  char *argv[]) {
  double sum = 0;
  for(int i = 0; i < argc; i++) {
    sum += atof(argv[i]);
  }
  printf("%f\n", sum);
  return 0;
}
