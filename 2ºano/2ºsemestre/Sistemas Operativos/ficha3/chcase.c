#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char*argv[]) {
    FILE* f = fopen(argv[2],"r");
    char c;

    if(strcmp(argv[1],"-u") == 0) {
      while((c = fgetc(f)) != EOF)
       printf("%c",toupper(c));
    }
    else if(strcmp(argv[1],"-l") == 0) {
      while((c = fgetc(f)) != EOF)
       printf("%c",tolower(c));
    }
    fclose(f);

  return 0;
}
