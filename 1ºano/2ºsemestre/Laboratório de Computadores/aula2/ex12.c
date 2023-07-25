#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
char *procurar(char *str, char ch);
int main() {
char str[SIZE],*x,ch[SIZE];

scanf(" %s",str);
scanf(" %c",ch);
x = procurar(str,*ch);
if(x != NULL)
printf("%c\n",*x);
else
printf("NULL\n");

 return 0;
}
char *procurar(char *str, char ch) {

while(*str != '\0') {
 if(*str == ch)
  return str;
 str++;
}
 return NULL;
}
