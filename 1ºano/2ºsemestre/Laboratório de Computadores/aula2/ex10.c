#include <stdio.h>
#define SIZE 100
int contar_espacos(char *str);
int main() {
char str[SIZE];
int cont;

fgets(str,SIZE,stdin);
cont = contar_espacos(str);
printf("%d\n",cont);

 return 0;
}

int contar_espacos(char *str) {
int cont=0;
 while(*str++ != '\0') {
  if(*str == ' ') cont++;
 }
 return cont;
}
