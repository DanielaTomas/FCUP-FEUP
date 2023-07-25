#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");

    char c;
    while((c = fgetc(f1)) != EOF)
      fprintf(f2,"%c",c);

    fclose(f1);
    fclose(f2);
}
