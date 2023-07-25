#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]){

int size;
int total = 0;

for (int i=1; i < argc; i++) {
  size = strlen(argv[i]);
  total += size;
  printf("%s -> %d \n",argv[i],size);
}
printf("total = %d\n",total);

 return 0;
}
