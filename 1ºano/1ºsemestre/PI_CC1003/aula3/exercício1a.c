#include <stdio.h>
// Surpresa 1
int main() {
int n, i, s;
printf("Valor de n? ");
scanf("%d",&n);
s= 0;
i= 1;
while (i<=n) {
s= s-i*i;
i= i+1;
}
printf("%d\n",s);
return 0;
}
