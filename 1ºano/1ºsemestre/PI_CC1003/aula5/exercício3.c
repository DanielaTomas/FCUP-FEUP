#include <stdio.h>

void posicao(int a,int b,int c,int d) {

 if (a>c) {
 printf("esquerda ");
 if (b>d) {
 printf("abaixo\n"); }
 if (b<d) {
 printf("acima\n"); }
 }
 else if (a<c) {
 printf("direita ");
 if (b>d) {
 printf("abaixo\n"); }
 if (b<d) {
 printf("acima\n"); }
 }
 else if (b>d) {
 printf("abaixo\n"); }
 else if (b<d) {
 printf("acima\n"); }

 else {
 printf("coincidentes\n"); }

 return;
}

int main () {
int a,b,c,d;
scanf("%d %d %d %d",&a,&b,&c,&d);
posicao(a,b,c,d);
return 0;
}
