#include <stdio.h>
int main() {
   int x,y,z;
   x = 5;
   y = 7;
   z = 10;
   if (x+y > z)
    y = x+z;
   if(y != x+z)
    z = x;
   else
    z = y-3*x+4;

   printf("(%d,%d,%d)\n",x,y,z);

return 0;
}
