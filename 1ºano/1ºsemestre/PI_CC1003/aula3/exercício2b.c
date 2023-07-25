#include <stdio.h>
int main() {

 int x,y,c;

  printf("Insira uma sequência de números inteiros (termina por '0')\n");
  scanf("%d",&x);
  c=1;
  if (x==0)
  c=0;

  while (x!=0 && y!=0) {
   scanf("%d",&y);
   if (y!=0) {
    if (x==y)
    c=c+1; }
  }

  printf("O número %d ocorreu %d vezes\n",x,c);

 return 0;
}
