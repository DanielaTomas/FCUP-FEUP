#include <stdio.h>
int main() {

int a,b,c,max;
  printf("Insira três números inteiros\n");
  scanf("%d %d %d",&a,&b,&c);

if (a > b)
max = a;

if (a < b)
max = b;

if (max >= c)
printf("O máximo dos três números é %d\n",max);

if (max < c)
printf("O máximo dos três números é %d\n",c);

 return 0;
}
