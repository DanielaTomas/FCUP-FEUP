#include <stdio.h>
void max_min(int vec[], int size, int *pmax, int *pmin);
int main() {
 int pmax,pmin,size;
 scanf("%d",&size);
 int vec[size];

 for(int i=0; i<size; i++) {
 scanf("%d",&vec[i]);
 }
 max_min(vec,size,&pmax,&pmin);
 printf("%d %d\n",pmax,pmin);

 return 0;
}

void max_min(int vec[], int size, int *pmax, int *pmin) {
 *pmax=vec[0];
 *pmin=vec[0];
 for(int i=0; i<size; i++) {
  if(*pmax < vec[i]) *pmax = vec[i];
  else if(*pmin > vec[i]) *pmin = vec[i];
 }
}
