#include <stdio.h>
int main() {

int np,ni,resultado;

scanf("%d",&resultado);

np=(resultado-9)/3;
ni=(resultado-9)/5;

if((resultado%2)!=0) {
 if(((resultado-9)%3)==0) {
  printf("%d\n",np); }
 else {
  printf("Acho que te enganaste nas contas.\n"); }
}
else if((resultado%2)==0) {
 if (((resultado-9)%5)==0) {
  printf("%d\n",ni); }
 else {
  printf("Acho que te enganaste nas contas.\n"); }
 }

 else {
  printf("Acho que te enganaste nas contas.\n"); }

 return 0;
}
