#include <stdio.h>

int main () {
 int i=0,cont=0;
 char c[1000];

while((c[i] = getchar())!='\n') {
 if(c[i]=='P' || c[i]=='p') {
  cont++;
 }
 i++;
}
 c[i]='\0';

 printf("%d\n",cont);

  return 0;
}
