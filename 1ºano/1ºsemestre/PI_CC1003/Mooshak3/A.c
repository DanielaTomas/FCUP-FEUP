#include <stdio.h>
int main () {
 int x[251],i,m,j,l,k,contnegativos,contdivisores;

 scanf("%d",&k);
 for(i=0; k!=0; i++) {
  x[i]=k;
  scanf("%d",&k);
 }

 scanf("%d",&m);
 while (m>0) {
  scanf("%d",&j);
  contnegativos=0;
  contdivisores=0;
  for (l=0; l<i; l++) {
   if(j%x[l]==0) {
    contdivisores++;
    if(x[l]<0) {
     contnegativos++; }
   }
  }
  printf("Resp: Numero de divisores de %d na sequencia = %d\n",j,contdivisores);
  printf("      Numero dos negativos = %d\n",contnegativos);
  m--;
 }
 return 0;
}
