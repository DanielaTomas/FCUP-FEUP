#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
int comparar(char *str1, char *str2);
int main() {
char str1[SIZE],x,str2[SIZE];

scanf(" %s",str1);
scanf(" %s",str2);
x = comparar(str1,str2);
if(x == 1)
printf("iguais\n");
else
printf("diferentes\n");

 return 0;
}
int comparar(char *str1, char *str2) {

while(*str1 != '\0' || *str2 != '\0') {
 if(*str1 != *str2)
  return 0;
 str1++;
 str2++;
}
 return 1;
}
