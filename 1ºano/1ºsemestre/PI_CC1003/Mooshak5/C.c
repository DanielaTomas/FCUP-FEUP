#include <stdio.h>
int main() {
 int anterior,seguinte,cont;
 char tabela[10][4]= {{'+'},
                      {'_'},
                      {'A','B','C'},
                      {'D','E','F'},
                      {'G','H','I'},
                      {'J','K','L'},
                      {'M','N','O'},
                      {'P','Q','R','S'},
                      {'T','U','V'},
                      {'W','X','Y','Z'}
                     };

scanf("%d",&anterior);
cont=1;
if(anterior==99) return 0;

while(seguinte!=99) {
 scanf("%d",&seguinte);
 if(seguinte==anterior) {
  cont++;
 }
 else if(seguinte==77){
  printf("%c",tabela[anterior][cont-1]);
  cont=1;
  anterior=seguinte;
 }
 else {
  if(anterior!=77) {
   printf("%c",tabela[anterior][cont-1]);
  }
  cont=1;
  anterior=seguinte;
 }
}
printf("\n");

  return 0;
}
