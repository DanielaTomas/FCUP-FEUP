#include <stdio.h>
#include <string.h>
#define SIZE 100
void inverter(char *str);
int main() {
char str[SIZE];

scanf("%s",str);
inverter(str);
printf("%s\n",str);

 return 0;
}

void inverter(char *str) {
 char *c = str+strlen(str)-1;
 for( ; c > str; c--, str++) {
  char temp = *c;
  *c = *str;
  *str = temp;
}
 }
