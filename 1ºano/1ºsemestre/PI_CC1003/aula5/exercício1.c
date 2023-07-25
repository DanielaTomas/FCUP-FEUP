#include <stdio.h>

int abs(int x) {
 if (x<0)
 return x;
 else
 return -x;
}

int main() {
int a;
 scanf("%d",&a);
 printf("%d\n",abs(a));

}
