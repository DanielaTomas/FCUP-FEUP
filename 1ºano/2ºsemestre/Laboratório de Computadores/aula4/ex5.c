#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//NAO FUNCIONA!!! SEGMENTATION FAULT
#define SIZE 100
char* my_strncat(char *dest, char *src, int n);
char* my_strdup(char *s);

int main() {
 char src[SIZE];
 char dest[SIZE];
 int n;
 scanf("%d",&n);
 fgets(src,SIZE,stdin);
 fgets(dest,SIZE,stdin);
 char *p = my_strncat(dest,src,n);
 printf("%s\n",p);
 return 0;
}

char* my_strncat(char *dest, char *src, int n) {
 char *p = my_strdup(src);
 dest = strlen(dest)+(char*)malloc(sizeof(char)*n);
 for(int i=0; i < n; i++) {
  dest[i] += p[i];
 }
  return dest;
}
char* my_strdup(char *s) {
  char *p;
  p = (char*)malloc(sizeof(char)*strlen(s));
  p = s;
 return p;
}
