#include <stdio.h>
int repetidos(int vec[], unsigned size) {
  int count=0,flag;
  for (int i =0; i < size; i++) {
    for(int j=i+1; j < size; j++) {
    if(vec[i]==vec[j])  {
      count++;
    }
  }
  }
  if (count>=1) {
    flag=1;
  }
  else {
    flag=0;
  }
  return flag;
}

int main() {
  int size;
  scanf("%d", &size);
  int a[size];
  for (int i=0; i < size; i++) {
    scanf("%d", &a[i]);
  }
  printf("%d\n", repetidos(a, size));
  return 0;
}
