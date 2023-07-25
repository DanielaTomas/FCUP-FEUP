#include <stdio.h>
int main() {

int a,b,c,delta;

 printf("Insira os valores (inteiros) de a, b e c da equação ax² + bx + c = 0\n");
 scanf("%d %d %d",&a,&b,&c);

 delta=(b*b-4*a*c);

 if (delta==0)
  printf("raiz dupla\n");

 else if (delta<0)
  printf("sem raizes\n");

 else if (delta>0)
  printf("duas raizes distintas\n");

return 0;
}
