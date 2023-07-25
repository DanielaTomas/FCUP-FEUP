#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_SIZE 64

int f(char* content) {
  char str[MAX_STR_SIZE];
  int result = 2;
  (void)strcpy(str, content);
  return result;
}
int main(int argc, char* argv[]) {
  if (argc == 2)
   printf("result = %d\n", f(argv[1]));
  return EXIT_SUCCESS;
}
