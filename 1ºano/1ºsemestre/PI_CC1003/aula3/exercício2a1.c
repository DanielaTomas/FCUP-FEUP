#include <stdio.h>
int main() {

 int x,y,cont;

  printf("Insira uma sequência de números inteiros (termina por '0')\n");
  scanf("%d",&x);

  cont=0;
  while (x!=0 && y!=0) {
   scanf("%d",&y);
   if (y!=0) {
    if (x%y!=0)
    cont=cont+1; }
  }

  if (cont!=0)
  printf("Nem todos multiplos de %d\n",x);
  else
  printf("Todos multiplos de %d\n",x);

 return 0;
}
