#include <stdio.h>

int main() {

 int e1,e2,andar,d1,d2;

  printf("Insira o andar de onde foi feita a chamada, a situação do elevador 1 e do elevador 2, respetivamente. Caso o elevador se encontre indisponível digitar '999'.\n");
  scanf("%d %d %d",&andar,&e1,&e2);

  d1=(andar-e1);
  if(d1<0) {
  d1=-d1; }

  d2=(andar-e2);
  if(d2<0) {
  d2=-d2;  }

  if ( d1>d2 && e1<=100 && e1>=-100 && e2<=100 && e2>=-100 && andar<=100 && andar>=-100)
  printf("2\n");
  if ( d1<d2 && e1<=100 && e1>=-100 && e2<=100 && e2>=-100 && andar<=100 && andar>=-100)
  printf("1\n");
  if (d1==d2 && e1==e2 && e1<=100 && e1>=-100 && e2<=100 && e2>=-100 && andar<=100 && andar>=-100)
  printf("1\n");
  if (d1==d2 && e1<e2 && e1<=100 && e1>=-100 && e2<=100 && e2>=-100 && andar<=100 && andar>=-100)
  printf("2\n");
  if (d1==d2 && e1>e2 && e1<=100 && e1>=-100 && e2<=100 && e2>=-100 && andar<=100 && andar>=-100)
  printf("1\n");
  if (e1==999 && e2==999)
  printf("0\n");
  if (e1==999 && e2<=100 && e2>=-100)
  printf("2\n");
  if (e1<=100 && e1>=-100 && e2==999)
  printf("1\n");

 return 0;
}
