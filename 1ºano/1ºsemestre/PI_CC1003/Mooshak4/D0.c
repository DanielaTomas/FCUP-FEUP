#include <stdio.h>
int main () {
 int i=0,contj1=0,contj2=0;
 char j1[11], j2[11];

 scanf(" %s",j1);
 scanf(" %s",j2);

 for(i=0; i<10; i++) {
   if(j1[i]=='R' && j2[i]=='T') {
    contj1++;
   }
   else if(j1[i]=='R' && j2[i]=='P') {
    contj2++;
   }
   else if(j1[i]=='T' && j2[i]=='R') {
    contj2++;
   }
   else if(j1[i]=='T' && j2[i]=='P') {
    contj1++;
   }
   else if(j1[i]=='P' && j2[i]=='R') {
    contj1++;
   }
   else if(j1[i]=='P' && j2[i]=='T') {
    contj2++;
   }
 }

 printf("%d\n%d\n",contj1,contj2);

  return 0;
}
