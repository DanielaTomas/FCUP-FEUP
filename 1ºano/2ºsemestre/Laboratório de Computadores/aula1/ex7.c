#include <stdio.h>
#include <string.h>
#define MAX 1000
void ordenar(char str[]) {
  int x,j,i,size;
  size=strlen(str);
  for(i=1; i<size; i++) {
   x=str[i];
   for(j=i-1; j>=0 && str[j]>x; j--) {
    str[j+1]=str[j];
   }
   str[j+1]=x;
  }
}
int main() {
  char vec[MAX];
  scanf("%s",vec);
  ordenar(vec);
  printf("%s\n",vec);
  return 0;
}
