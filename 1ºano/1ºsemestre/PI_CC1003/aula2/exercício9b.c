#include <stdio.h>
int main() {

 int c1,c2,r,n,x,y,distancia;

  printf("Insira as coordenadas do centro da circunferência\n");
   scanf("%d %d",&c1,&c2);
  printf("Insira a medida do raio da circunferência\n");
   scanf("%d",&r);
  printf("Insira o número de pontos a classificar\n");
   scanf("%d",&n);

  printf("Insira as coordenadas desses %d pontos\n",n);

  while (n!=0) {
   scanf("%d %d",&x,&y);
   distancia=(c1-x)*(c1-x)+(c2-y)*(c2-y);
   if (distancia<(r*r))
    printf("(%d,%d):no interior\n",x,y);
   if (distancia>(r*r))
    printf("(%d,%d):no exterior\n",x,y);
   if (distancia==(r*r))
    printf("(%d,%d):na fronteira\n",x,y);
   n = n-1;
   }

  return 0;
}
