#include <stdio.h>
int main() {

int a,b,c;
 printf("Insira três números inteiros\n");
 scanf("%d %d %d",&a,&b,&c);
//alínra a)
//if (a,b,c>0 && a<b+c && b<a+c && c<a+b)
//a,b,c positivos e menores do que a soma dos outros dois
//printf("(%d,%d,%d) define triângulo.\n",a,b,c);

//alínea b)
if (a>0 && b>0 && c>0 && a<b+c && b<a+c && c<a+b && a==b && b==c && c==a)
printf("(%d,%d,%d) define triângulo equilátero.\n",a,b,c);
     //todos os lados iguais

if (a>0 && b>0 && c>0 && a<b+c && b<a+c && c<a+b && a!=b && b!=c && c!=a)
printf("(%d,%d,%d) define triângulo escaleno.\n",a,b,c);
     //todos os lados diferentes

if (a>0 && b>0 && c>0 && a<b+c && b<a+c && c<a+b && ((a==b & c!=a)|| (b==c & a!=b) || (c==a & b!=c)))
printf("(%d,%d,%d) define triângulo isósceles.\n",a,b,c);
     //dois lados iguais

else
printf("(%d,%d,%d) não define triângulo.\n",a,b,c);

return 0;
}
