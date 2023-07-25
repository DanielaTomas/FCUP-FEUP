#include <stdio.h>
int main () {
 char dna;
 char anterior;
 char seguinte;

 scanf(" %c",&dna);
 anterior=dna;
 if(anterior=='a') {
  printf("a\n");
 }
 else if(anterior=='c') {
  printf("c\n");
 }
 else if(anterior=='t') {
  printf("t\n");
 }
 scanf(" %c",&dna);
 seguinte=dna;
 while(seguinte!='#') {
  if((anterior=='a' && seguinte=='a') || (anterior=='c' && seguinte=='t') || (anterior=='t' && seguinte=='c')) {
   printf("a\n");
  }
  else if((anterior=='c' && seguinte=='c') || (anterior=='a' && seguinte=='t') || (anterior=='t' && seguinte=='a')) {
   printf("c\n");
  }
  else if((anterior=='t' && seguinte=='t') || (anterior=='a' && seguinte=='c') || (anterior=='c' && seguinte=='a')) {
   printf("t\n");
  }
  anterior=seguinte;
  scanf(" %c",&dna);
  seguinte=dna;
 }

 return 0;
}
