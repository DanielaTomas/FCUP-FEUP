#include <stdio.h>
int main() {
   int x,y,z,w;
   x = 5;
   y = x;
   z = 10;
   w = 8;
   if (x == y)
    y = z;
   if(x !=y || y > w)
    z = x;
   if (z != x && y <= w)
    z = w;

   printf("%d %d %d %d\n",x,y,z,w);

return 0;
}
