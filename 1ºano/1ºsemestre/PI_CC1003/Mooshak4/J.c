#include <stdio.h>
#include <string.h>
#define MAX 100
int main () {
 int patas,max=0,min=0,cont=0;
 char registo[MAX];

 scanf("%d",&patas);
 while(patas>0) {
  scanf(" %s",registo);
  cont++;
  if(patas==2) {
   if(strcmp(registo,"muuu")==0 || strcmp(registo,"auau")==0 || strcmp(registo,"miao")==0 || strcmp(registo,"meemee")==0 || strcmp(registo,"jaco")==0) {
    max++;
    min++;
   }
   else if(strcmp(registo,"piupiu")==0 || strcmp(registo,"cacaraca")==0 || strcmp(registo,"cocorocoo")==0 || strcmp(registo,"quaqua")==0) {
    max++;
   }
   else {
    max++;
    min++;
   }
  }
   scanf("%d",&patas);
  }
  printf("%d %d %d\n",cont,min,max);

  return 0;
}
