#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(int argc, char* argv[]){

int size;
int total = 0;

for (int i=1; i < argc; i++) {
  size = 0;
  while(argv[i][size] != 0) {
    size++;
  }
  total += size;
  printf("%s -> %d \n",argv[i],size);
}
printf("total = %d\n",total);

 return 0;
}
