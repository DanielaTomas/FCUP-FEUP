#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
  char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
  char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

  strcpy(p1, argv[1]);
  strcpy(p2, argv[2]);

  int j = 0;
  for (int i = 0; i < strlen(p2) && j < strlen(p1); i++)
      if(p1[j] == p2[i])
        j++;

  if(j == strlen(p1))
    printf("YES\n");
  else {
    printf("NO\n");
  }

  return EXIT_SUCCESS;
}
