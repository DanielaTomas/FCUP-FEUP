#include <stdio.h>
#include <math.h>
struct Ponto{
 float x;
 float y;
};
typedef struct Ponto PONTO;

float distanciaEuclideana(PONTO p1, PONTO p2);

float distancia_total(PONTO percurso[], int size);

PONTO soma(PONTO p1, PONTO p2);

int main(){
 PONTO p1, p2, p3;
 PONTO caminho[] = {{0,0},{0,1}, {1,1},{4,5}};
 int size = 4;
 float dist;
 scanf("%f %f",&p1.x,&p1.y); // ler coordenada x e y de um ponto para p1
 scanf("%f %f",&p2.x,&p2.y); // ler coordenada x e y de um ponto para p2

 dist = distanciaEuclideana(p1,p2);
 p3 = soma(p1,p2);

 printf ("%f\n",dist); // imprimir distância euclideana entre os pontos p1 e p2
 printf ("%f %f\n",p3.x,p3.y); // imprimir vector soma dos vectores representados pelos pontos p1 e p2

 dist = distancia_total(caminho, size);

 printf ("%f\n",dist);

 return 0;
}

float distanciaEuclideana(PONTO p1, PONTO p2) {
  float dist;
  dist = sqrt(pow((p1.y - p2.y),2)+ pow((p1.x - p2.y),2));
  return dist;
}

PONTO soma(PONTO p1, PONTO p2) {
  PONTO p3;
  p3.x = p1.x + p2.x;
  p3.y = p1.y + p2.y;
  return p3;
}

float distancia_total(PONTO percurso[], int size) {
 float soma = 0;
 for(int i=1; i<size; i++) {
     soma += distanciaEuclideana(percurso[i-1],percurso[i]);
 }
 return soma;
}
