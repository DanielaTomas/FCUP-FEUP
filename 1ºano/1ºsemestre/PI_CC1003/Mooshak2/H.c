#include <stdio.h>
int main () {
int n,sinais=0,dobroant,dobroseg,anterior,seguinte,valor;

scanf("%d",&n);
scanf("%d",&anterior);
scanf("%d",&valor);
n-=2;


while(n>0 && n<=1000) {
 scanf("%d",&seguinte);
 dobroant=anterior*2;
 dobroseg=seguinte*2;
 if(valor>dobroant)
   if(valor>dobroseg) {
  sinais++; }
 anterior=valor;
 valor=seguinte;
 n--;
 }

printf("%d\n",sinais);

  return 0;
}
