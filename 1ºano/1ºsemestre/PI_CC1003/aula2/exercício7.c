#include <stdio.h>
int main() {

int x,max;

  scanf("%d",&x);
  max=x;

  while (x != 0) {
   scanf("%d",&x);
   if (x != 0) {
   if (x >= max)
    max=x;
   else
    x=max; }
 }

 printf("O máximo entre os números inseridos é %d\n",max);

return 0;
}
