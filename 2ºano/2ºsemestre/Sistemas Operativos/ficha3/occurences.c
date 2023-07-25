#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
  char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
  char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

  strcpy(p1, argv[1]);
  strcpy(p2, argv[2]);
  int size1 = strlen(p1);
  int size2 = strlen(p2);

  int m[size1+1][size2+1];

  for (int i = 0; i <= size2; ++i)
    m[0][i] = 0;

  for (int i = 0; i <= size1; ++i)
    m[i][0] = 1;

  for (int i = 1; i <= size1; i++) {
    for (int j = 1; j <= size2; j++) {
      if (p1[i-1] == p2[j-1])
        m[i][j] = m[i-1][j] + m[i-1][j-1];
      else
        m[i][j] = m[i-1][j];
    }
  }

  printf("%d\n",m[size1][size2]);
  return EXIT_SUCCESS;
}
