#include <stdio.h>
#include <string.h>
#define NMAX 205
int main () {
 char x[NMAX],y[NMAX];
 int i,k,j,contx=1,conty=1,comp1,comp2;

 scanf(" %[^\n]s",x);
 scanf(" %[^\n]s",y);

 comp1=strlen(x);   //comprimento das strings
 comp2=strlen(y);

 for(i=0; i<comp1; i++) {  //retirar espaços das strings
  if(x[i]==' ') {
   for(k=i; k<comp1; k++) {
   x[k]=x[k+1];
   }
  }
 }
 for(i=0; i<comp2; i++) {
  if(y[i]==' ') {
   for(k=i; k<comp2; k++) {
   y[k]=y[k+1];
   }
  }
 }
 comp1=strlen(x);   //comprimento das strings sem espaços
 comp2=strlen(y);

 for(i=0; i<comp1; i++) {   // minusculas para maiusculas x
  if(x[i]>='a' && x[i]<='z') {
  x[i]=x[i]-32;
  }
 }
 for(i=0; i<comp2; i++) {   // minusculas para maiusculas y
  if(y[i]>='a' && y[i]<='z') {
  y[i]=y[i]-32;
  }
}
 if(comp1!=comp2 || strcmp(x,y)==0) {  //comprimentos diferentes ou palavras iguais
  printf("no\n");
  return 0;
 }

 for(i=0; i<comp1; i++) {  //quantas vezes ocorre a mesma letra
  contx=1;
  conty=1;
  for(k=0; k<comp1; k++) {
   if(x[i]==x[k]) contx++;
  }
  for(j=0; j<comp1; j++) {
   if(y[j]==x[i]) {
   for(k=0; k<comp1; k++) {
    if(y[j]==y[k]) conty++;
   }
   j=comp1;
   }
  }
  if(contx!=conty) {
   printf("no\n");
   return 0;
   }
  }

  printf("yes\n");
  return 0;
}
