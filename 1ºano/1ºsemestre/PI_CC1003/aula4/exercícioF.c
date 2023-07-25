#include <stdio.h>
int main() {

int primeiro,n,ultimo,cont=0,soma=0;

 printf("Insira uma sequência de números inteiros positivos que termina por '0'\n");
 scanf("%d",&primeiro);
 scanf("%d",&n);

 while (n>0) {
  if (n!=0 && primeiro!=0) {
   if(n>primeiro)
   soma=soma+n;
   else {
   cont=cont+1; }
  }
  if (cont!=0) {
   ultimo=n; }
  scanf("%d",&n);
 }

 if (cont!=0) {
   if ((ultimo%primeiro)==0)
   printf("%d multiplo de %d\n",primeiro,ultimo);
   else
   printf("%d nao multiplo de %d\n",primeiro,ultimo); }
 else
   printf("%d\n",soma);

return 0;
}
