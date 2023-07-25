#include <stdio.h>
int main() {

 int n,r,x;
 //r - número de múltiplos de 2 ou de 3

  printf("Insira o número de inteiros que pretende introduzir na sequência\n");
  scanf("%d",&n);

  printf("Introduza os %d números inteiros da sequência\n",n);

  r=0;

  while (n!=0) {
   scanf("%d",&x);
   if ((x%2==0 || x%3==0) && ((x%6)!=0))
    r=r+1;
   n=n-1; }

printf("Número de múltiplos ou de 2 ou de 3 = %d\n",r);

return 0;
}
