#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[]) {
  for(int i = 1; i < argc; i++) {
    FILE* f = fopen(argv[i],"r");
    char c;
    while((c = fgetc(f)) != EOF)
     printf("%c",c);
    fclose(f);
  }
  
  return 0;
}
