#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char c;
  int cont=0;
  FILE* f1;
  FILE* f2;

  if(argc < 3) {
   fprintf(stderr, "%s numero arg inválido!!\n", argv[0]);
   exit(0);
  }
  f1 = fopen(argv[1], "r");
  if(f1 == NULL) {
   fprintf(stderr, "%s ficheiro falhou a abrir!!\n", argv[1]);
   exit(1);
  }

  f2 = fopen(argv[2], "w");
   if(f2 == NULL) {
   fprintf(stderr, "%s ficheiro falhou a abrir!!\n", argv[2]);
   exit(1);
  }
  while((c = fgetc(f1)) != EOF) {
   cont++;
  }

  fprintf(f2,"O ficheiro tem %d caracteres.\n",cont);
  fclose(f1);
  fclose(f2);

  return 0;
}
