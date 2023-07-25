#include <stdlib.h>
#include <stdio.h>

void copy(char dst[], const char *src) {
  char* p = dst;
  const char* q = src;
  while(*q != '\0') {
    *p = *q;
    p++;
    q++;
  }
  *p = 0;
}
void print(const char s[]) {
  const char* p = s;
  while (*p != '\0') {
    putchar(*p);
    p++;
  }
  putchar('\n');
}
int main(void) {
  /*
  a)
  char s[5];
  copy(s, "ABCDE");
  print(s);
  */
  /*
  b)
  char* s = malloc(6);
  copy(s, "ABCDE");
  print(s);
  */
  /*
  c)
  char* s = malloc(6);
  copy(s, "ABCDE");
  free(s);
  print(s);
  */
  /*
  d)
  char* s = malloc(6);
  copy(s, "ABCDE");
  print(s);
  free(s);
  free(s);
  */
  /*
  e)
  char* s = malloc(6);
  copy(s, "ABCDE");
  s = realloc(s, 10);
  copy(s + 5, "12345");
  print(s);
  free(s);
  */
  /*
  f)
  char c = '\0';
  char* s = malloc(6);
  copy(s, "ABCDE");
  s[0] = s[0] / c;
  print(s);
  free(s);
  */
  /*
  g)
  char* s = malloc(6);
  char *ps[] = { s, "ABCDE", 0};
  copy(ps[0], ps[2]);
  print(s);
  free(s);
  */
  /*
  h)
  char* s = malloc(6);
  char *ps[] = { s, "ABCDE", 0};
  ps[2]++;
  copy(ps[0], ps[2]);
  print(s);
  free(s);
  */
}
