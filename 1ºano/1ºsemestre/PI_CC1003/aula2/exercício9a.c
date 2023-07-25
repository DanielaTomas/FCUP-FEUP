#include <stdio.h>
int main() {

 int c1,c2,r,x,y,distancia;

 printf("Insira as coordenadas do centro da circunferência\n");
  scanf("%d %d",&c1,&c2);
 printf("Insira a medida do raio da circunferência\n");
  scanf("%d",&r);
 printf("Insira as coordenadas de um ponto qualquer\n");
  scanf("%d %d",&x,&y);

 distancia=(c1-x)*(c1-x)+(c2-y)*(c2-y);

 if (distancia<(r*r))
  printf("(%d,%d):no interior\n",x,y);
 if (distancia>(r*r))
  printf("(%d,%d):no exterior\n",x,y);
 if (distancia==(r*r))
  printf("(%d,%d):na fronteira\n",x,y);
 return 0;
}
