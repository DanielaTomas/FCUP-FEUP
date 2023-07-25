#include <stdio.h>

int primosfunction(int primos[], int n) {
int i,j,nprimos,c[5000];
  for (i=2; i<=n; i++) {
    c[i]=0;
  }
  for (i=2; i*i<=n; i++) {
   if(c[i]==0) {
    for (j=i*i; j<=n; j=j+i) {
      c[j]=1;
    }
   }
  }
  nprimos=0;
  for (i=2; i<=n; i++) {
   if(c[i]==0) {
     primos[nprimos]=i;
     nprimos++;
   }
  }
  return nprimos;
}

int main() {
int i,primos[5000],nprimos,m,n;

nprimos=primosfunction(primos,5000);

scanf("%d",&n);
while (n-- >0) {
 scanf("%d",&m);
 printf("%d = ",m);
 for (i=0; i<nprimos && m%primos[i] != 0; i++) {
    printf("%d",primos[i]);
    m=m/primos[i];
  }
 for( ; m>1 && i<nprimos; i++) {
   while (m%primos[i]==0) {
   printf("*%d",primos[i]);
   m=m/primos[i];
   }
 }
 printf("\n");
}
  return 0;
}
