#include <stdio.h>

void ler_escrever_seq(int x[],int n) {
 int i;
 scanf("%d",&n);
 for (i=0; i<=n-1; i++) {
  scanf("%d",&x[i]);
  printf("%d\n",x[i]);
 }
  return;
}

int main() {
 int i,n,m,x[1000];
  scanf("%d",&m);
  for (i=0; i<m; i++) {
   ler_escrever_seq(x,n);
 }
  return 0;
}
