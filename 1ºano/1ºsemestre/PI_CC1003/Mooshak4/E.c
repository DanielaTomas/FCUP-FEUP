#include <stdio.h>
int main () {
 int i=0,n,inacessivel=0;
 char c[1000];

 scanf("%d",&n);
 scanf("%s",&c[i]);

 if(c[i]=='#') {
  inacessivel++;
 }

 for(i=1; i<n; i++) {
  scanf("%s",&c[i]);
  if(c[i-1]=='#' && c[i]=='#') {
   inacessivel++;
  }
 }

printf("%d\n",inacessivel);

 return 0;
}
