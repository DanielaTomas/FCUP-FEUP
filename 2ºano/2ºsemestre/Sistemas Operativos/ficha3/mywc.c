#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE* f;
  f = argc == 3 ? fopen(argv[2],"r") : fopen(argv[1],"r");

  char c;
  int count = 0;
  if(strcmp(argv[1],"-w") == 0){
    while((c = fgetc(f)) != EOF)
      if(c == ' ' || c == '\t' || c == '\0' || c == '\n')
        count++;
  }
  else if(strcmp(argv[1],"-l") == 0){
    while((c = fgetc(f)) != EOF)
      if(c == '\0' || c == '\n')
        count++;
   }
   else {
    while((c = fgetc(f)) != EOF)
      count++;
   }

  fclose(f);
  printf("%d\n",count);

  return 0;
}
