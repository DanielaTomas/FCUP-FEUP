// Soma multiplos de 4
#include <stdio.h>
int main() {
int k, s;
 k= 4;
 s= 0;
 while (k <= 1000) {
  s= s+k;
  k= k+4;
 }
 printf("Soma = %d\n", s);
 return 0;
}
