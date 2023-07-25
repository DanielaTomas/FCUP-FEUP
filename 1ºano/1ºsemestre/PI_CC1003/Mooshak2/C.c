#include <stdio.h>
int main () {
int c,i,j,s,t;

scanf("%d",&c);

while(c>=1 && c<=100) {
 scanf("%d %d",&i,&j);
 scanf("%d %d",&s,&t);
 if(i<=j && s<=t) {
  if (i>=s && j>t) {
   printf("sem alibi\n"); }
  else if ((i>s && j>=t)) {
    printf("sem alibi\n"); }
  else if ((i<s && j<=t)) {
    printf("sem alibi\n"); }
  else {
   printf("com alibi\n"); }
 }
 c=c-1;
}

 return 0;
}
