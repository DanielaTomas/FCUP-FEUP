#include <stdio.h>
#include <stdlib.h>
int* readarray(int n){
 int i;
 int *v;
 v = (int*)malloc(sizeof(int)*n);
 for (i=0; i<n; i++){
  scanf("%d", v+i);
 }
 return v;
}
int* somaarrays(int *a, int *b, int n) {
/*deverá retornar um novo array com a soma dos arrays arrays a e b,
elemento a elemento*/
 int *p;
 p = (int*)malloc(sizeof(int)*n);
 for (int i=0; i<n; i++){
  p[i] = a[i] + b[i];
  /*printf("---p[%d] = %d\n",i,p[i]);
  printf("---a[%d] = %d\n",i,a[i]);
  printf("---b[%d] = %d\n",i,b[i]);*/
 }
 return p;
}
void printarray(int *v, int n){
  /*deverá imprimir os elementos de v*/
  for (int i=0; i<n; i++){
   printf("v[%d] = %d\n",i,v[i]);
  }
  printf("---------------\n");
}
int main(){
 int n;
 int *va, *vb, *vr;
 scanf("%d\n", &n);
 va = readarray(n);
 vb = readarray(n);
 vr = somaarrays(va, vb, n);
 printarray(va, n);
 printarray(vb, n);
 printarray(vr, n);
 return 0;
}
