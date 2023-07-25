#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
void esp(char *s);
char* esp1(char *s);
int main() {
char str[SIZE];

fgets(str,SIZE,stdin);
char *p = esp1(str);
printf("%s\n",p);
esp(str);
printf("%s\n",str);
return 0;
}

void esp(char *s) {
  for(int i=0; i < strlen(s); i++) {
    if(!isalpha(s[i]))
     s[i] = ' ';
  }
}
char* esp1(char *s) {
  char *p;
  p = (char*)malloc(sizeof(char)*strlen(s));
  p = s;
  for(int i=0; i < strlen(p); i++) {
    if(!isalpha(p[i]))
     p[i] = ' ';
  }
  return p;
}
