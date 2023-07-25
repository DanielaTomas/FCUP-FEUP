#include <stdio.h>
int main() {
int i=0,seq[50],j,local;

 scanf("%d",&local);
 seq[i]=local;
 for(i=1; local!=0; i++) {
  scanf("%d",&local);
  for(j=0; j<i; j++) {
   if(seq[i]!=seq[j]) {
    seq[i]=local;
   }
  }
  for(j=0; j<i; j++) {
   if(seq[i]==seq[j]) {
    i=j;
    seq[j]=local;
   }
  }
 }

for(j=0; j<i; j++) {
 if (seq[j]!=0) {
  printf("%d\n",seq[j]); }
}

 return 0;
}

/*
- manter num array a sequência de locais distintos relevantes que visitaram.
- o próximo local L pode ser mais um distinto ou um dos que estão no array.
- se  L for um "distintos relevantes", corta todos os que o seguem no array
(i.e., corta a volta de que as cigarras deram). Para isso, basta atualizar o
número N de elementos que são relevantes.
- se  L não estiver nos que visitou (isto é, não estiver nos primeiros N elementos
do array) então coloca-o a posição N e aumenta N uma unidade.
*/
