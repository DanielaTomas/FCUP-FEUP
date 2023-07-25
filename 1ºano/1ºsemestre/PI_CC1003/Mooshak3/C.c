#include <stdio.h>
int main () {
int l[32],t[32],n,i,acertos=0,pontos=0;

 scanf("%d",&n);

 for(i=0; i<n; i++) {
  scanf("%d",&l[i]);
 }
 for(i=0; i<n; i++) {
  scanf("%d",&t[i]);
 }

 l[n+1]=l[0]=0;
 t[n+1]=t[0]=1;

 for(i=1; i<=n; i++) {
  if(l[i]==t[i]) {
   acertos++;
   if(l[i-1]==t[i-1] || l[i+1]==t[i+1]) {
    pontos+=3; }
  else {
   pontos++; }
  }
 }


  printf("%d\n%d\n",acertos,pontos);

 return 0;
}
