#include <stdio.h>
#include <string.h>
#define MAXCHARS 1000
int palindromo(char str[]) {
  int size = strlen(str);
  char nova[size+1];
  for (int i = size-1, j=0; i >= 0; i--, j++){
    nova[j] = str[i];
  }
  if (strcmp(str,nova) == 0) {
    return 1;
}
return 0;
}
int main() {
  char str[MAXCHARS];
  scanf("%s", str);
  if(palindromo(str)) {
  printf("True\n");
   }
  else {
  printf("False\n");
  }
  return 0;
}
/*
#define DIGIT(X) ((X)-'0')
factor = 1; // 10^0  numero = 0; 
for(i = strlen(str)-1; i>=0; i--){​​   
numero += DIGIT(str[i])*factor;   
factor *= 10;  }​​
return numero;
*/
