#include <stdio.h>

int length(const char s[]) {
   int i = 0;
   while(s[i] != '\0') {
     i++;
   }
   return i;
}

void copy(char dst[], const char src[]) {
  int i = 0;
   for( ; src[i] != '\0'; i++) {
     dst[i] = src[i];
   }
   dst[i] = '\0';
}
void concat(char dst[], const char src[]) {
  int d = length(dst);
  for(int i = 0; i < (length(dst) + length(src)); i++) {
     dst[d] = src[i];
     d++;
   }
}
int length2(const char s[]) {
  const char* p = &s[0];  // ou simplesmente p = s
  while (*p != '\0') {
    p++; // avança para próxima posição
  }
  return p - &s[0]; // ou p - s
}
void concat2(char dst[], const char src[]) {
  const char *p;
  p = &src[0];
  for(int i = 0; i < (length(dst) + length(src)); i++) {
     dst[i] = *p;
     p++;
   }
}
int main(void) {
  char a[20];

  copy(a, "Hello"); puts(a); printf("%d\n", length(a));

  // Nota: "" é a string vazia (tem apenas '\0' no início)
  concat(a, ""); puts(a); printf("%d\n", length(a));
  concat(a, " world");  puts(a); printf("%d\n", length(a));
  concat(a, "!"); puts(a); printf("%d\n", length(a));

  return 0;
}
