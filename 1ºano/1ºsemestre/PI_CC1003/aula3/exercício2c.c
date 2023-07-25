#include <stdio.h>
int main() {

 int x,y,z,c;

  printf("Insira uma sequência de números inteiros (termina por '0')\n");
  scanf("%d",&x);
  scanf("%d",&y);
  c=1;
  if (y==x)
  c=c+1;
  if (y==0) {
  c=0;
  printf("Não aplicável\n"); }

  while (y!=0 && z!=0) {
   scanf("%d",&z);
   if (z!=0) {
    if (y==z)
    c=c+1; }
  }

  if (y!=0)
  printf("O número %d ocorreu %d vezes\n",y,c);

 return 0;  
}
