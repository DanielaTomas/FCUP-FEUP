#include <stdio.h>
// Surpresa 2
int main() {
int x, y, n, cm, c;
printf("Valor de n (positivo)? ");
scanf("%d",&n);
printf("Valor de x (nao nulo)? ");
scanf("%d",&x);
c = 0;
cm= 0;
while (c < n) {
c = c+1;
printf("Valor de y? ");
scanf("%d",&y);
if (y%x == 0)
cm= cm+1;
}
printf("%d em %d\n",cm,n);
return 0;
}
