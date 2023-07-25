#include <stdio.h>
#define MAX 100
int main () {
int membros,blocos,p,i,j,l,k=0,cont=0;;
int matriz[MAX][MAX];

scanf(" %d",&membros);
for(p=0; p<membros; p++) {
 scanf(" %d",&blocos);
 cont+=blocos;
 for(i=k; i<blocos+k; i++) {
  for(j=0; j<5; j++) {
   scanf("%d",&matriz[i][j]);
  }
 }
 k=i;
}


  return 0;
}
