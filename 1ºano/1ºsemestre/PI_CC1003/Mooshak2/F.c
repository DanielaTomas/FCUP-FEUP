#include <stdio.h>

int main() {
int media,min,max,i,contmax,contmin,n,c,c1,soma=0;

scanf("%d %d",&n,&c1);
min=max=c1;
soma+=c1;
contmax=contmin=1;
for (i=2; i<=n; i++) {
 scanf("%d",&c);
 soma+=c;
 if (c<min) {
  min=c;
  contmin=1; }
 else if(c==min) {
  contmin++; }
 if (c>max) {
  max=c;
  contmax=1; }
 else if(c==max) {
  contmax++; }
}
if(contmin>1 && contmax>1) {
 media=soma/n; }
else if(contmin==1 && contmax==1) {
 media=(soma-min-max)/(n-2); }
else if (contmin==1 && contmax>1) {
 media=(soma-min)/(n-1); }
else if (contmin>1 && contmax==1) {
 media=(soma-max)/(n-1); }

 printf("%d\n",media);

  return 0;
}
