#include <stdio.h>

int main() {

 int p,azul,amarelo,verde;

 printf("Insira uma sequência de produtos (identificados de 1 a 40) para reciclar que termina por '-1'\n");
 scanf("%d",&p);

 azul=0;
 amarelo=0;
 verde=0;

 while (p!=-1) {
   if(p<=10)
   azul++;
   else if(p<=23)
   verde++;
   else
   amarelo++; 
  scanf("%d",&p);
 }
 printf("azul: %d\n",azul);
 printf("amarelo: %d\n",amarelo);
 printf("verde: %d\n",verde);
 return 0;
}
