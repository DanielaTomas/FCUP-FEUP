#include <stdio.h>
int main () {

int n,r,r1,g,g1,b,b1,soma=0;

scanf("%d %d %d %d",&r,&g,&b,&n);

while (n>0 && n<=10000) {
scanf("%d %d %d",&r1,&g1,&b1);
if (r==r1 && g==g1 && b==b1){
soma++; }
n=n-1;
}
printf("%d\n",soma);

return 0;
}
