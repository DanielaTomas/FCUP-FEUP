#include <stdio.h>
#include <string.h>
#define MAX 1000
void ordenar(char str[]);
int anagramas(char str1[], char str2[]) {
  ordenar(str1);
  ordenar(str2);
  int l1=strlen(str1);
  int l2=strlen(str2);
  if(l1==l2) {
    if(strcmp(str1,str2)==0)
     return 1;
  }
    return 0;
}

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
  char str1[MAX],str2[MAX];
  scanf("%s",str1);
  scanf("%s",str2);
  printf("%d\n",anagramas(str1,str2));
  return 0;
}
