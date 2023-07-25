#include <stdio.h>

int main() {
 int i,j,l=0,n,k,extremo1,extremo2,escolhabela,escolhaalex,contbela=0,contalex=0,seq[200];

 scanf("%d",&n);
 for(i=0; i<n; i++) {
  scanf("%d",&seq[i]); }
 k=n;
 j=n;
while(k>0) {
 for(i=0;i<n;i++) {
  extremo1=seq[i];
  extremo2=seq[j-1];
  if (extremo1>extremo2 && seq[i]!=0 && seq[j-1]!=0) {
   escolhaalex=extremo1;
   contalex+=escolhaalex;
   seq[i]=0; }
  else if (extremo1<extremo2 && seq[i]!=0 && seq[j-1]!=0) {
   escolhaalex=extremo2;
   contalex+=escolhaalex;
   seq[j-1]=0; }
   j--;
  }
 if(l%2!=0) {
  escolhabela=seq[0];
  for(i=0;i<n;i++) {
   if(escolhabela<seq[i] && seq[i]!=0 && seq[j-1]!=0) {
   escolhabela=seq[i]; }
   contbela+=escolhabela;
   seq[i]=0; }
 }
 else {
  escolhabela=seq[0];
  for(i=0;i<n;i++) {
   if(escolhabela>seq[i] && seq[i]!=0 && seq[j-1]!=0) {
   contbela+=escolhabela;
   seq[i]=0; }
  }
  }
  k=k-2;
  l++;
 }

  if(contalex>contbela) {
   printf("Alex ganha com %d contra %d\n",contalex,contbela); }
  else if(contalex<contbela) {
   printf("Bela ganha com %d contra %d\n",contbela,contalex); }
   else {
    printf("Alex e Bela empatam com %d\n",contalex); }

  return 0;
}
