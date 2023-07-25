// N_Potencias
#include <stdio.h>
int main() {
 int n,k1,k,s;
  printf("Valor de n? ");
  scanf("%d",&n);
  printf("Valor de k? ");
  scanf("%d",&k);
  s= 0;
  k1=k;
  while (n != 0) {
   s= s+k;
   k= k1*k;
   n= n-1;
  }
  printf("Soma = %d\n", s);
  return 0;
}
