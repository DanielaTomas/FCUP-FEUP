#include <stdio.h>
#include <string.h>
#define MAXCHARS 1000
int contar_maiores(int vec[], int size, int val) {
  int sum=0;
  for (int i=0; i<size; i++) {
    if (vec[i] > val) {
      sum += vec[i];
    }
}
return sum;
}
int main() {
  int size, val;
  scanf("%d", &size);
  int vec[size];
  for (int i=0; i<size; i++) {
    scanf("%d", &vec[i]);
  }
  scanf("%d",&val);
  printf("%d", contar_maiores(vec,size,val));
  return 0;
}
