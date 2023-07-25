#include <stdio.h>
int main() {

 int n,ultimo,novo;

 printf("Insira o número de inteiros (dois ou mais) que pretende introduzir na sequência\n");
 scanf("%d",&n);

 printf("Introduza os %d números inteiros da sequência\n",n);
 scanf("%d",&ultimo);
 n=n-1;

 while (n>0) {
  scanf("%d",&novo);
  if (novo>ultimo) {
   novo-ultimo>=1; }
  if (novo<ultimo) {
   novo-ultimo<=-1; }
  n=n-1;
 }

 if (novo-ultimo>=1) {
  printf("A sequência é estritamente crescente\n"); }
 else if (novo-ultimo<=-1) {
  printf("A sequência é estritamente decrescente\n"); }
 else {
  printf("A sequência não é estritamente crescente nem decrescente\n"); }

  return 0;
}
