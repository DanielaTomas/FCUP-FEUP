#include <stdio.h>
int main (){
 int x[3] = {23, 41, 17};
 printf("%d\n%d\n%d\n", x[0], x[1], x[2]);
 printf("%ls\n%d\n",x, *x);
 printf("%ls\n%d\n",x+1, *(x+1));
 printf("%ls\n%d\n",x+2, *(x+2));
 printf("%ls\n%d\n",&(x[0]), *&(x[0]));
 // printf("%d\n",&*(x[0]));

return 0;
}
