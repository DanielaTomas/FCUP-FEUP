#include <stdio.h>
void store_zeros(int *a, int n);
int main() {
 int n;
 scanf("%d",&n);
 int vec[n];
 for(int i=0; i<n; i++)
 scanf("%d",&vec[i]);

 for(int i=0; i<n; i++)
 printf("v[%d] = %d\n",i,vec[i]);

 store_zeros(vec,n);
 printf("----------------------\n");
 for(int i=0; i<n; i++)
  printf("v[%d] = %d\n",i,vec[i]);

 return 0;
}


void store_zeros(int *a, int n) {
 for( ; n-- > 0; )
  *(a++) = 0;
}
