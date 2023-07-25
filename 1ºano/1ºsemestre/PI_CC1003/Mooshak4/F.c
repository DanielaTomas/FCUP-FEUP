#include <stdio.h>
int main () {
 int i,k,n,m,zeros[256]={0};
 char c[256];

 scanf("%d %d",&n,&m);

 for(i=0; i<n; i++) {
  scanf("%s",c);
  for(k=0; k<m; k++) {
   if(c[k]=='0') zeros[k]++;
  }
 }

 for(i=0; i<m; i++) {
  if(zeros[i]>=(n/2) && n%2==0) {
   printf("0");
  }
  else if(zeros[i]>=((n/2)+1) && n%2!=0) {
   printf("0");
  }
  else {
   printf("1");
  }
 }
 printf("\n");

 return 0;
}
