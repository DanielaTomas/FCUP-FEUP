#include <stdio.h>
int euclides(int a, int b);
void reduzir(int *pnum, int *pdenom);
int main() {
 int pnum, pdenom;
 scanf("%d %d",&pnum, &pdenom);
 reduzir(&pnum, &pdenom);
 printf("%d/%d\n",pnum, pdenom);

 return 0;
}

void reduzir(int *pnum, int *pdenom) {
 int mdc = euclides(*pnum,*pdenom);
  *pnum/=mdc;
  *pdenom/=mdc;
 }

int euclides(int a, int b) {
 if(a < b) euclides(b,a);
 if(b == 0) return a;
 return euclides(b,a%b);
}
