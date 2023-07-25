#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
  int size;
  int total = 0;
  for(int i=1; i<argc; i++){
    size = atoi(argv[i]);
    total += size;
  }
  printf("total = %d\n", total);
  return 0;
}
