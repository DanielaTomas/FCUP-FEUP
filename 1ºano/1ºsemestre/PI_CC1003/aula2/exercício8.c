#include <stdio.h>
int main() {

 int a,b,c;
//a - máximo; b - mínimo
 scanf("%d",&c);
 a=c;
 b=c;

 while (c != 0) {
  scanf("%d",&c);
  if (c != 0) {
   if (c>a)
    a=c;
   if (c<b)
    b=c; }
 }

 if (a>b && b<a)
  printf("Maior = %d e Menor = %d\n",a,b);
 else
  printf("Maior = Menor = %d\n",a);


  return 0;
}
